#include "../Window.h"

void Window::DeleteGame(size_t DeleteUnit)
{
	remove(("Data\\Saves\\"+to_string(DeleteUnit)+".xml").c_str());
}