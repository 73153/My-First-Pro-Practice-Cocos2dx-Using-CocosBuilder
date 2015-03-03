//
//  FeedbackViewController.h
//  IntuAlarm
//
//  Created by Henryp on 3/19/14.
//  Copyright (c) 2014 r3app. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GCPlaceholderTextView.h"
#import "NSData+Base64.h"
#import "AFHTTPRequestOperationManager.h"
#import "SVProgressHUD.h"


@interface FeedbackViewController : UIViewController <UITextFieldDelegate,UITextViewDelegate,UIActionSheetDelegate,UIImagePickerControllerDelegate,UINavigationControllerDelegate>
{
    IBOutlet UIImageView *imgViewBg;
    
    IBOutlet UITextField *txtName;
    IBOutlet UITextField *txtEmail;
    IBOutlet UITextField *txtSubject;
    IBOutlet UITextField *txtAreaCode;
    IBOutlet UITextField *txtPhoneNo;
    IBOutlet GCPlaceholderTextView *txtViewFeedback;
    IBOutlet UIScrollView *scrView;
    
    IBOutlet UIButton *btnAttachment1;
    IBOutlet UIButton *btnAttachment2;
    IBOutlet UIButton *btnAttachment3;
    
    IBOutlet UIButton *btnBack;
    IBOutlet UIButton *btnDone;
    IBOutlet UILabel *lblTitle;
    IBOutlet UILabel *lblPictureDesc;

    UIActionSheet *actsheet;
    UIButton *btnAttachment;
}

@property (nonatomic, retain) UIImagePickerController *imagePicker;
@property (nonatomic,assign)BOOL  shouldDismiss;

+ (void)present;

@end
