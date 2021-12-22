#include<iostream>
#include<string.h>

using namespace std;


/*

	Задание 1: Заметки
- Добавление заметки (название, текст)
- Удаление заметки
- Редактирование заметки (возможность менять название и текст)
- Вывод всего списка заметок
- Просмотр информации по каждой заметке в отдельности
- Поиск заметок по названию
- Поисковой запрос вида Title* должен находить заметки с заголовками вида Title и Title1

*/


struct Note
{
	char noteName[20];
	char noteText[100];
};


void printAll(const Note* arr, const int noteQuant)
{
	for (int i = 0; i < noteQuant; i++)
	{
		cout << "\n\n";

		cout << i << '\t' << arr[i].noteName << "\t\t\t";

		cout << arr[i].noteText << '\n';
	}

}

void printSpecificNote(const Note* arr, const int noteNumber)
{	
		cout << "\n\n";

		cout << noteNumber << '\t' << arr[noteNumber].noteName << "\t\t\t";

		cout << arr[noteNumber].noteText << '\n';

}


void addNote(Note*& arr, int& noteQuant) {

	Note* tmp = new Note[noteQuant + 1];

	for (int i = 0; i < noteQuant; i++)
	{
		tmp[i] = arr[i];
	}
	

	++noteQuant;
	delete[] arr;
	arr = tmp;
}

void deleteNote(Note*& arr, int& noteQuant, const int deleteNum) {

	Note* tmp = new Note[noteQuant - 1];

	for (size_t i = 0, b = 0; i < noteQuant; i++) {

		if (i != deleteNum)
		{
			tmp[b] = arr[i];
			b++;
		}
	}
	noteQuant--;
	delete[] arr;
	arr = tmp;
}


void editeNote(Note*& arr, const int editeNote)
{
	bool note = true;
	for (size_t i = editeNote; i < editeNote + 1; i++)
	{

		cout << "\nEnter name of note\n";
		cin >> arr[editeNote].noteName;

		cout << "Enter text of note\n";
		cin >> arr[editeNote].noteText;
		note = false;
	}

	if (note)
		cout << "\nYou haven't note\n";
}



void srchbyName(const Note* arr, const int size, const char* words) {
	int wordSize = strlen(words);
	int arrSize;
	bool act, list = true;

	for (size_t i = 0; i < size; i++) {
		act = true;

		
			for (size_t j = 0; j < wordSize - 1; j++)
			{
				if (arr[i].noteName[j] != words[j])
				{
					act = false;
				}
			}
			if (act && words[wordSize - 1] == '*')
			{
				list = false;
				cout << i << '\t' << arr[i].noteName << "\t\t\t";
				cout << arr[i].noteText << endl;
			}
		}
	
	if (list) {
		cout << "-\t-\t\t\t-\n\n";
	}
}



enum {
	Exit,
	Add,
	DeleteNote,
	Edit,
	PrintAll,
	PrintSpecific,
	Search
};

int main()
{
	int noteQuant,
		choice,
		deleteNum,
		editNote,
		numNote;

	const int ComeBack = -1;
	const int zero = 0;
	char note[20];


	do
	{
		cout << "Enter quantity Notes\n";
		cin >> noteQuant;
		if (noteQuant < zero)
		{
			cout << "The number of notes must be greater than or equal to zero\n\n";;
		}
		else {
			break;
		}
	} while (true);

	Note* arr = new Note[noteQuant];

	for (size_t i = 0; i < noteQuant; i++)
	{
		cout << "Enter name of note\n";
		cin >> arr[i].noteName;

		cout << "Enter text of note\n";
		cin >> arr[i].noteText;
	}


	do
	{
		cout << "Choose your variant \n";
		cout << "0. Exit program\n";
		cout << "1. Add note\n";
		cout << "2. Delete note \n";
		cout << "3. Edit note\n";
		cout << "4. Print all notes \n";
		cout << "5. Print specific note \n";
		cout << "6. Search note with name \n";

		cin >> choice;

		if (choice == Exit)
		{
			cout << "You left the program\n";
			break;
		}
		else if (choice == Add)
		{
			cout << "\nAdd new note\n\n";
			addNote(arr, noteQuant);
			cout << "\nEnter name of note\n";
			cin >> arr[noteQuant-1].noteName;

			cout << "Enter text of note\n";
			cin >> arr[noteQuant-1].noteText;
		}
		else if (choice == DeleteNote)
		{
			do
			{
				cout << "Choose the number of note (N) for delete\n";
				cin >> deleteNum;

				if (deleteNum < noteQuant)
				{
					cout << "\nYou deleted N " << deleteNum << " Name \t" << arr[deleteNum].noteName << endl;
					deleteNote(arr, noteQuant, deleteNum);
					break;
				}
				else if (noteQuant == zero) {
					cout << "You haven't notes\n";
					break;
				}
				else {
					cout << "Wrong selection, please try again.\n";
				}
			} while (true);
		}
		else if (choice == Edit)
		{
			do
			{
				cout << "Come back   -1\nSelect number of note (N) for edition\n";
				cin >> editNote;

				if (editNote == ComeBack) {
					cout << "You come back\n";
					break;
				}
				else if (editNote < noteQuant && editNote != ComeBack)
				{
					cout << "You edited N " << editNote << "\tname\t\t\t" << arr[editNote].noteName << '\n';
					editeNote(arr, editNote);
					break;
				}
				else if (noteQuant == zero) {
					cout << "You haven't notes\n";
					break;
				}
				else {
					cout << "Wrong selection,please try again.\n";
				}
			} while (true);
		}
		else if (choice == PrintAll)
		{
			cout << "\n\nPrint All List\n\nN\tName\t\t\tText\n\n";
			printAll(arr, noteQuant);
			if (noteQuant == zero)
			{
				cout << "-\t-\t\t\t-\n\nYou haven't note\n\n";
			}
		}
		else if (choice == PrintSpecific)
		{
			do
			{
				cout << "Come back   -1\nChoose number of note (N) \n";
				cin >> numNote;
				if (numNote < noteQuant && numNote != ComeBack)
				{
					cout << "Print All List\n\nN\tName\t\t\tText\n\n";
					printSpecificNote(arr, numNote);
					break;
				}
				else if (noteQuant == zero) {
					cout << "You haven't note\n";
					break;
				}
				else if (numNote == ComeBack)
				{
					cout << "You come back\n";
					break;
				}
				else {
					cout << "Wrong selection, try again.\n";
				}
			} while (true);
		}
		else if (choice == Search)
		{
			do
			{
				cout << "\n\nSearch for notes by name\n";
				cin >> note;
				cout << "\nN\tName\t\t\tText\n\n";
				srchbyName(arr, noteQuant, note);
				break;
			} while (true);
		}
		else {
			cout << "\nWrong selection, try again.\n";
		}
	} while (true);

	delete[] arr;
}