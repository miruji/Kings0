#include "UIInput.h"

//
UIInput::UIInput(string BlockName, string Id, string Type, string Spec, vector<string> Text, LanguagePack* LanguagePack1, string X, string Y, string W, string H) : UIObject(BlockName, Id, "", X, Y)
{
	//
	this->Spec = Spec;

	// Type
	if (true)
	{
		vector<string> Buffer2;
		string Buffer = "";
		for (size_t i = 0; i < Type.length(); i++)
		{
			if (Type[i] == '|' || i+1 == Type.length())
			{
				if (i+1 == Type.length())
					Buffer += Type[i];

				Buffer2.push_back(Buffer);
				Buffer = "";
			}
			else
				Buffer += Type[i];
		}

		this->Type = Buffer2[0];
		if (Buffer2.size() == 2)
			MaxChars = atoi(Buffer2[1].c_str());
	}

	// Set text 
	if (Text[0][0] == '~')
	{
		string Buffer = "";
		for (size_t i = 1; i < Text[0].length(); i++)
			Buffer += Text[0][i];

		string Buffer2 = LanguagePack1->GetLanguageText(Buffer);
		Buffer = "";
		for (size_t i = 0; i < Buffer2.length(); i++)
		{
			if (Buffer2[i] == ';' || i+1 == Buffer2.length())
			{
				if (i+1 == Buffer2.length())
					Buffer += Buffer2[i];

				this->Text.push_back(Buffer);
				Buffer = "";
			}
			else
				Buffer += Buffer2[i];
		}
	}
	else
		this->Text = Text;

	//for (size_t i = 0; i < Text.size(); i++)
	//	cout << Text[i] << endl;

	this->X = atoi(X.c_str()); this->Y = atoi(Y.c_str());
	this->W = atoi(W.c_str()); this->H = atoi(H.c_str());
}