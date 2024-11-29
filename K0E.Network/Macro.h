#pragma once
#define _CRT_SECURE_NO_WARNINGS
__pragma(warning(push, 0))

#pragma optimize( "g", on )
#pragma optimize( "t", on )

#include <iostream>
#include <string>
using namespace std;

#include "../K0E.Console/Console.h"
#include "../K0E.Console/Error/Error.h"
#include <SFML/Network.hpp>

// Macro
#define K0E_Network_Exports __declspec(dllexport)

#ifdef K0E_Network_Exports
	#define K0E_Network_Api __declspec(dllimport)
	#else
	#define K0E_Network_Api __declspec(dllimport)
#endif