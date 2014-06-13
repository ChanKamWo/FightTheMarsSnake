#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "FrozenEffect.h"


FrozenEffect::FrozenEffect()
{
}

void FrozenEffect::work( SnakeBase* snake )
{
    snake->sleep( 4.0 );
}
