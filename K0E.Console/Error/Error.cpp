#include "Error.h"

// Constructor 
Error::Error(Console* Console1, ErrorType ErrorType, std::vector<std::string> ReasonList, std::vector<std::string> ResultList, bool Shutdown)
{
	// Set error type 
	Console1->SetIndent(0);
	Console1->IPrint( "!> K0E.Error: " );

	if (ErrorType == ErrorType::IconLoadError)
	{
		this->ErrorType1 = ErrorType::IconLoadError;
		Console1->IPrintln("(IconLoadError): ");
	}
	else
	if (ErrorType == ErrorType::ImageLoadError)
	{
		this->ErrorType1 = ErrorType::ImageLoadError;
		Console1->IPrintln( "(ImageLoadError): " );
	}
	else
	if (ErrorType == ErrorType::AudioLoadError)
	{
		this->ErrorType1 = ErrorType::AudioLoadError;
		Console1->IPrintln( "(AudioLoadError): " );
	}
	else
	if (ErrorType == ErrorType::SteamLoadError)
	{
		this->ErrorType1 = ErrorType::SteamLoadError;
		Console1->IPrintln( "(SteamLoadError): " );
	}
	else
	if (ErrorType == ErrorType::XMLError)
	{
		this->ErrorType1 = ErrorType::XMLError;
		Console1->IPrintln( "(XMLError): " );
	}
	else
	if (ErrorType == ErrorType::FatalError)
	{
		this->ErrorType1 = ErrorType::FatalError;
		Console1->IPrintln( "(FatalError): " );
	}
	else
	if (ErrorType == ErrorType::WarningError)
	{
		this->ErrorType1 = ErrorType::WarningError;
		Console1->IPrintln( "(WarningError): " );
	}
	else
	{
		this->ErrorType1 = ErrorType::UnknownError;
		Console1->IPrintln( "(UnknownError): " );
	}

	// Printf ReasonList 
	Console1->SetIndent(1);
	Console1->IPrint( "> Reason: \r\n" );
	for (size_t i = 0; i < ReasonList.size(); i++)
	{
		// ... 
		Console1->IPrintln( "    "+std::to_string(i)+" "+ReasonList[i] );
	}

	// Printf ResultList 
	if (ResultList.size() != 0)
		Console1->IPrint( "> Result: \r\n" );
	for (size_t i = 0; i < ResultList.size(); i++)
	{
		// ... 
		Console1->IPrintln( "    "+std::to_string(i)+" "+ResultList[i] );
	}

	// Shutdown 
	if (Shutdown)
		exit(0);
}

// Get ErrorType1 (link) 
ErrorType& Error::GetErrorType()
{
	// ... 
	return ErrorType1;
}