//
//  LiveControl.m
//  IvySdk
//
//  Created by JackChan on 25/6/2019.
//  Copyright © 2019 JackChan. All rights reserved.
//

#import "LiveControl.h"
#import "LiveControlCell.h"
#import "Masonry.h"

static NSString * const kCellID = @"CellID";
static NSInteger const kItemsInLine = 4;
static CGFloat const kSpacing = 4.f;

@interface LiveControl () <UICollectionViewDelegateFlowLayout, UICollectionViewDataSource, LiveControlCellDelegate>

@property (nonatomic, strong) UICollectionViewFlowLayout *flowLayout;

@property (nonatomic, strong) UICollectionView *collectionView;

@property (nonatomic, strong) NSArray<LiveControlModel *> *dataSource;

@end

@implementation LiveControl

- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        [self initializer];
    }
    return self;
}

- (void)initializer {
    self.collectionView.backgroundColor = [UIColor whiteColor];
    
    [self addSubview:self.collectionView];
    
    UIEdgeInsets padding = UIEdgeInsetsMake(10, 10, 0, 10);
    [self.collectionView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.edges.insets(padding);
    }];
}

#pragma mark - UICollectionViewDataSource
- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section {
    return self.dataSource.count;
}

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath {
    UICollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:kCellID forIndexPath:indexPath];
    return cell;
}

#pragma mark - UICollectionViewDelegateFlowLayout
- (void)collectionView:(UICollectionView *)collectionView willDisplayCell:(UICollectionViewCell *)cell forItemAtIndexPath:(NSIndexPath *)indexPath {
    
    LiveControlModel *model = self.dataSource[indexPath.row];
    
    LiveControlCell *thisCell = (LiveControlCell *)cell;
    thisCell.delegate = self;
    thisCell.indexPath = indexPath;
    thisCell.title = model.title;
}

- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath {
    [collectionView deselectItemAtIndexPath:indexPath animated:YES];
    
    [collectionView reloadData];
}

- (CGSize)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout sizeForItemAtIndexPath:(NSIndexPath *)indexPath {
    CGFloat itemWidth = (CGRectGetWidth(collectionView.frame) - (kItemsInLine + 1) * kSpacing - 20) / kItemsInLine;
    CGSize itemSize = CGSizeMake(itemWidth, itemWidth * 0.618);
    return itemSize;
}

#pragma mark - LiveControlCellDelegate
- (void)liveControlCell:(LiveControlCell *)cell didTapAtIndexPath:(NSIndexPath *)indexPath {
    LiveControlModel *model = self.dataSource[indexPath.row];

    if ([_delegate respondsToSelector:@selector(liveControl:didTapItemTag:)]) {
        [_delegate liveControl:self didTapItemTag:model.tag];
    }
}

#pragma mark - Getter && Setter
- (UICollectionViewFlowLayout *)flowLayout {
    if (!_flowLayout) {
        _flowLayout = [UICollectionViewFlowLayout new];
        _flowLayout.scrollDirection = UICollectionViewScrollDirectionVertical;
        _flowLayout.minimumLineSpacing = kSpacing * 4;
        _flowLayout.minimumInteritemSpacing = kSpacing;
    }
    return _flowLayout;
}

- (UICollectionView *)collectionView {
    if (!_collectionView) {
        _collectionView = [[UICollectionView alloc] initWithFrame:CGRectZero collectionViewLayout:self.flowLayout];
        _collectionView.dataSource = self;
        _collectionView.delegate = self;
        [_collectionView registerClass:[LiveControlCell class] forCellWithReuseIdentifier:kCellID];
    }
    return _collectionView;
}

