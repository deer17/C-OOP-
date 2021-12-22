#include <iostream>
#include <string.h>

using namespace std;


int main()
{

	enum { add = 1, print, exit };
	int selection;

	int size = 20;
	const int nameSize = 500;
	char listofName[nameSize] = "Print your list : \n";

	do
	{
		
		cout << "\n Choose your variant \n";
		cout << "1. Add \n";
		cout << "2. Print \n";
		cout << "3. Exit \n";
		cin >> selection;
		if (selection == exit)
		{
			cout << "You exit  program\n";
			break;
		}
		else if (selection == add)
		{
			cout << "Enter name \n";
			char* name = new char[size];
			cin >> name;
			strcat_s(listofName, name);
			strcat_s(listofName, "\n");
			delete[] name;
		}
		else if (selection == print) {
			cout << listofName;
			
		}

	} while (true);

}

