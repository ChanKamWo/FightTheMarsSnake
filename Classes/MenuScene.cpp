#include "MenuScene.h"
#include "PlayScene.h"


bool MenuScene::init()
{
    if ( !Layer::init() ){
        return false;
    }
    initBackground();
    auto startMenuItem = MenuItemImage::create( "startgame.png", "startgame_selected.png", CC_CALLBACK_1( MenuScene::startCallback, this ) );
    auto endMenuItem = MenuItemImage::create( "exitgame.png", "exitgame_selected.png", CC_CALLBACK_1( MenuScene::exitCallback, this ) );
	
	Size appSize = Director::getInstance()->getWinSize();
	startMenuItem->setScale(MIN(appSize.width / 5 / startMenuItem->getContentSize().width, appSize.height / 5 / startMenuItem->getContentSize().height));
	endMenuItem->setScale(MIN(appSize.width / 5 / endMenuItem->getContentSize().width, appSize.height / 5 / endMenuItem->getContentSize().height));
    
	auto menu = Menu::create( startMenuItem, endMenuItem, NULL );
    menu->alignItemsHorizontally();
    menu->setPosition( Point( appSize.width / 2, appSize.height / 5 *2 ) );
    addChild( menu );

    return true;
}

void MenuScene::initBackground(){

    Sprite* bgImage = Sprite::create( "welcome.jpg" );
    Size appSize = Director::getInstance()->getWinSizeInPixels();
    bgImage->setScaleX( appSize.width / bgImage->getContentSize().width );
    bgImage->setScaleY( appSize.height / bgImage->getContentSize().height );
    bgImage->setPosition( Point( appSize.width / 2, appSize.height / 2 ) );

    addChild( bgImage );
}

Scene* MenuScene::createScene(){
	auto scene = Scene::create();
	scene->addChild(create());
	return scene;
}

void MenuScene::startCallback( Ref * pSender ){
	Director::getInstance()->replaceScene(TransitionProgressRadialCCW::create(1.0, PlayScene::createScene()));
}

void MenuScene::exitCallback( Ref* pSender ){
	Director::getInstance()->end();
}