#ifndef __PLAY_SCENE_H__
#define __PLAY_SCENE_H__

#include "cocos2d.h"
#include "AppMacros.h"
#include <vector>

using namespace std;
USING_NS_CC;

class Food;
class Snake;
class TimeAndScorePanel;

class PlayScene : public Layer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    void startGame();
	void addSnake(Snake* pSnake);
	void removeSnake(Snake*);
	virtual void onEnterTransitionDidFinish();
	void detectCollision(Snake*);
	void placeFood();
	void stop();
	void win(bool);
	void judge();
	void backToMenuCallBack(Ref*);

    // implement the "static node()" method manually
    CREATE_FUNC(PlayScene);
	int getNextDir(){return nextDir;}
	void resetNextDir(){nextDir = -1;}
	vector<Snake*> getSnakes(){return snakes;}
	TMXTiledMap* getTiledMap(){return tiledMap;}
	Food* getFood(){return food;}

	static cocos2d::Scene* createScene();

	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);


private:
	vector<Snake*> snakes;
	TMXTiledMap* tiledMap;
	Food* food;
	TimeAndScorePanel* panel;
	int nextDir;
};

#endif // __PLAY_SCENE_H__
