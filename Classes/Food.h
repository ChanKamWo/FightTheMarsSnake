#ifndef __FOOD_H__
#define __FOOD_H__

#include "cocos2d.h"
#include "AppMacros.h"

USING_NS_CC;

class Effect;

class Food : public Sprite
{
private:
    Effect* effect;
    std::string getFoodImage();
    Position position;
	int score;

public:
    Effect* getEffect() const {
        return effect;
    }
    void setGridPosition( Position );
    Position getGridPosition(){
        return position;
    }
	int getScore(){return score;}
    bool init();
    CREATE_FUNC( Food );
};
#endif
