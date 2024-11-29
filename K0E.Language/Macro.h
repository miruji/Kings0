#pragma once 

#include <iostream>
#include <vector>
using namespace std;

#include "../K0E.File/File.h"

#define K0E_Language_Exports __declspec(dllexport)

#ifdef K0E_Language_Exports
	#define K0E_Language_Api __declspec(dllimport)
	#else
	#define K0E_Language_Api __declspec(dllimport)
#endif