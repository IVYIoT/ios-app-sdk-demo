//
//  LiveController.m
//  IvySdk
//
//  Created by JackChan on 25/6/2019.
//  Copyright © 2019 JackChan. All rights reserved.
//

#import "LiveController.h"
#import "Masonry.h"
#import "IvyPlayer.h"
#import "LiveControl.h"
#import "SDCardController.h"

static int const kTimeout = 30000;

@interface LiveController () <IvyPlayerDelegate, LiveControlDelegate>

@property (nonatomic, strong) IvyCamera *ivyCamera;

@property (nonatomic, strong) UIImageView *imageView;

@property (nonatomic, strong) IvyPlayer *ivyPlayer;

@property (nonatomic, strong) LiveControl *liveControl;

@property (nonatomic, assign) BOOL isPreload;

@end

@implementation LiveController

- (instancetype)initWithIvyCamera:(IvyCamera *)ivyCamera {
    if (self = [super initWithNibName:nil bundle:nil]) {
        _ivyCamera = ivyCamera;
        _isPreload = YES;
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.title = @"Live";
    self.view.backgroundColor = [UIColor whiteColor];
    self.edgesForExtendedLayout = UIRectEdgeBottom;
    
    [self.view addSubview:self.imageView];
    [self.view addSubview:self.liveControl];
    
    [self layoutPageSubviews];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    [UIApplication sharedApplication].idleTimerDisabled = YES;
    
    if (_isPreload) { [self play]; }
    
    [self.ivyCamera addEventObserver:self selector:@selector(handleEvent:)];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(didEnterBackgroundNotification:) name:UIApplicationDidEnterBackgroundNotification object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(willEnterForegroundNotification:) name:UIApplicationWillEnterForegroundNotification object:nil];
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    
    [self.ivyCamera removeEventObserver:self];
    
    [self.ivyPlayer stop];
    
    _isPreload = YES;
    
    [UIApplication sharedApplication].idleTimerDisabled = NO;
    [[NSNotificationCenter defaultCenter] removeObserver:self name:UIApplicationDidEnterBackgroundNotification object:nil];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:UIApplicationWillEnterForegroundNotification object:nil];
}

- (void)layoutPageSubviews {
    [self.imageView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.left.right.equalTo(self.view);
        make.height.equalTo(self.view.mas_width).multipliedBy(9 / 16.f);
    }];
    
    [self.liveControl mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(self.imageView.mas_bottom);
        make.left.right.equalTo(self.view);
        make.bottom.offset(-44);
    }];
}

#pragma mark - Public Methods
- (void)preload {
    if (_isPreload) {
        _isPreload = NO;
    }
    
    [self play];
}

#pragma mark - Private Methods
- (void)play {
    __weak typeof(self) weakSelf = self;
    [self.ivyCamera loginCamera:^(IVYIO_HANDLE_STATE handleState, IVYIO_RESULT cmdResult) {
        if (IVYIO_RESULT_OK == cmdResult) {
            [weakSelf.ivyPlayer playLive:self.ivyCamera decodeType:IvyVideoDecodeUIImage];
        } else {
            NSLog(@"... 设备不在线");
        }
    }];
}

#pragma mark - Event Response
- (void)handleEvent:(NSDictionary *)eventDict {
    NSInteger eventId = [eventDict[@"eventId"] integerValue];
    
    switch (eventId) {
        case IVY_CTRL_MSG_DAY_NIGHT_MODE_CHG: {
            
        }
            break;
            
        case IVY_CTRL_MSG_MIRROR_FLIP_CHG: {
            
        }
            break;
            
        default:
            break;
    }
}

- (void)didEnterBackgroundNotification:(NSNotification *)not {
    [self.ivyPlayer stop];
}

- (void)willEnterForegroundNotification:(NSNotification *)not {
    [self play];
}

#pragma mark - IvyPlayerDelegate
- (void)ivyPlayer:(IvyPlayer *)ivyPlayer didReciveFrame:(UIImage *)image isFirstFrame:(BOOL)isFirstFrame {
    self.imageView.image = image;
    if (isFirstFrame) {
        
    }
}

