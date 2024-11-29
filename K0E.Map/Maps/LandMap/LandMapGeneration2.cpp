#include "LandMap.h"

// (Block update)
void LandMap::Generate2BlockUpdate(MapBlock& Block)
{
	// Block update
	Block.River = true;
	Block.Update();
}

// Generate map 2 (Rivers)
void LandMap::Generate2() 
{
	// First generate
	bool RiverTrue = true;

	for (size_t i = 0; i < BlocksVector.size()-1; i++) 
	for (size_t j = 0; j < BlocksVector[i].size(); j++) 
	{
		//
		if (BlocksVector[i][j].Land == false && i >= 1 && j >= 1) {
			// Main rivers
			// Up river - Centr - Down river
			if (Test1(BlocksVector, i, j, "--00NNNN"))
				BlocksVector[i][j].Type = 3;
			else
			// Left river - Centr - Right river
			if (Test1(BlocksVector, i, j, "00--NNNN"))
				BlocksVector[i][j].Type = 4;
			else
			// Angle rives
			// Left river - Centr - Down river
			if (Test1(BlocksVector, i, j, "0--0NN0N"))
				BlocksVector[i][j].Type = 5;
			else
			// Right river - Centr - Down river
			if (Test1(BlocksVector, i, j, "0-0-NNN0"))
				BlocksVector[i][j].Type = 6;
			else
			// Left river - Centr - Up river
			if (Test1(BlocksVector, i, j, "-0-00NNN"))
				BlocksVector[i][j].Type = 7;
			else
			// Left river - Centr - Up river
			if (Test1(BlocksVector, i, j, "-00-N0NN"))
				BlocksVector[i][j].Type = 8;
			else
			// Rivers connection
			// Left to Up river - Centr - Down river
			if (Test1(BlocksVector, i, j, "---00000"))
				BlocksVector[i][j].Type = 9;
			else
			// Right to Up river - Centr - Down river
			if (Test1(BlocksVector, i, j, "--0-0000"))
				BlocksVector[i][j].Type = 10;
			else
			// Up to Left river - Centr - Right river
			if (Test1(BlocksVector, i, j, "-0--0000"))
				BlocksVector[i][j].Type = 11;
			else
			// Down to Left river - Centr - Right river
			if (Test1(BlocksVector, i, j, "0---0000"))
				BlocksVector[i][j].Type = 12;
			else
			// Centr
			if (Test1(BlocksVector, i, j, "----0000"))
				BlocksVector[i][j].Type = 27;
			else
			// Leke
			if (Test1(BlocksVector, i, j, "0000NNNN"))
			{
				BlocksVector[i][j].Type = 82;
				BlocksVector[i][j].Lake = true;
			}
			else
				RiverTrue = false;

			// Block update
			if (RiverTrue == true)
				Generate2BlockUpdate(BlocksVector[i][j]);
			else
			{
				RiverTrue = true;
				BlocksVector[i][j].Update();
			}
			//
		}
	}
	RiverTrue = true;
	// Second generate (LAND CONNECTED 1)
	for (size_t i = 0; i < BlocksVector.size()-1; i++) 
	for (size_t j = 0; j < BlocksVector[i].size(); j++) 
	{
		//
		if (BlocksVector[i][j].Land == false && (i >= 1 && j >= 1) )
		{
			// Rivers end
			// Down (river) - Centr - End
			if (Test1(BlocksVector, i, j, "0-00NNNN"))
			{
				if (BlocksVector[i+1][j].River == true )
					BlocksVector[i][j].Type = 13;
				else
					BlocksVector[i][j].Type = 17;
			}
			else
			// Up (river) - Centr - End
			if (Test1(BlocksVector, i, j, "-000NNNN"))
			{
				if ( BlocksVector[i-1][j].River == true )
					BlocksVector[i][j].Type = 14;
				else
					BlocksVector[i][j].Type = 18;
			}
			else
			// Left (river) - Centr - End
			if (Test1(BlocksVector, i, j, "00-0NNNN")) 
			{
				if ( BlocksVector[i][j-1].River == true )
					BlocksVector[i][j].Type = 15;
				else
					BlocksVector[i][j].Type = 19;
			}
			else
			// Right (river) - Centr - End
			if (Test1(BlocksVector, i, j, "000-NNNN"))
			{
				if ( BlocksVector[i][j+1].River == true )
					BlocksVector[i][j].Type = 16;
				else 
					BlocksVector[i][j].Type = 20;
			}
			else
				RiverTrue = false;

			// Block update
			if (RiverTrue == true)
				Generate2BlockUpdate(BlocksVector[i][j]);
			else
			{
				RiverTrue = true;
				BlocksVector[i][j].Update();
			}
			//
		}
	}
	RiverTrue = true;
	// Second generate (LAND CONNECTED 1(2))
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

			// Block update
			BlocksVector[i][j].Update();
		}
	}
	RiverTrue = true;
	// Second generate (LAND CONNECTED 2)
	for (size_t i = 0; i < BlocksVector.size()-1; i++) 
	for (size_t j = 0; j < BlocksVector[i].size(); j++) 
	{
		//
		if (BlocksVector[i][j].Land == false && (i >= 1 && j >= 1) )
		{
			// Main rivers
			// Up - Centr - Down to river
			if ( (Test1(BlocksVector, i, j, "--00--NN") || Test1(BlocksVector, i, j, "--00-NNN") || Test1(BlocksVector, i, j, "--00N-NN") ) )
			{
				if (BlocksVector[i-1][j].River == false && BlocksVector[i+1][j].River == true)
					BlocksVector[i][j].Type = 21;
			}
			// Down river - Centr - Up
			if ( (Test1(BlocksVector, i, j, "--00NN--") || Test1(BlocksVector, i, j, "--00NN-N") || Test1(BlocksVector, i, j, "--00NNN-") ) )
			{
				if (BlocksVector[i+1][j].River == false && BlocksVector[i-1][j].River == true)
					BlocksVector[i][j].Type = 22;
			}
			// Left - Centr - Right river
			if ( (Test1(BlocksVector, i, j, "00---N-N") || Test1(BlocksVector, i, j, "00---NNN") || Test1(BlocksVector, i, j, "00--NN-N") ) )
			{
				if (BlocksVector[i][j-1].River == false && BlocksVector[i][j+1].River == true)
					BlocksVector[i][j].Type = 23;
			}
			// Right river - Centr - Left
			if ( (Test1(BlocksVector, i, j, "00--N-N-") || Test1(BlocksVector, i, j, "00--N-NN") || Test1(BlocksVector, i, j, "00--NNN-") ) )
			{
				if (BlocksVector[i][j+1].River == false && BlocksVector[i][j-1].River == true)
					BlocksVector[i][j].Type = 24;
			}
			// Up - Centr - Down
			if ( (Test1(BlocksVector, i, j, "--00NNNN")) )
			{
				if (BlocksVector[i-1][j].River == false && BlocksVector[i+1][j].River == false)
					BlocksVector[i][j].Type = 25;
			}
			else
			// Left - Centr - Right (Centr)
			if ( (Test1(BlocksVector, i, j, "00--NNNN")) )
			{
				if (BlocksVector[i][j-1].River == false && BlocksVector[i][j+1].River == false)
					BlocksVector[i][j].Type = 26;
			}
			else
				RiverTrue = false;

			// Block update
			if (RiverTrue == true)
				Generate2BlockUpdate(BlocksVector[i][j]);
			else
			{
				RiverTrue = true;
				BlocksVector[i][j].Update();
			}
			//
		}
	}
	RiverTrue = true;
	// Third generate (LAND CONNECTED 3)
	for (size_t i = 0; i < BlocksVector.size()-1; i++) 
	for (size_t j = 0; j < BlocksVector[i].size(); j++) 
	{
		//
		if (BlocksVector[i][j].Land == false && (i >= 1 && j >= 1) )
		{
			// Angle rives (Angle land not) (first)
			// Left river - Centr - Down river
			if (Test1(BlocksVector, i, j, "0--0NN0N") && BlocksVector[i+1][j].River == false)
			{
				//
				if (BlocksVector[i][j-1].Type == 23)
				{
					BlocksVector[i][j-1].Type = 36;
					BlocksVector[i][j-1].Update();
				}
				else 
				{
					//
					if (BlocksVector[i][j-1].Type == 4 && BlocksVector[i+1][j-1].Land == true)
					{
						BlocksVector[i][j-1].Type = 45;
						BlocksVector[i][j-1].Update();
					}
				}
				//
				if (BlocksVector[i-1][j-1].Type != 1 && BlocksVector[i-1][j-1].Type != 25)
					BlocksVector[i][j].Type = 28;
				else
					BlocksVector[i][j].Type = 88;
			}
			else
			// Right river - Centr - Down river
			if (Test1(BlocksVector, i, j, "0-0-NNN0") && BlocksVector[i+1][j].River == false)
			{
				//
				if (BlocksVector[i][j+1].Type == 24)
				{
					BlocksVector[i][j+1].Type = 37;
					BlocksVector[i][j+1].Update();
				}
				else 
				{
					//
					if (BlocksVector[i][j+1].Type == 4 && BlocksVector[i][j+2].Type == 5)
						BlocksVector[i][j+1].Type = 83;
					else
					{
						if (BlocksVector[i-1][j+1].Land == true)
							BlocksVector[i][j+1].Type = 44;
					}
					BlocksVector[i][j+1].Update();
				}
				//
				if (BlocksVector[i-1][j+1].Type != 1 && BlocksVector[i-1][j+1].Type != 25)
					BlocksVector[i][j].Type = 29;
				else 
					BlocksVector[i][j].Type = 89;
			}
			else
			// Left river - Centr - Up river
			if (Test1(BlocksVector, i, j, "-0-00NNN") && BlocksVector[i][j-1].River == false)
			{
				//
				if (BlocksVector[i-1][j].Type == 21)
				{
					BlocksVector[i-1][j].Type = 38;
					BlocksVector[i-1][j].Update();
				}
				else
				{
					//
					if (BlocksVector[i-1][j].Type == 3 && BlocksVector[i-1][j+1].Land == true)
					{
						BlocksVector[i-1][j].Type = 50;
						BlocksVector[i-1][j].Update();
					}
				}
				//
				if (BlocksVector[i-1][j+1].Type != 1 && BlocksVector[i-2][j].Type != 88)
					BlocksVector[i][j].Type = 30;
				else 
					BlocksVector[i][j].Type = 90;
			}
			else
			// Left river - Centr - Up river
			if (Test1(BlocksVector, i, j, "-00-N0NN") && BlocksVector[i][j+1].River == false)
			{
				//
				if (BlocksVector[i-1][j].Type == 21)
				{
					BlocksVector[i-1][j].Type = 39;
					BlocksVector[i-1][j].Update();
				}
				else
				{
					//
					if (BlocksVector[i-1][j].Type == 3 && BlocksVector[i-1][j-1].Land == true)
					{
						BlocksVector[i-1][j].Type = 51;
						BlocksVector[i-1][j].Update();
					}
				}
				//
				if (BlocksVector[i-1][j-1].Type != 1 && BlocksVector[i-2][j].Type != 89)
					BlocksVector[i][j].Type = 31;
				else 
					BlocksVector[i][j].Type = 91;
			}
			else
			// Angle rives (Angle land not) (second)
			// Left river - Centr - Down river
			if (Test1(BlocksVector, i, j, "0--0NN0N") && BlocksVector[i][j-1].River == false)
			{
				//
				if (BlocksVector[i+1][j].Type == 22)
				{
					BlocksVector[i+1][j].Type = 40;
					BlocksVector[i+1][j].Update();
				}
				else
				{
					//
					if (BlocksVector[i+1][j].Type == 3 && BlocksVector[i+2][j].Type == 7)
						BlocksVector[i+1][j].Type = 85;
					else
						BlocksVector[i+1][j].Type = 46;

					BlocksVector[i+1][j].Update();
				}
				//
				BlocksVector[i][j].Type = 32;
			}
			else
			// Right river - Centr - Down river
			if (Test1(BlocksVector, i, j, "0-0-NNN0") && BlocksVector[i][j+1].River == false)
			{
				//
				if (BlocksVector[i+1][j].Type == 22)
				{
					BlocksVector[i+1][j].Type = 41;
					BlocksVector[i+1][j].Update();
				}
				else
				{
					//
					if (BlocksVector[i+1][j].Type == 3 && BlocksVector[i+2][j].Type == 8)
						BlocksVector[i+1][j].Type = 86;
					else
						BlocksVector[i+1][j].Type = 47;

					BlocksVector[i+1][j].Update();
				}
				//
				BlocksVector[i][j].Type = 33;
			}
			else
			// Left river - Centr - Up river
			if (Test1(BlocksVector, i, j, "-0-00NNN") && BlocksVector[i-1][j].River == false)
			{
				//
				if (BlocksVector[i][j-1].Type == 23)
				{
					BlocksVector[i][j-1].Type = 42;
					BlocksVector[i][j-1].Update();
				}
				else
				{
					//
					if (BlocksVector[i][j-1].Type == 4 && BlocksVector[i-1][j-1].Land == true)
					{
						BlocksVector[i][j-1].Type = 49;
						BlocksVector[i][j-1].Update();
					}
				}
				//
				BlocksVector[i][j].Type = 34;
			}
			else
			// Left river - Centr - Up river
			if (Test1(BlocksVector, i, j, "-00-N0NN") && BlocksVector[i-1][j].River == false)
			{
				//
				if (BlocksVector[i][j+1].Type == 24)
				{
					BlocksVector[i][j+1].Type = 43;
					BlocksVector[i][j+1].Update();
				}
				else
				{
					//
					if (BlocksVector[i][j+1].Type == 4 && BlocksVector[i][j+2].Type == 7)
						BlocksVector[i][j+1].Type = 84;
					else
						BlocksVector[i][j+1].Type = 48;

					BlocksVector[i][j+1].Update();
				}
				//
				BlocksVector[i][j].Type = 35;
			}
			else
			// Angle rives (Angle land not) (fourth)
			if (BlocksVector[i][j].River == true) {
				// 
				if ( (Test1(BlocksVector, i, j, "0--0-N0N") )
					 && BlocksVector[i][j-1].River   == true
					 && BlocksVector[i+1][j].River   == true
					 && BlocksVector[i-1][j-1].River == true)
					BlocksVector[i][j].Type = 70;
				if ( (Test1(BlocksVector, i, j, "0--0NN0-") )
					 && BlocksVector[i][j-1].River   == true
					 && BlocksVector[i+1][j].River   == true
					 && BlocksVector[i+1][j+1].River == true)
					BlocksVector[i][j].Type = 66;
				//
				if ( (Test1(BlocksVector, i, j, "0-0-N-N0") )
					 && BlocksVector[i][j+1].River   == true
					 && BlocksVector[i+1][j].River   == true
					 && BlocksVector[i-1][j+1].River == true)
					BlocksVector[i][j].Type = 71;
				if ( (Test1(BlocksVector, i, j, "0-0-NN-0") )
					 && BlocksVector[i][j+1].River   == true
					 && BlocksVector[i+1][j].River   == true
					 && BlocksVector[i+1][j-1].River == true)
					BlocksVector[i][j].Type = 67;
				//
				if ( (Test1(BlocksVector, i, j, "-0-00-NN") )
					 && BlocksVector[i][j-1].River   == true
					 && BlocksVector[i-1][j].River   == true
					 && BlocksVector[i-1][j+1].River == true)
					BlocksVector[i][j].Type = 68;
				if ( (Test1(BlocksVector, i, j, "-0-00N-N") )
					 && BlocksVector[i][j-1].River   == true
					 && BlocksVector[i-1][j].River   == true
					 && BlocksVector[i+1][j-1].River == true)
					BlocksVector[i][j].Type = 72;
				//
				if ( (Test1(BlocksVector, i, j, "-00--0NN") )
					 && BlocksVector[i][j+1].River   == true
					 && BlocksVector[i-1][j].River   == true
					 && BlocksVector[i-1][j-1].River == true)
					BlocksVector[i][j].Type = 69;
				if ( (Test1(BlocksVector, i, j, "-00--N0N-") )
					 && BlocksVector[i][j+1].River   == true
					 && BlocksVector[i-1][j].River   == true
					 && BlocksVector[i+1][j+1].River == true)
					BlocksVector[i][j].Type = 73;
				// Centr
				if ( ( Test1(BlocksVector, i, j, "0--0-N0-")
					 && BlocksVector[i][j-1].River   == true
					 && BlocksVector[i+1][j].River   == true
					 && BlocksVector[i+1][j+1].River == true
					 && BlocksVector[i-1][j-1].River == true)
					||
					(Test1(BlocksVector, i, j, "0--00N00") || Test1(BlocksVector, i, j, "0--00N0-") || Test1(BlocksVector, i, j, "0--0-N00")) )
					BlocksVector[i][j].Type = 5;
				if ( ( Test1(BlocksVector, i, j, "0-0-N--0")
					 && BlocksVector[i][j+1].River   == true
					 && BlocksVector[i+1][j].River   == true
					 && BlocksVector[i-1][j+1].River == true
					 && BlocksVector[i+1][j-1].River == true)
					||
					(Test1(BlocksVector, i, j, "0-0-N000") || Test1(BlocksVector, i, j, "0-0-N0-0") || Test1(BlocksVector, i, j, "0-0-N-00")) )
					BlocksVector[i][j].Type = 6;
				if ( ( Test1(BlocksVector, i, j, "-0-00--N")
					 && BlocksVector[i][j-1].River   == true
					 && BlocksVector[i-1][j].River   == true
					 && BlocksVector[i-1][j+1].River == true
					 && BlocksVector[i+1][j-1].River == true)
					||
					(Test1(BlocksVector, i, j, "-0-0000N") || Test1(BlocksVector, i, j, "-0-000-N") || Test1(BlocksVector, i, j, "-0-00-0N")) )
					BlocksVector[i][j].Type = 7;
				if ( ( Test1(BlocksVector, i, j, "-00--0N-")
					 && BlocksVector[i][j+1].River   == true
					 && BlocksVector[i-1][j].River   == true
					 && BlocksVector[i-1][j-1].River == true
					 && BlocksVector[i+1][j+1].River == true)
					||
					(Test1(BlocksVector, i, j, "-00-00N0") || Test1(BlocksVector, i, j, "-00-00N-") || Test1(BlocksVector, i, j, "-00--0N0")) )
					BlocksVector[i][j].Type = 8;
				//
			}
			else
				RiverTrue = false;

			// Block update
			if (RiverTrue == true)
				Generate2BlockUpdate(BlocksVector[i][j]);
			else
			{
				RiverTrue = true;
				BlocksVector[i][j].Update();
			}
			//
		}
	}
	// River anles fix (...)
	for (size_t i = 0; i < BlocksVector.size()-1; i++) 
	for (size_t j = 0; j < BlocksVector[i].size(); j++) 
	{
		//
		if (BlocksVector[i][j].River == true) 
		{
			//
			if (BlocksVector[i][j].Type == 7 && BlocksVector[i-1][j].Type == 85) 
			{
				BlocksVector[i-1][j].Type = 46;
				BlocksVector[i-1][j].Update();
			}
			else
			//
			if (BlocksVector[i][j].Type == 8 && BlocksVector[i-1][j].Type == 86) 
			{
				BlocksVector[i-1][j].Type = 47;
				BlocksVector[i-1][j].Update();
			}
			else
			//
			if (BlocksVector[i][j].Type == 35 && BlocksVector[i][j+1].Type == 84
				&& BlocksVector[i][j+2].Type != 34) 
			{
				BlocksVector[i][j+1].Type = 48;
				BlocksVector[i][j+1].Update();
			}
			else
			//
			if (BlocksVector[i][j].Type == 29 && BlocksVector[i][j+1].Type == 83
				&& BlocksVector[i][j+2].Type != 28) 
			{
				BlocksVector[i][j+1].Type = 44;
				BlocksVector[i][j+1].Update();
			}
			// !!! FIX 2
			// Up
			if (BlocksVector[i][j].Type == 31 && BlocksVector[i-1][j].Type == 5) 
			{
				BlocksVector[i-1][j].Type = 70;
				BlocksVector[i-1][j].Update();
			}
			else
			if (BlocksVector[i][j].Type == 30 && BlocksVector[i-1][j].Type == 6) 
			{
				BlocksVector[i-1][j].Type = 71;
				BlocksVector[i-1][j].Update();
			}
			else
			// Down
			if (BlocksVector[i][j].Type == 33 && BlocksVector[i+1][j].Type == 7) 
			{
				BlocksVector[i+1][j].Type = 72;
				BlocksVector[i+1][j].Update();
			}
			else
			//
			if (BlocksVector[i][j].Type == 32 && BlocksVector[i+1][j].Type == 8) 
			{
				BlocksVector[i+1][j].Type = 73;
				BlocksVector[i+1][j].Update();
			}
			else
			// Right
			if (BlocksVector[i][j].Type == 29 && BlocksVector[i][j+1].Type == 7) 
			{
				BlocksVector[i][j+1].Type = 68;
				BlocksVector[i][j+1].Update();
			}
			else
			if (BlocksVector[i][j].Type == 35 && BlocksVector[i][j+1].Type == 5) 
			{
				BlocksVector[i][j+1].Type = 66;
				BlocksVector[i][j+1].Update();
			}
			else
			// Left
			if (BlocksVector[i][j].Type == 28 && BlocksVector[i][j-1].Type == 8) 
			{
				BlocksVector[i][j-1].Type = 69;
				BlocksVector[i][j-1].Update();
			}
			else
			if (BlocksVector[i][j].Type == 34 && BlocksVector[i][j-1].Type == 6) 
			{
				BlocksVector[i][j-1].Type = 67;
				BlocksVector[i][j-1].Update();
			}
			//
		}
		//
	}
}