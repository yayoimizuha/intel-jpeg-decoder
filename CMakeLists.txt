cmake_minimum_required(VERSION 3.27)

project(oneAPI_test)

set(CMAKE_CXX_STANDARD 23)
#find_package(PkgConfig)
find_package(VPL)

message("VPL_SHLIB_DIR: " ${VPL_SHLIB_DIR})
message("VPL_LIB_DIR: " ${VPL_LIB_DIR})
message("VPL_BIN_DIR: " ${VPL_BIN_DIR})
message("VPL_INCLUDE_DIR: " ${VPL_INCLUDE_DIR})

link_directories($ENV{LD_LIBRARY_PATH})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsycl")


add_executable(JPEG_DECODER main.cpp)
add_executable(JPEG_DECODER_RGB dec_rgb.cpp)
add_executable(JPEG_DECODER_RGB4 dec_rgb4.cpp)
add_executable(example-hello-decode hello-decode.cpp)
add_executable(example-hello-decvpp hello-decvpp.cpp)
add_executable(qsv_jpeg_dec qsv_jpeg_dec.cpp)
add_executable(double-step double-step.cpp)
add_executable(double-step-sycl double-step-sycl.cpp)
add_executable(directx_test directx_test.cpp)

include_directories(${VPL_INCLUDE_DIR})


target_link_libraries(JPEG_DECODER ${VPL_LIB_DIR}/vpl.lib)
target_link_libraries(JPEG_DECODER_RGB ${VPL_LIB_DIR}/vpl.lib)
target_link_libraries(JPEG_DECODER_RGB4 ${VPL_LIB_DIR}/vpl.lib)
target_link_libraries(example-hello-decode ${VPL_LIB_DIR}/vpl.lib)
target_link_libraries(example-hello-decvpp ${VPL_LIB_DIR}/vpl.lib)
target_link_libraries(qsv_jpeg_dec ${VPL_LIB_DIR}/vpl.lib)
target_link_libraries(double-step ${VPL_LIB_DIR}/vpl.lib)
target_link_libraries(directx_test ${VPL_LIB_DIR}/vpl.lib)
target_link_libraries(directx_test DirectXTex.lib)
target_link_libraries(double-step-sycl ${VPL_LIB_DIR}/vpl.lib)
#include(cmake/CPM.cmake)
#
#CPMAddPackage(
#        NAME magic_enum
#        GITHUB_REPOSITORY Neargye/magic_enum
#        GIT_TAG v0.9.5
#)
#
#target_link_libraries(JPEG_DECODER magic_enum)
