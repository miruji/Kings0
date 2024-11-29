#include "../Window.h"

bool Window::Contol_Zoom(char Type)
{
	bool Result = true;

	// + + +
	if (Event.key.code == sf::Keyboard::Add || Type == '+')
	{
		if (Camera1->AddZoom+1 <= 3)
		{
			Camera1->AddZoom++;
			Camera1->SetZoom(0.769);
		}
	}
	else
	// - - -
	if (Event.key.code == sf::Keyboard::Subtract || Type == '-')
	{
		if (Camera1->AddZoom-1 >= -2)
		{
			Camera1->AddZoom--;
			Camera1->SetZoom(1.3);
		}
	}
	else
		Result = false;

	return Result;
}