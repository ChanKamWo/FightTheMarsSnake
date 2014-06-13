#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "SlimEffect.h"


SlimEffect::SlimEffect()
{
}

void SlimEffect::work( SnakeBase* snake )
{
	if(snake->getSnakeNodes().size() >= 6)
		snake->removeBody(3);
}
