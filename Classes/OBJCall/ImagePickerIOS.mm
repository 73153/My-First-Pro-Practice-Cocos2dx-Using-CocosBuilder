
#import "../OBJCall/ImagePickerIOS.h"
#import <QuartzCore/QuartzCore.h>
#include "../OBJCall/ImagePicker.h"
#import "AppController.h"
#import "EAGLView.h"
#import "cocos2d.h"
#import "MKParentalGate.h"
#import "../MoreAppAndSupport/MoreApps/MoreAppsViewController.h"
#import "KAWModalWebViewController.h"
#import "PMParentalGateQuestion.h"
#include "../InApp/InAppController.h"
#import "../MoreAppAndSupport/Feedback/FeedbackViewController.h"
#import "../KAWebViewController/KAWebViewController.h"
#import "../MoreAppAndSupport/AppsCueSDK/AppsCue.h"

@implementation ImagePickerIOS

UIWindow *window2;
UIPopoverController *pop;

+ (ImagePickerIOS *) sharedObject {
    ImagePickerIOS *sharedPicker = nil;
    if (sharedPicker == nil)
    {
        sharedPicker = [[ImagePickerIOS alloc] init];
        [sharedPicker retain];
    }
    return sharedPicker;
}
- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}

- (void)viewDidLoad
{
    [super viewDidLoad];
}
-(void) takePhoto
{
    UIActionSheet *actionsheet=[[UIActionSheet alloc]initWithTitle:@"Select Photo" delegate:self cancelButtonTitle:@"Cancel" destructiveButtonTitle:Nil otherButtonTitles:@"Gallery",@"Camera", nil ];
    [actionsheet setTag:200];
    
    [actionsheet showInView:[[[[UIApplication sharedApplication] keyWindow] subviews] lastObject]];
}
-(void )takePhoto:(int )sourceClicked
{
    UIImagePickerController *picker = [[UIImagePickerController alloc] init];
    picker.delegate = self;
    picker.allowsEditing = YES;
    picker.sourceType = UIImagePickerControllerSourceTypePhotoLibrary;
    
    EAGLView *view = [EAGLView sharedEGLView];
    [view addSubview:(self.view)];
    
    [self presentViewController:picker animated:YES completion:NULL];
}
-(void) takePicture
{
    UIActionSheet *actionsheet=[[UIActionSheet alloc]initWithTitle:@"Select Photo" delegate:self cancelButtonTitle:@"Cancel" destructiveButtonTitle:Nil otherButtonTitles:@"Gallery",@"Camera", nil ];
    [actionsheet setTag:100];
    [actionsheet showInView:[[[[UIApplication sharedApplication] keyWindow] subviews] lastObject]];
}


#pragma mark - Image scaling
-(void)showPhotoLibrary:(id)pController{
    UIImagePickerController *imagePicker = [[UIImagePickerController alloc] init];
    imagePicker.delegate = pController;
    imagePicker.sourceType = UIImagePickerControllerSourceTypePhotoLibrary;
    [pController presentModalViewController:imagePicker animated:YES];
}

-(void )takePicture:(int )source
{
    UIView *view=[[[[UIApplication sharedApplication] keyWindow] subviews] lastObject];
    UIImagePickerController *imagePicker = [[UIImagePickerController alloc] init];
    if ([UIImagePickerController isSourceTypeAvailable:UIImagePickerControllerSourceTypeCamera]&&source==1)
    {
        imagePicker.sourceType = UIImagePickerControllerSourceTypeCamera;
    }
    else
    {
        imagePicker.sourceType = UIImagePickerControllerSourceTypePhotoLibrary;
    }
    [imagePicker setDelegate:self];
    pop = [[UIPopoverController alloc] initWithContentViewController:imagePicker];
    [pop setDelegate:self];
    [pop presentPopoverFromRect:CGRectMake(view.frame.size.width/3.5, view.frame.size.height/2.5, 10.0f, 10.0f) inView:view permittedArrowDirections:UIPopoverArrowDirectionAny animated:YES];
}
- (void)actionSheet:(UIActionSheet *)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex
{
    NSLog(@"%d",buttonIndex);
}
- (void)actionSheetCancel:(UIActionSheet *)actionSheet
{
    
}

- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary *)info {
    [picker dismissModalViewControllerAnimated:YES];
    image = [self imageWithImage:[info objectForKey:UIImagePickerControllerOriginalImage] scaledToSize:CGSizeMake(193, 193)];
    [image retain];
    [self cleanup];
    ImagePicker::setReady();
}

- (void)willPresentActionSheet:(UIActionSheet *)actionSheet
{
    
}
- (void)didPresentActionSheet:(UIActionSheet *)actionSheet
{
    
}
- (void)actionSheet:(UIActionSheet *)actionSheet willDismissWithButtonIndex:(NSInteger)buttonIndex
{
    NSLog(@"%d",buttonIndex);
}
- (void)actionSheet:(UIActionSheet *)actionSheet didDismissWithButtonIndex:(NSInteger)buttonIndex
{
    if([actionSheet tag]==100)
    {
        if (buttonIndex==0||buttonIndex==1)
        {
            [self takePicture:buttonIndex];
        }
        else
        {
            ImagePicker::dismissed();
        }
    }
    else  if([actionSheet tag]==200)
    {
        if (buttonIndex==0||buttonIndex==1)
        {
            [self takePhoto:buttonIndex];
        }
        else
        {
            ImagePicker::dismissed();
        }
    }
}

