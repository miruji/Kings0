#include "File.h"

// Constructor
File::File(string Path)
{
	// ...
	this->Path = Path;
}

// File to vector of str 
vector<string> File::FileToVector(string AddText)
{
	// Open file 
	cout << AddText<<"#K0E.File \"" + Path + "\":" << endl;
	// ...
	vector<string> Result;
	string Str = "";

	// ...
	ifstream File(Path);
	
	// Is file open 
	if (File.is_open ()) 
	{
		cout << AddText<<"| File is open ..." << endl;
		// Read file 
		while (getline(File, Str)) 
		{
			// ...
			Result.push_back(Str);
		}
	}
	else
	{
		cout << AddText<<"| File is not open ..." << endl;
		cout << AddText<<"| exit(0) ..." << endl;
		exit(0);
	}

	// ...
	return Result;
}

// Data to XML file 
void File::DataToXMLFile(vector<string> Data)
{
	// ... 
	std::ofstream OutputFile;
	OutputFile.open(Path+".xml", ios_base::trunc);
	
	for (size_t i = 0; i < Data.size(); i++)
		OutputFile << Data[i] << endl;

	OutputFile.close();
}