#include <iostream>

#include "String.h"
#include <string>
using namespace std;

void main() 
{
	String Text("Water of Baikal!");
	cout << Text << endl << Text.GetLength() << endl;

	cout << Text.GetSubString(2, 2);

	String waterCut = Text.GetSubString(0, 5);
	cout << waterCut << endl << waterCut.GetLength() << endl;

	String notProperCut = Text.GetSubString(5, 0);
	cout << notProperCut << endl << notProperCut.GetLength() << endl;

	cout << Text.ToLowerCase() << ' ' << Text.ToUpperCase() << endl;
}