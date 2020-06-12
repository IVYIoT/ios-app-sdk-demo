//
//  IvyCamera.h
//  IvySdk
//
//  Created by JackChan on 13/6/2019.
//  Copyright © 2019 ivyiot. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IvyConstants.h"

typedef void(^IvyCameraLoginBlock)(IVYIO_HANDLE_STATE handleState, IVYIO_RESULT cmdResult);

typedef void(^IvyCameraResultBlock)(_Nullable id obj, IVYIO_RESULT cmdResult);

NS_ASSUME_NONNULL_BEGIN

@interface IvyCamera : NSObject

/// 初始化IvyCamera对象
/// @param deviceUID 设备UID
/// @param username 设备用户名
/// @param password 设备密码
/// @return IvyCamera对象
- (instancetype)initWithDeviceUID:(NSString *)deviceUID username:(NSString *)username password:(NSString *)password;

/// 更新设备信息
/// @param deviceUID 设备UID
/// @param username 设备用户名
/// @param password 设备密码
- (BOOL)updateDeviceUID:(NSString *)deviceUID username:(NSString *)username password:(NSString *)password;

@end

@interface IvyCamera (Properties)

/// 设备句柄
@property (nonatomic, assign, readonly) IVYHANDLE handle;

/// 设备UID
@property (nonatomic, strong, readonly) NSString *deviceUID;

/// 设备用户名
@property (nonatomic, strong, readonly) NSString *username;

/// 设备密码
@property (nonatomic, strong, readonly) NSString *password;

/// 设备句柄状态
@property (nonatomic, assign, readonly) IVYIO_HANDLE_STATE handleState;

@end


@interface IvyCamera (APIs)

/// 登录Camera
/// @param resultBlock 登陆结果
- (void)loginCamera:(void(^)(IVYIO_HANDLE_STATE handleState, IVYIO_RESULT cmdResult))resultBlock;

/// 获取设备能力级
/// @param resultBlock 结果
- (void)getDevAbility:(void(^)(IvyDevAbility *devAbility, IVYIO_RESULT cmdResult))resultBlock;

/// 获取设备信息
/// @param resultBlock 结果
- (void)getDevInfo:(void(^)(IvyDevInfo *devInfo, IVYIO_RESULT cmdResult))resultBlock;

/// 获取设备SD卡信息
/// @param resultBlock 结果
- (void)getSDCardInfo:(void(^)(IvySDInfo *ivySDInfo, IVYIO_RESULT cmdResult))resultBlock;

/// 格式化SD卡
/// @param resultBlock 结果
- (void)setSDCardFormat:(IvyCameraResultBlock)resultBlock;

/// 修改设备用户名密码
/// @param newUserName 新用户名
/// @param newPassword 新密码
/// @param resultBlock 结果
- (void)modifyUserNameAndPassword:(NSString *)newUserName newPassword:(NSString *)newPassword onCompletion:(IvyCameraResultBlock)resultBlock;

/// 设置镜像状态
/// @param isMirror 开启镜像
/// @param resultBlock 结果
- (void)setMirrorVideo:(BOOL)isMirror onCompletion:(IvyCameraResultBlock)resultBlock;

/// 设置翻转状态
/// @param isFlip 开启翻转
/// @param resultBlock 结果
- (void)setFlipVideo:(BOOL)isFlip onCompletion:(IvyCameraResultBlock)resultBlock;

/// 设置红外灯状态
/// @param onoff 是否开启红外灯 (只有在手动模式下，onoff才会有效)
/// @param mode 红外灯的状态 (0：自动 1：手动 2：计划)
/// @param resultBlock 结果
- (void)setDayNightConfig:(BOOL)onoff mode:(NSInteger)mode onCompletion:(IvyCameraResultBlock)resultBlock;

/// 开始录像
/// @param filepath 文件存储路径
/// @param resultBlock 结果
- (void)startRecord:(NSString *)filepath onCompletion:(IvyCameraResultBlock)resultBlock;

/// 停止录像
/// @param resultBlock 结果
- (void)stopRecord:(IvyCameraResultBlock)resultBlock;

