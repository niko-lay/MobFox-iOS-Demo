//
//  InlineVideoAd.h
//  Test
//
//  Created by Itamar Nabriski on 6/4/15.
//  Copyright (c) 2015 Itamar Nabriski. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "WebViewJavascriptBridge.h"

@class InlineVideoAd;

@protocol InlineVideoDelegate <UIWebViewDelegate>

- (NSString *)publisherIdForInlineVideoAd:(InlineVideoAd *)banner;

@optional

- (void)InlineVideoAdDidLoadMobFoxAd:(InlineVideoAd *)banner;

- (void)InlineVideoAdDidFailToReceiveAdWithError:(NSError *)error;

- (void)InlineVideoAdClosed;

- (void)InlineVideoAdClicked;

@end

@interface InlineVideoAd : UIWebView

    @property (nonatomic, assign) id<InlineVideoDelegate> adDelegate;

    @property WebViewJavascriptBridge* bridge;
    @property NSString* longitude;
    @property NSString* latitude;
    @property NSString* demo_gender; //"m/f"
    @property NSString* demo_age;

- (NSString *)getIPAddress;
- (id) initWithFrame:(CGRect)aRect;
- (void) loadAd;

@end


