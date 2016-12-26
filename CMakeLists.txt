cmake_minimum_required(VERSION 2.6)

aux_source_directory(. DIR_SRCS)
aux_source_directory(interfaces DIR_SRCS)
aux_source_directory(definetions DIR_SRCS)

project(framework)
add_executable(framework ${DIR_SRCS})
install(TARGETS framework RUNTIME DESTINATION bin)

project(framework_dll)
add_library(framework_dll SHARED ${DIR_SRCS})
set_target_properties(framework_dll PROPERTIES OUTPUT_NAME "framework")
set_target_properties(framework_dll PROPERTIES PREFIX "")

project(framework_lib)
add_library(framework_lib STATIC ${DIR_SRCS})
set_target_properties(framework_lib PROPERTIES OUTPUT_NAME "framework")
set_target_properties(framework_lib PROPERTIES PREFIX "")
