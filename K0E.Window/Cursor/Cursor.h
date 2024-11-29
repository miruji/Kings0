#pragma once
#include "../Macro.h"

// CursorType
enum class K0E_Window_Api CursorType
{
	Basic,
	Fist
};

// Window cursor 
class K0E_Window_Api Cursor
{
private:
	// Cursor
	sf::Cursor Cursor1;
	sf::Image Image;

	// X & Y
	float X = 0.0f, Y = 0.0f;

public:
	// Constructor
	Cursor(float X, float Y);

	// Cursor type 
	CursorType Type = CursorType::Basic;

	// Get Cursor (link)
	sf::Cursor& GetCursor();

	// Get X (link)
	float& GetX();

	// Get Y (link)
	float& GetY();

	// Set X & Y 
	void SetXY(float X, float Y);

	// Set cursor in window
	void SetCursorInWindow(sf::RenderWindow& Render, std::string Path, CursorType Type);
};