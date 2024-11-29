#include "LandMap.h"

// (Land water borders blocks)
void LandMap::Generate3() 
{
	// Generate (first)
	for (size_t i = 0; i < BlocksVector.size()-1; i++) 
	for (size_t j = 0; j < BlocksVector[i].size(); j++) 
	{
		//
		if (BlocksVector[i][j].Land == true && i >= 1 && j >= 1) {
			// Land water border
			// Down land - Up water
			if ( (Test1(BlocksVector, i, j, "-NNN--NN") || Test1(BlocksVector, i, j, "-NNN-NNN") || Test1(BlocksVector, i, j, "-NNNN-NN") ) )
			{
				//
				if (BlocksVector[i-1][j].River == false)
					BlocksVector[i][j].Type = 52;
			}
			
			// Up land - Down water
			if ( (Test1(BlocksVector, i, j, "N-NNNN--") || Test1(BlocksVector, i, j, "N-NNNN-N") || Test1(BlocksVector, i, j, "N-NNNNN-") ) )
			{
				//
				if (BlocksVector[i+1][j].River == false)
					BlocksVector[i][j].Type = 53;
			}
			
			// Left land - Right water
			if ( (Test1(BlocksVector, i, j, "NNN-N-N-") || Test1(BlocksVector, i, j, "NNN-N-NN") || Test1(BlocksVector, i, j, "NNN-NNN-") ) )
			{
				//
				if (BlocksVector[i][j+1].River == false)
					BlocksVector[i][j].Type = 54;
			}
			
			// Right land - Left water
			if ( (Test1(BlocksVector, i, j, "NN-N-N-N") || Test1(BlocksVector, i, j, "NN-N-NNN") || Test1(BlocksVector, i, j, "NN-NNN-N") ) )
			{
				//
				if (BlocksVector[i][j-1].River == false)
					BlocksVector[i][j].Type = 55;
			}
			//
			BlocksVector[i][j].Update();
		}
	}
	// Generate (second)
	for (size_t i = 0; i < BlocksVector.size()-1; i++) 
	for (size_t j = 0; j < BlocksVector[i].size(); j++) 
	{
		//
		if (BlocksVector[i][j].Land == true && i >= 1 && j >= 1) {
			// Corner land
			// Left Up water
			if ( Test1(BlocksVector, i, j, "-N-NNNNN") &&
				BlocksVector[i-1][j].River == false && BlocksVector[i][j-1].River == false) 
			{
				BlocksVector[i][j].Type = 56;
			}
			// Right Up water
			if ( Test1(BlocksVector, i, j, "-NN-NNNN") &&
				BlocksVector[i-1][j].River == false && BlocksVector[i][j+1].River == false) 
			{
				BlocksVector[i][j].Type = 57;
			}
			// Left Down water
			if ( Test1(BlocksVector, i, j, "N--NNNNN") &&
				BlocksVector[i+1][j].River == false && BlocksVector[i][j-1].River == false) 
			{
				BlocksVector[i][j].Type = 58;
			}
			// Right Down water
			if ( Test1(BlocksVector, i, j, "N-N-NNNN") &&
				BlocksVector[i+1][j].River == false && BlocksVector[i][j+1].River == false) 
			{
				BlocksVector[i][j].Type = 59;
			}
			//
			BlocksVector[i][j].Update();
		}
	}
	// Generate (Third)
	for (size_t i = 0; i < BlocksVector.size()-1; i++) 
	for (size_t j = 0; j < BlocksVector[i].size(); j++) 
	{
		//
		if (BlocksVector[i][j].Land == true && i >= 1 && j >= 1) {
			// Double land water border
			// Left - Right
			if ( (Test1(BlocksVector, i, j, "--NNNNNN")) 
				&& BlocksVector[i-1][j].River == false && BlocksVector[i+1][j].River == false )
			{
				BlocksVector[i][j].Type = 60;
			}
			// Up - Down
			if ( (Test1(BlocksVector, i, j, "NN--NNNN") )
				&& BlocksVector[i][j-1].River == false && BlocksVector[i][j+1].River == false )
			{
				BlocksVector[i][j].Type = 61;
			}
			//
			BlocksVector[i][j].Update();
		}
	}
	// Generate (Fourth)
	for (size_t i = 0; i < BlocksVector.size()-1; i++) 
	for (size_t j = 0; j < BlocksVector[i].size(); j++) 
	{
		//
		if (BlocksVector[i][j].Land == true && i >= 1 && j >= 1) {
			// Arc land
			// Up arc
			if ( (Test1(BlocksVector, i, j, "-0--NNN") || (Test1(BlocksVector, i, j, "----NNN") && BlocksVector[i+1][j].River == true)) &&
				BlocksVector[i][j-1].River == false && BlocksVector[i][j+1].River == false && BlocksVector[i-1][j].River == false)
			{
				BlocksVector[i][j].Type = 62;
			}
			// Down arc
			if ( (Test1(BlocksVector, i, j, "0---NNN") || (Test1(BlocksVector, i, j, "----NNN") && BlocksVector[i-1][j].River == true)) &&
				BlocksVector[i][j-1].River == false && BlocksVector[i][j+1].River == false && BlocksVector[i+1][j].River == false)
			{
				BlocksVector[i][j].Type = 63;
			}
			// Left arc
			if ( (Test1(BlocksVector, i, j, "---0NNNN") || (Test1(BlocksVector, i, j, "----NNNN") && BlocksVector[i][j+1].River == true)) &&
				BlocksVector[i][j-1].River == false && BlocksVector[i-1][j].River == false && BlocksVector[i+1][j].River == false)
			{
				BlocksVector[i][j].Type = 64;
			}
			// Right arc
			if ( (Test1(BlocksVector, i, j, "--0-NNNN") || (Test1(BlocksVector, i, j, "----NNNN") && BlocksVector[i][j-1].River == true)) &&
				BlocksVector[i][j+1].River == false && BlocksVector[i-1][j].River == false && BlocksVector[i+1][j].River == false)
			{
				BlocksVector[i][j].Type = 65;
			}
			//
			BlocksVector[i][j].Update();
		}
	}
	// Generate (Fifth)
	for (size_t i = 0; i < BlocksVector.size()-1; i++) 
	for (size_t j = 0; j < BlocksVector[i].size(); j++) 
	{
		//
		if (BlocksVector[i][j].Land == true && i >= 1 && j >= 1) {
			// Arc land
			// Up arc
			if ( Test1(BlocksVector, i, j, "----NNNN") &&
				BlocksVector[i+1][j].River == false &&
				BlocksVector[i-1][j].River == false &&
				BlocksVector[i][j+1].River == false &&
				BlocksVector[i][j-1].River == false )
			{
				BlocksVector[i][j].Type = 87;
			}
			//
			BlocksVector[i][j].Update();
		}
	}
	//
}