/// 云台控制
/// @param ptzCmd 控制命令
/// @param resultBlock 结果
- (void)setPTZCmd:(IVY_PTZ_CMD)ptzCmd onCompletion:(IvyCameraResultBlock)resultBlock;

/// 获取Wi-Fi列表
/// @param resultBlock 结果
- (void)getWiFiList:(IvyCameraResultBlock)resultBlock;

/// 设置Wi-Fi
/// @param model 选择的Wi-Fi类型
/// @param password Wi-Fi密码
/// @param resultBlock 结果
- (void)setWiFiConfig:(IvyWiFiDetail *)model password:(NSString *)password onCompletion:(IvyCameraResultBlock)resultBlock;

/// 获取设备系统时间
/// @param resultBlock 结果
- (void)getSystemTime:(void(^)(IvyDevTime *devTime, IVYIO_RESULT cmdResult))resultBlock;

/// 设置系统时间
/// @param devTime 时间对象
/// @param resultBlock 结果
- (void)setSystemTime:(IvyDevTime *)devTime onCompletion:(IvyCameraResultBlock)resultBlock;

/// 同步手机时间到设备
/// @param resultBlock 结果
- (void)syncSystemTime:(IvyCameraResultBlock)resultBlock;

/// 获取SD卡录像列表
/// @param startTime 开始时间
/// @param endTime 结束时间
/// @param recordType 录像类型
/// @param resultBlock 结果
/// @note 一次查询时间不能超过一天
- (void)getSDCardRecordList:(NSUInteger)startTime endTime:(NSUInteger)endTime recordType:(NSInteger)recordType onCompletion:(IvyCameraResultBlock)resultBlock;

/// 获取告警信息
/// @param resultBlock 结果
- (void)getMotionDetectConfig:(void(^)(IvyMotionDetect *config, IVYIO_RESULT cmdResult))resultBlock;

/// 设置告警信息
/// @param config DevMotionDetect对象
/// @param resultBlock 结果
- (void)setMotionDetectConfig:(IvyMotionDetect *)config onCompletion:(IvyCameraResultBlock)resultBlock;

/// 获取人体侦测信息
/// @param resultBlock 结果
- (void)getPedestrianDetectConfig:(void(^)(IvyPedestrianDetect *config, IVYIO_RESULT cmdResult))resultBlock;

/// 设置告警信息
/// @param config DevMotionDetect对象
/// @param resultBlock 结果
- (void)setPedestrianDetectConfig:(IvyPedestrianDetect *)config onCompletion:(IvyCameraResultBlock)resultBlock;

/// 获取人体侦测设备信息
/// @param resultBlock 结果
- (void)getPedestrianLicenseDeviceInfo:(void(^)(NSString *info, IVYIO_RESULT cmdResult))resultBlock;

/// 设置人体侦测License
/// @param license license
/// @param resultBlock 结果
- (void)setPedestrianLicense:(NSString *)license onCompletion:(IvyCameraResultBlock)resultBlock;

/// 获取声音告警
/// @param resultBlock 结果
- (void)getAudioDetectConfig:(void(^)(IvyAudioDetect *config, IVYIO_RESULT cmdResult))resultBlock;

/// 设置声音告警
/// @param config DevMotionDetect对象
/// @param resultBlock 结果
- (void)setAudioDetectConfig:(IvyAudioDetect *)config onCompletion:(IvyCameraResultBlock)resultBlock;

/// 获取设备Wi-Fi配置
/// @param resultBlock 结果
- (void)getWiFiConfig:(void(^)(IvyWiFiConfig *config, IVYIO_RESULT cmdResult))resultBlock;

/// 获取摄像机音量
/// @param resultBlock 结果
- (void)getAudioVolume:(void(^)(NSInteger volume, IVYIO_RESULT cmdResult))resultBlock;

/// 设置摄像机音量
/// @param volume 音量大小
/// @param resultBlock 结果
- (void)setAudioVolume:(NSInteger)volume onCompletion:(IvyCameraResultBlock)resultBlock;

