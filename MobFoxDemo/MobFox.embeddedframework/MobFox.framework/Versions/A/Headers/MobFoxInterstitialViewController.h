//
//  MobFoxInterstitialViewController.h
//  MobFoxSDKSource
//
//  Created by Michał Kapuściński on 05.05.2015.
//
//

#import <UIKit/UIKit.h>

@protocol MobFoxInterstitialDelegate <NSObject>

- (NSString*)publisherIdForMobFoxInterstitial;

@optional

- (void)mobfoxInterstitialDidLoad;

- (void)mobfoxDidFailToLoadWithError:(NSError *)error;

- (void)mobfoxInterstitialWillPresent;

- (void)mobfoxInterstitialActionWillFinish;

@end

@interface MobFoxInterstitialViewController : NSObject

@property (nonatomic, assign) IBOutlet __unsafe_unretained id <MobFoxInterstitialDelegate> delegate;

- (instancetype)initWithViewController:(UIViewController*)controller;

- (void) requestAd;

- (void) showAd;

@end
