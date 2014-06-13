#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "SlowDownEffect.h"
#include "PlayScene.h"

using namespace std;

SlowDownEffect::SlowDownEffect()
{
}

void SlowDownEffect::work( SnakeBase* snake )
{
    vector<SnakeBase*> snakes = dynamic_cast<PlayScene*>( snake->getParent() )->getSnakes();

    for ( SnakeBase* var : snakes )
    {
        if (var!=snake)
        {
			if(var->getSpeed() > 1)
	           var->setSpeed( var->getSpeed() - 2 );
        }
    }
}
