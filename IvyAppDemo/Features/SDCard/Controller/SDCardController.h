//
//  SDCardController.h
//  IvySdk
//
//  Created by JackChan on 27/6/2019.
//  Copyright © 2019 JackChan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "IvyCamera.h"

NS_ASSUME_NONNULL_BEGIN

@interface SDCardController : UIViewController

- (instancetype)initWithIvyCamera:(IvyCamera *)ivyCamera;

@end

NS_ASSUME_NONNULL_END
