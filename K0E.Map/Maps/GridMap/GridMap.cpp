#include "GridMap.h"

// Constructor 
GridMap::GridMap(std::vector< std::vector<MapBlock> >& BlocksVector)
{
	// Generate map 
	bool WriteNull = false;
	std::vector< size_t > MapLine;
	for (size_t i = 0; i < BlocksVector.size(); i++)
	{
		// ... 
		for (size_t j = 0; j < BlocksVector[i].size(); j++)
		{
			// ... 
			if (WriteNull == false)
			{
				MapLine.push_back(1);
				WriteNull = true;
			}
			else
			{
				MapLine.push_back(0);
				WriteNull = false;
			}
		}

		Map.push_back(MapLine);
		MapLine.clear();

		if (WriteNull == true)
			WriteNull = false;
		else
			WriteNull = true;
	}

	// Load all textures to sprites 
	GridTexture.loadFromFile("Data/Textures/Map/Grid/Grid.png");
	GridSprite.setTexture(GridTexture);
}

// Draw 
void GridMap::Draw(sf::RenderWindow& Render, float CameraX, float CameraY, float CameraW, float CameraH, std::vector< std::vector<MapBlock> >& BlocksVector, bool DrawingWarFog)
{
	// ... 
	if (Drawing == true)
	for (size_t i = 0; i < BlocksVector.size(); i++) 
	for (size_t j = 0; j < BlocksVector[i].size(); j++) 
	{
		// War Fog 
		if (BlocksVector[i][j].WarFog == false || DrawingWarFog == false)
		// Optimize 
		if ((j >= size_t(CameraX/32) || CameraX <= 0) && (i >= size_t(CameraY/32) || CameraY <= 0) &&
			 j <= size_t((CameraX+CameraW)/32) && i <= size_t((CameraY+CameraH)/32))
		{
			// Drawing 
			GridSprite.setPosition(BlocksVector[i][j].X, BlocksVector[i][j].Y);
			if (Map[i][j] == 1)
				GridSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
			else 
				GridSprite.setTextureRect(sf::IntRect(32, 0, 32, 32));
			Render.draw(GridSprite);
		}
		// ...
	}
	// ...
}