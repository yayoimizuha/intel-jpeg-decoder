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

    mfxBitstream bitstream = {};

    bitstream.MaxLength = BITSTREAM_BUFFER_SIZE;
    bitstream.DataFlag = MFX_BITSTREAM_COMPLETE_FRAME;
    bitstream.Data = static_cast<mfxU8 *>(calloc(bitstream.MaxLength, sizeof(mfxU8)));
    bitstream.CodecId = MFX_CODEC_JPEG;
    FILE *input_file;
    fopen_s(&input_file, PATH, "rb");
    if (input_file == nullptr) {
        cout << "fail to open file" << endl;
        exit(-1);
    }
    bitstream.DataLength += fread(bitstream.Data + bitstream.DataLength, 1, bitstream.MaxLength - bitstream.DataLength,
                                  input_file);

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
    auto *channelParam = static_cast<mfxVideoChannelParam *>(malloc(sizeof(mfxVideoChannelParam)));
    memset(channelParam, 0, sizeof(mfxVideoChannelParam));
    channelParam->VPP.FourCC = MFX_FOURCC_RGB4;
    channelParam->VPP.ChromaFormat = decodeParams.mfx.FrameInfo.ChromaFormat;
    channelParam->VPP.PicStruct = MFX_PICSTRUCT_PROGRESSIVE;
    channelParam->VPP.FrameRateExtN = decodeParams.mfx.FrameInfo.FrameRateExtN;
    channelParam->VPP.FrameRateExtD = decodeParams.mfx.FrameInfo.FrameRateExtD;
    channelParam->VPP.CropW = decodeParams.mfx.FrameInfo.CropW;
    channelParam->VPP.CropH = decodeParams.mfx.FrameInfo.CropH;
    channelParam->VPP.Width = ALIGN16(channelParam->VPP.CropW);
    channelParam->VPP.Height = ALIGN16(channelParam->VPP.CropH);
    channelParam->VPP.ChannelId = 1;
    channelParam->Protected = 0;
    channelParam->IOPattern = MFX_IOPATTERN_IN_VIDEO_MEMORY | MFX_IOPATTERN_OUT_VIDEO_MEMORY;
    channelParam->ExtParam = nullptr;
    channelParam->NumExtParam = 0;


    CHECK(MFXVideoDECODE_VPP_Init(session, &decodeParams, &channelParam, 1));

//    CHECK(MFXVideoDECODE_Init(session, &decodeParams))

    auto fourcc = decodeParams.mfx.FrameInfo.FourCC;
    auto mask = 0xff;
    auto fourcc_str = ""s + (char) (fourcc & mask) + (char) ((fourcc & mask << 8) >> 8) +
                      (char) ((fourcc & mask << 16) >> 16) + (char) ((fourcc & mask << 24) >> 24);
    cout << "image format name: " << fourcc_str << endl;
    if (fourcc != MFX_FOURCC_NV12)exit(-1);
    mfxSurfaceArray *surface_out;
