#include "DomainMap.h"

//
bool DomainMap::SearchTeamDomain(float X, float Y, size_t Team)
{
	if (GetTeamMap()[Y/32-1][X/32-1] == Team+2)
		return true;
	else
	if (GetTeamMap()[Y/32][X/32-1] == Team+2)
		return true;
	else
	if (GetTeamMap()[Y/32+1][X/32-1] == Team+2)
		return true;
	else
	if (GetTeamMap()[Y/32-1][X/32] == Team+2)
		return true;
	else
	if (GetTeamMap()[Y/32-1][X/32+1] == Team+2)
		return true;
	else
	if (GetTeamMap()[Y/32][X/32+1] == Team+2)
		return true;
	else
	if (GetTeamMap()[Y/32+1][X/32+1] == Team+2)
		return true;
	else
	if (GetTeamMap()[Y/32+1][X/32] == Team+2)
		return true;
	else
		return false;
}

// Blocks land data test 
bool Test2(vector< vector<size_t> >& Map, vector< vector< size_t > > TeamMap, size_t i, size_t j, string Data)
{
	// Read data 
	//if (i > 0 && j > 0)
	for (size_t ii = 0; ii < Data.length(); ii++) 
	{
		//
		if (Data[ii] != '0' && Data[ii] != '-')
			continue;
		else
		//if (i >= 1 && j >= 1 )
		{
			// Up 
			if (ii == 0)
			{
			if (Data[0] == '0') {
				if (i == 0 || j == 0 || i+1 == Map.size() || j+1 == Map[i].size())
					{ /* ... */ }
				else
				if (Map[i-1][j] != 0 && (TeamMap[i-1][j] == TeamMap[i][j] || TeamMap[i-1][j] == 0))
					{ /* ... */ }
				else 
					return false;
			} else
			if (Data[0] == '-') {
				if (i == 0 || j == 0 || i+1 == Map.size() || j+1 == Map[i].size())
					return false;
				else
				if ((TeamMap[i-1][j] != TeamMap[i][j] || TeamMap[i-1][j] == 0))
					{ /* ... */ }
				else 
					return false;
			}
			}
			// Down 
			if (ii == 1)
			{
			if (Data[1] == '0') {
				if (i == 0 || j == 0 || i+1 == Map.size() || j+1 == Map[i].size())
					{ /* ... */ }
				else
				if (Map[i+1][j] != 0 && (TeamMap[i+1][j] == TeamMap[i][j] || TeamMap[i+1][j] == 0))
					{ /* ... */ }
				else 
					return false;
			} else
			if (Data[1] == '-') {
				if (i == 0 || j == 0 || i+1 == Map.size() || j+1 == Map[i].size())
					return false;
				else
				if ((TeamMap[i+1][j] != TeamMap[i][j] || TeamMap[i+1][j] == 0))
					{ /* ... */ }
				else 
					return false;
			}
			}
			// Left 
			if (ii == 2)
			{
			if (Data[2] == '0') {
				if (i == 0 || j == 0 || i+1 == Map.size() || j+1 == Map[i].size())
					{ /* ... */ }
				else
				if (Map[i][j-1] != 0 && (TeamMap[i][j-1] == TeamMap[i][j] || TeamMap[i][j-1] == 0))
					{ /* ... */ }
				else 
					return false;
			} else
			if (Data[2] == '-') {
				if (i == 0 || j == 0 || i+1 == Map.size() || j+1 == Map[i].size())
					return false;
				else
				if ((TeamMap[i][j-1] != TeamMap[i][j] || TeamMap[i][j-1] == 0))
					{ /* ... */ }
				else 
					return false;
			}
			}
			// Right 
			if (ii == 3)
			{
			if (Data[3] == '0') {
				if (i == 0 || j == 0 || i+1 == Map.size() || j+1 == Map[i].size())
					{ /* ... */ }
				else
				if (Map[i][j+1] != 0 && (TeamMap[i][j+1] == TeamMap[i][j] || TeamMap[i][j+1] == 0))
					{ /* ... */ }
				else 
					return false;
			} else
			if (Data[3] == '-') {
				if (i == 0 || j == 0 || i+1 == Map.size() || j+1 == Map[i].size())
					return false;
				else
				if ((TeamMap[i][j+1] != TeamMap[i][j] || TeamMap[i][j+1] == 0))
					{ /* ... */ }
				else 
					return false;
			}
			}
			//
			// Angles 
			// Left up 
			if (ii == 4)
			{
			if (Data[4] == '0') {
				if (i == 0 || j == 0 || i+1 == Map.size() || j+1 == Map[i].size())
					{ /* ... */ }
				else
				if (Map[i-1][j-1] != 0 && (TeamMap[i-1][j] == TeamMap[i][j] || TeamMap[i-1][j] == 0))
					{ /* ... */ }
				else 
					return false;
			} else
			if (Data[4] == '-') {
				if (i == 0 || j == 0 || i+1 == Map.size() || j+1 == Map[i].size())
					return false;
				else
				if ((TeamMap[i-1][j] != TeamMap[i][j] || TeamMap[i-1][j] == 0))
					{ /* ... */ }
				else 
					return false;
			}
			}
			// Right up 
			if (ii == 5)
			{
			if (Data[5] == '0') {
				if (i == 0 || j == 0 || i+1 == Map.size() || j+1 == Map[i].size())
					{ /* ... */ }
				else
				if (Map[i-1][j+1] != 0 && (TeamMap[i-1][j+1] == TeamMap[i][j] || TeamMap[i-1][j+1] == 0))
					{ /* ... */ }
				else 
					return false;
			} else
			if (Data[5] == '-') {
				if (i == 0 || j == 0 || i+1 == Map.size() || j+1 == Map[i].size())
					return false;
				else
				if ((TeamMap[i-1][j+1] != TeamMap[i][j] || TeamMap[i-1][j+1] == 0))
					{ /* ... */ }
				else 
					return false;
			}
			}
			// Left down 
			if (ii == 6)
			{
			if (Data[6] == '0') {
				if (i == 0 || j == 0 || i+1 == Map.size() || j+1 == Map[i].size())
					{ /* ... */ }
				else
				if (Map[i+1][j-1] != 0 && (TeamMap[i+1][j-1] == TeamMap[i][j] || TeamMap[i+1][j-1] == 0))
					{ /* ... */ }
				else 
					return false;
			} else
			if (Data[6] == '-') {
				if (i == 0 || j == 0 || i+1 == Map.size() || j+1 == Map[i].size())
					return false;
				else
				if ((TeamMap[i+1][j-1] != TeamMap[i][j] || TeamMap[i+1][j-1] == 0))
					{ /* ... */ }
				else 
					return false;
			}
			}
			// Right down 
			if (ii == 7)
			{
			if (Data[7] == '0') {
				if (i == 0 || j == 0 || i+1 == Map.size() || j+1 == Map[i].size())
					{ /* ... */ }
				else
				if (Map[i+1][j+1] != 0 && (TeamMap[i+1][j+1] == TeamMap[i][j] || TeamMap[i+1][j+1] == 0))
					{ /* ... */ }
				else 
					return false;
			} else
			if (Data[7] == '-') {
				if (i == 0 || j == 0 || i+1 == Map.size() || j+1 == Map[i].size())
					return false;
				else
				if ((TeamMap[i+1][j+1] != TeamMap[i][j] || TeamMap[i+1][j+1] == 0))
					{ /* ... */ }
				else 
					return false;
			}
			}
			//
		}
	}

	// Rerurn true 
	return true;
}

