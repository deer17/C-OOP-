#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
int main()
{
	int rows;
	int cols;
	cout << "Enter rows \n";
	cin >> rows;
	cout << "Enter cols \n";
	cin >> cols;
	char** arr = new char* [rows];

	for (int i = 0; i < rows; i++)
	{
		arr[i] = new char[cols];
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = '-';
		}
	}
	srand(time(nullptr));
	int iRand = rand() % rows;
	int jRand = rand() % cols;
	int bomba;
	while (true)
	{
		cout << "Enter the number of bombs \n";
		cin >> bomba;
		if (bomba < (rows * cols)) {
			break;
		}
		else {
			cout << "The number of bombs can't be greater than or equal too the number of arrays \n";
		}
	}

	for (int i = 0; i < bomba; i++)
	{
		arr[iRand][jRand] = 'x';
	}

	int ro;
	int co;
	int freeLevel = 0, chekfreeLevl = 0;
	for (int i = 0; i < rows; i++)
	{

		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] == '-') {
				freeLevel++;
			}

			cout << '-' << ' ';
		}
		cout << '\n';
	}
	while (true)
	{

		cout << "Minesweeper game \n";
		cout << "Number of empty seats - " << freeLevel << '\n';
		do
		{
			cout << "Enter ro \n";
			cin >> ro;
			if (ro >= rows)
			{
				cout << "Row size can't be greater than or equal to - " << rows << endl;
			}
		} while (ro >= rows);

		do
		{
			cout << "Enter co \n";
			cin >> co;
			if (co >= cols)
			{
				cout << "razmer stolbca ne mojit bolwe ili ravno - " << cols << endl;
			}
		} while (co >= cols);

		system("cls");
		if (arr[ro][co] == 'x') {
			cout << "You stepped on a bomb \n";
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					if (arr[i][j] == 'x') {
						cout << arr[i][j] << ' ';
					}
					else {
						cout << arr[i][j] << ' ';
					}
				}
				cout << '\n';
			}
			break;
		}
		else if (arr[ro][co] != 'x') {
			cout << "True step \n";
			arr[ro][co] = 'o';
		}
		chekfreeLevl = 0;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (arr[i][j] == 'o')
				{
					chekfreeLevl++;
				}
			}

		}
		if (freeLevel == chekfreeLevl) {
			cout << "You win the game \n";
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{

					if (arr[i][j] == 'x') {
						cout << '-' << ' ';
					}
					else {
						cout << arr[i][j] << ' ';
					}
				}
				cout << '\n';
			}
			break;
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{

				if (arr[i][j] == 'x') {
					cout << '-' << ' ';
				}
				else {
					cout << arr[i][j] << ' ';
				}
			}
			cout << '\n';
		}


	}



	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];
	}

	delete[]arr;
}
