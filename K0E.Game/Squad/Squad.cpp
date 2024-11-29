#include "Squad.h"

// Constructor 
Squad::Squad()
{
	// ... 
}

// Get Units vector (link) 
vector<Character*>& Squad::GetCharacters()
{
	// ... 
	return Characters;
}

// Get squad tax (link) 
size_t& Squad::GetTax()
{
	// ... 
	return Tax;
}

// Get Squad total damage (link) 
size_t& Squad::GetDamage()
{
	// ... 
	return Damage;
}

// Get squad genere condition (link) 
size_t& Squad::GetCondition()
{
	// ... 
	return Condition;
}