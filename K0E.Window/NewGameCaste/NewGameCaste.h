#include "../Macro.h"

struct K0E_Window_Api NewGameCaste
{
	int Num;
	string Name = "No name";
	string Color = "255;255;255;210";
	void NewColor(size_t num, char type);
	size_t StartPosition;

	NewGameCaste(int Num);
};