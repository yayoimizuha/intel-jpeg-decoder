#include <iostream>
#include <vpl/mfx.h>
#include <vpl/mfxjpeg.h>
#include <vpl/mfxvideo++.h>
#include <algorithm>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

mfxStatus state;
#define CHECK(x) if((state = x) != MFX_ERR_NONE){cout << "error in " << __LINE__ <<" by "<< state << endl;exit(-1);}
#define BITSTREAM_BUFFER_SIZE 2000000;
#define ALIGN16(value) (((value + 15) >> 4) << 4)
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
    if (input_file == nullptr) {
        cout << "fail to open file" << endl;
        exit(-1);
    }
    bitstream.DataLength += fread(bitstream.Data + bitstream.DataLength, 1, bitstream.MaxLength - bitstream.DataLength,
                                  input_file);

    mfxVideoParam decodeParams = {};
    mfxVideoParam decodeVPPParams = {};
    decodeParams.mfx.CodecId = MFX_CODEC_JPEG;
    decodeParams.IOPattern = MFX_IOPATTERN_OUT_SYSTEM_MEMORY;
//    decodeParams.mfx.JPEGColorFormat = MFX_JPEG_COLORFORMAT_RGB;
//    decodeParams.mfx.JPEGChromaFormat = MFX_CHROMAFORMAT_YUV444;

//    decodeVPPParams.mfx.CodecId = MFX_CODEC_JPEG;
//    decodeVPPParams.IOPattern = MFX_IOPATTERN_OUT_VIDEO_MEMORY;

    CHECK(MFXVideoDECODE_DecodeHeader(session, &bitstream, &decodeParams))
//    CHECK(MFXVideoDECODE_VPP_DecodeHeader(session, &bitstream, &decodeVPPParams))
    auto channelParam = new mfxVideoChannelParam[0];
    memset(channelParam, 0, sizeof(mfxVideoChannelParam));
    channelParam->VPP.FourCC = MFX_FOURCC_RGBP;
    channelParam->VPP.ChromaFormat = MFX_CHROMAFORMAT_YUV420;
    channelParam->VPP.PicStruct = MFX_PICSTRUCT_PROGRESSIVE;
    channelParam->VPP.FrameRateExtN = decodeParams.mfx.FrameInfo.FrameRateExtN;
    channelParam->VPP.FrameRateExtD = decodeParams.mfx.FrameInfo.FrameRateExtD;
    channelParam->VPP.CropW = decodeParams.mfx.FrameInfo.CropW;
    channelParam->VPP.CropH = decodeParams.mfx.FrameInfo.CropH;
    channelParam->VPP.Width = ALIGN16(channelParam->VPP.CropW);
    channelParam->VPP.Height = ALIGN16(channelParam->VPP.CropH);
    channelParam->VPP.ChannelId = 1;
    channelParam->Protected = 0;
    channelParam->IOPattern = MFX_IOPATTERN_IN_SYSTEM_MEMORY | MFX_IOPATTERN_OUT_SYSTEM_MEMORY;
    channelParam->ExtParam = nullptr;
    channelParam->NumExtParam = 0;


    CHECK(MFXVideoDECODE_VPP_Init(session, &decodeParams, &channelParam, 1))

//    CHECK(MFXVideoDECODE_Init(session, &decodeParams))

    auto fourcc = decodeParams.mfx.FrameInfo.FourCC;
    auto mask = 0xff;
    auto fourcc_str = ""s + (char) (fourcc & mask) + (char) ((fourcc & mask << 8) >> 8) +
                      (char) ((fourcc & mask << 16) >> 16) + (char) ((fourcc & mask << 24) >> 24);
    cout << "image format name: " << fourcc_str << endl;
    if (fourcc != MFX_FOURCC_NV12)exit(-1);
    mfxSurfaceArray *surface_out;
    mfxSyncPoint syncPoint;

    CHECK(MFXVideoDECODE_VPP_DecodeFrameAsync(session, &bitstream, nullptr, 0, &surface_out))
    surface_out->Surfaces[0]->FrameInterface->Synchronize(surface_out->Surfaces[0], 1000);
    auto aSurf = surface_out->Surfaces[1];
    CHECK(aSurf->FrameInterface->Synchronize(aSurf, 1000))
    CHECK(aSurf->FrameInterface->Map(aSurf, MFX_MAP_READ))
    auto h = aSurf->Info.CropH;
    auto w = aSurf->Info.CropW;

    fourcc = aSurf->Info.FourCC;
    fourcc_str = ""s + (char) (fourcc & mask) + (char) ((fourcc & mask << 8) >> 8) +
                 (char) ((fourcc & mask << 16) >> 16) + (char) ((fourcc & mask << 24) >> 24);
    cout << "image format name: " << fourcc_str << endl;
    auto out = fopen("out.raw", "wb");
    for (int i = 0; i < h; ++i) {
        fwrite(&aSurf->Data.R[i * aSurf->Data.Pitch], 1, w, out);
    }
    for (int i = 0; i < h; ++i) {
        fwrite(&aSurf->Data.G[i * aSurf->Data.Pitch], 1, w, out);
    }
    for (int i = 0; i < h; ++i) {
        fwrite(&aSurf->Data.B[i * aSurf->Data.Pitch], 1, w, out);
    }
}


//https://github.com/intel/libvpl/blob/383b5caac6df614e76ade5a07c4f53be702e9176/examples/api2x/hello-decvpp/src/hello-decvpp.cpp