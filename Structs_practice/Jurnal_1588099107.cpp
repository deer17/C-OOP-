#include<iostream>
#include<string.h>
#include<iomanip>

using namespace std;

/*
		ДОМАШНЕЕ ЗАДАНИЕ:
		1. Написать программу, реализующую журнал академической группы
		с произвольным количеством студентов. Программа должна
		предоставлять возможность добавления студента в группу,
		удаления студента из группы, редактирования данных о студенте,
		вывода информации о студентах каждой группы в консоль.
		2. В программе должно быть реализовано 2 типа структур: Group и Student. Структура
		Group должна содержать в себе название и список студентов (массив структур Student).
		3. Данные студента: Имя и средний балл
	*/


struct Student {
	char student[15];
	int averageBalls;
};



struct Group {
	char group[15];
	int size = 2;
	Student* set = new Student[size];
};



void printGroups(Group** arr, int sizeGroup) {

	for (int i = 0, b = 0; i < sizeGroup; i++, b++) {
		cout << "\n********************\n";
		cout << '\n' << b << ") " << "Group name\t";
		cout << arr[i]->group << endl;

		cout << "\n\n#\tName\t\t\t\Points\n";
		for (int j = 0; j < arr[i]->size; j++)
		{
			cout << j << '\t' << arr[i]->set[j].student << "\t\t\t";
			cout << arr[i]->set[j].averageBalls << '\n';
		}
	}
	cout << "\n********************\n";
}




void printGroup(Group** arr, int groupNum) {

	for (int i = groupNum, c = 0; c < 1; i++, c++) {
		cout << "\n********************\n";
		cout << '\n' << i << ") " << "Group name\t";
		cout << arr[i]->group << endl;

		cout << "\n\n#\tName\t\t\t\Points\n";
		for (int j = 0; j < arr[i]->size; j++)
		{
			cout << j << '\t' << arr[i]->set[j].student << "\t\t\t";
			cout << arr[i]->set[j].averageBalls << '\n';
		}
	}
	cout << "\n********************\n";
}



void addStudent(Group**& arr, int group) {

	for (int i = group, b = 0; b < 1; b++) {
		cout << "Add Student in " << arr[i]->group << " group\n\n";
		for (int j = arr[i]->size; j < (arr[i]->size + 1); j++) {
			cout << "Enter name of student\n";
			cin >> arr[i]->set[j].student;

			cout << "Enter student middle point \n";
			cin >> arr[i]->set[j].averageBalls;
		}
		arr[i]->size++;
	}
}




void deleteStudent(Group**& arr, int quantityGroup, int qroup, int student) {

	cout << "Delete Student in " << arr[qroup]->group << " group\n\n";

	Group** newArr = new Group * [quantityGroup];
	for (int i = 0, b = 0; i < quantityGroup; i++)
	{
		newArr[i] = new Group;
		newArr[i] = arr[i];
		if (i == qroup)
		{
			for (int j = 0, u = 0; j < arr[i]->size; j++)
			{
				if (j != student)
				{
					newArr[i]->set[u] = arr[i]->set[j];
					u++;
				}
			}
			arr[i]->size--;;
		}
	}
	delete[] arr;
	arr = newArr;
}




void studentEditing(Group**& arr, int quantityGroup, int group, int student)
{
	cout << "Edit Student in " << arr[group]->group << " group\n\n";
	for (int i = group, b = 0; b < 1; b++)
	{
		for (int j = student, u = 0; u < 1; u++)
		{
			cout << "Enter name of student\n";
			cin >> arr[i]->set[j].student;

			cout << "Enter student middle point \n";
			cin >> arr[i]->set[j].averageBalls;
		}

	}
}



const int Exit = 0;
const int AddGroup = 1;
const int DeleteSpecificGroup = 2;
const int AddStudent = 3;
const int DeleteSpecificStudent = 4;
const int PrintSpecificGroup = 5;
const int PrintAllGroup = 6;
const int StudentEditing = 7;



