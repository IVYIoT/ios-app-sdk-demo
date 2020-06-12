//
//  IvyObject.h
//  IvySdk
//
//  Created by JackChan on 1/7/2019.
//  Copyright © 2019 ivyiot. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface IvyObject : NSObject

@end



@interface IvyDevAbility : IvyObject

@property (nonatomic, assign) NSInteger val0;
@property (nonatomic, assign) NSInteger val1;
@property (nonatomic, assign) NSInteger val2;
@property (nonatomic, assign) NSInteger val3;
@property (nonatomic, assign) NSInteger val4;
@property (nonatomic, assign) NSInteger val5;
@property (nonatomic, assign) NSInteger val6;
@property (nonatomic, assign) NSInteger val7;
@property (nonatomic, assign) NSInteger val8;

@end


@interface IvyDevAbility (Helper)

/// 是否支持 sd 卡
@property (nonatomic, assign, readonly) BOOL enableSD;

/// 是否支持 outdoor
@property (nonatomic, assign, readonly) BOOL enableOutdoor;

/// 是否支持 pt
@property (nonatomic, assign, readonly) BOOL enablePT;

/// 是否支持 zoom
@property (nonatomic, assign, readonly) BOOL enableZoom;

/// 是否支持 rs485
@property (nonatomic, assign, readonly) BOOL enableRS485;

/// 是否支持 ioAlarm
@property (nonatomic, assign, readonly) BOOL enableIOAlarm;

/// 是否支持 onvif
@property (nonatomic, assign, readonly) BOOL enableOnvif;

/// 是否支持 p2p
@property (nonatomic, assign, readonly) BOOL enableP2P;

/// 是否支持 wps
@property (nonatomic, assign, readonly) BOOL enableWPS;

/// 是否支持 audio
@property (nonatomic, assign, readonly) BOOL enableAudio;

/// 是否支持 talk
@property (nonatomic, assign, readonly) BOOL enableTalk;

/// 是否支持 全双工
@property (nonatomic, assign, readonly) BOOL enableDuplexVoice;

/// 是否支持 视频参数网络自适应
@property (nonatomic, assign, readonly) BOOL enableNetworkAdapter;

/// 是否支持 分辨率切换和主次码流切换，false：只支持主次码流切换
@property (nonatomic, assign, readonly) BOOL enableStreamMode;

/// 是否支持 区域选择
@property (nonatomic, assign, readonly) BOOL enableMotionArea;

/// 是否支持 一键呼叫
@property (nonatomic, assign, readonly) BOOL enableOneKeyCall;

/// 是否支持 夜视计划
@property (nonatomic, assign, readonly) BOOL enableNightVisionSchedule;

/// 是否支持 dropbox 云存储，false表示支持百度云存储（fosbaby内外销系列都只支持百度云存储）
@property (nonatomic, assign, readonly) BOOL enableDropboxStorage;

/// 是否支持 百度推送
@property (nonatomic, assign, readonly) BOOL enableBaiduPush;

/// 是否支持 Foscam 推送
@property (nonatomic, assign, readonly) BOOL enableFoscamPush;

/// 是否支持 Foscam 存储
@property (nonatomic, assign, readonly) BOOL enableFoscamStorage;

/// 是否支持 Foscam 富媒体推送
@property (nonatomic, assign, readonly) BOOL enableFoscamRichPush;

/// 是否支持 Alexa
@property (nonatomic, assign, readonly) BOOL enableAlexa;

/// 是否支持 7*24 小时云存储
@property (nonatomic, assign, readonly) BOOL enable24HStorage;

/// 是否支持 告警录像时长设置
@property (nonatomic, assign, readonly) BOOL enableRecordTimeSet;

/// 是否支持 APP 预置位巡航
@property (nonatomic, assign, readonly) BOOL enablePresetCruise;

/// 是否支持 SmartHome
@property (nonatomic, assign, readonly) BOOL enableSmartHome;

/// 是否支持 框外侦测
@property (nonatomic, assign, readonly) BOOL enableOutSideDetect;

/// 是否支持 声音侦测
@property (nonatomic, assign, readonly) BOOL enableAudioDetect;

/// 是否支持 温度侦测
@property (nonatomic, assign, readonly) BOOL enableTemperatureDetect;

/// 是否支持 湿度侦测
@property (nonatomic, assign, readonly) BOOL enableHumidityDetect;

/// 是否支持 PIR侦测
@property (nonatomic, assign, readonly) BOOL enablePIRDetect;

/// 是否支持 IV侦测
@property (nonatomic, assign, readonly) BOOL enableIVDetect;

/// 是否支持 人体侦测--爱华盈通
@property (nonatomic, assign, readonly) BOOL enableHumanDetect_aiwinn;

/// 是否支持 人体侦测--珊口
@property (nonatomic, assign, readonly) BOOL enableHumanDetect_sanko;

