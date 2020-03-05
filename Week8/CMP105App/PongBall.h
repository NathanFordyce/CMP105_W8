#pragma once
#include "Framework/GameObject.h"
class PongBall:public GameObject
{
public:
	PongBall();
	~PongBall();

	void update(float dt) override;
	void collisionResponse();

	
};

