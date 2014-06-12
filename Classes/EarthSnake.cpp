#include "EarthSnake.h"
#include "AppMacros.h"
#include "SnakeNode.h"
#include "PlayScene.h"

USING_NS_CC;

EarthSnake* EarthSnake::createEarthSnake(PlayScene* ps, Position headPos, int ori, float speed){
	auto earthSnake = create();
	earthSnake->scene = ps;
	earthSnake->classifier = 1;
	earthSnake->score = 0;

	earthSnake->nextDir = ori;
	auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(EarthSnake::onKeyPressed, earthSnake);
	earthSnake->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, earthSnake);

	earthSnake->snakeNodes.push_back(SnakeNode::createSnakeNode(headPos, ori, earthSnake->classifier, SnakeNodeType::HEAD));
	earthSnake->snakeNodes.push_back(SnakeNode::createSnakeNode(Position(headPos.row - direction[ori][0], headPos.col - direction[ori][1])
		, ori, earthSnake->classifier, SnakeNodeType::BODY));
	earthSnake->snakeNodes.push_back(SnakeNode::createSnakeNode(Position(headPos.row - 2 * direction[ori][0], headPos.col - 2 * direction[ori][1])
		, ori, earthSnake->classifier, SnakeNodeType::TAIL));
	for(auto snakeNode : earthSnake->snakeNodes)
		earthSnake->addChild(snakeNode);
	earthSnake->setSpeed(speed);
	return earthSnake;
}

int EarthSnake::getNextDirection(){
	return nextDir;
}

void EarthSnake::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event){
	auto directing = snakeNodes[0]->getOrientation();
	switch(keyCode){
	case 23:
		nextDir = 2;
		break;
	case 25:
		nextDir = 3;
		break;
	case 24:
		nextDir = 0;
		break;
	default:
		nextDir = 1;
	}
	if(directing == (nextDir + 2) % 4)
		nextDir = directing;
	log("Key with keycode %d pressed", keyCode);
}