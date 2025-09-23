<!--
 * @Author: fuweiaa 2567873016@qq.com
 * @Date: 2025-09-12 20:41:33
 * @LastEditors: fuweiaa 2567873016@qq.com
 * @LastEditTime: 2025-09-12 22:00:44
 * @FilePath: \vue-cesium-platform\src\views\cesiumExa\index.vue
 * @Description: 
 * 
 * Copyright (c) 2025 by VGE, All Rights Reserved. 
-->
<template>
  <div id="cesiumContainer"></div>
</template>

<script setup>
import * as Cesium from 'Cesium';
import { onMounted } from 'vue';
onMounted(() => {
  var viewer = Cesium.DTGlobeViewer.createViewer(Cesium, 'cesiumContainer', false, {
    fullscreenButton: true
  });
})
</script>

<style scoped>
#cesiumContainer {
  width: 100%;
  height: 98vh;
}
</style>