#include "../Window.h"

// Game: new player war fog
void Window::Game_PlayerWarFog()
{
	//
	int X = Game1->Player1->X/32;
	int Y = Game1->Player1->Y/32;

	size_t MapW = LandMap1->BlocksVector.size()-1;

	//
	if (LandMap1->BlocksVector[Y][X].WarFog == true)
		LandMap1->BlocksVector[Y][X].WarFog = false;


	if (Y-1 >= 0 && X-1 >= 0)
	if (LandMap1->BlocksVector[Y-1][X-1].WarFog == true)
		LandMap1->BlocksVector[Y-1][X-1].WarFog = false;

	if (X-1 >= 0)
	if (LandMap1->BlocksVector[Y][X-1].WarFog == true)
		LandMap1->BlocksVector[Y][X-1].WarFog = false;

	if (Y+1 <= MapW && X-1 >= 0)
	if (LandMap1->BlocksVector[Y+1][X-1].WarFog == true)
		LandMap1->BlocksVector[Y+1][X-1].WarFog = false;

	if (Y-1 >= 0)
	if (LandMap1->BlocksVector[Y-1][X].WarFog == true)
		LandMap1->BlocksVector[Y-1][X].WarFog = false;

	if (Y+1 <= MapW)
	if (LandMap1->BlocksVector[Y+1][X].WarFog == true)
		LandMap1->BlocksVector[Y+1][X].WarFog = false;

	if (Y-1 >= 0 && X+1 <= MapW)
	if (LandMap1->BlocksVector[Y-1][X+1].WarFog == true)
		LandMap1->BlocksVector[Y-1][X+1].WarFog = false;

	if (X+1 <= MapW)
	if (LandMap1->BlocksVector[Y][X+1].WarFog == true)
		LandMap1->BlocksVector[Y][X+1].WarFog = false;

	if (Y+1 <= MapW && X+1 <= MapW)
	if (LandMap1->BlocksVector[Y+1][X+1].WarFog == true)
		LandMap1->BlocksVector[Y+1][X+1].WarFog = false;

	MapW = MapW-1;

	if (Y-2 >= 1)
	if (LandMap1->BlocksVector[Y-2][X].WarFog == true)
		LandMap1->BlocksVector[Y-2][X].WarFog = false;

	if (Y+2 <= MapW)
	if (LandMap1->BlocksVector[Y+2][X].WarFog == true)
		LandMap1->BlocksVector[Y+2][X].WarFog = false;

	if (X-2 >= 1)
	if (LandMap1->BlocksVector[Y][X-2].WarFog == true)
		LandMap1->BlocksVector[Y][X-2].WarFog = false;

	if (X+2 <= MapW)
	if (LandMap1->BlocksVector[Y][X+2].WarFog == true)
		LandMap1->BlocksVector[Y][X+2].WarFog = false;
}