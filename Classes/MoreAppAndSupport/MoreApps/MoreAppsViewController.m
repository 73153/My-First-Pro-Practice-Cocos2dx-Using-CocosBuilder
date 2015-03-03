//
//  MoreAppsViewController.m
//  MoreAppsDemo
//
//  Created by Henryp on 7/18/14.
//  Copyright (c) 2014 r3app. All rights reserved.
//

#import "MoreAppsViewController.h"

#define kScreenWidth [UIScreen mainScreen].bounds.size.width
#define kScreenHeight [UIScreen mainScreen].bounds.size.height

#define isiOS8OrGreater [[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0 ? YES : NO
#define isiPad UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad

#define isiPhone5  ( fabs( ( double )[ [ UIScreen mainScreen ] bounds ].size.height - ( double )568 ) < DBL_EPSILON )
#define isiPhone6  (fabs((double)[[UIScreen mainScreen] bounds].size.height - (double)667) < DBL_EPSILON)
#define isiPhone6Plus  (fabs((double)[[UIScreen mainScreen] bounds].size.height - (double)736) < DBL_EPSILON)


@interface MoreAppsViewController ()

@end

@implementation MoreAppsViewController

+ (void)present{
    MoreAppsViewController *moreAppVC = [[MoreAppsViewController alloc]init];
    [[self topViewController] presentViewController:moreAppVC animated:TRUE completion:nil];
}

+(UIViewController*) topViewController
{
    UIViewController *topController = [UIApplication sharedApplication].keyWindow.rootViewController;
    while (topController.presentedViewController)
    {
        topController = topController.presentedViewController;
    }
    return topController;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    _arrApps = [[NSMutableArray alloc]initWithContentsOfFile:ImagePath(@"appData.plist")];
    [pageControl setNumberOfPages:self.arrApps.count];
    
   // [imgViewBg setImage:[UIImage imageNamed:@""]];
    [self loadAppData];
    [carouselView setDelegate:self];
    [carouselView setPagingEnabled:TRUE];
    [carouselView setType:iCarouselTypeRotary];
    lblTitle.text = @"More Apps";
}

- (void)viewDidDisappear:(BOOL)animated {
    [super viewDidDisappear:animated];
  
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    [carouselView reloadData];
}

- (IBAction)btnDonePressed:(UIButton *)sender {
    [carouselView.visibleItemViews enumerateObjectsUsingBlock:^(UIView *view, NSUInteger idx, BOOL *stop) {
        JBAsyncImageView *topImageView =  (JBAsyncImageView *)[view viewWithTag:111];
        if ([topImageView isKindOfClass:[JBAsyncImageView class]]) {
            [topImageView stopImageAnimation];
        }
    }];
    [NSObject cancelPreviousPerformRequestsWithTarget:self];
    [NSObject cancelPreviousPerformRequestsWithTarget:self selector:@selector(startImageAnimation) object:nil];
    
    [UrlConnection cancel];
    [self dismissViewControllerAnimated:TRUE completion:nil];
    [self.navigationController popViewControllerAnimated:TRUE];
}
#pragma mark - Icarousel Delegate

- (NSUInteger)numberOfItemsInCarousel:(iCarousel *)carousel {
    return [self.arrApps count];
}

NSInteger getDeviceDependValue(NSInteger iPhone4, NSInteger iPhone5, NSInteger iPhone6, NSInteger iPhone6Plus, NSInteger iPad){
    if (isiPhone5) {
        return iPhone5;
    }else if (isiPhone6) {
        return iPhone6;
    }else if (isiPhone6Plus) {
        return iPhone6Plus;
    }else if (isiPad) {
        return iPad;
    }else {
        return iPhone4;
    }
    return 0;
}

