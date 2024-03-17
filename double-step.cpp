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
const char *PATH = R"(C:\Users\tomokazu\CLionProjects\oneAPI_test\test_files\12810158756-1.jpg)";

string fourcc_conv(mfxU32 fourcc) {
    auto mask = 0xff;
    return ""s + (char) (fourcc & mask) + (char) ((fourcc & mask << 8) >> 8) + (char) ((fourcc & mask << 16) >> 16) +
           (char) ((fourcc & mask << 24) >> 24);
}

int main(int argc, char *argv[]) {
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
    MFXDispReleaseImplDescription(loader, hdl);

    mfxBitstream bitstream = {};

    bitstream.MaxLength = BITSTREAM_BUFFER_SIZE;
    bitstream.DataFlag = MFX_BITSTREAM_COMPLETE_FRAME;
    bitstream.Data = static_cast<mfxU8 *>(calloc(bitstream.MaxLength, sizeof(mfxU8)));
    bitstream.CodecId = MFX_CODEC_JPEG;
    FILE *input_file;
    cout << "0: " << argv[0] << endl;
    cout << "1: " << argv[1] << endl;
    fopen_s(&input_file, argv[1], "rb");
    if (input_file == nullptr) {
        cout << "fail to open file" << endl;
        exit(-1);
    }
    bitstream.DataLength += fread(bitstream.Data + bitstream.DataLength, 1, bitstream.MaxLength - bitstream.DataLength,
                                  input_file);

    mfxVideoParam decodeParams = {};
//    mfxVideoParam decodeVPPParams = {};
    decodeParams.mfx.CodecId = MFX_CODEC_JPEG;
//    decodeParams.mfx.JPEGChromaFormat = MFX_CHROMAFORMAT_YUV420;
    decodeParams.mfx.JPEGColorFormat = MFX_JPEG_COLORFORMAT_YCbCr;
    decodeParams.mfx.JPEGChromaFormat = MFX_CHROMAFORMAT_YUV444;
    decodeParams.IOPattern = MFX_IOPATTERN_OUT_VIDEO_MEMORY;
    CHECK(MFXVideoDECODE_DecodeHeader(session, &bitstream, &decodeParams));


    cout << "CropW: " << decodeParams.vpp.In.CropW << endl;
    cout << "CropH: " << decodeParams.vpp.In.CropH << endl;
    cout << "CropX: " << decodeParams.vpp.In.CropX << endl;
    cout << "CropY: " << decodeParams.vpp.In.CropY << endl;
    cout << "Width: " << decodeParams.vpp.In.Width << endl;
    cout << "Height: " << decodeParams.vpp.In.Height << endl;
//    cout << "BufferSize: " << decodeParams.vpp.In.BufferSize << endl;
    cout << "ChromaFormat: " << decodeParams.vpp.Out.ChromaFormat << endl;
    cout << "FourCC: " << decodeParams.vpp.In.FourCC << endl;
    cout << "PicStruct: " << decodeParams.vpp.In.PicStruct << endl;


    auto fourcc = fourcc_conv(decodeParams.mfx.FrameInfo.FourCC);

    cout << "image format name: " << fourcc << endl;
    if (decodeParams.mfx.FrameInfo.FourCC != MFX_FOURCC_NV12)exit(-1);


    CHECK(MFXVideoDECODE_Init(session, &decodeParams));

    mfxFrameSurface1 *surface_out;
    mfxSyncPoint syncPoint;
    cout << "start decode" << endl;


    auto start = clock();
    CHECK(MFXVideoDECODE_DecodeFrameAsync(session, &bitstream, nullptr, &surface_out, &syncPoint));
    CHECK(surface_out->FrameInterface->Synchronize(surface_out, 1000));
//    CHECK(surface_out->FrameInterface->Map(surface_out, MFX_MAP_READ));
//    cout << surface_out->Info.CropH << endl;
//    auto pitch = surface_out->Data.Pitch;
//    auto w = decodeParams.vpp.In.CropW;
//    auto h = decodeParams.vpp.In.CropH;
//    auto data_size = sizeof(mfxU8) * (w * h + (w >> 1) * (h >> 1) + (w >> 1) * (h >> 1));
//    auto raw_data = static_cast<mfxU8 *>(malloc(data_size));
//    memcpy(raw_data, surface_out->Data.Y, data_size);
//    CHECK(surface_out->FrameInterface->Unmap(surface_out));
//    CHECK(surface_out->FrameInterface->Release(surface_out));
//    CHECK(MFXVideoDECODE_Close(session));
    mfxVideoParam VPPParams = {};
    VPPParams.IOPattern = MFX_IOPATTERN_IN_VIDEO_MEMORY | MFX_IOPATTERN_OUT_VIDEO_MEMORY;
    {
        VPPParams.vpp.In.FourCC = decodeParams.mfx.FrameInfo.FourCC;
        VPPParams.vpp.In.ChromaFormat = decodeParams.mfx.FrameInfo.ChromaFormat;
        VPPParams.vpp.In.CropX = decodeParams.vpp.In.CropX;
        VPPParams.vpp.In.CropY = decodeParams.vpp.In.CropY;
        VPPParams.vpp.In.CropW = decodeParams.vpp.In.CropW;
        VPPParams.vpp.In.CropH = decodeParams.vpp.In.CropH;
        VPPParams.vpp.In.PicStruct = MFX_PICSTRUCT_PROGRESSIVE;
        VPPParams.vpp.In.FrameRateExtN = 30;
        VPPParams.vpp.In.FrameRateExtD = 1;
        VPPParams.vpp.In.Width = ALIGN16(VPPParams.vpp.In.CropW);
        VPPParams.vpp.In.Height = ALIGN16(VPPParams.vpp.In.CropH);
    }
    {
        VPPParams.vpp.Out.FourCC = MFX_FOURCC_BGRA;
//        VPPParams.vpp.Out.ChromaFormat = MFX_CHROMAFORMAT_YUV444;
        VPPParams.vpp.Out.CropX = decodeParams.vpp.In.CropX;
        VPPParams.vpp.Out.CropY = decodeParams.vpp.In.CropY;
        VPPParams.vpp.Out.CropW = ALIGN16(decodeParams.vpp.In.CropW);
        VPPParams.vpp.Out.CropH = ALIGN16(decodeParams.vpp.In.CropH);
        VPPParams.vpp.Out.PicStruct = MFX_PICSTRUCT_PROGRESSIVE;
        VPPParams.vpp.Out.FrameRateExtN = 30;
        VPPParams.vpp.Out.FrameRateExtD = 1;
        VPPParams.vpp.Out.Width = ALIGN16(VPPParams.vpp.Out.CropW);
        VPPParams.vpp.Out.Height = ALIGN16(VPPParams.vpp.Out.CropH);
    }
    CHECK(MFXVideoVPP_Init(session, &VPPParams));
    mfxFrameSurface1 *surface_vpp_in, *surface_vpp_out = nullptr;
    CHECK(MFXMemory_GetSurfaceForVPPIn(session, &surface_vpp_in));
    CHECK(MFXMemory_GetSurfaceForVPPOut(session, &surface_vpp_out));
    CHECK(surface_out->FrameInterface->Map(surface_out, MFX_MAP_READ));
    CHECK(surface_vpp_in->FrameInterface->Map(surface_vpp_in, MFX_MAP_WRITE));
    auto pitch = surface_out->Data.Pitch;
    for (int h = 0; h < surface_out->Info.CropH; ++h) {
        memcpy(surface_vpp_in->Data.Y + pitch * h, surface_out->Data.Y + pitch * h,
               surface_out->Info.CropW);
    }

    for (int h = 0; h < surface_out->Info.CropH / 2; ++h) {
        memcpy(surface_vpp_in->Data.UV + pitch * h, surface_out->Data.UV + pitch * h,
               surface_out->Info.CropW);
    }

//    for (int h = 0; h < surface_out->Info.CropH ; ++h) {
//        memcpy(surface_vpp_in->Data.V + pitch * h, surface_out->Data.V + pitch * h,
//               surface_out->Info.CropW);
//    }
    cout << "size: " << static_cast<int>(surface_out->Data.Pitch * surface_out->Info.Height * 1.5) << endl;
    cout << "pitch: " << pitch << endl;

    CHECK(surface_out->FrameInterface->Unmap(surface_out));
    CHECK(surface_vpp_in->FrameInterface->Unmap(surface_vpp_in));


    CHECK(MFXVideoVPP_RunFrameVPPAsync(session, surface_out, surface_vpp_out, nullptr, &syncPoint));
    CHECK(surface_vpp_out->FrameInterface->Synchronize(surface_vpp_out, 1000));
    CHECK(surface_vpp_out->FrameInterface->Map(surface_vpp_out, MFX_MAP_READ));
    for (int i = 0; i < 10; ++i) {
        printf("%#x\t", surface_vpp_out->Data.B[i]);
    }

    bmp::Bitmap save_image(VPPParams.vpp.Out.CropW, VPPParams.vpp.Out.CropH);
    for (int h = 0; h < VPPParams.vpp.Out.CropH; ++h) {
        for (int w = 0; w < VPPParams.vpp.Out.CropW; ++w) {
            bmp::Pixel pixel;
            pixel.r = *(surface_vpp_out->Data.R + surface_vpp_out->Data.Pitch * h + w * 4);
            pixel.g = *(surface_vpp_out->Data.G + surface_vpp_out->Data.Pitch * h + w * 4);
            pixel.b = *(surface_vpp_out->Data.B + surface_vpp_out->Data.Pitch * h + w * 4);
            save_image.set(w, h, pixel);
        }
    }
    save_image.save("double-step.bmp");

}


//https://github.com/intel/libvpl/blob/383b5caac6df614e76ade5a07c4f53be702e9176/examples/api2x/hello-decvpp/src/hello-decvpp.cpp