#ifndef STEAL_SCORE_EFFECT_H
#define STEAL_SCORE_EFFECT_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Effect.h"
#include "SnakeBase.h"

class StealScoreEffect : public Effect
{
public:
    StealScoreEffect();

    void work( SnakeBase* snake );

};
#endif
