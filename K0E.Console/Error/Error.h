#pragma once
#include "../Macro.h"
#include "../Console.h"

enum class K0E_Console_Api ErrorType
{
	IconLoadError,

	ImageLoadError,

	AudioLoadError,

	SteamLoadError,

	XMLError,

	FatalError,

	WarningError,

	UnknownError
};

// K0E Error 
class K0E_Console_Api Error
{
private:
	ErrorType ErrorType1 = ErrorType::UnknownError;

public:
	// Constructor 
	Error(Console* Console1, ErrorType ErrorType, std::vector<std::string> OutputList, std::vector<std::string> ResultList, bool Shutdown);

	// Get ErrorType1 (link) 
	ErrorType& GetErrorType();
};