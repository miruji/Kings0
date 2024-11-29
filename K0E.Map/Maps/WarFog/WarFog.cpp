#include "WarFog.h"

// Constructor 
WarFog::WarFog(vector< vector<MapBlock> >& BlocksVector)
{
	// Load all textures to sprites 
	Texture.loadFromFile("Data/Textures/Map/WarFog/WarFog.bmp");
	Sprite.setTexture(Texture);

	//
	Rect = sf::IntRect(sf::Vector2i(GetRandomNumber(0, 15)*32, GetRandomNumber(0, 2)*32), sf::Vector2i(32, 32));
}

// Draw 
void WarFog::Draw(sf::RenderWindow& Render, float CameraX, float CameraY, float CameraW, float CameraH, std::vector< std::vector<MapBlock> >& BlocksVector)
{
	//
	if (Drawing == true)
	for (size_t i = 0; i < BlocksVector.size(); i++) 
	for (size_t j = 0; j < BlocksVector[i].size(); j++) 
	{
		// Optimize 
		if ((j >= size_t(CameraX/32) || CameraX <= 0) && (i >= size_t(CameraY/32) || CameraY <= 0) &&
			 j <= size_t((CameraX+CameraW)/32) && i <= size_t((CameraY+CameraH)/32))
		{
			// Drawing 
			if (BlocksVector[i][j].WarFog == true)
			{
				//
				Sprite.setPosition(BlocksVector[i][j].X, BlocksVector[i][j].Y);
				Sprite.setTextureRect(Rect);
				Render.draw(Sprite);
			}
			// If error WarFog 
			else
				continue;
		}
		//
	}
	//
}