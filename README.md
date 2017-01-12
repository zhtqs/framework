# Framework

## 说明

用C++实现的一个高内聚低耦合设计模式的框架

这个框架能够：
* 积木式软件架构思想，不同的开发者基于相同的积木规范可以开发兼容的模块
* 提高软件的健壮性
* 降低C++模块之间的耦合性，增加模块的灵活性
* 相较传统的COM和COM+，这个框架不仅可以在Windows平台上使用，还可以在Linux等其它平台上使用
* 软件只依赖于经典的STL和C++标准，任何人都可以容易的迁移到任意平台

## 关于积木规则

* 简约式积木架构，只需要调用一个C导出函数`get_instance`就能获得模块实例，通过模块接口调用它的API。
* 模块管理接口`framework.dll`同样有此接口。通过此获接可以管理模块。
* 导出C++函数是大多数C++开发同志们极不赞成的粗放型架构，建议新手同样遵循这样的规范。

## 如何开始

这里重点说一下需要注意的几个问题：
* CMakeLists.txt中已经把include文件夹和src/include文件夹加入整个编译环境的INCLUDE环境变量中。目前KDevelop不能识别CMake中关于<INCLUDE>的设置，它自己的工程设置中INCLUDE环境应当加入这两个文件夹。
* 我当前一直在使用KDevelop开发环境，但KDevelop编译有问题，它编译出32位的动态库引用64位的系统动态库，使得程序报错。好在CMake能生成VS解决方案，建议大家在发布时切换到CMake环境，下面专门提出一章讲解CMake怎么调用Visual Studio 2015

## CMake调用Visual Studio 2015的方法
如果直接双击CMake应用程序，那么CMake生成Visual Studio 2015解决方案都会失败，原因是CMake运行的时候缺少NMake环境变量，Visual Studio极力引导开发都使用C#开发，很多C++开发环境在开发工具安装的时候并没有配置。解决办法是：

1. 启动VS2015 x64 Native Tools Command Prompt（在开始菜单Visual Studio 2015 Tools菜单里面）
2. 选择代码所在文件夹与CMake生成文件所有文件夹
3. 运行命令：

```
cmake-gui 
```

4. 点击configure按钮，选择当前系统上已经安装好的Visual Studio 版本
5. 点击generate按钮
6. 点击Open Project按钮

自动构建非常需要命令行操作，不能存在需要人为干预和操作的界面，这里也有办法，如下所示：

1. 启动VS2015 x64 Native Tools Command Prompt（在开始菜单Visual Studio 2015 Tools菜单里面）
2. 选择代码所在文件夹与CMake生成文件所有文件夹
3. 运行命令：

```
cd <转到所有所在文件夹>
mkdir build
cmake -G "NMake Makefiles" ../
nmake
```