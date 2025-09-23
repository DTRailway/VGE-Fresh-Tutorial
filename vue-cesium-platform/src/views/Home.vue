<template>
  <div class="page-container">
    <!-- 头部导航栏 -->
    <header class="header">
      <div class="logo">地质三维可视化平台</div>
      <nav class="nav">
        <a href="#" class="nav-item active">首页</a>
        <a href="#" class="nav-item">模型管理</a>
        <a href="#" class="nav-item">数据分析</a>
        <a href="#" class="nav-item">帮助文档</a>
        <a href="#" class="nav-item">关于我们</a>
      </nav>
    </header>

    <!-- 主要内容区 -->
    <main class="main-content">
      <h1>欢迎使用地质三维可视化平台</h1>
      <p class="intro">
        该平台提供专业的三维地质模型展示与分析功能，支持模型剖切、属性查询等多种交互操作。
      </p>

      <!-- 三维场景入口 -->
      <div class="cesium-view" @click="goToCesium">
        <i class="icon" aria-hidden="true"></i>
        三维可视化地球场景
      </div>
    </main>
  </div>
</template>

<script setup lang="ts">
import router from '@/router/router';

// 定义跳转方法
const goToCesium = () => {
  // 跳转路由到三维场景页面
  router.push('/3DScene');
};
</script>

<style lang="scss" scoped>
.page-container {
  min-height: 100vh;
  display: flex;
  flex-direction: column;
}

// 头部导航样式
.header {
  display: flex;
  align-items: center;
  justify-content: space-between;
  padding: 0 2rem;
  height: 60px;
  background-color: #1e293b;
  color: white;
  box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);

  .logo {
    font-size: 1.25rem;
    font-weight: bold;
  }

  .nav {
    display: flex;
    gap: 1rem;

    .nav-item {
      color: #e2e8f0;
      text-decoration: none;
      padding: 0.5rem 0.75rem;
      border-radius: 4px;
      transition: all 0.3s ease;

      &:hover {
        background-color: #334155;
        color: white;
      }

      &.active {
        background-color: #409eff;
        color: white;
      }
    }
  }
}

// 主要内容区样式
.main-content {
  flex: 1;
  display: flex;
  flex-direction: column;
  align-items: center;
  justify-content: center;
  padding: 2rem;
  background-color: #f8fafc;

  h1 {
    font-size: 2rem;
    color: #1e293b;
    margin-bottom: 1rem;
  }

  .intro {
    font-size: 1.1rem;
    color: #64748b;
    max-width: 800px;
    text-align: center;
    margin-bottom: 2rem;
    line-height: 1.6;
  }
}

// 三维场景入口样式
.cesium-view {
  width: 240px;
  height: 60px;
  line-height: 60px;
  text-align: center;
  background-color: #409eff;
  color: #fff;
  border-radius: 6px;
  cursor: pointer;
  user-select: none;
  font-size: 1.05rem;
  transition: all 0.3s ease;
  display: flex;
  align-items: center;
  justify-content: center;
  gap: 8px;

  &:hover {
    background-color: #3688e6;
    transform: translateY(-2px);
    box-shadow: 0 4px 12px rgba(64, 158, 255, 0.3);
  }

  .icon::before {
    content: "🌐";
    font-size: 1.2rem;
  }
}
</style>
