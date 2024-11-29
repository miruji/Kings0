#include "../Window.h"

// Clear unit pointer position 
void Window::UI_InventoryUnitClearUpdate()
{
	//
	size_t PositionCount = 0;
	size_t TradePointer1X = 0;
	size_t TradePointer1Y = 0;

	size_t BuyCout = 0;

	for (size_t i = 0; i < UI1->GetUIBlocks().size(); i++)
	{
		//
		vector< UIImage* > UIImages = UI1->GetUIBlocks()[i]->UI_Image;
		for (size_t j = 0; j < UIImages.size(); j++)
		{
			// TradeUnit1
			if (UIImages[j]->GetId() == "TradeUnit1")
			{
				// Search first items basic X & Y 
				TradePointer1X = UIImages[j]->GetXY().x/UI1->ResizeWidth;
				TradePointer1Y = UIImages[j]->GetXY().y/UI1->ResizeHeight;
			}
			// Trade pointer 
			else 
			{
			vector< UIGif* > UIGifs = UI1->GetUIBlocks()[i]->UI_Gif;
			for (size_t q = 0; q < UIGifs.size(); q++)
			if (UIGifs[q]->GetId() == "TradePointer")
			{
				//
				PositionCount = 0;

				UIGifs[q]->SetXY( to_string((TradePointer1X+PositionCount-64 -(PositionCount)/64)*UI1->ResizeWidth), to_string(TradePointer1Y*UI1->ResizeHeight) );

				// Set buy cout 
				BuyCout = (PositionCount)/64;
			} }
		}
		//
	}
}