#include "NewGameCaste.h"
#include "../Func/ColorGenerate.h"

NewGameCaste::NewGameCaste(int Num)
{
	this->Num = Num;
}

void NewGameCaste::NewColor(size_t num, char type)
{
	//
	vector<string> Colors;
	string buffer = "";
	for (size_t i = 0; i < Color.length(); i++)
	{
		if (Color[i] == ';' || i+1 == Color.length())
		{
			if (i+1 == Color.length())
				buffer += Color[i];

			Colors.push_back(buffer);
			buffer = "";
		}
		else
			buffer += Color[i];
	}
	//
	int buffer2 = atoi(Colors[num].c_str());
	if (type == '+')
	{
		if (buffer2+15 <= 255)
		Colors[num] = to_string(buffer2+15);
	}
	else
	if (type == '-')
	{
		if (buffer2-15 >= 45)
		Colors[num] = to_string(buffer2-15);
	}
	else
		return;
	Color = "";
	//
	for (size_t i = 0; i < Colors.size(); i++)
	{
		if (i+1 == Colors.size())
			Color += Colors[i];
		else
			Color += Colors[i]+';';
	}
	//cout << "!!! NewColor: " << Color << endl;
}