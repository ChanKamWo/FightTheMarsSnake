#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "ScenairoLayer.h"
#include "GameController.h"


bool ScenairoLayer::init()
{
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    //initBackground
    Sprite* bgImage = Sprite::create( "scenario_bg.jpg" );
    Size appSize = Director::getInstance()->getWinSizeInPixels();
    bgImage->setScaleX( appSize.width / bgImage->getContentSize().width );
    bgImage->setScaleY( appSize.height / bgImage->getContentSize().height );
    bgImage->setPosition( Point( appSize.width / 2, appSize.height / 2 ) );

    this->addChild( bgImage );

    schedule( schedule_selector( ScenairoLayer::transit ), 2.0, 0, 1.0 );
        return true;
}


void ScenairoLayer::transit(float interal){
    GameController::getInstance()->menu();
}