int main()
{
	int quantityGroup;
	do
	{
		cout << "Enter quantity of group\n";
		cin >> quantityGroup;

		if (quantityGroup >= 1) {
			break;
		}
		else {
			cout << "\nSize of group must be greater than or equal to 1 \n";
		}

	} while (true);


	Group** arr = new Group * [quantityGroup];

	for (size_t i = 0; i < quantityGroup; i++)
	{
		arr[i] = new Group;

		cout << "Enter name of group\n";
		cin >> arr[i]->group;


		for (size_t j = 0; j < arr[i]->size; j++)
		{
			cout << "Enter Student name\n";
			cin >> arr[i]->set[j].student;

			cout << "Enter Student average points\n";
			cin >> arr[i]->set[j].averageBalls;
		}
	}

	int action;
	do
	{


		cout << "0 - Exit\n1 - Add Group\n2 - Delete Specific Group\n";
		cout << "3 - Add Student\n4 - Delete Specific Student\n5 - Print Specific Group";
		cout << "\n6 - Print All Group\n7 - Student editing\n\n";

		cin >> action;


		if (action == Exit) {
			cout << "You exit the program\n";
			break;
		}
		else if (action == AddGroup) {
			Group** newArr = new Group * [quantityGroup + 1];
			for (int i = 0; i < quantityGroup; i++) {
				newArr[i] = new Group;
				newArr[i] = arr[i];
			}

			for (int i = quantityGroup; i < (quantityGroup + 1); i++) {
				newArr[i] = new Group;
				cout << "Enter name of group\n";
				cin >> newArr[i]->group;

				for (int j = 0; j < newArr[i]->size; j++) {
					cout << "Enter Student name\n";
					cin >> newArr[i]->set[j].student;

					cout << "Enter student middle point \n";
					cin >> newArr[i]->set[j].averageBalls;
				}
			}
			quantityGroup++;
			delete[] arr;

			arr = newArr;
		}
		else if (action == DeleteSpecificGroup) {
			int act;
			do
			{
				cout << "Choose delete number \n";
				cin >> act;
				if (act < quantityGroup) {
					Group** newArr = new Group * [quantityGroup - 1];
					for (int i = 0, b = 0; i < quantityGroup; i++)
					{
						if (act != i) {
							newArr[b] = new Group;
							newArr[b] = arr[i];
							b++;
						}
					}
					quantityGroup--;
					delete[] arr;

					arr = newArr;
					break;
				}
				else {
					cout << "Wrong choice try again\n";
				}
			} while (true);
			cout << "\nThis group  deleted\n";
		}
		else if (action == AddStudent) {
			int act4;
			do
			{
				cout << "Where do you want  add a student ?\n";
				cin >> act4;
				if (act4 < quantityGroup) {
					cout << "You add a student to  " << arr[act4]->group << " group\n\n";
					addStudent(arr, act4);
					cout << "Upload completed successfully\n\n";
					printGroup(arr, act4);
					break;
				}
				else
				{
					cout << "This group doesn't exist, please try again\n\n";
				}
			} while (true);
		}
		else if (action == DeleteSpecificStudent)
		{
			int act2;
			do
			{
				cout << "Choose from which group to remove the student\n\n";
				cin >> act2;
				if (act2 < quantityGroup)
				{
					int act3;
					cout << "Selected  " << arr[act2]->group << " group\n";
					printGroup(arr, act2);
					do
					{
						cout << "\nChoose a student\n\n";
						cin >> act3;

						if (act3 < arr[act2]->size)
						{
							deleteStudent(arr, quantityGroup, act2, act3);
							cout << "\n\nStudent removed\n\n";

							printGroup(arr, act2);
							break;
						}
						else {
							cout << "Wrong selection, try again.\n";
						}

					} while (true);
					break;
				}
				else {
					cout << "Wrong selection , this group does not exist , try again.\n\n";
				}
			} while (true);
		}
		else if (action == PrintSpecificGroup)
		{
			int act1;
			do
			{
				cout << "Which group to print (#) ?\n";
				cin >> act1;
				if (act1 < quantityGroup)
				{
					printGroup(arr, act1);
					break;
				}
				else {
					cout << "Wrong selection , this group does not exist , try again.\n\n";
				}
			} while (true);
		}
		else if (action == PrintAllGroup)
		{
			cout << "Print all list\n\n";
			printGroups(arr, quantityGroup);
		}
		else if (action == StudentEditing)
		{
			int groupNum;
			do
			{
				cout << "Select a group to edit (#) ?\n";
				cin >> groupNum;
				if (groupNum < quantityGroup)
				{
					int studentNum;
					cout << "Select student number to edit information\n";
					cin >> studentNum;

					if (studentNum < arr[groupNum]->size)
					{
						studentEditing(arr, quantityGroup, groupNum, studentNum);
						cout << "You edited student datae\n";
						printGroup(arr, groupNum);
						break;
					}
					else {
						cout << "The wrong choice of such a student does not exist\n";
					}
				}
				else {
					cout << "Wrong selection, try again\n";
				}
			} while (true);

		}
		else
		{
			cout << "Wrong selection, try again.\n";
		}
	} while (true);



	for (int i = 0; i < quantityGroup; i++)
	{
		delete[] arr[i];
	}

	delete[] arr;

}