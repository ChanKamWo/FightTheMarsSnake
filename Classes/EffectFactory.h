#ifndef EFFECT_FACTORY_H
#define EFFECT_FACTORY_H

#include "Effect.h"

class EffectFactory
{
public:
    static Effect* createRandomEffect();

    static Effect* createNullEffect();

    static Effect* createSlowDownEffect();

    static Effect* createSpeedUpEffect();

    static Effect* createFrozenEffect();

	static Effect* createSlimEffect();
};
#endif
