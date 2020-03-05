#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	////Task 2////
	beachball.loadFromFile("gfx/Beach_Ball.png");
	ball_1.setSize(sf::Vector2f(100, 100));
	ball_1.setPosition(100, 200);
	ball_1.setTexture(&beachball);
	ball_1.setVelocity(sf::Vector2f(100, 0));

	ball_2.setSize(sf::Vector2f(100, 100));
	ball_2.setPosition(700, 200);
	ball_2.setTexture(&beachball);
	ball_2.setVelocity(sf::Vector2f(-100, 0));
	////Task 3////
	goombaTexture.loadFromFile("gfx/Goomba.png");
	goomba1.setSize(sf::Vector2f(50, 50));
	goomba1.setCollisionBox(sf::FloatRect(0, 0, 50, 50));
	goomba1.setPosition(0, 200);
	goomba1.setVelocity(50, 0);
	goomba1.setTexture(&goombaTexture);

	goomba2.setSize(sf::Vector2f(50, 50));
	goomba2.setCollisionBox(sf::FloatRect(0, 0, 50, 50));
	goomba2.setPosition(750, 200);
	goomba2.setVelocity(50, 0);
	goomba2.setTexture(&goombaTexture);
	////Task 4/////
	paddle1.setSize(sf::Vector2f(20, 200));
	paddle1.setCollisionBox(sf::FloatRect(0, 0, 20, 200));
	paddle1.setPosition(20, 20);
	paddle1.setFillColor(sf::Color::Green);
	paddle1.setInput(input);
	
	paddle2.setSize(sf::Vector2f(20, 200));
	paddle2.setCollisionBox(sf::FloatRect(0, 0, 20, 200));
	paddle2.setPosition(1160, 20);
	paddle2.setFillColor(sf::Color::Green);
	paddle2.setInput(input);
	
	ball.setSize(sf::Vector2f(100, 100));
	ball.setOrigin(50, 50);
	ball.setPosition(600, 335);
	ball.setTexture(&beachball);
	ball.setVelocity(sf::Vector2f (100, -100));

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	ball_1.update(dt);
	ball_2.update(dt);

	if (Collision::checkBoundingCircle(&ball_1, &ball_2))
	{
		ball_1.collisionResponse();
		ball_2.collisionResponse();
	}

	goomba1.update(dt);
	goomba2.update(dt);

	if (Collision::checkBoundingBox(&goomba1, &goomba2))
	{
		goomba1.collisionResponse();
		goomba2.collisionResponse();
	}

	paddle1.update(dt);
	paddle2.update(dt);
	ball.update(dt);
	
}

// Render level
void Level::render()
{
	beginDraw();
	
	window->draw(paddle1);
	window->draw(paddle2);
	window->draw(ball);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}