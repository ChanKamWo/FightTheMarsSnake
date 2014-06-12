#ifndef __SNAKE_NODE_H__
#define __SNAKE_NODE_H__

#include "cocos2d.h"
#include "AppMacros.h"

USING_NS_CC;

class SnakeNode : public Sprite{
public:
	static SnakeNode* createSnakeNode(Position pos, int ori, int classifier, SnakeNodeType type);
	void setOrientation(int ori);
	int getOrientation(){return orientation;}
	void setGridPosition(Position);
	Position getGridPosition(){return position;}
	
	CREATE_FUNC(SnakeNode);
	
private:
	int orientation;
	Position position;
};

#endif