# 分布式协同组织管理引擎研发 - 前端 3D 数字地球应用

[![Cesium Version](https://img.shields.io/badge/Cesium-1.132+-8EABC8?logo=cesium&logoColor=white)](https://cesium.com/)
[![Vue Version](https://img.shields.io/badge/Vue-3.5.18+-4FC08D?logo=vuedotjs&logoColor=white)](https://vuejs.org/)
[![Vite Version](https://img.shields.io/badge/Vite-7.0.6+-646CFF?logo=vite&logoColor=white)](https://vitejs.dev/)
[![Node Version](https://img.shields.io/badge/Node-20.19+/22.12+-339933?logo=nodedotjs&logoColor=white)](https://nodejs.org/)

## 📋 目录
- [项目简介](#项目简介)
- [功能特性](#功能特性)
- [安装与运行](#安装与运行)
- [技术栈](#技术栈)
- [项目结构](#项目结构)
- [常见问题](#常见问题)
- [贡献指南](#贡献指南)
- [开源协议](#开源协议)

## 🎯 项目简介
本项目演示基于 **Vue 3** 与 **CesiumJS** 的三维数字地球应用，用于展示 GIS 数据、3D 漫游、数字孪生动态交互及可视化分析。

> **研发提示**：当前使用 CesiumJS 仅用于培训，后续实际项目将基于团队自研的 3D 数字地球引擎 **DTScope** 开发。

---

## ✨ 功能特性

### 🌍 核心功能
- 高性能 3D 地球渲染
- 全球地形、影像与标注集成
- 多种相机控制与导航
- 支持点、线、面等地理实体绘制
- 预设路径自动漫游
- 时间轴数据展示

### 🎮 交互功能
- 鼠标、键盘与触摸屏交互
- 视角预设与快速切换

### 🎨 界面特性
- 响应式现代化 UI
- 平滑动画与视角切换

---

## 🚀 安装与运行

### 环境要求
- Node.js >= 20.19.0 或 >= 22.12.0
- npm >= 8.0.0

### Node.js 环境安装

#### Windows 系统
1. **下载 Node.js**
    - 访问 [Node.js 官网](https://nodejs.org/)
    - 下载 LTS (长期支持) 版本（推荐 20.x 或 22.x）
2. **安装步骤**
    - 双击下载的 `.msi` 文件
    - 勾选 "Add to PATH"
    - 安装完成后重启命令行
3. **验证安装**
   ```bash
   node --version
   npm --version
   ```

#### 使用 Node Version Manager (nvm)
1. 安装 nvm
    - [nvm for Linux/macOS](https://github.com/nvm-sh/nvm)
    - [nvm-windows](https://github.com/coreybutler/nvm-windows)
2. 使用 nvm 安装 Node.js
   ```bash
   nvm install 20.19.0
   nvm use 20.19.0
   ```

#### 配置 npm 镜像源（国内用户推荐）
```bash
npm config set registry https://registry.npmmirror.com
```

#### 添加自定义二次开发Cesium

在小组内部找丁老师24级硕士程泽坤同学获取定制版Cesium包，下载后解压到项目的`public/libs`目录下。


---

### 获取代码
```bash
git clone https://github.com/DTRailway/VGE-Fresh-Tutorial.git
cd VGE-Fresh-Tutorial/vue-cesium-platform
```

### 安装依赖
```bash
npm install
```

### 开发模式运行
```bash
npm run dev
```
访问：`http://localhost:5173`

### 构建生产版本
```bash
npm run build
```

### 预览生产版本
```bash
npm run preview
```

---

## 🛠 技术栈

### Vue 3
- Composition API
- 更佳 TypeScript 支持
- 性能与包体积优化

### CesiumJS
- WebGL 高性能渲染
- 支持地形、影像、模型等多数据类型
- 强大的时间与相机控制系统

### Vite
- 极速开发服务器
- 热模块替换（HMR）
- 基于 Rollup 的构建优化

---

## 📁 项目结构

```
vue-cesium-platform/
├── public/                 # 静态资源
├── src/                    # 源码
│   ├── assets/             # 资源文件
│   ├── components/         # Vue 组件
│   ├── utils/              # 工具方法
│   ├── views/              # 页面组件
│   ├── App.vue             # 主应用组件
│   └── main.js             # 入口文件
├── index.html              # HTML 模板
├── package.json            # 项目配置
├── vite.config.js          # Vite 配置
└── README.md               # 文档
```

---

## ❓ 常见问题

**Q: 如何获取 Cesium Ion Token？**  
A: [注册 Cesium Ion](https://cesium.com/ion/signup/) 获取。

**Q: 如何加载自定义地形？**
```javascript
viewer.terrainProvider = new Cesium.CesiumTerrainProvider({
  url: 'your-terrain-url-token'
});
```

---

## 🤝 贡献指南

1. Fork 本仓库
2. 创建特性分支 (`git checkout -b feature/AmazingFeature`)
3. 提交更改 (`git commit -m 'Add some AmazingFeature'`)
4. 推送分支 (`git push origin feature/AmazingFeature`)
5. 发起 Pull Request

---

## 📜 开源协议

本项目基于 [MIT License](https://opensource.org/licenses/MIT) 协议开源。

```
Copyright (c) 2025 VGE团队

特此免费授予任何获得本软件及相关文档文件（以下简称“软件”）副本的人免费使用本软件的权利，
包括但不限于使用、复制、修改、合并、发布、分发、再许可及/或销售软件副本，
并允许被提供软件的人这样做，条件是上述版权声明和本许可声明应包含在软件的所有副本或主要部分中。

本软件按“原样”提供，不提供任何形式的明示或暗示担保，
包括但不限于适销性、特定用途适用性及不侵权的担保。
```
