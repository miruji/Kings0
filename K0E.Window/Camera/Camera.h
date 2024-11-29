#pragma once
#include "../Macro.h"

// Window camera 
class K0E_Window_Api Camera
{
private:
	// Camera View 
	sf::View View1;

public:
	// X and Y, W and H 
	float X = 0.0f, Y = 0.0f,
		  W = 0.0f, H = 0.0f;
	// For reset X, Y to player center
	bool AddXY = false;
	float AddX = 0.0f, AddY = 0.0f;

	// Zoom 
	float Zoom = 1.0f;
	float AddZoom = 0.0f;

	// Speed 
	float Speed = 32; // 32 px

	// Constructor
	Camera(float X, float Y, float W, float H);

	// Get view (link) 
	sf::View& GetView();

	// Move 
	void Move(float X, float Y);

	// Set zoom 
	void SetZoom(float Zoom);
};