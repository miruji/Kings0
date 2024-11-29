#include "Mouse.h"

// Constructor
Mouse::Mouse() {
	//
}

// Get map position 
sf::Vector2f Mouse::GetMapPosition(sf::RenderWindow& Render)
{
	//
	return Render.mapPixelToCoords( Mouse1.getPosition(Render) );
}

// Get UI position 
sf::Vector2i Mouse::GetUIPosition(sf::RenderWindow& Render)
{
	//
	return sf::Mouse::getPosition(Render);
}

// Get mouse (link)
sf::Mouse& Mouse::GetMouse() 
{
	//
	return Mouse1;
}