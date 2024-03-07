cmake_minimum_required(VERSION 3.27)
project(oneAPI_test)

set(CMAKE_CXX_STANDARD 20)

add_executable(JPEG_DECODER main.cpp)
add_executable(JPEG_DECODER_RGB dec_rgb.cpp)
add_executable(example hello-decode.cpp)

target_link_libraries(JPEG_DECODER vpl)
target_link_libraries(JPEG_DECODER_RGB vpl)
target_link_libraries(example vpl)
#include(cmake/CPM.cmake)
#
#CPMAddPackage(
#        NAME magic_enum
#        GITHUB_REPOSITORY Neargye/magic_enum
#        GIT_TAG v0.9.5
#)
#
#target_link_libraries(JPEG_DECODER magic_enum)