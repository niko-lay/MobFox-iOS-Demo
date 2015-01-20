import UIKit
import CoreLocation

class ViewController: UIViewController, MobFoxBannerViewDelegate, MobFoxVideoInterstitialViewControllerDelegate, CLLocationManagerDelegate {
    
    var bannerView: MobFoxBannerView!
    let videoInterstitialViewController = MobFoxVideoInterstitialViewController();
    let locationManager = CLLocationManager();

    override func viewDidLoad() {
        super.viewDidLoad()
        
        videoInterstitialViewController.delegate = self;
        
        self.view.addSubview(videoInterstitialViewController.view);
        
        locationManager.delegate = self; //optional, location is used for providing better targetted ads.
        locationManager.desiredAccuracy = kCLLocationAccuracyBest;
        locationManager.requestAlwaysAuthorization();
        locationManager.startUpdatingLocation();
        
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
    

    /*** delegate methods for banner ads ***/
    
    func publisherIdForMobFoxBannerView(banner: MobFoxBannerView!) -> String! {
        return "ENTER_PUBLISHER_ID_HERE";
    }
    
    func mobfoxBannerViewDidLoadMobFoxAd(banner: MobFoxBannerView!) {
        //position the banner correctly on the screen
        bannerView.center = CGPointMake(self.view.bounds.size.width/2.0, self.view.bounds.size.height - bannerView.bounds.size.height/2);
    }
    
    func mobfoxBannerViewDidLoadRefreshedAd(banner: MobFoxBannerView!) {
        //position the banner correctly on the screen
        bannerView.center = CGPointMake(self.view.bounds.size.width/2.0, self.view.bounds.size.height - bannerView.bounds.size.height/2);
    }
    
    func mobfoxBannerView(banner: MobFoxBannerView!, didFailToReceiveAdWithError error: NSError!) {
        NSLog("MobFox Banner: did fail to load ad: %@", error.localizedDescription);
    }
    
    func mobfoxBannerViewActionWillPresent(banner: MobFoxBannerView!) {
        NSLog("MobFox Banner: will present");
    }
    
    /*** delegate methods for fullscreen ads ***/
    func publisherIdForMobFoxVideoInterstitialView(videoInterstitial: MobFoxVideoInterstitialViewController!) -> String! {
        return "ENTER_PUBLISHER_ID_HERE";
    }
    
    func mobfoxVideoInterstitialViewDidLoadMobFoxAd(videoInterstitial: MobFoxVideoInterstitialViewController!, advertTypeLoaded advertType: MobFoxAdType) {
        videoInterstitial.presentAd(advertType);
    }
    
    func mobfoxVideoInterstitialView(videoInterstitial: MobFoxVideoInterstitialViewController!, didFailToReceiveAdWithError error: NSError!) {
        NSLog("MobFox Interstitial: did fail to load ad: %@", error.localizedDescription);
    }
    
    func mobfoxVideoInterstitialViewWasClicked(videoInterstitial: MobFoxVideoInterstitialViewController!) {
        NSLog("MobFox Interstitial: was clicked");
    }
    
    func mobfoxVideoInterstitialViewDidDismissScreen(videoInterstitial: MobFoxVideoInterstitialViewController!) {
        NSLog("MobFox Interstitial: did dismiss screen");
    }

    

    @IBAction func showBannerAd(sender: AnyObject) {
        if(bannerView == nil) {
            bannerView = MobFoxBannerView(frame: CGRectZero);
            bannerView.allowDelegateAssigmentToRequestAd = false; //use this if you don't want to trigger ad loading when setting delegate and intend to request it it manually
        
            bannerView.delegate = self;
        
            bannerView.backgroundColor = UIColor.clearColor();
        
            self.bannerView.autoresizingMask = UIViewAutoresizing.FlexibleWidth | UIViewAutoresizing.FlexibleTopMargin;
        
            self.view.addSubview(bannerView);
        
            bannerView.requestURL = "http://my.mobfox.com/request.php";

            if(UIDevice.currentDevice().userInterfaceIdiom != UIUserInterfaceIdiom.Pad)
            {
                bannerView.adspaceWidth = 320; //optional, used to set the custom size of banner placement. Without setting it, the SDK will use default sizes (320x50 for iPhone, 728x90 for iPad).
                bannerView.adspaceHeight = 50;
                
                bannerView.adspaceStrict = false; //optional, tells the server to only supply Adverts that are exactly of desired size. Without setting it, the server could also supply smaller Ads when no ad of desired size is available.
            }
            else
            {
                bannerView.adspaceWidth = 728;
                bannerView.adspaceHeight = 90;
                
                bannerView.adspaceStrict = true;
            }
            
            
            bannerView.userAge = 22; //optional, sends user's age
            bannerView.userGender = "female"; //optional, sends user's gender (allowed values: "female" and "male")
            
            bannerView.keywords = ["cars","finance"]; //optional, to send list of keywords (user interests) to ad server.

            if(locationManager.location != nil) {
                bannerView.locationAwareAdverts = true;
                bannerView.setLocationWithLatitude(CGFloat(locationManager.location.coordinate.latitude), longitude: CGFloat(locationManager.location.coordinate.longitude));
            }
            

        }

        bannerView.requestAd(); // Request a Banner Advert manually
    }

    @IBAction func showFullscreenAd(sender: AnyObject) {
        videoInterstitialViewController.requestURL = "http://my.mobfox.com/request.php";
        
        videoInterstitialViewController.enableInterstitialAds = true; //enabled by default. Allows the SDK to request static interstitial ads.
        videoInterstitialViewController.enableVideoAds = true; //disabled by default. Allows the SDK to request video fullscreen ads.
        videoInterstitialViewController.prioritizeVideoAds = true; //disabled by default. If enabled, indicates that SDK should request video ads first, and only if there is no video equest a static interstitial (if they are enabled).
        
        videoInterstitialViewController.userAge = 35; //optional, sends user's age
        videoInterstitialViewController.userGender = "male";  //optional, sends user's gender (allowed values: "female" and "male")

        self.videoInterstitialViewController.keywords = ["football", "sports"]; //optional, to send list of keywords (user interests) to ad server.
        
        videoInterstitialViewController.requestAd();
    }
    
    /*** delegate methods for location manager ***/
    func locationManager(manager: CLLocationManager!, didUpdateLocations locations: [AnyObject]!) {
        var locValue : CLLocationCoordinate2D = manager.location.coordinate;
        if(bannerView != nil) {
            bannerView.locationAwareAdverts = true;
            bannerView.setLocationWithLatitude(CGFloat(locValue.latitude), longitude: CGFloat(locValue.longitude));
        }
        
        videoInterstitialViewController.locationAwareAdverts = true;
        videoInterstitialViewController.setLocationWithLatitude(CGFloat(locValue.latitude), longitude: CGFloat(locValue.longitude));
       
    }
    
}

