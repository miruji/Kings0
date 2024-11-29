#include "../Window.h"

// Control: [Main menu] 
bool Window::Control_Esc()
{
	// ... 
	bool Result = true;

	if (Event.key.code == sf::Keyboard::Escape)
	{
		// ... 
		if (NewGame == true)
		{
			if (UI1->MainMenu == false)
			{
				UIEvent('!', "MainMenuBack", false, 0, false);
				if (UI1->Drawing == false)
				{
					UIDrawingSave = false;
					UI1->Drawing = true;
				}
			}
			else
			{
				UIEvent('!', "MainMenuBack2", false, 1, false);
				if (UIDrawingSave == false)
				{
					UI1->Drawing = false;
					UIDrawingSave = true;
				}
			}
		}
	}
	else
		Result = false;

	return Result;
}