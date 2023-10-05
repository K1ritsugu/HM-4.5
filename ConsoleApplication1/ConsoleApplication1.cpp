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
	int j = 0;
	string a = "";
	string str;
	setlocale(0, "");
	cout << "Введите римское число:" << endl;
	cin >> str;
	number = 0;
	if (str.find("IL") == -1 and str.find("IC") == -1 and str.find("ID") == -1 and str.find("IM") == -1 and str.find("XD") == -1 and str.find("XM") == -1)
	{
		for (int i = str.length() - 1; i > 0; i--)
		{
			if (Rome(str[i - 1]) >= Rome(str[i]) and flag == 0)
			{
				number += Rome(str[i]);
			}
			else if (flag == 0)
			{
				flag = 1;
				number += Rome(str[i]);
			}
			else if (flag == 1)
			{
				number -= Rome(str[i]);
				a += str[i];
			}
		}
		if (flag == 0)
		{
			number += Rome(str[0]);
		}
		else
		{
			number -= Rome(str[0]);
			a = str[0];
		}
		int flag1 = 0;
		for (int m = 0; m < a.length(); m++)
		{
			if (count(str.begin(), str.end(), a[m]) > 1)
			{
				flag1 = 1;
				break;
			}
		}
		if (flag1 == 0 and str.find("IIII") == -1 and str.find("VVVV") == -1 and str.find("XXXX") == -1 and str.find("LLLL") == -1 and str.find("MMMM") == -1 and str.find("DDDD") == -1 and str.find("CCCC") == -1)
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