// Constructor 
DomainMap::DomainMap()
{
	// Load all textures to sprites 
	DomainTexture.loadFromFile("Data/Textures/Map/DomainMap/DomainMap.png");
	DomainBorderTexture.loadFromFile("Data/Textures/Map/DomainMap/DomainMapBorder.png");
	Sprite.setTexture(DomainTexture);
}

// Generate 
void DomainMap::Generate(vector< vector<MapBlock> >& BlocksVector, vector< vector<size_t> > TeamMap)
{
	// Generate map 
	bool WriteNull = false;
	vector< size_t > MapLine;
	for (size_t i = 0; i < BlocksVector.size(); i++)
	{
		//
		for (size_t j = 0; j < BlocksVector[i].size(); j++)
		{
			//
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

	// String vector 
	string StrBuffer = "";
	//cout << "MP: " << TeamMap.size() << ", SV: " << StringsVector.size() << endl;
	for (size_t i = 0; i < StringsVector.size(); i++)
	for (size_t j = 0; j < StringsVector[i].size(); j++)
	{
		if (StringsVector[i][j] == '-' || StringsVector[i][j] == ' ' || StringsVector[i][j] == ';')
		{
			//cout << "-";
			continue;
		}
		else
		{
			StrBuffer = StringsVector[i][j];
			//cout << StrBuffer;
			if (i <= TeamMap.size()-1 && j/2 <= TeamMap[i].size()-1)
				TeamMap[i][j/2] = atoi(StrBuffer.c_str());
		}
	}

	this->TeamMap = TeamMap;
	// Generate team map 
	//cout << TeamMap.size() << " || " << TeamMap[0].size() << endl;
	/*
	for (size_t i = 0; i < TeamMap.size(); i++)
	{
		for (size_t j = 0; j < TeamMap[i].size(); j++)
		{
			cout << TeamMap[i][j] << " ";
		}
		cout << endl;
	}
	*/

	// Generate border map 
	UpdateBorderMap();
}

// Update border map 
void DomainMap::UpdateBorderMap()
{
	//
	BorderMap = TeamMap;
	for (size_t i = 0; i < BorderMap.size(); i++)
	for (size_t j = 0; j < BorderMap[i].size(); j++)
	{
		if (BorderMap[i][j] != 0)
		{
			BorderMap[i][j] = 1;
		}

	}

	// Generate 
	for (size_t i = 0; i < BorderMap.size(); i++)
	for (size_t j = 0; j < BorderMap[i].size(); j++)
	{
		if (BorderMap[i][j] != 0)
		{
			// Panel 
			if ( Test2(BorderMap, TeamMap, i, j, "--00NNNN") )
				BorderMap[i][j] = 14;
			else
			if ( Test2(BorderMap, TeamMap, i, j, "00--NNNN") )
				BorderMap[i][j] = 15;
			else
			// Arc 
			if ( Test2(BorderMap, TeamMap, i, j, "0---NNNN") )
				BorderMap[i][j] = 13;
			else
			if ( Test2(BorderMap, TeamMap, i, j, "--0-NNNN") )
				BorderMap[i][j] = 12;
			else
			if ( Test2(BorderMap, TeamMap, i, j, "---0NNNN") )
				BorderMap[i][j] = 11;
			else
			if ( Test2(BorderMap, TeamMap, i, j, "-0--NNNN") )
				BorderMap[i][j] = 10;
			else
			// Basic + 0 
			if ( Test2(BorderMap, TeamMap, i, j, "0000NNNN"))
				BorderMap[i][j] = 16;
			else
			if ( Test2(BorderMap, TeamMap, i, j, "-N00NNNN") )
				BorderMap[i][j] = 2;
			else
			if ( Test2(BorderMap, TeamMap, i, j, "N-00NNNN") )
				BorderMap[i][j] = 4;
			else
			if ( Test2(BorderMap, TeamMap, i, j, "00-NNNNN") )
				BorderMap[i][j] = 3;
			else
			if ( Test2(BorderMap, TeamMap, i, j, "00N-NNNN") )
				BorderMap[i][j] = 5;
			else
			// Angles 
			if ( Test2(BorderMap, TeamMap, i, j, "-0-0NNNN") )
				BorderMap[i][j] = 6;
			else
			if ( Test2(BorderMap, TeamMap, i, j, "-00-NNNN") )
				BorderMap[i][j] = 7;
			else
			if ( Test2(BorderMap, TeamMap, i, j, "0--0NNNN") )
				BorderMap[i][j] = 8;
			else
			if ( Test2(BorderMap, TeamMap, i, j, "0-0-NNNN") )
				BorderMap[i][j] = 9;
			// Else 
			else
			//	BorderMap[i][j] = 17; // 1 
				BorderMap[i][j] = 1;
		}
	}
	// Generate 2 
	/*
	for (size_t i = 0; i < BorderMap.size(); i++)
	for (size_t j = 0; j < BorderMap[i].size(); j++)
	{
		if (BorderMap[i][j] == 17)
		{
			if ((BorderMap[i-1][j] == 17 || BorderMap[i-1][j] == 4) && TeamMap[i][j] != TeamMap[i-1][j])
				BorderMap[i][j] = 2;
			else
			if ((BorderMap[i+1][j] == 17 || BorderMap[i+1][j] == 2) && TeamMap[i][j] != TeamMap[i+1][j])
				BorderMap[i][j] = 4;
			else
			if ((BorderMap[i][j-1] == 17 || BorderMap[i][j-1] == 5) && TeamMap[i][j] != TeamMap[i][j-1])
				BorderMap[i][j] = 3;
			else
			if ((BorderMap[i][j+1] == 17 || BorderMap[i][j+1] == 3) && TeamMap[i][j] != TeamMap[i][j+1])
				BorderMap[i][j] = 5;
		}
	}
	// Generate 3 
	for (size_t i = 0; i < BorderMap.size(); i++)
	for (size_t j = 0; j < BorderMap[i].size(); j++)
	{
		if (BorderMap[i][j] != 0)
		{
			// Angles 
			// Left - Right 
			if (BorderMap[i][j] == 5 && BorderMap[i-1][j] != 0 && BorderMap[i+1][j] == 0 && BorderMap[i][j+1] == 3)
				BorderMap[i][j] = 9;
			else
			if (BorderMap[i][j] == 5 && BorderMap[i+1][j] != 0 && BorderMap[i-1][j] == 0 && BorderMap[i][j+1] == 3)
				BorderMap[i][j] = 7;
			else
			if (BorderMap[i][j] == 3 && BorderMap[i-1][j] != 0 && BorderMap[i+1][j] == 0 && (BorderMap[i][j-1] == 5 || BorderMap[i][j-1] == 9 || BorderMap[i][j-1] == 7))
				BorderMap[i][j] = 8;
			else
			if (BorderMap[i][j] == 3 && BorderMap[i+1][j] != 0 && BorderMap[i-1][j] == 0 && (BorderMap[i][j-1] == 5 || BorderMap[i][j-1] == 9 || BorderMap[i][j-1] == 7))
				BorderMap[i][j] = 6;
			else
			// Up - Down 
			if (BorderMap[i][j] == 4 && BorderMap[i][j-1] == 0 && BorderMap[i][j+1] != 0 && BorderMap[i+1][j] == 2)
				BorderMap[i][j] = 8;
			else
			if (BorderMap[i][j] == 4 && BorderMap[i][j-1] != 0 && BorderMap[i][j+1] == 0 && BorderMap[i+1][j] == 2)
				BorderMap[i][j] = 9;
			else
			if (BorderMap[i][j] == 2 && BorderMap[i][j-1] == 0 && BorderMap[i][j+1] != 0 && (BorderMap[i-1][j] == 4 || BorderMap[i-1][j] == 9 || BorderMap[i-1][j] == 8))
				BorderMap[i][j] = 6;
			else
			if (BorderMap[i][j] == 2 && BorderMap[i][j-1] != 0 && BorderMap[i][j+1] == 0 && (BorderMap[i-1][j] == 4 || BorderMap[i-1][j] == 9 || BorderMap[i-1][j] == 8))
				BorderMap[i][j] = 7;
			else
			// Arc fix 1 
			if (BorderMap[i][j] == 5 && BorderMap[i-1][j] == 0 && BorderMap[i+1][j] == 0 && BorderMap[i][j+1] == 3)
				BorderMap[i][j] = 12;
			else
			if (BorderMap[i][j] == 3 && BorderMap[i-1][j] == 0 && BorderMap[i+1][j] == 0 && (BorderMap[i][j-1] == 5 || BorderMap[i][j-1] == 12))
				BorderMap[i][j] = 11;
			else
			if (BorderMap[i][j] == 4 && BorderMap[i][j-1] == 0 && BorderMap[i][j+1] == 0 && BorderMap[i+1][j] == 2)
				BorderMap[i][j] = 13;
			else
			if (BorderMap[i][j] == 2 && BorderMap[i][j-1] == 0 && BorderMap[i][j+1] == 0 && (BorderMap[i-1][j] == 4 || BorderMap[i-1][j] == 13))
				BorderMap[i][j] = 10;
		}
	}
	*/

	// Output 
	/*
	for (size_t i = 0; i < TeamMap.size(); i++)
	{
		for (size_t j = 0; j < TeamMap[i].size(); j++)
		{
			cout << TeamMap[i][j] << " ";
		}
		cout << endl;
	}
	*/
	// Output 
	/**
	for (size_t i = 0; i < BorderMap.size(); i++)
	{
		for (size_t j = 0; j < BorderMap[i].size(); j++)
		{
			if (BorderMap[i][j] < 10)
				cout << BorderMap[i][j] << "  ";
			else
				cout << BorderMap[i][j] << " ";
		}
		cout << endl;
		cout << endl;
	}
	*/
}

// Get team map (link) 
vector< vector< size_t > >& DomainMap::GetTeamMap()
{
	return TeamMap;
}

// Draw 
void DomainMap::Draw(sf::RenderWindow& Render, float CameraX, float CameraY, float CameraW, float CameraH, std::vector< std::vector<MapBlock> >& BlocksVector, bool DrawingWarFog, vector<string> Colors)
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
			// Team map 
				// Drawing 
				Sprite.setTexture(DomainTexture);
				Sprite.setPosition(BlocksVector[i][j].X, BlocksVector[i][j].Y);
				// Team map 
				if (TeamMap[i][j] == 0)
					continue;
				else
				if (TeamMap[i][j] == 1)
				{
					Sprite.setColor(sf::Color(192, 59, 18));
					AddY = 0;
				}
				else
				{
					//if (Colors.size() >= TeamMap[i][j])
					if (TeamMap[i][j]-2 < Colors.size())
					Sprite.setColor(StringToColor(Colors[TeamMap[i][j]-2]));
					AddY = 32;
				}
				// Map 
				if (Map[i][j] == 1)
					Sprite.setTextureRect(sf::IntRect(0, AddY, 32, 32));
				else 
					Sprite.setTextureRect(sf::IntRect(32, AddY, 32, 32));
				Render.draw(Sprite);
			// Border map 
			Sprite.setTexture(DomainBorderTexture);
			if (BorderMap[i][j] != 16)
				Sprite.setTextureRect(sf::IntRect(BorderMap[i][j]*32, AddY, 32, 32));
			else
				Sprite.setTextureRect(sf::IntRect(0, AddY, 32, 32));
			Render.draw(Sprite);
		}
		//
	}
	//
}