#include "../Window.h"

void Window::UI_UpdateNewGamePlayerIcon()
{
	size_t CurrentWindow = UI1->FocusedBlockName;

	UIImage* UIImage1;
	for (size_t i = 0; i < UI1->GetDrawUIBlocks()[CurrentWindow]->UI_Image.size(); i++)
	{
		UIImage1 = UI1->GetDrawUIBlocks()[CurrentWindow]->UI_Image[i];
		string Buffer2 = UIImage1->GetId();
		size_t Team = CharToInt(Buffer2[Buffer2.length()-1]);
		Buffer2.erase(Buffer2.end()-1);
		if (Buffer2 == "DiplomacyTeam")
		{
			if (Team <= CurrentMapTeams && Team != 0)
				UI1->GetDrawUIBlocks()[CurrentWindow]->UI_Image[i]->Show = true;
			else
				UI1->GetDrawUIBlocks()[CurrentWindow]->UI_Image[i]->Show = false;
			//cout << "Team: " << Team << ", Id: " << Buffer2 << ", Limit: " << CurrentMapTeams << endl;
		}
	}

	UIButton* UIButton1;
	for (size_t i = 0; i < UI1->GetDrawUIBlocks()[CurrentWindow]->UI_Button.size(); i++)
	{
		UIButton1 = UI1->GetDrawUIBlocks()[CurrentWindow]->UI_Button[i];
		string Buffer2 = UIButton1->GetId();
		size_t Team = CharToInt(Buffer2[Buffer2.length()-1]);
		Buffer2.erase(Buffer2.end()-1);
		if (Buffer2 == "DiplomacyTeam")
		{
			if (Team <= CurrentMapTeams && Team != 0)
				UI1->GetDrawUIBlocks()[CurrentWindow]->UI_Button[i]->Show = true;
			else
				UI1->GetDrawUIBlocks()[CurrentWindow]->UI_Button[i]->Show = false;
			//cout << "Team: " << Team << ", Id: " << Buffer2 << ", Limit: " << CurrentMapTeams << endl;
		}
	}
}