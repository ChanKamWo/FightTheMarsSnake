#ifndef MENU_LAYER_H
#define MENU_LAYER_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include "cocos2d.h"
USING_NS_CC;
class MenuLayer : public Layer
{
private:
    void startCallback( Ref * pSender );
    void exitCallback( Ref* pSender );

public:
    bool init();

    CREATE_FUNC( MenuLayer );
};
#endif
