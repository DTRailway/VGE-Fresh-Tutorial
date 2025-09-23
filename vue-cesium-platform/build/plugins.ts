/*
 * @Author: 枫林残忆
 * @Date: 2024-04-05 09:21:49
 * @LastEditors: fuwei 2567873016@qq.com
 * @LastEditTime: 2024-10-15 11:38:33
 * @FilePath: \Geology-v3\build\plugins.ts
 * @Description:
 * Copyright (c) 2024 by VGE, All Rights Reserved.
 */
import { cdn } from "./cdn";
import vue from "@vitejs/plugin-vue";
import { viteBuildInfo } from "./info";
import vueJsx from "@vitejs/plugin-vue-jsx";
import { configCompressPlugin } from "./compress";
import { visualizer } from "rollup-plugin-visualizer";
import removeConsole from "vite-plugin-remove-console";
import { createSvgIconsPlugin } from 'vite-plugin-svg-icons';
import htmlConfig from 'vite-plugin-html-config';
import { viteExternalsPlugin } from 'vite-plugin-externals';

import path from 'node:path';

const externalConfig = viteExternalsPlugin({
	Cesium: 'Cesium',
	turf: 'turf',
});
const svgConfig = createSvgIconsPlugin({
	iconDirs: [
		path.resolve(process.cwd(), 'src/views/SceneManagement/Layout/Assets/svg'),
	],
	symbolId: 'icon-[name]',
});

const htmlConfigs = htmlConfig({
	headScripts: [
	],
	links: [
	],
});


export function getPluginsList(
	command: string,
	VITE_CDN: boolean,
	VITE_COMPRESSION: ViteCompression
) {
	// const prodMock = true;
	const lifecycle = process.env.npm_lifecycle_event;
	return [
		vue(),
		// jsx、tsx语法支持
		vueJsx(),
		// VITE_CDN ? cdn : null,
		configCompressPlugin(VITE_COMPRESSION),
		// 线上环境删除console
		removeConsole(),
		viteBuildInfo(),
		// 打包分析
		lifecycle === "report"
			? visualizer({ open: true, brotliSize: true, gzipSize: true, filename: "report.html" })
			: null,
		// 配置第三方库
		viteExternalsPlugin({
			Cesium: "Cesium",
		}),
		externalConfig,
		svgConfig,
		htmlConfigs
	];
}
