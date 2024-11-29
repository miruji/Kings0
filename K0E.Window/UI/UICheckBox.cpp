#include "UICheckBox.h"

// Constructor 
UICheckBox::UICheckBox(string BlockName, string Spec, string Text, LanguagePack* LanguagePack1, float Size, string CheckEvent, float XX, string X, float YY, string Y) : UIObject(BlockName, "", "", X, Y)
{
	// Set check event 
	this->CheckEvent = CheckEvent;

	// Set spec 
	this->Spec = Spec;

	// Set language 
	this->LanguagePack1 = LanguagePack1;

	// Set x and y 
	this->X = X; this->Y = Y;
	this->XX = XX; this->YY = YY;

	// Set size 
	this->Size = Size;

	// Set text 
	SetText(Text);
}

// Set XML XY
void UICheckBox::SetXMLXY()
{
	// ! Set X
	if (XToX == true)
	{
		//float XBuffer = XX + FirstX + (SecondX - FirstX) / 2 - (TextString.length() * ((Size - 5.5) / 2)) / 2;
		//float XBuffer = XX + ((SecondX - FirstX) /2) + ( (TextString.length()*Size) /2);
		float XBuffer = 0.0f;
		if (Text.length() != 1)
			XBuffer = XX + (FirstX + SecondX) / 2 - (TextLength*Size/2/1.5);
		else
			XBuffer = XX + (FirstX + SecondX) / 2 - ((TextLength+1)*Size/2/2/2);
		//cout << to_string(XBuffer) << endl;

		SetXY(to_string(XBuffer), this->Y);
	}
	//cout << "X: " << XX << ", FX: " << FirstX << ", SX: " << SecondX << endl;
	// ! Set Y
	if (YToY == true)
	{
		float YBuffer = YY + FirstY + (SecondY - FirstY) / 2 - ((Size - Size/2 - Size/2/2 + Size/2/2) * 2) / 2;
		//cout << to_string(YBuffer) << endl;
		
		SetXY(this->X, to_string(YBuffer));
	}
	//cout << "Y: " << YY << ", FY: " << FirstY << ", SY: " << SecondY << endl;

	// Else to 
	if (XToX == false && YToY == true)
		SetXY(to_string(FirstX+XX), this->Y);
	else
	if (XToX == true && YToY == false)
		SetXY(this->X, to_string(FirstY+YY));
	else
	if (XToX == false && YToY == false)
		SetXY(to_string(FirstX+XX), to_string(FirstY+YY));

	//cout << "X: " << this->X << ", Y: " << this->Y << endl;
	//cout << endl;
}

// Set text 
void UICheckBox::SetText(string Text)
{
	// Set text 
	if (Text[0] == '~')
	{
		// 
		string Buffer = "";
		for (size_t i = 1; i < Text.length(); i++)
			Buffer += Text[i];

		// 
		if ( LanguagePack1->GetLanguageText(Buffer) != "" )
			this->Text = LanguagePack1->GetLanguageText(Buffer);
		else
			this->Text = Text;
	}
	else
		this->Text = Text;

	if (true)
	{
		string Buffer = "";
		for (size_t i = 0; i < this->Text.length(); i++)
		{
			//cout << this->Text[i] << " : " << ThisSymbol(this->Text[i]) << endl;
			if (ThisSymbol(this->Text[i]) == false)
				Buffer += this->Text[i];
		}
		TextLength = Buffer.length();
	}

	// ! Set X
	string Buffer = "";
	for (size_t i = 0; i < X.length(); i++)
	{
		// ... 
		if (X[i] == '|' || i+1 == X.length())
		{
			if (i+1 == X.length())
				Buffer += X[i];

			if (X[i] == '|')
				XToX = true;

			XBuffer.push_back(atof(Buffer.c_str()));
			Buffer = "";
		}
		else
			Buffer += X[i];
	}
	if (XBuffer[0] != NULL)
		FirstX = XBuffer[0];
	else
		FirstX = NULL;

	if (XBuffer[1] != NULL)
		SecondX = XBuffer[1];
	else
		SecondX = NULL;
	// ! Set Y
	Buffer = "";
	for (size_t i = 0; i < Y.length(); i++)
	{
		// ... 
		if (Y[i] == '|' || i+1 == Y.length())
		{
			if (i+1 == Y.length())
				Buffer += Y[i];

			if (Y[i] == '|')
				YToY = true;

			YBuffer.push_back(atof(Buffer.c_str()));
			Buffer = "";
		}
		else
			Buffer += Y[i];
	}
	if (YBuffer[0] != NULL)
		FirstY = YBuffer[0];
	else
		FirstY = NULL;

	if (YBuffer[1] != NULL)
		SecondY = YBuffer[1];
	else
		SecondY = NULL;

	if (XToX == true || YToY == true)
	{
		SetXMLXY();
	}
	else
		SetXY(to_string(XBuffer[0] + XX), to_string(YBuffer[0] + YY));

	// Update position
	SetXY(this->X, this->Y);
}

// Set value 
void UICheckBox::SetValue(bool Value)
{
	// ... 
	this->Value = Value;
}

// Get value (link) 
bool& UICheckBox::GetValue()
{
	// ... 
	return Value;
}

// Get text (link) 
string& UICheckBox::GetText()
{
	// ... 
	return Text;
}

// Get size (link) 
float& UICheckBox::GetSize()
{
	// ... 
	return Size;
}

// Get spec (link) 
string& UICheckBox::GetSpec()
{
	// ... 
	return Spec;
}

// Get check event
string& UICheckBox::GetCheckEvent()
{
	// ... 
	return CheckEvent;
}