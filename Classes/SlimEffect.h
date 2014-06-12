#ifndef SLIM_EFFECT_H
#define SLIM_EFFECT_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Effect.h"
#include "SnakeBase.h"

class SlimEffect : public Effect
{
public:
    SlimEffect();

    void work( SnakeBase* snake );

};
#endif
