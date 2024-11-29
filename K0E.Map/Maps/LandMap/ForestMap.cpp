#include "ForestMap.h"

// Constructor 
ForestMap::ForestMap()
{
}

// Generate
void ForestMap::Generate(vector< vector<MapBlock> >& BlocksVector)
{
	//
	for (size_t i = 0; i < StringsVector.size(); i++)
	for (size_t j = 0; j < StringsVector[i].size(); j++) 
	{
		//
		if (StringsVector[i][j] == '|')
		{
			BlocksVector[i][j/2].RectAddY += 96;
			BlocksVector[i][j/2].Forest = true;
		}
		else
			continue;
	}
}