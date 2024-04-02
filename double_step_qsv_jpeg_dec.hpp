#include <vpl/mfx.h>
#include <sycl/sycl.hpp>

using namespace std;
using namespace chrono;

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
        cerr << x << endl;
        runtime_error(to_string(x));
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
#define BITSTREAM_BUFFER_SIZE 2000000
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

sycl::queue *createSYCLQueue() {
    auto syclDevice = sycl::device(sycl::gpu_selector_v);
    static sycl::queue syclQueue(syclDevice);
    cout << "SYCL Device name: " << syclDevice.get_info<sycl::info::device::name>() << endl;
    cout << "SYCL Device vendor: " << syclDevice.get_info<sycl::info::device::vendor>() << endl;
    return &syclQueue;
}

sycl::queue *syclQueue = nullptr;
mfxSession *session = nullptr;

struct decodeInput {
    size_t size;
    mfxU8 *data;
    void *metadata;
};
struct decodeOutput {
    size_t width;
    size_t height;
    mfxU8 *data;
    void *metadata;
};

decodeOutput decodeStream(decodeInput data_stream) {
    mfxBitstream bitstream = {};
    if (syclQueue == nullptr)syclQueue = createSYCLQueue();
    if (session == nullptr)session = createSession();

    bitstream.MaxLength = BITSTREAM_BUFFER_SIZE;
    bitstream.DataFlag = MFX_BITSTREAM_COMPLETE_FRAME;
    bitstream.Data = static_cast<mfxU8 *>(calloc(bitstream.MaxLength, sizeof(mfxU8)));
    bitstream.CodecId = MFX_CODEC_JPEG;

    bitstream.DataLength = data_stream.size;
    memcpy(bitstream.Data, data_stream.data, data_stream.size);
    free(data_stream.data);
//    data_stream.data = nullptr;
    mfxVideoParam decodeParams = {};

    decodeParams.mfx.CodecId = MFX_CODEC_JPEG;
    decodeParams.IOPattern = MFX_IOPATTERN_OUT_VIDEO_MEMORY;

    auto [height, width] = size_from_header(bitstream.Data, bitstream.DataLength);

    CHECK(MFXVideoDECODE_DecodeHeader(*session, &bitstream, &decodeParams));


    mfxStatus status;
    switch (status = MFXVideoDECODE_Init(*session, &decodeParams)) {
        case MFX_ERR_NONE:
            break;
        default:
            MFXVideoDECODE_Close(*session);
            check(status, 255);
    };


    mfxFrameSurface1 *surface_out = nullptr;
    mfxSyncPoint syncPoint;

    auto start_jpeg_dec = system_clock::now();
    CHECK(MFXVideoDECODE_DecodeFrameAsync(*session, &bitstream, nullptr, &surface_out, &syncPoint));
    CHECK(surface_out->FrameInterface->Synchronize(surface_out, 1000));
    cout << "decode JPEG: " << duration_cast<microseconds>((system_clock::now() - start_jpeg_dec)).count() << "us"
         << endl;

    CHECK(surface_out->FrameInterface->Map(surface_out, MFX_MAP_READ));


    auto data = surface_out->Data;
    auto pitch = data.Pitch;
    auto *sycl_Y = sycl::malloc_device<mfxU8>(pitch * height, *syclQueue);
    syclQueue->memcpy(sycl_Y, data.Y, pitch * height).wait();
    auto *sycl_UV = sycl::malloc_device<mfxU8>(pitch * (height / 2), *syclQueue);
    syclQueue->memcpy(sycl_UV, data.UV, pitch * (height / 2)).wait();
    auto *sycl_RGB = sycl::malloc_device<mfxU8>(width * height * 3, *syclQueue);
    auto *sycl_WidthPitch = sycl::malloc_device<mfxU16>(10, *syclQueue);
    unsigned short WidthPitch[2] = {width, pitch};
    syclQueue->memcpy(sycl_WidthPitch, WidthPitch, 2).wait();
//    cout << "begin color conversion..." << endl;
    auto start_color_conv = system_clock::now();
//    constexpr sycl::specialization_id<pair<mfxU16, mfxU16>> size_pair;
    sycl::range<1> range{static_cast<size_t>(width * height)};
    try {
        syclQueue->submit([&](sycl::handler &syclHandler) {
            syclHandler.parallel_for<class ColorConversion>(
                    range, [=](sycl::id<1> i) {
                        auto h = i / width;
                        auto w = i % width;
                        auto U_ptr = pitch * (h / 2) + (w / 2) * 2;
                        auto Y = static_cast<sycl::half>(sycl_Y[pitch * h + w]);
                        auto U = static_cast<sycl::half>(sycl_UV[U_ptr]);
                        auto V = static_cast<sycl::half>(sycl_UV[U_ptr + 1]);
                        auto r = sycl::half(1.164) * (Y - sycl::half(16.0)) +
                                 sycl::half(1.596) * (V - (sycl::half(128.0)));
                        auto g = sycl::half(1.164) * (Y - sycl::half(16.0)) -
                                 sycl::half(0.391) * (U - sycl::half(128.0)) -
                                 sycl::half(0.813) * (V - sycl::half(128.0));
                        auto b = sycl::half(1.164) * (Y - sycl::half(16.0)) +
                                 sycl::half(2.018) * (U - sycl::half(128.0));
                        sycl_RGB[i * 3 + 0] = static_cast<mfxU8>(min(sycl::half(255.0), max(sycl::half(0), r)));
                        sycl_RGB[i * 3 + 1] = static_cast<mfxU8>(min(sycl::half(255.0), max(sycl::half(0), g)));
                        sycl_RGB[i * 3 + 2] = static_cast<mfxU8>(min(sycl::half(255.0), max(sycl::half(0), b)));
                    });
        });
        syclQueue->wait();
    } catch (sycl::exception &exception) {
        cerr << exception.what() << endl;
        return {0, 0, nullptr};
    }
    sycl::free(sycl_WidthPitch, *syclQueue);
    cout << "end color conversion in " << duration_cast<microseconds>((system_clock::now() - start_color_conv)).count()
         << "us" << endl;

    auto hostRGB = static_cast<mfxU8 *>(malloc(height * width * 3));
    syclQueue->memcpy(hostRGB, sycl_RGB, height * width * 3).wait();
    sycl::free(sycl_Y, *syclQueue);
    sycl::free(sycl_UV, *syclQueue);
    sycl::free(sycl_RGB, *syclQueue);
    MFXVideoDECODE_Close(*session);
    free(bitstream.Data);
    decodeOutput output{
            width,
            height,
            hostRGB,
            data_stream.metadata
    };
    return output;
}
//}