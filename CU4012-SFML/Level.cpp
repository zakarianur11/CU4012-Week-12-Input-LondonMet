#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

	// Render text 
	if (!Mousefont.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading font/n";
	}

	MousePositiontext.setFont(Mousefont);
	MousePositiontext.setCharacterSize(24);
	MousePositiontext.setFillColor(sf::Color::Red);
	input->setMouseLDown(false);
	input->setMouseRDown(false);

	circle.setRadius(15);
	circle.setFillColor(sf::Color::Red);
	circle.setPosition(-100,-100);

	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(2.f);
}


Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{
	sf::Vector2i MousePos = sf::Vector2i(input->getMouseX(), input->getMouseY());
	std::string MousePosString = std::to_string(MousePos.x);
	MousePosString.append(":");
	MousePosString.append(std::to_string(MousePos.y));
	MousePositiontext.setString(MousePosString);

	// if space is pressed output to console
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		input->setKeyUp(sf::Keyboard::Space);
		std::cout << "Space was pressed\n";
	}

	if (input->isKeyDown(sf::Keyboard::J) && input->isKeyDown(sf::Keyboard::K) && input->isKeyDown(sf::Keyboard::L))
	{
		input->setKeyUp(sf::Keyboard::J);
		input->setKeyUp(sf::Keyboard::K);
		input->setKeyUp(sf::Keyboard::L);


		std::cout << "J was pressed\n";
		std::cout << "K was pressed\n";
		std::cout << "L was pressed\n";
	}

	if (input->isKeyDown(sf::Keyboard::Escape))

	{
		input->setKeyUp(sf::Keyboard::Escape);
		window->close();
	}

	if (input->isMouseLDown())
	
	{
		if (!dragging)
		{
			dragging = true;
			InitialMousePosition = sf::Vector2i(input->getMouseX(), input->getMouseY());
		}
		else
		{
			FinalMousePosition = sf::Vector2i(input->getMouseX(), input->getMouseY());

			// Calculate distance using pythagoras theorem

			float dx = float(FinalMousePosition.x - InitialMousePosition.x);
			float dy = float(FinalMousePosition.y - InitialMousePosition.y);
			float distance = std::sqrt(dx * dx + dy * dy);
			
			std::cout << "Distance: " << distance << std::endl;
			
			
		}
	}
	else
	{
		dragging = false;
	}

	if (input->isMouseRDown())
	{
		circle.setPosition(input->getMouseX(), input->getMouseY());

	}
}

// Update game objects
void Level::update()
{
	
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(MousePositiontext);
	window->draw(circle);

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