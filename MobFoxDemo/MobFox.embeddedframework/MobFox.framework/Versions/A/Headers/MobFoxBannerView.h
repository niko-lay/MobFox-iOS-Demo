//
//  MobFoxBannerView.h
//  MobFoxSDKSource
//
//  Created by Michał Kapuściński on 04.05.2015.
//
//

#import <UIKit/UIKit.h>

@class MobFoxBannerView;

@protocol MobFoxBannerViewDelegate <NSObject>

- (NSString *)publisherIdForMobFoxBannerView:(MobFoxBannerView *)banner;

@optional

- (void)mobfoxBannerViewDidLoadMobFoxAd:(MobFoxBannerView *)banner;

- (void)mobfoxBannerViewDidFailToReceiveAdWithError:(NSError *)error;

- (void)mobfoxBannerViewActionWillPresent;

- (void)mobfoxBannerViewActionWillFinish;


@end

@interface MobFoxBannerView : UIView

@property (nonatomic, assign) IBOutlet __unsafe_unretained id <MobFoxBannerViewDelegate> delegate;

@property (nonatomic, assign) NSInteger adspaceWidth;
@property (nonatomic, assign) NSInteger adspaceHeight;

- (void)requestAd;

@end
