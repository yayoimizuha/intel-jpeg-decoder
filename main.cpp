#include <iostream>
#include <vpl/mfx.h>
#include <vpl/mfxjpeg.h>
#include <vpl/mfxvideo++.h>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

mfxStatus state;
#define CHECK(x) if((state = x) != MFX_ERR_NONE){cout << "error in " << __LINE__ <<" by "<< state << endl;exit(-1);}
#define BITSTREAM_BUFFER_SIZE 2000000;

const char *PATH = R"(C:\Users\tomokazu\CLionProjects\oneAPI_test\jpeg420exif.jpg)";

int main() {
    auto loader = MFXLoad();
    auto cfg = MFXCreateConfig(loader);
    mfxVariant variant;
    variant.Type = MFX_VARIANT_TYPE_U32;
    variant.Data.U32 = MFX_IMPL_HARDWARE;
    MFXSetConfigFilterProperty(cfg, reinterpret_cast<const mfxU8 *>("mfxImplDescription.Impl"), variant);
    variant.Data.U32 = MFX_CODEC_JPEG;
    MFXSetConfigFilterProperty(cfg,
                               reinterpret_cast<const mfxU8 *>("mfxImplDescription.mfxDecoderDescription.decoder.CodecID"),
                               variant);
    mfxStatus iter;
    mfxImplDescription *implDesc;
    mfxSession session;
    int impl_idx = -1;
    for (int i = 0; iter = MFXEnumImplementations(loader, i,
                                                  mfxImplCapsDeliveryFormat::MFX_IMPLCAPS_IMPLDESCSTRUCTURE,
                                                  reinterpret_cast<mfxHDL *>(&implDesc))
            , iter != MFX_ERR_NOT_FOUND; ++i) {

        switch (iter) {
            case MFX_ERR_NONE:
                cout << "Found suitable device: " << implDesc->ImplName << endl;
                cout << "License: " << implDesc->License << endl;
                cout << "Device ID: " << implDesc->Dev.DeviceID << endl;
                cout << "Vendor ID: " << implDesc->Impl << endl;

//                cout <<  << endl;１QSくださいあ
                MFXCreateSession(loader, i, &session);
                mfxIMPL impl;
                if (MFXQueryIMPL(session, &impl) == MFX_ERR_NONE) {
                    switch (impl & 0x0f00) {
                        case MFX_IMPL_VIA_D3D9:
                            cout << "Impl: MFX_IMPL_VIA_D3D9" << endl;
                            break;
                        case MFX_IMPL_VIA_D3D11:
                            cout << "Impl: MFX_IMPL_VIA_D3D11" << endl;
                            break;
                        case MFX_IMPL_VIA_VAAPI:
                            cout << "Impl: MFX_IMPL_VIA_VAAPI" << endl;
                            break;
                        case MFX_IMPL_VIA_HDDLUNITE:
                            cout << "Impl: MFX_IMPL_VIA_HDDLUNITE" << endl;
                            break;
                        default:
                            cout << "Impl: MFX_IMPL_UNSUPPORTED" << endl;
                    }
                }
                impl_idx = i;
            default:
                MFXDispReleaseImplDescription(loader, implDesc);
        }
    }
    if (impl_idx == -1)return 1;

    mfxHDL hdl;
    MFXEnumImplementations(loader, impl_idx, mfxImplCapsDeliveryFormat::MFX_IMPLCAPS_IMPLEMENTEDFUNCTIONS, &hdl);
    auto *implementedFunctions = static_cast<mfxImplementedFunctions *>(hdl);
    std::for_each(implementedFunctions->FunctionsName,
                  implementedFunctions->FunctionsName + implementedFunctions->NumFunctions,
                  [](mfxChar *functionName) {
                      cout << "implemented: " << functionName << endl;
                  });
    MFXDispReleaseImplDescription(loader, hdl);

    mfxBitstream bitstream = {};

    bitstream.MaxLength = BITSTREAM_BUFFER_SIZE;
    bitstream.DataFlag = MFX_BITSTREAM_COMPLETE_FRAME;
    bitstream.Data = static_cast<mfxU8 *>(calloc(bitstream.MaxLength, sizeof(mfxU8)));
    bitstream.CodecId = MFX_CODEC_JPEG;
    auto input_file = fopen(PATH, "rb");
    bitstream.DataLength += fread(bitstream.Data + bitstream.DataLength, 1, bitstream.MaxLength - bitstream.DataLength,
                                  input_file);

    mfxVideoParam decodeParams = {};
    decodeParams.mfx.CodecId = MFX_CODEC_JPEG;
    decodeParams.IOPattern = MFX_IOPATTERN_OUT_SYSTEM_MEMORY;
//    decodeParams.mfx.JPEGColorFormat = MFX_JPEG_COLORFORMAT_RGB;
//    decodeParams.mfx.JPEGChromaFormat = MFX_CHROMAFORMAT_YUV444;


    CHECK(MFXVideoDECODE_DecodeHeader(session, &bitstream, &decodeParams))

    CHECK(MFXVideoDECODE_Init(session, &decodeParams))

    auto fourcc = decodeParams.mfx.FrameInfo.FourCC;
    auto mask = 0xff;
    auto fourcc_str = ""s + (char) (fourcc & mask) + (char) ((fourcc & mask << 8) >> 8) +
                      (char) ((fourcc & mask << 16) >> 16) + (char) ((fourcc & mask << 24) >> 24);
    cout << "image format name: " << fourcc_str << endl;
    if (fourcc != MFX_FOURCC_NV12)exit(-1);
    mfxFrameSurface1 *surface_out;
    mfxSyncPoint syncPoint;

    CHECK(MFXVideoDECODE_DecodeFrameAsync(session, &bitstream, nullptr, &surface_out, &syncPoint))
    CHECK(surface_out->FrameInterface->Synchronize(surface_out, 1000))
    CHECK(surface_out->FrameInterface->Map(surface_out, MFX_MAP_READ))
    auto h = surface_out->Info.CropH;
    auto w = surface_out->Info.CropW;

    fourcc = surface_out->Info.FourCC;
    fourcc_str = ""s + (char) (fourcc & mask) + (char) ((fourcc & mask << 8) >> 8) +
                 (char) ((fourcc & mask << 16) >> 16) + (char) ((fourcc & mask << 24) >> 24);
    cout << "image format name: " << fourcc_str << endl;
    auto out = fopen("out.raw", "wb");
    for (int i = 0; i < h; ++i) {
        fwrite(&surface_out->Data.Y[i * surface_out->Data.Pitch], 1, w, out);
    }
    for (int i = 0; i < h / 2; ++i) {
        fwrite(&surface_out->Data.UV[i * surface_out->Data.Pitch], 1, w, out);
    }
}
