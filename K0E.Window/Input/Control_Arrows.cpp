#include "../Window.h"

// Control: [Arrows] 
bool Window::Control_Arrows()
{
	// ... 
	bool Result = true;

	if (Event.key.code == sf::Keyboard::Up   || Event.key.code == sf::Keyboard::Left ||
		Event.key.code == sf::Keyboard::Down || Event.key.code == sf::Keyboard::Right)
	{
		// Arrow keys repeat 
		Render.setKeyRepeatEnabled(true);

		// Arrow Camera mode 
		if (Camera1->AddXY == false)
			Camera1->AddXY = true;

		// Control 
			// Up
			if (Event.key.code == sf::Keyboard::Up)
			{
				Camera1->Move(0, -Camera1->Speed);
				if (Camera1->AddXY)
					Camera1->AddY -= Camera1->Speed;
			}
			else
			// Left
			if (Event.key.code == sf::Keyboard::Left)
			{
				Camera1->Move(-Camera1->Speed, 0);
				if (Camera1->AddXY)
					Camera1->AddX -= Camera1->Speed;
			}
			else
			// Down
			if (Event.key.code == sf::Keyboard::Down)
			{
				Camera1->Move(0, Camera1->Speed);
				if (Camera1->AddXY)
					Camera1->AddY += Camera1->Speed;
			}
			else
			// Right
			if (Event.key.code == sf::Keyboard::Right)
			{
				Camera1->Move(Camera1->Speed, 0);
				if (Camera1->AddXY)
					Camera1->AddX += Camera1->Speed;
			}
		// ...
	}
	else
	{
		// Disable arrow keys repat 
		Render.setKeyRepeatEnabled(false);
		Result = false;
	}
	
	return Result;
}