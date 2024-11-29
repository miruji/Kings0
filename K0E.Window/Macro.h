#pragma once
#define _CRT_SECURE_NO_WARNINGS
	__pragma(warning(push, 0))

#pragma optimize( "g", on )
#pragma optimize( "t", on )

#include <iostream>
#include <string>

#include "UI/ImGui/imgui.h"
#include "UI/ImGui/imgui-SFML.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "../K0E.XMLParser/XMLParser.h"

#include "Func/GetRandomNumber.h"

#define RGBA_TO_FLOAT(r,g,b,a) (float)r/255.0f, (float)g/255.0f, (float)b/255.0f, (float)a/255.0f

#include "../K0E.Console/Console.h"
#include "../K0E.Console/Error/Error.h"

// Macro 
#define K0E_Window_Exports __declspec(dllexport)

#ifdef K0E_Window_Exports
	#define K0E_Window_Api __declspec(dllexport)
	#else
	#define K0E_Window_Api __declspec(dllimport)
#endif