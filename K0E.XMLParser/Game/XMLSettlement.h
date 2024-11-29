#pragma once

#include "../Macro.h"

// Class XML settlemt 
class K0E_XMLParser_Api XMLSettlement
{
public:
	// Name 
	string Name = "Noname";

	// Type 
	string Type = "Settlement";

	// Population 
	size_t Population = 1;

	// Team 
	size_t Team = 0;

	// X & Y 
	float X = 0.0f, Y = 0.0f;

	// Constructor 
	XMLSettlement(string Name, string Type, size_t Population, size_t Team, float X, float Y);
	XMLSettlement();
};