#include "ThisInt.h"

bool ThisInt(char C)
{
	if (C <= '9' && C >= '0')
		return true;
	else
		return false;
}