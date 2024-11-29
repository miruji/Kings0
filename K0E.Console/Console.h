#pragma once
#include "Macro.h"

// Class 
class K0E_Console_Api Console
{
private:
	size_t Indent = 0;
	string IndentStr = "";

public:
	// Constructor 
	Console();

	// Get Indent (link) 
	size_t& GetIndent();

	// Set Indent 
	void SetIndent(size_t Indent);

	// Print Ident
	void PrintIdent();

	// Print 
	void Print(string Data);
	// Println 
	void Println(string Data);

	// IPrint 
	void IPrint(string Data);
	// IPrintln 
	void IPrintln(string Data);
};