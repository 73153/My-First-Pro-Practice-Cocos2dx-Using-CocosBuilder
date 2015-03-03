/*
 * EnemyPaddle.h
 *
 *  Created on: Sep 17, 2013
 *      Author: daniel
 */

#ifndef ENEMYPADDLE_H_
#define ENEMYPADDLE_H_

#include "cocos2d.h"
#include "../Paddle/Paddle.h"
#include "../Ball/Ball.h"

using namespace cocos2d;

class EnemyPaddle: public Paddle {
public:

	static EnemyPaddle* createEnemyPaddle();
	void myInit();
//	float getWidth();
//	float getHeight();

	b2Body* getEnemyPaddleBody();
	void setEnemyPaddleBody(b2Body* enemyPaddleBody);
	void move(Ball *ball, Ball *extraBall);
    void setEnemyPaddleLife(int life);

    
    CC_SYNTHESIZE(int, enemyPaddleLife, enemyPaddleLife);

private:
	EnemyPaddle();
	virtual ~EnemyPaddle();
	b2Body *enemyPaddleBody;
};

#endif /* ENEMYPADDLE_H_ */