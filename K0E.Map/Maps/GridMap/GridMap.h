#pragma once
#include "../../Macro.h"
#include "../MapBlock/MapBlock.h"

class K0E_Map_Api GridMap
{
private:
	// WarFog 
	sf::Texture GridTexture;
	sf::Sprite GridSprite;

	// Map 
	std::vector< std::vector< size_t > > Map;

public:
	// Constructor 
	GridMap(std::vector< std::vector<MapBlock> >& BlocksVector);

	// Drawing 
	bool Drawing = true;
	void Draw(sf::RenderWindow& Render, float CameraX, float CameraY, float CameraW, float CameraH, std::vector< std::vector<MapBlock> >& BlocksVector, bool DrawingWarFog);
};