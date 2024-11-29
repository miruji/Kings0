#include "XMLSettlement.h"

// Constructor 
XMLSettlement::XMLSettlement(string Name, string Type, size_t Population, size_t Team, float X, float Y)
{
	// Name 
	this->Name = Name;

	// Type 
	this->Type = Type;

	// Population
	this->Population = Population;

	// Team
	this->Team = Team;

	// Set X & Y 
	this->X = X; this->Y = Y;
}
XMLSettlement::XMLSettlement()
{
	// ... 
}
