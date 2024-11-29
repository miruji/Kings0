#include "../Window.h"

// Control: [Player show / hide]
bool Window::Control_P()
{
	// ... 
	bool Result = true;

	if (Event.key.code == sf::Keyboard::P)
	{
		// ... 
		if (Game1->Player1->Drawing == false)
		{
			Game1->Player1->Drawing = true;
		}
		else
		{
			Game1->Player1->Drawing = false;
		}
	}
	else
		Result = false;

	return Result;
}