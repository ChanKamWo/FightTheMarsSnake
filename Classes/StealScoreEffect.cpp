#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "StealScoreEffect.h"
#include "PlayScene.h"


StealScoreEffect::StealScoreEffect()
{
}

void StealScoreEffect::work( SnakeBase* snake )
{
	auto snakes = dynamic_cast<PlayScene*>( snake->getScene() )->getSnakes();
	auto enemy = snakes[0] == snake? snakes[1] : snakes[0];
	auto delta = enemy->getScore() / 5;
	enemy->setScore(enemy->getScore() - delta);
	snake->setScore(snake->getScore() + delta);
}
