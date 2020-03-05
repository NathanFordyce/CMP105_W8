#include "Ball.h"

Ball::Ball()
{

}

Ball::~Ball()
{

}

void Ball::update(float dt)
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

void Ball::setVelocity(sf::Vector2f vel)
{
	velocity = vel;
}

void Ball::collisionResponse()
{
	velocity.x = -velocity.x;
}