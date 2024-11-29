#include "Event.h"

// Constructor 
Event::Event(size_t Id, string Type, string Yes, string No)
{
	// Id 
	this->Id = Id;
	cout << Id << endl;

}

// Do 
void Event::Do()
{
	// ... 
	cout << "Do!" << endl;
}