

#import <UIKit/UIKit.h>

enum {
    MobFoxErrorUnknown = 0,
    MobFoxErrorServerFailure = 1,
    MobFoxErrorInventoryUnavailable = 2,
};

@class MobFoxHTMLBannerView;

@protocol MobFoxHTMLBannerViewDelegate <NSObject>

- (NSString *)publisherIdForMobFoxHTMLBannerView:(MobFoxHTMLBannerView *)banner;

@optional

- (void)mobfoxHTMLBannerViewDidLoadMobFoxAd:(MobFoxHTMLBannerView *)banner;

- (void)mobfoxHTMLBannerViewDidLoadRefreshedAd:(MobFoxHTMLBannerView *)banner;

- (void)mobfoxHTMLBannerView:(MobFoxHTMLBannerView *)banner didFailToReceiveAdWithError:(NSError *)error;

- (BOOL)mobfoxHTMLBannerViewActionShouldBegin:(MobFoxHTMLBannerView *)banner willLeaveApplication:(BOOL)willLeave;

- (void)mobfoxHTMLBannerViewActionWillPresent:(MobFoxHTMLBannerView *)banner;

- (void)mobfoxHTMLBannerViewActionWillFinish:(MobFoxHTMLBannerView *)banner;

- (void)mobfoxHTMLBannerViewActionDidFinish:(MobFoxHTMLBannerView *)banner;

- (void)mobfoxHTMLBannerViewActionWillLeaveApplication:(MobFoxHTMLBannerView *)banner;

@end

@interface MobFoxHTMLBannerView : UIView 
{
	NSString *advertisingSection;
	BOOL bannerLoaded;
	BOOL bannerViewActionInProgress;

	BOOL _tapThroughLeavesApp;
	BOOL _shouldScaleWebView;
	BOOL _shouldSkipLinkPreflight;
	BOOL _statusBarWasVisible;
	NSURL *_tapThroughURL;
    NSInteger _refreshInterval;
	NSTimer *_refreshTimer;

}

@property (nonatomic, assign) IBOutlet __unsafe_unretained id <MobFoxHTMLBannerViewDelegate> delegate;
@property (nonatomic, copy) NSString *advertisingSection;
@property (nonatomic, assign) UIViewAnimationTransition refreshAnimation;

@property (nonatomic, assign) NSInteger adspaceWidth;
@property (nonatomic, assign) NSInteger adspaceHeight;
@property (nonatomic, assign) BOOL adspaceStrict;

@property (nonatomic, readonly, getter=isBannerLoaded) BOOL bannerLoaded;
@property (nonatomic, readonly, getter=isBannerViewActionInProgress) BOOL bannerViewActionInProgress;

@property (nonatomic, assign) BOOL refreshTimerOff;
@property (nonatomic, assign) NSInteger customReloadTime;
@property (nonatomic, retain) UIImage *_bannerImage;
@property (strong, nonatomic) NSString *requestURL;

@property (nonatomic, assign) NSInteger userAge;
@property (nonatomic, strong) NSString* userGender;
@property (nonatomic, retain) NSArray* keywords;

@property (nonatomic, assign) BOOL allowDelegateAssigmentToRequestAd;

@property (nonatomic, assign) BOOL locationAwareAdverts;


- (void)setLocationWithLatitude:(CGFloat)latitude longitude:(CGFloat)longitude;

- (void)requestAd;

@end

extern NSString * const MobFoxErrorDomain;