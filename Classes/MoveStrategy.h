#ifndef __MOVE_STRATEGY_H__
#define __MOVE_STRATEGY_H__

#include "AppMacros.h"

class Snake;
class PlayScene;

class MoveStrategy{
public:
	MoveStrategy(PlayScene* scene) : myScene(scene){}
	virtual int getNextDirection() = 0;
protected:
	PlayScene *myScene;
};

class HumanControlStrategy : public MoveStrategy{
public:
	HumanControlStrategy(PlayScene* playScene) : MoveStrategy(playScene){}
	virtual int getNextDirection();
};

class AIStrategy : public MoveStrategy{
public:
	AIStrategy(PlayScene* scene) : MoveStrategy(scene){}
	virtual int getNextDirection() = 0;
protected:
	bool matrix[15][25];
	void initMatrix();
};

class WanderStrategy : public AIStrategy{
public:
	WanderStrategy(Snake* pSnake, PlayScene* playScene) : snake(pSnake), AIStrategy(playScene){}
	virtual int getNextDirection();
private:
	Snake* snake;
};

class ManhattanDistStrategy : public AIStrategy{
public:
	ManhattanDistStrategy(Snake* pSnake, PlayScene* playScene) : snake(pSnake), AIStrategy(playScene){}
	virtual int getNextDirection();
private:
	Snake* snake;
	int calcManhattanDist(Position, Position);
};

#endif