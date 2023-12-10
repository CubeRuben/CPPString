#include <iostream>

#include "String.h"
#include <string>
using namespace std;

void main() 
{
	String Text("Water of Baikal!");

	String waterCut = Text.GetSubString(0, 5);
	cout << waterCut << endl << waterCut.GetLength() << endl;

	String notProperCut = Text.GetSubString(5, 0);
	cout << notProperCut << endl << notProperCut.GetLength() << endl;

	cout << Text.ToLowerCase() << ' ' << Text.ToUpperCase() << endl;
}