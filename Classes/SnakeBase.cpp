#include "SnakeBase.h"
#include "SnakeNode.h"
#include "PlayScene.h"
#include "GameEnd.h"
#include "Food.h"

void SnakeBase::setSpeed( float speed ){
    if ( speed > 10 )
    {
        this->speed = 10;
    }
    else{
        this->speed = speed;
    }
    schedule( schedule_selector( SnakeBase::move ), 1 / this->speed);
	
}

void SnakeBase::sleep(float t){
	unschedule(schedule_selector(SnakeBase::move));
	schedule(schedule_selector(SnakeBase::move), 1 / speed, kRepeatForever, t);
}

void SnakeBase::move(float dt){
	//移动
	auto pos = snakeNodes[snakeNodes.size() - 1]->getGridPosition();
	tailPos = snakeNodes[snakeNodes.size() - 1]->getGridPosition();
	tailOrien = snakeNodes[snakeNodes.size() - 1]->getOrientation();
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
	if(scene->getFood()->getGridPosition() == pos){
		log("eat");
		eat(scene->getFood());
        scene->eliminateFood();
		scene->addFood();
	}
}

void SnakeBase::eat(Food* food){
	food->getEffect()->work(this);
	score += 10;
	addTail();
}

void SnakeBase::addTail(){
	auto lastOne = snakeNodes[snakeNodes.size() - 1];
	auto lastButOne = snakeNodes[snakeNodes.size() - 2];
	auto snakeNode = SnakeNode::createSnakeNode(lastOne->getGridPosition(), lastOne->getOrientation(), classifier, SnakeNodeType::BODY);
	scene->addChild(snakeNode);
	lastOne->setOrientation(tailOrien);
	lastOne->setGridPosition(tailPos);
	scene->setGrid(lastOne->getGridPosition().row, lastOne->getGridPosition().col, classifier);
	snakeNodes.pop_back();
	snakeNodes.push_back(snakeNode);
	snakeNodes.push_back(lastOne);
}

void SnakeBase::removeBody(int num){
	for(size_t i = snakeNodes.size() - num;i < snakeNodes.size();i++)
		scene->setGrid(snakeNodes[i]->getGridPosition().row, snakeNodes[i]->getGridPosition().col, 0);
    for ( size_t i = snakeNodes.size() - num - 1; i < snakeNodes.size() - 1; i++ )
		scene->removeChild(snakeNodes[i]);
}