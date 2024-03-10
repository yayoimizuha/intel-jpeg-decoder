#include <iostream>
#include <vpl/mfx.h>
#include <algorithm>
#include <cstring>
#include "BitmapPlusPlus.hpp"
#include <d3d11.h>
//#include <sycl/CL/cl_d3d11.h>
using namespace std;


void check(mfxStatus x, int LINE) {
    switch (x) {
        case MFX_ERR_NONE:
            return;
        case MFX_ERR_UNKNOWN:
            cerr << "error in " << LINE << " by " << "MFX_ERR_UNKNOWN" << endl;
            break;
        case MFX_ERR_NULL_PTR:
            cerr << "error in " << LINE << " by " << "MFX_ERR_NULL_PTR" << endl;
            break;
        case MFX_ERR_UNSUPPORTED:
            cerr << "error in " << LINE << " by " << "MFX_ERR_UNSUPPORTED" << endl;
            break;
        case MFX_ERR_MEMORY_ALLOC:
            cerr << "error in " << LINE << " by " << "MFX_ERR_MEMORY_ALLOC" << endl;
            break;
        case MFX_ERR_NOT_ENOUGH_BUFFER:
            cerr << "error in " << LINE << " by " << "MFX_ERR_NOT_ENOUGH_BUFFER" << endl;
            break;
        case MFX_ERR_INVALID_HANDLE:
            cerr << "error in " << LINE << " by " << "MFX_ERR_INVALID_HANDLE" << endl;
            break;
        case MFX_ERR_LOCK_MEMORY:
            cerr << "error in " << LINE << " by " << "MFX_ERR_LOCK_MEMORY" << endl;
            break;
        case MFX_ERR_NOT_INITIALIZED:
            cerr << "error in " << LINE << " by " << "MFX_ERR_NOT_INITIALIZED" << endl;
            break;
        case MFX_ERR_NOT_FOUND:
            cerr << "error in " << LINE << " by " << "MFX_ERR_NOT_FOUND" << endl;
            break;
        case MFX_ERR_MORE_DATA:
            cerr << "error in " << LINE << " by " << "MFX_ERR_MORE_DATA" << endl;
            break;
        case MFX_ERR_MORE_SURFACE:
            cerr << "error in " << LINE << " by " << "MFX_ERR_MORE_SURFACE" << endl;
            break;
        case MFX_ERR_ABORTED:
            cerr << "error in " << LINE << " by " << "MFX_ERR_ABORTED" << endl;
            break;
        case MFX_ERR_DEVICE_LOST:
            cerr << "error in " << LINE << " by " << "MFX_ERR_DEVICE_LOST" << endl;
            break;
        case MFX_ERR_INCOMPATIBLE_VIDEO_PARAM:
            cerr << "error in " << LINE << " by " << "MFX_ERR_INCOMPATIBLE_VIDEO_PARAM" << endl;
            break;
        case MFX_ERR_INVALID_VIDEO_PARAM:
            cerr << "error in " << LINE << " by " << "MFX_ERR_INVALID_VIDEO_PARAM" << endl;
            break;
        case MFX_ERR_UNDEFINED_BEHAVIOR:
            cerr << "error in " << LINE << " by " << "MFX_ERR_UNDEFINED_BEHAVIOR" << endl;
            break;
        case MFX_ERR_DEVICE_FAILED:
            cerr << "error in " << LINE << " by " << "MFX_ERR_DEVICE_FAILED" << endl;
            break;
        case MFX_ERR_MORE_BITSTREAM:
            cerr << "error in " << LINE << " by " << "MFX_ERR_MORE_BITSTREAM" << endl;
            break;
        case MFX_ERR_GPU_HANG:
            cerr << "error in " << LINE << " by " << "MFX_ERR_GPU_HANG" << endl;
            break;
        case MFX_ERR_REALLOC_SURFACE:
            cerr << "error in " << LINE << " by " << "MFX_ERR_REALLOC_SURFACE" << endl;
            break;
        case MFX_ERR_RESOURCE_MAPPED:
            cerr << "error in " << LINE << " by " << "MFX_ERR_RESOURCE_MAPPED" << endl;
            break;
        case MFX_ERR_NOT_IMPLEMENTED:
            cerr << "error in " << LINE << " by " << "MFX_ERR_NOT_IMPLEMENTED" << endl;
            break;
        case MFX_WRN_IN_EXECUTION:
            cerr << "warn in " << LINE << " by " << "MFX_WRN_IN_EXECUTION" << endl;
            break;
        case MFX_WRN_DEVICE_BUSY:
            cerr << "warn in " << LINE << " by " << "MFX_WRN_DEVICE_BUSY" << endl;
            break;
        case MFX_WRN_VIDEO_PARAM_CHANGED:
            cerr << "warn in " << LINE << " by " << "MFX_WRN_VIDEO_PARAM_CHANGED" << endl;
            break;
        case MFX_WRN_PARTIAL_ACCELERATION:
            cerr << "warn in " << LINE << " by " << "MFX_WRN_PARTIAL_ACCELERATION" << endl;
            break;
        case MFX_WRN_INCOMPATIBLE_VIDEO_PARAM:
            cerr << "warn in " << LINE << " by " << "MFX_WRN_INCOMPATIBLE_VIDEO_PARAM" << endl;
            break;
        case MFX_WRN_VALUE_NOT_CHANGED:
            cerr << "warn in " << LINE << " by " << "MFX_WRN_VALUE_NOT_CHANGED" << endl;
            break;
        case MFX_WRN_OUT_OF_RANGE:
            cerr << "warn in " << LINE << " by " << "MFX_WRN_OUT_OF_RANGE" << endl;
            break;
        case MFX_WRN_FILTER_SKIPPED:
            cerr << "warn in " << LINE << " by " << "MFX_WRN_FILTER_SKIPPED" << endl;
            break;
        case MFX_ERR_NONE_PARTIAL_OUTPUT:
            cerr << "warn in " << LINE << " by " << "MFX_ERR_NONE_PARTIAL_OUTPUT" << endl;
            break;
        case MFX_WRN_ALLOC_TIMEOUT_EXPIRED:
            cerr << "warn in " << LINE << " by " << "MFX_WRN_ALLOC_TIMEOUT_EXPIRED" << endl;
            break;
        case MFX_TASK_WORKING:
            cerr << "warn in " << LINE << " by " << "MFX_TASK_WORKING" << endl;
            break;
        case MFX_TASK_BUSY:
            cerr << "warn in " << LINE << " by " << "MFX_TASK_BUSY" << endl;
            break;
        case MFX_ERR_MORE_DATA_SUBMIT_TASK:
            cerr << "warn in " << LINE << " by " << "MFX_ERR_MORE_DATA_SUBMIT_TASK" << endl;
            break;
    }
    if (x < 0) {
        exit(x);
    }
}

