#include "Effect.h"
#include "Snake.h"
#include "SnakeNode.h"
#include "PlayScene.h"
#include "AppMacros.h"
#include "MoveStrategy.h"
#include <vector>

using namespace std;

void SlowDownEffect::work( PlayScene* scene, Snake* snake ){
	snake->setSpeed(snake->getSpeed() / 2, 5);
}
void SpeedUpEffect::work(PlayScene* scene, Snake* snake){
	if(snake->getSpeed() <= 7)
		snake->setSpeed(snake->getSpeed() + 2, 5);
}

void FrozenEffect::work(PlayScene* scene, Snake* snake ){
	snake->frozen(5.0);
}

void SlimEffect::work(PlayScene* scene, Snake* snake){
	if(snake->getSnakeNodes().size() >= 4){
		snake->slim(snake->getSnakeNodes().size() / 2);
	}else if(snake->getSnakeNodes().size() >= 3){
		snake->slim(1);
	}
}

void BreakupEffect::work(PlayScene* scene, Snake* snake){
	auto nodes = snake->getSnakeNodes();
	if(nodes.size() >= 4){
		vector<Position> newPos;
		for(int i = nodes.size() / 2;i < nodes.size();i++)
			newPos.push_back(nodes[i]->getGridPosition());
		auto newSnake = Snake::createSnake(scene, snake->getName(), newPos, nodes[nodes.size() / 2]->getOrientation());
		snake->slim(nodes.size() - nodes.size() / 2);
		scene->addSnake(newSnake);
		auto strategy = new ManhattanDistStrategy(newSnake, scene);
		newSnake->setStrategy(strategy);
		newSnake->setSpeed(1.0);
		newSnake->sleep(3.0);
	}
}