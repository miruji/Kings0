#include "../Window.h"

// Game: Get item status 
string Window::GetItemStatus(string Type, size_t i)
{
	string Result = "";
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
			Result = GetItemStatusResult(Settlement1, Type, Count, i);
			break;
		}
	}
	// Result 
	return Result;
}