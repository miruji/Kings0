#pragma once
#define _CRT_SECURE_NO_WARNINGS
	__pragma(warning(push, 0))

#pragma optimize( "g", on )
#pragma optimize( "t", on )

#include <iostream> 
#include <string>
using namespace std;

#include <vector>
#include <fstream>

// Macro
#define K0E_File_Exports __declspec(dllexport)

#ifdef K0E_File_Exports
	#define K0E_File_Api __declspec(dllexport)
	#else
	#define K0E_File_Api __declspec(dllimport)
#endif