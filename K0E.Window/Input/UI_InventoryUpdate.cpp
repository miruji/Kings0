#include "../Window.h"

bool ThisStringEqually(string Text, string Equally)
{
	// ... 
	bool Result = true;

	for (size_t i = 0; i < Equally.size(); i++)
	{
		if (Text[i] != Equally[i])
		{
			return false;
		}
	}

	return Result;
}

// UI: Inventory update 
void Window::UI_InventoryUpdate() 
{
	// ... 
	vector<UIBlock*> UIBlocks = UI1->GetDrawUIBlocks();
	vector<UIImage*> UIImages;
	vector<Settlement> Settlements;

	for (size_t i = 0; i < UIBlocks.size(); i++)
	if (UIBlocks[i]->GetName() == "GameSettlementMarket" || UIBlocks[i]->GetName() == "GameSettlementTavern")
	{
		// ... 
		UIImages = UIBlocks[i]->UI_Image;
		for (size_t j = 0; j < UIImages.size(); j++)
		if ( ThisStringEqually(UIImages[j]->GetId(), "TradeUnit") )
		{
			// True
			//for (size_t q = 0; q < Game1->Castes.size(); q++)
			//{
			Settlements = Game1->Castes[Game1->Player1->Team]->Settlements;
			for (size_t t = 0; t < Settlements.size(); t++)
			{
				// If player in settlement 
				if (Settlements[t].X == Game1->Player1->X &&
					Settlements[t].Y == Game1->Player1->Y)
				{
					// Update 
					for (size_t p = 0; p < 16; p++)
					{
						// ...
						if (UIBlocks[i]->GetName() == "GameSettlementMarket")
						{
							if (Settlements[t].GetItemsMarket().size() > p)
							{
								UIImages[j+p]->SetNewSprite( Settlements[t].GetItemMarket( p )->GetSprite() );
							}
							else
							{
								for (size_t r = 0; r < Game1->Items.size(); r++)
								if (Game1->Items[r]->GetName() == "None")
								{
									UIImages[j+p]->SetNewSprite( Game1->Items[r]->GetSprite() );
									break;
								}
							}
						}
						else
						if (UIBlocks[i]->GetName() == "GameSettlementTavern")
						{
							if (Settlements[t].GetItemsTavern().size() > p)
							{
								UIImages[j+p]->SetNewSprite( Settlements[t].GetItemTavern( p )->GetSprite() );
							}
							else
							{
								for (size_t r = 0; r < Game1->Items.size(); r++)
								if (Game1->Items[r]->GetName() == "None")
								{
									UIImages[j+p]->SetNewSprite( Game1->Items[r]->GetSprite() );
									break;
								}
							}
						}
						// ... 
					}
				}
				// ... 
			}
			break;
			//}
		}
	// ... 
	}
}