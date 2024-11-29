#pragma once
#define _CRT_SECURE_NO_WARNINGS
	__pragma(warning(push, 0))

#pragma optimize( "g", on )
#pragma optimize( "t", on )

#include <iostream>
#include <vector>
using namespace std;

#include "../tinyxml/tinystr.h"
#include "../tinyxml/tinyxml.h"

// Macro 
#define K0E_XMLParser_Exports __declspec(dllexport)

#ifdef K0E_XMLParser_Exports
	#define K0E_XMLParser_Api __declspec(dllexport)
	#else
	#define K0E_XMLParser_Api __declspec(dllimport)
#endif