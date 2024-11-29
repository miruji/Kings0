#include "../Window.h"

// Update map pointer 
void Window::UI_UpdateMapPointer(bool Attack)
{
	//
	size_t ii = 0, jj = 0;

	//
	if (MapPointer1->GetX() == Game1->Player1->X && MapPointer1->GetY() == Game1->Player1->Y)
		MapPointer1->XAdd = 0;
	else
		MapPointer1->XAdd = 4;

	for (size_t i = 0; i < Game1->Castes.size(); i++)
	{
		for (size_t j = 0; j < Game1->Castes[i]->Settlements.size(); j++)
		{
			if (Game1->Castes[i]->Settlements[j].X == MapPointer1->GetX() && Game1->Castes[i]->Settlements[j].Y == MapPointer1->GetY())
			{
				MapPointer1->XAdd = 0;
				ii = i; jj = j;
				break;
			}
		}
		for (size_t j = 0; j < Game1->Castes[i]->Units.size(); j++)
		{
			if (Game1->Castes[i]->Units[j]->X == MapPointer1->GetX() && Game1->Castes[i]->Units[j]->Y == MapPointer1->GetY())
			{
				MapPointer1->XAdd = 0;
				break;
			}
		}
	}
	//
	MapBlock MapBlock1 = LandMap1->BlocksVector[MapPointer1->GetY()/32][MapPointer1->GetX()/32];
	if (MapBlock1.Settlement != 0)
	{
		size_t SettlementType1 = Game1->Castes[ii]->Settlements[jj].GetTypeInt();
		//
		if (SettlementType1 == 0)
			UI_LeftBlockUpdate("LeftBlockNone");
		else
		//
		if (SettlementType1 == 1)
			UI_LeftBlockUpdate("LeftBlockSettlement");
		else
		if (SettlementType1 == 2)
			UI_LeftBlockUpdate("LeftBlockBarn");
		else
		//
		if (SettlementType1 == 3)
			UI_LeftBlockUpdate("LeftBlockWall");
		else
		if (SettlementType1 == 4)
			UI_LeftBlockUpdate("LeftBlockTower");
		else
		if (SettlementType1 == 5)
			UI_LeftBlockUpdate("LeftBlockCastle");
		else
		//
		if (SettlementType1 == 6)
			UI_LeftBlockUpdate("LeftBlockField");
		else
		if (SettlementType1 == 7)
			UI_LeftBlockUpdate("LeftBlockPasture");
		else
		if (SettlementType1 == 8)
			UI_LeftBlockUpdate("LeftBlockFisheries");
		else
		//
		if (SettlementType1 == 9)
			UI_LeftBlockUpdate("LeftBlockSuburb");
		else
		if (SettlementType1 == 10)
			UI_LeftBlockUpdate("LeftBlockSawmill");
	}
	else
	{
		if (MapBlock1.Lake)
		{
			// Lake 
			UI_LeftBlockUpdate("LeftBlockLake");
		}
		else
		if (!MapBlock1.River)
		{
			// Land 
			if (MapBlock1.Mountain && MapBlock1.Forest)
			{
				// Forest mountain 
				UI_LeftBlockUpdate("LeftBlockForestMountain");
			}
			else
			if (MapBlock1.Mountain && !MapBlock1.Land)
			{
				// Water mountain 
				UI_LeftBlockUpdate("LeftBlockWaterMountain");
			}
			else
			if (MapBlock1.Mountain)
			{
				// Mountain 
				UI_LeftBlockUpdate("LeftBlockMountain");
			}
			else
			if (MapBlock1.Forest)
			{
				// Forest 
				UI_LeftBlockUpdate("LeftBlockForest");
			}
			else
			{
				// Land
				if (MapBlock1.Land)
					UI_LeftBlockUpdate("LeftBlockLand");
				// Water
				else
					UI_LeftBlockUpdate("LeftBlockWater");
			}
		}
		else
		{
			// River 
			UI_LeftBlockUpdate("LeftBlockRiver");
		}
	}

	bool Hide = false;
	if (true)
	{
	Settlement Settlement1;
	for (size_t i = 0; i < Game1->Castes.size(); i++)
	for (size_t j = 0; j < Game1->Castes[i]->Settlements.size(); j++)
	{
		Settlement1 = Game1->Castes[i]->Settlements[j];
		if (Game1->Player1->X == Settlement1.X && Game1->Player1->Y == Settlement1.Y && 
			Game1->Player1->Team != Settlement1.Team)
		{
			Hide = true;
			break;
		}
	}
	}

	if (MapPointer1->GetX() != Game1->Player1->X || MapPointer1->GetY() != Game1->Player1->Y || Attack || Hide || Game1->Player1->Die)
	{
		UI_LeftBlockHideButtons();
	}
	else
	{
		for (size_t i = 0; i < UI1->GetDrawUIBlocks().size(); i++)
		{
			string Name = UI1->GetDrawUIBlocks()[i]->GetName();
			Name.erase(Name.begin()+9, Name.end());
			if (Name == "LeftBlock")
			{
				if (LeftBlockMinimize == false)
					UI1->GetDrawUIBlocks()[i]->SetWH(192*UI1->ResizeWidth, UI1->GetDrawUIBlocks()[i]->GetWH().y);
				else
					UI1->GetDrawUIBlocks()[i]->SetWH(97*UI1->ResizeWidth, UI1->GetDrawUIBlocks()[i]->GetWH().y);
				vector<UIImage*> UIImages = UI1->GetDrawUIBlocks()[i]->UI_Image;
				for (size_t j = 0; j < UIImages.size(); j++)
				{
					if (UIImages[j]->GetId() == "Window")
					{
						Name = "Data\\Textures\\UI\\"+UI1->GetDrawUIBlocks()[i]->GetName()+"0.png";
						UIImages[j]->LoadTextureToSprite(Name, to_string(UIImages[j]->GetWH().x), to_string(UIImages[j]->GetWH().y));
						break;
					}
				}
				ShowAllElements(i);
				break;
			}
		}
		//
	}
}