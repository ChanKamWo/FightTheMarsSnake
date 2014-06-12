#ifndef SCENAIRO_LAYER_H
#define SCENAIRO_LAYER_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "cocos2d.h"
USING_NS_CC;
class ScenairoLayer : public Layer
{
private:
    void transit( float interal );
public:
    bool init();

    CREATE_FUNC( ScenairoLayer );
};
#endif
