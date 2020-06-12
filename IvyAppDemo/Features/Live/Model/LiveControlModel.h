//
//  LiveControlModel.h
//  IvySdk
//
//  Created by JackChan on 26/6/2019.
//  Copyright © 2019 JackChan. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, LiveControlTag) {
    LiveControlOpenAudio,
    LiveControlCloseAudio,
    LiveControlStartTalk,
    LiveControlEndTalk,
    LiveControlStartRecord,
    LiveControlStopRecord,
    LiveControlCapture,
    LiveControlFlip,
    LiveControlMirror,
    LiveControlPTZUp,
    LiveControlPTZDown,
    LiveControlZoomIn,
    LiveControlZoomOut,
    LiveControlSyncTime,
    LiveControlWiFiList,
    LiveControlSetWiFi,
    LiveControlModify,
    LiveControlSDCard,
    LiveControlGetOSD,
    LiveControlSetOSD,
    LiveControlMotionDetection,
    LiveControlAudioDetection,
    LiveControlSSID,
    LiveControlAudioVolume,
    LiveControlStreamType,
    LiveControlPresetPointList,
    LiveControlGoToPresetPoint,
    LiveControlAddPresetPoint,
    LiveControlDelPresetPoint,
    LiveControlStartCruise,
    LiveControlStopCruise,
    LiveControlOnlineUpgrade,
    LiveControlStorage,
    LiveControlPush,
    LiveControlPedestrianLicense,
    LiveControlPedestrian,
};

@interface LiveControlModel : NSObject

- (instancetype)initWithTitle:(NSString *)title tag:(LiveControlTag)tag;

@property (nonatomic, strong) NSString *title;

@property (nonatomic, assign) LiveControlTag tag;

@end

NS_ASSUME_NONNULL_END
