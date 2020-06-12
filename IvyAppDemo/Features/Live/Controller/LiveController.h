//
//  LiveController.h
//  IvySdk
//
//  Created by JackChan on 25/6/2019.
//  Copyright © 2019 JackChan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "IvyCamera.h"

NS_ASSUME_NONNULL_BEGIN

@interface LiveController : UIViewController

- (instancetype)initWithIvyCamera:(IvyCamera *)ivyCamera;

- (void)preload;

@end

NS_ASSUME_NONNULL_END
