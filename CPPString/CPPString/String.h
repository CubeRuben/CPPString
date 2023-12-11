#pragma once

#include <iostream>

class String
{
public:

	String();
	String(const char* CharArray);
	String(const String& Other);

	~String();

protected:

	static const int CharacterCaseOffset;
	static char* GetNoneString();

	static int CalculateCharArrayLength(const char* CharArray);
	static char* CopyCharArray(const char* OriginalArray);
	static char* CopyCharArray(const char* OriginalArray, int CopyLength);

private:

	char* CharArray;

public:

	int GetLength();

	const char* GetCharArray();

	String GetSubString(int Start, int End);
	String ToUpperCase();
	String ToLowerCase();


	friend std::ostream& operator<<(std::ostream& Output, const String& String);
};

