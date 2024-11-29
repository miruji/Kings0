#include "LandMap.h"

// (Inside)
void LandMap::Generate4()
{
	// Generate (first) 
	for (size_t i = 0; i < BlocksVector.size()-1; i++) 
	for (size_t j = 0; j < BlocksVector[i].size(); j++) 
	{
		//
		if (BlocksVector[i][j].Land == true && i >= 1 && j >= 1)
		{
			// Up left
			if (BlocksVector[i-1][j-1].River == false 
				&& BlocksVector[i][j].Type != 59 && BlocksVector[i][j].Type != 53 && BlocksVector[i][j].Type != 54)
			{
				//
				if ( Test1(BlocksVector, i, j, "NNNN-NNN") && BlocksVector[i-1][j-1].River == false )
					BlocksVector[i][j].Type = 92;
			}
			// Up right
			if (BlocksVector[i-1][j+1].River == false
				&& BlocksVector[i][j].Type != 58 && BlocksVector[i][j].Type != 53 && BlocksVector[i][j].Type != 55) 
			{
				//
				if ( Test1(BlocksVector, i, j, "NNNNN-NN") && BlocksVector[i-1][j+1].River == false )
					BlocksVector[i][j].Type = 93;
			}
			// Down right
			if (BlocksVector[i+1][j+1].River == false
				&& BlocksVector[i][j].Type != 56 && BlocksVector[i][j].Type != 52 && BlocksVector[i][j].Type != 55)
			{
				//
				if ( Test1(BlocksVector, i, j, "NNNNNNN-") && BlocksVector[i+1][j+1].River == false)
					BlocksVector[i][j].Type = 94;
			}
			// Down left
			if (BlocksVector[i+1][j-1].River == false
				&& BlocksVector[i][j].Type != 57 && BlocksVector[i][j].Type != 52 && BlocksVector[i][j].Type != 54)
			{
				//
				if ( Test1(BlocksVector, i, j, "NNNNNN-N") && BlocksVector[i+1][j-1].River == false )
					BlocksVector[i][j].Type = 95;
			}
			//
			BlocksVector[i][j].Update();
		}
		//
	}
	// Generate (second)
	for (size_t i = 0; i < BlocksVector.size()-1; i++) 
	for (size_t j = 0; j < BlocksVector[i].size(); j++) 
	{
		//
		if (BlocksVector[i][j].Land == true && i >= 1 && j >= 1)
		{
			// Up : left & right
			if (BlocksVector[i-1][j-1].River == false && BlocksVector[i-1][j+1].River == false)
			{
				// ...
				if ( Test1(BlocksVector, i, j, "0000--00")
					|| 
					(Test1(BlocksVector, i, j, "-000--00") && BlocksVector[i-1][j].River == true) 
					|| 
					(Test1(BlocksVector, i, j, "-NNN--NN") && BlocksVector[i-1][j].River == true && BlocksVector[i+1][j-1].River == true && BlocksVector[i+1][j+1].River == true)
					|| 
					(Test1(BlocksVector, i, j, "0NNN--NN") && BlocksVector[i-1][j-1].River == false && BlocksVector[i-1][j+1].River == false) )
					BlocksVector[i][j].Type = 96;
			}

			// Down : left & right
			if (BlocksVector[i+1][j-1].River == false && BlocksVector[i+1][j+1].River == false)
			{
				//
				if ( Test1(BlocksVector, i, j, "000000--")
					|| 
					(Test1(BlocksVector, i, j, "0-0000--") && BlocksVector[i+1][j].River == true)
					|| 
					(Test1(BlocksVector, i, j, "N-NNNN--") && BlocksVector[i+1][j].River == true && BlocksVector[i-1][j-1].River == true && BlocksVector[i-1][j+1].River == true)
					|| 
					(Test1(BlocksVector, i, j, "N0NNNN--") && BlocksVector[i+1][j-1].River == false && BlocksVector[i+1][j+1].River == false) )
					BlocksVector[i][j].Type = 97;
			}

			// Left : up & down
			if (BlocksVector[i-1][j-1].River == false && BlocksVector[i+1][j-1].River == false)
			{
				//
				if ( Test1(BlocksVector, i, j, "0000-0-0")
					|| 
					(Test1(BlocksVector, i, j, "00-0-0-0") && BlocksVector[i][j-1].River == true)
					|| 
					(Test1(BlocksVector, i, j, "NN-N-N-N") && BlocksVector[i][j-1].River == true && BlocksVector[i-1][j+1].River == true && BlocksVector[i+1][j+1].River == true) 
					|| 
					(Test1(BlocksVector, i, j, "NN0N-N-N")&& BlocksVector[i-1][j-1].River == false && BlocksVector[i+1][j-1].River == false) )
					BlocksVector[i][j].Type = 98;
			}

			// Right : up & down
			if (BlocksVector[i+1][j+1].River == false && BlocksVector[i-1][j+1].River == false)
			{
				//
				if ( Test1(BlocksVector, i, j, "00000-0-")
					|| 
					(Test1(BlocksVector, i, j, "000-0-0-") && BlocksVector[i][j+1].River == true)
					|| 
					(Test1(BlocksVector, i, j, "NNN-N-N-") && BlocksVector[i][j+1].River == true && BlocksVector[i-1][j-1].River == true && BlocksVector[i+1][j-1].River == true) 
					|| 
					(Test1(BlocksVector, i, j, "NNN0N-N-") && BlocksVector[i-1][j+1].River == false && BlocksVector[i+1][j+1].River == false) )
					BlocksVector[i][j].Type = 99;
			}
			//
			BlocksVector[i][j].Update();
		}
		//
	}
	// Generate (regen 3 gen)
	Generate3();
	// Generate (regen 3 gen)
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
	// Generate (regen 3 gen)
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
	// Generate (regen 3 gen)
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
	// Generate (Third)
	for (size_t i = 0; i < BlocksVector.size()-1; i++) 
	for (size_t j = 0; j < BlocksVector[i].size(); j++) 
	{
		//
		if (BlocksVector[i][j].Land == true && i >= 1 && j >= 1)
		{
			// Up : left & right
			if (BlocksVector[i-1][j-1].River == false && BlocksVector[i-1][j+1].River == false)
			{
				//
				if ( Test1(BlocksVector, i, j, "N-NN--NN") && BlocksVector[i][j].Type == 53
					&& BlocksVector[i+1][j].River == false )
					BlocksVector[i][j].Type = 100;
			}
			// Down : left & right
			if (BlocksVector[i+1][j-1].River == false && BlocksVector[i+1][j+1].River == false)
			{
				//
				if ( Test1(BlocksVector, i, j, "-NNNNN--") && BlocksVector[i][j].Type == 52
					&& BlocksVector[i-1][j].River == false )
					BlocksVector[i][j].Type = 101;
			}
			// Left : up & down
			if (BlocksVector[i-1][j-1].River == false && BlocksVector[i+1][j-1].River == false)
			{
				//
				if ( Test1(BlocksVector, i, j, "NNN--N-N") && BlocksVector[i][j].Type == 54
					&& BlocksVector[i][j+1].River == false )
					BlocksVector[i][j].Type = 102;
			}
			// Right : up & down
			if (BlocksVector[i-1][j+1].River == false && BlocksVector[i+1][j+1].River == false)
			{
				//
				if ( Test1(BlocksVector, i, j, "NN-NN-N-") && BlocksVector[i][j].Type == 55
					&& BlocksVector[i][j-1].River == false )
					BlocksVector[i][j].Type = 103;
			}
			//
			BlocksVector[i][j].Update();
		}
		//
	}
	// Generate (regen 3 gen)
	for (size_t i = 0; i < BlocksVector.size()-1; i++) 
	for (size_t j = 0; j < BlocksVector[i].size(); j++) 
	{
		//
		if (BlocksVector[i][j].Land == false && (i >= 1 && j >= 1) )
		{
			// Rivers end
			// Down (river) - Centr - End
			if (Test1(BlocksVector, i, j, "0-00NN-0") && BlocksVector[i+1][j-1].River == false
				&& BlocksVector[i+2][j].Land == true)
			{
				BlocksVector[i][j].Type = 74;
			}
			else
			if (Test1(BlocksVector, i, j, "0-00NN0-") && BlocksVector[i+1][j+1].River == false
				&& BlocksVector[i+2][j].Land == true)
			{
				BlocksVector[i][j].Type = 75;
			}
			else
			if (Test1(BlocksVector, i, j, "0-00NNNN"))
			{
				if (BlocksVector[i+1][j].River == true )
					BlocksVector[i][j].Type = 13;
				else
					BlocksVector[i][j].Type = 17;
			} 
			// Up (river) - Centr - End
			if ( Test1(BlocksVector, i, j, "-000-0NN") && BlocksVector[i-1][j-1].River == false
				&& BlocksVector[i-2][j].Land == true )
			{
				BlocksVector[i][j].Type = 76;
			}
			else
			if (Test1(BlocksVector, i, j, "-0000-NN") && BlocksVector[i-1][j+1].River == false
				&& BlocksVector[i-2][j].Land == true )
			{
				BlocksVector[i][j].Type = 77;
			}
			else
			if (Test1(BlocksVector, i, j, "-000--NN"))
			{
				if ( BlocksVector[i-1][j].River == true )
					BlocksVector[i][j].Type = 14;
				else
					BlocksVector[i][j].Type = 18;
			}
			// Left (river) - Centr - End
			if (Test1(BlocksVector, i, j, "00-00N-N") && BlocksVector[i+1][j-1].River == false
				&& BlocksVector[i][j-2].Land == true)
			{
				BlocksVector[i][j].Type = 78;
			}
			else
			if (Test1(BlocksVector, i, j, "00-0-N0N") && BlocksVector[i-1][j-1].River == false
				&& BlocksVector[i][j-2].Land == true)
			{
				BlocksVector[i][j].Type = 79;
			}
			else
			if (Test1(BlocksVector, i, j, "00-0NNNN")) 
			{
				if ( BlocksVector[i][j-1].River == true )
					BlocksVector[i][j].Type = 15;
				else
					BlocksVector[i][j].Type = 19;
			}
			// Right (river) - Centr - End
			if (Test1(BlocksVector, i, j, "000-N0N-") && BlocksVector[i+1][j+1].River == false
				&& BlocksVector[i][j+2].Land == true)
			{
				BlocksVector[i][j].Type = 80;
			}
			else
			if (Test1(BlocksVector, i, j, "000-N-N0") && BlocksVector[i-1][j+1].River == false
				&& BlocksVector[i][j+2].Land == true)
			{
				BlocksVector[i][j].Type = 81;
			}
			else
			if (Test1(BlocksVector, i, j, "000-NNNN"))
			{
				if ( BlocksVector[i][j+1].River == true )
					BlocksVector[i][j].Type = 16;
				else 
					BlocksVector[i][j].Type = 20;
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
		if (BlocksVector[i][j].Land == true && i >= 1 && j >= 1)
		{
			// Left Up water
			if ( BlocksVector[i][j].Type == 56 && 
				(BlocksVector[i+1][j+1].Land == false && BlocksVector[i+1][j+1].River == false) )
				BlocksVector[i][j].Type = 104;
			// Right Up water
			if ( BlocksVector[i][j].Type == 57 && 
				(BlocksVector[i+1][j-1].Land == false && BlocksVector[i+1][j-1].River == false) )
				BlocksVector[i][j].Type = 105;
			// Left Down water
			if ( BlocksVector[i][j].Type == 58 && 
				(BlocksVector[i-1][j+1].Land == false && BlocksVector[i-1][j+1].River == false) )
				BlocksVector[i][j].Type = 106;
			// Right Down water
			if ( BlocksVector[i][j].Type == 59 && 
				(BlocksVector[i-1][j-1].Land == false && BlocksVector[i-1][j-1].River == false) )
				BlocksVector[i][j].Type = 107;
			//
			BlocksVector[i][j].Update();
		}
		//
	}
	// Generate (Fifth)
	for (size_t i = 0; i < BlocksVector.size()-1; i++) 
	for (size_t j = 0; j < BlocksVector[i].size(); j++) 
	{
		//
		if (BlocksVector[i][j].Land == true && i >= 1 && j >= 1)
		{
			// Cross angle
			// Left down - Right up
			if ( (BlocksVector[i][j].Type == 92 || BlocksVector[i][j].Type == 94 || BlocksVector[i][j].Type == 95) && Test1(BlocksVector, i, j, "NNNNN--N")
				 && BlocksVector[i-1][j+1].River == false && BlocksVector[i+1][j-1].River == false)
				BlocksVector[i][j].Type = 108;

			// Left up - Right down
			if ( (BlocksVector[i][j].Type == 93 || BlocksVector[i][j].Type == 94 || BlocksVector[i][j].Type == 95) && Test1(BlocksVector, i, j, "NNNN-NN-")
				 && BlocksVector[i-1][j-1].River == false && BlocksVector[i+1][j+1].River == false)
				BlocksVector[i][j].Type = 109;

			// Centr angle
			if ( Test1(BlocksVector, i, j, "NNNN----")
				&& 
				(BlocksVector[i-1][j].River == true || BlocksVector[i-1][j].Land == true)
				&&
				(BlocksVector[i+1][j].River == true || BlocksVector[i+1][j].Land == true)
				&&
				(BlocksVector[i][j-1].River == true || BlocksVector[i][j-1].Land == true)
				&&
				(BlocksVector[i][j+1].River == true || BlocksVector[i][j+1].Land == true)
				&& (BlocksVector[i-1][j-1].River == false && BlocksVector[i-1][j+1].River == false &&
					BlocksVector[i+1][j-1].River == false && BlocksVector[i+1][j+1].River == false)
			   )
				BlocksVector[i][j].Type = 110;

			// Third angle
			// Left up
			if (BlocksVector[i][j].Type == 98 && Test1(BlocksVector, i, j, "0N0N---N")
				&& (BlocksVector[i+1][j+1].Land == true || BlocksVector[i+2][j+2].Land == true))
				BlocksVector[i][j].Type = 111;
			// Right up
			if (BlocksVector[i][j].Type == 99 && Test1(BlocksVector, i, j, "0NN0--N-")
				&& (BlocksVector[i+1][j-1].Land == true || BlocksVector[i+2][j-2].Land == true))
				BlocksVector[i][j].Type = 112;
			// Right down
			if (BlocksVector[i][j].Type == 98 && Test1(BlocksVector, i, j, "N00N-N--")
				&& (BlocksVector[i-1][j+1].Land == true || BlocksVector[i-2][j+2].Land == true))
				BlocksVector[i][j].Type = 114;
			// Left down
			if (BlocksVector[i][j].Type == 99 && Test1(BlocksVector, i, j, "N0N0N---")
				&& (BlocksVector[i-1][j-1].Land == true || BlocksVector[i-2][j-2].Land == true))
				BlocksVector[i][j].Type = 113;
			//
			BlocksVector[i][j].Update();
		}
		//
	}
	// Generate (Sixth)
	for (size_t i = 0; i < BlocksVector.size()-1; i++) 
	for (size_t j = 0; j < BlocksVector[i].size(); j++) 
	{
		//
		if (BlocksVector[i][j].Land == true && i >= 1 && j >= 1)
		{
			// Up water - right down angle
			if ( BlocksVector[i][j].Type == 52 
				&& 
				((Test1(BlocksVector, i, j, "NNN0NNNN") && (BlocksVector[i][j+1].Type == 60 || BlocksVector[i][j+1].Type == 65) )
				||
				(Test1(BlocksVector, i, j, "NNN-NNNN") && BlocksVector[i][j+1].Type == 25)) )
				BlocksVector[i][j].Type = 115;
			// Up water - left down angle
			if ( BlocksVector[i][j].Type == 52 
				&& 
				((Test1(BlocksVector, i, j, "NN0NNNNN") && (BlocksVector[i][j-1].Type == 60 || BlocksVector[i][j-1].Type == 64) )
				|| 
				(Test1(BlocksVector, i, j, "NN-NNNNN") && BlocksVector[i][j-1].Type == 25)) )
				BlocksVector[i][j].Type = 116;
			// Down water - right up angle
			if ( BlocksVector[i][j].Type == 53 
				&&
				((Test1(BlocksVector, i, j, "NNN0NNNN") && (BlocksVector[i][j+1].Type == 60 || BlocksVector[i][j+1].Type == 65)) 
				|| 
				(Test1(BlocksVector, i, j, "NNN-NNNN") && BlocksVector[i][j+1].Type == 25)) )
				BlocksVector[i][j].Type = 117;
			// Down water - left up angle
			if ( BlocksVector[i][j].Type == 53 
				&&
				((Test1(BlocksVector, i, j, "NN0NNNNN") && (BlocksVector[i][j-1].Type == 60 || BlocksVector[i][j-1].Type == 64))
				||
				(Test1(BlocksVector, i, j, "NN-NNNNN") && BlocksVector[i][j-1].Type == 25)) )
				BlocksVector[i][j].Type = 118;
			// Left water - right down angle
			if ( BlocksVector[i][j].Type == 55 
				&&
				((Test1(BlocksVector, i, j, "N0NNNNNN") && (BlocksVector[i+1][j].Type == 61 || BlocksVector[i+1][j].Type == 63))
				||
				(Test1(BlocksVector, i, j, "N-NNNNNN") && BlocksVector[i+1][j].Type == 26)) )
				BlocksVector[i][j].Type = 119;
			// Right water - left down angle
			if ( BlocksVector[i][j].Type == 54 
				&&
				((Test1(BlocksVector, i, j, "N0NNNNNN") && (BlocksVector[i+1][j].Type == 61 || BlocksVector[i+1][j].Type == 63))
				||
				(Test1(BlocksVector, i, j, "N-NNNNNN") && BlocksVector[i+1][j].Type == 26)) )
				BlocksVector[i][j].Type = 120;
			// Left water - right up angle
			if ( BlocksVector[i][j].Type == 55 
				&& 
				((Test1(BlocksVector, i, j, "0NNNNNNN") && (BlocksVector[i-1][j].Type == 62 || BlocksVector[i-1][j].Type == 61)) 
				||
				(Test1(BlocksVector, i, j, "-NNNNNNN") && BlocksVector[i-1][j].Type == 26)) )
				BlocksVector[i][j].Type = 121;
			// Right water - left up angle
			if ( BlocksVector[i][j].Type == 54 
				&&
				((Test1(BlocksVector, i, j, "0NNNNNNN") && (BlocksVector[i-1][j].Type == 62 || BlocksVector[i-1][j].Type == 61))
				||
				(Test1(BlocksVector, i, j, "-NNNNNNN") && BlocksVector[i-1][j].Type == 26)) )
				BlocksVector[i][j].Type = 122;
			//
			BlocksVector[i][j].Update();
		}
	}
}