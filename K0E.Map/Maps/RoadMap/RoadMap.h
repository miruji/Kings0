#pragma once
#include "../../Macro.h"
#include "../MapBlock/MapBlock.h"

class K0E_Map_Api RoadMap
{
private:
	// Road 
	sf::Texture RoadTexture;
	sf::Sprite RoadSprite;

	// IntRect
	sf::IntRect Rect;
	vector< vector<int> > Rects;

public:
	// Constructor 
	RoadMap();

	// Map vector 
	vector< string > StringsVector;

	// Generate 
	void Generate(vector< vector<MapBlock> >& BlocksVector);

	// Drawing 
	bool Drawing = true;
	void Draw(sf::RenderWindow& Render, float CameraX, float CameraY, float CameraW, float CameraH, std::vector< std::vector<MapBlock> >& BlocksVector, bool DrawingWarFog);
};