#pragma once 
#include "UIObject.h"

//
class K0E_Window_Api UISlideInt : public UIObject
{
public:
	int Slider = 0;
	int Min = 0, Max = 1;

	int GetH();

	UISlideInt(string BlockName, string Id, string ImageId, int Min, int Max, string X, string Y, string W);
};