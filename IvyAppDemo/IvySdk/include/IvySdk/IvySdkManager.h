//
//  IvySdkManager.h
//  IvySdk
//
//  Created by JackChan on 26/6/2019.
//  Copyright © 2019 ivyiot. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IvyConstants.h"

NS_ASSUME_NONNULL_BEGIN

@interface IvySdkManager : NSObject

/// 单例对象
/// @return 单例对象
+ (IvySdkManager *)shared;

/// 初始化方法
- (void)initializer;

/// 获取版本信息
/// @return 版本信息
- (NSString *)versionInfo;

/// 设置Sdk日志信息
/// @param level 日志等级 (0: NO 1: Error 2:Debug 3: All)
/// @param filepath 日志文件路径
/// @param maxSize 文件最大尺寸(M)
- (void)setLog:(NSInteger)level filepath:(NSString *)filepath maxSize:(NSUInteger)maxSize;

/// 停止局域网搜索
- (void)stopDiscovery;

/// 重启局域网搜索
- (void)restartDiscovery;

/// 搜索局域网设备
/// @param resultBlock 结果
- (void)searchDevices:(void(^)(NSArray<IvyDevLan *> *devices))resultBlock;

/// EZLink 3.0(IPC扫码配网)
/// @param SSID 路由器SSID
/// @param password 路由器密码
/// @return 配网字符串
/// @note 根据该字符串，生成对应的二维码，用于IPC的配置网络
- (NSString *)qrCodeString:(NSString *)SSID password:(NSString *)password;

/// 设备出厂密码
- (NSString *)resetPasswordByDeviceUID:(nonnull NSString *)deviceUID;

@end

NS_ASSUME_NONNULL_END
