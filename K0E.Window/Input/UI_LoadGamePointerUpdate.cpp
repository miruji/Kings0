#include "../Window.h"

void Window::UI_LoadGamePointerUpdate(size_t UnitCount)
{
	string NewX, NewY;
	string BlockName = UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->GetName();
	if (BlockName == "MainMenuLoadGame0" ||
		BlockName == "MainMenuSaveGame0")
	{
		//
		NewX = to_string(12*UI1->ResizeWidth);
		if (UnitCount == 1)
			NewY = to_string(105*UI1->ResizeHeight);
		else
		if (UnitCount == 2)
			NewY = to_string(174*UI1->ResizeHeight);
		else
		if (UnitCount == 3)
			NewY = to_string(243*UI1->ResizeHeight);
		else
		if (UnitCount == 4)
			NewY = to_string(312*UI1->ResizeHeight);
		else // to 0
			NewY = to_string(36*UI1->ResizeHeight);
		//
		if (BlockName == "MainMenuLoadGame0")
			LoadGameUnit = UnitCount;
		else
		if (BlockName == "MainMenuSaveGame0")
			SaveGameUnit = UnitCount;
	}
	else
	if (BlockName == "MainMenuNewGame1")
	{
		NewX = to_string(200*UI1->ResizeWidth);
		if (UnitCount == 1)
			NewY = to_string(95*UI1->ResizeHeight);
		else
		if (UnitCount == 2)
			NewY = to_string(134*UI1->ResizeHeight);
		else
		if (UnitCount == 3)
			NewY = to_string(173*UI1->ResizeHeight);
		else
		if (UnitCount == 4)
			NewY = to_string(212*UI1->ResizeHeight);
		else
		if (UnitCount == 5)
			NewY = to_string(251*UI1->ResizeHeight);
		else
		if (UnitCount == 6)
			NewY = to_string(290*UI1->ResizeHeight);
		else
		if (UnitCount == 7)
			NewY = to_string(329*UI1->ResizeHeight);
		else
		if (UnitCount == 8)
			NewY = to_string(368*UI1->ResizeHeight);
		else
		if (UnitCount == 9)
			NewY = to_string(407*UI1->ResizeHeight);
		else // to 0
			NewY = to_string(56*UI1->ResizeHeight);
		NewGameUnit = UnitCount;
	}
	/*
	else
	if (BlockName == "MainMenuMultiplayer1")
	{
		NewX = to_string(257*UI1->ResizeWidth);
		if (UnitCount == 1)
			NewY = to_string(137*UI1->ResizeHeight);
		else
		if (UnitCount == 2)
			NewY = to_string(193*UI1->ResizeHeight);
		else
		if (UnitCount == 3)
			NewY = to_string(249*UI1->ResizeHeight);
		else
		if (UnitCount == 4)
			NewY = to_string(305*UI1->ResizeHeight);
		else
		if (UnitCount == 5)
			NewY = to_string(361*UI1->ResizeHeight);
		else
		if (UnitCount == 6)
			NewY = to_string(417*UI1->ResizeHeight);
		else // to 0
			NewY = to_string(81*UI1->ResizeHeight);
		NewGameUnit = UnitCount;
	}
	*/

	UIGif* UIGif1;
	for (size_t i = 0; i < UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->UI_Gif.size(); i++)
	{
		UIGif1 = UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->UI_Gif[i];
		if (UIGif1->GetId() == "Pointer")
		{
			UIGif1->SetXY(NewX, NewY);
			break;
		}
	}
	//cout << "|LoadGameUnit " << LoadGameUnit << "|SaveGameUnit " << SaveGameUnit << "|NewGameUnit " << NewGameUnit << endl;
}