/// 是否支持 童谣
@property (nonatomic, assign, readonly) BOOL enableBabyMusic;

/// 是否支持 芯片加密
@property (nonatomic, assign, readonly) BOOL enableChipEncrypt;

/// 是否支持 SoftAP
@property (nonatomic, assign, readonly) BOOL enableSoftAP;

/// 是否支持 EZLink(不区分芯片，不表示是否支持IPC扫码)
@property (nonatomic, assign, readonly) BOOL enableEZLink;

/// 是否支持 PPPoE
@property (nonatomic, assign, readonly) BOOL enablePPPoE;

/// 是否支持 夜视红外功能
@property (nonatomic, assign, readonly) BOOL enableNightIRCut;

/// 是否支持 镜头畸变矫正
@property (nonatomic, assign, readonly) BOOL enableDistortion;

/// 是否支持 录像功能
@property (nonatomic, assign, readonly) BOOL enableRecord;

/// 是否支持 定时重启
@property (nonatomic, assign, readonly) BOOL enableReboot;

/// 是否支持 布撤防
@property (nonatomic, assign, readonly) BOOL enableDefend;

/// 是否支持 led 灯开关
@property (nonatomic, assign, readonly) BOOL enableLEDLight;

/// 是否支持 小夜灯开关
@property (nonatomic, assign, readonly) BOOL enableNightLight;

/// 是否支持 音量控制
@property (nonatomic, assign, readonly) BOOL enableVolume;

/// 是否支持 HDR
@property (nonatomic, assign, readonly) BOOL enableHDR;

/// 是否支持 WDR
@property (nonatomic, assign, readonly) BOOL enableWDR;

/// 是否支持 语音提示开关
@property (nonatomic, assign, readonly) BOOL enableVoiceTip;

/// 是否支持 双马达自动聚焦
@property (nonatomic, assign, readonly) BOOL enable2MotorsAutoFocus;

/// 是否支持 云台巡航看守位
@property (nonatomic, assign, readonly) BOOL enablePTCruise;

@end



@interface IvyDevInfo : NSObject

/// 设备类型
@property (nonatomic, assign) NSInteger devType;

/// 平台类型
@property (nonatomic, assign) NSInteger platType;

/// sensor类型
@property (nonatomic, assign) NSInteger sensorType;

/// wifi类型
@property (nonatomic, assign) NSInteger wifiType;

/// 语言
@property (nonatomic, assign) NSInteger language;

/// 产品名字
@property (nonatomic, strong) NSString *productName;

/// 设备名
@property (nonatomic, strong) NSString *devName;

/// 应用固件版本号
@property (nonatomic, strong) NSString *firmwareVersion;

/// 系统固件版本号
@property (nonatomic, strong) NSString *hardwareVersion;

/// 序列号
@property (nonatomic, assign) NSInteger serialNo;

/// 设备UID
@property (nonatomic, strong) NSString *uid;

/// MAC 地址
@property (nonatomic, strong) NSString *mac;

/// OEM 码
@property (nonatomic, assign) NSInteger oemCode;

@end



@interface IvyDevLan : IvyObject

/// Mac地址
@property (nonatomic, strong) NSString *mac;

/// 设备名
@property (nonatomic, strong) NSString *name;

/// IP地址
@property (nonatomic, strong) NSString *ip;

/// mask
@property (nonatomic, assign) NSInteger mask;

/// NDS
@property (nonatomic, assign) NSInteger dns;

/// 类型 0:FOSIPC_H264 1:FOSIPC_MJ 2: FOSIPC_UNKNOW
@property (nonatomic, assign) NSInteger type;

/// 端口
@property (nonatomic, assign) NSInteger port;

/// DHCP 是否开启
@property (nonatomic, assign) NSInteger dhcp_enabled;

/// 设备UID
@property (nonatomic, strong) NSString *uid;

@end



@interface IvyMotionDetect : IvyObject

/// 开关 (0:关 1:开)
@property (nonatomic, assign) NSInteger isEnable;

/// 联动 (Bit0:Ring Bit1:发送邮件 Bit2:截图 Bit3:录像 Bit4:Io输出 Bit5:截图上云 Bit6:录像上云 Bit7:手机推送)
@property (nonatomic, assign) NSInteger linkage;

/// 敏感度
@property (nonatomic, assign) NSInteger sensitivity;

/// 触发间隔
@property (nonatomic, assign) NSInteger triggerInterval;

/// 周日
/// @note bit0-bit47表示一天，每个bit表示半个小时
@property (nonatomic, assign) long long schedule0;

/// 周一
@property (nonatomic, assign) long long schedule1;

/// 周二
@property (nonatomic, assign) long long schedule2;

/// 周三
@property (nonatomic, assign) long long schedule3;

/// 周四
@property (nonatomic, assign) long long schedule4;

/// 周五
@property (nonatomic, assign) long long schedule5;

