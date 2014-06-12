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
    int region = nrand( 1, 10 );
    if ( region >= 1 && region <= 3 )
    {
        int val = nrand( 1, 10 );
        switch ( val )
        {
            case 1:
            case 2:
                return createAccelerateEffect();
            case 3:
            case 4:
                return createFrozenEffect();
            case 5:
            case 6:
                return createSlimEffect();
            case 7:
            case 8:
                return createSlowDownEffect();
            case 9:
                return createTurnEffect();
            case 10:
                return createStealScoreEffect();
            default:
                break;
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
