#include "Window.h"

// Get window position 
void Window::GetWindowPosition(int& x, int& y)
{
	// ... 
	HWND HWND1 = FindWindow(0, StringToWString(Title).c_str());
	// ... 
	RECT rect;
	GetWindowRect(HWND1, &rect);
	x = rect.top;
	y = rect.left;
}