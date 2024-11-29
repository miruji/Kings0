#pragma once
#include "../Macro.h"
#include "../K0E.Map/Maps/MapBlock/MapBlock.h"

// Window cursor 
class K0E_Window_Api MapPointer
{
private:
	// Texture & sprite 
	sf::Texture Texture;
	sf::Sprite Sprite;

	sf::IntRect Rect;
	size_t Count = 0;
	size_t Delay = 5;

	// X & Y
	float X = 0.0f, Y = 0.0f;

public:
	// Drawing ?
	bool Drawing = true;

	// XAdd 
	size_t XAdd = 0;

	// Constructor
	MapPointer(float X, float Y);

	// Get X (link)
	float& GetX();

	// Get Y (link)
	float& GetY();

	// Set X & Y 
	void SetXY(float X, float Y);

	// Draw 
	void Draw(sf::RenderWindow& Render, float CameraX, float CameraY, float CameraW, float CameraH, std::vector< std::vector<MapBlock> >& BlocksVector, size_t NewDelay);
};