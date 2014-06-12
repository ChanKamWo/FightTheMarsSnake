#ifndef __SNAKE_BASE_H__
#define __SNAKE_BASE_H__

#include "cocos2d.h"
#include <vector>
#include "AppMacros.h"

USING_NS_CC;

class Food;
class SnakeNode;
class PlayScene;

class SnakeBase : public Node{
public:
	void setSpeed(float speed);
	float getSpeed(){return speed;}
	void sleep(float t);
	int getClassifier(){return classifier;}
	void setScore(int score){this->score = score;}
	int getScore(){return score;}
	std::vector<SnakeNode*> getSnakeNodes(){return snakeNodes;}
	void move(float dt);
	void eat(Food* food);
	virtual int getNextDirection(){return 0;}

	CREATE_FUNC(SnakeBase);

protected:
	int score;
	float speed;
	int classifier;
	PlayScene* scene;
	std::vector<SnakeNode*> snakeNodes;
};

#endif