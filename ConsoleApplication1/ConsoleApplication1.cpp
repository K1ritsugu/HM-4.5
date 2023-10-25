#include <iostream>
#include <string>
int m, i, c, coun, start, str1, h;
char str;
using namespace std;
int generator(int start, int str1) {
	switch (str1) {
	case 1:
		m = 37, i = 3, c = 64;
		return (m * start + i) % c;
	case 2:
		m = 25173, i = 13849, c = 65537;
		return (m * start + i) % c;
	}
}
int main()
{
	setlocale(0, "");
	cout << "Выберите начальное число" << endl;
	cin >> start;
	while (true) {
		cout << "Сгенерировать следующее число? Y/N" << endl;
		cin >> str;
		if (str == 'N') {
			return 0;
		}
		cout << "Выберите вариант генерации 1/2" << endl;
		cin >> str1;
		h = generator(start, str1);
		cout << h << endl;
		start = h;
	}
}