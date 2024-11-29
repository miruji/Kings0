#include "ColorGenerate.h"

vector<size_t> ColorGenerate()
{
	vector<size_t> Color;
	//
	if (true)
	{
		size_t r1, c1, c2, c3;
		while (true)
		{
			r1 = GetRandomNumber(0, 4);

			if (r1 == 0)
			{
				srand(GetRandomNumber(0, 8));
				c1 = round(float(rand())/100.0f*7); c1 = 15*GetRandomNumber(c1+3, 17);
			}
			else
				c1 = 15*GetRandomNumber(3, 17);
			//
			if (r1 == 1)
			{
				srand(GetRandomNumber(0, 8));
				c2 = round(float(rand())/100.0f*7); c2 = 15*GetRandomNumber(c2+3, 17);
			}
			else
				c2 = 15*GetRandomNumber(3, 17);
			//
			if (r1 == 2)
			{
				srand(GetRandomNumber(0, 8));
				c3 = round(float(rand())/100.0f*7); c3 = 15*GetRandomNumber(c3+3, 17);
			}
			else
				c3 = 15*GetRandomNumber(3, 17);
			//
			if (
				(
				(c1 <= 255 && c2 <= 210 && c3 <= 210) ||
				(c1 <= 210 && c2 <= 255 && c3 <= 210) ||
				(c1 <= 210 && c2 <= 210 && c3 <= 255)
				) ||
				(
				(c1 <= 255 && (c2 <= 180 || c3 <= 180)) ||
				(c2 <= 255 && (c1 <= 180 || c3 <= 180)) ||
				(c3 <= 255 && (c1 <= 180 || c2 <= 180))
				)
			   )
			if ((c1 >= 45 && (c2 >= 210 || c3 >= 210)) ||
				(c2 >= 45 && (c1 >= 210 || c3 >= 210)) ||
				(c3 >= 45 && (c1 >= 210 || c2 >= 210)) ||
				c1 >= 210 || c2 >= 210 || c3 >= 210)
			if (((c1+15 < c2 && c1+15 < c3) || (c1-15 > c2 && c1-15 > c3)) ||
				((c2+15 < c1 && c2+15 < c3) || (c2-15 > c1 && c2-15 > c3)) ||
				((c3+15 < c1 && c3+15 < c2) || (c3-15 > c1 && c3-15 > c2)))
			{
				Color.push_back(c1);
				Color.push_back(c2);
				Color.push_back(c3);
				break;
			}
		}
		//
	}

	return Color;
}