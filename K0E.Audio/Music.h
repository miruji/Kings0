#pragma once
#include "Macro.h"

// Class music
class K0E_Audio_Api Music
{
private:
	// Music
	sf::Music* Music1;

public:
	// Loaded 
	bool Loaded = false;

	// Constructor
	Music(string Path);

	// Get music (link)
	sf::Music* GetMusic();

	// Play
	void Play();

	// Stop
	void Stop();
};