#pragma once
#include "../../Macro.h"
#include "../MapBlock/MapBlock.h"
#include "../LandMap/LandMap.h"
#include "../../Func/StringToColor.h"

class K0E_Map_Api DomainMap
{
private:
	// WarFog 
	sf::Texture DomainTexture;
	sf::Texture DomainBorderTexture;
	sf::Sprite Sprite;

	// Map 
	size_t AddY;
	vector< vector< size_t > > Map;
	vector< vector< size_t > > TeamMap;
	vector< vector< size_t > > BorderMap;

public:
	//
	bool SearchTeamDomain(float X, float Y, size_t Team);

	// Constructor 
	DomainMap();

	// Map vector 
	vector< string > StringsVector;

	// Generate 
	void Generate(vector< vector<MapBlock> >& BlocksVector, vector< vector<size_t> > TeamMap);

	// Get team map (link) 
	vector< vector< size_t > >& GetTeamMap();

	// Update border map 
	void UpdateBorderMap();

	// Drawing 
	bool Drawing = true;
	void Draw(sf::RenderWindow& Render, float CameraX, float CameraY, float CameraW, float CameraH, std::vector< std::vector<MapBlock> >& BlocksVector, bool DrawingWarFog, vector<string> Colors);
};