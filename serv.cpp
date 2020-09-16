#include <fstream>
#include <list>
#include <string>
#include <cstdlib>

using namespace std;

class Student {
private:
	string name, surname;
	int weight, height;
public:
	int k = 0;
	Student (string name0 = " ", string surname0 = " ", int weight0 = 0, int height0 = 0){
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
	list <Student> students;
	int prev = 0;
	int k = 0;
	ifstream f("transport.txt");
	while (1) {
		string s;
		while (getline(f, s) && k <= prev) {
			k++;
		}
		--k;
		while (getline(f, s)) {
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
							string m(1, a);
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
							string m(1, a);
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
		ofstream g("list_of_students.txt");
		for (auto it = students.begin(); it != students.end(); ++it) {
			//вывод в файл списка
		}
	}

}
