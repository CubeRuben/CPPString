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

String::String(char* CharArray) 
{
	this->CharArray = CharArray;
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
	return CharArray;
}

String String::FromInt(int Number)
{
	const int NumberLength = log10(Number) + 1;

	char* newCharArray = new char[NumberLength + 1];

	for (int i = 0; i < NumberLength; i++) 
	{
		int digit = Number / (int)pow(10, i) % 10;
		newCharArray[NumberLength - i - 1] = (char)((int)'0' + digit);
	}

	newCharArray[NumberLength] = '\0';

	return String(newCharArray);
}

String String::GetSubString(int Start, int End)
{
	if (Start < 0 || Start >= GetLength())
		throw std::out_of_range("Requested character out of range");

	if (End < 0 || End >= GetLength())
		throw std::out_of_range("Requested character out of range");

	return String(CopyCharArray(&this->CharArray[Start], End - Start + 1));
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

String String::Replace(const char& CharToReplace, const char& Replacement)
{
	String newStr(*this);

	for (int i = 0; newStr.CharArray[i] != '\0'; i++)
	{
		if (newStr.CharArray[i] == CharToReplace)
		{
			newStr.CharArray[i] = Replacement;
		}
	}

	return newStr;
}

String String::Reverse()
{
	String newStr(*this);

	const int length = newStr.GetLength();

	for (int i = 0; i < length / 2; i++)
	{
		char temp = newStr.CharArray[i];
		newStr.CharArray[i] = newStr.CharArray[length - 1 - i];
		newStr.CharArray[length - 1 - i] = temp;
	}

	return newStr;
}

String& String::operator+(const String& Other)
{
	const int Length = GetLength();
	const int CombinedLength = Length + CalculateCharArrayLength(Other.CharArray);

	char* newCharArray = new char[CombinedLength];

	for (int i = 0; CharArray[i] != '\0'; i++) 
	{
		newCharArray[i] = CharArray[i];
	}

	for (int i = 0; Other.CharArray[i] != '\0'; i++)
	{
		newCharArray[i + Length] = Other.CharArray[i];
	}

	newCharArray[CombinedLength - 1] = '\0';

	delete[] CharArray;
	CharArray = newCharArray;

	return *this;
}

String& String::operator=(const String& Other)
{
	delete[] CharArray;
	CharArray = CopyCharArray(Other.CharArray);
	return *this;
}

String& String::operator*(const int& Other)
{
	if (Other <= 1)
		return *this;

	const int Length = GetLength();
	const int NewLength = Length * Other + 1;
	char* newCharArray = new char[NewLength];

	for (int i = 0; CharArray[i] != '\0'; i++)
	{
		for (int a = 0; a < Other; a++) 
		{
			newCharArray[Length * a + i] = CharArray[i];
		}
	}

	newCharArray[NewLength - 1] = '\0';
	delete[] CharArray;
	CharArray = newCharArray;

	return *this;
}

const char& String::operator[](int Index)
{
	if (Index < 0 || Index >= GetLength())
		throw std::out_of_range("Requested character out of range");

	return CharArray[Index];
}

std::ostream& operator<<(std::ostream& Output, const String& String)
{
	return Output << String.CharArray;
}

bool operator==(const String& First, const String& Second)
{
	const int FirstLength = String::CalculateCharArrayLength(First.CharArray);
	const int SecondLength = String::CalculateCharArrayLength(Second.CharArray);

	if (FirstLength != SecondLength)
		return false;

	for (int i = 0; i < FirstLength; i++) 
	{
		if (First.CharArray[i] != Second.CharArray[i])
			return false;
	}

	return true;
}

bool operator!=(const String& First, const String& Second)
{
	return !(First == Second);
}