- (void)ivyPlayer:(IvyPlayer *)ivyPlayer didReciveIVYFrame:(IVYIO_FRAME *)frame isFirstFrame:(BOOL)isFirstFrame {
    NSLog(@"... isKey:%@ len:%@", @(frame->iKey), @(frame->len));
}

- (void)ivyPlayer:(IvyPlayer *)ivyPlayer playerCommand:(IvyPlayerCommand)command result:(IVYIO_RESULT)result {
    NSLog(@"... command:%@ result:%@", @(command), @(result));
}

- (void)ivyPlayer:(IvyPlayer *)ivyPlayer mediaTransmitSpeed:(NSUInteger)transmitSpeed {
    NSString *text = nil;
    CGFloat mb = transmitSpeed / (1024.f * 1024.f);
    if (mb > 1) {
        text = [NSString stringWithFormat:@"%4.1fMB", mb];
    } else {
        CGFloat kb = transmitSpeed / 1024.f;
        text = [NSString stringWithFormat:@"%4.1fKB",kb];
    }
    
//    NSLog(@"... transmitSpeed:%@", text);
}

#pragma mark - LiveControlDelegate
- (void)liveControl:(LiveControl *)liveControl didTapItemTag:(LiveControlTag)tag {
    switch (tag) {
        case LiveControlOpenAudio: {
            self.ivyPlayer.validAudio = YES;
        }
            break;
            
        case LiveControlCloseAudio: {
            self.ivyPlayer.validAudio = NO;
        }
            break;
            
        case LiveControlStartTalk: {
            [self.ivyPlayer startTalk];
        }
            break;
            
        case LiveControlEndTalk: {
            [self.ivyPlayer endTalk];
        }
            break;
            
        case LiveControlStartRecord: {
            NSString *filepath = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES).firstObject stringByAppendingPathComponent:@"record.mp4"];
            [self.ivyCamera startRecord:filepath onCompletion:^(id  _Nullable obj, IVYIO_RESULT cmdResult) {
                NSLog(@"... startRecord cmdResult:%@", @(cmdResult));
            }];
        }
            break;
            
        case LiveControlStopRecord: {
            [self.ivyCamera stopRecord:^(id  _Nullable obj, IVYIO_RESULT cmdResult) {
                NSLog(@"... stopRecord cmdResult:%@", @(cmdResult));
            }];
        }
            break;
            
        case LiveControlCapture: {
            UIImage *image = self.imageView.image;
            NSData *data = UIImageJPEGRepresentation(image, 1);
            NSLog(@"... image size:%@", @(data.length));
        }
            break;
            
        case LiveControlFlip: {
            static BOOL flag = NO;
            flag = !flag;
            [self.ivyCamera setFlipVideo:flag onCompletion:^(id  _Nullable obj, IVYIO_RESULT cmdResult) {}];
        }
            break;
            
        case LiveControlMirror: {
            static BOOL flag = NO;
            flag = !flag;
            [self.ivyCamera setMirrorVideo:flag onCompletion:^(id  _Nullable obj, IVYIO_RESULT cmdResult) {}];
        }
            break;
            
        case LiveControlPTZUp: {
            IVY_PTZ_CMD ptzCmd = IVY_PTZ_MOVE_UP;
            [self.ivyCamera setPTZCmd:ptzCmd onCompletion:^(id  _Nullable obj, IVYIO_RESULT cmdResult) {}];
            
            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                [self.ivyCamera setPTZCmd:IVY_PTZ_STOP onCompletion:^(id  _Nullable obj, IVYIO_RESULT cmdResult) {}];
            });
        }
            break;
            
        case LiveControlPTZDown: {
            IVY_PTZ_CMD ptzCmd = IVY_PTZ_MOVE_DOWN;
            [self.ivyCamera setPTZCmd:ptzCmd onCompletion:^(id  _Nullable obj, IVYIO_RESULT cmdResult) {}];
            
            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                [self.ivyCamera setPTZCmd:IVY_PTZ_STOP onCompletion:^(id  _Nullable obj, IVYIO_RESULT cmdResult) {}];
            });
        }
            break;
            
        case LiveControlZoomIn: {
            IVY_PTZ_CMD ptzCmd = IVY_PTZ_ZOOM_IN;
            [self.ivyCamera setPTZCmd:ptzCmd onCompletion:^(id  _Nullable obj, IVYIO_RESULT cmdResult) {}];
            
            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                [self.ivyCamera setPTZCmd:IVY_PTZ_STOP onCompletion:^(id  _Nullable obj, IVYIO_RESULT cmdResult) {}];
            });
        }
            break;
            
        case LiveControlZoomOut: {
            IVY_PTZ_CMD ptzCmd = IVY_PTZ_ZOOM_OUT;
            [self.ivyCamera setPTZCmd:ptzCmd onCompletion:^(id  _Nullable obj, IVYIO_RESULT cmdResult) {}];
            
            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                [self.ivyCamera setPTZCmd:IVY_PTZ_STOP onCompletion:^(id  _Nullable obj, IVYIO_RESULT cmdResult) {}];
            });
        }
            break;
            
        case LiveControlSyncTime: {
            [self.ivyCamera syncSystemTime:^(id  _Nullable obj, IVYIO_RESULT cmdResult) {
                NSLog(@"... syncSystemTime cmdResult:%@", @(cmdResult));
            }];
        }
            break;
            
        case LiveControlWiFiList: {
            [self.ivyCamera getWiFiList:^(id  _Nullable obj, IVYIO_RESULT cmdResult) {
                NSLog(@"... getWiFiList cmdResult:%@ obj:%@", @(cmdResult), obj);
            }];
        }
            break;
            
        case LiveControlSetWiFi: {
            
        }
            break;
            
        case LiveControlModify: {
            NSString *username = @"a";
            NSString *password = @"abc123";
            [self.ivyCamera modifyUserNameAndPassword:username newPassword:password onCompletion:^(id  _Nullable obj, IVYIO_RESULT cmdResult) {
                NSLog(@"... cmdResult:%@, obj:%@", @(cmdResult), obj);
            }];
        }
            break;
            
        case LiveControlSDCard: {
            SDCardController *vc = [[SDCardController alloc] initWithIvyCamera:self.ivyCamera];
            [self.navigationController pushViewController:vc animated:YES];
        }
            break;
            
        case LiveControlGetOSD: {
            [self.ivyCamera sendCommand:IVY_CTRL_MSG_GET_OSD_PARAM parameters:@{} iTimeout:kTimeout onCompletion:^(id  _Nullable obj, IVYIO_RESULT cmdResult) {
                NSLog(@"... cmdResult:%@, obj:%@", @(cmdResult), obj);
            }];
        }
            break;
            
        case LiveControlSetOSD: {
            NSInteger osdType = 0b001;
            NSDictionary *parameters = @{@"dispPos" : @(0),
                                         @"osdType" : @(osdType)};
            [self.ivyCamera sendCommand:IVY_CTRL_MSG_SET_OSD_PARAM parameters:parameters iTimeout:kTimeout onCompletion:^(id  _Nullable obj, IVYIO_RESULT cmdResult) {
                NSLog(@"... cmdResult:%@, obj:%@", @(cmdResult), obj);
            }];
        }
            break;
            
        case LiveControlMotionDetection: {
            [self.ivyCamera getMotionDetectConfig:^(IvyMotionDetect * _Nonnull config, IVYIO_RESULT cmdResult) {
                config.isEnable = !config.isEnable;
                
                [self.ivyCamera setMotionDetectConfig:config onCompletion:^(id  _Nullable obj, IVYIO_RESULT cmdResult) {
                    NSLog(@"... cmdResult:%@, obj:%@", @(cmdResult), obj);
                }];
            }];
        }
            break;
            
        case LiveControlAudioDetection: {
            [self.ivyCamera getAudioDetectConfig:^(IvyAudioDetect * _Nonnull config, IVYIO_RESULT cmdResult) {
                config.isEnable = !config.isEnable;
                
                [self.ivyCamera setAudioDetectConfig:config onCompletion:^(id  _Nullable obj, IVYIO_RESULT cmdResult) {
                    NSLog(@"... cmdResult:%@, obj:%@", @(cmdResult), obj);
                }];
            }];
        }
            break;
          
        case LiveControlSSID: {
            [self.ivyCamera getWiFiConfig:^(IvyWiFiConfig * _Nonnull config, IVYIO_RESULT cmdResult) {
                NSLog(@"... cmdResult:%@, obj:%@", @(cmdResult), config.ssid);
            }];
        }
            break;
            
        case LiveControlAudioVolume: {
            [self.ivyCamera getAudioVolume:^(NSInteger volume, IVYIO_RESULT cmdResult) {
                NSLog(@"... cmdResult:%@, volume:%@", @(cmdResult), @(volume));
                
                [self.ivyCamera setAudioVolume:80 onCompletion:^(id  _Nullable obj, IVYIO_RESULT cmdResult) {
                    NSLog(@"... cmdResult:%@, obj:%@", @(cmdResult), obj);
                }];
            }];
        }
            break;
            
        case LiveControlStreamType: {
            [self.ivyCamera getSupportedStreamTypes:^(NSArray * _Nonnull types, IVYIO_RESULT cmdResult) {
                NSLog(@"... cmdResult:%@, types:%@", @(cmdResult), types);
            }];
            
            [self.ivyCamera getStreamType:^(IvyDefinitionType streamType, IVYIO_RESULT cmdResult) {
                NSLog(@"... cmdResult:%@, streamType:%@", @(cmdResult), @(streamType));
            }];
            
            IvyDefinitionType type = IvyDefinitionHD;
            [self.ivyCamera setStreamType:type onCompletion:^(id  _Nullable obj, IVYIO_RESULT cmdResult) {
                NSLog(@"... cmdResult:%@, obj:%@", @(cmdResult), obj);
            }];
        }
            break;
            
        case LiveControlPresetPointList: {
            [self.ivyCamera getPresetPointList:^(IvyPresetPoint * _Nonnull presetPoint, IVYIO_RESULT cmdResult) {
                NSLog(@"... cmdResult:%@, obj:%@", @(cmdResult), presetPoint.pointNames);
            }];
        }
            break;
            
        case LiveControlGoToPresetPoint: {
            NSString *pointName = @"room";
            [self.ivyCamera goToPresetPoint:pointName onCompletion:^(id  _Nullable obj, IVYIO_RESULT cmdResult) {
                NSLog(@"... cmdResult:%@, obj:%@", @(cmdResult), obj);
            }];
        }
            break;
            
        case LiveControlAddPresetPoint: {
            NSString *pointName = @"room";
            [self.ivyCamera addPresetPoint:pointName onCompletion:^(id  _Nullable obj, IVYIO_RESULT cmdResult) {
                NSLog(@"... cmdResult:%@, obj:%@", @(cmdResult), obj);
            }];
        }
            break;
            
        case LiveControlDelPresetPoint: {
            NSString *pointName = @"room";
            [self.ivyCamera deletePresetPoint:pointName onCompletion:^(IvyPresetPoint * _Nonnull presetPoint, IVYIO_RESULT cmdResult) {
                NSLog(@"... cmdResult:%@, obj:%@", @(cmdResult), presetPoint.pointNames);
            }];
        }
            break;
            
        case LiveControlStartCruise: {
            [self.ivyCamera startPresetPointCruise:^(id  _Nullable obj, IVYIO_RESULT cmdResult) {
                NSLog(@"... cmdResult:%@, obj:%@", @(cmdResult), obj);
            }];
        }
            break;
            
        case LiveControlStopCruise: {
            [self.ivyCamera stopCruise:^(id  _Nullable obj, IVYIO_RESULT cmdResult) {
                NSLog(@"... cmdResult:%@, obj:%@", @(cmdResult), obj);
            }];
        }
            break;
            
        case LiveControlOnlineUpgrade: {
            NSString *URLString = @"http://test-download.myfoscam.com:9001/firmware/test/anba_F_app_ver2.x.1.77_0821--1569550740170.bin";
            [self.ivyCamera setOnlineUpgrade:URLString onCompletion:^(id  _Nullable obj, IVYIO_RESULT cmdResult) {
                NSLog(@"... cmdResult:%@, obj:%@", @(cmdResult), obj);
            }];
        }
            break;
            
        case LiveControlStorage: {
            NSString *portal = @"https://test-api.myfoscam.com:443";
            NSString *deviceMac = @"00000000232A";
            NSString *streamId = @"1a8d226eca789c189403c112b6c1acb5104256400000000232A";
            NSString *userTag = @"d85280b8e9e146679197c2dca2f54531";
            
            [self.ivyCamera setCloudStorageConfig:portal deviceMac:deviceMac streamId:streamId userTag:userTag onCompletion:^(id  _Nullable obj, IVYIO_RESULT cmdResult) {
                NSLog(@"... cmdResult:%@, obj:%@", @(cmdResult), obj);
            }];
        }
            break;
            
        case LiveControlPush: {
            NSString *portal = @"https://test-api.myfoscam.com";
            NSString *userTag = @"a44ad70c97f84d21b763412119f3397e";
            
            [self.ivyCamera setRichMediaPushConfig:portal userTag:userTag onCompletion:^(id  _Nullable obj, IVYIO_RESULT cmdResult) {
                NSLog(@"... cmdResult:%@, obj:%@", @(cmdResult), obj);
            }];
        }
            break;
            
        case LiveControlPedestrianLicense: {
            [self.ivyCamera getPedestrianLicenseDeviceInfo:^(NSString * _Nonnull info, IVYIO_RESULT cmdResult) {
                NSLog(@"... cmdResult:%@, obj:%@", @(cmdResult), info);
            }];
            
            NSString *license = @"bc7eb17155e92568a68e824ae4d6db8404f3d5f83c10acd3a81a055fdfdaee0b6241a508e0dad8ac9e0ae693862313b081210481727592dbb39b42feb5b205552343e1809445bbd7b842f44f2063254c73468a73d23da92519b036bbcb71b82a0af7b77079bacc80f008d2542b7e15e943374b37a3d4ede533d1a67ff90b8b59ab389f55826d83903402ac438ac4bbf72a89dc5a24c079f70ea90a0d0e95a11d6fe8e7ffbe1a0d4b7a985747daa7505826566b1cd48c0423d402ecb2bd2fc4d00384fb7ab89264bae8161e387d206ca0ace504fadcdd013a34dd4a15b0bcdf11539320c27fe8b05b09e33ab4aa86d598f875eae4b4d17452769d37f9e7e0c37f";
            
            [self.ivyCamera setPedestrianLicense:license onCompletion:^(id  _Nullable obj, IVYIO_RESULT cmdResult) {
                NSLog(@"... cmdResult:%@, obj:%@", @(cmdResult), obj);
            }];
        }
            break;
            
        case LiveControlPedestrian: {
            [self.ivyCamera getPedestrianDetectConfig:^(IvyPedestrianDetect * _Nonnull config, IVYIO_RESULT cmdResult) {
                NSLog(@"... cmdResult:%@, config:%@", @(cmdResult), config);
                config.isEnable = !config.isEnable;
                [self.ivyCamera setPedestrianDetectConfig:config onCompletion:^(id  _Nullable obj, IVYIO_RESULT cmdResult) {
                    NSLog(@"... cmdResult:%@, obj:%@", @(cmdResult), obj);
                }];
            }];
        }
            break;
            
        default: {
            NSAssert(NO, @"### Unkown tag");
        }
            break;
    }
}

#pragma mark - Getter && Setter
- (UIImageView *)imageView {
    if (!_imageView) {
        _imageView = [UIImageView new];
        _imageView.backgroundColor = [UIColor colorWithWhite:0 alpha:0.1];
    }
    return _imageView;
}

- (IvyPlayer *)ivyPlayer {
    if (!_ivyPlayer) {
        _ivyPlayer = [IvyPlayer new];
        _ivyPlayer.delegate = self;
    }
    return _ivyPlayer;
}

- (LiveControl *)liveControl {
    if (!_liveControl) {
        _liveControl = [LiveControl new];
        _liveControl.delegate = self;
    }
    return _liveControl;
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
