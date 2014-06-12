#ifndef EFFECT_H
#define EFFECT_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "SnakeBase.h"
#include "cocos2d.h"

class Effect : public Ref
{
protected:

    SnakeBase* targetSnake;

    float speedAddtion;

    volatile float scoreCut;

public:

    virtual void work( SnakeBase* snake ) = 0;

};
#endif
