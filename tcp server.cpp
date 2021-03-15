// tcp server.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

// SERVER TCP 
#include <iostream>  
#include <winsock2.h> 
#include <windows.h> 
#include <string> 
#pragma comment (lib, "Ws2_32.lib")  
using namespace std;
#define SRV_PORT 1234  
#define BUF_SIZE 64  
const string QUEST = "Who are you?\n";
struct Patient {
	int weight;
	int height;
	char buf[256];
};
struct Answer {
	int mark;
	char buf[256];
};
int main() {
	setlocale(LC_ALL, "Russian");
	char buff[1024];
	if (WSAStartup(0x0202, (WSADATA*)&buff[0]))
	{
		cout << "Error WSAStartup \n" << WSAGetLastError();   // Ошибка!
		return -1;
	}
	Patient client;
	Answer medcentr;
	SOCKET s, s_new;
	int from_len;
	char buf[BUF_SIZE] = { 0 };
	sockaddr_in sin, from_sin;
	s = socket(AF_INET, SOCK_STREAM, 0);
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = 0;
	sin.sin_port = htons(SRV_PORT);
	bind(s, (sockaddr*)&sin, sizeof(sin));
	char msg[BUF_SIZE];
	listen(s, 3);
	while (1) {
		from_len = sizeof(from_sin);
		s_new = accept(s, (sockaddr*)&from_sin, &from_len);
		cout << "Подключился новый пользователь!" << endl;
		from_len = recv(s_new, (char*)&client, sizeof(client), 0);
		double avg = client.weight / ((pow(client.height, 2)) / 10000);
		if (avg < 18.5)
			medcentr.mark = 0;
		else if (avg > 24.9) 
			medcentr.mark = 2;
		else
			medcentr.mark = 1;
		send(s_new, (char*)&medcentr, sizeof(medcentr), 0); // функция посылки данных
		strncpy_s(msg, QUEST.c_str(), BUF_SIZE);
		while (1) {
			send(s_new, (char*)&msg[0], BUF_SIZE, 0);
			from_len = recv(s_new, (char*)&client.buf, BUF_SIZE, 0);
			client.buf[from_len] = 0;
			strncpy_s(medcentr.buf, client.buf, BUF_SIZE);
			cout << "Пользователь: ";
			cout << medcentr.buf << endl;
			if (strcmp(medcentr.buf, "Bye") == 0) break;
			cout << "Вы: ";
			cin.getline(msg, BUF_SIZE);
		}
		cout << "Пользователь отключился!";
		closesocket(s_new);
	}
	return 0;
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
