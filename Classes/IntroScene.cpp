#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "IntroScene.h"
#include "ScenairoLayer.h"


bool IntroScene::init()
{
    if (!Scene::init())
    {
        return false;
    }
    Layer* scenarioLayer = ScenairoLayer::create();
    addChild( scenarioLayer );

    return true;
}
