#pragma once
#include "../../Macro.h"
#include "../MapBlock/MapBlock.h"

class K0E_Map_Api WarFog
{
private:
	// WarFog 
	sf::Texture Texture;
	sf::Sprite Sprite;
	sf::IntRect Rect;

public:
	// Constructor 
	WarFog(vector< vector<MapBlock> >& BlocksVector);

	// Drawing 
	bool Drawing = true;
	void Draw(sf::RenderWindow& Render, float CameraX, float CameraY, float CameraW, float CameraH, std::vector< std::vector<MapBlock> >& BlocksVector);
};