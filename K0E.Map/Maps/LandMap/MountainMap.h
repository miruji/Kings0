#pragma once
#include "../../Macro.h"
#include "../MapBlock/MapBlock.h"

class K0E_Map_Api MountainMap
{
public:
	// Map vector 
	vector< string > StringsVector;

	// Constructor 
	MountainMap();

	// Generate 
	void Generate(vector< vector<MapBlock> >& BlocksVector);
};