#include "../Window.h"

// Control: [Settlement numbers]
bool Window::Control_SettlementNumbers()
{
	//
	bool Result = false;

	//
	if (  (LandMap1->BlocksVector[Game1->Player1->Y/32][Game1->Player1->X/32].Settlement || (Event.key.code == sf::Keyboard::Num0 || Event.key.code == sf::Keyboard::Numpad0))
		 && !Game1->Player1->Die )
	if ( (Event.key.code == sf::Keyboard::Num0 || Event.key.code == sf::Keyboard::Numpad0) || 
		 (Event.key.code == sf::Keyboard::Num1 || Event.key.code == sf::Keyboard::Numpad1) || 
		 (Event.key.code == sf::Keyboard::Num2 || Event.key.code == sf::Keyboard::Numpad2) || 
		 (Event.key.code == sf::Keyboard::Num3 || Event.key.code == sf::Keyboard::Numpad3) || 
		 (Event.key.code == sf::Keyboard::Num4 || Event.key.code == sf::Keyboard::Numpad4) || 
		 (Event.key.code == sf::Keyboard::Num5 || Event.key.code == sf::Keyboard::Numpad5) || 
		 (Event.key.code == sf::Keyboard::Num6 || Event.key.code == sf::Keyboard::Numpad6) || 
		 (Event.key.code == sf::Keyboard::Num7 || Event.key.code == sf::Keyboard::Numpad7) || 
		 (Event.key.code == sf::Keyboard::Num8 || Event.key.code == sf::Keyboard::Numpad8) || 
		 (Event.key.code == sf::Keyboard::Num9 || Event.key.code == sf::Keyboard::Numpad9) )
	{
		Result = true;
		cout << "Settlement number pressed!" << endl;
			
		UI1->FocusedBlockName = UI_GetLeftBlockName();
		Control_NumbersEvents(Event.key.code);
	}
	else
		Result = false;

	return Result;
}