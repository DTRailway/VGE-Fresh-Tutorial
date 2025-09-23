/*
 * @Author: 枫林残忆 2997534654@qq.com
 * @Date: 2024-04-09 13:07:56
 * @LastEditors: Lincong-pro lincong_pro@163.com
 * @LastEditTime: 2024-05-07 12:48:28
 * @FilePath: \Geology-v3\build\cdn.ts
 * @Description: 
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
 * 
 */
import { Plugin as importToCDN } from "vite-plugin-cdn-import";

//! 注意：vite的这个插件不能解决AutoImport的自动引入的插件，必须在rollup中进行声明

/**
 * @description 打包时采用`cdn`模式，仅限外网使用（默认不采用，如果需要采用cdn模式，请在 .env.production 文件，将 VITE_CDN 设置成true）
 * 平台采用国内cdn：https://www.bootcdn.cn，当然你也可以选择 https://unpkg.com 或者 https://www.jsdelivr.com
 * 提醒：mockjs不能用cdn模式引入，会报错。正确的方式是，生产环境删除mockjs，使用真实的后端请求
 * 注意：上面提到的仅限外网使用也不是完全肯定的，如果你们公司内网部署的有相关js、css文件，也可以将下面配置对应改一下，整一套内网版cdn
 */
export const cdn = importToCDN({
	//（prodUrl解释： name: 对应下面modules的name，version: 自动读取本地package.json中dependencies依赖中对应包的版本号，path: 对应下面modules的path，当然也可写完整路径，会替换prodUrl）
	prodUrl: "https://cdn.bootcdn.net/ajax/libs/{name}/{version}/{path}",
	modules: [
		{
			name: "vue",
			var: "Vue",
			path: "vue.global.prod.min.js"
		},
		{
			name: "vue-demi",
			var: "VueDemi",
			path: "index.iife.min.js"
		},
		{
			name: "vue-router",
			var: "VueRouter",
			path: "vue-router.global.min.js"
		},
		{
			name: "element-plus",
			var: "ElementPlus",
			path: "index.full.min.js",
			css: "index.min.css"
		},
		{
			name: "axios",
			var: "axios",
			path: "axios.min.js"
		},
		{
			name: "echarts",
			var: "echarts",
			path: "echarts.min.js"
		},
		{
			name: "video.js",// 源代码中的引入方式
			var: "videojs", // 包中导出的变量
			path: "video.min.js"
		},
		{
			name: "html2canvas",
			var: "html2canvas",
			path: "html2canvas.min.js"
		}
	]
});
