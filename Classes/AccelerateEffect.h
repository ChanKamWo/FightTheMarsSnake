#ifndef ACCELERATE_EFFECT_H
#define ACCELERATE_EFFECT_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Effect.h"
#include "SnakeBase.h"

class AccelerateEffect : public Effect
{
public:
    AccelerateEffect();

    void work( SnakeBase* snake );

};
#endif
