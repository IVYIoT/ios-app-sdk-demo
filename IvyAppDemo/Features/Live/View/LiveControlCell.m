//
//  LiveControlCell.m
//  IvySdk
//
//  Created by JackChan on 26/6/2019.
//  Copyright © 2019 JackChan. All rights reserved.
//

#import "LiveControlCell.h"
#import "UIImage+IvySdk.h"
#import "Masonry.h"

@interface LiveControlCell ()

@property (nonatomic, strong) UIButton *button;

@end

@implementation LiveControlCell

- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        [self initializer];
    }
    return self;
}

- (void)initializer {
    [self addSubview:self.button];
    [self.button mas_makeConstraints:^(MASConstraintMaker *make) {
        make.edges.equalTo(self);
    }];
}

- (void)setTitle:(NSString *)title {
    [self.button setTitle:title forState:UIControlStateNormal];
}

- (void)buttonTapped:(UIButton *)sender {
    if ([_delegate respondsToSelector:@selector(liveControlCell:didTapAtIndexPath:)]) {
        [_delegate liveControlCell:self didTapAtIndexPath:self.indexPath];
    }
}

- (UIButton *)button {
    if (!_button) {
        _button = [UIButton buttonWithType:UIButtonTypeCustom];
        _button.layer.cornerRadius = 8;
        _button.layer.masksToBounds = YES;
        _button.titleLabel.font = [UIFont systemFontOfSize:12];
        [_button setTitleColor:RGBCOLOR(81, 91, 88) forState:UIControlStateNormal];
        [_button setBackgroundImage:[UIImage imageWithColor:RGBCOLOR(242, 242, 243)] forState:UIControlStateNormal];
        [_button setBackgroundImage:[UIImage imageWithColor:RGBCOLOR(232, 232, 233)] forState:UIControlStateSelected];
        [_button setBackgroundImage:[UIImage imageWithColor:RGBCOLOR(232, 180, 180)] forState:UIControlStateHighlighted];
        [_button addTarget:self action:@selector(buttonTapped:) forControlEvents:UIControlEventTouchUpInside];
    }
    return _button;
}

@end
