#include "../Window.h"

// UI: Update game basci flag 
void Window::UI_UpdateGameBasicFlag()
{
	//
	size_t FlagsSize = 0; // Max = 2 
	for (size_t i = 0; i < UI1->GetDrawUIBlocks().size(); i++)
	if (UI1->GetDrawUIBlocks()[i]->GetName() == "GameBasic")
	{
		UIImage* UIImage1;
		for (size_t j = 0; j < UI1->GetDrawUIBlocks()[i]->UI_Image.size(); j++)
		{
			UIImage1 = UI1->GetDrawUIBlocks()[i]->UI_Image[j];
			if (UIImage1->GetId() == "TeamUnit" || CutBackNum(UIImage1->GetId()) == "TeamFlag")
			{
				if (UIImage1->GetId() != "TeamFlag2")
				UIImage1->Color = StringToColor(NewGamePlayers[0].Color); // if 0 == player
				//cout << UIImage1->GetId() << endl;
				FlagsSize++;
				if (UIImage1->GetId() == "TeamUnit")
				{
					UIImage1->LoadTextureToSprite("Data\\Textures\\Game\\Bracket1.png", "32", "32");
				}
				else
				{
					UIImage1->SetNewRect( sf::IntRect(sf::Vector2i((SaveNewGameFlag+1)*36, SaveNewGameTeam*72), sf::Vector2i(36, 72)) );
				}
				//
			}

			if (FlagsSize == 3)
				break;
		}
		//
		if (FlagsSize == 3)
			break;
	}
}