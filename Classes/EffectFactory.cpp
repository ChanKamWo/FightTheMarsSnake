#include "EffectFactory.h"
#include "Effect.h"
#include "AppMacros.h"

Effect* EffectFactory::createRandomEffect()
{
    int region = rand( 10 );
    if ( region <= 5 )
    {
        region = rand( 100 );
		if(region < 10){
			return createFrozenEffect();
		}else if(region < 40){
			return createSpeedUpEffect();
		}else if(region < 70){
			return createSlowDownEffect();
		}else if(region < 80){
			return createSlimEffect();
		}else{
			return createBreakupEffect();
		}
    }else
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

Effect* EffectFactory::createSpeedUpEffect()
{
    return new SpeedUpEffect();
}

Effect* EffectFactory::createFrozenEffect()
{
	return new FrozenEffect();
}

Effect* EffectFactory::createSlimEffect(){
	return new SlimEffect();
}

Effect* EffectFactory::createBreakupEffect(){
	return new BreakupEffect();
}