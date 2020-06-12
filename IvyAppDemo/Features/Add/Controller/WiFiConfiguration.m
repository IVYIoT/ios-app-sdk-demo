//
//  WiFiConfiguration.m
//  IvyAppDemo
//
//  Created by JackChan on 8/1/2020.
//  Copyright © 2020 JackChan. All rights reserved.
//
#import "WiFiConfiguration.h"
#import "IvySdkManager.h"
#import "IvyVoicePlayer.h"
#import "UIImage+IvySdk.h"
#import "Constants.h"
#import "Masonry.h"

static NSString * const kCellID = @"CellID";

@interface WiFiConfiguration () <IvyVoicePlayerDelegate, UITableViewDataSource, UITableViewDelegate>

@property (nonatomic, strong) IvyVoicePlayer *voicePlayer;

@property (nonatomic, strong) UIButton *voiceButton;

@property (nonatomic, strong) UITableView *tableView;

@property (nonatomic, strong) NSArray<IvyDevLan *> *dataSoucre;

@property (nonatomic, strong) NSTimer *timer;

@end

@implementation WiFiConfiguration

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.title = @"WiFi Configuration";
    self.view.backgroundColor = [UIColor whiteColor];
    
    [self.view addSubview:self.voiceButton];
    [self.view addSubview:self.tableView];
    
    [self.voiceButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.offset(100);
        make.centerX.equalTo(self.view);
        make.size.mas_equalTo(CGSizeMake(90, 90));
    }];
    
    [self.tableView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.offset(200);
        make.left.bottom.right.equalTo(self.view);
    }];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    [self startTimer];
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    
    [self stopTimer];
    
    if (_voicePlayer) {
        [_voicePlayer stop];
    }
}

#pragma mark - Private Methods
- (void)startTimer {
    if (_timer) {
        [_timer invalidate];
        _timer = nil;
    }
    _timer = [NSTimer scheduledTimerWithTimeInterval:0.25 target:self selector:@selector(handleTimer) userInfo:nil repeats:YES];
}

- (void)stopTimer {
    if (_timer) {
        [_timer invalidate];
        _timer = nil;
    }
}

#pragma mark - UITableViewDataSource
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return [self.dataSoucre count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:kCellID];
    return cell;
}

#pragma mark - UITableViewDelegate
- (void)tableView:(UITableView *)tableView willDisplayCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath {
    IvyDevLan *model = self.dataSoucre[indexPath.row];
    
    cell.textLabel.text = model.uid;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    
    IvyDevLan *model = self.dataSoucre[indexPath.row];
    NSLog(@"... deviceUID:%@", model.uid);
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return 64.f;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
    return @"Device In Lan";
}

#pragma mark - IvyVoicePlayerDelegate
- (void)ivyVoicePlayerDidFinishPlaying:(IvyVoicePlayer *)player successfully:(BOOL)flag {
    self.voiceButton.enabled = YES;
    NSLog(@"... did Finish Playing flag:%@", @(flag));
}

- (void)ivyVoicePlayerDecodeErrorDidOccur:(IvyVoicePlayer *)player error:(NSError * __nullable)error {
    self.voiceButton.enabled = YES;
    NSLog(@"... decodeErrorDidOccur:%@", error);
}

#pragma mark - Event Response
- (void)voiceButtonTapped:(UIButton *)sender {
    sender.enabled = NO;
    
    NSString *SSID = kDeviceUID;
    NSString *password = kWiFiPassword;
    NSString *deviceUID = kDeviceUID;
    
    IvyDeviceType type = IvyDeviceFOS;
    _voicePlayer = [[IvyVoicePlayer alloc] initWithSSID:SSID password:password deviceUID:deviceUID type:type];
    _voicePlayer.delegate = self;
    
    [_voicePlayer play];
}

- (void)handleTimer {
    [[IvySdkManager shared] searchDevices:^(NSArray<IvyDevLan *> * _Nonnull devices) {
        self.dataSoucre = [devices copy];
        [self.tableView reloadData];
    }];
}

#pragma mark - Getter && Setter
- (UIButton *)voiceButton {
    if (!_voiceButton) {
        _voiceButton = [UIButton buttonWithType:UIButtonTypeCustom];
        _voiceButton.layer.cornerRadius = 8;
        _voiceButton.layer.masksToBounds = YES;
        _voiceButton.titleLabel.font = [UIFont systemFontOfSize:12];
        [_voiceButton setTitle:@"Send Voice" forState:UIControlStateNormal];
        [_voiceButton setTitleColor:RGBCOLOR(81, 91, 88) forState:UIControlStateNormal];
        [_voiceButton setBackgroundImage:[UIImage imageWithColor:RGBCOLOR(242, 242, 243)] forState:UIControlStateNormal];
        [_voiceButton setBackgroundImage:[UIImage imageWithColor:RGBCOLOR(232, 232, 233)] forState:UIControlStateSelected];
        [_voiceButton setBackgroundImage:[UIImage imageWithColor:RGBCOLOR(232, 180, 180)] forState:UIControlStateHighlighted];
        [_voiceButton setBackgroundImage:[UIImage imageWithColor:RGBCOLOR(202, 202, 206)] forState:UIControlStateDisabled];
        [_voiceButton addTarget:self action:@selector(voiceButtonTapped:) forControlEvents:UIControlEventTouchUpInside];
    }
    return _voiceButton;
}

- (UITableView *)tableView {
    if (!_tableView) {
        _tableView = [[UITableView alloc] initWithFrame:CGRectZero style:UITableViewStyleGrouped];
        _tableView.backgroundColor = [UIColor clearColor];
        _tableView.dataSource = self;
        _tableView.delegate = self;
        _tableView.estimatedRowHeight = 0;
        _tableView.estimatedSectionHeaderHeight = 0;
        _tableView.estimatedSectionFooterHeight = 0;
        [_tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:kCellID];
    }
    return _tableView;
}


- (void)dealloc {
    NSLog(@"... %@ dealloc", NSStringFromClass([self class]));
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
