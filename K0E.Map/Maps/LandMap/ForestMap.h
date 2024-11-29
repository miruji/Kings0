#pragma once
#include "../../Macro.h"
#include "../MapBlock/MapBlock.h"

class K0E_Map_Api ForestMap
{
public:
	// Map vector 
	vector< string > StringsVector;

	// Constructor 
	ForestMap();

	// Generate 
	void Generate(vector< vector<MapBlock> >& BlocksVector);
};