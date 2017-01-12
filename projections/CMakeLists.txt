cmake_minimum_required(VERSION 2.6)

include_directories(include/)
include_directories(src/include/)

aux_source_directory(src DIR_SRC)
aux_source_directory(src/interfaces DIR_SRC)
aux_source_directory(src/definetions DIR_SRC)
aux_source_directory(test/main/ DIR_TEST_MAIN)
aux_source_directory(test/module/ DIR_TEST_MODULE)

# set(CMAKE_CXX_FLAGS "/D_DEBUG /MTd /Zi /Ob0 /Od /RTC1")
# set(CMAKE_CXX_FLAGS_DEBUG "/MT /O1 /Ob1 /D NDEBUG")
# set(CMAKE_CXX_FLAGS_DEBUG "/MT /O2 /Ob2 /D NDEBUG")
# set(CMAKE_CXX_FLAGS_RELEASE "/MT /Zi /O2 /Ob1 /D NDEBUG") 
# 
# set(CMAKE_C_FLAGS "/D_DEBUG /MTd /Zi /Ob0 /Od /RTC1")
# set(CMAKE_C_FLAGS_DEBUG "/MT /O1 /Ob1 /D NDEBUG")
# set(CMAKE_C_FLAGS_DEBUG "/MT /O2 /Ob2 /D NDEBUG")
# set(CMAKE_C_FLAGS_RELEASE "/MT /Zi /O2 /Ob1 /D NDEBUG") 

if(UNIX)
    add_definitions(-std=c++14)
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


message(STATUS "compiler is " ${CMAKE_CXX_COMPILER} ", platform is " ${GUI}) # 字符串的连接不必用 + 号，格式化转义字符必须与字符串转义定符隔开

project(framework)
add_library(framework SHARED ${DIR_SRC})
# add_definitions(framework -DFRAMEWORK_LIBRARY)
add_definitions(-DFRAMEWORK_LIBRARY)
target_compile_definitions(framework PRIVATE -DFRAMEWORK_LIBRARY)
set_target_properties(framework PROPERTIES CXX_STANDARD 14)
set_target_properties(framework PROPERTIES OUTPUT_NAME "framework")
set_target_properties(framework PROPERTIES PREFIX "")

project(framework_lib)
add_library(framework_lib STATIC ${DIR_SRC})
# set_property(TARGET framework_lib PROPERTY CXX_STANDARD 14)
set_target_properties(framework_lib PROPERTIES CXX_STANDARD 14)
set_target_properties(framework_lib PROPERTIES OUTPUT_NAME "framework")
set_target_properties(framework_lib PROPERTIES PREFIX "")

# project(test_module)
# add_library(test_module SHARED ${DIR_TEST_MODULE})
# set_target_properties(test_module PROPERTIES CXX_STANDARD 14)
# set_target_properties(test_module PROPERTIES OUTPUT_NAME "module")
# set_target_properties(test_module PROPERTIES PREFIX "")
# 
# project(test_main)
# add_executable(test_main ${DIR_TEST_MAIN})
# # set_property(TARGET framework PROPERTY CXX_STANDARD 11)
# set_target_properties(test_main PROPERTIES CXX_STANDARD 14)
# set_target_properties(test_main PROPERTIES OUTPUT_NAME "test")
# # target_link_libraries(test_main framework_lib z m) z 和 m 不是 project 名称，被自动识别为 lib 文件名称
# target_link_libraries(test_main framework_lib)
# install(TARGETS test_main RUNTIME DESTINATION bin)
