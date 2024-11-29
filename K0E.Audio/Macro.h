#pragma once
#define _CRT_SECURE_NO_WARNINGS
	__pragma(warning(push, 0))

#pragma optimize( "g", on )
#pragma optimize( "t", on )

#include <iostream>
#include <vector>
using namespace std;

#include <SFML/Audio.hpp>

#include "../K0E.XMLParser/XMLParser.h"

#include "Func/GetRandomNumber.h"

// Macro
#define K0E_Audio_Exports __declspec(dllexport)

#ifdef K0E_Audio_Exports
	#define K0E_Audio_Api __declspec(dllexport)
	#else
	#define K0E_Audio_Api __declspec(dllimport)
#endif