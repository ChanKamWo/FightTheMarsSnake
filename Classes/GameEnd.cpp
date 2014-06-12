#include "GameEnd.h"
#include "SnakeBase.h"

Scene* GameEnd::createWinScene(const vector<SnakeBase*>& snakes){
	auto layer = create();
	auto sprite = Sprite::create("gamewin.png");
	auto size = Director::getInstance()->getVisibleSize();
	sprite->setPosition(size.width / 2, size.height / 2);
	sprite->setScale(size.width / sprite->getContentSize().width, size.height / sprite->getContentSize().height);
	layer->addChild(sprite);
	auto scene = Scene::create();
	scene->addChild(layer);
	return scene;
}

Scene* GameEnd::createLoseScene(const vector<SnakeBase*>& snakes){
	auto layer = create();
	auto sprite = Sprite::create("gameover.png");
	auto size = Director::getInstance()->getVisibleSize();
	sprite->setPosition(size.width / 2, size.height / 2);
	sprite->setScale(size.width / sprite->getContentSize().width, size.height / sprite->getContentSize().height);
	layer->addChild(sprite);
	auto scene = Scene::create();
	scene->addChild(layer);
	return scene;
}