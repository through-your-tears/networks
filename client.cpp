// client0.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

void main() {
	const unsigned short int id = 0;
	string s;
	int prev = 0;
	while (1) {
		int k = 0;
		ifstream f("C:/Users/Dmitriy/source/repos/server0/server0/output0.txt");
		
		while (getline(f, s))
		{
			k++;
		}
		f.close();
		if (k > prev) {
			ifstream h("C:/Users/Dmitriy/source/repos/server0/server0/output0.txt");
			while (getline(h, s))
			{
				cout << s << "\n";
			}
			h.close();
		}
		
		ofstream g("message.txt", ios_base::app);
		cout << "lastname, weight, height" << "\n";
		getline(cin, s);
		while (s != " ") {
			g << s << "\n";
			getline(cin, s);
		}
		g.close();
		prev = k;
		Sleep(2000);
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
