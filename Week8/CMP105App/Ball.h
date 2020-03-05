#pragma once
#include "Framework/GameObject.h"

class Ball: public GameObject
{
public:
	Ball();
	~Ball();

	void update(float dt) override;
	void setVelocity(sf::Vector2f vel);
	void collisionResponse();

	sf::Vector2f velocity;
};

