#include "../Window.h"

void Window::UI_UpdateTechnologyBack()
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
	UIImage* UIImage1;
	for (size_t i = 0; i < UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->UI_Image.size(); i++)
	{
		UIImage1 = UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->UI_Image[i];
		string Buffer2 = UIImage1->GetId();

		for (size_t j = 0; j < Game1->Castes[Game1->Player1->Team]->Technologys.size(); j++)
		if (Buffer2 == "TechnologyLearn_"+to_string(j))
		{
			//
			if (!Game1->Castes[Game1->Player1->Team]->Technologys[j].Locked(Game1->Castes[Game1->Player1->Team]->Technologys))
			{
				if (Game1->Castes[Game1->Player1->Team]->Technologys[j].Opened)
					UIImage1->LoadTextureToSprite("Data\\Textures\\UI\\LearnedButton0.png", "32", "32");
				else
					UIImage1->LoadTextureToSprite("Data\\Textures\\UI\\LearnedButton1.png", "32", "32");
			}
			else
				UIImage1->LoadTextureToSprite("Data\\Textures\\UI\\LearnedButton2.png", "32", "32");
			break;
		}
		//
	}
	UI_UpdateTechnologyButtons();
}