#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "MenuScene.h"
#include "MenuLayer.h"


bool MenuScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
    initBackground();
    Layer* menuLayer = MenuLayer::create();
    this->addChild( menuLayer );
    return true;
}

void MenuScene::initBackground(){
    Layer* backgroundLayer = Layer::create();

    Sprite* bgImage = Sprite::create( "welcome.jpg" );
    Size appSize = Director::getInstance()->getWinSizeInPixels();
    bgImage->setScaleX( appSize.width / bgImage->getContentSize().width );
    bgImage->setScaleY( appSize.height / bgImage->getContentSize().height );
    bgImage->setPosition( Point( appSize.width / 2, appSize.height / 2 ) );

    backgroundLayer->addChild( bgImage );
    this->addChild( backgroundLayer );
}