/// 周六
@property (nonatomic, assign) long long schedule6;

@end



@interface IvyAudioDetect : IvyObject

/// 开关 (0:关 1:开)
@property (nonatomic, assign) NSInteger isEnable;

/// 联动 (Bit0:Ring Bit1:发送邮件 Bit2:截图 Bit3:录像 Bit4:Io输出 Bit5:截图上云 Bit6:录像上云 Bit7:手机推送)
@property (nonatomic, assign) NSInteger linkage;

/// 敏感度
@property (nonatomic, assign) NSInteger sensitivity;

/// 触发间隔
@property (nonatomic, assign) NSInteger triggerInterval;

/// 抓拍间隔
@property (nonatomic, assign) NSInteger snapInterval;

/// 周日
/// @note bit0-bit47表示一天，每个bit表示半个小时
@property (nonatomic, assign) long long schedule0;

/// 周一
@property (nonatomic, assign) long long schedule1;

/// 周二
@property (nonatomic, assign) long long schedule2;

/// 周三
@property (nonatomic, assign) long long schedule3;

/// 周四
@property (nonatomic, assign) long long schedule4;

/// 周五
@property (nonatomic, assign) long long schedule5;

/// 周六
@property (nonatomic, assign) long long schedule6;

@end


@interface IvySDInfo : NSObject

/// 是否存在SD卡
@property (nonatomic, assign) BOOL isExist;

/// SD的剩余空间
@property (nonatomic, assign) unsigned long long freeSpace;

/// SD卡总空间
@property (nonatomic, assign) unsigned long long totalSpace;

@end



@interface IvyDevTime : IvyObject

/// 年
@property (nonatomic, assign) NSInteger year;

/// 月
@property (nonatomic, assign) NSInteger month;

/// 日
@property (nonatomic, assign) NSInteger day;

/// 小时
@property (nonatomic, assign) NSInteger hour;

/// 分钟
@property (nonatomic, assign) NSInteger min;

/// 秒
@property (nonatomic, assign) NSInteger sec;

/// ntp服务器
@property (nonatomic, strong) NSString *ntpServer;

/// 日期格式 (0:YYYY-MM-DD 1:DD/MM/YYYY 2:MM/DD/YYYY)
@property (nonatomic, assign) NSInteger dateFormat;

/// 夏令时时长
@property (nonatomic, assign) NSInteger dst;

/// 是否有夏令时 (0:没有夏令时 1:有夏令时)
@property (nonatomic, assign) NSInteger isDst;

/// 时间格式 (0:24小时 1:12小时)
@property (nonatomic, assign) NSInteger timeFormat;

/// 时间来源 (0:NTP 1:手动同步)
@property (nonatomic, assign) NSInteger timeSource;

/// 时区
@property (nonatomic, assign) NSInteger timeZone;

@end



@interface IvyWiFiDetail : IvyObject

/// Wi-Fi ssid
@property (nonatomic, strong) NSString *ssid;

/// Wi-Fi mac
@property (nonatomic, strong) NSString *mac;

/// 是否加密
@property (nonatomic, assign) BOOL encryption;

/// 信号质量 (0-100) 值越大，信号质量越高
@property (nonatomic, assign) NSInteger quality;

/// 模式
@property (nonatomic, assign) NSInteger mode;

/// 加密类型
@property (nonatomic, assign) NSInteger encryptType;


@end



@interface IvyWiFiConfig : IvyObject

/// SSID
@property (nonatomic, strong) NSString *ssid;

/// Wi-Fi 加密类型
@property (nonatomic, assign) NSInteger encryptType;

@end



@interface IvyStreamParam : NSObject

/// GOP
@property (nonatomic, assign) int GOP;

/// bitRate
@property (nonatomic, assign) int bitRate;

/// frameRate
@property (nonatomic, assign) int frameRate;

/// isVBR
@property (nonatomic, assign) int isVBR;

/// resolution
@property (nonatomic, assign) int resolution;

@end



@interface IvyPresetPoint : IvyObject

/// 结果 0: 成功 1:预置点不存在  2:参数错误 3: 添加出厂预置点 4: 已存在
@property (nonatomic, assign) NSInteger result;

/// 预置点名称
@property (nonatomic, strong) NSArray<NSString *> *pointNames;

@end



@interface IvyPedestrianDetect : IvyObject

/// 开关
@property (nonatomic, assign) BOOL isEnable;

/// 追踪开关
@property (nonatomic, assign) BOOL isTrackEnable;

/// 联动告警
@property (nonatomic, assign) NSInteger linkage;

/// 灵敏度 0：low 1:middle 2:high
@property (nonatomic, assign) NSInteger sensitivity;

/// 抓拍时间间隔
@property (nonatomic, assign) NSInteger snapInterval;

/// 触发时间间隔
@property (nonatomic, assign) NSInteger triggerInterval;

@end

NS_ASSUME_NONNULL_END
