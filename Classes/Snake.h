#ifndef __SNAKE_H__
#define __SNAKE_H__

#include "cocos2d.h"
#include <vector>
#include <string>
#include "AppMacros.h"

USING_NS_CC;
using namespace std;

class SnakeNode;
class MoveStrategy;
class PlayScene;

class Snake : public Node{
public:
	static Snake* createSnake(PlayScene*, string, vector<Position>, int orientation);
	void setSpeed(float speed);
	void setSpeed(float speed, float dt);
	void revertSpeed(float dt);
	void sleep(float t);
	void move(float dt);
	void grow();
	void slim(int);
	void frozen(float t);
	void removeFrozenImage(float);
	
	void die(){alive = false;}
	bool isAlive(){return alive;}
	float getSpeed(){return speed;}
	string getName(){return myName;}
	void setScore(int score){this->score = score;}
	int getScore(){return score;}
	std::vector<SnakeNode*> getSnakeNodes(){return snakeNodes;}
	void setStrategy(MoveStrategy* strategy){moveStrategy = strategy;}
	~Snake(){delete moveStrategy;}
	CREATE_FUNC(Snake);

protected:
	MoveStrategy *moveStrategy;
	PlayScene* playScene;
	int score;
	float speed, originalSpeed;
	string myName;
	Position tailPos;
	int tailOrien;
	bool alive;
	std::vector<SnakeNode*> snakeNodes;
	std::vector<Sprite*> frozenImgs;
};

#endif