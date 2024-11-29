#include "../Window.h"

// Game: in (to) settlement 
void Window::Game_InSettlement(MapBlock& Block, bool Attack)
{
	// !!! Settlement in (to)
	if (Block.Settlement)
	{
		// Clear blocks 
		if (!Attack)
			UIClearDrawBlocks(false);
		// Reset UI
			// all XML block
			for (size_t i = 0; i < Game1->Castes.size(); i++)
			for (size_t j = 0; j < Game1->Castes[i]->Settlements.size(); j++)
			{
				// ...
				if (Game1->Castes[i]->Settlements[j].X == Block.X &&
					Game1->Castes[i]->Settlements[j].Y == Block.Y)
				{
					// ! Player in settlement = true (Draw)
					Game1->Player1->SettlementType = Game1->Castes[i]->Settlements[j].GetType();
					Game1->Player1->SettlementName = Game1->Castes[i]->Settlements[j].Name;

					// This settlement now is opened ! 
					if (Game1->Castes[i]->Settlements[j].Opened == false)
						Game1->Castes[i]->Settlements[j].Opened = true;
				}
			}

		// Update items 
		if (Game1->Castes[Game1->Player1->Team]->Settlements[Block.Settlement-1].GetItems().size() <= 0)
		{
			UI_InventoryUnitClearUpdate();
			TradeItemsUpdate();
		}

		// play sound 
		if (Game1->Player1->SettlementType == SettlementTypes::Settlement)
			Audio1->PlaySound1("Settlement0");
		else
		if (Game1->Player1->SettlementType == SettlementTypes::Barn)
		{
			size_t Random = GetRandomNumber(0, 1);
			if (Random == 0)
				Audio1->PlaySound1("Barn0");
			else
			if (Random == 1)
				Audio1->PlaySound1("Barn1");
		}
		else
		if (Game1->Player1->SettlementType == SettlementTypes::Sawmill)
		{
			size_t Random = GetRandomNumber(0, 1);
			if (Random == 0)
				Audio1->PlaySound1("Sawmill0");
			else
			if (Random == 1)
				Audio1->PlaySound1("Sawmill1");
		}
	}
	// !!! Settlement out
	else
	{
		// ! Player in settlement = false (Draw) 
		if (Game1->Player1->SettlementType != SettlementTypes::None)
		{
			//
			Game1->Player1->SettlementType = SettlementTypes::None;
			Game1->Player1->SettlementName = "";

			// To back (basic) UI 
			if (!Attack)
				UIClearDrawBlocks(false);
		}
	}
	//
}
