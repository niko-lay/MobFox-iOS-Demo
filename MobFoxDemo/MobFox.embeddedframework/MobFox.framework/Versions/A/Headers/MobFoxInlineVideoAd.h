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


    @property (nonatomic, weak) id<MobFoxInlineVideoDelegate> adDelegate;

   
    @property (nonatomic, copy) NSString* longitude;
    @property (nonatomic, copy) NSString* latitude;
    @property (nonatomic, copy) NSString* demo_gender; //"m/f"
    @property (nonatomic, copy) NSString* demo_age;
    @property (nonatomic, copy) NSString* s_subid;
    @property (nonatomic, copy) NSString* sub_name;
    @property (nonatomic, copy) NSString* sub_domain;
    @property (nonatomic, copy) NSString* sub_storeurl;
    @property (nonatomic, copy) NSString* v_dur_min;
    @property (nonatomic, copy) NSString* v_dur_max;
    @property (nonatomic, copy) NSString* r_floor;
    @property (nonatomic, assign) BOOL autoplay;
    @property (nonatomic, assign) BOOL skip;


- (NSString *)getIPAddress;
- (id) initWithFrame:(CGRect)aRect;
- (void) loadAd;

@end


