//
// View controller used for setting of Publisher IDs
//

#import "ConfigurePublishedIdsViewController.h"

@interface ConfigurePublishedIdsViewController ()

@end

@implementation ConfigurePublishedIdsViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.bannerIdTextField.text = self.idForBanners;
    self.interstitialIdTextField.text = self.idForInterstitials;
    self.nativeIdTextField.text = self.idForNativeAds;
    
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

- (IBAction)doneButtonClicked:(id)sender {
    [self dismissViewControllerAnimated:YES completion:nil];
    
    self.idForBanners = self.bannerIdTextField.text;
    self.idForInterstitials = self.interstitialIdTextField.text;
    self.idForNativeAds = self.nativeIdTextField.text;

    [self.delegate configurePublisherIdsControllerIsDone];
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField
{
    [textField resignFirstResponder];
    return YES;
}



@end
