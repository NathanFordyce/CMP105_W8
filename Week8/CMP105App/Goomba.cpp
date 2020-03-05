#include "Goomba.h"
Goomba::Goomba()
{

}

Goomba::~Goomba()
{

}

void Goomba::update(float dt)
{
	move(velocity * dt);

	if (getPosition().x < 0)
	{
		setPosition(0, getPosition().y);
		velocity.x = -velocity.x;

	}

	if (getPosition().x > 750)
	{
		setPosition(750, getPosition().y);
		velocity.x = -velocity.x;

	}
}

void Goomba::collisionResponse()
{
	velocity.x = -velocity.x;
}