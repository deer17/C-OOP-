#include<iostream>

using namespace std;


int main()
{
	/*
	
  ДЗ 1:
		1. В программе должно быть три опции
		2. Для хранения этих опций используйте переменную типа uint8_t
		3. Реализуйте возможность включать/отключать опции на основе ввода пользователя
		4. Реализуйте возможность распечатать состояние опций
	*/
	const int EXIT_OPTION = 0;
	const int TV_OPTION = 1;
	const int RADIO_OPTION = 2;
	const int COMPUTER_OPTION = 3;

	const int ON = 1;
	const int OFF = 2;
	const int ComeBack = 3;

	uint8_t fullOption = 0;			// 00000000

	const uint8_t TV = 1;   		// 00000001  
	const uint8_t RADIO = 2;		// 00000010  
	const uint8_t COMPUTER = 4;	    // 00000100 


	int choice;

	do
	{
		cout << "1. TV\t\t  -\t";
		if (TV == (fullOption & TV)) {
			cout << "Turn on\n";
		}
		else {
			cout << "Turn off\n";
		}

		cout << "2. Radio\t  -\t";
		if (RADIO == (fullOption & RADIO)) {
			cout << "Turn on\n";
		}
		else {
			cout << "Turn off\n";
		}

		cout << "3. Computer\t  -\t";
		if (COMPUTER == (fullOption & COMPUTER)) {
			cout << "Turn on\n";
		}
		else {
			cout << "Turn off\n";
		}


		cout << "Choose your variant \n";
		cout << "0. Exit\n";
		cout << "1. TV (Turn on/Turn off)\n";
		cout << "2. Radio (Turn on/Turn off)\n";
		cout << "3. Computer (Turn on/Turn off)\n";
		

		
		cin >> choice;
		system("cls");

		if (choice == EXIT_OPTION)
		{
			cout << "You have left the program\n";
			break;
		}
		else if (choice == TV)
		{
			do
			{
				cout << "\nTV : \n1 - on\n2 - off\n3 -  back\n\n";
				cin >> choice;
				system("cls");
				if (choice == ON) {
					if (TV == (fullOption & TV)) {
						cout << "You can't turn on TV because it is already on\n";
					}
					else {
						fullOption |= TV;
						cout << "You turned on the TV\n";
					}
				}
				else if (choice == OFF)
				{
					if (TV == (fullOption & TV)) {
						cout << "You turned off the TV\n";
						fullOption &= ~TV;
					}
					else {
						cout << "You cann't turn off TV because it is already turned off\n";
					}
				}
				else if (choice == ComeBack)
				{
					cout << "You came back\n";
					break;
					system("cls");
				}
				else {
					cout << "Wrong choice , try again \n";
				}
			} while (true);
		}
		else if (choice == RADIO_OPTION)
		{
			do
			{
				cout << "\nRadio : \n1 - on\n2 - off\n3 -  back\n\n";
				cin >> choice;
				system("cls");
				if (choice == ON) {
					if (RADIO == (fullOption & RADIO)) {
						cout << "You cannot turn on the radio because it is already ON\n";
					}
					else {
						fullOption |= RADIO;
						cout << "You turned on the radio\n";
					}
				}
				else if (choice == OFF)
				{
					if (RADIO != (fullOption & RADIO)) {
						cout << "You cannot turn off the radio because it is already turned OFF\n";
					}
					else {
						fullOption &= ~RADIO;
						cout << "You turned off the radio\n";
					}
				}
				else if (choice == ComeBack)
				{
					cout << "You came back\n";
					break;
					system("cls");
				}
				else {
					cout << "Wrong choice , try again \n";
				}
			} while (true);
		}
		else if (choice == COMPUTER_OPTION)
		{
			do
			{
				cout << "\nComputer : \n1 - on\n2 - off\n3 -  back\n\n";
				cin >> choice;
				system("cls");
				if (choice == ON) {
					if (COMPUTER == (fullOption & COMPUTER)) {
						cout << "You can't turn on the computer because it is already turned on\n";
					}
					else {
						fullOption |= COMPUTER;
						cout << "You turned on the computer\n";
					}
				}
				else if (choice == OFF)
				{
					if (COMPUTER == (fullOption & COMPUTER)) {
						cout << "You turned off the computer\n";
						fullOption &= ~COMPUTER;
					}
					else {
						cout << "You can't turn off the computer because it is already turned off\n";
					}
				}
				else if (choice == ComeBack)
				{
					cout << "You came back\n";
					break;
					system("cls");
				}
				else {
					cout << "Wrong choice , try again \n";
				}
			} while (true);

		}
		else {
			cout << "Wrong choice , try again \n";
		}

	} while (true);
}

/*
	ДЗ 2:
		1. Создайте переменную типа uint8_t и присвойте ей некоторое значение (например 1)
		2. Напишите функцию, которая печатает биты переменной типа uint8_t
		Пример:
		uint8_t n = 1; // 00000001
		f(n); // печатает 00000001
void int2bin(uint8_t number)
{
	int a = 8;
	for (int i = 0; i < a; i++)
		if (number & (1 << (a - i - 1))) {
			cout << '1';
		}
		else {
			cout << '0';
		}
}

int main() {
	uint8_t b = 8;
	int2bin(b);
}
*/
