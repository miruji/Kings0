#include "../Window.h"

// Control: [Grid show / hide]
bool Window::Control_H()
{
	// ... 
	bool Result = true;

	if (Event.key.code == sf::Keyboard::H)
	{
		// ... 
		if (UI1->Drawing == true)
		{
			UI1->Drawing = false;
		}
		else
		{
			UI1->Drawing = true;
		}
	}
	else
		Result = false;

	return Result;
}