- (UIView *)carousel:(iCarousel *)carousel viewForItemAtIndex:(NSUInteger)index reusingView:(UIView *)view {
    NSDictionary *dict = [self.arrApps objectAtIndex:index];
    
    NSURL *urlToLoad = [NSURL URLWithString:[dict valueForKey:isiPadOrIphone6Plus()?kiPadImageUrl:kiPhoneImageUrl]];
    //    NSLog(@"Base url = %@",urlToLoad);
    
    view = [[UIView alloc]initWithFrame:CGRectMake(0, 0, carousel.frame.size.width-100, carousel.frame.size.height)];
    //[view setBackgroundColor:[UIColor redColor]];
    
    JBAsyncImageView *imageView =nil;
    if (![[NSFileManager defaultManager] fileExistsAtPath:ImagePath(urlToLoad.lastPathComponent)]) {
       // imageView = [[JBAsyncImageView alloc] initWithURL:urlToLoad];
    }else{
        imageView = [[JBAsyncImageView alloc] init];
       [imageView setImage:[UIImage imageWithContentsOfFile:ImagePath(urlToLoad.lastPathComponent)]];
        
    }
    //imageView = [[JBAsyncImageView alloc]initWithImage:[UIImage imageNamed:@"1-fullimg"]];
    
    [imageView setContentMode:UIViewContentModeScaleAspectFit];
    [imageView setFrame:CGRectMake(0, 0, carousel.frame.size.width-100, carousel.frame.size.height)];
    [imageView setBackgroundColor:[UIColor clearColor]];
    
    JBAsyncImageView *topImageView = [[JBAsyncImageView alloc]init];
    NSArray *arrImages = [dict valueForKey:isiPadOrIphone6Plus()?kiPadTitleImgs:kiPodTitleImgs];
    if (arrImages.count) {
        UIImage *image = [UIImage imageWithContentsOfFile:ImagePath([[arrImages objectAtIndex:0]lastPathComponent])];
        [topImageView setImage:image];
    }
    
    [topImageView setAnimationImages_:arrImages];
    [topImageView setTag:111];
    [topImageView setContentMode:UIViewContentModeScaleToFill];
    
    NSInteger width = getDeviceDependValue(179, 220, 275, 314, 478);
    NSInteger height = getDeviceDependValue(115, 140, 170, 192, 283);
    [topImageView setFrame:CGRectMake(0, 0, width, height)];
   
    
    [topImageView setBackgroundColor:[UIColor clearColor]];
    [topImageView moveCenterHorizontalOf:view];
    
    [view addSubview:topImageView];
    [view addSubview:imageView];
    
    return view;
}

- (void)carouselWillBeginScrollingAnimation:(iCarousel *)carousel {
    [carousel.visibleItemViews enumerateObjectsUsingBlock:^(UIView *view, NSUInteger idx, BOOL *stop) {
        JBAsyncImageView *topImageView =  (JBAsyncImageView *)[view viewWithTag:111];
        if ([topImageView isKindOfClass:[JBAsyncImageView class]]) {
            [topImageView stopImageAnimation];
        }
    }];
    
    //NSLog(@"WillBeginScrolling");
}

- (void)carouselCurrentItemIndexDidChange:(iCarousel *)carousel {
    [pageControl setCurrentPage:carousel.currentItemIndex];
    
    
    // NSLog(@"CurrentItemIndexDidChange");
}

- (void)carouselDidEndScrollingAnimation:(iCarousel *)carousel {
    //NSLog(@"DidEndScrolling");
    
    UIView *view = [carousel itemViewAtIndex:carousel.currentItemIndex];
    JBAsyncImageView *topImageView =  (JBAsyncImageView *)[view viewWithTag:111];
    if ([topImageView isKindOfClass:[JBAsyncImageView class]]) {
        [topImageView startImageAnimation];
    }
}

- (CATransform3D)carousel:(iCarousel *)_carousel itemTransformForOffset:(CGFloat)offset baseTransform:(CATransform3D)transform
{
    //implement 'flip3D' style carousel
    transform = CATransform3DRotate(transform, M_PI / 8.0f, 0.0f, 1.0f, 0.0f);
    return CATransform3DTranslate(transform, 0.0f, 0.0f, offset * carouselView.itemWidth);
}

- (CGFloat)carousel:(iCarousel *)_carousel valueForOption:(iCarouselOption)option withDefault:(CGFloat)value {
    //customize carousel display
    switch (option) {
        case iCarouselOptionWrap:
            return TRUE;
        case iCarouselOptionSpacing:
            return value * 1.05f;
        case iCarouselOptionFadeMin:
            return -0.2;
        case iCarouselOptionFadeMax:
            return 0.2;
        case iCarouselOptionFadeRange:
            return 1.0;
        default:
            return value;
    }
}

-(void)carousel:(iCarousel *)carousel didSelectItemAtIndex:(NSInteger)index {
    NSDictionary *dict = [self.arrApps objectAtIndex:index];
    if ([[UIApplication sharedApplication]canOpenURL:[NSURL URLWithString:[dict valueForKey:kUrlSchema]]]) {
        [[UIApplication sharedApplication]openURL:[NSURL URLWithString:[dict valueForKey:kUrlSchema]]];
    }else{
        NSInteger appID = [[[self.arrApps objectAtIndex:index] valueForKey:kAppID] integerValue];
        if ([SKStoreProductViewController class]) {
            NSDictionary *appParameters = @{SKStoreProductParameterITunesItemIdentifier : [NSString stringWithFormat:@"%ld",(long)appID]};
            _productViewController = [[SKStoreProductViewController alloc] init];
            [self.productViewController setDelegate:self];
            [self.productViewController loadProductWithParameters:appParameters completionBlock:nil];
            [self presentViewController:self.productViewController animated:YES completion:nil];
        } else {
            NSString *appUrlString = [NSString stringWithFormat:@"itms-apps://itunes.apple.com/app/id%ld?mt=8", (long)appID];
            NSURL *appURL = [[NSURL alloc] initWithString:appUrlString];
            [[UIApplication sharedApplication] openURL:appURL];
        }
    }
}

