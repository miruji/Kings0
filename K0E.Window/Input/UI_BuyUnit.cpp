#include "../Window.h"

// Buy unit 
void Window::UI_BuyUnit()
{
	//
	for (size_t i = UI1->FocusedBlockName; i < UI1->GetDrawUIBlocks().size(); i++)
	{
		// If cash >= 0 
		if (Game1->Castes[Game1->Player1->Team]->PreviewCash-atoi(GetItemStatus("Cost", i).c_str()) >= 0)
		{
			// Add resource 
			if (GetItemStatus("Class", i) == "Food")
				Game1->Castes[Game1->Player1->Team]->PreviewFood += atoi(GetItemStatus("Size", i).c_str());
			else
			if (GetItemStatus("Class", i) == "Wood")
				Game1->Castes[Game1->Player1->Team]->PreviewWood += atoi(GetItemStatus("Size", i).c_str());
			else
			if (GetItemStatus("Class", i) == "Army")
			{
				if (Game1->Castes[Game1->Player1->Team]->PreviewPopulation-atoi(GetItemStatus("Size", i).c_str()) < 0)
				{
					NeedResources = GetItemStatus("Size", i)+"P";
					return;
				}
				Game1->Castes[Game1->Player1->Team]->PreviewPopulation -= atoi(GetItemStatus("Size", i).c_str());
				Game1->Castes[Game1->Player1->Team]->PreviewArmy       += atoi(GetItemStatus("Size", i).c_str());
			}
			Game1->Castes[Game1->Player1->Team]->PreviewCash -= atoi(GetItemStatus("Cost", i).c_str());
			// delete item 
			DeleteItem("Class", i);
			// play sound
			size_t Random = GetRandomNumber(0, 1);
			if (Random == 0)
				Audio1->PlaySound1("Buy0");
			else
			if (Random == 1)
				Audio1->PlaySound1("Buy4");
		}
		else
		{
			NeedResources = GetItemStatus("Cost", i)+"G";
		}
		break;
	}
}