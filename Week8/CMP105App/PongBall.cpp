#include "PongBall.h"

PongBall::PongBall()
{
	
}

PongBall::~PongBall()
{

}

void PongBall::update(float dt)
{
	move(velocity * dt);

	if (getPosition().y > 625)
	{
		velocity.y = -velocity.y;
	}

	if (getPosition().y < 0)
	{
		velocity.y = velocity.y;
	}
}

void PongBall::collisionResponse()
{
	velocity.x = -velocity.x;
}