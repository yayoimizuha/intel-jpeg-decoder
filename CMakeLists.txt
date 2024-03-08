cmake_minimum_required(VERSION 3.27)
project(oneAPI_test)

set(CMAKE_CXX_STANDARD 20)
find_package(PkgConfig)
find_package(VPL)

pkg_check_modules(VPL REQUIRED vpl)

add_executable(JPEG_DECODER main.cpp)
add_executable(JPEG_DECODER_RGB dec_rgb.cpp)
add_executable(example hello-decode.cpp)

include_directories(${VPL_INCLUDE_DIRS})

target_link_libraries(JPEG_DECODER ${VPL_LIBRARIES})
target_link_libraries(JPEG_DECODER_RGB ${VPL_LIBRARIES})
target_link_libraries(example ${VPL_LIBRARIES})
message("VPL_LIBRARIES: " ${VPL_LIBRARIES})
message("VPL_LIB_DIR: " ${VPL_LIBS})
message("VPL_INCLUDE_DIRS: " ${VPL_INCLUDE_DIRS})
#include(cmake/CPM.cmake)
#
#CPMAddPackage(
#        NAME magic_enum
#        GITHUB_REPOSITORY Neargye/magic_enum
#        GIT_TAG v0.9.5
#)
#
#target_link_libraries(JPEG_DECODER magic_enum)