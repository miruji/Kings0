#include "GetBackEventNumber.h"

size_t GetBackEventNumber(string Event)
{
	string buffer1 = "";
	for (size_t i = Event.length()-1; i > 0; i--)
	{
		if (ThisInt(Event[i]))
			buffer1 += Event[i];
		else
			break;
	}
	//
	if (buffer1.length() > 1)
		reverse(buffer1.begin(), buffer1.end());
	//
	return atoi(buffer1.c_str());
}