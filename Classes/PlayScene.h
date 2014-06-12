#ifndef __PLAY_SCENE_H__
#define __PLAY_SCENE_H__

#include "cocos2d.h"
#include "AppMacros.h"
#include <vector>

class Food;
class Snake;

class PlayScene : public cocos2d::Layer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static node()" method manually
    CREATE_FUNC(PlayScene);

	static cocos2d::Scene* createScene();

	void setGrid(int r, int c, int id){matrix[r][c] = id;}
	int getGrid(int r, int c){if(r < TILE_MAP_ROW_SIZE && r >= 0 && c >= 0 && c < TILE_MAP_COL_SIZE){return matrix[r][c];}return -1;}
	Food* getFood(){return food;}
	std::vector<Snake*> getSnakes(){return snakes;}

private:
	cocos2d::TMXTiledMap *tiledMap;
	std::vector<Snake*> snakes;
	Food *food;
	int matrix[TILE_MAP_ROW_SIZE][TILE_MAP_COL_SIZE];
	Position tiledToGridCoordinate(cocos2d::Point);
	cocos2d::Point gridToTiledCoordinate(Position);
};

#endif // __PLAY_SCENE_H__
