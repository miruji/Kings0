#include "../Window.h"

// Control: [Castes show / hide]
bool Window::Control_B()
{
	// ... 
	bool Result = true;

	if (Event.key.code == sf::Keyboard::B)
	{
		// ... 
		if (Game1->CastesDrawing == true)
		{
			// ... 
			Game1->CastesDrawing = false;

			// ... 
			UpdateLandMapSettlements(false);
		}
		else
		{
			// ... 
			Game1->CastesDrawing = true;

			// ... 
			UpdateLandMapSettlements(true);
		}
	}
	else
		Result = false;

	return Result;
}