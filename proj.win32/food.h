#ifndef __FOOD_H__
#define __FOOD_H__

#include <string>

#include "cocos2d.h"
USING_NS_CC;

class Effect;

class Food : public Sprite
{
private:
    Effect* effect;

    std::string foodType;
public:
    Effect* getEffect() const {
        return effect;
    }

    bool init();
    CREATE_FUNC( Food );
};
#endif