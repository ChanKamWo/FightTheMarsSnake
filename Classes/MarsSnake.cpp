#include "MarsSnake.h"
#include "AppMacros.h"
#include "SnakeNode.h"
#include "PlayScene.h"
#include "Food.h"

MarsSnake* MarsSnake::createMarsSnake(PlayScene* ps, Position headPos, int ori, float speed){
	auto marsSnake = create();
	marsSnake->scene = ps;
	marsSnake->classifier = -1;
	marsSnake->score = 0;
	marsSnake->snakeNodes.push_back(SnakeNode::createSnakeNode(headPos, ori, marsSnake->classifier, SnakeNodeType::HEAD));
	marsSnake->snakeNodes.push_back(SnakeNode::createSnakeNode(Position(headPos.row - direction[ori][0], headPos.col - direction[ori][1])
		, ori, marsSnake->classifier, SnakeNodeType::BODY));
	marsSnake->snakeNodes.push_back(SnakeNode::createSnakeNode(Position(headPos.row - 2 * direction[ori][0], headPos.col - 2 * direction[ori][1])
		, ori, marsSnake->classifier, SnakeNodeType::TAIL));
	for(auto snakeNode : marsSnake->snakeNodes)
		marsSnake->addChild(snakeNode);
	marsSnake->setSpeed(speed);
	return marsSnake;
}

int MarsSnake::getNextDirection(){
	int i = rand(4), nextDirection = -1, dist;
	Position foodPos = scene->getFood()->getGridPosition();
	for(int j = 0;j < 4;j++, i = (i + 1) % 4){
		if(i == (snakeNodes[0]->getOrientation() + 2) % 4)continue;
		Position nextPos(snakeNodes[0]->getGridPosition().row + direction[i][0], snakeNodes[0]->getGridPosition().col + direction[i][1]);
		if(scene->getGrid(nextPos.row, nextPos.col) == 0){
			if(nextDirection == -1){
				nextDirection = i;
				dist = calcManhattanDistance(nextPos, foodPos);
			}else if(calcManhattanDistance(nextPos, foodPos) < dist){
				nextDirection = i;
				dist = calcManhattanDistance(nextPos, foodPos);
			}
		}
	}
	if(nextDirection == -1)
		nextDirection = snakeNodes[0]->getOrientation();
	return nextDirection;
}

int MarsSnake::calcManhattanDistance(Position posa, Position posb){
	return abs(posa.row - posb.row) + abs(posa.col - posb.col);
}