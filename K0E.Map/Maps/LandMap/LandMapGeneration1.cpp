#include "LandMap.h"

// Generate map (Basic land and water)
void LandMap::Generate() 
{
	// Create basic blocks
	std::vector<MapBlock> BlocksLine;

	// Next generation lvl 
	for (size_t i = 0; i < StringsVector.size(); i++) {
		//
		for (size_t j = 0; j < StringsVector[i].size(); j++)
		{
			//
			if (StringsVector[i][j] == '0') 
			{
				BlocksLine.push_back(MapBlock(float(j*16), float(i*32), 32.0f, 32.0f, 0));
				BlocksLine[BlocksLine.size()-1].Land = true;
			}
			else
			if (StringsVector[i][j] == '-')
			{
				BlocksLine.push_back(MapBlock(float(j*16), float(i*32), 32.0f, 32.0f, 1));
				BlocksLine[BlocksLine.size()-1].Land = false;
			}
			else
				continue;
		}
		//
		BlocksVector.push_back(BlocksLine);
		BlocksLine.clear();
	}

	// Next generate (Rivers) 
	Generate2();

	// Next generate (Land water borders blocks) 
	Generate3();

	// Next generate (Inside) 
	Generate4();
}