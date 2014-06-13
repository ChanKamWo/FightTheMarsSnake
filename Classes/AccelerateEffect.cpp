#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "AccelerateEffect.h"


AccelerateEffect::AccelerateEffect()
{
}

void AccelerateEffect::work( SnakeBase* snake )
{
    float origin = snake->getSpeed();
    if ( origin < 10 )
        snake->setSpeed( origin + 2 );
}
