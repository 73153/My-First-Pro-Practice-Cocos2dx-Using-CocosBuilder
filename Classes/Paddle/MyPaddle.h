

#ifndef MYPADDLE_H_
#define MYPADDLE_H_
#include "cocos2d.h"
#include "../Paddle/Paddle.h"
using namespace cocos2d;
// #define MY_PADDLE_SCALE_X 0.3
// #define MY_PADDLE_SCALE_Y 0.5

class MyPaddle: public Paddle {
public:

	static MyPaddle* createMyPaddle(std::string paddleName);

	float getWidth();
	float getHeight();
protected:
	MyPaddle();
	virtual ~MyPaddle();

};

#endif /* MYPADDLE_H_ */
