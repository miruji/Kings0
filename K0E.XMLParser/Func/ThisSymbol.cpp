#include "ThisSymbol.h"

// This symbol 
bool ThisSymbol(char C)
{
	bool Result = true;
	if (C == ' ')             Result = false; else
	if (C >= '0' && C <= '9') Result = false; else
	if (C >= 'a' && C <= 'z') Result = false; else
	if (C >= 'A' && C <= 'Z') Result = false; else
	if (C >= '�' && C <= '�') Result = false; else
	if (C >= '�' && C <= '�') Result = false;

	return Result;
}