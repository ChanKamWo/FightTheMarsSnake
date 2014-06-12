#ifndef NULL_EFFECT_H
#define NULL_EFFECT_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Effect.h"
#include "SnakeBase.h"

class NullEffect : public Effect
{
public:
    NullEffect();

    void work( SnakeBase* snake );

};
#endif
