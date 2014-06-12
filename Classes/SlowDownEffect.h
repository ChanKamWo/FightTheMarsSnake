#ifndef SLOW_DOWN_EFFECT_H
#define SLOW_DOWN_EFFECT_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Effect.h"
#include "SnakeBase.h"

class SlowDownEffect : public Effect
{
public:
    SlowDownEffect();

    void work( SnakeBase* snake );

};
#endif