-(UIImage *)imageWithImage:(UIImage*)image1 scaledToSize:(CGSize)newSize
{
    float oldWidth = image1.size.width;
    float scaleFactor = newSize.width / oldWidth;
    
    float newHeight = image1.size.height * scaleFactor;
    float newWidth = oldWidth * scaleFactor;
    
    //    UIGraphicsBeginImageContext(CGSizeMake(newWidth, newHeight));
    UIGraphicsBeginImageContextWithOptions(newSize, YES, [UIScreen mainScreen].scale);
    [image1 drawInRect:CGRectMake(0, 0, newWidth, newHeight)];
    UIImage *newImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    //
    //    // Create a bitmap context.
    //    UIGraphicsBeginImageContextWithOptions(newSize, YES, [UIScreen mainScreen].scale);
    //    [image1 drawInRect:CGRectMake(0,0,newSize.width,newSize.height)];
    //
    //    UIImage* newImage = UIGraphicsGetImageFromCurrentImageContext();
    //    UIGraphicsEndImageContext();
    return newImage;
    
}
- (void)popoverControllerDidDismissPopover:(UIPopoverController *)popoverController
{
    ImagePicker::dismissed();
    [self cleanup];
}
-(void) cleanup
{
    if (pop)
    {
        [pop dismissPopoverAnimated:YES];
        [pop release];
    }
    
    //    [window2 setHidden:YES];
    //    [window2 release];
    
}

#pragma mark - Share
- (void)openShareActivity {
    NSArray *activityProviders = @[kShareString];
    UIView *view=[[[[UIApplication sharedApplication] keyWindow] subviews] lastObject];
    UIActivityViewController *activityViewController = [[UIActivityViewController alloc] initWithActivityItems:activityProviders applicationActivities:nil];
    activityViewController.excludedActivityTypes = @[UIActivityTypePrint, UIActivityTypeCopyToPasteboard, UIActivityTypeAssignToContact, UIActivityTypeSaveToCameraRoll,UIActivityTypeAddToReadingList];
    if(isiPad) {
        _popupActivityView = [[UIPopoverController alloc] initWithContentViewController:activityViewController];
        CGRect frame =CGRectMake(view.frame.size.width/3.5, view.frame.size.height/2.1, 10.0f, 10.0f) ;
        [_popupActivityView presentPopoverFromRect:frame inView:view permittedArrowDirections:UIPopoverArrowDirectionUp animated:YES];
    }
    else {
        [[MoreAppsViewController topViewController] presentViewController:activityViewController animated:YES completion:nil];
    }
}

- (void)onShareClickedFromMonuments {
    
    NSArray *activityProviders = @[kShareString];
    UIView *view=[[[[UIApplication sharedApplication] keyWindow] subviews] lastObject];
    UIActivityViewController *activityViewController = [[UIActivityViewController alloc] initWithActivityItems:activityProviders applicationActivities:nil];
    activityViewController.excludedActivityTypes = @[UIActivityTypePrint, UIActivityTypeCopyToPasteboard, UIActivityTypeAssignToContact, UIActivityTypeSaveToCameraRoll,UIActivityTypeAddToReadingList];
    if(isiPad) {
        _popupActivityView = [[UIPopoverController alloc] initWithContentViewController:activityViewController];
        CGRect frame =CGRectMake(view.frame.size.width/3.6, view.frame.size.height/2, 10.0f, 10.0f) ;
        [_popupActivityView presentPopoverFromRect:frame inView:view permittedArrowDirections:UIPopoverArrowDirectionUp animated:YES];
    }
    else {
        [[MoreAppsViewController topViewController] presentViewController:activityViewController animated:YES completion:nil];
    }
    
}

-(void)displayParentalGatesForFB
{
    int randomNumber = arc4random()%2;
    if(randomNumber==0){
        [MKParentalGate displayGateWithCurrentViewController:[MoreAppsViewController topViewController] successBlock:^{
            
            NSURL *url = [NSURL URLWithString:@"fb://profile/262949970541423"];
            if ([[UIApplication sharedApplication]canOpenURL:url]) {
                [[UIApplication sharedApplication] openURL:url];
            }
            else{
                
                [MKParentalGate dismiisViewController:[MoreAppsViewController topViewController]];
                [self performSelector:@selector(OpenTwitterOrFaceBook:) withObject:@"https://www.facebook.com/r3app" afterDelay:0.5];
            }
        } failureBlock:^{
            return;
        }];
    }else
    {
        [[PMParentalGateQuestion sharedGate] presentGateWithText:@"You're trying to access a parents only area. Prove you're not a kiddo by solving the following problem."  finishedBlock:^(BOOL allowPass, GateResult result) {
            
            
            if(result==GR_GOOD)
            {
                NSURL *url = [NSURL URLWithString:@"fb://profile/262949970541423"];
                if ([[UIApplication sharedApplication]canOpenURL:url]) {
                    [[UIApplication sharedApplication] openURL:url];
                }
                else{
                    
                    [MKParentalGate dismiisViewController:[MoreAppsViewController topViewController]];
                    
                    [self performSelector:@selector(OpenTwitterOrFaceBook:) withObject:@"https://www.facebook.com/r3app" afterDelay:0.5];
                }
            }
            else if(result==GR_WRONG)
            {
                [[[UIAlertView alloc] initWithTitle:@"Wrong Answer"
                                            message:nil
                                           delegate:nil
                                  cancelButtonTitle:@"Ok"
                                  otherButtonTitles: nil] show];
                
            }
        }];
    }
}

