#pragma once
#define _CRT_SECURE_NO_WARNINGS
	__pragma(warning(push, 0))

#pragma optimize( "g", on )
#pragma optimize( "t", on )

#include <windows.h>

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

#include "../K0E.XMLParser/XMLParser.h"

#undef min
#undef max
#include <SFML/Graphics.hpp>

// Macro
#define K0E_Game_Exports __declspec(dllexport)

#ifdef K0E_Game_Exports
	#define K0E_Game_Api __declspec(dllexport)
	#else
	#define K0E_Game_Api __declspec(dllimport)
#endif