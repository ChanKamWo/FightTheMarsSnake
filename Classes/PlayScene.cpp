#include "PlayScene.h"
#include "cocos2d.h"
#include "Snake.h"
#include "SnakeNode.h"
#include "AppMacros.h"
#include "MoveStrategy.h"
#include "Food.h"
#include "Effect.h"
#include "TimeAndScorePanel.h"
#include "MenuScene.h"

USING_NS_CC;

bool PlayScene::init(){
	if(!Layer::init())
		return false;

	nextDir = -1;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(PlayScene::onKeyPressed, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
#endif

	tiledMap = TMXTiledMap::create(mapsDirectory + "/lvl1.tmx");
	addChild(tiledMap);

	Position epositions[] = {Position(2, 4), Position(2, 3), Position(2, 2)};
	auto esnake = Snake::createSnake(this, "E1", vector<Position>(epositions, epositions + sizeof(epositions) / sizeof(Position)), 0);
	addSnake(esnake);
	auto estrategy = new HumanControlStrategy(this);
	esnake->setStrategy(estrategy);

	Position mpositions[] = {Position(12, 20), Position(12, 21), Position(12, 22)};
	auto msnake = Snake::createSnake(this, "M1", vector<Position>(mpositions, mpositions + sizeof(mpositions) / sizeof(Position)), 2);
	addSnake(msnake);
	auto mstrategy = new ManhattanDistStrategy(msnake, this);
	msnake->setStrategy(mstrategy);

	panel = TimeAndScorePanel::create();
	addChild(panel, 2);

	return true;
}


Scene* PlayScene::createScene(){
	auto scene = Scene::create();
	auto layer = PlayScene::create();
	scene->addChild(PlayScene::create());
	return scene;
}

void PlayScene::onEnterTransitionDidFinish(){
	startGame();
}

void PlayScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event){
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
	log("Key with keycode %d pressed", keyCode);
}

void PlayScene::addSnake(Snake* pSnake){
	snakes.push_back(pSnake);
	addChild(pSnake, 1.5);
}

void PlayScene::startGame(){
	panel->start();
	food = Food::create();
	placeFood();
	addChild(food);
	for(auto snake : snakes){
		snake->setSpeed(10);
	}
}

void PlayScene::detectCollision(Snake* pSnake){
	auto nodes = pSnake->getSnakeNodes();
	auto head = nodes[0];
	if(food->getGridPosition() == head->getGridPosition()){
		pSnake->setScore(pSnake->getScore() + 10);
		if(pSnake->getName().substr(0, 1) == "E"){
			panel->setEarthSnakeScore(pSnake->getScore());
		}else{
			panel->setMarsSnakeScore(pSnake->getScore());
		}
		pSnake->grow();
		auto effect = food->getEffect();
		effect->work(this, pSnake);
		removeChild(food);
		food = Food::create();
		placeFood();
		addChild(food);
		if(pSnake->getScore() >= 300){
			win(pSnake->getName().substr(0, 1) == "E");
		}
	}else{
		for(int i = 0;i < 15;i++){
			for(int j = 0;j < 25;j++){
				if(tiledMap->getLayer("obstacles")->getTileGIDAt(gridToTiledCoordinate(Position(i, j))) != 0){
					if(head->getGridPosition() == Position(i, j)){
						win(pSnake->getName().substr(0, 1) != "E");
						return;
					}
				}
			}
		}
		for(auto snake : snakes){
			for(auto node : snake->getSnakeNodes()){
				if(head != node && head->getGridPosition() == node->getGridPosition()){
					win(pSnake->getName().substr(0, 1) != "E");
					return;
				}
			}
		}
	}
}

void PlayScene::placeFood(){
	bool matrix[15][25];
	for(int i = 0;i < 15;i++){
		for(int j = 0;j < 25;j++){
			if(tiledMap->getLayer("obstacles")->getTileGIDAt(gridToTiledCoordinate(Position(i, j))) != 0){
				matrix[i][j] = true;
			}else{
				matrix[i][j] = false;
			}
		}
	}
	for(auto snake : snakes){
		for(auto node : snake->getSnakeNodes()){
			matrix[node->getGridPosition().row][node->getGridPosition().col] = true;
		}
	}
	vector<Position> vec;
	for(int i = 0;i < 15;i++){
		for(int j = 0;j < 25;j++){
			if(!matrix[i][j])
				vec.push_back(Position(i, j));
		}
	}
	food->setGridPosition(vec[rand(vec.size())]);
}

void PlayScene::stop(){
	panel->unscheduleAllSelectors();
	for ( auto snake : snakes ){
		snake->unscheduleAllSelectors();
    }
}

void PlayScene::win(bool flag){
	stop();
	string tip = flag? "You Win" : "You Lose";
	auto tipLabel = Label::createWithTTF(tip, "fonts/tahoma.ttf", 36);

	Size size = Director::getInstance()->getWinSize();
	tipLabel->setPosition(size.width / 2, size.height / 2 * 3);
	addChild(tipLabel, 2);

	auto back = MenuItemFont::create("Go Back", CC_CALLBACK_1(PlayScene::backToMenuCallBack, this));
	auto menu = Menu::create(back, NULL);
	menu->setPosition(size.width  - back->getContentSize().width / 2, back->getContentSize().height / 2);
	addChild(menu, 2);
	
	tipLabel->runAction(Sequence::create(MoveTo::create(0.4, Point(size.width / 2, size.height / 2.2)), MoveTo::create(0.2, Point(size.width / 2, size.height / 1.8)),
		MoveTo::create(0.2, Point(size.width / 2, size.height / 2)), NULL));
}

void PlayScene::backToMenuCallBack(Ref* sender){
	Director::getInstance()->replaceScene(MenuScene::createScene());
}