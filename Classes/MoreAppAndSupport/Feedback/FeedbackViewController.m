//
//  FeedbackViewController.m
//  IntuAlarm
//
//  Created by Henryp on 3/19/14.
//  Copyright (c) 2014 r3app. All rights reserved.
//

#import "FeedbackViewController.h"
@interface FeedbackViewController ()

@end

@implementation FeedbackViewController

+ (void)present{
    FeedbackViewController *feedBack = [[FeedbackViewController alloc]init];
    [[self topViewController] presentViewController:feedBack animated:TRUE completion:nil];
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

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    [btnAttachment1.imageView setContentMode:UIViewContentModeScaleAspectFill];
    [btnAttachment2.imageView setContentMode:UIViewContentModeScaleAspectFill];
    [btnAttachment3.imageView setContentMode:UIViewContentModeScaleAspectFill];
    
    [txtViewFeedback setPlaceholder:@"Explain the issue"];
    [txtViewFeedback setPlaceholderColor:[[UIColor blackColor] colorWithAlphaComponent:1]];
    
    [txtName setValue:txtViewFeedback.placeholderColor forKeyPath:@"_placeholderLabel.textColor"];
    [txtEmail setValue:txtViewFeedback.placeholderColor forKeyPath:@"_placeholderLabel.textColor"];
    [txtAreaCode setValue:txtViewFeedback.placeholderColor forKeyPath:@"_placeholderLabel.textColor"];
    [txtPhoneNo setValue:txtViewFeedback.placeholderColor forKeyPath:@"_placeholderLabel.textColor"];
    [txtSubject setValue:txtViewFeedback.placeholderColor forKeyPath:@"_placeholderLabel.textColor"];
    
    [txtName setPlaceholder:@"Name"];
    [txtAreaCode setPlaceholder:@"Area"];
    [txtEmail setPlaceholder:@"Email"];
    [txtPhoneNo setPlaceholder:@"Number"];
    [txtSubject setPlaceholder:@"Subject"];
    
    [lblTitle setText:@"Get help"];
    [btnBack setTitle:@"Cancel" forState:UIControlStateNormal];
    [btnDone setTitle:@"Send" forState:UIControlStateNormal];
    
    actsheet = [[UIActionSheet alloc]initWithTitle:nil delegate:self cancelButtonTitle:@"Cancel" destructiveButtonTitle:nil otherButtonTitles:@"Select Image",@"Delete", nil];
    
   /* UISwipeGestureRecognizer *swipe = [[UISwipeGestureRecognizer alloc] initWithTarget:self action:@selector(handleSwipe:)];
    [swipe setDirection:UISwipeGestureRecognizerDirectionRight];
    [self.view addGestureRecognizer:swipe];*/
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleLightContent animated:YES];
    
   
}

- (IBAction)selectAttachment:(UIButton *)sender {
    btnAttachment = sender;
    [actsheet showFromRect:sender.frame inView:sender.superview animated:TRUE];
}

- (IBAction)btnbackPressed:(id)sender {
    [self dismissViewControllerAnimated:YES completion:nil];

}

- (void)handleSwipe:(UISwipeGestureRecognizer *)sender {
    if(sender.state == UIGestureRecognizerStateEnded) {
//        [self.navigationController popViewControllerAnimated:TRUE];
        [self dismissViewControllerAnimated:YES completion:nil];
    }
}


- (IBAction)btnDonePressed:(id)sender {
    if ([self isFormDataValid]) {
        [SVProgressHUD show];
        AFHTTPRequestOperationManager *manager = [AFHTTPRequestOperationManager manager];
        
        NSMutableArray *arrImages = [[NSMutableArray alloc]init];
        if (btnAttachment1.imageView.image) {
            NSData *data = UIImageJPEGRepresentation(btnAttachment1.imageView.image, 1.0);
            NSDictionary *dict = @{@"name":@"image1.jpg",@"type":@"jpg",@"strimage":[NSData base64forData:data]};
            [arrImages addObject:dict];
        }
        if (btnAttachment2.imageView.image) {
            NSData *data = UIImageJPEGRepresentation(btnAttachment2.imageView.image, 1.0);
            NSDictionary *dict = @{@"name":@"image2.jpg",@"type":@"jpg",@"strimage":[NSData base64forData:data]};
            [arrImages addObject:dict];
        }
        if (btnAttachment3.imageView.image) {
            NSData *data = UIImageJPEGRepresentation(btnAttachment3.imageView.image, 1.0);
            NSDictionary *dict = @{@"name":@"image3.jpg",@"type":@"jpg",@"strimage":[NSData base64forData:data] };
            [arrImages addObject:dict];
        }
        
        NSString *bundleName = [[[NSBundle mainBundle] infoDictionary]
                                objectForKey:@"CFBundleDisplayName"];
        NSString *appendableString = [NSString stringWithFormat:@"\n\nOS : iOS \nAPP : %@",bundleName];
        NSDictionary *parameters = @{@"name": txtName.text,
                                     @"email":txtEmail.text,
                                     @"phone":@"",
                                     @"message":[txtViewFeedback.text stringByAppendingString:appendableString],
                                     @"subject":[NSString stringWithFormat:@"New Support Request from %@",bundleName],
                                     @"attachments":arrImages};

        
//        NSDictionary *parameters = @{@"name": txtName.text, @"email":txtEmail.text,@"phone":@"1234567891",@"message":[txtViewFeedback.text stringByAppendingString:@"\n\nOS : iOS \nAPP : Convertr"],@"subject":@"" ,@"attachments":arrImages};
        
        [manager POST:@"http://appdatafog.com/support/services/register.php" parameters:parameters constructingBodyWithBlock:^(id<AFMultipartFormData> formData) {
            
        } success:^(AFHTTPRequestOperation *operation, id responseObject) {
            NSLog(@"Success: %@", responseObject);
            [SVProgressHUD dismiss];
            [self.navigationController popViewControllerAnimated:TRUE];
            [self dismissViewControllerAnimated:YES completion:nil];
        } failure:^(AFHTTPRequestOperation *operation, NSError *error) {
            NSLog(@"Error: %@", error);
            [SVProgressHUD dismiss];
//            [self.navigationController popViewControllerAnimated:TRUE];
//            [self dismissViewControllerAnimated:YES completion:nil];
        }];
    }
}


