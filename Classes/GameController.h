#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include "cocos2d.h"

USING_NS_CC;

class GameController : public Ref
{
public:
    static GameController* getInstance();

    void launchGame();

    void exitGame();

    void menu();

    void startGame();

    void pauseGame();

    void endGame();
private:
    static GameController* uniqueInstance;
};
#endif
