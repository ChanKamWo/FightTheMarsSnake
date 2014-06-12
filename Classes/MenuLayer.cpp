#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "MenuLayer.h"
#include "GameController.h"


bool MenuLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    auto welcomeBg = Sprite::create( "welcome.jpg" );
    Size appSize = Director::getInstance()->getOpenGLView()->getFrameSize();
    welcomeBg->setScaleX( appSize.width / welcomeBg->getContentSize().width );
    welcomeBg->setScaleY( appSize.height / welcomeBg->getContentSize().height );
    welcomeBg->setPosition( Point( appSize.width / 2, appSize.height / 2 ) );
    addChild( welcomeBg, 0 );

    auto startMenuItem = MenuItemImage::create( "startgame.png", "startgame_selected.png", CC_CALLBACK_1( MenuLayer::startCallback, this ) );
    auto endMenuItem = MenuItemImage::create( "exitgame.png", "exitgame_selected.png", CC_CALLBACK_1( MenuLayer::exitCallback, this ) );

    auto menu = Menu::create( startMenuItem, endMenuItem, NULL );
    menu->alignItemsHorizontally();
    menu->setPosition( Point( appSize.width / 2, appSize.height / 5 *2 ) );
    addChild( menu );
    return true;
}

void MenuLayer::startCallback( Ref * pSender ){
    GameController::getInstance()->startGame();
}

void MenuLayer::exitCallback( Ref* pSender ){
    GameController::getInstance()->exitGame();
}