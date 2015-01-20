//
//  CunfigurePublishedIdsViewController.h
//  MobFoxDemo
//
//  Created by Michał Kapuściński on 09.12.2014.
//

#import <UIKit/UIKit.h>


@protocol ConfigurePublisherIdsControllerDelegate
-(void) configurePublisherIdsControllerIsDone;
@end


@interface ConfigurePublishedIdsViewController : UIViewController <UITextViewDelegate>

@property (nonatomic, strong) NSString* idForBanners;
@property (nonatomic, strong) NSString* idForInterstitials;
@property (nonatomic, strong) NSString* idForNativeAds;
@property (nonatomic, weak) id <ConfigurePublisherIdsControllerDelegate> delegate;

- (IBAction)doneButtonClicked:(id)sender;

@property (weak, nonatomic) IBOutlet UITextField *bannerIdTextField;
@property (weak, nonatomic) IBOutlet UITextField *interstitialIdTextField;
@property (weak, nonatomic) IBOutlet UITextField *nativeIdTextField;

@end