- (void) OpenTwitterOrFaceBook:(NSString *)aStrURL {
    [KAWModalWebViewController presentFrom:[MoreAppsViewController topViewController] WithUrl:aStrURL];
}

-(void)displayParentalGatesForTwitter
{
    int randomNumber = arc4random()%2;
    if(randomNumber==0){
        [MKParentalGate displayGateWithCurrentViewController:[MoreAppsViewController topViewController] successBlock:^{
            
            NSURL *url = [NSURL URLWithString:@"twitter://user?screen_name=r3applive"];
            if ([[UIApplication sharedApplication]canOpenURL:url]) {
                [[UIApplication sharedApplication] openURL:url];
            }
            else{
                [MKParentalGate dismiisViewController:[MoreAppsViewController topViewController]];
                [self performSelector:@selector(OpenTwitterOrFaceBook:) withObject:@"https://twitter.com/r3applive" afterDelay:0.5];
            }
            
        } failureBlock:^{
            return;
        }];
    }
    else
    {
        [[PMParentalGateQuestion sharedGate] presentGateWithText:@"You're trying to access a parents only area. Prove you're not a kiddo by solving the following problem."  finishedBlock:^(BOOL allowPass, GateResult result) {
            
            
            if(result==GR_GOOD)
            {
                NSURL *url = [NSURL URLWithString:@"twitter://user?screen_name=r3applive"];
                if ([[UIApplication sharedApplication]canOpenURL:url]) {
                    [[UIApplication sharedApplication] openURL:url];
                }
                else{
                    [MKParentalGate dismiisViewController:[MoreAppsViewController topViewController]];
                    [self performSelector:@selector(OpenTwitterOrFaceBook:) withObject:@"https://twitter.com/r3applive" afterDelay:0.5];
                }
            }
            else if(result==GR_WRONG)
            {
                [[[UIAlertView alloc] initWithTitle:@"Wrong Answer"
                                            message:nil
                                           delegate:nil
                                  cancelButtonTitle:@"Ok"
                                  otherButtonTitles: nil] show];
                
            }
        }];
    }
}
-(void)dissmissTopViewFordisplayParentalGatesForFeedBackForm
{
    [FeedbackViewController present];
}
-(void)displayParentalGatesForFeedBackForm
{
    int randomNumber = arc4random()%2;
    if(randomNumber==0){
        [MKParentalGate displayGateWithCurrentViewController:[MoreAppsViewController topViewController] successBlock:^{
            [MKParentalGate dismiisViewController:[MoreAppsViewController topViewController]];
            [self performSelector:@selector(dissmissTopViewFordisplayParentalGatesForFeedBackForm) withObject:nil afterDelay:0.5];
            
        } failureBlock:^{
            return;
        }];
    }else
    {
        [[PMParentalGateQuestion sharedGate] presentGateWithText:@"You're trying to access a parents only area. Prove you're not a kiddo by solving the following problem."  finishedBlock:^(BOOL allowPass, GateResult result) {
            
            if(result==GR_GOOD){
                [MKParentalGate dismiisViewController:[MoreAppsViewController topViewController]];
                [self performSelector:@selector(dissmissTopViewFordisplayParentalGatesForFeedBackForm) withObject:nil afterDelay:0.5];
            }
            else if(result==GR_WRONG)
            {
                [[[UIAlertView alloc] initWithTitle:@"Wrong Answer"
                                            message:nil
                                           delegate:nil
                                  cancelButtonTitle:@"Ok"
                                  otherButtonTitles: nil] show];
                
            }
        }];
    }
}
-(void)dissmissTopViewFordisplayParentalGatesForFollowUs
{
    NSURL *url = [NSURL URLWithString:@"fb://profile/262949970541423"];
    if ([[UIApplication sharedApplication]canOpenURL:url]) {
        [[UIApplication sharedApplication] openURL:url];
    }
    else{
        [KAWModalWebViewController presentFrom:[MoreAppsViewController topViewController] WithUrl:@"https://www.facebook.com/r3app"];
    }
}

