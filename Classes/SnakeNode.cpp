#include "SnakeNode.h"

SnakeNode* SnakeNode::createSnakeNode(Position pos, int ori, int classifier, SnakeNodeType type){
	auto snakeNode = create();
	std::string file;
	if(classifier > 0)
		file = snakesDirectory + "/E" + snakeNodeTypeString[type];
	else
		file = snakesDirectory + "/M" + snakeNodeTypeString[type];
	snakeNode->setTexture(file);
	snakeNode->setGridPosition(pos);
	snakeNode->setOrientation(ori);
	return snakeNode;
}

void SnakeNode::setOrientation(int ori){
	setRotation(ori * 90);
	orientation = ori;
}

void SnakeNode::setGridPosition(Position pos){
	setPosition((pos.col + 0.5) * getContentSize().width, (TILE_MAP_ROW_SIZE - 0.5 - pos.row) * getContentSize().height);
	position = pos;
}