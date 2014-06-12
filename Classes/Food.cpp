#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Food.h"
#include "EffectFactory.h"

bool Food::init(){
    this->initWithFile( "food.png" );
    effect = EffectFactory::createRandomEffect();
    return true;
}