-(void)displayParentalGatesForFollowUs
{
    int randomNumber = arc4random()%2;
    if(randomNumber==0){
        [MKParentalGate displayGateWithCurrentViewController:[MoreAppsViewController topViewController] successBlock:^{
            [MKParentalGate dismiisViewController:[MoreAppsViewController topViewController]];
            [self performSelector:@selector(dissmissTopViewFordisplayParentalGatesForFollowUs) withObject:nil afterDelay:0.5];
            
            
        } failureBlock:^{
            return;
        }];
    }else
    {
        [[PMParentalGateQuestion sharedGate] presentGateWithText:@"You're trying to access a parents only area. Prove you're not a kiddo by solving the following problem."  finishedBlock:^(BOOL allowPass, GateResult result) {
            
            
            if(result==GR_GOOD)
            {
                [MKParentalGate dismiisViewController:[MoreAppsViewController topViewController]];
                [self performSelector:@selector(dissmissTopViewFordisplayParentalGatesForFollowUs) withObject:nil afterDelay:0.5];
                
            }
            else if(result==GR_WRONG)
            {
                [[[UIAlertView alloc] initWithTitle:@"Wrong Answer"
                                            message:nil
                                           delegate:nil
                                  cancelButtonTitle:@"Ok"
                                  otherButtonTitles: nil] show];
                
            }
        }];
    }
}
-(void)dissmissTopViewForShare
{
    [[ImagePickerIOS sharedObject] onShareClickedFromMonuments];
    
}

-(void)displayParentalGatesForShare
{
    int randomNumber = arc4random()%2;
    if(randomNumber==0){
        [MKParentalGate displayGateWithCurrentViewController:[MoreAppsViewController topViewController] successBlock:^{
            
            [MKParentalGate dismiisViewController:[MoreAppsViewController topViewController]];
            
            [self performSelector:@selector(dissmissTopViewForShare) withObject:nil afterDelay:0.5];
            
        } failureBlock:^{
            return;
        }];
    }else
    {
        [[PMParentalGateQuestion sharedGate] presentGateWithText:@"You're trying to access a parents only area. Prove you're not a kiddo by solving the following problem."  finishedBlock:^(BOOL allowPass, GateResult result) {
            
            if(result==GR_GOOD){
                [MKParentalGate dismiisViewController:[MoreAppsViewController topViewController]];
                [self performSelector:@selector(dissmissTopViewForShare) withObject:nil afterDelay:0.5];
            }
            else if(result==GR_WRONG)
            {
                [[[UIAlertView alloc] initWithTitle:@"Wrong Answer"
                                            message:nil
                                           delegate:nil
                                  cancelButtonTitle:@"Ok"
                                  otherButtonTitles: nil] show];
                
            }
        }];
    }
    
}
-(void)dissmissTopViewFordisplayParentalGatesForRateUs
{
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:kAppUrl]];
}

-(void)displayParentalGatesForRateUs
{
    int randomNumber = arc4random()%2;
    if(randomNumber==0){
        [MKParentalGate displayGateWithCurrentViewController:[MoreAppsViewController topViewController] successBlock:^{
            
            [MKParentalGate dismiisViewController:[MoreAppsViewController topViewController]];
            
            [self performSelector:@selector(dissmissTopViewFordisplayParentalGatesForRateUs) withObject:nil afterDelay:0.5];
        } failureBlock:^{
            return;
        }];
    }else
    {
        [[PMParentalGateQuestion sharedGate] presentGateWithText:@"You're trying to access a parents only area. Prove you're not a kiddo by solving the following problem."  finishedBlock:^(BOOL allowPass, GateResult result) {
            
            if(result==GR_GOOD){
                [MKParentalGate dismiisViewController:[MoreAppsViewController topViewController]];
                
                [self performSelector:@selector(dissmissTopViewFordisplayParentalGatesForRateUs) withObject:nil afterDelay:0.5];
            }
            else if(result==GR_WRONG)
            {
                [[[UIAlertView alloc] initWithTitle:@"Wrong Answer"
                                            message:nil
                                           delegate:nil
                                  cancelButtonTitle:@"Ok"
                                  otherButtonTitles: nil] show];
                
            }
        }];
    }
    
}

-(void)dissmissTopViewForMoreApp
{
    
    //    UIViewController *topController = [UIApplication sharedApplication].keyWindow.rootViewController;
    //    while (topController.presentedViewController)
    //    {
    //        topController = topController.presentedViewController;
    //    }
    
    [[AppsCue sharedInstance]presentPromotrViewFromViewController:[MoreAppsViewController topViewController] completion:^(BOOL success) {
        
    }];
}
-(void)displayParentalGatesForMoreApps
{
    int randomNumber = arc4random()%2;
    if(randomNumber==0){
        [MKParentalGate displayGateWithCurrentViewController:[MoreAppsViewController topViewController] successBlock:^{
            
            [MKParentalGate dismiisViewController:[MoreAppsViewController topViewController]];
            
            [self performSelector:@selector(dissmissTopViewForMoreApp) withObject:nil afterDelay:0.5];
            
        } failureBlock:^{
            return;
        }];
    }else
    {
        [[PMParentalGateQuestion sharedGate] presentGateWithText:@"You're trying to access a parents only area. Prove you're not a kiddo by solving the following problem."  finishedBlock:^(BOOL allowPass, GateResult result) {
            if(result==GR_GOOD){
                
                [MKParentalGate dismiisViewController:[MoreAppsViewController topViewController]];
                
                [self performSelector:@selector(dissmissTopViewForMoreApp) withObject:nil afterDelay:0.5];
                
            }
            else if(result==GR_WRONG)
            {
                [[[UIAlertView alloc] initWithTitle:@"Wrong Answer"
                                            message:nil
                                           delegate:nil
                                  cancelButtonTitle:@"Ok"
                                  otherButtonTitles: nil] show];
                
            }
        }];
    }
}

