//
//  ViewController.h
//

#import <UIKit/UIKit.h>
#import <MobFox/MobFox.h>
#import "ConfigurePublishedIdsViewController.h"

@interface ViewController : UIViewController <MobFoxVideoInterstitialViewControllerDelegate, MobFoxHTMLBannerViewDelegate, MobFoxNativeAdDelegate, UITableViewDelegate, UITableViewDataSource, ConfigurePublisherIdsControllerDelegate, InlineVideoDelegate,
    MobFoxBannerViewDelegate, MobFoxInterstitialDelegate>

@property (nonatomic, strong) MobFoxVideoInterstitialViewController *videoInterstitialViewController;

@property (strong, nonatomic) MobFoxHTMLBannerView *htmlBannerView;
@property (strong, nonatomic) InlineVideoAd *inlineVideoAd;

@property (nonatomic, strong) MobFoxBannerView *banner;
@property (nonatomic, strong) MobFoxInterstitialViewController *interstitial;
@property (nonatomic, strong) InlineVideoAd *InlineVideoAdView;


@property (strong, nonatomic) UIView *nativeAdView;
@property (strong, nonatomic) NSMutableArray *tableData;
@property (strong, nonatomic) MobFoxTableViewHelper *tableViewHelper;
@property (strong, nonatomic) MobFoxNativeAdController *nativeAdController;
@property (strong, nonatomic) ConfigurePublishedIdsViewController *configurePublishedIdsViewController;

- (IBAction)requestInterstitialAdvert:(id)sender;
- (IBAction)requestBannerAdvert:(id)sender;

- (IBAction)requestInlineVideoAdvert:(id)sender;
- (IBAction)requestWaterfallInterAdvert:(id)sender;
- (IBAction)requestWaterfallBannerAdvert:(id)sender;

- (IBAction)requestNativeAdvert:(id)sender;
- (IBAction)showTableViewWithNativeAds:(id)sender;
- (IBAction)showSingleNativeAd:(id)sender;
- (IBAction)showConfigDialog:(id)sender;


@property (weak, nonatomic) IBOutlet UITableView *tableViewWithAds;

@end
