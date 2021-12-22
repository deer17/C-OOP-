#include <iostream>
#include <ctime>;
#include <cstdlib>

using namespace std;

int main()
{
	srand(time(nullptr));

	int sizeRows;
	int sizeCols;
	cout << "Enter rows \n";
	cin >> sizeRows;
	cout << "Enter cols \n";
	cin >> sizeCols;

	int** arr = new int* [sizeRows];

	for (int i = 0; i < sizeRows; i++)
	{
		arr[i] = new int[sizeCols];
	}
	for (int i = 0; i < sizeRows; i++)
	{
		for (int j = 0; j < sizeCols; j++)
		{
			arr[i][j] = rand() % 20;
		}
	}

	int rowsRand = rand() % sizeRows;
	int colsRand = rand() % sizeCols;

	arr[rowsRand][colsRand] = 2;

	for (int i = 0; i < sizeRows; i++)
	{
		for (int j = 0; j < sizeCols; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}

	int popitka = 3;

	int row, col;

	while (popitka != 0)
	{
		cout << "Enter row \n";
		cin >> row;
		cout << "Enter col \n";
		cin >> col;

		if (arr[row][col] == arr[rowsRand][colsRand]) {
			cout << "You win! \n";
			break;
		}
		else {
			cout << "You did't find the number \n";
		}
		popitka--;
		if (popitka == 0)
		{
			cout << "You lost :(\n";
		}

	}

	for (int i = 0; i < sizeRows; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;

}