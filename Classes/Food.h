#ifndef FOOD_H
#define FOOD_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Effect.h"
#include "cocos2d.h"
USING_NS_CC;

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
