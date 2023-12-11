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
	CopyLength++;

	if (CopyLength <= 0) 
	{
		return GetNoneString();
	}

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
	return String(CopyCharArray(&CharArray[Start], End - Start + 1));
}

String String::ToUpperCase()
{
	String newStr(*this);

	for (int i = 0; newStr.CharArray[i] != '\0'; i++)
	{
		const int charIndex = (int)newStr.CharArray[i];

		if (charIndex >= (int)'a' && charIndex <= (int)'z')
		{
			newStr.CharArray[i] = charIndex - CharacterCaseOffset;
		}
	}

	return newStr;
}

String String::ToLowerCase()
{
	String newStr(*this);

	for (int i = 0; newStr.CharArray[i] != '\0'; i++)
	{
		const int charIndex = (int)newStr.CharArray[i];

		if (charIndex >= (int)'A' && charIndex <= (int)'Z')
		{
			newStr.CharArray[i] = charIndex + CharacterCaseOffset;
		}
	}

	return newStr;
}

std::ostream& operator<<(std::ostream& Output, const String& String)
{
	Output << String.CharArray;
	return Output;
}
