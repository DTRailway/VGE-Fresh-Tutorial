# 分布式协同组织管理引擎接口开发框架

[![Go Version](https://img.shields.io/badge/go-1.20+-00ADD8?logo=go&logoColor=white)](go.mod)
[![License](https://img.shields.io/badge/license-MIT-blue)](LICENSE)
[![MongoDB](https://img.shields.io/badge/MongoDB-5.0+-47A248?logo=mongodb&logoColor=white)](https://www.mongodb.com)

## 项目概述

本教程目的是展示分布式组织管理引擎接口的基本开发思路, 通过 Golang 语言生态框架与 MongoDB 构建实现标准化 HTTP 协议接口：

- 🧠 掌握基本数据库引擎后端服务开发核心范式
- 🛠️ 学习使用一门语言生态快速构建服务接口
- 🔄 提供可扩展的研发思路, 可迁移至其他语言 / 数据库 / 基础操作组合

> **知识迁移**：本方案采用的架构设计同样适用于其他技术栈组合, 如 Python / Java + Django + PostgreSQL 等

---

## 🌟 核心特性

- 🚀 无模式文档数据库操作
- 🔗 原生 JSON 数据交互
- ⚡️ 快速构建 HTTP 接口
- 🔐 内置认证与权限控制

---

## 🛠️ 快速开始

### 环境准备

#### 基础依赖
| 组件        | 最低版本 | 推荐版本 | 安装指南 |
|-------------|----------|----------|----------|
| **Git**     | 2.30     | 2.40+    | [下载](https://git-scm.com/downloads) |
| **Docker**  | 20.10    | 24.0+    | [下载](https://docs.docker.com/get-docker/) |
| **Golang**  | 1.20     | 1.21+    | [下载](https://go.dev/dl/) |
| **MongoDB** | 5.0      | 6.0+     | [容器方案](#1-数据库部署) |

#### MongoDB替代安装方案(无需安装docker)
- [Windows安装指南](https://www.mongodb.com/docs/manual/tutorial/install-mongodb-on-windows/)
- [macOS安装指南](https://www.mongodb.com/docs/manual/tutorial/install-mongodb-on-os-x/)
- [Linux安装指南](https://www.mongodb.com/docs/manual/administration/install-on-linux/)

#### 版本兼容性说明
- 所有组件版本均支持主流操作系统（Windows 10+/macOS 12+/Ubuntu 20.04+）
- 容器方案(Docker+MongoDB)与原生安装(MongoDB)方案二选一即可

---

### 1. 数据库部署

#### 容器化方案（推荐）

**创建自定义网络**
```bash
docker network create mongo-net
```

**启动 MongoDB 服务**
```bash
docker run -d \
  --network mongo-net \
  --name mongo-dev \
  -p 27017:27017 \
  -e MONGO_INITDB_ROOT_USERNAME=admin \
  -e MONGO_INITDB_ROOT_PASSWORD=123456 \
  mongo:latest
```

**启动可视化管理控制台**
```bash
docker run -d \
  --network mongo-net \
  -p 8081:8081 \
  --name mongo-express \
  -e ME_CONFIG_MONGODB_ADMINUSERNAME=admin \
  -e ME_CONFIG_MONGODB_ADMINPASSWORD=123456 \
  -e ME_CONFIG_MONGODB_SERVER=mongo-dev \
  mongo-express:latest
```

#### 访问方式
- **数据库连接**: `mongodb://admin:123456@localhost:27017`
- **Web 控制台**: [http://localhost:8081](http://localhost:8081)
  - 用户名：admin
  - 密码：pass
- **命令行工具**:
```bash
docker exec -it mongo-dev mongosh -u admin -p 123456
```

---

### 2. 获取代码
```bash
git clone https://github.com/DTRailway/VGE-Fresh-Tutorial.git
cd VGE-Fresh-Tutorial/mongodb-golang-interface
```

---
### 3. 项目结构
```
.
├── docs/                # Swagger文档(自动生成)
├── internal/
│   ├── controllers/     # 路由处理层
│   │   └── user.go      
│   └── models/          # 数据模型
│       └── user.go      
├── dbOperations/        # 数据库操作
│   └── mongo.go         
├── routes/              # 路由定义
│   └── router.go        
├── main.go              # 应用入口
└── go.mod               # 依赖管理
```


---
### 4. 生成文档(如果没添加也可忽略)
```bash
go install github.com/swaggo/swag/cmd/swag@latest
swag init -g main.go
```

---

### 4. 启动服务

**安装依赖**
```bash
go mod tidy
```

**运行开发服务器**
```bash
go run main.go
```

---

## 📚 接口文档

### 基础管理接口

| 方法     | 端点         | 描述     | 示例     |
|----------|--------------|----------|----------|
| `POST`   | `/users`     | 创建用户 | [示例](#) |

---

## 🧪 测试验证

建议使用 **Swagger UI** 或 **Postman** 进行接口测试：

- **Swagger UI**：启动项目后, 访问 `http://localhost:8080/swagger/index.html`, 在页面中选择接口、填写参数并执行请求
- **Postman**：导入项目的接口集合文件, 修改请求参数后直接发送请求

> 示例：创建测试用户
> - 请求方法：`POST`
> - 请求 URL：`http://localhost:8080/users`
> - 请求体：
```json
{
  "name": "测试用户",
  "age": 24
}
```

---

## 🤝 参与贡献

欢迎提交 PR 或 Issue, 请参考 [GitHub 官方贡献指南](https://docs.github.com/zh/contributing)

---

## 📜 开源协议

本项目采用 [MIT License](https://opensource.org/licenses/MIT)