/// 获取设置支持的清晰度类型
/// @param resultBlock 结果
/// @note types数组值参考IvyDefinitionType
- (void)getSupportedStreamTypes:(void(^)(NSArray *types, IVYIO_RESULT cmdResult))resultBlock;

/// 获取当前清晰度类型
/// @param resultBlock 结果
- (void)getStreamType:(void(^)(IvyDefinitionType streamType, IVYIO_RESULT cmdResult))resultBlock;

/// 设置摄像机清晰度
/// @param streamType 清晰度
/// @param resultBlock 结果
- (void)setStreamType:(IvyDefinitionType)streamType onCompletion:(IvyCameraResultBlock)resultBlock;

/// 获取预置点列表
/// @param resultBlock 结果
- (void)getPresetPointList:(void(^)(IvyPresetPoint *presetPoint, IVYIO_RESULT cmdResult))resultBlock;

/// 转到指定预置点
/// @param pointName 预置点
/// @param resultBlock 结果
- (void)goToPresetPoint:(NSString *)pointName onCompletion:(IvyCameraResultBlock)resultBlock;

/// 添加预置点
/// @param pointName 预置点
/// @param resultBlock 结果
- (void)addPresetPoint:(NSString *)pointName onCompletion:(IvyCameraResultBlock)resultBlock;

/// 删除预置点
/// @param pointName 预置点
/// @param resultBlock 结果
- (void)deletePresetPoint:(NSString *)pointName onCompletion:(void(^)(IvyPresetPoint *presetPoint, IVYIO_RESULT cmdResult))resultBlock;

/// 垂直巡航
/// @param resultBlock 结果
- (void)startVerticalCruise:(IvyCameraResultBlock)resultBlock;

/// 水平巡航
/// @param resultBlock 结果
- (void)startHorizontalCruise:(IvyCameraResultBlock)resultBlock;

/// 定点巡航
/// @param resultBlock 结果
/// @note 该模式要求预置位不得少于2个
- (void)startPresetPointCruise:(IvyCameraResultBlock)resultBlock;

/// 停止巡航
/// @param resultBlock 结果
- (void)stopCruise:(IvyCameraResultBlock)resultBlock;

/// 在线升级
/// @param URLString 升级链接
/// @param resultBlock 结果
- (void)setOnlineUpgrade:(NSString *)URLString onCompletion:(IvyCameraResultBlock)resultBlock;

/// 设置云存储配置
/// @param portal 网关地址
/// @param deviceMac 设备Mac
/// @param streamId 已授权的云存储Id
/// @param userTag 已授权的用户tag
/// @param resultBlock 结果
- (void)setCloudStorageConfig:(NSString *)portal deviceMac:(NSString *)deviceMac streamId:(NSString *)streamId userTag:(NSString *)userTag onCompletion:(IvyCameraResultBlock)resultBlock;

/// 设置富媒体推送配置
/// @param portal 网关地址
/// @param userTag 已授权的用户tag
/// @param resultBlock 结果
- (void)setRichMediaPushConfig:(NSString *)portal userTag:(NSString *)userTag onCompletion:(IvyCameraResultBlock)resultBlock;

/// 设置文本推送配置
/// @param portal 网关地址
/// @param userTag 已授权的用户tag
/// @param resultBlock 结果
- (void)setTextPushConfig:(NSString *)portal userTag:(NSString *)userTag onCompletion:(IvyCameraResultBlock)resultBlock;

/// 通用命令
/// @param cgiCommand 命令
/// @param parameters 输入参数
/// @param iTimeout 超时时长
/// @param resultBlock 结果
- (void)sendCommand:(int)cgiCommand parameters:(NSDictionary *)parameters iTimeout:(int)iTimeout onCompletion:(IvyCameraResultBlock)resultBlock;

@end



@interface IvyCamera (Event)

/// 添加一个事件的观察者
/// @param observer 观察者
/// @param aSelector 选择子
/// @note 必须调用removeEventObserver:移除当前观察者
- (void)addEventObserver:(id)observer selector:(SEL)aSelector;

/// 移除一个观察者
/// @param observer 观察者
- (void)removeEventObserver:(id)observer;

@end

NS_ASSUME_NONNULL_END
