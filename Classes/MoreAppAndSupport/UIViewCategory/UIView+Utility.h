//
//  UIView+Utility.h
//  Calvertr
//
//  Created by Henryp on 6/26/14.
//  Copyright (c) 2014 r3app. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (Utility)
- (void) atOriginX:(CGFloat )x;
- (void) atOriginY:(CGFloat )y;
- (void) moveBottomOf:(UIView *)targetView margin:(CGFloat)margin;
- (void) moveRightOf:(UIView *)targetView margin:(CGFloat)margin;
- (void) moveCenterHorizontalOf:(UIView *)targetView;
- (void) moveCenterVerticalOf:(UIView *)targetView;
- (void) moveBottomRightCorner:(UIView *)targetView margin:(CGFloat)margin;
- (void) moveTopRightCorner:(UIView *)targetView margin:(CGFloat)margin;
- (void) centerJusticateWithSubviews:(NSArray *)subviews margin:(CGFloat)margin;
@end


@interface UIView (FrameAdditions)
@property float x;
@property float y;
@property float width;
@property float height;
@end