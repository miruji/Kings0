#include "RoadMap.h"

// Constructor 
RoadMap::RoadMap()
{
	//
	RoadTexture.loadFromFile("Data/Textures/Map/Road/Road.png");
	RoadSprite.setTexture(RoadTexture);
}

// Generate
void RoadMap::Generate(vector< vector<MapBlock> >& BlocksVector)
{
	// Set rects to null 
	vector< int > RectsLine;
	for (size_t i = 0; i < BlocksVector.size(); i++)
	{
		for (size_t j = 0; j < BlocksVector[i].size(); j++)
		{
			//
			RectsLine.push_back(0);
		}
		Rects.push_back(RectsLine);
		RectsLine.clear();
	}

	// Set road in BlocksVector 
	for (size_t i = 0; i < StringsVector.size(); i++)
	for (size_t j = 0; j < StringsVector[i].size(); j++) 
	{
		//
		if (StringsVector[i][j] == '%')
		{
			BlocksVector[i][j/2].Road = true;
		}
		else
			continue;
	}

	// Generate road map 
	for (size_t i = 0; i < BlocksVector.size(); i++)
	for (size_t j = 0; j < BlocksVector[i].size(); j++)
	{
		//
		if ( (i > 1 && j > 1) && (i < BlocksVector.size()-1 && j < BlocksVector.size()-1) )
		if (BlocksVector[i][j].Road == true && Rects[i][j] == 0)
		{
			//
			if ((BlocksVector[i][j-1].Road == true && BlocksVector[i][j+1].Road == true) && (BlocksVector[i-1][j].Road == true && BlocksVector[i+1][j].Road == true))
				Rects[i][j] = 11;
			else
			if (BlocksVector[i][j+1].Road == true && (BlocksVector[i-1][j].Road == true && BlocksVector[i+1][j].Road == true))
				Rects[i][j] = 7;
			else
			if (BlocksVector[i+1][j].Road == true && (BlocksVector[i][j-1].Road == true && BlocksVector[i][j+1].Road == true))
				Rects[i][j] = 8;
			else
			if (BlocksVector[i][j-1].Road == true && (BlocksVector[i-1][j].Road == true && BlocksVector[i+1][j].Road == true))
				Rects[i][j] = 9;
			else
			if (BlocksVector[i-1][j].Road == true && (BlocksVector[i][j-1].Road == true && BlocksVector[i][j+1].Road == true))
				Rects[i][j] = 10;
			else
			if (BlocksVector[i][j+1].Road == true && BlocksVector[i+1][j].Road == true)
				Rects[i][j] = 1;
			else
			if (BlocksVector[i][j-1].Road == true && BlocksVector[i+1][j].Road == true)
				Rects[i][j] = 2;
			else
			if (BlocksVector[i][j-1].Road == true && BlocksVector[i-1][j].Road == true)
				Rects[i][j] = 3;
			else
			if (BlocksVector[i][j+1].Road == true && BlocksVector[i-1][j].Road == true)
				Rects[i][j] = 4;
			else
			if (BlocksVector[i+1][j].Road == true || BlocksVector[i-1][j].Road == true)
				Rects[i][j] = 5;
			else
			if (BlocksVector[i][j+1].Road == true || BlocksVector[i][j-1].Road == true)
				Rects[i][j] = 6;
		}
	}

	// Output 
	/*
	for (size_t i = 0; i < Rects.size(); i++)
	{
		for (size_t j = 0; j < Rects[i].size(); j++)
		{
			// ...
			cout << Rects[i][j];
		}
		cout << endl;
	}
	*/
}

// Draw 
void RoadMap::Draw(sf::RenderWindow& Render, float CameraX, float CameraY, float CameraW, float CameraH, std::vector< std::vector<MapBlock> >& BlocksVector, bool DrawingWarFog)
{
	//
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
			if (BlocksVector[i][j].Road == true)
			{
				RoadSprite.setPosition(BlocksVector[i][j].X, BlocksVector[i][j].Y);

				Rect = sf::IntRect((Rects[i][j]-1)*32, 0, 32, 32);
				RoadSprite.setTextureRect(Rect);

				Render.draw(RoadSprite);
			}
		}
		//
	}
	//
}