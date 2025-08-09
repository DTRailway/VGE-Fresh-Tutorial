# 组织管理及数据结构基本知识

[![C++标准](https://img.shields.io/badge/C++-11/17/20-blue.svg)](https://isocpp.org/)
[![许可证: MIT](https://img.shields.io/badge/License-MIT-blue)](https://opensource.org/licenses/MIT)

## 项目概述

本项目基于 C++ 演示数据结构的基础，包括指针核心概念和链表操作：
- 指针声明与初始化
- 内存地址操作
- 参数传递方式
- 常见指针陷阱
- 智能指针使用
- 链表数据结构（带交互式操作）

> **学习目标**：掌握指针操作与基本数据结构，构建健壮的 C++ 应用程序，并理解数据结构和索引基本原理

---

## 🌟 核心功能

- 🧠 基础指针机制演示
- 🔄 三种参数传递方式对比
- ⚠️ 危险指针操作的安全演示
- 🤖 智能指针 RAII 实现
- 🔗 链表的增删查改、反转与遍历
- 🖥️ 交互式链表操作系统（菜单驱动）
- 📊 控制台可视化输出及内存信息展示

---

## 🛠️ 快速开始

### 环境准备

| 组件         | 最低版本   | 推荐版本   | 备注               |
|--------------|------------|------------|------------------|
| **C++编译器**| GCC 7+     | GCC 11+    | 支持 MSVC 2017+    |
| **CMake**    | 3.10       | 3.20+      | 推荐用但未引入复杂CMake语法 |

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
│   ├── cpp-linked-list.h       # 链表头文件声明
│   ├── cpp-linked-list.cpp     # 链表核心实现
│   └── main.cpp                # 链表演示入口（交互菜单）
├── cpp-linked-list.sln         # MSVC 2017 工程配置
└── README.md                   # 本文档
```

---

## ▶️ 编译运行

### 使用 MSVC（Windows）
1. 打开 `cpp-linked-list.sln` 工程文件
2. 选中一个启动方案并设置为启动项目(默认`cpp-linked-list`)
3. 选择 **Release** 或 **Debug** 模式
4. 编译并运行

### 使用 g++（Linux/Mac/Windows MinGW）
```bash
# 编译指针演示(以cpp-pointer-basics解决方案为例, 链表同样)
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
make
./linkedlist_app
```

---

## 🧑‍🏫 教学模块

### 1. 指针基础概念
```cpp
PointerDemo(); // 演示：
// - 取地址(&)和解引用(*)操作符
// - 指针大小和内存布局
```

### 2. 参数传递方式
```cpp
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
WildPointerDemo();    // 未初始化指针
DanglingPointerDemo(); // 悬垂指针
MemoryLeakDemo();      // 内存泄漏
```

### 5. 链表核心实现与交互操作
```cpp
LinkedList list;
list.interactiveCreate();
list.interactiveInsert();
list.interactiveRemove();
list.interactiveFind();
list.reverse();
list.traverse();
```

**支持的操作：**
- 创建链表（支持批量节点输入）
- 按位置插入节点
- 按位置删除节点
- 按值查找节点
- 反转链表
- 遍历链表并显示详细内存信息

---

## 📚 核心知识点

### 基础概念
- 内存地址查看与操作
- 参数传递方式
- 常见指针陷阱
- 链表数据结构

### 安全实践
- 空指针检查
- RAII 原则
- 智能指针 (`unique_ptr`, `shared_ptr`)
- 内存所有权

### 链表实现要点
- 采用带哨兵节点（sentinel head）的单向链表
- 所有操作均进行边界检查
- 支持交互式创建与调试
- 提供链表连接图与内存地址输出

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
