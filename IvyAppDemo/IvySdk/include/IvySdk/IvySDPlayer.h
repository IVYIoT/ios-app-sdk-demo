//
//  IvySDPlayer.h
//  IvySdk
//
//  Created by JackChan on 28/6/2019.
//  Copyright © 2019 ivyiot. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "IvyConstants.h"
#import "IvyCamera.h"

NS_ASSUME_NONNULL_BEGIN

@class IvySDPlayer;

@protocol IvySDPlayerDelegate <NSObject>

@optional

/// 解码到一帧图像
/// @param player 当前播放器
/// @param image 一帧图像
/// @param isFirstFrame 是否为第一帧数据
/// @note 播放使用IvyVideoDecodeUIImage类型时，帧数据通过该方法回掉。否则通过ivySDPlayer:didReciveIVYFrame:isFirstFrame回掉指定帧数据。
- (void)ivySDPlayer:(IvySDPlayer *)player didReciveFrame:(UIImage *)image isFirstFrame:(BOOL)isFirstFrame;

/// 解码到一帧图像
/// @param player 当前播放器
/// @param frame 指定帧数据
/// @param isFirstFrame 是否为第一帧数据
- (void)ivySDPlayer:(IvySDPlayer *)player didReciveIVYFrame:(IVYIO_FRAME *)frame isFirstFrame:(BOOL)isFirstFrame;

/// 执行命令结果
/// @param player 当前播放器
/// @param command 命令
/// @param result 结果
- (void)ivySDPlayer:(IvySDPlayer *)player playerCommand:(IvyPlayerCommand)command result:(IVYIO_RESULT)result;

/// 播放时间
/// @param player 当前播放器
/// @param totalTime 本段录像总时长
/// @param timePosition 当前播放位置
- (void)ivySDPlayer:(IvySDPlayer *)player totalTime:(NSTimeInterval)totalTime timePosition:(NSTimeInterval)timePosition;

/// 流量大小
/// @param player 当前播放器
/// @param transmitSpeed 流量大小(Kb)
- (void)ivySDPlayer:(IvySDPlayer *)player mediaTransmitSpeed:(NSUInteger)transmitSpeed;

@end

@interface IvySDPlayer : NSObject

/// SD卡回放
/// @param ivyCamera 设备对象
/// @param filename 文件名
/// @param decodeType 解码数据的类型
- (void)playBack:(IvyCamera *)ivyCamera filename:(NSString *)filename decodeType:(IvyVideoDecodeType)decodeType;

/// 暂停播放
- (void)pause;

/// 继续播放
- (void)resume;

/// 设置播放位置
/// @param pos 播放位置
- (void)seekToPosition:(NSTimeInterval)pos;

/// 停止播放
- (void)stop;

/// 音频开关
@property (nonatomic, assign) BOOL validAudio;

/// 代理
@property (nonatomic, weak) id<IvySDPlayerDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
