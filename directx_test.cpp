#include <iostream>
#include <vpl/mfx.h>
#include <algorithm>
#include <cstring>
#include "BitmapPlusPlus.hpp"
#include <d3d11.h>
#include <dxgi1_6.h>
#include <DirectXTex.h>
#include <wincodec.h>

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

inline unsigned char clip(float val) {
    if (val < 0)val = 0;
    if (val > 255)val = 255;
    return static_cast<unsigned char>(val);
}

pair<mfxU16, mfxU16> size_from_header(mfxU8 *data, mfxU32 size) {
    mfxU32 ptr = 0;
    mfxU16 segment_size;
    if (data[ptr] != 0xff || data[ptr + 1] != 0xd8)return {0, 0};
    ptr += 2;
    while (ptr <= size) {
        if (data[ptr] == 0xff && (data[ptr + 1] & 0xf0) == 0xc0) {
            return {(data[ptr + 5] << 8) + data[ptr + 6], (data[ptr + 7] << 8) + data[ptr + 8]};
        }
        segment_size = (data[ptr + 2] << 8) + data[ptr + 3];
        ptr += segment_size + 2;
    }
    return {0, 0};
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

    auto [height, width] = size_from_header(bitstream.Data, bitstream.DataLength);
    cout << height << "x" << width << endl;

    mfxVideoParam decodeParams = {};
    decodeParams.mfx.CodecId = MFX_CODEC_JPEG;
    decodeParams.IOPattern = MFX_IOPATTERN_OUT_VIDEO_MEMORY;
    CHECK(MFXVideoDECODE_DecodeHeader(session, &bitstream, &decodeParams));


    auto fourcc = fourcc_conv(decodeParams.mfx.FrameInfo.FourCC);

    cout << "image format name: " << fourcc << endl;
    if (decodeParams.mfx.FrameInfo.FourCC != MFX_FOURCC_NV12)exit(-1);


    CHECK(MFXVideoDECODE_Init(session, &decodeParams));

    mfxFrameSurface1 *surface_out;
    mfxSyncPoint syncPoint;
    cout << "start_conv_color decode" << endl;


    auto start_jpeg_dec = clock();
    CHECK(MFXVideoDECODE_DecodeFrameAsync(session, &bitstream, nullptr, &surface_out, &syncPoint));
    CHECK(surface_out->FrameInterface->Synchronize(surface_out, 1000));
    cout << "decode JPEG: " << clock() - start_jpeg_dec << "ms" << endl;


//    CHECK(surface_out->FrameInterface->Map(surface_out, MFX_MAP_READ));
    mfxHDL nativeHandle = nullptr;
    mfxResourceType nativeResourceType = {};
    CHECK(surface_out->FrameInterface->GetNativeHandle(surface_out, &nativeHandle, &nativeResourceType));
    cout << "Native handle type: ";
    switch (nativeResourceType) {
        case MFX_RESOURCE_SYSTEM_SURFACE:
            cout << "MFX_RESOURCE_SYSTEM_SURFACE" << endl;
            break;
        case MFX_RESOURCE_VA_SURFACE_PTR:
            cout << "MFX_RESOURCE_VA_SURFACE_PTR" << endl;
            break;
        case MFX_RESOURCE_VA_BUFFER_PTR:
            cout << "MFX_RESOURCE_VA_BUFFER_PTR" << endl;
            break;
        case MFX_RESOURCE_DX9_SURFACE:
            cout << "MFX_RESOURCE_DX9_SURFACE" << endl;
            break;
        case MFX_RESOURCE_DX11_TEXTURE:
            cout << "MFX_RESOURCE_DX11_TEXTURE" << endl;
            break;
        case MFX_RESOURCE_DX12_RESOURCE:
            cout << "MFX_RESOURCE_DX12_RESOURCE" << endl;
            break;
        case MFX_RESOURCE_DMA_RESOURCE:
            cout << "MFX_RESOURCE_DMA_RESOURCE" << endl;
            break;
        case MFX_RESOURCE_HDDLUNITE_REMOTE_MEMORY:
            cout << "MFX_RESOURCE_HDDLUNITE_REMOTE_MEMORY" << endl;
            break;
    }
    auto *pDXTexture = reinterpret_cast<ID3D11Texture2D *>(nativeHandle);
    D3D11_TEXTURE2D_DESC texDesc = {};
    pDXTexture->GetDesc(&texDesc);
    cout << "  Width              =" << texDesc.Width << endl;
    cout << "  Height             =" << texDesc.Height << endl;
    cout << "  MipLevels          =" << texDesc.MipLevels << endl;
    cout << "  ArraySize          =" << texDesc.ArraySize << endl;
    cout << "  Format             =" << texDesc.Format << endl;
    cout << "  SampleDesc.Count   =" << texDesc.SampleDesc.Count << endl;
    cout << "  SampleDesc.Quality =" << texDesc.SampleDesc.Quality << endl;
    cout << std::hex << std::showbase;
    cout << "  Usage              =" << texDesc.Usage << endl;
    cout << "  BindFlags          =" << texDesc.BindFlags << endl;
    cout << "  CPUAccessFlags     =" << texDesc.CPUAccessFlags << endl;
    cout << "  MiscFlags          =" << texDesc.MiscFlags << endl;
    cout << std::dec << endl;
    mfxHDL deviceHandle = nullptr;
    mfxHandleType deviceHandleType = {};
    CHECK(surface_out->FrameInterface->GetDeviceHandle(surface_out, &deviceHandle, &deviceHandleType));
    cout << "Device handle type: ";
    switch (deviceHandleType) {
        case MFX_HANDLE_DIRECT3D_DEVICE_MANAGER9:
            cout << "MFX_HANDLE_DIRECT3D_DEVICE_MANAGER9" << endl;
            break;
        case MFX_HANDLE_RESERVED1:
            cout << "MFX_HANDLE_RESERVED1" << endl;
            break;
        case MFX_HANDLE_D3D11_DEVICE:
            cout << "MFX_HANDLE_D3D11_DEVICE" << endl;
            break;
        case MFX_HANDLE_VA_DISPLAY:
            cout << "MFX_HANDLE_VA_DISPLAY" << endl;
            break;
        case MFX_HANDLE_RESERVED3:
            cout << "MFX_HANDLE_RESERVED3" << endl;
            break;
        case MFX_HANDLE_VA_CONFIG_ID:
            cout << "MFX_HANDLE_VA_CONFIG_ID" << endl;
            break;
        case MFX_HANDLE_VA_CONTEXT_ID:
            cout << "MFX_HANDLE_VA_CONTEXT_ID" << endl;
            break;
        case MFX_HANDLE_CM_DEVICE:
            cout << "MFX_HANDLE_CM_DEVICE" << endl;
            break;
        case MFX_HANDLE_HDDLUNITE_WORKLOADCONTEXT:
            cout << "MFX_HANDLE_HDDLUNITE_WORKLOADCONTEXT" << endl;
            break;
        case MFX_HANDLE_PXP_CONTEXT:
            cout << "MFX_HANDLE_PXP_CONTEXT" << endl;
            break;
    }
    auto *pDXDevice = reinterpret_cast<ID3D11Device *>(deviceHandle);
    ID3D11Texture2D *renderTexture = nullptr;
    texDesc.MiscFlags = D3D10_RESOURCE_MISC_SHARED;
    auto hr = pDXDevice->CreateTexture2D(&texDesc, nullptr, &renderTexture);
    ID3D11DeviceContext *pDXDeviceContext;
    hr = pDXDevice->CreateDeferredContext(0, &pDXDeviceContext);
    pDXDeviceContext->CopyResource(renderTexture, pDXTexture);
    IDXGIResource1 *pDXGIResource = nullptr;

    hr = renderTexture->QueryInterface(__uuidof(IDXGIResource1), (void **) &pDXGIResource);
//    HANDLE *pSharedHandle = nullptr;
//    hr = pDXGIResource->CreateSharedHandle(nullptr, DXGI_SHARED_RESOURCE_READ, nullptr, pSharedHandle);
    DirectX::ScratchImage srcImage, rgbImage;
    DirectX::CaptureTexture(pDXDevice, pDXDeviceContext, renderTexture, srcImage);
    DirectX::Convert(srcImage.GetImages(), srcImage.GetImageCount(), srcImage.GetMetadata(),
                     DXGI_FORMAT::DXGI_FORMAT_R8G8B8A8_UNORM, DirectX::TEX_FILTER_FLAGS::TEX_FILTER_DEFAULT, 0.0f,
                     rgbImage);
    CoInitialize(nullptr);
    DirectX::SaveToWICFile(*rgbImage.GetImage(0, 0, 0), DirectX::WIC_FLAGS::WIC_FLAGS_NONE,
                           GUID_ContainerFormatBmp, L"texture.bmp", &GUID_WICPixelFormat24bppRGB);

    pDXGIResource->Release();


    //    CHECK(surface_out->FrameInterface->Unmap(surface_out));
    CHECK(surface_out->FrameInterface->Release(surface_out));
    CHECK(MFXVideoDECODE_Close(session));

}


//https://github.com/intel/libvpl/blob/383b5caac6df614e76ade5a07c4f53be702e9176/examples/api2x/hello-decvpp/src/hello-decvpp.cpp