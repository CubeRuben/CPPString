#pragma once

#include <iostream>

class String
{
public:

	String();
	String(const char* CharArray);
	String(const char* CharArray, int Length);
	String(const String& Other);

	~String();

protected:

	static const int CharacterCaseOffset;
	static char* GetNoneString();

	static char* CopyCharArray(const char* OriginalArray, int Length);
	static char* CopyCharArray(const char* OriginalArray, int Length, int CopyLength);

private:

	char* CharArray;
	int Length;

public:

	int GetLength() { return Length; }

	const char* GetCharArray();

	String GetSubString(int Start, int End);
	String ToUpperCase();
	String ToLowerCase();


	friend std::ostream& operator<<(std::ostream& Output, const String& String);
};

