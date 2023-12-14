#include <iostream>

#include "String.h"
#include <string>
using namespace std;

void main() 
{
	String ReprText("This text will help to represent my own string class");

	cout << "Adding" << endl;
	cout << ReprText + "-" + ReprText << endl;
	cout << String("-") * 30 << endl;

	cout << "Case Changing" << endl;
	cout << ReprText.ToLowerCase() << endl << ReprText.ToUpperCase() << endl;
	cout << String("-") * 30 << endl;

	cout << "Split" << endl;
	for (String el : (ReprText * 2).Split(' ')) 
	{
		cout << el << endl;
	}
	cout << String("-") * 30 << endl;

	cout << "Reverse" << endl;
	cout << ReprText.Reverse() << endl;
	cout << String("-") * 30 << endl;

	cout << "SubString" << endl;
	cout << ReprText.GetSubString(0, 3) << " - " << ReprText.GetSubString(10, 20) << endl;
	cout << String("-") * 30 << endl;

	cout << "Replace/Replace All" << endl;
	cout << ReprText.Replace('t', 'a') << endl << ReprText.ReplaceAll(' ', '=') << endl;
	cout << String("-") * 30 << endl;

	cout << "FromInt" << endl;
	for (int i = 5; i < 15; i++) 
	{
		cout << String::FromInt(pow(i, 4)) << " ";
	}
	cout << endl << String("-") * 30 << endl;

	cout << "Find" << endl;
	cout << ReprText.Find('w') << ' ' << ReprText.Find('a') << endl;
	cout << String("-") * 30 << endl;

	cout << "Compare" << endl;
	cout << (ReprText == ReprText) << " " << (ReprText != ReprText) << " " << (ReprText.Reverse() == ReprText) << endl;
	cout << String("-") * 30 << endl;

	cout << "Starts with" << endl;
	cout << ReprText.StartsWith("This") << endl;
	cout << String("-") * 30 << endl;

	cout << "Iterate" << endl;
	for (int i = 0; true; i++)
	{
		try 
		{
			cout << ReprText[i] << " - " << i << endl;
		}
		catch (const exception& ex)
		{
			cout << ex.what() << endl;
			break;
		}
	}
	cout << String("-") * 30 << endl;
}