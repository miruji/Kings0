#include "Camera.h"

// Constructor
Camera::Camera(float X, float Y, float W, float H) {
	// X and Y, W and H 
	this->X = X; this->Y = Y;
	this->W = W; this->H = H;

	// Create View
	View1 = sf::View(sf::Vector2f(X, Y), sf::Vector2f(W, H));
}

// Get view (link) 
sf::View& Camera::GetView() 
{
	// Return camera view 
	return View1;
}

// Move 
void Camera::Move(float X, float Y)
{
	// Set new X and Y 
	this->X += X; this->Y += Y;

	// Move View 
	View1.move(X, Y);
}

// Set zoom 
void Camera::SetZoom(float Zoom)
{
	// Setting
	this->Zoom = Zoom;
	//cout << "!> Zoom: " << Zoom << ", AddZoom: " << AddZoom << endl;

	// Updating
	View1.zoom(Zoom);
}