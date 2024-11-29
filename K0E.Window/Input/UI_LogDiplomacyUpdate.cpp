#include "../Window.h"

// UI: Log diplomacy update 
void Window::UI_LogDiplomacyUpdate()
{
	// Castes list 
	vector<Caste*> CastesBuffer;
	for (size_t i = 0; i < Game1->Castes.size(); i++)
	if (Game1->Castes[i]->Team != Game1->Player1->Team)
		CastesBuffer.push_back(Game1->Castes[i]);
	// Search elements 
	UIBlock* UIBlock1 = UI1->GetDrawUIBlocks()[UI1->FocusedBlockName];
	//size_t Limit = 0;
		// Image 
		UIImage* UIImage1;
		for (size_t i = 0; i < UIBlock1->UI_Image.size(); i++)
		{
			//if (Limit == CastesBuffer.size())
			//	break;

			UIImage1 = UIBlock1->UI_Image[i];
			if (CutBackNum(UIImage1->GetId()) == "TeamBracket")
			{
				size_t TeamBuffer = GetBackEventNumber(UIImage1->GetId());
				if (TeamBuffer >= CastesBuffer.size()+1)
				{
					UIBlock1->UI_Image[i]->Show = false;
				}
				else
					UIImage1->Color = StringToColor(Game1->Castes[TeamBuffer]->Color);
				
				//Limit++;
			}
			else
			if (CutBackNum(UIImage1->GetId()) == "BlockTeamItem")
			{
				size_t TeamBuffer = GetBackEventNumber(UIImage1->GetId());
				if (TeamBuffer >= CastesBuffer.size()+1)
				{
					UIBlock1->UI_Image[i]->Show = false;
				}
			}
			else
			if (CutBackNum(UIImage1->GetImageId()) == "BlockTeamItem")
			{
				size_t TeamBuffer = GetBackEventNumber(UIImage1->GetImageId());
				if (TeamBuffer >= CastesBuffer.size()+1)
				{
					UIBlock1->UI_Image[i]->Show = false;
				}
			}
			//
		}
		// Texts 
		UIText* UIText1;
		for (size_t i = 0; i < UIBlock1->UI_Text.size(); i++)
		{
			UIText1 = UIBlock1->UI_Text[i];
			if (CutBackNum(UIText1->GetId()) == "TeamName" ||
				CutBackNum(UIText1->GetId()) == "TeamAttitude" ||
				CutBackNum(UIText1->GetId()) == "TeamStatus")
			{
				size_t TeamBuffer = GetBackEventNumber(UIText1->GetId());
				if (TeamBuffer >= CastesBuffer.size()+1)
				{
					UIBlock1->UI_Text[i]->Show = false;
				}
				else
					UIBlock1->UI_Text[i]->SetSpec( DevideOutCharacter(UIText1->GetId())+to_string(TeamBuffer) );
			}
			else
			if (CutBackNum(UIText1->GetImageId()) == "BlockTeamItem")
			{
				size_t TeamBuffer = GetBackEventNumber(UIText1->GetImageId());
				if (TeamBuffer >= CastesBuffer.size()+1)
					UIBlock1->UI_Text[i]->Show = false;
			}
			//
		}
		// Buttons  
		UIButton* UIButton1;
		for (size_t i = 0; i < UIBlock1->UI_Button.size(); i++)
		{
			UIButton1 = UIBlock1->UI_Button[i];
			if (UIButton1->GetId() != "" && UIButton1->GetId()[0] == 'T')
			{
				size_t TeamBuffer = GetBackEventNumber(UIButton1->GetId());
				if (TeamBuffer >= CastesBuffer.size()+1)
				{
					UIBlock1->UI_Button[i]->Show = false;
				}
				else
					UIBlock1->UI_Button[i]->SetEvent( "!"+DevideOutCharacter(UIButton1->GetId())+to_string(TeamBuffer) );
			}
			//
		}
}