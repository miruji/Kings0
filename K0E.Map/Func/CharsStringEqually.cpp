#include "CharsStringEqually.h"

// String equally ?
bool CharsStringEqually(std::string Str1, std::string Str2)
{
	// ...
	bool Result = true;
	// ...
	for (size_t i = 0; i < Str2.length(); i++) {
		if (Str1[i] == Str2[i]) {
			// Result == true
		}
		else
		{
			Result = false;
			return Result;
		}
	}
	// ...
	return Result;
}