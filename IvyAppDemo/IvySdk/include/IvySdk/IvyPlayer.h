//
//  IvyPlayer.h
//  IvySdk
//
//  Created by JackChan on 11/6/2019.
//  Copyright © 2019 ivyiot. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "IvyCamera.h"
#import "IvyConstants.h"

NS_ASSUME_NONNULL_BEGIN

@class IvyPlayer;

@protocol IvyPlayerDelegate <NSObject>

@optional

/// 解码到一帧图像
/// @param ivyPlayer 当前播放器
/// @param image 一帧图像
/// @param isFirstFrame 是否为第一帧数据
/// @note 播放使用IvyVideoDecodeUIImage类型时，帧数据通过该方法回掉。否则通过ivyPlayer:didReciveIVYFrame:isFirstFrame回掉指定帧数据。
- (void)ivyPlayer:(IvyPlayer *)ivyPlayer didReciveFrame:(UIImage *)image isFirstFrame:(BOOL)isFirstFrame;

/// 解码到一帧图像
/// @param ivyPlayer 当前播放器
/// @param frame 指定帧数据
/// @param isFirstFrame 是否为第一帧数据
- (void)ivyPlayer:(IvyPlayer *)ivyPlayer didReciveIVYFrame:(IVYIO_FRAME *)frame isFirstFrame:(BOOL)isFirstFrame;

/// 执行命令结果
/// @param ivyPlayer 当前播放器
/// @param command 命令
/// @param result 结果
- (void)ivyPlayer:(IvyPlayer *)ivyPlayer playerCommand:(IvyPlayerCommand)command result:(IVYIO_RESULT)result;

/// 流量大小
/// @param ivyPlayer 当前播放器
/// @param transmitSpeed 流量大小(Kb)
- (void)ivyPlayer:(IvyPlayer *)ivyPlayer mediaTransmitSpeed:(NSUInteger)transmitSpeed;

@end

@interface IvyPlayer : NSObject

/// 直播
/// @param ivyCamera 设备
/// @param decodeType 解码数据的类型
- (void)playLive:(IvyCamera *)ivyCamera decodeType:(IvyVideoDecodeType)decodeType;

/// 停止播放
- (void)stop;

/// 打开对讲
- (void)startTalk;

/// 关闭对讲
- (void)endTalk;

/// 音频开关
@property (nonatomic, assign) BOOL validAudio;

/// 代理
@property (nonatomic, weak) id<IvyPlayerDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
