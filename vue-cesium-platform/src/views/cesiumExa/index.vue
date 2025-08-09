<template>
  <button class="sci-fi-btn" @click="startTour">
    开始漫游
  </button>
  <div id="cesiumContainer"></div>
</template>

<script setup>
import { onMounted } from 'vue'
import * as Cesium from 'cesium'
import Roaming from '@/utils/Roaming'

let viewer;
let roaming;

const tourPoints = [
  { lon: 103.986241, lat: 30.764382, height: 200 }, // 起点：西南交通大学犀浦校区
  { lon: 103.988500, lat: 30.765200, height: 200 }, // 东北方向
  { lon: 103.990000, lat: 30.767000, height: 200 }, // 继续东北
  { lon: 103.992000, lat: 30.768500, height: 200 }, // 更远东北
  { lon: 103.994000, lat: 30.769000, height: 200 }, // 最远点
  { lon: 103.992500, lat: 30.770500, height: 200 }, // 开始向南
  { lon: 103.990500, lat: 30.772000, height: 200 }, // 继续向南
  { lon: 103.988000, lat: 30.773500, height: 200 }, // 更远南
  { lon: 103.985500, lat: 30.774000, height: 200 }, // 最南点
  { lon: 103.983000, lat: 30.772500, height: 200 }, // 开始向西
  { lon: 103.980500, lat: 30.770000, height: 200 }, // 继续向西
  { lon: 103.978000, lat: 30.767500, height: 200 }, // 更远西
  { lon: 103.975500, lat: 30.765000, height: 200 }, // 最西点
  { lon: 103.978000, lat: 30.763000, height: 200 }, // 开始向北
  { lon: 103.980500, lat: 30.761500, height: 200 }, // 继续向北
  { lon: 103.983000, lat: 30.760000, height: 200 }, // 更远北
  { lon: 103.985500, lat: 30.762500, height: 200 }, // 回到起点附近
  { lon: 103.986241, lat: 30.764382, height: 200 }  // 回到起点
];

const startTour = async () => {
  if (!roaming) {
    console.error('漫游类未初始化');
    return;
  }

  if (roaming.getRoamingStatus()) {
    roaming.switchPause();
    return;
  }

  try {
    // 加载漫游路径
    await roaming.load(tourPoints, 50); // 15秒漫游
    // 开始漫游
    roaming.start();
  } catch (error) {
    console.error('漫游启动失败:', error);
  }
};

onMounted(() => {
  Cesium.Ion.defaultAccessToken = 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJqdGkiOiJkODgzMmY3OC0yZDRmLTRjNjQtYTBlMi03OGRkZTBmY2M4YjIiLCJpZCI6MTQyNDMzLCJpYXQiOjE3NTA5MzM2MTB9.9z-CeiRJ3ct4NJCyFPnvvRCyFNqVtUsJXxwgi1OpHzk';

  viewer = new Cesium.Viewer('cesiumContainer', {
    homeButton: false,
    sceneModePicker: false,
    baseLayerPicker: false,
    navigationHelpButton: false,
    animation: true, // 启用动画
    timeline: true,   // 启用时间轴
    fullscreenButton: false,
    geocoder: false,
    infoBox: false,
    selectionIndicator: false
  });

  // 初始化漫游类
  roaming = new Roaming(viewer);

  // 初始视角：西南交通大学犀浦校区
  viewer.camera.flyTo({
    destination: Cesium.Cartesian3.fromDegrees(103.986241, 30.724382, 3000),
    orientation: {
      heading: Cesium.Math.toRadians(0),
      pitch: Cesium.Math.toRadians(-30),
      roll: 0.0
    },
    duration: 3
  }, 'easeInOutCubic');

  // 添加西南交通大学标记点
  viewer.entities.add({
    position: Cesium.Cartesian3.fromDegrees(103.986241, 30.764382),
    point: {
      pixelSize: 15,
      color: Cesium.Color.CYAN,
      outlineColor: Cesium.Color.WHITE,
      outlineWidth: 2
    },
    label: {
      text: '西南交通大学犀浦校区',
      font: '16pt monospace',
      style: Cesium.LabelStyle.FILL_AND_OUTLINE,
      outlineWidth: 2,
      verticalOrigin: Cesium.VerticalOrigin.BOTTOM,
      pixelOffset: new Cesium.Cartesian2(0, -15),
      fillColor: Cesium.Color.CYAN
    }
  });

  // 添加漫游路径标记点
  tourPoints.forEach((point, index) => {
    if (index > 0 && index < tourPoints.length - 1) {
      viewer.entities.add({
        position: Cesium.Cartesian3.fromDegrees(point.lon, point.lat),
        point: {
          pixelSize: 8,
          color: Cesium.Color.YELLOW,
          outlineColor: Cesium.Color.ORANGE,
          outlineWidth: 1
        },
        label: {
          text: `点${index}`,
          font: '12pt monospace',
          style: Cesium.LabelStyle.FILL_AND_OUTLINE,
          outlineWidth: 1,
          verticalOrigin: Cesium.VerticalOrigin.TOP,
          pixelOffset: new Cesium.Cartesian2(0, 10),
          fillColor: Cesium.Color.YELLOW
        }
      });
    }
  });
});
</script>

<style scoped>
#cesiumContainer {
  width: 100%;
  height: 100%;
  margin: 0;
  padding: 0;
  overflow: hidden;
}

.sci-fi-btn {
  position: absolute;
  top: 70px;
  right: 20px;
  z-index: 1000;
  display: inline-block;
  padding: 0.75em 2.5em;
  font-size: 1.2em;
  color: #00ffe7;
  background: linear-gradient(90deg, #0f2027 0%, #2c5364 100%);
  border: 2px solid #00ffe7;
  border-radius: 12px;
  box-shadow: 0 0 16px #00ffe7, 0 0 32px #1a2980 inset;
  letter-spacing: 2px;
  text-transform: uppercase;
  cursor: pointer;
  overflow: hidden;
  transition: all 0.3s ease;
  backdrop-filter: blur(10px);
}

.sci-fi-btn::before {
  content: "";
  position: absolute;
  top: -50%;
  left: -50%;
  width: 200%;
  height: 200%;
  background: linear-gradient(120deg, transparent 40%, #00ffe7 60%, transparent 80%);
  opacity: 0.5;
  transform: rotate(25deg);
  transition: opacity 0.3s;
  pointer-events: none;
}

.sci-fi-btn:hover {
  background: linear-gradient(90deg, #1a2980 0%, #26d0ce 100%);
  color: #fff;
  box-shadow: 0 0 32px #00ffe7, 0 0 64px #1a2980 inset;
  transform: translateY(-2px);
}

.sci-fi-btn:active {
  background: #0f2027;
  color: #00ffe7;
  box-shadow: 0 0 8px #00ffe7, 0 0 16px #1a2980 inset;
  transform: translateY(0);
}

.sci-fi-btn:focus {
  outline: none;
  box-shadow: 0 0 32px #00ffe7, 0 0 64px #1a2980 inset, 0 0 0 2px #00ffe7;
}
</style>