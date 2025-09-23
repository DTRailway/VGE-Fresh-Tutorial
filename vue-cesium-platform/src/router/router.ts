/*
 * @Author: fuweiaa 2567873016@qq.com
 * @Date: 2025-09-12 20:42:59
 * @LastEditors: fuweiaa 2567873016@qq.com
 * @LastEditTime: 2025-09-12 20:49:35
 * @FilePath: \vue-cesium-platform\src\router\router.ts
 * @Description:
 *
 * Copyright (c) 2025 by VGE, All Rights Reserved.
 */
import { createRouter, createWebHistory } from "vue-router"
// 导入你的页面组件

// 路由规则配置
const routes = [
  {
    path: "/",
    name: "Home",
    component: () => import("@/views/Home.vue"),
    children: [],
  },
  {
    path: "/3DScene",
    name: "3DScene",
    component: () => import("@/views/cesiumExa/index.vue"),
    // 也可以使用懒加载方式
    // component: () => import('../views/About.vue')
  },
]

// 创建路由实例
const router = createRouter({
  history: createWebHistory(), // 使用HTML5 history模式
  routes, // 传入路由规则
})

export default router // 导出路由实例
