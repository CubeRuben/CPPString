#include "String.h"

#include <math.h>

const int String::CharacterCaseOffset = (int)'a' - (int)'A';

char* String::GetNoneString()
{
	char* newChar = new char[1];
	newChar[0] = '\0';
	return newChar;
}

char* String::CopyCharArray(const char* OriginalArray, int Length)
{
	return CopyCharArray(OriginalArray, Length, Length);
}

char* String::CopyCharArray(const char* OriginalArray, int Length, int CopyLength)
{
	char* copy = new char[Length];

	//Проверка, если длина копирования больше длины массива
	const int iterateLength = std::min(CopyLength, Length);

	for (int i = 0; i < iterateLength; i++)
	{
		copy[i] = OriginalArray[i];
	}

	return copy;
}

String::String()
{
	Length = 0;
	CharArray = GetNoneString();
}

String::String(const char* CharArray)
{
	Length = 0;

	while (true) 
	{
		if (CharArray[Length] == '\0') 
			break;

		Length++;
	}

	this->CharArray = CopyCharArray(CharArray, Length);
}

String::String(const char* CharArray, int Length)
{
	this->Length = std::max(0, Length);

	if (Length < 0)
	{
		this->CharArray = GetNoneString();
	}
	else
	{
		this->CharArray = CopyCharArray(CharArray, Length);
	}
}

String::String(const String& Other)
{
	Length = Other.Length;
	CharArray = CopyCharArray(Other.CharArray, Length);
}

String::~String()
{
	delete[] CharArray;
}

const char* String::GetCharArray()
{
	char* returnCopy = CopyCharArray(CharArray, Length + 1, Length);
	returnCopy[Length] = '\0';
	return returnCopy;
}

String String::GetSubString(int Start, int End)
{
	return String(CopyCharArray(&CharArray[Start], Start + End), End - Start);
}

String String::ToUpperCase()
{
	String newStr(*this);

	for (int i = 0; i < newStr.Length; i++)
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

	for (int i = 0; i < newStr.Length; i++)
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
	for (int i = 0; i < String.Length; i++) 
	{
		Output << String.CharArray[i];
	}

	Output << '\0';

	return Output;
}
