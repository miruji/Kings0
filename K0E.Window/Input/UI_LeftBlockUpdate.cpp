#include "../Window.h"

void Window::UI_LeftBlockUpdate(string NextBlockName)
{
	if (UI1->MainMenu == false)
	{
		// Search id 
		size_t Num = 0;
		for (size_t i = 0; i < UI1->GetDrawUIBlocks().size(); i++)
		{
			string BlockName = UI1->GetDrawUIBlocks()[i]->GetName();
			string Buffer = "";

			if (BlockName.length() >= 9)
			for (size_t j = 0; j < 9; j++)
			{
				Buffer += BlockName[j];
			}
			if (Buffer == "LeftBlock")
				Num = i;
			
		}
		// Set 
		if (NextBlockName == "")
		{
		MapBlock MapBlock1 = LandMap1->BlocksVector[MapPointer1->GetY()/32][MapPointer1->GetX()/32];
		if (MapBlock1.Settlement)
		{
			//
			if (Game1->Player1->SettlementType == SettlementTypes::Settlement)
				NextBlockName = "LeftBlockSettlement";
			else
			if (Game1->Player1->SettlementType == SettlementTypes::Barn)
				NextBlockName = "LeftBlockBarn";
			else
			//
			if (Game1->Player1->SettlementType == SettlementTypes::Wall)
				NextBlockName = "LeftBlockWall";
			else
			if (Game1->Player1->SettlementType == SettlementTypes::Tower)
				NextBlockName = "LeftBlockTower";
			else
			if (Game1->Player1->SettlementType == SettlementTypes::Castle)
				NextBlockName = "LeftBlockCastle";
			else
			//
			if (Game1->Player1->SettlementType == SettlementTypes::Field)
				NextBlockName = "LeftBlockField";
			else
			if (Game1->Player1->SettlementType == SettlementTypes::Pasture)
				NextBlockName = "LeftBlockPasture";
			else
			if (Game1->Player1->SettlementType == SettlementTypes::Fisheries)
				NextBlockName = "LeftBlockFisheries";
			else
			//
			if (Game1->Player1->SettlementType == SettlementTypes::Suburb)
				NextBlockName = "LeftBlockSuburb";
			else
			if (Game1->Player1->SettlementType == SettlementTypes::Sawmill)
				NextBlockName = "LeftBlockSawmill";
		}
		else
		//
		{
			if (MapBlock1.Lake)
			{
				// Lake 
				NextBlockName = "LeftBlockLake";
			}
			else
			if (!MapBlock1.River)
			{
				// Land 
				if (MapBlock1.Mountain && MapBlock1.Forest)
				{
					// Forest mountain 
					NextBlockName = "LeftBlockForestMountain";
				}
				else
				if (MapBlock1.Mountain && !MapBlock1.Land)
				{
					// Water mountain 
					NextBlockName = "LeftBlockWaterMountain";
				}
				else
				if (MapBlock1.Mountain)
				{
					// Mountain 
					NextBlockName = "LeftBlockMountain";
				}
				else
				if (MapBlock1.Forest)
				{
					// Forest 
					NextBlockName = "LeftBlockForest";
				}
				else
				{
					// Land
					if (MapBlock1.Land)
						NextBlockName = "LeftBlockLand";
					// Water
					else
						NextBlockName = "LeftBlockWater";
				}
			}
			else
			{
				// River 
				NextBlockName = "LeftBlockRiver";
			}
		} }

		// To next block 
		if (LeftBlockMinimize)
			NextBlockName = NextBlockName + "Minimize";
		UIEvent('@', NextBlockName, false, Num, false);

		// Update spec text 
		UI1->SpecTextUpdate = true;
	}
	//
}