#include<iostream>
#include<string.h>
#include<cstdio>
#pragma warning (disable: 4996)

using namespace std;

/*
 Задание 1: Контроль доступа
		 - При первом запуске программы пользователь установить логин и пароль
		 - В следующий раз при запуске программы должен требоваться ввод логина и пароля,
		 - которые были выбраны при первом запуске программы
		 - На все действия пользователя должна быть ответная реакция
		 struct Person

*/
struct Data {
	char login[20];
	int password;
};
int main()
{
	
	Data dWrite;
	cout << "Enter login \n";
	cin >> dWrite.login;
	cout << "Enter password \n";
	cin >> dWrite.password;
	
	
	FILE* fileWrite = fopen("C:\\Users\\99451\\Desktop\\Ceyran\\Ceyran.txt", "wb");
	if (!fileWrite) {
		perror("Error");
	}
	else {
		cout << "Data saved \n";
		fwrite(&dWrite, sizeof(Data),1 , fileWrite);
		fclose(fileWrite);
	}
	

Data dRead;
	FILE* fileRead = fopen("C:\\Users\\99451\\Desktop\\Ceyran\\Ceyran.txt", "rb");
	if (!fileRead) {
		perror("Error");
	}
	else {
		cout << "Data read\n";
		fread(&dRead, sizeof(Data), 1, fileRead);
		fclose(fileRead);
	}
	
		cout << "login = " << dRead.login << '\n';
		cout << "password = " << dRead.password << '\n';


		Data dCin;
		do
		{
			cout << "Enter login \n";
			cin >> dCin.login;
			cout << "Enter password \n";
			cin >> dCin.password;
			if (dCin.password == dRead.password && strcmp(dCin.login, dRead.login)==0) {
				cout << "You entered into accaunt \n";
				break;
			}
			else {
				cout << "Incorrect data ,please try again\n";

			}
		} while (true);
	
}