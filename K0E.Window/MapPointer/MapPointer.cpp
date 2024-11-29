#include "MapPointer.h"

// Constructor 
MapPointer::MapPointer(float X, float Y)
{
	// Load all textures to sprites 
	Texture.loadFromFile("Data/Textures/UI/MapPointer.png");
	Sprite.setTexture(Texture);

	// Set X & Y 
	SetXY(X, Y);
}

// Get X (link) 
float& MapPointer::GetX()
{
	return X;
}

// Get Y (link) 
float& MapPointer::GetY()
{
	return Y;
}

// Set X & Y 
void MapPointer::SetXY(float X, float Y)
{
	this->X = X;
	this->Y = Y;
}

// Draw 
void MapPointer::Draw(sf::RenderWindow& Render, float CameraX, float CameraY, float CameraW, float CameraH, std::vector< std::vector<MapBlock> >& BlocksVector, size_t NewDelay)
{
	//
	if (Drawing == true)
	// Optimize 
	if ((X/32 >= size_t(CameraX/32) || CameraX <= 0) && (Y/32 >= size_t(CameraY/32) || CameraY <= 0) &&
		 X/32 <= size_t((CameraX+CameraW)/32) && Y/32 <= size_t((CameraY+CameraH)/32))
	{
		//
		Sprite.setPosition(X, Y);
			
		if (Count <= 2)
		{ 
			if (Delay >= 5)
			{
				Count++;
				Delay = 0;
			}
			else
				Delay += NewDelay;
		}
		else
			Count = 0;

		Rect = sf::IntRect((XAdd+Count)*32, 0, 32, 32);

		Sprite.setTextureRect(Rect);
		Render.draw(Sprite);
	}
	//
}