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

    for each ( SnakeBase* var in snakes )
    {
        if (var!=snake)
        {
            var->setSpeed( var->getSpeed() - 1 );
        }
    }
}
