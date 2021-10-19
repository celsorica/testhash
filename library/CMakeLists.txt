cmake_minimum_required(VERSION 3.10)

# set the project name
project (tlv)
set(CMAKE_BUILD_TYPE Release)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

# add the executable
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(tlv SHARED src/tlv.c)



