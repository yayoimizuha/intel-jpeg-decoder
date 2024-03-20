#include <iostream>
#include <vpl/mfx.h>
#include <algorithm>
#include <cstring>
#include <filesystem>
#include "BitmapPlusPlus.hpp"
#include <sycl/sycl.hpp>

using namespace std;
using namespace chrono;
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
        exit(x);
    }
}

pair<mfxU16, mfxU16> size_from_header(mfxU8 *data, mfxU32 size) {
    mfxU32 ptr = 0;
    mfxU16 segment_size;
    if (data[ptr] != 0xff || data[ptr + 1] != 0xd8)return {0, 0};
    ptr += 2;
    while (ptr < size) {
        if (data[ptr] == 0xff && (data[ptr + 1] & 0xf0) == 0xc0) {
            return {(data[ptr + 5] << 8) + data[ptr + 6], (data[ptr + 7] << 8) + data[ptr + 8]};
        }
        segment_size = (data[ptr + 2] << 8) + data[ptr + 3];
        ptr += segment_size + 2;
    }
    return {0, 0};
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
#ifdef _WIN32
    variant.Data.U32 = MFX_ACCEL_MODE_VIA_D3D11;
#elifdef __linux__
    variant.Data.U32 = MFX_ACCEL_MODE_VIA_VAAPI;
#else
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

sycl::queue createSYCLQueue() {
    auto syclDevice = sycl::device(sycl::gpu_selector_v);
    sycl::queue syclQueue(syclDevice);
    cout << "SYCL Device name: " << syclDevice.get_info<sycl::info::device::name>() << endl;
    cout << "SYCL Device vendor: " << syclDevice.get_info<sycl::info::device::vendor>() << endl;
    return syclQueue;
}

pair<pair<mfxU16, mfxU16>, mfxU8 *> decodeStream(mfxSession session, vector<char> data_stream, sycl::queue syclQueue) {
    mfxBitstream bitstream = {};

    bitstream.MaxLength = data_stream.size() + 100;
    bitstream.DataFlag = MFX_BITSTREAM_COMPLETE_FRAME;
    bitstream.Data = static_cast<mfxU8 *>(calloc(bitstream.MaxLength, sizeof(mfxU8)));
    bitstream.CodecId = MFX_CODEC_JPEG;

    bitstream.DataLength = data_stream.size();
    copy(data_stream.begin(), data_stream.end(), bitstream.Data);
    mfxVideoParam decodeParams = {};

    decodeParams.mfx.CodecId = MFX_CODEC_JPEG;
    decodeParams.IOPattern = MFX_IOPATTERN_OUT_VIDEO_MEMORY;

    auto [height, width] = size_from_header(bitstream.Data, bitstream.DataLength);

    CHECK(MFXVideoDECODE_DecodeHeader(session, &bitstream, &decodeParams));


    mfxStatus status;
    switch (status = MFXVideoDECODE_Init(session, &decodeParams)) {
        case MFX_ERR_NONE:
            break;
        default:
            MFXVideoDECODE_Close(session);
            check(status, 241);
    };


    mfxFrameSurface1 *surface_out;
    mfxSyncPoint syncPoint;

    auto start_jpeg_dec = system_clock::now();
    CHECK(MFXVideoDECODE_DecodeFrameAsync(session, &bitstream, nullptr, &surface_out, &syncPoint));
    CHECK(surface_out->FrameInterface->Synchronize(surface_out, 1000));
    cout << "decode JPEG: " << duration_cast<microseconds>((system_clock::now() - start_jpeg_dec)).count() << "us" << endl;

    CHECK(surface_out->FrameInterface->Map(surface_out, MFX_MAP_READ));


    auto data = surface_out->Data;
    auto pitch = data.Pitch;
    auto *sycl_Y = sycl::malloc_device<mfxU8>(pitch * height, syclQueue);
    syclQueue.memcpy(sycl_Y, data.Y, pitch * height).wait();
    auto *sycl_UV = sycl::malloc_device<mfxU8>(pitch * (height / 2), syclQueue);
    syclQueue.memcpy(sycl_UV, data.UV, pitch * (height / 2)).wait();
    auto *sycl_RGB = sycl::malloc_device<mfxU8>(width * height * 3, syclQueue);
//    cout << "begin color conversion..." << endl;
    auto start_color_conv = system_clock::now();
    try {
        syclQueue.submit([&](sycl::handler &syclHandler) {
            syclHandler.parallel_for<class ColorConversion>(sycl::range<1>(width * height), [=](sycl::id<1> i) {
                auto h = i / width;
                auto w = i % width;
                auto U_ptr = pitch * (h / 2) + (w / 2) * 2;
                auto Y = static_cast<float>(sycl_Y[pitch * h + w]);
                auto U = static_cast<float>(sycl_UV[U_ptr]);
                auto V = static_cast<float>(sycl_UV[U_ptr + 1]);
                auto r = 1.164F * (Y - 16.0F) + 1.596F * (V - 128.0F);
                auto g = 1.164F * (Y - 16.0F) - 0.391F * (U - 128.0F) - 0.813F * (V - 128.0F);
                auto b = 1.164F * (Y - 16.0F) + 2.018F * (U - 128.0F);
                sycl_RGB[i * 3 + 0] = static_cast<mfxU8>(min(255.0F, max(.0F, r)));
                sycl_RGB[i * 3 + 1] = static_cast<mfxU8>(min(255.0F, max(.0F, g)));
                sycl_RGB[i * 3 + 2] = static_cast<mfxU8>(min(255.0F, max(.0F, b)));
            });
        });
        syclQueue.wait();
    } catch (sycl::exception &exception) {
        cerr << exception.what() << endl;
        return {{width, height}, nullptr};
    }
    cout << "end color conversion in " << duration_cast<microseconds>((system_clock::now() - start_color_conv)).count() << "us" << endl;

    auto hostRGB = static_cast<mfxU8 *>(malloc(height * width * 3));
    syclQueue.memcpy(hostRGB, sycl_RGB, height * width * 3).wait();
    sycl::free(sycl_Y, syclQueue);
    sycl::free(sycl_UV, syclQueue);
    sycl::free(sycl_RGB, syclQueue);
    MFXVideoDECODE_Close(session);
    free(bitstream.Data);
    return {{width, height}, hostRGB};
}

int main() {
//    string PATH = R"(C:\Users\tomokazu\friends-4385686.jpg)";
    auto *session = createSession();
    auto queue = createSYCLQueue();

    auto dir_iterator = fs::directory_iterator(R"(C:\Users\tomokazu\CLionProjects\intel-jpeg-decoder\test_files)");
    for (auto &path: dir_iterator) {
        cout << path.path().string() << endl;

        ifstream input_file(path.path().string(), ios::binary | ios::in);
        if (!input_file) {
            cerr << "failed to open file" << endl;
        }
        vector<char> data{istreambuf_iterator<char>(input_file), istreambuf_iterator<char>()};
        try {
            auto out = decodeStream(*session, data, queue);
            free(out.second);
        } catch (exception &e) {
            cout << "failed to decode :" << path.path().string() << "by" << e.what() << endl;
        }

    }


    free(session);
}
//https://github.com/intel/libvpl/blob/383b5caac6df614e76ade5a07c4f53be702e9176/examples/api2x/hello-decvpp/src/hello-decvpp.cpp