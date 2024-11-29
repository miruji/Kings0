#include "../Window.h"

// Game: Delete item 
void Window::DeleteItem(string Type, size_t i)
{
	// ... 
	size_t XPos = 0, YPos = 0, Count = 0;
	vector< UIGif* > UIGifs = UI1->GetDrawUIBlocks()[i]->UI_Gif;
	for (size_t q = 0; q < UIGifs.size(); q++)
	if (UIGifs[q]->GetId() == "TradePointer")
	{
		XPos = size_t((UIGifs[q]->GetXY().x/UI1->ResizeWidth+64)/64);
		YPos = size_t((UIGifs[q]->GetXY().y/UI1->ResizeHeight-64)/64);

		if (YPos == 1)
			Count = XPos;
		else
		if (YPos == 2)
			Count = XPos+4;
		else
		if (YPos == 3)
			Count = XPos+8;
		else
		if (YPos == 4)
			Count = XPos+12;
		Count--;
	}
	Settlement Settlement1;
	for (size_t k = 0; k < Game1->Castes[Game1->Player1->Team]->Settlements.size(); k++)
	{
		Settlement1 = Game1->Castes[Game1->Player1->Team]->Settlements[k];
		if (Settlement1.GetType() == SettlementTypes::Settlement || Settlement1.GetType() == SettlementTypes::Castle)
		if (Settlement1.X/32 == Game1->Player1->X/32 && Settlement1.Y/32 == Game1->Player1->Y/32)
		{
			//cout << ">>>> Size: " << Settlement1.GetItems().size() << ", Count: " << Count << endl;

			if (UI1->GetDrawUIBlocks()[i]->GetName() == "GameSettlementMarket")
			{
				if (Count+1 <= Settlement1.GetItemsMarket().size())
				{
					vector<Item*> ItemsBuffer = Game1->Castes[Game1->Player1->Team]->Settlements[k].GetItems();
					vector<Item*> ItemsBuffer2 = Game1->Castes[Game1->Player1->Team]->Settlements[k].GetItemsMarket();
					for (size_t p = 0; p < ItemsBuffer.size(); p++)
					{
						if (ItemsBuffer[p]->GetName() == ItemsBuffer2[Count]->GetName())
						if (ItemsBuffer[p]->GetSize() == ItemsBuffer2[Count]->GetSize())
						{
							Game1->Castes[Game1->Player1->Team]->Settlements[k].GetItems().erase(Game1->Castes[Game1->Player1->Team]->Settlements[k].GetItems().begin()+p);
							break;
						}
					}
					//Game1->Castes[Game1->Player1->Team]->Settlements[k].GetItems().erase(Game1->Castes[Game1->Player1->Team]->Settlements[k].GetItems().begin()+Count);
					UI_InventoryUpdate();
					break;
				}
			}
			else
			if (UI1->GetDrawUIBlocks()[i]->GetName() == "GameSettlementTavern")
			{
				if (Count+1 <= Settlement1.GetItemsTavern().size())
				{
					vector<Item*> ItemsBuffer = Game1->Castes[Game1->Player1->Team]->Settlements[k].GetItems();
					vector<Item*> ItemsBuffer2 = Game1->Castes[Game1->Player1->Team]->Settlements[k].GetItemsTavern();
					for (size_t p = 0; p < ItemsBuffer.size(); p++)
					{
						if (ItemsBuffer[p]->GetName() == ItemsBuffer2[Count]->GetName())
						if (ItemsBuffer[p]->GetSize() == ItemsBuffer2[Count]->GetSize())
						{
							Game1->Castes[Game1->Player1->Team]->Settlements[k].GetItems().erase(Game1->Castes[Game1->Player1->Team]->Settlements[k].GetItems().begin()+p);
							break;
						}
					}
					//Game1->Castes[Game1->Player1->Team]->Settlements[k].GetItems().erase(Game1->Castes[Game1->Player1->Team]->Settlements[k].GetItems().begin()+Count);
					UI_InventoryUpdate();
					break;
				}
			}
			break;
		}
	}
}