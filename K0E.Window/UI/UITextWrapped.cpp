#include "UITextWrapped.h"

//
UITextWrapped::UITextWrapped(string BlockName, string Id, vector<string> Text, LanguagePack* LanguagePack1, string X, string Y, string W, string H) : UIObject(BlockName, Id, "", X, Y)
{
	// Set text 
	if (Text[0][0] == '~')
	{
		string Buffer = "";
		for (size_t i = 1; i < Text[0].length(); i++)
			Buffer += Text[0][i];

		string Buffer2 = '`'+LanguagePack1->GetLanguageText(Buffer);
		Buffer = "";
		for (size_t i = 0; i < Buffer2.length(); i++)
		{
			if (Buffer2[i] == ';' || i+1 == Buffer2.length())
			{
				if (i+1 == Buffer2.length())
					Buffer += Buffer2[i];
				this->Text += Buffer+"\n\n";
				Buffer = "";
			}
			else
			{
				if(Buffer2[i] == '`')
					Buffer += ' ';
				else
					Buffer += Buffer2[i];
			}
		}
	}
	else
		this->Text = Text[0];

	this->X = atoi(X.c_str()); this->Y = atoi(Y.c_str());
	this->W = atoi(W.c_str()); this->H = atoi(H.c_str());
}