#include <iostream>
#include <string>
char x;
int number;
using namespace std;
int Rome(char x)
{
	switch (x)
	{
	case 'I':
		return 1;
	case 'V':
		return 5;
	case 'X':
		return 10;
	case 'L':
		return 50;
		break;
	case 'C':
		return 100;
	case 'D':
		return 500;
	case 'M':
		return 1000;
	}
	return 0;
}
int main()
{
	string str;
	setlocale(0, "");
	cout << "Введите римское число:" << endl;
	cin >> str;
	number = 0;
	int h, base;
	for (int i = 0; i < str.length() - 1; i++)
	{
		if (Rome(str[i]) >= Rome(str[i + 1]))
		{
			number += Rome(str[i]);
		}
		else
		{
			number -= Rome(str[i]);
			if (str.length() >= i + 2) {
				h = i + 2;
				base = Rome(str[i + 1]);
				for (int j = h; j < str.length(); j++) {
					if (Rome(str[j]) <= base) {
						cout << "Число не существует";
						return 0;
					}
				}
			}
		}
	}
	number += Rome(str[str.length() - 1]);
	if (str.length() >= 3) {
		for (int i = 0; i < str.length() - 2; i+=3) 
		{
			if ((Rome(str[i]) < Rome(str[i + 2])) && (Rome(str[i+1]) < Rome(str[i + 2]))){
				cout << "Число не существует";
				return 0;
			}
		}
	}
	if (str.length() >= 4) {
		for (int i = 1; i < str.length() - 2; i+=3)
		{
			if ((Rome(str[i]) < Rome(str[i + 2])) && (Rome(str[i + 1]) < Rome(str[i + 2]))) {
				cout << "Число не существует";
				return 0;
			}
		}
	}
	if (str.length() >= 5) {
		for (int i = 2; i < str.length() - 2; i+=3)
		{
			if ((Rome(str[i]) < Rome(str[i + 2])) && (Rome(str[i + 1]) < Rome(str[i + 2]))) {
				cout << "Число не существует";
				return 0;
			}
		}
	}
	if (str.find("VX") == -1 && str.find("VL") == -1 && str.find("IL") == -1 && str.find("LC") == -1 && str.find("IC") == -1\
		&& str.find("VC") == -1 && str.find("ID") == -1 && str.find("VD") == -1 && str.find("XD") == -1 && str.find("LD") == -1\
		&& str.find("DM") == -1 && str.find("LM") == -1 && str.find("XM") == -1 && str.find("VM") == -1 && str.find("IM") == -1 && str.find("VV") == -1 && str.find("LL") == -1 && str.find("DD") == -1) {
		if (str.find("IIII") == -1 && str.find("VVVV") == -1 && str.find("XXXX") == -1 && str.find("LLLL") == -1 && str.find("MMMM") == -1 && str.find("DDDD") == -1 && str.find("CCCC") == -1)
		{
			cout << number << endl;
		}
		else
		{
			cout << "Число не существует";
		}
	}
	else
	{
		cout << "Число не существует";
	}	
}