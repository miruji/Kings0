#pragma once
#include "Macro.h"

// Class music
class K0E_Audio_Api Sound
{
private:
	// ... 
	sf::SoundBuffer SoundBuffer;
	sf::Sound* Sound1;

	// Name 
	string Name;
	void PathToName(string Path);

public:
	// Loaded 
	bool Loaded = false;

	// Constructor 
	Sound(string Path);

	// Get sound (link)
	sf::Sound* GetSound();

	// Play
	void Play();

	// Stop
	void Stop();

	// Get name (link) 
	string& GetName();
};