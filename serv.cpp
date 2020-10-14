// server.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std;

class Patient {
private:
	string lastname;
	int weight, height;
public:
	Patient(string lastname0 = " ", int weight0 = 0, int height0 = 0) {
		lastname = lastname0;
		weight = weight0;
		height = height0;
	}
	void setLastname(string lastname0) {
		lastname = lastname0;
	}
	void setWeight(int weight0) {
		weight = weight0;
	}
	void setHeight(int height0) {
		height = height0;
	}
	string getLastname() {
		return lastname;
	}
	int getWeight() {
		return weight;
	}
	int getHeight() {
		return height;
	}
	string normOfDevel() {
		if (height - weight >= 100 && height - weight <= 115) {
			return "normal";
		}
		else if (height - weight < 100) {
			return "excess";
		}
		else {
			return "lack";
		}
	}
};

void main() {
	int prev = 0;
	while (1) {
		int k = 0;
		ifstream f("C:/Users/Dmitri/source/repos/client/client/message.txt");
		string s;
		while (getline(f, s)) {
			k++;
		}
		vector <Patient> patients;
		f.close();
		if (k > prev) {
			ifstream h("C:/Users/Dmitri/source/repos/client/client/message.txt");
			while (!h.eof()) {
				string lastname;
				int weight, height;
				h >> lastname >> weight >> height;
				Patient patient(lastname, weight, height);
				patients.push_back(patient);
			}
			h.close();
			ofstream g("output.txt");
			for (int i = 0; i < patients.size() - 1; ++i) {
				g << patients[i].getLastname() << " " << patients[i].normOfDevel() << "\n";
			}
			g.close();
			prev = k;
		}
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
