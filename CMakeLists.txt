cmake_minimum_required(VERSION 2.6)

aux_source_directory(. DIR_SRCS)
aux_source_directory(interfaces DIR_SRCS)
aux_source_directory(definetions DIR_SRCS)

add_definitions(-std=c++11)
add_definitions(-DFRAMEWORK_EXPORT)
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_BUILD_TYPE "Release")
message(STATUS "compiler is " ${CMAKE_CXX_COMPILER} ", version is " ${CMAKE_CXX_COMPILER_VERSION})

project(framework)
add_executable(framework ${DIR_SRCS})
# set_property(TARGET framework PROPERTY CXX_STANDARD 11)
set_target_properties(framework PROPERTIES CXX_STANDARD 14)
install(TARGETS framework RUNTIME DESTINATION bin)

project(framework_dll)
add_library(framework_dll SHARED ${DIR_SRCS})
set_property(TARGET framework_dll PROPERTY CXX_STANDARD 11)
set_target_properties(framework_dll PROPERTIES OUTPUT_NAME "framework")
set_target_properties(framework_dll PROPERTIES PREFIX "")

project(framework_lib)
add_library(framework_lib STATIC ${DIR_SRCS})
set_property(TARGET framework_lib PROPERTY CXX_STANDARD 11)
set_target_properties(framework_lib PROPERTIES OUTPUT_NAME "framework")
set_target_properties(framework_lib PROPERTIES PREFIX "")