- (void)productViewControllerDidFinish:(SKStoreProductViewController *)viewController {
    [viewController dismissViewControllerAnimated:TRUE completion:nil];
    
}

-(void)loadAppData {
    
    if (![[NSFileManager defaultManager] fileExistsAtPath:MoreAppImageFolderPath]) {
        [[NSFileManager defaultManager]createDirectoryAtPath:MoreAppImageFolderPath withIntermediateDirectories:TRUE attributes:nil error:nil];
        [self addSkipBackupAttributeToItemAtURL:MoreAppImageFolderPath];
    }
    // Create request
	NSURLRequest *request = [[NSURLRequest alloc] initWithURL:[NSURL URLWithString:kServerURL]
                                                  cachePolicy:NSURLRequestReloadIgnoringLocalCacheData
                                              timeoutInterval:HUGE_VAL];
	
	// Begin download
	
	UrlConnection = [[NSURLConnection alloc] initWithRequest:request
                                                    delegate:self
                                            startImmediately:YES];
}

#pragma mark - *** NSURLConnectionDelegate ***


- (void)connection:(NSURLConnection *)connection didFailWithError:(NSError *)error {
	NSLog(@"connection didFailWithError = %@",error);
	
}

- (void)connection:(NSURLConnection *)connection didReceiveData:(NSData *)data {
	if (!_appData) {
		_appData = [[NSMutableData alloc] init];
	}
	[self.appData appendData:data];
}

- (void)connectionDidFinishLoading:(NSURLConnection *)connection {
    NSError *error;
	NSDictionary *dict = [NSJSONSerialization JSONObjectWithData:self.appData options:NSJSONReadingMutableContainers error:&error];
    if ([[dict valueForKey:@"success"] boolValue]) {
        _arrApps = [[NSMutableArray alloc]initWithArray:[dict valueForKey:@"data"]];
        [self.arrApps enumerateObjectsUsingBlock:^(NSDictionary *obj, NSUInteger idx, BOOL *stop) {
            if ([[obj valueForKey:kAppID] integerValue] == MyAppID) {
                [self.arrApps removeObject:obj];
                *stop = TRUE;
            }
        }];
        [self.arrApps writeToFile:ImagePath(@"appData.plist") atomically:TRUE];
        
        [carouselView reloadData];
        [pageControl setNumberOfPages:self.arrApps.count];
        [self loadImages];
        
    }
    if (error) {
        NSLog(@"Error while Parse More Apps Data = %@",error);
    }
}

- (void)loadImages {
    SDWebImageDownloader *downloader = [SDWebImageDownloader sharedDownloader];
    [_arrApps enumerateObjectsUsingBlock:^(NSDictionary *dict, NSUInteger idx, BOOL *stop) {
        NSURL *urlToLoad = [NSURL URLWithString:[dict valueForKey:isiPadOrIphone6Plus()?kiPadImageUrl:kiPhoneImageUrl]];
        //NSLog(@"Base url = %@",urlToLoad);
        if (![[NSFileManager defaultManager] fileExistsAtPath:ImagePath(urlToLoad.lastPathComponent)]) {
            [downloader downloadImageWithURL:urlToLoad options:SDWebImageDownloaderIgnoreCachedResponse progress:nil completed:^(UIImage *image, NSData *data, NSError *error, BOOL finished) {
                [data writeToFile:ImagePath(urlToLoad.lastPathComponent) atomically:TRUE];
            }];
        }
        NSArray *arrImages = [dict valueForKey:isiPadOrIphone6Plus()?kiPadTitleImgs:kiPodTitleImgs];
        [arrImages enumerateObjectsUsingBlock:^(NSString *strUrl, NSUInteger idx, BOOL *stop) {
            if (![[NSFileManager defaultManager] fileExistsAtPath:ImagePath(strUrl.lastPathComponent)]) {
                [downloader downloadImageWithURL:[NSURL URLWithString:strUrl] options:SDWebImageDownloaderIgnoreCachedResponse progress:nil completed:^(UIImage *image, NSData *data, NSError *error, BOOL finished) {
                    [data writeToFile:ImagePath(strUrl.lastPathComponent) atomically:TRUE];
                }];
            }
        }];
    }];
    
}


- (BOOL)addSkipBackupAttributeToItemAtURL:(NSString *)path
{
    NSURL *URL = [NSURL fileURLWithPath:[path stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding]];
    assert([[NSFileManager defaultManager] fileExistsAtPath: [URL path]]);
    
    NSError *error = nil;
    BOOL success = [URL setResourceValue: [NSNumber numberWithBool: YES]
                                  forKey: NSURLIsExcludedFromBackupKey error: &error];
    if(!success){
        NSLog(@"Error excluding %@ from backup %@", [URL lastPathComponent], error);
    }
    return success;
}

@end


BOOL isiPadOrIphone6Plus() {
    if (isiPad || isiPhone6Plus) {
        return TRUE;
    }
    return FALSE;
}