-(void)displayParentalGatesForunlockAllMonuments;
{
    int randomNumber = arc4random()%2;
    if(randomNumber==0){
        
        [MKParentalGate displayGateWithCurrentViewController:[MoreAppsViewController topViewController] successBlock:^{
            InAppController *inAppObj = [[InAppController alloc]init];
            [inAppObj unlockAllMonuments];
            
        } failureBlock:^{
            return;
        }];
    }else
    {
        [[PMParentalGateQuestion sharedGate] presentGateWithText:@"You're trying to access a parents only area. Prove you're not a kiddo by solving the following problem."  finishedBlock:^(BOOL allowPass, GateResult result) {
            
            
            if(result==GR_GOOD){
                InAppController *inAppObj = [[InAppController alloc]init];
                [inAppObj unlockAllMonuments];
            }
            else if(result==GR_WRONG)
            {
                [[[UIAlertView alloc] initWithTitle:@"Wrong Answer"
                                            message:nil
                                           delegate:nil
                                  cancelButtonTitle:@"Ok"
                                  otherButtonTitles: nil] show];
                
            }
        }];
    }
    
}
-(void)displayParentalGatesForpurchaseEffielTower
{
    int randomNumber = arc4random()%2;
    if(randomNumber==0){
        [MKParentalGate displayGateWithCurrentViewController:[MoreAppsViewController topViewController] successBlock:^{
            InAppController *inAppObj = [[InAppController alloc]init];
            [inAppObj purchaseEffielTower];
            
        } failureBlock:^{
            return;
        }];
    }else
    {
        [[PMParentalGateQuestion sharedGate] presentGateWithText:@"You're trying to access a parents only area. Prove you're not a kiddo by solving the following problem."  finishedBlock:^(BOOL allowPass, GateResult result) {
            
            
            if(result==GR_GOOD)
            {
                InAppController *inAppObj = [[InAppController alloc]init];
                [inAppObj purchaseEffielTower];
                
            }
            else if(result==GR_WRONG)
            {
                [[[UIAlertView alloc] initWithTitle:@"Wrong Answer"
                                            message:nil
                                           delegate:nil
                                  cancelButtonTitle:@"Ok"
                                  otherButtonTitles: nil] show];
                
            }
        }];
    }
    
}
-(void)displayParentalGatesForpurchaseStatueueOfLiberty
{
    int randomNumber = arc4random()%2;
    if(randomNumber==0){
        [MKParentalGate displayGateWithCurrentViewController:[MoreAppsViewController topViewController] successBlock:^{
            InAppController *inAppObj = [[InAppController alloc]init];
            [inAppObj purchaseStatueueOfLiberty];
            
        } failureBlock:^{
            return;
        }];
    }else
    {
        [[PMParentalGateQuestion sharedGate] presentGateWithText:@"You're trying to access a parents only area. Prove you're not a kiddo by solving the following problem."  finishedBlock:^(BOOL allowPass, GateResult result) {
            
            
            if(result==GR_GOOD)
            {
                InAppController *inAppObj = [[InAppController alloc]init];
                [inAppObj purchaseStatueueOfLiberty];
            }
            else if(result==GR_WRONG)
            {
                [[[UIAlertView alloc] initWithTitle:@"Wrong Answer"
                                            message:nil
                                           delegate:nil
                                  cancelButtonTitle:@"Ok"
                                  otherButtonTitles: nil] show];
                
            }
        }];
    }
    
}
-(void)displayParentalGatesForpurchaseTowerOfPisa
{
    int randomNumber = arc4random()%2;
    if(randomNumber==0){
        [MKParentalGate displayGateWithCurrentViewController:[MoreAppsViewController topViewController] successBlock:^{
            InAppController *inAppObj = [[InAppController alloc]init];
            [inAppObj purchaseTowerOfPisa];
            
        } failureBlock:^{
            return;
        }];
    }else
    {
        [[PMParentalGateQuestion sharedGate] presentGateWithText:@"You're trying to access a parents only area. Prove you're not a kiddo by solving the following problem."  finishedBlock:^(BOOL allowPass, GateResult result) {
            
            
            if(result==GR_GOOD)
            {
                InAppController *inAppObj = [[InAppController alloc]init];
                [inAppObj purchaseTowerOfPisa];
            }
            else if(result==GR_WRONG)
            {
                [[[UIAlertView alloc] initWithTitle:@"Wrong Answer"
                                            message:nil
                                           delegate:nil
                                  cancelButtonTitle:@"Ok"
                                  otherButtonTitles: nil] show];
                
            }
        }];
    }
    
}
-(void)displayParentalGatesForpurchaseBigBen
{
    int randomNumber = arc4random()%2;
    if(randomNumber==0){
        [MKParentalGate displayGateWithCurrentViewController:[MoreAppsViewController topViewController] successBlock:^{
            InAppController *inAppObj = [[InAppController alloc]init];
            [inAppObj purchaseBigBen];
            
        } failureBlock:^{
            return;
        }];
    }else
    {
        [[PMParentalGateQuestion sharedGate] presentGateWithText:@"You're trying to access a parents only area. Prove you're not a kiddo by solving the following problem."  finishedBlock:^(BOOL allowPass, GateResult result) {
            if(result==GR_GOOD)
            {
                InAppController *inAppObj = [[InAppController alloc]init];
                [inAppObj purchaseBigBen];
            }
            else if(result==GR_WRONG)
            {
                [[[UIAlertView alloc] initWithTitle:@"Wrong Answer"
                                            message:nil
                                           delegate:nil
                                  cancelButtonTitle:@"Ok"
                                  otherButtonTitles: nil] show];
                
            }
        }];
    }
    
}
-(void)displayParentalGatesForpurchaseColosseum
{
    int randomNumber = arc4random()%2;
    if(randomNumber==0){
        [MKParentalGate displayGateWithCurrentViewController:[MoreAppsViewController topViewController] successBlock:^{
            InAppController *inAppObj = [[InAppController alloc]init];
            [inAppObj purchaseColosseum];
            
        } failureBlock:^{
            return;
        }];
    }else
    {
        [[PMParentalGateQuestion sharedGate] presentGateWithText:@"You're trying to access a parents only area. Prove you're not a kiddo by solving the following problem."  finishedBlock:^(BOOL allowPass, GateResult result) {
            
            
            if(result==GR_GOOD)
            {
                InAppController *inAppObj = [[InAppController alloc]init];
                [inAppObj purchaseColosseum];
            }
            else if(result==GR_WRONG)
            {
                [[[UIAlertView alloc] initWithTitle:@"Wrong Answer"
                                            message:nil
                                           delegate:nil
                                  cancelButtonTitle:@"Ok"
                                  otherButtonTitles: nil] show];
                
            }
        }];
    }
    
}
-(void)displayParentalGatesForpurchaseOperaHouse
{
    int randomNumber = arc4random()%2;
    if(randomNumber==0){
        [MKParentalGate displayGateWithCurrentViewController:[MoreAppsViewController topViewController] successBlock:^{
            
            InAppController *inAppObj = [[InAppController alloc]init];
            [inAppObj purchaseOperaHouse];
            
        } failureBlock:^{
            return;
        }];
    }else
    {
        [[PMParentalGateQuestion sharedGate] presentGateWithText:@"You're trying to access a parents only area. Prove you're not a kiddo by solving the following problem."  finishedBlock:^(BOOL allowPass, GateResult result) {
            
            
            if(result==GR_GOOD)
            {
                InAppController *inAppObj = [[InAppController alloc]init];
                [inAppObj purchaseOperaHouse];
            }
            else if(result==GR_WRONG)
            {
                [[[UIAlertView alloc] initWithTitle:@"Wrong Answer"
                                            message:nil
                                           delegate:nil
                                  cancelButtonTitle:@"Ok"
                                  otherButtonTitles: nil] show];
                
            }
        }];
    }
    
}
-(void)displayParentalGatesForpurchaseEasterStone
{
    int randomNumber = arc4random()%2;
    if(randomNumber==0){
        [MKParentalGate displayGateWithCurrentViewController:[MoreAppsViewController topViewController] successBlock:^{
            InAppController *inAppObj = [[InAppController alloc]init];
            [inAppObj purchaseEasterStone];
            
        } failureBlock:^{
            return;
        }];
    }else
    {
        [[PMParentalGateQuestion sharedGate] presentGateWithText:@"You're trying to access a parents only area. Prove you're not a kiddo by solving the following problem."  finishedBlock:^(BOOL allowPass, GateResult result) {
            
            
            if(result==GR_GOOD)
            {
                InAppController *inAppObj = [[InAppController alloc]init];
                [inAppObj purchaseEasterStone];
            }
            else if(result==GR_WRONG)
            {
                [[[UIAlertView alloc] initWithTitle:@"Wrong Answer"
                                            message:nil
                                           delegate:nil
                                  cancelButtonTitle:@"Ok"
                                  otherButtonTitles: nil] show];
                
            }
        }];
    }
    
}