#pragma mark - Validation
- (BOOL)isFormDataValid {
    if (txtName.text.length==0) {
        [[[UIAlertView alloc]initWithTitle:nil message:@"Name should not be empty" delegate:nil cancelButtonTitle:@"Ok" otherButtonTitles:nil] show];
        return false;
    }else if (![self isValidEmail:txtEmail.text]){
        [[[UIAlertView alloc]initWithTitle:nil message:@"Please enter valid email address" delegate:nil cancelButtonTitle:@"Ok" otherButtonTitles:nil] show];
        return false;
    }/*else if ([txtAreaCode.text stringByAppendingString:txtPhoneNo.text].length != 0 && [txtAreaCode.text stringByAppendingString:txtPhoneNo.text].length<10){
        [[[UIAlertView alloc]initWithTitle:nil message:@"Please enter valid phone number" delegate:nil cancelButtonTitle:@"Ok" otherButtonTitles:nil] show];
        return false;
    }else if (txtSubject.text.length ==0){
        [[[UIAlertView alloc]initWithTitle:nil message:@"Subject should not be empty" delegate:nil cancelButtonTitle:@"Ok" otherButtonTitles:nil] show];
        return false;
    }*/
    else if (txtViewFeedback.text.length ==0){
        [[[UIAlertView alloc]initWithTitle:nil message:@"Feedback should not be empty" delegate:nil cancelButtonTitle:@"Ok" otherButtonTitles:nil] show];
        return false;
    }
    return TRUE;
}
-(BOOL)isValidEmail:(NSString *)email
{
	BOOL stricterFilter = YES;
	NSString *stricterFilterString = @"[A-Z0-9a-z._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{1,4}";
	NSString *laxString = @".+@.+\\.[A-Za-z]{2}[A-Za-z]*";
	NSString *emailRegex = stricterFilter ? stricterFilterString : laxString;
	NSPredicate *emailTest = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", emailRegex];
	return [emailTest evaluateWithObject:email];
}

#pragma mark - UIActionSheet Delegate
- (void)actionSheet:(UIActionSheet *)actionSheet didDismissWithButtonIndex:(NSInteger)buttonIndex {
//- (void)actionSheet:(UIActionSheet *)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex {
    if (buttonIndex == 0) {
        //select image
        _imagePicker = [[UIImagePickerController alloc]init];
        [_imagePicker setDelegate:self];
        [_imagePicker setSourceType:UIImagePickerControllerSourceTypeSavedPhotosAlbum];
        [self presentViewController:_imagePicker animated:TRUE completion:nil];
    }else if (buttonIndex == 1){
        // delete image
        [btnAttachment.imageView setImage:nil];
        [btnAttachment setImage:nil forState:UIControlStateNormal];
    }
}

#pragma mark - UIImagePicker Delegate
- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary *)info {

    UIImage *image = [info valueForKey:UIImagePickerControllerOriginalImage];
    NSData *data = UIImageJPEGRepresentation(image, 0.4);
    [btnAttachment setImage:[UIImage imageWithData:data] forState:UIControlStateNormal];
    [picker dismissViewControllerAnimated:TRUE completion:nil];
}

- (void)imagePickerControllerDidCancel:(UIImagePickerController *)picker {
    [picker dismissViewControllerAnimated:TRUE completion:nil];
}

-(BOOL)textFieldShouldReturn:(UITextField *)textField {
    [textField resignFirstResponder];
    return TRUE;
}

- (BOOL)textView:(UITextView *)textView shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text {
    if ([text isEqualToString:@"\n"]) {
        [textView resignFirstResponder];
        return false;
    }
    return TRUE;
}
/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
