

#include "../Paddle/MyPaddle.h"


MyPaddle::MyPaddle() :
		Paddle() {

}

MyPaddle::~MyPaddle() {

}

MyPaddle* MyPaddle::createMyPaddle(std::string paddleName) {

	MyPaddle *myPaddle = new MyPaddle();
	if (myPaddle && myPaddle->initWithFile(paddleName.c_str())) {
		myPaddle->autorelease();
		return myPaddle;
	}
	CC_SAFE_DELETE(myPaddle);
	return NULL;

}

float MyPaddle::getWidth() {
	return this->getTextureRect().getMaxX();
}

float MyPaddle::getHeight() {
	return this->getTextureRect().getMaxY();
}



