#pragma once
#include "../Macro.h"

// Class 
class K0E_Game_Api Event
{
private:
	//size_t Koef = 0; // % 
	size_t Id = 0; // In item list 


public:
	// Constructor 
	Event(size_t Id, string Type, string Yes, string No);

	// Do 
	void Do();
};