#include "NoEntryMap.h"

// Constructor 
NoEntryMap::NoEntryMap()
{
	//
	NoEntryTexture.loadFromFile("Data/Textures/Game/NoEntry.png");
	NoEntrySprite.setTexture(NoEntryTexture);
}

// Generate
void NoEntryMap::Generate(vector< vector<MapBlock> >& BlocksVector)
{
	// Set rects to null 
	vector< string > Line;
	for (size_t i = 0; i < BlocksVector.size(); i++)
	{
		for (size_t j = 0; j < BlocksVector[i].size(); j++)
		{
			//
			Line.push_back("0");
		}
		MapVector.push_back(Line);
		Line.clear();
	}
}

// Output 
void NoEntryMap::Output()
{
	// Output 
	for (size_t i = 0; i < MapVector.size(); i++)
	{
		for (size_t j = 0; j < MapVector[i].size(); j++)
		{
			//
			cout << MapVector[j][i] << " ";
		}
		cout << endl;
	}
}

// Draw 
void NoEntryMap::Draw(sf::RenderWindow& Render, float CameraX, float CameraY, float CameraW, float CameraH, std::vector< std::vector<MapBlock> >& BlocksVector, bool DrawingWarFog)
{
	//
	if (Drawing == true)
	for (size_t i = 0; i < BlocksVector.size(); i++) 
	for (size_t j = 0; j < BlocksVector[i].size(); j++) 
	{
		// War Fog 
		//if (BlocksVector[i][j].WarFog == false || DrawingWarFog == false)
		// Optimize 
		if ((j >= size_t(CameraX/32) || CameraX <= 0) && (i >= size_t(CameraY/32) || CameraY <= 0) &&
			 j <= size_t((CameraX+CameraW)/32) && i <= size_t((CameraY+CameraH)/32))
		{
			// Drawing 
			if (MapVector[j][i][0] != '0')
			{
				NoEntrySprite.setPosition(BlocksVector[i][j].X, BlocksVector[i][j].Y);

				//if ( MapVector[j][i].size() == 1 )
				//	Rect = sf::IntRect(0, (atoi(MapVector[j][i].c_str()))*32, 32, 32);
				//else
					Rect = sf::IntRect(0, 0, 32, 32);

				NoEntrySprite.setTextureRect(Rect);

				Render.draw(NoEntrySprite);
			}
		}
		//
	}
	//
}