#include "SearchChar.h"

// Search char 
bool SearchChar(string Text, char Search)
{
	// ... 
	bool Result = false;

	for (size_t i = 0; i < Text.length(); i++)
	{
		if (Text[i] == Search)
		{
			Result = true;
			break;
		}
	}

	return Result;
}