#include "PlayScene.h"
#include "cocos2d.h"
#include "MarsSnake.h"

USING_NS_CC;

bool PlayScene::init(){
	if(!Layer::init())
		return false;
	tiledMap = TMXTiledMap::create(mapsDirectory + "/lvl1.tmx");
	addChild(tiledMap);
	for(int i = 0;i < TILE_MAP_ROW_SIZE;i++){
		for(int j = 0;j < TILE_MAP_COL_SIZE;j++){
			matrix[i][j] = tiledMap->getLayer("obstacles")->getTileGIDAt(gridToTiledCoordinate(Position(i,j)));
		}
	}
	addChild(MarsSnake::createMarsSnake(this, Position(3,3), 0, 10));
	return true;
}

Position PlayScene::tiledToGridCoordinate(Point pos){
	return Position(pos.y, pos.x);
}

Point PlayScene::gridToTiledCoordinate(Position pos){
	return Point(pos.col, pos.row);
}

Scene* PlayScene::createScene(){
	auto scene = Scene::create();
	scene->addChild(PlayScene::create());
	return scene;
}