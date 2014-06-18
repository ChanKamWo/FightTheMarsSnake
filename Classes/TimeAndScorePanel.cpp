#include "TimeAndScorePanel.h"
#include <string>
using std::string;

TimeAndScorePanel::TimeAndScorePanel(void)
{
}


TimeAndScorePanel::~TimeAndScorePanel(void)
{

}


TimeAndScorePanel * TimeAndScorePanel::create()
{
	TimeAndScorePanel * ret = new TimeAndScorePanel();
	if(ret && ret->init())
		return ret;
	return nullptr;
}


bool TimeAndScorePanel::init()
{
	Size size = Director::getInstance()->getWinSize();
	this->gameTime = 0;
	this->timeLabel	= Label::createWithBMFont("fonts/markerFelt.fnt", "Time 00:00");
	this->timeLabel->setPosition(Point(size.width-100,size.height-20));
	this->timeLabel->setOpacity(150);
	this->addChild(this->timeLabel);

	this->earthSnakeScoreLabel	= Label::createWithBMFont("fonts/markerFelt.fnt", "Earth Snake Score  : 0");
	this->earthSnakeScoreLabel->setPosition(Point(120,size.height-20));
	this->earthSnakeScoreLabel->setOpacity(150);
	this->addChild(this->earthSnakeScoreLabel);

	this->marsSnakeScoreLabel	= Label::createWithBMFont("fonts/markerFelt.fnt", "Mars Snake Score : 0");
	this->marsSnakeScoreLabel->setPosition(Point(120,size.height-60));
	this->marsSnakeScoreLabel->setOpacity(150);
	this->addChild(this->marsSnakeScoreLabel);

	return true;
}


void TimeAndScorePanel::step(float dt)
{
	char ret[] = {"00:00"};

	long long t = this->gameTime++;
	string show = string("Time ");
	if(t == 0)
		show += "00:00";
	else{
		int s = t % 60;
		int m = t / 60;

		ret[0] = m / 10 + '0', ret[1] = m % 10 + '0';

		ret[3] = s / 10 + '0', ret[4] = s % 10 + '0';
		show += string(ret);
	}
	this->timeLabel->setString(show.c_str());
}

void TimeAndScorePanel::setEarthSnakeScore(int score)
{
	char buffer[50];
	sprintf(buffer,"%s%d","Earth Snake Score  : ",score);

	this->earthSnakeScoreLabel->setString(buffer);
	this->earthSnakeScoreLabel->runAction(
		Sequence::create(ScaleTo::create(0.05f,0.8f,0.8f),ScaleTo::create(0.05f,0.5,0.5),ScaleTo::create(0.05f,1.0,1.0),
		NULL
		)
	);
}

void TimeAndScorePanel::setMarsSnakeScore(int score)
{
	char buffer[50];
	sprintf(buffer,"%s%d","Mars Snake Score  : ",score);
	this->marsSnakeScoreLabel->setString(buffer);
	this->marsSnakeScoreLabel->runAction(
		Sequence::create(ScaleTo::create(0.05f,0.8f,0.8f),ScaleTo::create(0.05f,0.5,0.5),ScaleTo::create(0.05f,1.0,1.0),
		NULL
		)
	);
}

void TimeAndScorePanel::start(){
	schedule(schedule_selector(TimeAndScorePanel::step), 1.0);
}