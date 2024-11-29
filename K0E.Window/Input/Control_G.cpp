#include "../Window.h"

// Control: [Grid show / hide]
bool Window::Control_G()
{
	// ... 
	bool Result = true;

	if (Event.key.code == sf::Keyboard::G)
	{
		// ... 
		if (GridMap1->Drawing == true)
		{
			GridMap1->Drawing = false;
		}
		else
		{
			GridMap1->Drawing = true;
		}
	}
	else
		Result = false;

	return Result;
}