-(void)displayParentalGatesForrestoreInAppPurchase
{
    int randomNumber = arc4random()%2;
    if(randomNumber==0){
        [MKParentalGate displayGateWithCurrentViewController:[MoreAppsViewController topViewController] successBlock:^{
            InAppController *inAppObj = [[InAppController alloc]init];
            [inAppObj restoreProduct];
            
        } failureBlock:^{
            return;
        }];
    }else
    {
        [[PMParentalGateQuestion sharedGate] presentGateWithText:@"You're trying to access a parents only area. Prove you're not a kiddo by solving the following problem."  finishedBlock:^(BOOL allowPass, GateResult result) {
            
            
            if(result==GR_GOOD)
            {
                InAppController *inAppObj = [[InAppController alloc]init];
                [inAppObj restoreProduct];
            }
            else if(result==GR_WRONG)
            {
                [[[UIAlertView alloc] initWithTitle:@"Wrong Answer"
                                            message:nil
                                           delegate:nil
                                  cancelButtonTitle:@"Ok"
                                  otherButtonTitles: nil] show];
                
            }
        }];
    }
    
}
-(void)displayParentalGatesForpurchaseFiveHundredCoins
{
    int randomNumber = arc4random()%2;
    if(randomNumber==0){
        [MKParentalGate displayGateWithCurrentViewController:[MoreAppsViewController topViewController] successBlock:^{
            InAppController *inAppObj = [[InAppController alloc]init];
            [inAppObj purchaseFiveHundredCoins];
            
        } failureBlock:^{
            return;
        }];
    }else
    {
        [[PMParentalGateQuestion sharedGate] presentGateWithText:@"You're trying to access a parents only area. Prove you're not a kiddo by solving the following problem."  finishedBlock:^(BOOL allowPass, GateResult result) {
            
            
            if(result==GR_GOOD){
                InAppController *inAppObj = [[InAppController alloc]init];
                [inAppObj purchaseFiveHundredCoins];
            }
            else if(result==GR_WRONG)
            {
                [[[UIAlertView alloc] initWithTitle:@"Wrong Answer"
                                            message:nil
                                           delegate:nil
                                  cancelButtonTitle:@"Ok"
                                  otherButtonTitles: nil] show];
                
            }
        }];
    }
}


