#pragma once
#include "../Macro.h"

// Mouse class 
class K0E_Window_Api Mouse
{
private:
	// Mouse 
	sf::Mouse Mouse1;

public:
	// Constructor
	Mouse();

	// Get map position 
	sf::Vector2f GetMapPosition(sf::RenderWindow& Render);

	// Get UI position 
	sf::Vector2i GetUIPosition(sf::RenderWindow& Render);

	// Get mouse (link) 
	sf::Mouse& GetMouse();
};

