#include "UISlideInt.h"

UISlideInt::UISlideInt(string BlockName, string Id, string ImageId, int Min, int Max, string X, string Y, string W) : UIObject(BlockName, Id, ImageId, X, Y)
{
	this->Min = Min;
	this->Max = Max;

	this->W = W;
}

int UISlideInt::GetH()
{
	return atoi(W.c_str());
}