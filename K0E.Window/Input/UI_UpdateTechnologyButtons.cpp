#include "../Window.h"

void Window::UI_UpdateTechnologyButtons()
{
	if (true)
	{
	string Buffer = "";
	for (size_t i = 0; i < UI1->GetDrawUIBlocks().size(); i++)
	{
		Buffer = UI1->GetDrawUIBlocks()[i]->GetName();
		Buffer.erase(Buffer.end()-1);
		if (Buffer == "GameLogTechnology")
		{
			UI1->FocusedBlockName = i;
			break;
		}
	}
	}

	//
	vector<size_t> Technologys;
	for (size_t i = 0; i < Game1->Castes[Game1->Player1->Team]->Technologys.size(); i++)
	{
		if (Game1->Castes[Game1->Player1->Team]->Technologys[i].Opened || 
			(!Game1->Castes[Game1->Player1->Team]->Technologys[i].Opened && Game1->Castes[Game1->Player1->Team]->Technologys[i].Locked(Game1->Castes[Game1->Player1->Team]->Technologys)))
			Technologys.push_back(i);
	}

	UIButton* UIButton1;
	for (size_t i = 0; i < UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->UI_Button.size(); i++)
	{
		UIButton1 = UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->UI_Button[i];
		string Buffer2 = UIButton1->GetId();

		//cout << "B2: " << Buffer2 << endl;
		for (size_t j = 0; j < Technologys.size(); j++)
			if (Buffer2 == "TechnologyLearn_"+to_string(Technologys[j]))
			{
				UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->UI_Button[i]->Show = false;
				break;
			}
			else
				UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->UI_Button[i]->Show = true;
	}
}