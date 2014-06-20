#include "Snake.h"
#include "SnakeNode.h"
#include "MoveStrategy.h"
#include "PlayScene.h"

Snake* Snake::createSnake(PlayScene* scene, string name, vector<Position> positions, int orientation){
	auto snake = create();
	snake->originalSpeed = -1;
	snake->alive = true;
	snake->score = 0;
	snake->myName = name;
	snake->playScene = scene;
	snake->snakeNodes.push_back(SnakeNode::createSnakeNode(positions[0], orientation, name.substr(0, 1), SnakeNodeType::HEAD));
	auto last = positions.size() - 1;
	for(int i = 1;i < last;i++){
		for(int dir = 0;dir < 4;dir++){
			if(positions[i].row + direction[dir][0] == positions[i - 1].row && positions[i].col + direction[dir][1] == positions[i - 1].col){
				snake->snakeNodes.push_back(SnakeNode::createSnakeNode(positions[i], dir, name.substr(0, 1), SnakeNodeType::BODY));
				break;
			}
		}
	}
	if(last != 0){
		for(int dir = 0;dir < 4;dir++){
			if(positions[last].row + direction[dir][0] == positions[last - 1].row && positions[last].col + direction[dir][1] == positions[last - 1].col){
				snake->snakeNodes.push_back(SnakeNode::createSnakeNode(positions[last], dir, name.substr(0, 1), SnakeNodeType::TAIL));
				break;
			}
		}
	}
	for(auto node : snake->snakeNodes){
		snake->addChild(node);
	}
	return snake;
}

void Snake::setSpeed(float speed){
	if(originalSpeed == -1)
		originalSpeed = speed;
	schedule(schedule_selector(Snake::move), 1 / speed);
	this->speed = speed;
}

void Snake::setSpeed(float speed, float dt){
	setSpeed(speed);
	scheduleOnce(schedule_selector(Snake::revertSpeed), dt);
}

void Snake::revertSpeed(float dt){
	setSpeed(originalSpeed);
}

void Snake::sleep(float t){
	unschedule(schedule_selector(Snake::move));
	schedule(schedule_selector(Snake::move), 1 / speed, kRepeatForever, t);
}

void Snake::move(float dt){
	auto pos = snakeNodes[snakeNodes.size() - 1]->getGridPosition();
	
	tailPos = pos;
	tailOrien = snakeNodes[snakeNodes.size() - 1]->getOrientation();

	for(int i = snakeNodes.size() - 1;i > 0;i--){
		snakeNodes[i]->setGridPosition(snakeNodes[i - 1]->getGridPosition());
		snakeNodes[i]->setOrientation(snakeNodes[i - 1]->getOrientation());
	}

	auto dir = moveStrategy->getNextDirection();

	if(dir == -1 || snakeNodes[0]->getOrientation() == (dir + 2) % 4)
		dir = snakeNodes[0]->getOrientation();

	snakeNodes[0]->setOrientation(dir);
	pos = Position(snakeNodes[0]->getGridPosition().row + direction[dir][0], snakeNodes[0]->getGridPosition().col + direction[dir][1]);
	snakeNodes[0]->setGridPosition(pos);

	playScene->detectCollision(this);
}

void Snake::grow(){
	auto lastOne = snakeNodes[snakeNodes.size() - 1];
	auto lastButOne = snakeNodes[snakeNodes.size() - 2];
	auto snakeNode = SnakeNode::createSnakeNode(lastOne->getGridPosition(), lastOne->getOrientation(), myName.substr(0, 1), SnakeNodeType::BODY);
	addChild(snakeNode);
	lastOne->setOrientation(tailOrien);
	lastOne->setGridPosition(tailPos);
	snakeNodes.pop_back();
	snakeNodes.push_back(snakeNode);
	snakeNodes.push_back(lastOne);
}

void Snake::slim(int num){
	auto reserve = snakeNodes[snakeNodes.size() - 1];
	for(int i = 0;i < num;i++){
		if(i != 0)
			removeChild(snakeNodes[snakeNodes.size() - 1]);
		snakeNodes.pop_back();
	}
	reserve->setOrientation(snakeNodes[snakeNodes.size() - 1]->getOrientation());
	reserve->setGridPosition(snakeNodes[snakeNodes.size() - 1]->getGridPosition());
	removeChild(snakeNodes[snakeNodes.size() - 1]);
	snakeNodes.pop_back();
	snakeNodes.push_back(reserve);
}

void Snake::frozen(float t){
	for(auto snakeNode : snakeNodes){
		auto sprite = Sprite::create(snakesDirectory + "/ice.png");
		sprite->setPosition(snakeNode->getPosition());
		frozenImgs.push_back(sprite);
		addChild(sprite, 10);
	}
	sleep(t);
	scheduleOnce(schedule_selector(Snake::removeFrozenImage), t);
}

void Snake::removeFrozenImage(float dt){
	for(auto sprite : frozenImgs){
		removeChild(sprite);
	}
	frozenImgs.clear();
}