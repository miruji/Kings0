#pragma once
#include "Macro.h"

// KOE File class 
struct K0E_File_Api File
{
	string Path = "";

	// Constructor 
	File(string Path);

	// File to vector of str 
	vector<string> FileToVector(string AddText);

	// Data to XML file 
	void DataToXMLFile(vector<string> Data);
};