#include "NumToKeyCode.h"

// Num to key code 
sf::Keyboard::Key NumToKeyCode(size_t Num)
{
	// ... 
	if (Num == 0)
		return sf::Keyboard::Num0;
	else
	if (Num == 1)
		return sf::Keyboard::Num1;
	else
	if (Num == 2)
		return sf::Keyboard::Num2;
	else
	if (Num == 3)
		return sf::Keyboard::Num3;
	else
	if (Num == 4)
		return sf::Keyboard::Num4;
	else
	if (Num == 5)
		return sf::Keyboard::Num5;
	else
	if (Num == 6)
		return sf::Keyboard::Num6;
	else
	if (Num == 7)
		return sf::Keyboard::Num7;
	else
	if (Num == 8)
		return sf::Keyboard::Num8;
	else
	if (Num == 9)
		return sf::Keyboard::Num9;
}