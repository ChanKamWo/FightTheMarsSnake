#ifndef MENU_SCENE_H
#define MENU_SCENE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "cocos2d.h"
USING_NS_CC;

class MenuScene : public Scene
{
private:
    void initBackground();
public:
    bool init();

    CREATE_FUNC( MenuScene );
};
#endif
