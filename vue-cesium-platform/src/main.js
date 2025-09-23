import { createApp } from 'vue'
import App from './App.vue'
import router from './router/router.ts'  // 导入路由实例

// 创建应用并使用路由，然后挂载
createApp(App)
  .use(router)  // 关键步骤：使用路由
  .mount('#app')