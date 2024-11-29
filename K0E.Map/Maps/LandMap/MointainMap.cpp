#include "MountainMap.h"

// Constructor 
MountainMap::MountainMap()
{
}

// Generate
void MountainMap::Generate(vector< vector<MapBlock> >& BlocksVector)
{
	//
	for (size_t i = 0; i < StringsVector.size(); i++)
	for (size_t j = 0; j < StringsVector[i].size(); j++)
	{
		//
		if (StringsVector[i][j] == '#')
		{
			BlocksVector[i][j/2].RectAddY += 192;
			BlocksVector[i][j/2].Mountain = true;
		}
		else
			continue;
	}
}