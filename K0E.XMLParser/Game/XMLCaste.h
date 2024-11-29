#pragma once

#include "../Macro.h"
#include "XMLSettlement.h"

// Class caste
class K0E_XMLParser_Api XMLCaste
{
public:
	// Team
	size_t Team = 0;

	// Settlemnts
	vector< XMLSettlement* > XMLSettlements;

	// Constructor
	XMLCaste(size_t Team, vector< XMLSettlement* > XMLSettlements);
};