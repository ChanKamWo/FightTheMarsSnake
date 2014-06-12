#include "SnakeBase.h"
#include "SnakeNode.h"

void SnakeBase::setSpeed(float speed){
	schedule(schedule_selector(SnakeBase::move), 1 / speed);
	this->speed = speed;
}

void SnakeBase::sleep(float t){
	unschedule(schedule_selector(SnakeBase::move));
	schedule(schedule_selector(SnakeBase::move), 1 / speed, kRepeatForever, t);
}

void SnakeBase::move(float dt){
	//移动
	for(int i = snakeNodes.size() - 1;i > 0;i--){
		snakeNodes[i]->setGridPosition(snakeNodes[i - 1]->getGridPosition());
		snakeNodes[i]->setOrientation(snakeNodes[i - 1]->getOrientation());
	}
	int dir = getNextDirection();
	snakeNodes[0]->setOrientation(dir);
	snakeNodes[0]->setGridPosition(Position(snakeNodes[0]->getGridPosition().row + direction[dir][0], snakeNodes[0]->getGridPosition().col + direction[dir][1]));
	//判断有无吃到食物
}

void SnakeBase::eat(Food* food){

}