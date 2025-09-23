/*
 * @Author: changfanhao
 * @Date: 2023-02-27 18:21:57
 * @LastEditors: fuweiaa 2567873016@qq.com
 * @LastEditTime: 2025-09-12 21:52:03
 * @FilePath: \vue-cesium-platform\vite.config.js
 * @Description:
 * Copyright (c) 2023 by VGE, All Rights Reserved.
 */
import { defineConfig, loadEnv, ConfigEnv } from "vite"
import path from "node:path"
import { warpperEnv } from "./build"
import { include, exclude } from "./build/optimize"
import { getPluginsList } from "./build/plugins"

/** 当前执行node命令时文件夹的地址（工作目录） */
const root = process.cwd()

//@ts-ignore
const viteConfig = defineConfig((confg) => {
  const env = loadEnv(confg.mode, process.cwd())
  const { VITE_CDN, VITE_PORT, VITE_COMPRESSION, VITE_PUBLIC_PATH } =
    warpperEnv(loadEnv(confg.mode, root))
  console.log("VITE_MODE: ", confg.mode)
  console.log("ENV: ", env)

  return {
    root: process.cwd(),
    build: {
      assetsDir: "./",
      sourcemap: false,
      minify: ["false"].includes(env.VITE_IS_MINIFY) ? false : true,
      rollupOptions: {
        manualChunks(id) {
          if (id.includes("node_modules")) {
            return id
              .toString()
              .split("node_modules/")[1]
              .split("/")[0]
              .toString()
          }
        },
        output: {
          chunkFileNames: "static/js/[name]-[hash].js",
          entryFileNames: "static/js/[name]-[hash].js",
          assetFileNames: "static/[ext]/[name]-[hash].[ext]",
        },
      },
    },
    // base: confg.command == 'serve' ? './' : VITE_PUBLIC_PATH,
    base: confg.command === "serve" ? "./" : "./", // 将 base 统一为相对路径
    plugins: getPluginsList(confg.command, VITE_CDN, VITE_COMPRESSION),
    resolve: {
      alias: {
        "@": path.resolve(__dirname, "src"),
        components: path.resolve(__dirname, "src/components"),
      },
      extensions: [".mjs", ".js", ".ts", ".json", ".tsx", ".jsx", ".vue"],
    },
    optimizeDeps: {
      include,
      exclude,
    },
    server: {
      host: "0.0.0.0",
      port: 10010,
      open: JSON.parse(env.VITE_OPEN),
      cors: true,
    },
    test: {
      globals: true,
      environment: "edge-runtime",
    },
  }
})
export default viteConfig
