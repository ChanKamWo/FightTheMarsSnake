#ifndef __PLAY_SCENE_H__
#define __PLAY_SCENE_H__

#include "cocos2d.h"
#include "AppMacros.h"
#include <vector>

USING_NS_CC;
class Food;
class SnakeBase;

class PlayScene : public Layer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static node()" method manually
    CREATE_FUNC(PlayScene);

	static Scene* createScene();
	void addSnakeToMatrix(SnakeBase* snake);
	void stop();

	void setGrid(int r, int c, int id){matrix[r][c] = id;}
	int getGrid(int r, int c){if(r < TILE_MAP_ROW_SIZE && r >= 0 && c >= 0 && c < TILE_MAP_COL_SIZE){return matrix[r][c];}return -1;}
	Food* getFood(){return food;}
    void addFood();
    void eliminateFood();
	std::vector<SnakeBase*> getSnakes(){return snakes;}

private:
    SnakeBase* earthSnake;
    SnakeBase* marsSnake;
    Label* eSpeedLabel;
    Label* mSpeedLabel;
    Label* eScoreLabel;
    Label* mScoreLabel;

	TMXTiledMap *tiledMap;
	std::vector<SnakeBase*> snakes;
	Food *food;
	int matrix[TILE_MAP_ROW_SIZE][TILE_MAP_COL_SIZE];
	Position tiledToGridCoordinate(Point);
	Point gridToTiledCoordinate(Position);
    void createScoreLayer(  );
    void updateScore( float interval );
};

#endif // __PLAY_SCENE_H__
