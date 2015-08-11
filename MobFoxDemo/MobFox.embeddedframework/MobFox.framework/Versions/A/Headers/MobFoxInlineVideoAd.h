//
//  InlineVideoAd.h
//  Test
//
//  Created by Itamar Nabriski on 6/4/15.
//  Copyright (c) 2015 Itamar Nabriski. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "WebViewJavascriptBridge.h"

@class MobFoxInlineVideoAd;

@protocol MobFoxInlineVideoDelegate <UIWebViewDelegate>

- (NSString *)publisherIdForInlineVideoAd:(MobFoxInlineVideoAd *)banner;

@optional

- (void)InlineVideoAdDidLoadMobFoxAd:(MobFoxInlineVideoAd *)banner;

- (void)InlineVideoAdDidFailToReceiveAdWithError:(NSError *)error;

- (void)InlineVideoAdClosed;

- (void)InlineVideoAdClicked;

- (void)InlineVideoAdFinished;

@end

@interface MobFoxInlineVideoAd : UIWebView

    @property (nonatomic, assign) id<MobFoxInlineVideoDelegate> adDelegate;

    @property WebViewJavascriptBridge* bridge;
    @property NSString* longitude;
    @property NSString* latitude;
    @property NSString* demo_gender; //"m/f"
    @property NSString* demo_age;
    @property NSString* s_subid;
    @property NSString* sub_name;
    @property NSString* sub_domain;
    @property NSString* sub_storeurl;
    @property NSString* v_dur_min;
    @property NSString* v_dur_max;
    @property NSString* r_floor;
    @property BOOL autoplay;
    @property BOOL skip;


- (NSString *)getIPAddress;
- (id) initWithFrame:(CGRect)aRect;
- (void) loadAd;

@end


