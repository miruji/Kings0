#include "../Window.h"

// UI: CheckBox event 
void Window::UICheckBoxEvent(string CheckEvent, size_t Value)
{
	//
	//cout << CheckEvent << " | " << Value << endl;
	if (CheckEvent == "VerticalSync")
		VerticalSync = Value;
	else
	if (CheckEvent == "RandomMusicType")
		Audio1->RandomMusicType = Value;
	else
	if (CheckEvent == "RepeatMusicType")
		Audio1->RepeatMusicType = Value;
}

// UI: CheckBox First draw 
void Window::UICheckBoxFirstDraw(UICheckBox* UICheckBox1)
{
	//
	//cout << CheckEvent << " | " << Value << endl;
	if (UICheckBox1->GetCheckEvent() == "VerticalSync")
		UICheckBox1->SetValue(VerticalSync);
	else
	if (UICheckBox1->GetCheckEvent() == "RandomMusicType")
		UICheckBox1->SetValue(Audio1->RandomMusicType);
	else
	if (UICheckBox1->GetCheckEvent() == "RepeatMusicType")
		UICheckBox1->SetValue(Audio1->RepeatMusicType);
	else
		UICheckBox1->SetValue(false);
}