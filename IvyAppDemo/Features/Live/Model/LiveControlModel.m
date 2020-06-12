//
//  LiveControlModel.m
//  IvySdk
//
//  Created by JackChan on 26/6/2019.
//  Copyright © 2019 JackChan. All rights reserved.
//

#import "LiveControlModel.h"

@implementation LiveControlModel

- (instancetype)initWithTitle:(NSString *)title tag:(LiveControlTag)tag {
    if (self = [super init]) {
        _title = title;
        _tag = tag;
    }
    return self;
}

@end
