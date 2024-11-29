#include "UIComboBox.h"

// Constructor 
UIComboBox::UIComboBox(string BlockName, string Id, string ImageId, string Spec, string Text, LanguagePack* LanguagePack1, string X, string Y, float Width) : UIObject(BlockName, Id, ImageId, X, Y)
{
	// Set language 
	this->LanguagePack1 = LanguagePack1;

	// Set spec (TO:DO) 
	string Buffer = "";
	for (size_t i = 0; i < Spec.length(); i++)
	{
		if (Spec[i] == '|' || i+1 == Spec.length())
		{
			if (i+1 == Spec.length())
				Buffer += Spec[i];

			this->Specs.push_back(Buffer);
			//cout << Buffer << endl;
			Buffer = "";
		}
		else
			Buffer += Spec[i];
	}
	// Set text 
	//cout << "TT: " << Text << endl;
	for (size_t i = 0; i < Text.length(); i++)
	{
		if (Text[i] == '|' || i+1 == Text.length())
		{
			if (i+1 == Text.length())
				Buffer += Text[i];

			// Set text 
			if (Buffer[0] == '~')
			{
				// 
				string Buffer2 = "";
				for (size_t i = 1; i < Buffer.length(); i++)
					Buffer2 += Buffer[i];

				// 
				if ( LanguagePack1->GetLanguageText(Buffer2) != "" )
					this->Texts.push_back( LanguagePack1->GetLanguageText(Buffer2) );
				else
					this->Texts.push_back(Buffer2);
			}
			else
				this->Texts.push_back(Buffer);

			
			//cout << Buffer << endl;
			Buffer = "";
		}
		else
			Buffer += Text[i];
	}

	// Set x and y 
	this->X = X;
	this->Y = Y;

	this->Width = Width;
}

// Set texts 
void UIComboBox::SetTexts(vector<string> Texts)
{
	this->Texts = Texts;
}

// Get texts (Link) 
vector<string>& UIComboBox::GetTexts()
{
	return Texts;
}