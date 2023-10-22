#include <iostream>
#include <string>
char x;
int number, flag = 0;
using namespace std;
int Rome(char x)
{
	switch (x)
	{
	case 'I':
		return 1;
		break;
	case 'V':
		return 5;
		break;
	case 'X':
		return 10;
		break;
	case 'L':
		return 50;
		break;
	case 'C':
		return 100;
		break;
	case 'D':
		return 500;
		break;
	case 'M':
		return 1000;
		break;
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
	if (str.find("IL") == -1 and str.find("IC") == -1 and str.find("ID") == -1 and str.find("IM") == -1 and str.find("XD") == -1 and str.find("XM") == -1)
	{
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