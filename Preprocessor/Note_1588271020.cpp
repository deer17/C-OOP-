#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

/*
ДОМАШНЕЕ ЗАДАНИЕ:
		- Добавление заметки (название, текст)
		- Удаление заметки
		- Редактирование заметки (возможность менять название и текст)
		- Вывод всего списка заметок
		- Просмотр информации по каждой заметке в отдельности
		- Поиск заметок по названию
*/



struct Note {
	char name[10];
	char information[200];
};
void printList(const Note* arr, const int quantity) {

	for (int i = 0; i < quantity; i++)
	{
		cout << "\n\n";

		cout << i << '\t' << arr[i].name<< "\t\t\t";

		cout << arr[i].information << '\n';

	}
	cout << "\n\n";
}

void printNote(const Note* arr, const int noteNumber)
{
	for (int i = noteNumber; i < noteNumber + 1; i++)
	{
		cout << "\n\n";

		cout << i << '\t' << arr[i].name << "\t\t\t";

		cout << arr[i].information << '\n';
	}
	cout << "\n\n";
}

void Add(Note*& arr, int& quantity) {

	Note* tmp = new Note[quantity + 1];

	for (int i = 0; i < quantity; i++)
	{
		tmp[i] = arr[i];
	}
	cout << "\nEnter name of note \n";
	cin >> tmp[quantity].name;

	cout << "Enter note text\n";
	cin >> tmp[quantity].information;

	++quantity;
	delete[] arr;
	arr = tmp;
}



void Remove(Note*& arr, int& quantity, const int deleteNumber) {

	Note* tmp = new Note[quantity - 1];

	for (size_t i = 0, j = 0; i < quantity; i++) {

		if (i != deleteNumber)
		{
			tmp[j] = arr[i];
			j++;
		}
	}
	quantity--;
	delete[] arr;
	arr = tmp;
}



void editeNoteFunc(Note*& arr, const int editeNote)
{
	for (size_t i = editeNote; i < editeNote + 1; i++)
	{
		cout << "\nEnter note name\n";
		cin >> arr[editeNote].name;

		cout << "Enter note text\n";
		cin >> arr[editeNote].information;
	}
}



void serachNote(const Note* arr, const int quantity, const char* name)
{
	bool note = true;

	for (size_t i = 0; i < quantity; i++)
		if (strcmp(arr[i].name, name) == 0)
		{
			cout << "\n\n";
			cout << i << '\t' << arr[i].name << "\t\t\t";
			cout << arr[i].information << '\n';
			note = false;
		}

	if (note)
		cout << "\nThere is no such note \n";
}


int main()
{
	const int exit = 0;
	const int add = 1;
	const int remove = 2;
	const int edit = 3;
	const int information = 4;
	const int print = 5;
	const int search = 6;


	int quantity, action;

	cout << "Enter quantity Notes\n";
	cin >> quantity;

	Note* arr = new Note[quantity];

	for (size_t i = 0; i < quantity; i++)
	{
		cout << "Enter note name\n";
		cin >> arr[i].name;

		cout << "Enter note text\n";
		cin >> arr[i].information;
	}


	do
	{
	
		

		cout << "Choose your variant \n";
		cout << "0. Exit \n";
		cout << "1. Add \n";
		cout << "2. remove \n";
		cout << "3. Edit \n";
		cout << "4. Print information \n";
		cout << "5. Print note \n";
		cout << "6. Search \n";

		cin >> action;

		if (action == exit)
		{
			cout << "You have left the program\n";
			break;

		}
		else if (action == add)
		{
			cout << "Add new note\n\n";
			Add(arr, quantity);
		}
		else if (action == remove)
		{
			int deleteNumber;
			do
			{
				cout << "Choose note number (N) for delete\n";
				cin >> deleteNumber;

				if (deleteNumber < quantity)
				{
					cout << "\nYou delete N " << deleteNumber << " Name \t" << arr[deleteNumber].name << endl;
					Remove(arr, quantity, deleteNumber);
					break;
				}
				else if (quantity == 0) {
					cout << "You have no notes\n";
					break;
				}
				else {
					cout << "Wrong selection, try again.\n";
				}

			} while (true);
		}
		else if (action == edit)
		{
			int editNote;
			do
			{
				cout << "Select note num (N) for edition\n";
				cin >> editNote;
				if (editNote < quantity)
				{
					cout << "You edit N " << editNote << "\tname\t\t\t" << arr[editNote].name << endl;
					editeNoteFunc(arr, editNote);
					break;
				}
				else if (quantity == 0) {
					cout << "You have no notes\n";
					break;
				}
				else {
					cout << "Wrong selection, try again.\n";
				}
			} while (true);
		}
		else if (action == information)
		{
			cout << "\n\nPrint All List\n\nN\tName\t\t\tText\n\n";
			printList(arr, quantity);
		}
		else if (action == print)
		{
			int numNote;
			do
			{
				cout << "Choose note number (#) \n";
				cin >> numNote;
				if (numNote < quantity)
				{
					cout << "Print All List\n\n#\tName\t\t\tText\n\n";
					printNote(arr, numNote);
					break;
				}
				else if (quantity == 0) {
					cout << "You have no notes\n";
					break;
				}
				else {
					cout << "Wrong selection, try again.\n";
				}
			} while (true);

		}
		else if (action == search)
		{
			char note[20];
			do
			{
				cout << "\nCome back  -1\nSearch for notes by name\n";
				cin >> note;
				serachNote(arr, quantity, note);
				break;
			} while (true);
		}
		else {

		}

	} while (true);

}