-(void)displayParentalGatesForalertForCoinsBuy
{
    int randomNumber = arc4random()%2;
    if(randomNumber==0){
        [MKParentalGate displayGateWithCurrentViewController:[MoreAppsViewController topViewController] successBlock:^{
            [[ImagePickerIOS sharedObject] alertForCoinsBuy];
            
        } failureBlock:^{
            return;
        }];
    }else
    {
        [[PMParentalGateQuestion sharedGate] presentGateWithText:@"You're trying to access a parents only area. Prove you're not a kiddo by solving the following problem."  finishedBlock:^(BOOL allowPass, GateResult result) {
            
            
            if(result==GR_GOOD){
                [[ImagePickerIOS sharedObject] alertForCoinsBuy];
            }
            else if(result==GR_WRONG)
            {
                [[[UIAlertView alloc] initWithTitle:@"Wrong Answer"
                                            message:nil
                                           delegate:nil
                                  cancelButtonTitle:@"Ok"
                                  otherButtonTitles: nil] show];
                
            }
        }];
    }
    
}

-(UIImage*) getImage
{
    return image;
}


-(void)dissmissTopViewFordisplayParentalGatesForInAppMonument
{
    if([monumentNameStr isEqualToString:@"EIFFEL TOWER"])
    {
        InAppController *inAppObj = [[InAppController alloc]init];
        [inAppObj purchaseEffielTower];
    }
    else if ([monumentNameStr isEqualToString:@"STATUE OF LIBERTY"])
    {
        InAppController *inAppObj = [[InAppController alloc]init];
        [inAppObj purchaseStatueueOfLiberty];
    }
    else if ([monumentNameStr isEqualToString:@"TOWER OF PISA"])
    {
        InAppController *inAppObj = [[InAppController alloc]init];
        [inAppObj purchaseTowerOfPisa];
    }
    else if ([monumentNameStr isEqualToString:@"BIG BEN"])
    {
        InAppController *inAppObj = [[InAppController alloc]init];
        [inAppObj purchaseBigBen];
    }
    else if ([monumentNameStr isEqualToString:@"COLOSSEUM"])
    {
        InAppController *inAppObj = [[InAppController alloc]init];
        [inAppObj purchaseColosseum];
    }
    else if ([monumentNameStr isEqualToString:@"OPERA HOUSE"])
    {
        InAppController *inAppObj = [[InAppController alloc]init];
        [inAppObj purchaseOperaHouse];
    }
    else if ([monumentNameStr isEqualToString:@"EASTER STONE"])
    {
        InAppController *inAppObj = [[InAppController alloc]init];
        [inAppObj purchaseEasterStone];
    }
}

