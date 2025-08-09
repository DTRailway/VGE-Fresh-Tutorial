import * as Cesium from 'cesium';

/**
 * @description: 漫游工具类
 */
class Roaming {
  private viewer: Cesium.Viewer;
  private roamingEntity: Cesium.Entity | undefined;
  private startTime: Cesium.JulianDate;
  private duration: number = 8; // 漫游总时长（秒）
  private isRoaming: boolean = false;
  private clockTickListener: any;

  constructor(viewer: Cesium.Viewer) {
    this.viewer = viewer;
    this.startTime = Cesium.JulianDate.fromDate(new Date(2025, 3, 26, 14, 0, 0));
  }

  /**
   * @description: 加载漫游路径并启动漫游
   * @param {Array} pathPoints - 漫游路径点数组，格式：[{lon, lat, height, heading?, pitch?, roll?}]
   * @param {number} duration - 漫游总时长（秒），默认8秒
   * @return {Promise<void>}
   */
  public async load(pathPoints: any[], duration: number = 8): Promise<void> {
    try {
      if (!pathPoints || pathPoints.length < 2) {
        console.error('漫游路径至少需要2个点');
        return;
      }

      console.log('开始加载漫游路径，点数:', pathPoints.length);
      this.duration = duration;
      const cartesians: Cesium.Cartesian3[] = []; // 坐标点数组
      const orientations: Cesium.Cartesian3[] = []; // 朝向数组

      // 遍历路径点，计算笛卡尔坐标和朝向
      pathPoints.forEach((item, index) => {
        const cartesian = Cesium.Cartesian3.fromDegrees(item.lon, item.lat, item.height);
        cartesians.push(cartesian);

        // 计算朝向（如果没有提供，则自动计算）
        let heading = item.heading || 0;
        let pitch = item.pitch || -20;
        let roll = item.roll || 0;

        // 如果不是最后一个点，自动计算朝向
        if (index < pathPoints.length - 1 && !item.heading) {
          const nextPoint = pathPoints[index + 1];
          const deltaLon = nextPoint.lon - item.lon;
          const deltaLat = nextPoint.lat - item.lat;
          heading = Math.atan2(deltaLon, deltaLat) * 180 / Math.PI;
        }

        const orientation = new Cesium.Cartesian3(
          Cesium.Math.toRadians(heading),
          Cesium.Math.toRadians(pitch),
          Cesium.Math.toRadians(roll)
        );
        orientations.push(orientation);
      });

      // 计算路径总长度并分配时间
      let totalLength = 0;
      const distances: number[] = [0];
      
      for (let i = 1; i < cartesians.length; i++) {
        const distance = Cesium.Cartesian3.distance(cartesians[i - 1], cartesians[i]);
        totalLength += distance;
        distances.push(totalLength);
      }

      console.log('路径总长度:', totalLength, '米');

      // 创建位置和朝向属性
      const positionProperty = new Cesium.SampledPositionProperty();
      const orientationProperty = new Cesium.SampledProperty(Cesium.Cartesian3);

      // 为每个路径段创建采样点
      for (let i = 0; i < cartesians.length; i++) {
        const proportion = distances[i] / totalLength;
        const seconds = proportion * this.duration;
        const time = Cesium.JulianDate.addSeconds(this.startTime, seconds, new Cesium.JulianDate());
        
        positionProperty.addSample(time, cartesians[i]);
        
        // 朝向控制：只在到达点时设置朝向
        orientationProperty.addSample(time, orientations[i]);
      }

      // 移除之前的漫游实体
      if (this.roamingEntity) {
        this.viewer.entities.remove(this.roamingEntity);
      }

      // 添加漫游实体到场景
      this.roamingEntity = this.viewer.entities.add({
        availability: new Cesium.TimeIntervalCollection([
          new Cesium.TimeInterval({
            start: this.startTime,
            stop: Cesium.JulianDate.addSeconds(this.startTime, this.duration, new Cesium.JulianDate()),
          }),
        ]),
        position: positionProperty,
        orientation: orientationProperty,
        point: {
          show: false, // 隐藏实体点
        },
      });

      // 设置时钟
      this.viewer.clock.startTime = this.startTime.clone();
      this.viewer.clock.stopTime = Cesium.JulianDate.addSeconds(this.startTime, this.duration, new Cesium.JulianDate());
      this.viewer.clock.currentTime = this.startTime.clone();
      this.viewer.clock.clockRange = Cesium.ClockRange.UNBOUNDED;
      this.viewer.clock.multiplier = 1;
      this.viewer.clock.shouldAnimate = false;
      
      // 安全地设置timeline
      if (this.viewer.timeline) {
        this.viewer.timeline.zoomTo(this.startTime, this.viewer.clock.stopTime.clone());
      }

      // 监听时钟更新
      this.clockTickListener = this.cameraViewListener.bind(this);
      this.viewer.clock.onTick.addEventListener(this.clockTickListener);
      
      console.log('漫游路径加载完成');
    } catch (error) {
      console.error('加载漫游路径时出错:', error);
      throw error;
    }
  }

  /**
   * @description: 开始漫游
   */
  public start(): void {
    if (!this.roamingEntity) {
      console.warn('请先加载漫游路径');
      return;
    }
    
    this.isRoaming = true;
    this.viewer.clock.shouldAnimate = true;
    console.log('开始漫游');
  }

  /**
   * @description: 停止漫游
   */
  public stop(): void {
    this.isRoaming = false;
    this.viewer.clock.shouldAnimate = false;
    this.viewer.clock.currentTime = this.startTime.clone(); // 回到起点
    
    if (this.clockTickListener) {
      this.viewer.clock.onTick.removeEventListener(this.clockTickListener);
    }
    
    console.log('停止漫游');
  }

  /**
   * @description: 切换暂停状态
   */
  public switchPause(): void {
    if (!this.roamingEntity) {
      console.warn('请先加载漫游路径');
      return;
    }
    
    this.viewer.clock.shouldAnimate = !this.viewer.clock.shouldAnimate;
    this.isRoaming = this.viewer.clock.shouldAnimate;
    
    console.log(this.isRoaming ? '继续漫游' : '暂停漫游');
  }

  /**
   * @description: 获取漫游状态
   */
  public getRoamingStatus(): boolean {
    return this.isRoaming;
  }

  /**
   * @description: 清理漫游
   */
  public destroy(): void {
    this.stop();
    
    if (this.roamingEntity) {
      this.viewer.entities.remove(this.roamingEntity);
      this.roamingEntity = undefined;
    }
    
    if (this.clockTickListener) {
      this.viewer.clock.onTick.removeEventListener(this.clockTickListener);
      this.clockTickListener = undefined;
    }
    
    console.log('清理漫游');
  }

  /**
   * @description: 相机视角更新的监听器
   * @param {Object} tick - 时钟的 tick 事件
   */
  private cameraViewListener = (tick: any): void => {
    if (!this.viewer.clock.shouldAnimate || !this.roamingEntity) {
      return;
    }
    
    const position = this.roamingEntity.position.getValue(tick.currentTime);
    const orientation = this.roamingEntity.orientation.getValue(tick.currentTime);
    
    if (position && orientation) {
      this.viewer.camera.setView({
        destination: position,
        orientation: {
          heading: orientation.x,
          pitch: orientation.y,
          roll: orientation.z,
        },
      });
    }
  };
}

export default Roaming;
