// server0.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std;

class Student {
private:
	string name, surname;
	int weight, height;
public:
	int k = 0;
	Student(string name0 = " ", string surname0 = " ", int weight0 = 0, int height0 = 0) {
		name = name0;
		surname = surname0;
		weight = weight0;
		height = height0;
		k++;
	}
	void setName(string name0) {
		name = name0;
	}
	void setSurname(string surname0) {
		surname = surname0;
	}
	void setWeight(int weight0) {
		weight = weight0;
	}
	void setHeight(int height0) {
		height = height0;
	}
	string getName() {
		return name;
	}
	string getSurname() {
		return surname;
	}
	int getWeight() {
		return weight;
	}
	int getHeight() {
		return height;
	}
};

void main() {
	vector <Student> students;
	int prev = 0;
	const unsigned short int id = 0;
	int k = 0;
	while (1) {
		ifstream f("C:/Users/Dmitriy/source/repos/client0/Debug/transport.txt");
		string s;
		while (getline(f, s) && k <= prev) {
			k++;
		}
		--k;
		bool flag = 0;
		while (getline(f, s)) {
			flag = 1;
			int i = 0;
			string str;
			Student st;
			for (char a : s) {

				if (a != ' ') {
					str += a;
				}
				else {
					if (i == 0) {
						st.setSurname(str);
					}
					else if (i == 1) {
						st.setName(str);
					}
					else if (i == 2) {
						int p = pow(10, str.length() - 1);
						int sum = 0;
						for (char a0 : str) {
							string m(1, a0);
							const char* ps = m.c_str();
							sum += atoi(ps) * p;
							p /= 10;
						}
						st.setWeight(sum);
					}
					else {
						int p = pow(10, str.length() - 1);
						int sum = 0;
						for (char a0 : str) {
							string m(1, a0);
							const char* ps = m.c_str();
							sum += atoi(ps) * p;
							p /= 10;
						}
						st.setHeight(sum);
					}
				}
			}
			students.push_back(st);
			prev++;
		}
		f.close();
		ofstream g("C:/Users/Dmitriy/source/repos/client0/Debug", ios_base::app);
		if (flag) {
			g << "Server:" << "\n" << "changes saved " << "\n";
		}
		/*for (auto it = students.begin(); it != students.end(); ++it) {
			Student student = *it;
			g << id << ' ' << student.getSurname << ' ' << student.getName << ' ' << student.getWeight << ' ' << student.setHeight;
		}*/
		g.close();
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
