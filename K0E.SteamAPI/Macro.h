#pragma once
#define _CRT_SECURE_NO_WARNINGS
	__pragma(warning(push, 0))

#pragma optimize( "g", on )
#pragma optimize( "t", on )

#include "steam/steam_api.h"
#include <iostream>
using namespace std;

#include "../K0E.Console/Console.h"
#include "../K0E.Console/Error/Error.h"

// Macro
#define K0E_SteamAPI_Exports __declspec(dllexport)

#ifdef K0E_SteamAPI_Exports
	#define K0E_SteamAP_Api __declspec(dllimport)
	#else
	#define K0E_SteamAP_Api __declspec(dllimport)
#endif