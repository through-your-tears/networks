#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void main() {
	ofstream f("transport.txt");
	string s;
	while (getline(cin, s)) { //фамилия имя рост вес
		string str = " ";
		int i = 0;
		char previous = ' ';
		for (char a : s) {
			if (a != ' ') {
				str += a;
			}
			else {
				f << str << ' ';
				str = " ";
			}
			previous = a;
		}
		f << s;
	}
}
