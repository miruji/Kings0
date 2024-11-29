#include "../Window.h"

void Window::UpdateNewGamePlayer()
{
	// UI_Image
	UIImage* UIImage1;
	size_t Num;
	for (size_t i = 0; i < UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->UI_Image.size(); i++)
	{
		UIImage1 = UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->UI_Image[i];
		if (CutBackNum(UIImage1->GetId()) == "PlayerList" || CutBackNum(UIImage1->GetId()) == "Item")
		{
			//
			Num = GetBackEventNumber(UIImage1->GetId());
			if ((Num < NewGamePlayers.size() || Num == 0) && NewGamePlayers[Num].Num != -1)
			{
				if (CutBackNum(UIImage1->GetId()) == "PlayerList")
				{
					UIImage1->LoadTextureToSprite("Data\\Textures\\Game\\Bracket1.png", "32", "32");
					//UIImage1->GetSprite().setColor(StringToColor(NewGamePlayers[Num].Color));
					UIImage1->Color = StringToColor(NewGamePlayers[Num].Color);
				}
				else
					UIImage1->LoadTextureToSprite("Data\\Textures\\UI\\NewGameItem1.png", "393", "38");
			}
			else
			{
				if (CutBackNum(UIImage1->GetId()) == "PlayerList")
					UIImage1->LoadTextureToSprite("Data\\Textures\\Game\\Bracket0.png", "32", "32");
				else
					UIImage1->LoadTextureToSprite("Data\\Textures\\UI\\NewGameItem0.png", "393", "38");
			}
		}
		//
	}

	// UI_Text
	UIText* UIText1;
	for (size_t i = 0; i < UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->UI_Text.size(); i++)
	{
		UIText1 = UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->UI_Text[i];
		if (CutBackNum(UIText1->GetId()) == "PlayerName" || CutBackNum(UIText1->GetId()) == "PlayerEmpty")
		{
			Num = GetBackEventNumber(UIText1->GetId());

			if (Num < NewGamePlayers.size() || Num == 0)
			{
				if (NewGamePlayers[Num].Num != -1)
				{
					if (CutBackNum(UIText1->GetId()) == "PlayerName")
						UIText1->Show = true;
					else
						UIText1->Show = false;
				}
				else
				{
					if (CutBackNum(UIText1->GetId()) == "PlayerName")
						UIText1->Show = false;
					else
						UIText1->Show = true;
				}
			}
			//
		}
		else
		if (CutBackNum(UIText1->GetSpec()) == "Color")
		{
			Num = GetBackEventNumber(UIText1->GetImageId());

			if (NewGamePlayers[Num].Num == -1 || Num >= NewGamePlayers.size())
			{
				UIText1->Show = false;
			}
			else
				UIText1->Show = true;
		}
		//
	}

	// UI_Button
	UIButton* UIButton1;
	for (size_t i = 0; i < UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->UI_Button.size(); i++)
	{
		UIButton1 = UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->UI_Button[i];
		Num = GetBackEventNumber(UIButton1->GetImageId());

		if (CutBackNum(UIButton1->GetEvent()) == "!LoadGamePointerUpdate")
		{
			if (Num < NewGamePlayers.size() || Num == 0)
			{
				if (NewGamePlayers[Num].Num != -1)
					UIButton1->SetWH("311", "34");
				else
					UIButton1->SetWH("389", "34");
			}
		}
		else
		if (CutBackNum(UIButton1->GetImageId()) == "Item")
		{
			if (NewGamePlayers[Num].Num == -1 || Num >= NewGamePlayers.size())
			{
				UIButton1->Show = false;
			}
			else
				UIButton1->Show = true;
		}
	}

	// UI_ComboBox
	UIComboBox* UIComboBox1;
	for (size_t i = 0; i < UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->UI_ComboBox.size(); i++)
	{
		UIComboBox1 = UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->UI_ComboBox[i];
		Num = GetBackEventNumber(UIComboBox1->GetImageId());

		if (NewGamePlayers[Num].Num == -1 || Num >= NewGamePlayers.size())
		{
			UIComboBox1->Show = false;
		}
		else
			UIComboBox1->Show = true;
	}
}