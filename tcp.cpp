// tcp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>  // CLIENT TCP
#define _WINSOCK_DEPRECATED_NO_WARNINGS  
// подавление предупреждений библиотеки winsock2
#include <winsock2.h> 
#include <string>
#include <windows.h>
#pragma comment (lib, "Ws2_32.lib")
#pragma warning(disable: 4996)  // подавление предупреждения 4996 
using namespace std;
#define SRV_HOST "localhost"  
#define SRV_PORT 1234 
#define CLNT_PORT 1235  
#define BUF_SIZE 64
struct Patient {
    int weight;
    int height;
    char mst[256];
};
struct Answer {
    int mark;
    char buf[256];
};
int main() {
    setlocale(LC_ALL, "Russian");
    char buff[1024];
    if (WSAStartup(0x0202, (WSADATA*)&buff[0])) {
        cout << "Error WSAStartup \n" << WSAGetLastError();  // Ошибка!
        return -1;
    }
    SOCKET s;
    int from_len;
    char buf[BUF_SIZE] = { 0 };
    hostent* hp;
    sockaddr_in clnt_sin, srv_sin;
    Patient client;
    client.height = 0;
    client.weight = 0;
    Answer medcentr;
    medcentr.mark = 0;
    cout << "Укажите свой рост и вес для проверки\n";
    cin >> client.height >> client.weight;
    cin.getline(client.mst, 256);
    s = socket(AF_INET, SOCK_STREAM, 0); //создание сокета
    clnt_sin.sin_family = AF_INET; // тип адреса (TCP/IP)
    clnt_sin.sin_addr.s_addr = 0; // порт
    clnt_sin.sin_port = htons(CLNT_PORT); // перевод номера порта из обычного в TCP/IP представление
    bind(s, (sockaddr*)&clnt_sin, sizeof(clnt_sin));
    hp = gethostbyname(SRV_HOST);
    srv_sin.sin_port = htons(SRV_PORT);
    srv_sin.sin_family = AF_INET;
    ((unsigned long*)&srv_sin.sin_addr)[0] =
        ((unsigned long**)hp->h_addr_list)[0][0];
    connect(s, (sockaddr*)&srv_sin, sizeof(srv_sin)); //установление связи
    send(s, (char*)&client, sizeof(client), 0);  // отправка данных
    recv(s, (char*)&medcentr, sizeof(medcentr), 0); // приём данных
    if (medcentr.mark == 0) {
        cout << "Недовес";
    }
    else if (medcentr.mark == 1) {
        cout << "Вес в норме";
    }
    else {
        cout << "Перевес";
    }
    cout << "Для завершения работа напишите 'Bye'";
    do {
        from_len = recv(s, (char*)&medcentr.buf, BUF_SIZE, 0);
        cout << "Разработчик: ";
        cout << medcentr.buf << endl;
        cout << "Вы: ";
        cin.getline(client.mst, BUF_SIZE);
        send(s, (char*)&client.mst[0], BUF_SIZE, 0);
    } while (strcmp(client.mst, "Bye"));
    cout << "exit to infinity" << endl;
    cin.get();
    closesocket(s);
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
