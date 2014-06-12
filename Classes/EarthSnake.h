#ifndef __EARTH_SNAKE_H__
#define __EARTH_SNAKE_H__

#include "SnakeBase.h"

class EarthSnake : public SnakeBase{
public:
	static EarthSnake* createEarthSnake(PlayScene* ps, Position headPos, int ori, float speed = 1);
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	int getNextDirection();

	CREATE_FUNC(EarthSnake);

protected:
	int nextDir;
};

#endif