//
//  LiveControl.h
//  IvySdk
//
//  Created by JackChan on 25/6/2019.
//  Copyright © 2019 JackChan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LiveControlModel.h"
NS_ASSUME_NONNULL_BEGIN

@class LiveControl;

@protocol LiveControlDelegate <NSObject>

- (void)liveControl:(LiveControl *)liveControl didTapItemTag:(LiveControlTag)tag;

@end

@interface LiveControl : UIView

@property (nonatomic, weak) id<LiveControlDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
