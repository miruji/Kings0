#pragma once
#include "../../Macro.h"

struct K0E_Map_Api MapBlock
{
	// X and Y
	float X = 0, Y = 0;

	// Block size
	sf::Vector2i BlockSize;

	// Block type
	size_t Type = 1;

	// IntRect
	sf::IntRect Rect;
	float RectAddY = 0;

	// Land ? 
	bool Land = false;

	// River ? 
	bool River = false;

	// Lake ?
	bool Lake = false;

	// Forest ? 
	bool Forest = false;

	// Mountain ? 
	bool Mountain = false;

	// Settlement ? 
	size_t Settlement = 0;
	bool SettlementDrawing = true;

	// War Fog ? 
	bool WarFog = true;

	// Road ? 
	bool Road = false;

	// Enemy ? 
	size_t Enemy = 0;

	// Wood 
	int Wood = 0;

	// Constructor
	MapBlock(float X, float Y, float W, float H, size_t Type);
	MapBlock(); // Basic

	// Updating
	void Update();
};