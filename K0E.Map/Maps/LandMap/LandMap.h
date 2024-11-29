#pragma once
#include "../../Macro.h"
#include "../MapBlock/MapBlock.h"

// Class 
class K0E_Map_Api LandMap
{
private:
	// Main stream sprite 
	sf::Sprite CurrentSprite;

	// Unknown 
		sf::Texture UnknownTexture;
		sf::Sprite UnknownSprite;

	// Land 
		sf::Texture LandTexture;
		sf::Sprite LandSprite;

	// Water 
		sf::Texture WaterTexture;
		sf::Sprite WaterSprite;

	// Crag 
		sf::Texture CragTexture;
		sf::Sprite CragSprite;

	// River 
		// River main
		sf::Texture RiverMainTexture;
		sf::Sprite RiverMainSprite;

		// River angles
		sf::Texture RiverAnglesTexture;
		sf::Sprite RiverAnglesSprite;

		// River ends
		sf::Texture RiverEndsTexture;
		sf::Sprite RiverEndsSprite;

	// Basic land 
		// Lake 
		sf::Texture LakeTexture;
		sf::Sprite LakeSprite;

		// Land water border 
		sf::Texture LandWaterBorderTexture;
		sf::Sprite LandWaterBorderSprite;

		// Corner land 
		sf::Texture CornerLandTexture;
		sf::Sprite CornerLandSprite;

		// Double land water border 
		sf::Texture DoubleLandWaterBorderTexture;
		sf::Sprite DoubleLandWaterBorderSprite;

		// Arc land 
		sf::Texture ArcLandTexture;
		sf::Sprite ArcLandSprite;

		// Island 
		sf::Texture IslandTexture;
		sf::Sprite IslandSprite;

	// Angles land 
		// Angle
		sf::Texture AngleTexture;
		sf::Sprite AngleSprite;

		// Double angle
		sf::Texture DoubleAngleTexture;
		sf::Sprite DoubleAngleSprite;

		// Land water border double angle
		sf::Texture LandWaterBorderDoubleAngleTexture;
		sf::Sprite LandWaterBorderDoubleAngleSprite;

		// Corner angle
		sf::Texture CornerAngleTexture;
		sf::Sprite CornerAngleSprite;

		// Cross angle
		sf::Texture CrossAngleTexture;
		sf::Sprite CrossAngleSprite;

		// Centr angle
		sf::Texture CentrAngleTexture;
		sf::Sprite CentrAngleSprite;

		// Third angle
		sf::Texture ThirdAngleTexture;
		sf::Sprite ThirdAngleSprite;

		// Land water border angle
		sf::Texture LandWaterBorderAngleTexture;
		sf::Sprite LandWaterBorderAngleSprite;

public:
	size_t ForestSize;

	// Map vector 
	vector< string >           StringsVector;
	vector< vector<MapBlock> > BlocksVector;

	// Constructor
	LandMap();

	// Generate map 
	void Generate();  // (Basic land and water)
	void Generate2(); // (Rivers)
	void Generate3(); // (Land water borders blocks)
	void Generate4(); // (Inside) 

	void Generate2BlockUpdate(MapBlock& Block); // (Block update)

	// Blocks land data test 
	bool Test1(vector< vector<MapBlock> >& BlocksVector, size_t i, size_t j, std::string Data);

	// Rendering map 
	void Draw(sf::RenderWindow& Render, float CameraX, float CameraY, float CameraW, float CameraH, bool DrawingWarFog);
};