#pragma once

#include <iostream>
#include <vector>

class String
{
public:

	String();
	String(const char* CharArray);
	String(const String& Other);

	~String();

protected:

	String(char* CharArray);

	static const int CharacterCaseOffset;
	static char* GetNoneString();

	static int CalculateCharArrayLength(const char* CharArray);
	static char* CopyCharArray(const char* OriginalArray);
	static char* CopyCharArray(const char* OriginalArray, int CopyLength);

private:

	char* CharArray;

public:

	int GetLength() const;
	const char* GetCharArray();

	static String FromInt(int Number);

	String GetSubString(int Start, int End);
	String ToUpperCase();
	String ToLowerCase();
	String Replace(const char& CharToReplace, const char& Replacement);
	String ReplaceAll(const char& CharToReplace, const char& Replacement);
	String Reverse();

	int Find(const char& Char);

	std::vector<String> Split(const char& Separator);

	bool StartsWith(const String& Start);

	String operator+(const String& Other);
	String& operator=(const String& Other);
	String operator*(const int& Other);
	const char& operator[](int Index);

	friend std::ostream& operator<<(std::ostream& Output, const String& Other);
	friend std::istream& operator>>(std::istream& Input, String& Other);

	friend bool operator==(const String& First, const String& Second);
	friend bool operator!=(const String& First, const String& Second);
};

