#include "../Window.h"

// Control: [Enemy units show / hide]
bool Window::Control_O(bool Keyboard)
{
	// ... 
	bool Result = true;

	if (Event.key.code == sf::Keyboard::O || Keyboard == false)
	{
		// ... 
		if (Game1->UnitsDrawing == true)
		{
			// ... 
			Game1->UnitsDrawing = false;
		}
		else
		{
			// ... 
			Game1->UnitsDrawing = true;
		}
	}
	else
		Result = false;

	return Result;
}