#ifndef __GAME_END_H__
#define __GAME_END_H__

#include "cocos2d.h"
#include <vector>

using namespace std;
USING_NS_CC;

class SnakeBase;

class GameEnd : public Layer{
public:
	static Scene* createWinScene(const vector<SnakeBase*>& snakes);
	static Scene* createLoseScene(const vector<SnakeBase*>& snakes);
	CREATE_FUNC(GameEnd);
};

#endif