#include "../Window.h"

// Control: [Roads show / hide]
bool Window::Control_R()
{
	//
	bool Result = true;

	if (Event.key.code == sf::Keyboard::R)
	{
		//
		if (RoadMap1->Drawing == true)
		{
			RoadMap1->Drawing = false;
		}
		else
		{
			RoadMap1->Drawing = true;
		}
	}
	else
		Result = false;

	return Result;
}