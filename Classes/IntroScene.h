#ifndef INTRO_SCENE_H
#define INTRO_SCENE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "cocos2d.h"
USING_NS_CC;

class IntroScene : public Scene
{
public:
    bool init();
    CREATE_FUNC( IntroScene );
};
#endif
