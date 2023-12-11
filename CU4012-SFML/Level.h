#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput();
	void update();
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	// Add your object here

	sf::Font Mousefont;
	sf::Text MousePositiontext;
	sf::CircleShape circle;


	int x, y;

	sf::Vector2i InitialMousePosition;
	sf::Vector2i FinalMousePosition;
	bool dragging = false;
};