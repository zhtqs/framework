cmake_minimum_required(VERSION 2.6)

aux_source_directory(src DIR_SRCS)
aux_source_directory(src/interfaces DIR_SRCS)
aux_source_directory(src/definetions DIR_SRCS)
aux_source_directory(test DIR_FTESTS)

if(UNIX)
    add_definitions(-std=c++11)
    set(CMAKE_CXX_COMPILER "g++")
    if(APPLE)
        set(GUI "Cocoa")
    else(APPLE)
        set(GUI "X11")
    endif(APPLE)
else(UNIX)
#    set(CMAKE_CXX_COMPILER "C:/Program Files (x86)/Microsoft Visual Studio 11.0/VC/bin/cl.exe") # cmake 会自动查找最新版本的VC编译套件，这不能切换编译套件
#    set(CMAKE_C_COMPILER "C:/Program Files (x86)/Microsoft Visual Studio 11.0/VC/bin/cl.exe")
    set(LINK_FLAGS "/MANIFEST:NO")
    if(WIN32)
        set(GUI "Win32")
    else(WIN32)
        set(GUI "Win64 or Unknown")
    endif(WIN32)
endif(UNIX)
add_definitions(-DFRAMEWORK_LIBRARY)
set(CMAKE_BUILD_TYPE "Release")
message(STATUS "compiler is " ${CMAKE_CXX_COMPILER} ", platform is " ${GUI}) # 字符串的连接不必用 + 号，格式化转义字符必须与字符串转义定符隔开

project(framework)
add_library(framework SHARED ${DIR_SRCS})
set_property(TARGET framework PROPERTY CXX_STANDARD 11)
set_target_properties(framework PROPERTIES OUTPUT_NAME "framework")
set_target_properties(framework PROPERTIES PREFIX "")

project(framework_lib)
add_library(framework_lib STATIC ${DIR_SRCS})
set_property(TARGET framework_lib PROPERTY CXX_STANDARD 11)
set_target_properties(framework_lib PROPERTIES OUTPUT_NAME "framework")
set_target_properties(framework_lib PROPERTIES PREFIX "")

project(ftest)
add_executable(ftest ${DIR_FTESTS})
# set_property(TARGET framework PROPERTY CXX_STANDARD 11)
set_target_properties(ftest PROPERTIES CXX_STANDARD 14)
# target_link_libraries(ftest framework_lib z m) z 和 m 不是 project 名称，被自动识别为 lib 文件名称
target_link_libraries(ftest framework_lib)
install(TARGETS ftest RUNTIME DESTINATION bin)


