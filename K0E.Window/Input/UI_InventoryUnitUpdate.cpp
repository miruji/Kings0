#include "../Window.h"

// Set unit pointer position
void Window::UI_InventoryUnitUpdate(size_t UnitCount, size_t Num)
{
	//
	size_t PositionCount = 0;
	size_t TradePointer1X = 0;
	size_t TradePointer1Y = 0;

	size_t BuyCout = 0;

	for (size_t i = 0; i < UI1->GetDrawUIBlocks().size(); i++)
	{
		//
		if (i == Num)
		{
		vector< UIImage* > UIImages = UI1->GetDrawUIBlocks()[i]->UI_Image;
		for (size_t j = 0; j < UIImages.size(); j++)
		{
			// TradeUnit1
			if (UIImages[j]->GetId() == "TradeUnit1")
			{
				// Search first items basic X & Y 
				TradePointer1X = UIImages[j]->GetXY().x/UI1->ResizeWidth;
				TradePointer1Y = UIImages[j]->GetXY().y/UI1->ResizeHeight;
				//std::cout << "X: " << TradePointer1X << ", Y: " << TradePointer1Y << std::endl;
			}
			// Trade pointer 
			else 
			{
			vector< UIGif* > UIGifs = UI1->GetDrawUIBlocks()[i]->UI_Gif;
			for (size_t q = 0; q < UIGifs.size(); q++)
			if (UIGifs[q]->GetId() == "TradePointer")
			{
				//
				PositionCount = UnitCount * 64;
				//cout << PositionCount << endl;
				if (PositionCount >= 768)
				{
					//std::cout << "Fourth ->> X:" << PositionCount-768 << ", Y: 192" << std::endl;
					UIGifs[q]->SetXY( to_string((TradePointer1X+(PositionCount-768)-64 -(PositionCount-768)/64)*UI1->ResizeWidth), to_string((TradePointer1Y+192)*UI1->ResizeHeight) );
				}
				else
				if (PositionCount >= 512)
				{
					//std::cout << "Third ->> X:" << PositionCount-512 << ", Y: 128" << std::endl;
					UIGifs[q]->SetXY( to_string((TradePointer1X+(PositionCount-512)-64 -(PositionCount-512)/64)*UI1->ResizeWidth), to_string((TradePointer1Y+128)*UI1->ResizeHeight) );
				}
				else
				if (PositionCount >= 256)
				{
					//std::cout << "Second ->> X:" << PositionCount-256 << ", Y: 64" << std::endl;
					UIGifs[q]->SetXY( to_string((TradePointer1X+(PositionCount-256)-64 -(PositionCount-256)/64)*UI1->ResizeWidth), to_string((TradePointer1Y+64)*UI1->ResizeHeight) );
				}
				else
				{
					//std::cout << "First ->> X:" << PositionCount << ", Y: 0" << std::endl;
					UIGifs[q]->SetXY( to_string((TradePointer1X+PositionCount-64 -(PositionCount)/64)*UI1->ResizeWidth), to_string(TradePointer1Y*UI1->ResizeHeight) );
				}

				// Set buy cout 
				BuyCout = (PositionCount)/64;
				//cout << BuyCout << endl;

				//std::cout << "Item count ->> " << PositionCount / 64 << std::endl;
				//std::cout << "- - - - - - - " << std::endl;
			} }
		} }
		//
	}
}