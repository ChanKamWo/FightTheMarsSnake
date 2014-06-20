#ifndef EFFECT_H
#define EFFECT_H

#include "cocos2d.h"

USING_NS_CC;

class Snake;
class PlayScene;

class Effect
{
public:

    virtual void work(PlayScene* scene, Snake* snake ) = 0;
};

class NullEffect : public Effect
{
public:
	NullEffect(){}

	void work(PlayScene* scene, Snake* snake){}

};

class SlowDownEffect : public Effect
{
public:
	SlowDownEffect(){}

    void work( PlayScene* scene, Snake* snake);
};

class SpeedUpEffect : public Effect, private Node{
public:
	SpeedUpEffect(){}

    void work(PlayScene* scene, Snake* snake);
};

class FrozenEffect : public Effect{
public:
	FrozenEffect(){}

    void work(PlayScene* scene, Snake* snake);
};

class SlimEffect : public Effect{
public:
	SlimEffect(){}

	void work(PlayScene* scene, Snake* snake);
};

class BreakupEffect : public Effect{
public:
	void work(PlayScene* scene, Snake* snake);
};

#endif
