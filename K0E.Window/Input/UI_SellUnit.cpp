#include "../Window.h"

// Sell unit 
void Window::UI_SellUnit()
{
	//
	bool play_music = false;
	for (size_t i = UI1->FocusedBlockName; i < UI1->GetDrawUIBlocks().size(); i++)
	{
		// If food && cash >= 0 
		if (GetItemStatus("Class", i) == "Food")
		{
			if (Game1->Castes[Game1->Player1->Team]->PreviewFood-atoi(GetItemStatus("Size", i).c_str()) >= 0)
			{
				Game1->Castes[Game1->Player1->Team]->PreviewFood -= atoi(GetItemStatus("Size", i).c_str());
				Game1->Castes[Game1->Player1->Team]->PreviewCash += atoi(GetItemStatus("Cost", i).c_str())/4;
				DeleteItem("Class", i);
				play_music = true;
			}
			else
				NeedResources = GetItemStatus("Size", i)+"F";
		}
		else
		if (GetItemStatus("Class", i) == "Wood")
		{
			if (Game1->Castes[Game1->Player1->Team]->PreviewWood-atoi(GetItemStatus("Size", i).c_str()) >= 0)
			{
				Game1->Castes[Game1->Player1->Team]->PreviewWood -= atoi(GetItemStatus("Size", i).c_str());
				Game1->Castes[Game1->Player1->Team]->PreviewCash += atoi(GetItemStatus("Cost", i).c_str())/4;
				DeleteItem("Class", i);
				play_music = true;
			}
			else
				NeedResources = GetItemStatus("Size", i)+"W";
		}
		else
		if (GetItemStatus("Class", i) == "Army")
		{
			if (Game1->Castes[Game1->Player1->Team]->PreviewArmy-atoi(GetItemStatus("Size", i).c_str()) >= 0)
			{
				Game1->Castes[Game1->Player1->Team]->PreviewArmy       -= atoi(GetItemStatus("Size", i).c_str());
				Game1->Castes[Game1->Player1->Team]->PreviewPopulation += atoi(GetItemStatus("Size", i).c_str());
				Game1->Castes[Game1->Player1->Team]->PreviewCash       += atoi(GetItemStatus("Cost", i).c_str())/2;
				DeleteItem("Class", i);
				play_music = true;
			}
			else
				NeedResources = GetItemStatus("Size", i)+"A";
		}
			
		break;
	}
	// play sound
	if (play_music)
	{
		size_t Random = GetRandomNumber(0, 2);
		if (Random == 0)
			Audio1->PlaySound1("Buy1");
		else
		if (Random == 1)
			Audio1->PlaySound1("Buy2");
		else
		if (Random == 2)
			Audio1->PlaySound1("Buy3");
	}
}