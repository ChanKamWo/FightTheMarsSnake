#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "GameController.h"
#include "base\CCDirector.h"
#include "IntroScene.h"
#include "MenuScene.h"

USING_NS_CC;

GameController* GameController::uniqueInstance = NULL;

GameController* GameController::getInstance(){
    if ( !uniqueInstance )
    {
        uniqueInstance = new GameController();
    }
    return uniqueInstance;
}

void GameController::launchGame()
{
    Scene* introscene = IntroScene::create();
    Director::getInstance()->runWithScene( introscene );
}

void GameController::exitGame()
{
    Director::getInstance()->end();
    exit(0);
}

void GameController::menu(){
    Scene* introscene = MenuScene::create();
    auto transitions = TransitionMoveInL::create( 0.2f, introscene );
    Director::getInstance()->replaceScene( transitions );
}

void GameController::startGame()
{
}

void GameController::pauseGame()
{
}

