//
//  UIView+Utility.m
//  Calvertr
//
//  Created by Henryp on 6/26/14.
//  Copyright (c) 2014 r3app. All rights reserved.
//

#import "UIView+Utility.h"

@implementation UIView (FrameAdditions)

-(float) x {
    return self.frame.origin.x;
}

-(void) setX:(float) newX {
    CGRect frame = self.frame;
    frame.origin.x = newX;
    self.frame = frame;
}

-(float) y {
    return self.frame.origin.y;
}

-(void) setY:(float) newY {
    CGRect frame = self.frame;
    frame.origin.y = newY;
    self.frame = frame;
}

-(float) width {
    return self.frame.size.width;
}

-(void) setWidth:(float) newWidth {
    CGRect frame = self.frame;
    frame.size.width = newWidth;
    self.frame = frame;
}

-(float) height {
    return self.frame.size.height;
}

-(void) setHeight:(float) newHeight {
    CGRect frame = self.frame;
    frame.size.height = newHeight;
    self.frame = frame;
}
@end

@implementation UIView (Utility)

- (void) atOriginX:(CGFloat )x{
    [self setFrame: CGRectMake(
                               x,
                               self.frame.origin.y,
                               self.frame.size.width,
                               self.frame.size.height
                               )];
}

- (void) atOriginY:(CGFloat )y{
    [self setFrame: CGRectMake(
                               self.frame.origin.x,
                               y,
                               self.frame.size.width,
                               self.frame.size.height
                               )];
}

- (void)moveBottomOf:(UIView *)targetView margin:(CGFloat)margin{
    [self setFrame: CGRectMake(
                               self.frame.origin.x,
                               targetView.frame.origin.y + targetView.frame.size.height + margin,
                               self.frame.size.width,
                               self.frame.size.height
                               )];
}

- (void)moveRightOf:(UIView *)targetView margin:(CGFloat)margin{
    [self setFrame: CGRectMake(
                               targetView.frame.origin.x + targetView.frame.size.width + margin,
                               self.frame.origin.y,
                               self.frame.size.width,
                               self.frame.size.height
                               )];
}


- (void) moveCenterHorizontalOf:(UIView *)targetView{
    [self setFrame: CGRectMake(
                               ( targetView.frame.size.width - self.frame.size.width  )/2,
                               self.frame.origin.y,
                               self.frame.size.width,
                               self.frame.size.height
                               )];
}

- (void)moveCenterVerticalOf:(UIView *)targetView {
    [self setFrame: CGRectMake(
                               self.frame.origin.x,
                               ( targetView.frame.size.height - self.frame.size.height)/2,
                               self.frame.size.width,
                               self.frame.size.height
                               )];
}

- (void) moveBottomRightCorner:(UIView *)targetView margin:(CGFloat)margin{
    [self setFrame: CGRectMake(
                               targetView.frame.size.width
                               - self.frame.size.width - margin,
                               targetView.frame.size.height
                               - self.frame.size.height - margin,
                               self.frame.size.width,
                               self.frame.size.height
                               )];
}

- (void) moveTopRightCorner:(UIView *)targetView
                     margin:(CGFloat)margin{
    [self setFrame: CGRectMake(
                               targetView.frame.size.width
                               - self.frame.size.width - margin,
                               self.frame.size.height - margin,
                               self.frame.size.width,
                               self.frame.size.height
                               )];
}



- (void)centerJusticateWithSubviews:(NSArray *)subviews
                             margin:(CGFloat)margin
{
    
    CGFloat totalWidth = 0;
    for( UIView *view in subviews){
        totalWidth += view.bounds.size.width;
    }
    totalWidth += margin*( subviews.count - 1);
    
    CGFloat eachX = ( self.bounds.size.width - totalWidth) /2;
    
    for( UIView *view in subviews){
        [view atOriginX:eachX];
        eachX += view.bounds.size.width + margin;
    }
    
}
@end