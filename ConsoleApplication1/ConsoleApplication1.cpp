#include <iostream>
#include <string>
int m, c, coun, start, str1, h;
using namespace std;
int swap(char s) {
	m = int(s) - 48;
	if (m < 10) {
		return m;
	}
	else {
		return m - 7;
	}

}
int main()
{
	string str;
	setlocale(0, "");
	cout << "Введите число в начальном основании" << endl;
	cin >> str;
	cout << "Введите начальное основание" << endl;
	cin >> h;
	cout << "Введите итоговое основание" << endl;
	cin >> c;
	if (h < 2 || h > 16 || c < 2 || c > 16) {
		cout << "Ошибка";
		return 0;
	}
	int itog_10 = 0;
	int j = 0;

	for (int i = str.length() - 1; i > -1; i--) {
		if (swap(str[i]) < 0 || swap(str[i]) > 15) {
			cout << "Ошибка";
			return 0;
		}
		itog_10 += swap(str[i]) * pow(h, j);
		j += 1;
	}
	string itog = "";
	while (itog_10 > 0) {
		itog = to_string(itog_10 % c) + itog;
		itog_10 = itog_10 / c;
	}
	cout << itog;
}