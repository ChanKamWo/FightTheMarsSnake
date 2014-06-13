#ifndef FROZEN_EFFECT_H
#define FROZEN_EFFECT_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Effect.h"
#include "SnakeBase.h"

class FrozenEffect : public Effect
{
public:
    FrozenEffect();

    void work( SnakeBase* snake );
};
#endif
