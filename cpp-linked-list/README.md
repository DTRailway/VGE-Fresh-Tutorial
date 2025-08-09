# 组织管理及数据结构基本知识

[![C++标准](https://img.shields.io/badge/C++-11/17/20-blue.svg)](https://isocpp.org/)
[![许可证: MIT](https://img.shields.io/badge/License-MIT-blue)](https://opensource.org/licenses/MIT)

## 📖 项目概述

本项目基于 C++ 演示数据结构的基础，包括指针核心概念和链表操作：
- 指针声明与初始化
- 内存地址操作
- 参数传递方式
- 常见指针陷阱
- 智能指针使用
- 链表数据结构

> **学习目标**：掌握指针操作与基本数据结构，构建健壮的 C++ 应用程序，理解数据结构和索引基本原理

---

## 🌟 核心功能

- 🧠 基础指针机制演示
- 🔄 三种参数传递方式对比
- ⚠️ 危险指针操作的安全演示
- 🤖 智能指针 RAII 实现
- 📊 控制台可视化输出

---

## 🛠️ 快速开始

### 环境准备

| 组件         | 最低版本   | 推荐版本   | 备注               |
|--------------|------------|------------|------------------|
| **C++编译器**| GCC 7+     | GCC 11+    | 支持 MSVC 2017+    |
| **CMake**    | 3.10       | 3.20+      | 推荐但未引入复杂CMake语法 |

---

### 获取代码
```bash
git clone https://github.com/DTRailway/VGE-Fresh-Tutorial.git
cd VGE-Fresh-Tutorial/cpp-linked-list
```

---

## 📂 项目结构
```
.
├── cpp-pointer-basics/
│   ├── cpp-pointer-basis.h     # 头文件声明
│   ├── cpp-pointer-basis.cpp   # 核心实现
│   └── main.cpp                # 演示入口
├── cpp-linked-list/
│   └── main.cpp                # 链表核心实现
├── cpp-linked-list.sln         # MSVC 2017 工程配置
└── README.md                   # 本文档
```

---

## ▶️ 编译与运行

### 方法一：使用 MSVC（Windows）
1. 双击 `cpp-linked-list.sln` 打开 Visual Studio 2017 或更高版本
2. 选择 **Debug** 或 **Release**
3. 点击 **本地 Windows 调试器** 运行程序

### 方法二：使用 g++（Linux / macOS / Windows MinGW）
```bash
# 编译指针演示
g++ cpp-pointer-basics/cpp-pointer-basis.cpp cpp-pointer-basics/main.cpp -o pointer_demo

# 编译链表演示
g++ cpp-linked-list/main.cpp -o linked_list_demo

# 运行
./pointer_demo
./linked_list_demo
```

### 方法三：使用 CMake（跨平台, 但需要自行编写编译文件）
```bash
mkdir build && cd build
cmake ..
cmake --build .
```

---

## 🧑‍🏫 演示模块

### 1. 指针基础概念
```cpp
PointerDemo(); // 演示：
// - 取地址(&)和解引用(*)操作符
// - 指针大小和内存布局
```

### 2. 参数传递方式
```cpp
// 值传递 vs 指针传递 vs 引用传递
CrossModifyDemo(); // 对比：
// - ModifyValueByValue()
// - ModifyValueByPointer()
// - ModifyValueByReference()
```

### 3. 多返回值实现
```cpp
int a, b;
ReturnByPointer(&a, &b); // 传统输出参数方式
```

### 4. 指针常见错误
```cpp
WildPointerDemo();     // 未初始化指针
DanglingPointerDemo(); // 悬垂指针
MemoryLeakDemo();      // 内存泄漏
```

---

## 📚 核心知识点

### 基础概念
- 指针算术运算
- const 正确性
- 栈与堆内存分配
- 平台相关特性

### 安全实践
- 空指针检查
- RAII 原则
- 智能指针 (`unique_ptr`, `shared_ptr`)
- 内存所有权模型

---

## 🤝 参与贡献

欢迎通过以下方式改进项目：

1. Fork 项目仓库
2. 创建特性分支 (`git checkout -b feature/改进功能`)
3. 提交更改 (`git commit -m '添加某功能'`)
4. 推送分支 (`git push origin feature/改进功能`)
5. 发起 Pull Request

---

## 📜 开源协议

本项目基于 [MIT License](https://opensource.org/licenses/MIT) 开源。

```
Copyright (c) 2025 VGE团队

特此授予任何获得本软件及相关文档文件（以下简称“软件”）副本的人免费使用本软件的权利，
包括但不限于使用、复制、修改、合并、发布、分发、再许可及/或销售软件副本，
并允许被提供软件的人这样做，条件是上述版权声明和本许可声明应包含在软件的所有副本或主要部分中。

本软件按“原样”提供，不提供任何形式的明示或暗示担保，
包括但不限于适销性、特定用途适用性及不侵权的担保。
在任何情况下，作者或版权持有人不对因软件或软件的使用或其他交易而产生的任何索赔、
损害或其他责任负责，无论是在合同诉讼、侵权行为或其他方面。
```
