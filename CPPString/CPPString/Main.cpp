#include <iostream>

#include "String.h"
#include <string>
using namespace std;

void main() 
{
	String Text("Water of Baikal!");
	cout << Text << endl << Text.GetLength() << endl;

	String waterCut = Text.GetSubString(0, 4);
	cout << waterCut << endl << waterCut.GetLength() << endl;

	String notProperCut = Text.GetSubString(5, 0);
	cout << notProperCut << endl << notProperCut.GetLength() << endl;

	cout << Text.ToLowerCase() << ' ' << Text.ToUpperCase() << ' ' << Text.ToUpperCase() << ' ' << Text << endl;

	cout << Text.ToLowerCase() << endl;
	cout << Text.ToUpperCase() << endl;

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
}