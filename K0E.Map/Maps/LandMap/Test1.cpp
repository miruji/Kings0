#include "LandMap.h"

// Blocks land data test 
bool LandMap::Test1(vector< vector<MapBlock> >& BlocksVector, size_t i, size_t j, std::string Data)
{
	// Read data 
	for (size_t ii = 0; ii < Data.length(); ii++) 
	{
		//
		if (Data[ii] != '0' && Data[ii] != '-')
			continue;
		else
		if (i >= 1 && j >= 1 && i <= BlocksVector.size()-1 && j <= BlocksVector.size()-1)
		{
			// Up 
			if (ii == 0)
			if (Data[0] == '0') {
				if (BlocksVector[i-1][j].Land == true)
				{ /* ... */ }
				else 
				{ return false; }
			} else
			if (Data[0] == '-') {
				if (BlocksVector[i-1][j].Land == false)
				{ /* ... */ }
				else 
				{ return false; }
			}
			// Down 
			if (ii == 1)
			if (Data[1] == '0') {
				if (BlocksVector[i+1][j].Land == true)
				{ /* ... */ }
				else 
				{ return false; }
			} else
			if (Data[1] == '-') {
				if (BlocksVector[i+1][j].Land == false)
				{ /* ... */ }
				else 
				{ return false; }
			}
			// Left 
			if (ii == 2)
			if (Data[2] == '0') {
				if (BlocksVector[i][j-1].Land == true)
				{ /* ... */ }
				else 
				{ return false; }
			} else
			if (Data[2] == '-') {
				if (BlocksVector[i][j-1].Land == false)
				{ /* ... */ }
				else 
				{ return false; }
			}
			// Right 
			if (ii == 3)
			if (Data[3] == '0') {
				if (BlocksVector[i][j+1].Land == true)
				{ /* ... */ }
				else 
				{ return false; }
			} else
			if (Data[3] == '-') {
				if (BlocksVector[i][j+1].Land == false)
				{ /* ... */ }
				else 
				{ return false; }
			}
			// ...
			// Angles 
			// Left up 
			if (ii == 4)
			if (Data[4] == '0') {
				if (BlocksVector[i-1][j-1].Land == true)
				{ /* ... */ }
				else 
				{ return false; }
			} else
			if (Data[4] == '-') {
				if (BlocksVector[i-1][j-1].Land == false)
				{ /* ... */ }
				else 
				{ return false; }
			}
			// Right up 
			if (ii == 5)
			if (Data[5] == '0') {
				if (BlocksVector[i-1][j+1].Land == true)
				{ /* ... */ }
				else 
				{ return false; }
			} else
			if (Data[5] == '-') {
				if (BlocksVector[i-1][j+1].Land == false)
				{ /* ... */ }
				else 
				{ return false; }
			}
			// Left down 
			if (ii == 6)
			if (Data[6] == '0') {
				if (BlocksVector[i+1][j-1].Land == true)
				{ /* ... */ }
				else 
				{ return false; }
			} else
			if (Data[6] == '-') {
				if (BlocksVector[i+1][j-1].Land == false)
				{ /* ... */ }
				else 
				{ return false; }
			}
			// Right down 
			if (ii == 7)
			if (Data[7] == '0') {
				if (BlocksVector[i+1][j+1].Land == true)
				{ /* ... */ }
				else 
				{ return false; }
			} else
			if (Data[7] == '-') {
				if (BlocksVector[i+1][j+1].Land == false)
				{ /* ... */ }
				else 
				{ return false; }
			}
			//
		}
	}

	// Rerurn true 
	return true;
}