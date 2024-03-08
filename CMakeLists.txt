cmake_minimum_required(VERSION 3.27)
project(oneAPI_test)

set(CMAKE_CXX_STANDARD 20)
#find_package(PkgConfig)
find_package(VPL)

message("VPL_SHLIB_DIR: " ${VPL_SHLIB_DIR})
message("VPL_LIB_DIR: " ${VPL_LIB_DIR})
message("VPL_BIN_DIR: " ${VPL_BIN_DIR})
message("VPL_INCLUDE_DIR: " ${VPL_INCLUDE_DIR})

add_executable(JPEG_DECODER main.cpp)
add_executable(JPEG_DECODER_RGB dec_rgb.cpp)
add_executable(JPEG_DECODER_RGB4 dec_rgb4.cpp)
add_executable(example hello-decode.cpp)

include_directories(${VPL_INCLUDE_DIR})

link_directories(${VPL_SHLIB_DIR})


target_link_libraries(JPEG_DECODER  ${VPL_LIB_DIR}/vpl.lib)
target_link_libraries(JPEG_DECODER_RGB  ${VPL_LIB_DIR}/vpl.lib)
target_link_libraries(JPEG_DECODER_RGB4  ${VPL_LIB_DIR}/vpl.lib)
target_link_libraries(example  ${VPL_LIB_DIR}/vpl.lib)
#include(cmake/CPM.cmake)
#
#CPMAddPackage(
#        NAME magic_enum
#        GITHUB_REPOSITORY Neargye/magic_enum
#        GIT_TAG v0.9.5
#)
#
#target_link_libraries(JPEG_DECODER magic_enum)