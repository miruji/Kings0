#include "../Window.h"

// Control: [Names show / hide] 
bool Window::Control_N()
{
	//
	bool Result = true;

	if (Event.key.code == sf::Keyboard::N)
	{
		//
		if (Game1->NamesDrawing == false)
		{
			Game1->NamesDrawing = true;
		}
		else
		{
			Game1->NamesDrawing = false;
		}
	}
	else
		Result = false;

	return Result;
}