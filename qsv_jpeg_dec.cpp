#include <iostream>
#include <vpl/mfx.h>
#include <algorithm>
#include <cstring>
#include <filesystem>
#include "BitmapPlusPlus.hpp"
//#include <sycl/CL/cl_d3d11.h>
using namespace std;
namespace fs = filesystem;

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
        throw x;
//        exit(x);
    }
}

#define CHECK(x) check(x,__LINE__)
#define BITSTREAM_BUFFER_SIZE 2000000;
#define ALIGN16(value) (((value + 15) >> 4) << 4)

mfxSession *createSession() {
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
    auto *session = static_cast<mfxSession *>(malloc(sizeof(mfxSession)));
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
                MFXCreateSession(loader, i, session);
                mfxIMPL impl;
                if (MFXQueryIMPL(*session, &impl) == MFX_ERR_NONE) {
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
    MFXUnload(loader);
    return session;
}


pair<pair<mfxU16, mfxU16>, mfxU8 *> decodeStream(mfxSession session, vector<char> data_stream) {
    mfxBitstream bitstream = {};

    bitstream.MaxLength = data_stream.size();
    bitstream.DataFlag = MFX_BITSTREAM_COMPLETE_FRAME;
    bitstream.Data = static_cast<mfxU8 *>(calloc(bitstream.MaxLength, sizeof(mfxU8)));
    bitstream.CodecId = MFX_CODEC_JPEG;
//    FILE *input_file;
//    fopen_s(&input_file, R"(C:\Users\tomokazu\friends-4385686.jpg)", "rb");
//    if (input_file == nullptr) {
//        cout << "fail to open file" << endl;
//        exit(-1);
//    }
//    bitstream.DataLength += fread(bitstream.Data + bitstream.DataLength, 1, bitstream.MaxLength - bitstream.DataLength,
//                                  input_file);
    bitstream.DataLength = data_stream.size();
    copy(data_stream.begin(), data_stream.end(), bitstream.Data);
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
    if (channelParam == nullptr) {
        CHECK(MFX_ERR_NULL_PTR);
        exit(-1);
    }
    memset(channelParam, 0, sizeof(mfxVideoChannelParam));
    channelParam->VPP.FourCC = MFX_FOURCC_RGB4;
//    channelParam->VPP.ChromaFormat = decodeParams.mfx.FrameInfo.ChromaFormat;
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

    mfxStatus status;
    switch (status = MFXVideoDECODE_VPP_Init(session, &decodeParams, &channelParam, 1)) {
        case MFX_ERR_NONE:
            break;
        default:
            MFXVideoDECODE_VPP_Close(session);
            check(status, 248);
    };

//    CHECK(MFXVideoDECODE_Init(session, &decodeParams))

    auto fourcc = decodeParams.mfx.FrameInfo.FourCC;
    auto mask = 0xff;
    auto fourcc_str = ""s + (char) (fourcc & mask) + (char) ((fourcc & mask << 8) >> 8) +
                      (char) ((fourcc & mask << 16) >> 16) + (char) ((fourcc & mask << 24) >> 24);
    cout << "image format name: " << fourcc_str << endl;
    if (fourcc != MFX_FOURCC_NV12)CHECK(MFX_ERR_NOT_IMPLEMENTED);
    mfxSurfaceArray *surface_out;
//    mfxSyncPoint syncPoint;

    auto start = clock();
    CHECK(MFXVideoDECODE_VPP_DecodeFrameAsync(session, &bitstream, nullptr, 0, &surface_out));

    CHECK(surface_out->Surfaces[0]->FrameInterface->Synchronize(surface_out->Surfaces[0], 1000));
    CHECK(surface_out->Surfaces[0]->FrameInterface->Release(surface_out->Surfaces[0]));
    auto aSurf = surface_out->Surfaces[1];
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
    auto *return_buff = static_cast<mfxU8 *>(malloc(sizeof(mfxU8) * w * h * 4));
    for (int i = 0; i < h; ++i) {
        memcpy(return_buff + 4 * w * i, data->B + pitch * i, w * 4);
    }
//    MFXVideoVPP_Close(session);
    aSurf->FrameInterface->Release(aSurf);
    free(bitstream.Data);
    free(channelParam);
    MFXVideoDECODE_VPP_Close(session);
    return {{w, h}, return_buff};
}

int main() {
//    string PATH = R"(C:\Users\tomokazu\friends-4385686.jpg)";
    mfxSession *session = createSession();

    auto dir_iterator = fs::directory_iterator(R"(C:\Users\tomokazu\CLionProjects\oneAPI_test\test_files)");
    for (auto &path: dir_iterator) {
        cout << path.path().string() << endl;

        ifstream input_file(path.path().string(), ios::binary | ios::in);
        if (!input_file) {
            cerr << "failed to open file" << endl;
        }
        vector<char> data{istreambuf_iterator<char>(input_file), istreambuf_iterator<char>()};
        try {
            auto out = decodeStream(*session, data);
        } catch (const mfxStatus) {
            cout << "failed to decode :" << path.path().string() << endl;
        }
    }


    free(session);
}
//https://github.com/intel/libvpl/blob/383b5caac6df614e76ade5a07c4f53be702e9176/examples/api2x/hello-decvpp/src/hello-decvpp.cpp