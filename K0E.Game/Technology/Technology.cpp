#include "Technology.h"

Technology::Technology(bool Opened, int Cost, vector<size_t> Need)
{
	this->Opened = Opened;
	this->Cost = Cost;
	this->Need = Need;
}

bool Technology::Locked(vector<Technology> Technologys)
{
	for (size_t i = 0; i < Need.size(); i++)
	{
		if (!Technologys[Need[i]].Opened)
			return true;
	}
	return false;
}