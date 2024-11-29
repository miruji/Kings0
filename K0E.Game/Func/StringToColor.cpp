#include "StringToColor.h"

sf::Color StringToColor(string Color)
{
	vector<size_t> ColorBuffer;
	string Buffer = "";
	for (size_t i = 0; i < Color.size(); i++)
	{
		if (Color[i] == ';' || i+1 == Color.size())
		{
			if (i+1 == Color.size())
				Buffer += Color[i];

			ColorBuffer.push_back(atoi(Buffer.c_str()));
			Buffer = "";
		}
		else
			Buffer += Color[i];
	}
	//
	if (ColorBuffer.size() == 4)
		return sf::Color(ColorBuffer[0], ColorBuffer[1], ColorBuffer[2], ColorBuffer[3]);
	else
	if (ColorBuffer.size() == 3)
		return sf::Color(ColorBuffer[0], ColorBuffer[1], ColorBuffer[2]);
	else
		sf::Color(255, 255, 255, 255);
}