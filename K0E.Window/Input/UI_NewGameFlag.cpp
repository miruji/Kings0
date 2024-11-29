#include "../Window.h"

// UI: New game flag 
void Window::UI_NewGameFlag(char Type)
{
	//
	if (Type == '+')
	{
		if (NewGameFlag+1 <= 23)
			NewGameFlag++;
	}
	else
	if (Type == '-')
	{
		if (NewGameFlag-1 >= 0 && NewGameFlag-1 <= 23)
			NewGameFlag--;
	}

	//
	size_t FlagsSize = 0; // Max = 3 
	for (size_t i = 0; i < UI1->GetDrawUIBlocks().size(); i++)
	if (UI1->GetDrawUIBlocks()[i]->GetName() == "MainMenuNewGame1")
	{
		UIImage* UIImage1;
		for (size_t j = 0; j < UI1->GetDrawUIBlocks()[i]->UI_Image.size(); j++)
		{
			UIImage1 = UI1->GetDrawUIBlocks()[i]->UI_Image[j];
			if (UIImage1->GetId() == "NewGameFlag1" || UIImage1->GetId() == "NewGameFlag1_2" || 
				UIImage1->GetId() == "NewGameFlag2" || UIImage1->GetId() == "NewGameFlag2_2" ||
				UIImage1->GetId() == "NewGameFlag3" || UIImage1->GetId() == "NewGameFlag3_2")
			{
				if (UIImage1->GetId() == "NewGameFlag1" || UIImage1->GetId() == "NewGameFlag2" || UIImage1->GetId() == "NewGameFlag3")
					UIImage1->Color = StringToColor(NewGamePlayers[0].Color); // if 0 == player
				//cout << UIImage1->GetId() << endl;
				FlagsSize++;

				if ( ((UIImage1->GetId() == "NewGameFlag3" || UIImage1->GetId() == "NewGameFlag3_2") && NewGameFlag == 23) ||
					 ((UIImage1->GetId() == "NewGameFlag1" || UIImage1->GetId() == "NewGameFlag1_2") && NewGameFlag == 0) )
					UIImage1->SetNewRect( sf::IntRect(sf::Vector2i(0, NewGameTeam*72), sf::Vector2i(36, 72)) );
				else
				{
					if (UIImage1->GetId() == "NewGameFlag1" || UIImage1->GetId() == "NewGameFlag1_2")
						UIImage1->SetNewRect( sf::IntRect(sf::Vector2i((NewGameFlag)*36, NewGameTeam*72), sf::Vector2i(36, 72)) );
					else
					if (UIImage1->GetId() == "NewGameFlag3" || UIImage1->GetId() == "NewGameFlag3_2")
						UIImage1->SetNewRect( sf::IntRect(sf::Vector2i((NewGameFlag+2)*36, NewGameTeam*72), sf::Vector2i(36, 72)) );
					else
						UIImage1->SetNewRect( sf::IntRect(sf::Vector2i((NewGameFlag+1)*36, NewGameTeam*72), sf::Vector2i(36, 72)) );
				}
			}

			if (FlagsSize == 6)
				break;
		}

		if (FlagsSize == 6)
			break;
	}
}