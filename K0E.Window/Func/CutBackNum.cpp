#include "CutBackNum.h"

string CutBackNum(string Event)
{
	string Buffer = "";
	for (size_t i = 0; i < Event.length(); i++)
	{
		if (Event[i] == '_' || ThisInt(Event[i]))
		{
			break;
		}
		else
			Buffer += Event[i];
	}
	return Buffer;
}