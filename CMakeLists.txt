#   Only at 3.5 because cmake complains, could likely be 2.0
cmake_minimum_required(VERSION 3.5)
project(picklist)

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
    set(CMAKE_GENERATOR "Unix Makefiles")
    get_filename_component(CMAKE_BUILD_TYPE ${CMAKE_BINARY_DIR} NAME)
endif()

set(CMAKE_CONFIGURATION_TYPES Debug;Release)
set(CMAKE_CXX_STANDARD 17)                 
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(picklist picklist.cpp)
