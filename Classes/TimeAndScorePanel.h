#ifndef __SCORE_PANEL_H__
#define __SCORE_PANEL_H__

#include "cocos2d.h"

using namespace cocos2d;

class TimeAndScorePanel : public Node
{
private :
	Label *timeLabel;
	Label *earthSnakeScoreLabel;
	Label *marsSnakeScoreLabel;
	long long gameTime ;

public:
	Label * getTimeLabel()				{return this->timeLabel;}
	Label * getEarthSnakeScoreLabel()	{return this->earthSnakeScoreLabel;}
	Label * getMarsSnakeScoreLabel()	{return this->marsSnakeScoreLabel;}
	static TimeAndScorePanel * create();
	void setEarthSnakeScore(int score);
	void setMarsSnakeScore(int score);
	TimeAndScorePanel(void);
	~TimeAndScorePanel(void);
	void step(float dt);
	void start();
	bool init();
};

#endif