- (NSArray *)dataSource {
    if (!_dataSource) {
        NSMutableArray *mutableArray = [NSMutableArray new];
        
        {
            LiveControlModel *model = [[LiveControlModel alloc] initWithTitle:@"OpenAudio" tag:LiveControlOpenAudio];
            [mutableArray addObject:model];
        }
        
        {
            LiveControlModel *model = [[LiveControlModel alloc] initWithTitle:@"CloseAudio" tag:LiveControlCloseAudio];
            [mutableArray addObject:model];
        }
        
        {
            LiveControlModel *model = [[LiveControlModel alloc] initWithTitle:@"StartTalk" tag:LiveControlStartTalk];
            [mutableArray addObject:model];
        }
        
        {
            LiveControlModel *model = [[LiveControlModel alloc] initWithTitle:@"EndTalk" tag:LiveControlEndTalk];
            [mutableArray addObject:model];
        }
        
        {
            LiveControlModel *model = [[LiveControlModel alloc] initWithTitle:@"StartRecord" tag:LiveControlStartRecord];
            [mutableArray addObject:model];
        }
        
        {
            LiveControlModel *model = [[LiveControlModel alloc] initWithTitle:@"StopRecord" tag:LiveControlStopRecord];
            [mutableArray addObject:model];
        }
        
        {
            LiveControlModel *model = [[LiveControlModel alloc] initWithTitle:@"Capture" tag:LiveControlCapture];
            [mutableArray addObject:model];
        }
        
        {
            LiveControlModel *model = [[LiveControlModel alloc] initWithTitle:@"Flip" tag:LiveControlFlip];
            [mutableArray addObject:model];
        }
        
        {
            LiveControlModel *model = [[LiveControlModel alloc] initWithTitle:@"Mirror" tag:LiveControlMirror];
            [mutableArray addObject:model];
        }
        
        {
            LiveControlModel *model = [[LiveControlModel alloc] initWithTitle:@"PTZUp" tag:LiveControlPTZUp];
            [mutableArray addObject:model];
        }
        
        {
            LiveControlModel *model = [[LiveControlModel alloc] initWithTitle:@"PTZDown" tag:LiveControlPTZDown];
            [mutableArray addObject:model];
        }
        
        {
            LiveControlModel *model = [[LiveControlModel alloc] initWithTitle:@"ZoomIn" tag:LiveControlZoomIn];
            [mutableArray addObject:model];
        }
        
        {
            LiveControlModel *model = [[LiveControlModel alloc] initWithTitle:@"ZoomOut" tag:LiveControlZoomOut];
            [mutableArray addObject:model];
        }
        
        {
            LiveControlModel *model = [[LiveControlModel alloc] initWithTitle:@"SyncTime" tag:LiveControlSyncTime];
            [mutableArray addObject:model];
        }
        
        {
            LiveControlModel *model = [[LiveControlModel alloc] initWithTitle:@"WiFiList" tag:LiveControlWiFiList];
            [mutableArray addObject:model];
        }
        
        {
            LiveControlModel *model = [[LiveControlModel alloc] initWithTitle:@"SetWiFi" tag:LiveControlSetWiFi];
            [mutableArray addObject:model];
        }
        
        {
            LiveControlModel *model = [[LiveControlModel alloc] initWithTitle:@"Modify" tag:LiveControlModify];
            [mutableArray addObject:model];
        }
        
        {
            LiveControlModel *model = [[LiveControlModel alloc] initWithTitle:@"SDCard" tag:LiveControlSDCard];
            [mutableArray addObject:model];
        }
        
        {
            LiveControlModel *model = [[LiveControlModel alloc] initWithTitle:@"GetOSD" tag:LiveControlGetOSD];
            [mutableArray addObject:model];
        }
        
        {
            LiveControlModel *model = [[LiveControlModel alloc] initWithTitle:@"SetOSD" tag:LiveControlSetOSD];
            [mutableArray addObject:model];
        }
        
        {
            LiveControlModel *model = [[LiveControlModel alloc] initWithTitle:@"Motion Alarm" tag:LiveControlMotionDetection];
            [mutableArray addObject:model];
        }
        
        {
            LiveControlModel *model = [[LiveControlModel alloc] initWithTitle:@"Audio Alarm" tag:LiveControlAudioDetection];
            [mutableArray addObject:model];
        }
        
        {
            LiveControlModel *model = [[LiveControlModel alloc] initWithTitle:@"SSID" tag:LiveControlSSID];
            [mutableArray addObject:model];
        }
        
        {
            LiveControlModel *model = [[LiveControlModel alloc] initWithTitle:@"Volume" tag:LiveControlAudioVolume];
            [mutableArray addObject:model];
        }
        
        {
            LiveControlModel *model = [[LiveControlModel alloc] initWithTitle:@"Stream Type" tag:LiveControlStreamType];
            [mutableArray addObject:model];
        }
        
        {
            LiveControlModel *model = [[LiveControlModel alloc] initWithTitle:@"Preset List" tag:LiveControlPresetPointList];
            [mutableArray addObject:model];
        }
        
        {
            LiveControlModel *model = [[LiveControlModel alloc] initWithTitle:@"Goto Preset" tag:LiveControlGoToPresetPoint];
            [mutableArray addObject:model];
        }
        
        {
            LiveControlModel *model = [[LiveControlModel alloc] initWithTitle:@"Add Preset" tag:LiveControlAddPresetPoint];
            [mutableArray addObject:model];
        }
        
        {
            LiveControlModel *model = [[LiveControlModel alloc] initWithTitle:@"Delete Preset" tag:LiveControlDelPresetPoint];
            [mutableArray addObject:model];
        }
        
        {
            LiveControlModel *model = [[LiveControlModel alloc] initWithTitle:@"Start Cruise" tag:LiveControlStartCruise];
            [mutableArray addObject:model];
        }
        
        {
            LiveControlModel *model = [[LiveControlModel alloc] initWithTitle:@"Stop Cruise" tag:LiveControlStopCruise];
            [mutableArray addObject:model];
        }
        
        {
            LiveControlModel *model = [[LiveControlModel alloc] initWithTitle:@"Upgrade" tag:LiveControlOnlineUpgrade];
            [mutableArray addObject:model];
        }
        
        {
            LiveControlModel *model = [[LiveControlModel alloc] initWithTitle:@"Storage" tag:LiveControlStorage];
            [mutableArray addObject:model];
        }
        
        {
            LiveControlModel *model = [[LiveControlModel alloc] initWithTitle:@"Push" tag:LiveControlPush];
            [mutableArray addObject:model];
        }
        
        {
            LiveControlModel *model = [[LiveControlModel alloc] initWithTitle:@"License" tag:LiveControlPedestrianLicense];
            [mutableArray addObject:model];
        }
        
        {
            LiveControlModel *model = [[LiveControlModel alloc] initWithTitle:@"Pedestrian" tag:LiveControlPedestrian];
            [mutableArray addObject:model];
        }
        
        _dataSource = [mutableArray copy];
    }
    return _dataSource;
}

@end
