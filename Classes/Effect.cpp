#include "Effect.h"
#include "Snake.h"
#include "SnakeNode.h"

void SlowDownEffect::work( PlayScene* scene, Snake* snake ){
	snake->setSpeed(snake->getSpeed() / 2, 5);
}
void SpeedUpEffect::work(PlayScene* scene, Snake* snake){
	if(snake->getSpeed() <= 7)
		snake->setSpeed(snake->getSpeed() + 2, 5);
}

void FrozenEffect::work(PlayScene* scene, Snake* snake ){
	snake->frozen(5.0);
}

void SlimEffect::work(PlayScene* scene, Snake* snake){
	if(snake->getSnakeNodes().size() >= 4){
		snake->slim(snake->getSnakeNodes().size() / 2);
	}else if(snake->getSnakeNodes().size() >= 3){
		snake->slim(1);
	}
}