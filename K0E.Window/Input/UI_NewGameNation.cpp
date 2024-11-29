#include "../Window.h"

// UI: New game nation 
void Window::UI_NewGameNation(char Type)
{
	// ... 
	if (Type == '+')
	{
		if (NewGameNation+1 <= 3)
			NewGameNation++;
	}
	else
	if (Type == '-')
	{
		if (NewGameNation-1 >= 0 && NewGameNation-1 <= 3)
			NewGameNation--;
	}
}