#include "../Window.h"

// UI: Log diplomacy big update 
void Window::UI_LogDiplomacyBigUpdate(size_t CasteNum)
{
	CasteNum++;
	Caste* Caste1 = Game1->Castes[CasteNum];

	UIBlock* UIBlock1 = UI1->GetDrawUIBlocks()[UI1->FocusedBlockName];
	
		// Image 
		UIImage* UIImage1;
		for (size_t i = 0; i < UIBlock1->UI_Image.size(); i++)
		{
			UIImage1 = UIBlock1->UI_Image[i];
			if (CutBackNum(UIImage1->GetId()) == "TeamBracket")
			{
				UIImage1->Color = StringToColor(Game1->Castes[CasteNum-1]->Color);
			}
			else
			if (CutBackNum(UIImage1->GetId()) == "TeamFlag")
			{
				if (UIImage1->GetId() == "TeamFlag1")
					UIImage1->Color = StringToColor(Game1->Castes[CasteNum-1]->Color);

				UIImage1->SetNewRect( sf::IntRect(36*Game1->Castes[CasteNum-1]->Rune, 0, 36, 72) );
			}
		}

		// Texts 
		UIText* UIText1;
		for (size_t i = 0; i < UIBlock1->UI_Text.size(); i++)
		{
			UIText1 = UIBlock1->UI_Text[i];
			if (UIText1->GetId() != "" && UIText1->GetId()[0] == 'T')
			{
				UIBlock1->UI_Text[i]->SetSpec(DevideOutCharacter(UIText1->GetId())+to_string(CasteNum-1) );
			}
		}

		// Buttons  
		UIButton* UIButton1;
		for (size_t i = 0; i < UIBlock1->UI_Button.size(); i++)
		{
			UIButton1 = UIBlock1->UI_Button[i];
			if (UIButton1->GetId() != "" && UIButton1->GetId()[0] == 'T')
			{
				char TeamBuffer = UIButton1->GetId()[UIButton1->GetId().length()-1];
				UIBlock1->UI_Button[i]->SetEvent( "!"+ DevideOutCharacter(UIButton1->GetId())+to_string(CasteNum-1) );
			}
		}

	//
	if (CasteNum-1 == Game1->Player1->Team)
	{
		UI_HideImageButton(UIBlock1->GetName(), "PlusButton");
		UI_HideImageButton(UIBlock1->GetName(), "MinusButton");
	}
}