//    mfxSyncPoint syncPoint;

    auto start = clock();
    CHECK(MFXVideoDECODE_VPP_DecodeFrameAsync(session, &bitstream, nullptr, 0, &surface_out));

    CHECK(surface_out->Surfaces[0]->FrameInterface->Synchronize(surface_out->Surfaces[0], 1000));
    CHECK(surface_out->Surfaces[0]->FrameInterface->Release(surface_out->Surfaces[0]));
    auto aSurf = surface_out->Surfaces[1];
    mfxHDL handle = nullptr;
    mfxResourceType resourceType;
    CHECK(aSurf->FrameInterface->GetNativeHandle(aSurf, &handle, &resourceType));
    auto *texture = static_cast<ID3D11Texture2D *>(handle);
    cout << "Resource type: ";
    switch (resourceType) {
        case MFX_RESOURCE_SYSTEM_SURFACE:
            cout << "MFX_RESOURCE_SYSTEM_SURFACE";
            break;
        case MFX_RESOURCE_VA_SURFACE_PTR:
            cout << "MFX_RESOURCE_VA_SURFACE_PTR";
            break;
        case MFX_RESOURCE_VA_BUFFER_PTR:
            cout << "MFX_RESOURCE_VA_BUFFER_PTR";
            break;
        case MFX_RESOURCE_DX9_SURFACE:
            cout << "MFX_RESOURCE_DX9_SURFACE";
            break;
        case MFX_RESOURCE_DX11_TEXTURE:
            cout << "MFX_RESOURCE_DX11_TEXTURE";
            break;
        case MFX_RESOURCE_DX12_RESOURCE:
            cout << "MFX_RESOURCE_DX12_RESOURCE";
            break;
        case MFX_RESOURCE_DMA_RESOURCE:
            cout << "MFX_RESOURCE_DMA_RESOURCE";
            break;
        case MFX_RESOURCE_HDDLUNITE_REMOTE_MEMORY:
            cout << "MFX_RESOURCE_HDDLUNITE_REMOTE_MEMORY";
            break;
    }
    cout << endl;
    cout << handle << endl;
    CHECK(aSurf->FrameInterface->Synchronize(aSurf, 1000));
    cout << (clock() - start) << "ms" << endl;
    CHECK(aSurf->FrameInterface->Map(aSurf, MFX_MAP_READ));
    auto *info = &aSurf->Info;
    auto *data = &aSurf->Data;
    auto pitch = data->Pitch;
    auto h = info->CropH;
    auto w = info->CropW;
    cout << "pitch :" << pitch << endl;
    cout << w << "x" << h << endl;

    fourcc = info->FourCC;
    fourcc_str = ""s + (char) (fourcc & mask) + (char) ((fourcc & mask << 8) >> 8) +
                 (char) ((fourcc & mask << 16) >> 16) + (char) ((fourcc & mask << 24) >> 24);
    cout << "image format name: " << fourcc_str << endl;
    uint32_t file_size = 54 + w * h * 4;
    auto *bitmap = static_cast<uint8_t *>(calloc(file_size, sizeof(uint8_t)));
    auto rgb = fopen("rgb_bmp.bmp", "wb");
//    struct BitmapFileHeader {
//        uint16_t bfType;
//        uint32_t bfSize;
//        uint16_t bfReserved1;
//        uint16_t bfReserved2;
//        uint32_t bfOffBits;
//    } header{};
    BITMAPFILEHEADER header = {};
//    struct BitmapInfoHeader {
//        uint32_t biSize;
//        int32_t biWidth;
//        int32_t biHeight;
//        uint16_t biPlanes;
//        uint16_t biBitCount;
//        uint32_t biCompression;
//        uint32_t biSizeImage;
//        int32_t biXPelsPerMeter;
//        int32_t biYPelsPerMeter;
//        uint32_t biClrUsed;
//        uint32_t biClrImportant;
//    } infoHeader{};
    BITMAPINFOHEADER infoHeader = {};
    memset(&header, '\0', sizeof(header));
    memset(&infoHeader, '\0', sizeof(infoHeader));
    memcpy(&header.bfType, "BM", 2);
    header.bfSize = 0;
    sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + w * h * 4;
    header.bfOffBits = 0;
    sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    infoHeader.biSize = 40;
    infoHeader.biWidth = w;
    infoHeader.biHeight = -h;
    infoHeader.biPlanes = 1;
    infoHeader.biBitCount = 32;
    infoHeader.biCompression = 0;
    infoHeader.biSizeImage = 0;
    cout << sizeof(header) << endl;
    cout << sizeof(infoHeader) << endl;
    fwrite(&header, sizeof(header), 1, rgb);
    fwrite(&infoHeader, sizeof(infoHeader), 1, rgb);
    for (int i = 0; i < h; ++i) {
        fwrite(data->B + i * pitch, sizeof(data->B[0]) * w * 4, 1, rgb);
    }
    fclose(rgb);



    //    bmp::Bitmap img(w, h);
//    for (int i = 0; i < h; ++i) {
//        for (int j = 0; j < w; ++j) {
//            bmp::Pixel pixel;
//            pixel.r = *(data->R + i * pitch + 4 * j);
//            pixel.g = *(data->G + i * pitch + 4 * j);
//            pixel.b = *(data->B + i * pitch + 4 * j);
//            img.set(j, i, pixel);
//        }
//
//    }
//    aSurf->FrameInterface->Release(aSurf);
//    img.save("rgb.bmp");
    MFXVideoVPP_Close(session);
}


//https://github.com/intel/libvpl/blob/383b5caac6df614e76ade5a07c4f53be702e9176/examples/api2x/hello-decvpp/src/hello-decvpp.cpp