#pragma once
#define _CRT_SECURE_NO_WARNINGS
    __pragma(warning(push, 0))

#pragma optimize( "g", on )
#pragma optimize( "t", on )

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Macro
#define K0E_Console_Exports __declspec(dllexport)

#ifdef K0E_Console_Exports
#define K0E_Console_Api __declspec(dllimport)
#else
#define K0E_Console_Api __declspec(dllimport)
#endif