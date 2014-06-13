#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "EffectFactory.h"
#include "NullEffect.h"
#include "SlowDownEffect.h"
#include "AccelerateEffect.h"
#include "FrozenEffect.h"
#include "SlimEffect.h"
#include "StealScoreEffect.h"
#include "TurnEffect.h"
#include "RandomNum.h"


Effect* EffectFactory::createRandomEffect()
{
    int region = nrand( 1, 100 );
    if ( region >= 1 && region <= 30 )
    {
        int val = nrand( 1, 100 );

        if ( val >= 1 && val <= 20 )
        {
            return createAccelerateEffect();
        }
        if ( val >= 21 && val <= 40 )
        {
            return createFrozenEffect();
        }
        if ( val >= 41 && val <= 60 )
        {
            return createSlimEffect();
        }
        if ( val >= 61 && val <= 80 )
        {
            return createSlowDownEffect();
        }
        if ( val >= 81 && val <= 90 )
        {
            return createTurnEffect();
        }
        if ( val >= 91 && val <= 100 )
        {
            return createStealScoreEffect();
        }
    }
    return createNullEffect();
}

Effect* EffectFactory::createNullEffect()
{
    return new NullEffect();
}

Effect* EffectFactory::createSlowDownEffect()
{
    return new SlowDownEffect();
}

Effect* EffectFactory::createAccelerateEffect()
{
    return new AccelerateEffect();
}

Effect* EffectFactory::createFrozenEffect()
{
    return new FrozenEffect();
}

Effect* EffectFactory::createSlimEffect()
{
    return new SlimEffect();
}

Effect* EffectFactory::createStealScoreEffect()
{
    return new StealScoreEffect();
}

Effect* EffectFactory::createTurnEffect()
{
    return new TurnEffect();
}
