#include "SnakeBase.h"
#include "SnakeNode.h"
#include "PlayScene.h"
#include "GameEnd.h"

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
	auto pos = snakeNodes[snakeNodes.size() - 1]->getGridPosition();
	scene->setGrid(pos.row, pos.col, 0);
	for(int i = snakeNodes.size() - 1;i > 0;i--){
		snakeNodes[i]->setGridPosition(snakeNodes[i - 1]->getGridPosition());
		snakeNodes[i]->setOrientation(snakeNodes[i - 1]->getOrientation());
	}
	auto dir = getNextDirection();
	snakeNodes[0]->setOrientation(dir);
	pos = Position(snakeNodes[0]->getGridPosition().row + direction[dir][0], snakeNodes[0]->getGridPosition().col + direction[dir][1]);
	snakeNodes[0]->setGridPosition(pos);
	
	//判断有无碰撞
	if(scene->getGrid(pos.row, pos.col) != 0){//die hard
		log("crash");
		scene->stop();
		if(classifier > 0)
			Director::getInstance()->replaceScene(GameEnd::createLoseScene(scene->getSnakes()));
		else
			Director::getInstance()->replaceScene(GameEnd::createWinScene(scene->getSnakes()));
	}

	scene->setGrid(pos.row, pos.col, classifier);

	//判断有无吃到食物
//	if(scene->getFood()){
		log("eat");
		
//	}
}

void SnakeBase::eat(Food* food){

}