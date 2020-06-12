//
//  SDCardController.m
//  IvySdk
//
//  Created by JackChan on 27/6/2019.
//  Copyright © 2019 JackChan. All rights reserved.
//

#import "SDCardController.h"
#import "Masonry.h"
#import "IvySDPlayer.h"

@interface SDCardController () <IvySDPlayerDelegate>

@property (nonatomic, strong) IvyCamera *ivyCamera;

@property (nonatomic, strong) UIImageView *imageView;

@property (nonatomic, strong) IvySDPlayer *player;

@property (nonatomic, strong) NSArray *records;

@end

@implementation SDCardController

- (instancetype)initWithIvyCamera:(IvyCamera *)ivyCamera {
    if (self = [super initWithNibName:nil bundle:nil]) {
        _ivyCamera = ivyCamera;
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.view.backgroundColor = [UIColor whiteColor];
    self.edgesForExtendedLayout = UIRectEdgeBottom;
    
    [self.view addSubview:self.imageView];
    
    [self layoutPageSubviews];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    [UIApplication sharedApplication].idleTimerDisabled = YES;
    
    __weak typeof(self) weakSelf = self;
    [self.ivyCamera loginCamera:^(IVYIO_HANDLE_STATE handleState, IVYIO_RESULT cmdResult) {
        if (IVYIO_RESULT_OK == cmdResult) {
            [weakSelf getRecordList];
        } else {
            NSLog(@"... 设备不在线");
        }
    }];
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    
    [self.player stop];
}

- (void)layoutPageSubviews {
    [self.imageView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.left.right.equalTo(self.view);
        make.height.equalTo(self.view.mas_width).multipliedBy(9 / 16.f);
    }];
}

#pragma mark - Private Methods
- (void)getRecordList {
    NSInteger year = 2019;
    NSInteger month = 7;
    NSInteger day = 2;
    NSInteger recordType = 2;
    
    NSDateComponents *components = [[NSDateComponents alloc] init];
    
    components.year = year;
    components.month = month;
    components.day = day;
    components.minute = 0;
    components.second = 0;
    
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSDate *date = [calendar dateFromComponents:components];
    
    NSUInteger st = (unsigned int)[date timeIntervalSince1970];
    NSUInteger et = st + 24 * 3600 - 1;
    
    __weak typeof(self) weakSelf = self;
    [self.ivyCamera getSDCardRecordList:st endTime:et recordType:recordType onCompletion:^(id  _Nullable obj, IVYIO_RESULT cmdResult) {
        if (IVYIO_RESULT_OK == cmdResult) {
            NSArray *records = (NSArray *)obj;
            NSLog(@"%@ %@ %@", @([records count]), records.firstObject, records.lastObject);
            
            weakSelf.records = records;
            [weakSelf playBack];
        } else {
            NSLog(@"... Error");
        }
    }];
}

- (void)playBack {
    NSString *filename = self.records.lastObject;
    if (nil == filename) {
        NSLog(@"... 无录像");
        return;
    }
    
    [self.player playBack:self.ivyCamera filename:filename decodeType:IvyVideoDecodeUIImage];
    self.player.validAudio = YES;
}

#pragma mark - IvySDPlayerDelegate
- (void)ivySDPlayer:(IvySDPlayer *)player didReciveFrame:(UIImage *)image isFirstFrame:(BOOL)isFirstFrame {
    self.imageView.image = image;
    if (isFirstFrame) {
        
    }
}

- (void)ivySDPlayer:(IvySDPlayer *)player playerCommand:(IvyPlayerCommand)command result:(IVYIO_RESULT)result {
    NSLog(@"... command:%@ result:%@", @(command), @(result));
}

- (void)ivySDPlayer:(IvySDPlayer *)player totalTime:(NSTimeInterval)totalTime timePosition:(NSTimeInterval)timePosition {
    if (fabs(totalTime - timePosition) < 0.01) {
        self.imageView.image = nil;
        NSLog(@"... 播放完成");
    }
}

- (void)ivySDPlayer:(IvySDPlayer *)player mediaTransmitSpeed:(NSUInteger)transmitSpeed {
    NSString *text = nil;
    CGFloat mb = transmitSpeed / (1024.f * 1024.f);
    if (mb > 1) {
        text = [NSString stringWithFormat:@"%4.1fMB", mb];
    } else {
        CGFloat kb = transmitSpeed / 1024.f;
        text = [NSString stringWithFormat:@"%4.1fKB",kb];
    }
    
    NSLog(@"... transmitSpeed:%@", text);
}

#pragma mark - Getter && Setter
- (UIImageView *)imageView {
    if (!_imageView) {
        _imageView = [UIImageView new];
        _imageView.backgroundColor = [UIColor colorWithWhite:0 alpha:0.1];
    }
    return _imageView;
}

- (IvySDPlayer *)player {
    if (!_player) {
        _player = [IvySDPlayer new];
        _player.delegate = self;
    }
    return _player;
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
