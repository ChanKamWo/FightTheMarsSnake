#include "MoveStrategy.h"
#include "PlayScene.h"
#include "AppMacros.h"
#include "Snake.h"
#include "SnakeNode.h"
#include "Food.h"
#include <cstring>

void AIStrategy::initMatrix(){
	memset(matrix, false, sizeof(matrix));
	auto map = myScene->getTiledMap();
	for(int i = 0;i < 15;i++){
		for(int j = 0;j < 25;j++){
			if(map->getLayer("obstacles")->getTileGIDAt(gridToTiledCoordinate(Position(i, j))) != 0)
				matrix[i][j] = true;
		}
	}
	auto snakes = myScene->getSnakes();
	for(auto snake : snakes){
		for(auto node : snake->getSnakeNodes()){
			auto pos = node->getGridPosition();
			matrix[pos.row][pos.col] = true;
		}
	}
}

int WanderStrategy::getNextDirection(){
	initMatrix();
	int i = rand(4);
	auto nodes = snake->getSnakeNodes();
	auto head = nodes[0];
	for(int j = 0;j < 4;j++, i = (i + 1) % 4){
		if(i == (head->getOrientation() + 2) % 4)continue;
		Position nextPos(head->getGridPosition().row + direction[i][0], head->getGridPosition().col + direction[i][1]);
		if(!matrix[nextPos.row][nextPos.col])
			return i;
	}
	return head->getOrientation();
}

int ManhattanDistStrategy::getNextDirection(){
	initMatrix();
	int i = rand(4);
	auto nodes = snake->getSnakeNodes();
	auto head = nodes[0];
	int nextDir = -1, dist = 0xfffffff;
	for(int j = 0;j < 4;j++, i = (i + 1) % 4){
		if(i == (head->getOrientation() + 2) % 4)continue;
		Position nextPos(head->getGridPosition().row + direction[i][0], head->getGridPosition().col + direction[i][1]);
		if(!matrix[nextPos.row][nextPos.col] && dist > calcManhattanDist(nextPos, myScene->getFood()->getGridPosition())){
			nextDir = i;
			dist = calcManhattanDist(nextPos, myScene->getFood()->getGridPosition());
		}
	}
	return nextDir;
}

int ManhattanDistStrategy::calcManhattanDist(Position pos1, Position pos2){
	return abs(pos1.row - pos2.row) + abs(pos1.col - pos2.col);
}

int HumanControlStrategy::getNextDirection(){
	auto nextDir = myScene->getNextDir();
	myScene->resetNextDir();
	return nextDir;
}