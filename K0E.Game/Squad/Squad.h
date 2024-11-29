#pragma once
#include "../Macro.h"
#include "Character.h"

// Class Squad
class K0E_Game_Api Squad
{
private:
	// Units vector 
	vector< Character* > Characters;

	// Squad tax 
	size_t Tax = 0;

	// Squad total damage 
	size_t Damage = 0;

	// Squad genere condition 
	size_t Condition = 100; // in percent (%)

	// Army (all classes) 
	size_t Infantry = 0; 
	size_t Archers = 0;
	size_t Cavalry = 0;
	size_t SiegeEngines = 0;

public:
	// Constructor 
	Squad();

	// Get Units vector (link) 
	vector< Character* >& GetCharacters();

	// Get squad tax (link) 
	size_t& GetTax();

	// Get Squad total damage (link) 
	size_t& GetDamage();

	// Get squad genere condition (link) 
	size_t& GetCondition();
};