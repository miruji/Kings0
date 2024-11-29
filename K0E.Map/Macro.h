#pragma once
#pragma optimize( "g", on )
#pragma warning(disable : 4273)
#pragma warning(disable : 4244)

#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
#include "Func/GetRandomNumber.h"

#define K0E_Map_Exports __declspec(dllexport)

#ifdef K0E_Map_Exports
#define K0E_Map_Api __declspec(dllexport)
#else
#define K0E_Map_Api __declspec(dllimport)
#endif