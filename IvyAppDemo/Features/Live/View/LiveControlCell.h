//
//  LiveControlCell.h
//  IvySdk
//
//  Created by JackChan on 26/6/2019.
//  Copyright © 2019 JackChan. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class LiveControlCell;

@protocol LiveControlCellDelegate <NSObject>

- (void)liveControlCell:(LiveControlCell *)cell didTapAtIndexPath:(NSIndexPath *)indexPath;

@end

@interface LiveControlCell : UICollectionViewCell

@property (nonatomic, weak) id<LiveControlCellDelegate> delegate;

@property (nonatomic, strong) NSIndexPath *indexPath;

@property (nonatomic, strong) NSString *title;

@end

NS_ASSUME_NONNULL_END
