//
//  IvyVoicePlayer.h
//  IvyAppDemo
//
//  Created by JackChan on 7/1/2020.
//  Copyright © 2020 JackChan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IvyConstants.h"

NS_ASSUME_NONNULL_BEGIN

@class IvyVoicePlayer;

@protocol IvyVoicePlayerDelegate <NSObject>

@optional
/// 声波配网结束
/// @param player 当前对象
/// @param flag 结果
- (void)ivyVoicePlayerDidFinishPlaying:(IvyVoicePlayer *)player successfully:(BOOL)flag;

/// 声波配网异常
/// @param player 当前对象
/// @param error 异常
- (void)ivyVoicePlayerDecodeErrorDidOccur:(IvyVoicePlayer *)player error:(NSError * __nullable)error;

@end



@interface IvyVoicePlayer : NSObject

/// 初始化方法
/// @param SSID Wi-Fi SSID
/// @param password Wi-Fi 密码
/// @param deviceUID 设备UID
/// @param type 设备类型
/// @return 对象
/// @note IvyDeviceFOS类型，须传入deviceUID，否则报错；IvyDeviceIVY类型可不传；
- (instancetype)initWithSSID:(nonnull NSString *)SSID password:(nonnull NSString *)password deviceUID:(nullable NSString *)deviceUID type:(IvyDeviceType)type;

/// 播放
- (void)play;

/// 停止播放
- (void)stop;

/// 代理
@property (nonatomic, weak) id<IvyVoicePlayerDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
