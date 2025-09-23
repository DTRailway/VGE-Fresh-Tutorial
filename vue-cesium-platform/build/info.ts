/*
 * @Author: 枫林残忆 2997534654@qq.com
 * @Date: 2024-04-09 13:07:56
 * @LastEditors: 枫林残忆 2997534654@qq.com
 * @LastEditTime: 2024-04-09 14:36:06
 * @FilePath: \Geology-V3\build\info.ts
 * @Description: 
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
 * 
 */
import type { Plugin } from "vite";
import dayjs, { Dayjs } from "dayjs";
import { sum, formatBytes } from "@pureadmin/utils";
import duration from "dayjs/plugin/duration";
import { readdir, stat } from "node:fs";
import * as picocolors from 'picocolors'

dayjs.extend(duration);

const fileListTotal: number[] = [];

/** 获取指定文件夹中所有文件的总大小 */
const getPackageSize = options => {
	const { folder = "dist", callback, format = true } = options;
	readdir(folder, (err, files: string[]) => {
		if (err) throw err;
		let count = 0;
		const checkEnd = () => {
			++count == files.length &&
				callback(format ? formatBytes(sum(fileListTotal)) : sum(fileListTotal));
		};
		files.forEach((item: string) => {
			stat(`${folder}/${item}`, async (err, stats) => {
				if (err) throw err;
				if (stats.isFile()) {
					fileListTotal.push(stats.size);
					checkEnd();
				} else if (stats.isDirectory()) {
					getPackageSize({
						folder: `${folder}/${item}/`,
						callback: checkEnd
					});
				}
			});
		});
		files.length === 0 && callback(0);
	});
};


export function viteBuildInfo(): Plugin {
	let config: { command: string };
	let startTime: Dayjs;
	let endTime: Dayjs;
	let outDir: string;
	return {
		name: "vite:buildInfo",
		configResolved(resolvedConfig) {
			config = resolvedConfig;
			outDir = resolvedConfig.build?.outDir ?? "dist";
		},
		buildStart() {
			console.log(
				//@ts-ignore
				picocolors.default.bold(picocolors.default.green(`👏欢迎使用${picocolors.default.blue("[vue-pure-admin]")}，DTRailServer`))
			);
			if (config.command === "build") {
				startTime = dayjs(new Date());
			}
		},
		closeBundle() {
			if (config.command === "build") {
				endTime = dayjs(new Date());
				getPackageSize({
					folder: outDir,
					callback: (size: string) => {
						console.log(//@ts-ignore
							picocolors.default.bold(//@ts-ignore
								picocolors.default.green(
									`🎉恭喜打包完成（总用时${dayjs
										.duration(endTime.diff(startTime))
										.format("mm分ss秒")}，打包后的大小为${size}）`
								)
							)
						);
					}
				});
			}
		}
	};
}
