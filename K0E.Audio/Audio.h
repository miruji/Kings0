#pragma once
#include "Macro.h"

#include "Music.h"
#include "Sound.h"

// Class Audio
class K0E_Audio_Api Audio {
public:
	int Soundtrack = 80, SoundEffects = 80;

	XMLParser* XMLParser1; // Xml parser
	TiXmlElement* ElAudio; // Audio.xml

		// Parse XML soundtrack
		void ParseSoundtrack(TiXmlElement* MainBlock);

		// Parse XML sound
		void ParseSound(TiXmlElement* MainBlock);

	// Basic stream of music
	sf::Music* MusicStream;

	// Music vector
	vector<Music*> Musics;
	int MusicCount = 0;

		// Play music
		void PlayMusic();

		// Stop music
		void StopMusic();

		// Next music
		void NextMusic();

		// Back music
		void BackMusic();

		// Random music
		void RandomMusic();

		// Random music ? 
		bool RandomMusicType = false;

		// Repeat music ? 
		bool RepeatMusicType = false;

	// Sound vector
	vector<Sound*> Sounds;
	size_t SoundCount = 0;

		// Play sound 
		void PlaySound1(size_t Count);

		// Play sound (by Name) 
		void PlaySound1(string Name);

		// Stop music 
		void StopSound1(size_t Count);

	// Constructor
	Audio(Console* Console1);
};