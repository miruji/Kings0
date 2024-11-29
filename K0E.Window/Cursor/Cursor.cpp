#include "Cursor.h"

// Constructor 
Cursor::Cursor(float X, float Y)
{
	// Set X & Y 
	SetXY(X, Y);
}

// Get cursor (link) 
sf::Cursor& Cursor::GetCursor()
{
	// ... 
	return Cursor1;
}

// Get X (link) 
float& Cursor::GetX()
{
	// ... 
	return X;
}

// Get Y (link) 
float& Cursor::GetY()
{
	// ... 
	return Y;
}

// Set X & Y 
void Cursor::SetXY(float X, float Y)
{
	// ... 
	this->X = X;
	this->Y = Y;
}

// Set cursor in window
void Cursor::SetCursorInWindow(sf::RenderWindow& Render, std::string Path, CursorType Type)
{
	// Set type 
	this->Type = Type;

	// Set cursor ... 
	if (Image.loadFromFile(Path))
		Cursor1.loadFromPixels(Image.getPixelsPtr(), Image.getSize(), sf::Vector2u(0, 0));
	else
		{ /* ... */}
	
	// To window 
	Render.setMouseCursor(Cursor1);
}