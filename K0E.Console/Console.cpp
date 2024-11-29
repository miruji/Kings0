#include "Console.h"

// Constructor 
Console::Console() 
{
	// ... 

}

// Get Indent (link) 
size_t& Console::GetIndent()
{
	// ... 
	return Indent;
}

// Set Indent 
void Console::SetIndent(size_t Indent)
{
	// ... 
	this->Indent = Indent;
}

// Print Ident
void Console::PrintIdent()
{

	// Reset IndentStr 
	IndentStr = "";

	// ... 
	for (size_t i = 0; i < Indent; i++)
		IndentStr += "  ";

	printf((IndentStr).c_str());
}

// Print 
void Console::Print(string Data)
{
	// ... 
	printf( (Data).c_str() );
}
// Println 
void Console::Println(string Data)
{
	// ... 
	printf( (Data+"\r\n").c_str() );
}

// IPrint 
void Console::IPrint(string Data)
{
	// ... 
	PrintIdent();
	printf( (IndentStr + Data ).c_str());
}
// IPrintln 
void Console::IPrintln(string Data)
{
	// ... 
	PrintIdent();
	printf( (IndentStr + Data + "\r\n" ).c_str());
}