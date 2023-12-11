#include "String.h"

#include <math.h>

const int String::CharacterCaseOffset = (int)'a' - (int)'A';

char* String::GetNoneString()
{
	char* newChar = new char[1];
	newChar[0] = '\0';
	return newChar;
}

int String::CalculateCharArrayLength(const char* CharArray)
{
	int length = 0;

	while (CharArray[length++] != '\0') {}

	return length;
}

char* String::CopyCharArray(const char* OriginalArray)
{
	return CopyCharArray(OriginalArray, CalculateCharArrayLength(OriginalArray) - 1);
}

char* String::CopyCharArray(const char* OriginalArray, int CopyLength)
{
	if (CopyLength <= 0) 
	{
		return GetNoneString();
	}

	CopyLength++;

	char* copy = new char[CopyLength];

	for (int i = 0; i < CopyLength - 1; i++)
	{
		copy[i] = OriginalArray[i];
	}

	copy[CopyLength - 1] = '\0';

	return copy;
}

String::String()
{
	CharArray = GetNoneString();
}

String::String(const char* CharArray)
{
	this->CharArray = CopyCharArray(CharArray);
}

String::String(const String& Other)
{
	CharArray = CopyCharArray(Other.CharArray);
}

String::~String()
{
	delete[] CharArray;
}

int String::GetLength()
{
	return CalculateCharArrayLength(CharArray) - 1;
}

const char* String::GetCharArray()
{
	return CopyCharArray(CharArray);
}

String String::GetSubString(int Start, int End)
{
	return String(CopyCharArray(&(*this)[Start], End - Start + 1));
}

String& String::ToUpperCase()
{
	for (int i = 0; CharArray[i] != '\0'; i++)
	{
		const int charIndex = (int)CharArray[i];

		if (charIndex >= (int)'a' && charIndex <= (int)'z')
		{
			CharArray[i] = charIndex - CharacterCaseOffset;
		}
	}

	return *this;
}

String& String::ToLowerCase()
{
	for (int i = 0; CharArray[i] != '\0'; i++)
	{
		const int charIndex = (int)CharArray[i];

		if (charIndex >= (int)'A' && charIndex <= (int)'Z')
		{
			CharArray[i] = charIndex + CharacterCaseOffset;
		}
	}

	return *this;
}

String& String::Replace(const char& CharToReplace, const char& Replacement)
{
	String newStr(*this);



	return newStr;
}

const char& String::operator[](int index)
{
	if (index < 0 || index >= GetLength())
		throw std::out_of_range("Requested character out of range");

	return CharArray[index];
}

std::ostream& operator<<(std::ostream& Output, const String& String)
{
	Output << String.CharArray;
	return Output;
}
