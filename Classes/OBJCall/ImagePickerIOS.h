#ifndef __IMAGE_PICKER_IOS__
#define __IMAGE_PICKER_IOS__

#import <UIKit/UIKit.h>
#import "cocos2d.h"


@interface ImagePickerIOS : UIViewController<UINavigationControllerDelegate, UIImagePickerControllerDelegate, UIPopoverControllerDelegate,UIActionSheetDelegate>
{
    UIImage *image;
    UIImageView * imageView;
    UIButton * choosePhotoBtn;
    UIButton * takePhotoBtn;
    UIViewController *pictureController;
    NSString *monumentNameStr;
    BOOL isParenTalPuzzleSolved;
}

@property (nonatomic, strong)UIPopoverController *popupActivityView;
-(void) takePicture;
-(void) takePhoto;
-(void) cleanup;
-(UIImage*) getImage;
-(void)openAlert:(bool)allLocked monumentName:(NSString *)monumentName;
-(void)alertForCoinsBuy;
-(void)showPhotoLibrary:(id)pController;
-(BOOL)isCameraDeviceAvailable;
-(BOOL)isFrontCameraDeviceAvailable;
-(BOOL)isRearCameraDeviceAvailable;
-(void)displayParentalGatesForFB;
-(void)displayParentalGatesForTwitter;
-(void)displayParentalGatesForFeedBackForm;
-(void)displayParentalGatesForFollowUs;
-(void)displayParentalGatesForShare;
-(void)displayParentalGatesForRateUs;
-(void)displayParentalGatesForMoreApps;
-(void)displayParentalGatesForpurchaseEffielTower;
-(void)displayParentalGatesForunlockAllMonuments;
-(void)displayParentalGatesForpurchaseStatueueOfLiberty;
-(void)displayParentalGatesForpurchaseTowerOfPisa;
-(void)displayParentalGatesForpurchaseBigBen;
-(void)displayParentalGatesForpurchaseColosseum;
-(void)displayParentalGatesForpurchaseOperaHouse;
-(void)displayParentalGatesForpurchaseEasterStone;
-(void)displayParentalGatesForrestoreInAppPurchase;
-(void)displayParentalGatesForalertForCoinsBuy;
-(void)displayParentalGatesForpurchaseFiveHundredCoins;
-(void)OpenTwitterOrFaceBook:(NSString *)aStrURL;
-(void)openShareActivity;
-(void)dissmissTopViewForMoreApp;
-(void)onShareClickedFromMonuments;
-(void)dissmissTopViewForShare;
-(void)dissmissTopViewFordisplayParentalGatesForFeedBackForm;
-(void)dissmissTopViewFordisplayParentalGatesForInAppMonument;
-(void)dissmissTopViewFordisplayParentalGatesForFollowUs;
-(void)dissmissTopViewFordisplayParentalGatesForRateUs;

+ (ImagePickerIOS *) sharedObject;
@end

#endif  // __IMAGE_PICKER_IOS__