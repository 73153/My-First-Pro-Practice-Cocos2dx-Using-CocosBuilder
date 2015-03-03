//
//  KAWModalWebViewController.m
//  KAWebViewController
//
//  Created by Kyle Adams on 12-04-14.
//  Copyright (c) 2014 Kyle Adams. All rights reserved.
//

#import "KAWModalWebViewController.h"
#import "KAWebViewController.h"

@interface KAWModalWebViewController () <UINavigationControllerDelegate>

@property (strong, nonatomic) KAWebViewController *webViewController;
@property (strong, nonatomic) UIBarButtonItem *doneButton;

@end

@implementation KAWModalWebViewController
+ (void)presentFrom:(UIViewController *)sourceVC WithUrl:(NSString *)URL {
    KAWModalWebViewController *modelWeb = [[KAWModalWebViewController alloc]init];
    [modelWeb setUrl:[NSURL URLWithString:[URL stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding]]];
    [sourceVC presentViewController:modelWeb animated:TRUE completion:nil];
    /*
    if(!isiPad) {
        [sourceVC presentViewController:modelWeb animated:TRUE completion:nil];
    }
    else {
        [sourceVC presentViewController:modelWeb animated:TRUE completion:nil];
    }
     */
}

-(id)init {
    self = [super init];
    [self.navigationBar setTintColor:[UIColor blackColor]];
    [self.navigationBar setBarTintColor:[UIColor whiteColor]];
    self.view.backgroundColor = [UIColor whiteColor];
    [self.navigationBar setTitleTextAttributes:
     [NSDictionary dictionaryWithObjectsAndKeys:
      [UIColor blackColor],
      NSForegroundColorAttributeName,
      nil]];
    return self;
}
- (void)awakeFromNib
{
    self.view.backgroundColor = [UIColor whiteColor];
}

- (void)setUrl:(NSURL *)url
{
    _url = url;
    self.webViewController.url = url;
    self.viewControllers = @[self.webViewController];
}

- (KAWebViewController *)webViewController
{
    if (!_webViewController) {
        _webViewController = [[KAWebViewController alloc] init];
        
        if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) {
            _webViewController.navigationItem.leftBarButtonItem = self.doneButton;
        } else {
            _webViewController.navigationItem.rightBarButtonItem = self.doneButton;
        }
    }
    return _webViewController;
}

- (UIBarButtonItem *)doneButton
{
    if (!_doneButton) {
        _doneButton = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemDone target:self action:@selector(dismissView)];
        [_doneButton setTintColor:[UIColor blackColor]];
    }
    return _doneButton;
}

- (void)dismissView
{
    [self dismissViewControllerAnimated:YES completion:^{
        self.webViewController = nil;
        [[UIApplication sharedApplication] setNetworkActivityIndicatorVisible:NO];
    }];
}

@end
