#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/Collision.h"
#include <string>
#include <iostream>
#include "Ball.h"
#include "Goomba.h"
#include "Paddle.h"
#include "PongBall.h"


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	Ball ball_1;
	Ball ball_2;
	
	sf::Texture beachball;

	Goomba goomba1;
	Goomba goomba2;

	sf::Texture goombaTexture;

	Paddle paddle1;
	Paddle paddle2;
	PongBall ball;

	//1200x675
};