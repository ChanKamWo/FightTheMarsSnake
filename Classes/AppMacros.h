#ifndef __APPMACROS_H__
#define __APPMACROS_H__

#include "cocos2d.h"
#include <ctime>
#include <cstdlib>

#define TILE_MAP_ROW_SIZE 15
#define TILE_MAP_COL_SIZE 25

USING_NS_CC;

struct Position{
	Position(int r = 0, int c = 0):row(r),col(c){}
	int row, col;
    bool operator == ( const Position pos ){
        return pos.row == row && pos.col == col;
    }
};

enum SnakeNodeType{
	HEAD,
	BODY,
	TAIL
};

static int rand(int x){
	srand((int)time(0));
	return rand() % x;
}

static Position tiledToGridCoordinate(cocos2d::Point pos){
	return Position(pos.y, pos.x);
}

static cocos2d::Point gridToTiledCoordinate(Position pos){
	return Point(pos.col, pos.row);
}

static const int direction[4][2] = {0,1,1,0,0,-1,-1,0};
static Size designResolutionSize = Size(800, 480);
static std::string mapsDirectory = "maps", snakesDirectory = "snakes", snakeNodeTypeString[3] = {"Head.png", "body.png", "tail.png"};

#endif /* __APPMACROS_H__ */
