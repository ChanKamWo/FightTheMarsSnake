#ifndef MENU_SCENE_H
#define MENU_SCENE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "cocos2d.h"
USING_NS_CC;

class MenuScene : public Layer
{
private:
    void initBackground();
	void startCallback( Ref * pSender );
    void exitCallback( Ref* pSender );

public:
    bool init();
	static Scene* createScene();
    CREATE_FUNC( MenuScene );
};
#endif
