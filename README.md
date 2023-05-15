# template_cpp

## Table of Contents

- [About](#about)
- [Getting Started](#getting_started)

## About <a name = "about"></a>

该仓库作为 C/C++开发时使用的模板仓库，提供 C/C++代码编译调试，代码补全，函数跳转,代码格式化等其他开发常用功能。

## Getting Started <a name = "getting_started"></a>

### Prerequisites

需要开发机器上有 cmake、mingw、llvm+clang（windows 平台上可以不需要）、vscode 环境。除此之外 vscode 需要安装插件 clangd、calng-formate、codelldb、cmake、cmake-tools、cmake-formate、c_cpp 等，具体需要安装哪些插件可以在 vscode 插件商店的推荐进行查看。推荐安装 Fira Code 字体，获得更好体验。

### Installing

将该仓库 git clone 到开发机器上即可。

选择使用的编译器，vscode 搜索`//CONFIG::`,根据自己所选的编译环境进行配置。

有问题可以具体查看 Note 仓库中关于使用 _vscode+clang+msvc+mingw+cmake 搭建 C、C++环境_ 的内容。
