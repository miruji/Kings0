#include "DevideOutCharacter.h"

string DevideOutCharacter(string Text)
{
	// ... 
	string Buffer = "";
	for (size_t i = 0; i < Text.length() - 1; i++)
		Buffer += Text[i];
	return Buffer;
}