# HTTP 基础教程（基于 Golang Gin 框架）

[![Go版本](https://img.shields.io/badge/Go-1.24.4-00ADD8?logo=go&logoColor=white)](https://go.dev/dl/)
[![Gin框架版本](https://img.shields.io/badge/Gin-v1.10.1-00ADD8)](https://github.com/gin-gonic/gin/releases/tag/v1.10.1)
[![许可证: MIT](https://img.shields.io/badge/License-MIT-blue)](https://opensource.org/licenses/MIT)

## 项目概述

本教程演示了HTTP基础开发概念，涵盖：
- 基础 GET/POST 请求
- 文件上传处理
- API 响应最佳实践
- Postman 测试工作流

> **学习目标**：掌握现代 Web 服务开发模式, 进而可以用自己熟悉的语言及其生态框架进一步开发更强大功能.

---

## 🌟 核心特性

- 🚀 支持带查询参数的简单 GET 端点
- 📤 通过 POST 实现文件上传（multipart/form-data 格式）
- 🔗 自动生成文件访问 URL
- 🔄 未匹配路由自动 302 重定向
- 📝 简洁的代码结构，适合培训使用

---

## 🛠️ 快速开始

### 环境准备

| 组件       | 最低版本 | 推荐版本 | 安装指南 |
|------------|----------|----------|----------|
| **Go**     | 1.20     | 1.21+    | [下载](https://go.dev/dl/) |
| **Postman**| -        | 最新版   | [下载](https://www.postman.com/downloads/) |

---

### 获取代码
```bash
git clone https://github.com/DTRailway/VGE-Fresh-Tutorial.git
cd VGE-Fresh-Tutorial/go-gin-http
```

---

## 📂 项目结构
```
.
├── main.go     # 主程序入口
├── uploads/    # 文件上传目录（自动创建）
├── go.mod      # 依赖管理文件
└── README.md   # 项目文档
```

---

## ▶️ 启动服务器

**安装依赖**
```bash
go mod tidy
```

**编译为可执行文件**
```bash
go build main.go
```

**执行程序**
```bash
main.exe
```

---

## 🚦 API 接口说明

### 1. GET /hello
**描述**：基础 GET 请求演示  
**参数**：
- `name`（可选）：您的名字

**示例**：
```bash
curl "http://localhost:8080/hello?name=张三"
```

**响应**：
```json
{
  "message": "Welcome to VGE·Group, 张三!",
  "method": "GET"
}
```

---

### 2. POST /upload
**描述**：文件上传接口  
**内容类型**：`multipart/form-data`  
**必填字段**：`image`（文件上传）

**Postman 设置**：
1. 方法选择 POST
2. Body → form-data
3. 添加字段 `image`（类型：File）
4. 选择图片文件

**响应**：
```json
{
  "message": "图片上传成功",
  "filename": "test.jpg",
  "size": 12345,
  "image_url": "http://localhost:8080/files/test.jpg"
}
```

---

### 3. GET /files/:filename
**描述**：访问上传的文件  
**示例**：  
浏览器或 Postman 访问：
```
http://localhost:8080/files/test.jpg
```

---

### 4. 未定义路由
所有未定义的路由将重定向至：
```
https://www.vrlab.org.cn
```

---

## 📚 学习要点

### HTTP 方法
- **GET**：获取数据（参数在 URL 中）
- **POST**：提交数据（数据在请求体中）

### 关键概念
- 路由处理
- 查询参数与表单数据
- 文件上传处理
- HTTP 状态码（200, 302, 400, 500）
- API 响应格式

---

## 🤝 参与贡献

欢迎提交 PR 或 Issue，请参考 [GitHub 官方贡献指南](https://docs.github.com/zh/contributing)

1. Fork 项目仓库
2. 创建特性分支 (`git checkout -b feature/AmazingFeature`)
3. 提交更改 (`git commit -m 'Add some AmazingFeature'`)
4. 推送到分支 (`git push origin feature/AmazingFeature`)
5. 打开 Pull Request

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
