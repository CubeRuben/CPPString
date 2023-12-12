#include <iostream>

#include "String.h"
#include <string>
using namespace std;

void main() 
{


	String Text("Water of Baikal!");
	cout << Text << ' ' << Text.GetLength() << endl;

	String waterCut = Text.GetSubString(0, 4);
	cout << waterCut << ' ' << waterCut.GetLength() << endl;

	String notProperCut = Text.GetSubString(5, 0);
	cout << notProperCut << ' ' << notProperCut.GetLength() << endl;

	cout << Text.ToUpperCase() << ' ' << Text.ToLowerCase() << ' ' << Text.ToUpperCase() << ' ' << Text << endl;

	cout << Text.Replace('a', 'i') << endl;

	String reverseTest = Text.GetSubString(0, 4);
	cout << reverseTest << ' ' << reverseTest.Reverse() << endl;
	reverseTest = Text.GetSubString(9, 14);
	cout << reverseTest << ' ' << reverseTest.Reverse() << endl;

	for (int i = 0; true; i++) 
	{
		try {
			cout << Text[i] << " - " << i << endl;
		}
		catch (const exception& ex)
		{
			cout << ex.what() << endl;
			break;
		}
	}

	String Word1("Some"), Space(" "), Word2("text");
	cout << Word1 + Space + Word2 << endl;

	cout << String::FromInt(5123) << " + " << String::FromInt(14124) << endl;

	String number = String::FromInt(123);
	cout << (number + number.GetSubString(0, 1).Reverse()) * 10 << endl;

	String compare1("Yes"), compare2("No"), compare3("oN");
	cout << (compare1 == compare2) << (compare2 != compare3) << (compare2 == compare3.Reverse()) << endl;

	String anotherText("Yay!");
	cout << anotherText.StartsWith("Yay!") << anotherText.StartsWith("No") << anotherText.Reverse().StartsWith("!ya") << endl;
	cout << anotherText.StartsWith("Yay!  ") << endl;

	cout << Text.Find('B') << endl;

	for (String el : Text.Split(' ')) 
	{
		cout << el << endl;
	}
}