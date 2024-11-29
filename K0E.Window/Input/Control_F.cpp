#include "../Window.h"

// Control: [War fog show / hide]
bool Window::Control_F()
{
	// ... 
	bool Result = true;

	if (Event.key.code == sf::Keyboard::F)
	{
		// ... 
		if (WarFog1->Drawing == false)
		{
			WarFog1->Drawing = true;
		}
		else
		{
			WarFog1->Drawing = false;
		}
	}
	else
		Result = false;

	return Result;
}