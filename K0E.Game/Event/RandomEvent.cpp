#include "RandomEvent.h"

// To get random event 
bool K0E_Game_Api RandomEvent()
{
	// Koef 
	size_t Koef = 0;

	for (size_t i = 0; i < 50; i++)
	{
		// ... 
		if ( GetRandomNumber(0, 1) )
		{
			if ( GetRandomNumber(0, 1) )
				Koef = GetRandomNumber(75, 100);
			else
				Koef = GetRandomNumber(50, 100);
		}
		else
		{
			if ( GetRandomNumber(0, 1) )
			{
				Koef = GetRandomNumber(25, 100);
			}
			else
				Koef = GetRandomNumber(0, 100);
		}

		// New 
		if (Koef == 0)
			break;
	}

	// Result 
	if (Koef == 0)
		return 1;
	else
		return 0;
}