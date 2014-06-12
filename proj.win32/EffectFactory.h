#ifndef EFFECT_FACTORY_H
#define EFFECT_FACTORY_H

class Effect;

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