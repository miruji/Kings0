#include "../Window.h"

// Control: [MainMenu numbers] 
bool Window::Control_MainMenuNumbers()
{
	// ... 
	bool Result = false;

	// ... 
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
		if (UI1->GetDrawUIBlocks().size() > 1)
			return true;

		Result = true;
		cout << "MainMenu numbers" << endl;
		UI1->FocusedBlockName = 0;
		Control_NumbersEvents(Event.key.code);
	}
	else
		Result = false;

	return Result;
}