#include "AppDelegate.h"
#include "HelloWorldScene.h"

USING_NS_CC;

/*
 iPhone
 7 Plus         1080 x 1920      414 x 736
 7               750 x 1334      375 x 667
 6 Plus/6S Plus	1080 x 1920      414 x 736
 6/6S            750 x 1334      375 x 667
 5               640 x 1136      320 x 568
 iPod Touch      640 x 1136      320 x 568
 iPad Pro       2048 x 2732     1024 x 1366
 
 Android
 Nexus 6P       1440 x 2560     411 x 731
 Nexus 5X       1080 x 1920     411 x 731
 Google Pixel	1080 x 1920     411 x 731
 Galaxy Note 5	1440 x 2560     480 x 853
 LG G5          1440 x 2560     480 x 853
 One Plus 3     1080 x 1920     480 x 853
 Galaxy S7      1440 x 2560     340 x 640
 Galaxy S7 Edge	1440 x 2560     411 x 731
 
 Tablets
 Nexus 7 (2013)	1200 x 1920     600 x 960
 Nexus 9        1536 x 2048     768 x 1024
 Galaxy Tab 10	 800 x 1280     800 x 1280

 */

static cocos2d::Size iphone6ResolutionSize = cocos2d::Size(1334, 750);
static cocos2d::Size iphone6plusResolutionSize = cocos2d::Size(1920 * 0.6f, 1080 * 0.6f);
static cocos2d::Size sevenInchResolutionSize = cocos2d::Size(1920 * 0.6f, 1200 * 0.6f);

static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);

static cocos2d::Size designResolutionSize = mediumResolutionSize;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate() 
{
}

// if you want a different context, modify the value of glContextAttrs
// it will affect all platforms
void AppDelegate::initGLContextAttrs()
{
    // set OpenGL context attributes: red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

// if you want to use the package manager to install more packages,  
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = GLViewImpl::createWithRect("Rogue 5.4", cocos2d::Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
#else
        glview = GLViewImpl::create("Rogue 5.4");
#endif
        director->setOpenGLView(glview);
    }

    // turn on display FPS
//    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0f / 60);

#if 0 // doesn't work well with tilemap?
    // Set the design resolution
    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
    auto frameSize = glview->getFrameSize();
    // if the frame's height is larger than the height of medium size.
    if (frameSize.height > mediumResolutionSize.height)
    {        
        director->setContentScaleFactor(MIN(largeResolutionSize.height/designResolutionSize.height, largeResolutionSize.width/designResolutionSize.width));
    }
    // if the frame's height is larger than the height of small size.
    else if (frameSize.height > smallResolutionSize.height)
    {        
        director->setContentScaleFactor(MIN(mediumResolutionSize.height/designResolutionSize.height, mediumResolutionSize.width/designResolutionSize.width));
    }
    // if the frame's height is smaller than the height of medium size.
    else
    {        
        director->setContentScaleFactor(MIN(smallResolutionSize.height/designResolutionSize.height, smallResolutionSize.width/designResolutionSize.width));
    }
#endif

    register_all_packages();

    // create a scene. it's an autorelease object
    auto scene = HelloWorld::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be paused
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
