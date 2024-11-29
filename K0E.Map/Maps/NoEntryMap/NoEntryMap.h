#pragma once
#include "../../Macro.h"
#include "../MapBlock/MapBlock.h"

class K0E_Map_Api NoEntryMap
{
private:
	// Road 
	sf::Texture NoEntryTexture;
	sf::Sprite NoEntrySprite;

	// IntRect
	sf::IntRect Rect;

public:
	vector< vector<string> > MapVector;

	// Constructor 
	NoEntryMap();

	// Generate 
	void Generate(vector< vector<MapBlock> >& BlocksVector);

	// Drawing 
	bool Drawing = true;

	// Output 
	void Output();
	void Draw(sf::RenderWindow& Render, float CameraX, float CameraY, float CameraW, float CameraH, std::vector< std::vector<MapBlock> >& BlocksVector, bool DrawingWarFog);
};