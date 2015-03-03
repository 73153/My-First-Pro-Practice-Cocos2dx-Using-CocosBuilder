//
//  AppsCue.h
//  AppsCue
//
//  Created by AppsCue on 25/09/14.
//  Copyright (c) 2014 AppsCue. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@interface AppsCue : NSObject

+ (AppsCue *)sharedInstance;

- (NSString *)apiKey;

- (void)startWithApiKey:(NSString *)apiKey;

- (void)presentPromotrViewFromViewController:(UIViewController *)viewController completion:(void(^)(BOOL success))success;


@end
