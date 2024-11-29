#pragma once
#include "../Macro.h"
#include "../Func/GetRandomNumber.h"

struct K0E_Game_Api Technology
{
	bool Opened;
	int Cost;
	vector<size_t> Need;

	Technology(bool Opened, int Cost, vector<size_t> Need);
	bool Locked(vector<Technology> Technologys);
};