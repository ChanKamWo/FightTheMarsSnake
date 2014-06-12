#ifndef EFFECT_FACTORY_H
#define EFFECT_FACTORY_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Effect.h"

class EffectFactory
{
public:
    static Effect* createRandomEffect();

    static Effect* createNullEffect();

    static Effect* createSlowDownEffect();

    static Effect* createAccelerateEffect();

    static Effect* createFrozenEffect();

    static Effect* createSlimEffect();

    static Effect* createStealScoreEffect();

    static Effect* createTurnEffect();

};
#endif
