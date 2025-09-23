/*
 * @Author: 枫林残忆 2997534654@qq.com
 * @Date: 2024-04-09 13:07:56
 * @LastEditors: 枫林残忆 2997534654@qq.com
 * @LastEditTime: 2024-04-09 16:05:16
 * @FilePath: \Geology-V3\build\index.ts
 * @Description: 
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
 * 
 */
/** 处理环境变量 */
const warpperEnv = (envConf: Recordable): ViteEnv => {
	/** 此处为默认值 */
	const ret: ViteEnv = {
		VITE_PORT: 10010,
		VITE_PUBLIC_PATH: "",
		VITE_ROUTER_HISTORY: "",
		VITE_CDN: false,
		VITE_HIDE_HOME: "false",
		VITE_COMPRESSION: "gzip"
	};

	for (const envName of Object.keys(envConf)) {
		let realName = envConf[envName].replace(/\\n/g, "\n");
		realName =
			realName === "true" ? true : realName === "false" ? false : realName;

		if (envName === "VITE_PORT") {
			realName = Number(realName);
		}
		ret[envName] = realName;
		if (typeof realName === "string") {
			process.env[envName] = realName;
		} else if (typeof realName === "object") {
			process.env[envName] = JSON.stringify(realName);
		}
	}
	return ret;
};

export { warpperEnv };
