cmake_minimum_required(VERSION 3.10)

# set the project name
project(hashapp)

# add dynamic library
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../library/include)
link_directories(${CMAKE_SOURCE_DIR}/../library/lib)

# add the executable
add_executable(hashapp main.c)
target_link_libraries(hashapp tlv)