-(void)openAlert:(bool)isAnyLevelCleared monumentName:(NSString *)monumentName
{
    int randomNumber = arc4random()%2;
    if(randomNumber==0){
        [MKParentalGate displayGateWithCurrentViewController:[MoreAppsViewController topViewController] successBlock:^{
            
            [MKParentalGate dismiisViewController:[MoreAppsViewController topViewController]];
            
            if(monumentNameStr==nil)
                monumentNameStr = [[NSString alloc]initWithString:monumentName];
            else
                monumentNameStr = [NSString stringWithFormat:@"%@",monumentName];
            if(isAnyLevelCleared==false){
                NSString *strMessage = [NSString stringWithFormat:@"All levels of %@ are locked. Do you want to unlock all levels?",monumentName];
                UIAlertView *myalertView = [[UIAlertView alloc]initWithTitle:@"Oops!"
                                                                     message:strMessage delegate:self cancelButtonTitle:@"No, Thanks" otherButtonTitles:@"Yes, Sure", nil];
                [myalertView setTag:1000];
                [myalertView show];
            }
            else if(isAnyLevelCleared==true){
                
                [MKParentalGate dismiisViewController:[MoreAppsViewController topViewController]];
                NSString *strMessage = [NSString stringWithFormat:@"Remaining levels of %@ are locked. Do you want to unlock remaining levels?",monumentName];
                UIAlertView *myalertView = [[UIAlertView alloc]initWithTitle:@"Oops!"
                                                                     message:strMessage  delegate:self cancelButtonTitle:@"No, Thanks" otherButtonTitles:@"Yes, Sure", nil];
                [myalertView setTag:200];
                [myalertView show];
            }
            
        } failureBlock:^{
            return;
        }];
    }else
    {
        [[PMParentalGateQuestion sharedGate] presentGateWithText:@"You're trying to access a parents only area. Prove you're not a kiddo by solving the following problem."  finishedBlock:^(BOOL allowPass, GateResult result) {
            
            if(result==GR_GOOD){
                
                [MKParentalGate dismiisViewController:[MoreAppsViewController topViewController]];
                
                if(monumentNameStr==nil)
                    monumentNameStr = [[NSString alloc]initWithString:monumentName];
                else
                    monumentNameStr = [NSString stringWithFormat:@"%@",monumentName];
                if(isAnyLevelCleared==false){
                    NSString *strMessage = [NSString stringWithFormat:@"All levels of %@ are locked. Do you want to unlock all levels?",monumentName];
                    UIAlertView *myalertView = [[UIAlertView alloc]initWithTitle:@"Oops!"
                                                                         message:strMessage delegate:self cancelButtonTitle:@"No, Thanks" otherButtonTitles:@"Yes, Sure", nil];
                    [myalertView setTag:1000];
                    [myalertView show];
                }
                else if(isAnyLevelCleared==true){
                    NSString *strMessage = [NSString stringWithFormat:@"Remaining levels of %@ are locked. Do you want to unlock remaining levels?",monumentName];
                    UIAlertView *myalertView = [[UIAlertView alloc]initWithTitle:@"Oops!"
                                                                         message:strMessage  delegate:self cancelButtonTitle:@"No, Thanks" otherButtonTitles:@"Yes, Sure", nil];
                    [myalertView setTag:200];
                    [myalertView show];
                }
                
            }
            else if(result==GR_WRONG)
            {
                [[[UIAlertView alloc] initWithTitle:@"Wrong Answer"
                                            message:nil
                                           delegate:nil
                                  cancelButtonTitle:@"Ok"
                                  otherButtonTitles: nil] show];
                
            }
        }];
    }
}
-(void)alertForCoinsBuy
{
    NSString *strMessage = [NSString stringWithFormat:@"You do not have sufficient coins to upgrade.\nDo you want to buy 500 coins pack?"];
    UIAlertView *myalertView = [[UIAlertView alloc]initWithTitle:@"Oops!"
                                                         message:strMessage delegate:self cancelButtonTitle:@"No, Thanks" otherButtonTitles:@"Yes, Sure", nil];
    [myalertView setTag:300];
    [myalertView show];
}

- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex {
    switch ([alertView tag]) {
        case 1000:
            if(buttonIndex == 1) {
                [self dissmissTopViewFordisplayParentalGatesForInAppMonument];
                //                [self performSelector:@selector(dissmissTopViewFordisplayParentalGatesForInAppMonument) withObject:nil afterDelay:0.5];
            }
        case 200:
            if(buttonIndex == 1) {
                //                [MKParentalGate dismiisViewController:[MoreAppsViewController topViewController]];
                [self dissmissTopViewFordisplayParentalGatesForInAppMonument];
                
                //                [self performSelector:@selector(dissmissTopViewFordisplayParentalGatesForInAppMonument) withObject:nil afterDelay:0.5];
            }
            break;
        case 300:
            if(buttonIndex == 1) {
                InAppController *inAppObj = [[InAppController alloc]init];
                [inAppObj purchaseFiveHundredCoins];
            }
            break;
            
            
        default:
            break;
    }
}

- (void)openInAppScreen {
    
    if([monumentNameStr isEqualToString:@"EIFFEL TOWER"])
    {
        ObjCCalls::purchaseEffielTower();
    }
    else if ([monumentNameStr isEqualToString:@"STATUE OF LIBERTY"])
    {
        ObjCCalls::purchaseStatueueOfLiberty();
    }
    else if ([monumentNameStr isEqualToString:@"TOWER OF PISA"])
    {
        ObjCCalls::purchaseTowerOfPisa();
    }
    else if ([monumentNameStr isEqualToString:@"BIG BEN"])
    {
        ObjCCalls::purchaseBigBen();
    }
    else if ([monumentNameStr isEqualToString:@"COLOSSEUM"])
    {
        ObjCCalls::purchaseColosseum();
    }
    else if ([monumentNameStr isEqualToString:@"OPERA HOUSE"])
    {
        ObjCCalls::purchaseOperaHouse();
    }
    else if ([monumentNameStr isEqualToString:@"EASTER STONE"])
    {
        ObjCCalls::purchaseEasterStone();
    }
}

- (void)viewDidUnload
{
    [super viewDidUnload];
}
- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
}
- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
}
- (void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
}
- (void)viewDidDisappear:(BOOL)animated
{
    [super viewDidDisappear:animated];
}
- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return (interfaceOrientation != UIInterfaceOrientationPortraitUpsideDown);
}

@end
