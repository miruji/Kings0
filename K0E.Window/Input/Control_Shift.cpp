#include "../Window.h"

bool Window::Contol_Shift(bool Keyboard)
{
	bool Result = true;

	if (Event.key.code == sf::Keyboard::LShift || Event.key.code == sf::Keyboard::RShift || !Keyboard)
	{
		UIEvent('!', "ForestCut", false, 0, false);
	}
	else
		Result = false;

	return Result;
}