#define CHECK(x) check(x,__LINE__)
#define BITSTREAM_BUFFER_SIZE 2000000;
#define ALIGN16(value) (((value + 15) >> 4) << 4)
const char *PATH = R"(C:\Users\tomokazu\friends-4385686.jpg)";

mfxStatus ReadEncodedStream(mfxBitstream &bs, FILE *f) {
    printf("ReadEncodedStream\n");
    cout << "offset: " << bs.DataOffset << endl;
    cout << "length: " << bs.DataLength << endl;
    memmove(bs.Data, bs.Data + bs.DataOffset, bs.DataLength);
    bs.DataOffset = 0;
    bs.DataLength += (mfxU32) fread(bs.Data + bs.DataLength, 1, bs.MaxLength - bs.DataLength, f);
    if (bs.DataLength == 0)
        return MFX_ERR_MORE_DATA;

    return MFX_ERR_NONE;
}

int main() {
    auto loader = MFXLoad();
    auto cfg = MFXCreateConfig(loader);
    mfxVariant variant;
    variant.Type = MFX_VARIANT_TYPE_U32;
    variant.Data.U32 = MFX_IMPL_TYPE_HARDWARE;
    CHECK(MFXSetConfigFilterProperty(cfg, reinterpret_cast<const mfxU8 *>("mfxImplDescription.Impl"), variant));
    variant.Type = MFX_VARIANT_TYPE_U32;
#ifdef WIN32
    variant.Data.U32 = MFX_ACCEL_MODE_VIA_D3D11;
#elifdef __linux__
    variant.Data.U32 = MFX_ACCEL_MODE_VIA_VAAPI;
#elifndef
    variant.Data.U32 = MFX_ACCEL_MODE_NA;
#endif
    CHECK(MFXSetConfigFilterProperty(cfg, reinterpret_cast<const mfxU8 *>("mfxImplDescription.AccelerationMode"),
                                     variant));
    variant.Data.U32 = MFX_CODEC_JPEG;
    CHECK(MFXSetConfigFilterProperty(cfg,
                                     reinterpret_cast<const mfxU8 *>("mfxImplDescription.mfxDecoderDescription.decoder.CodecID"),
                                     variant));
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

//                cout <<  << endl;
                MFXCreateSession(loader, i, &session);
                mfxIMPL impl;
                if (MFXQueryIMPL(session, &impl) == MFX_ERR_NONE) {
                    switch (impl & 0x0f00) {
                        case MFX_IMPL_VIA_D3D11:
                            cout << "Impl: MFX_IMPL_VIA_D3D11" << endl;
                            break;
                        case MFX_IMPL_VIA_VAAPI:
                            cout << "Impl: MFX_IMPL_VIA_VAAPI" << endl;
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
    if (impl_idx == -1) {
        cerr << "Cannot found suitable device." << endl;
        CHECK(MFX_ERR_NOT_FOUND);
    }

    mfxHDL hdl;
    MFXEnumImplementations(loader, impl_idx, mfxImplCapsDeliveryFormat::MFX_IMPLCAPS_IMPLEMENTEDFUNCTIONS, &hdl);
//    auto *implementedFunctions = static_cast<mfxImplementedFunctions *>(hdl);
//    std::for_each(implementedFunctions->FunctionsName,
//                  implementedFunctions->FunctionsName + implementedFunctions->NumFunctions,
//                  [](mfxChar *functionName) {
//                      cout << "implemented: " << functionName << endl;
//                  });
    MFXDispReleaseImplDescription(loader, hdl);


//    mfxHDL hdl;
    MFXEnumImplementations(loader, impl_idx, mfxImplCapsDeliveryFormat::MFX_IMPLCAPS_IMPLPATH, &hdl);
//    auto *extendedDeviceID = static_cast<mfxExtendedDeviceId *>(hdl);
    cout << "Driver PATH: " << reinterpret_cast<mfxChar *>(hdl) << endl;
    MFXDispReleaseImplDescription(loader, hdl);


    mfxBitstream bitstream = {};

    bitstream.MaxLength = BITSTREAM_BUFFER_SIZE;
    bitstream.DataFlag = MFX_BITSTREAM_COMPLETE_FRAME;
    bitstream.Data = static_cast<mfxU8 *>(calloc(bitstream.MaxLength, sizeof(mfxU8)));
    bitstream.CodecId = MFX_CODEC_JPEG;
    FILE *input_file;
    fopen_s(&input_file, PATH, "rb");
    if (input_file == nullptr) {
        cout << "fail to open file" << endl;
        exit(ERROR_FILE_NOT_FOUND);
    }
//    bitstream.DataLength += fread(bitstream.Data + bitstream.DataLength, 1, bitstream.MaxLength - bitstream.DataLength,
//                                  input_file);

    ReadEncodedStream(bitstream, input_file);

    mfxVideoParam decodeParams = {};
    mfxVideoParam decodeVPPParams = {};
    decodeParams.mfx.CodecId = MFX_CODEC_JPEG;
    decodeParams.IOPattern = MFX_IOPATTERN_OUT_VIDEO_MEMORY;
//    decodeParams.mfx.JPEGColorFormat = MFX_JPEG_COLORFORMAT_RGB;
//    decodeParams.mfx.JPEGChromaFormat = MFX_CHROMAFORMAT_YUV444;

//    decodeVPPParams.mfx.CodecId = MFX_CODEC_JPEG;
//    decodeVPPParams.IOPattern = MFX_IOPATTERN_OUT_VIDEO_MEMORY;

    CHECK(MFXVideoDECODE_DecodeHeader(session, &bitstream, &decodeParams));
//    CHECK(MFXVideoDECODE_VPP_DecodeHeader(session, &bitstream, &decodeVPPParams))
    cout << "size of mfxVideoChannelParam: " << sizeof(mfxVideoChannelParam) << endl;
    mfxVideoChannelParam **channelParam = nullptr;
    channelParam = new mfxVideoChannelParam *[2];
//    *channelParam = static_cast<mfxVideoChannelParam *>(calloc(2, sizeof(mfxVideoChannelParam)));
    channelParam[0] = new mfxVideoChannelParam;
    memset(channelParam[0], 0, sizeof(mfxVideoChannelParam));
    channelParam[1] = new mfxVideoChannelParam;
    memset(channelParam[1], 0, sizeof(mfxVideoChannelParam));
    {
        channelParam[0]->VPP.FourCC = MFX_FOURCC_RGB4;
        channelParam[0]->VPP.ChromaFormat = decodeParams.mfx.FrameInfo.ChromaFormat;
        channelParam[0]->VPP.PicStruct = MFX_PICSTRUCT_PROGRESSIVE;
        channelParam[0]->VPP.FrameRateExtN = decodeParams.mfx.FrameInfo.FrameRateExtN;
        channelParam[0]->VPP.FrameRateExtD = decodeParams.mfx.FrameInfo.FrameRateExtD;
        channelParam[0]->VPP.CropW = decodeParams.mfx.FrameInfo.CropW;
        channelParam[0]->VPP.CropH = decodeParams.mfx.FrameInfo.CropH;
        channelParam[0]->VPP.Width = ALIGN16(channelParam[0]->VPP.CropW);
        channelParam[0]->VPP.Height = ALIGN16(channelParam[0]->VPP.CropH);
        channelParam[0]->VPP.ChannelId = 1;
        channelParam[0]->Protected = 0;
        channelParam[0]->IOPattern = MFX_IOPATTERN_IN_VIDEO_MEMORY | MFX_IOPATTERN_OUT_VIDEO_MEMORY;
        channelParam[0]->ExtParam = nullptr;
        channelParam[0]->NumExtParam = 0;

        channelParam[1]->VPP.FourCC = MFX_FOURCC_RGBP;
        channelParam[1]->VPP.ChromaFormat = decodeParams.mfx.FrameInfo.ChromaFormat;
        channelParam[1]->VPP.PicStruct = MFX_PICSTRUCT_PROGRESSIVE;
        channelParam[1]->VPP.FrameRateExtN = decodeParams.mfx.FrameInfo.FrameRateExtN;
        channelParam[1]->VPP.FrameRateExtD = decodeParams.mfx.FrameInfo.FrameRateExtD;
        channelParam[1]->VPP.CropW = decodeParams.mfx.FrameInfo.CropW;
        channelParam[1]->VPP.CropH = decodeParams.mfx.FrameInfo.CropH;
        channelParam[1]->VPP.Width = ALIGN16(channelParam[1]->VPP.CropW);
        channelParam[1]->VPP.Height = ALIGN16(channelParam[1]->VPP.CropH);
        channelParam[1]->VPP.ChannelId = 2;
        channelParam[1]->Protected = 0;
        channelParam[1]->IOPattern = MFX_IOPATTERN_IN_VIDEO_MEMORY | MFX_IOPATTERN_OUT_VIDEO_MEMORY;
        channelParam[1]->ExtParam = nullptr;
        channelParam[1]->NumExtParam = 0;
    }

    CHECK(MFXVideoDECODE_VPP_Init(session, &decodeParams, channelParam, 2));

//    CHECK(MFXVideoDECODE_Init(session, &decodeParams))

    auto fourcc = decodeParams.mfx.FrameInfo.FourCC;
    auto mask = 0xff;
    auto fourcc_str = ""s + (char) (fourcc & mask) + (char) ((fourcc & mask << 8) >> 8) +
                      (char) ((fourcc & mask << 16) >> 16) + (char) ((fourcc & mask << 24) >> 24);
    cout << "image format name: " << fourcc_str << endl;
    if (fourcc != MFX_FOURCC_NV12) {
        CHECK(MFX_ERR_UNSUPPORTED);
    }
    mfxSurfaceArray *surface_out;
//    mfxSyncPoint syncPoint;
    bool isDraining = false;
    bool isStillGoing = true;
    mfxStatus sts;
    mfxU32 framenum = 0;
    mfxFrameSurface1 *aSurf;
    while (isStillGoing) {
        // Load encoded stream if not draining
        if (!isDraining) {
            cout << "read stream " << endl;
            sts = ReadEncodedStream(bitstream, input_file);
            if (sts != MFX_ERR_NONE)
                isDraining = true;
        }

        sts = MFXVideoDECODE_VPP_DecodeFrameAsync(session,
                                                  (isDraining) ? nullptr : &bitstream,
                                                  nullptr,
                                                  0,
                                                  &surface_out);
        cout << framenum << " :" << ((isDraining) ? "nullptr" : "&bitstream") << endl;

        cout << "Async status: " << sts << endl;
        switch (sts) {
            case MFX_ERR_NONE:
                // decode output
                if (surface_out == nullptr) {
                    printf("ERROR - empty array of surfaces.\n");
                    isStillGoing = false;
                    continue;
                }

                for (mfxU32 i = 0; i < surface_out->NumSurfaces; i++) {
                    aSurf = surface_out->Surfaces[i];
                    do {
                        sts = aSurf->FrameInterface->Synchronize(aSurf, 1000);
                        CHECK(sts);
                        if (sts == MFX_ERR_NONE) {
                            if (aSurf->Info.ChannelId == 0) { // decoder output
//                                sts = WriteRawFrame_InternalMem(aSurf, sinkDec);

                                CHECK(aSurf->FrameInterface->Map(aSurf, MFX_MAP_READ));
                                cout << "map" << endl;
                            }
                        }
                        if (sts != MFX_WRN_IN_EXECUTION) {
                            sts = aSurf->FrameInterface->Release(aSurf);
                            CHECK(sts);
                        }

                    } while (sts == MFX_WRN_IN_EXECUTION);
                }
                framenum++;

                sts = surface_out->Release(surface_out);
                CHECK(sts);
                surface_out = nullptr;

                break;

            case MFX_ERR_MORE_DATA:
                // The function requires more bitstream at input before decoding can proceed
                if (isDraining)
                    isStillGoing = false;
                break;
            default:
                printf("unknown status %d\n", sts);
                isStillGoing = false;
                break;
        }
    }



//    auto aSurf = surface_out->Surfaces[2];
}


//https://github.com/intel/libvpl/blob/383b5caac6df614e76ade5a07c4f53be702e9176/examples/api2x/hello-decvpp/src/hello-decvpp.cpp