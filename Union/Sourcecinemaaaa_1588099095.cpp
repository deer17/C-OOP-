#include<iostream>
#include<iomanip>
#include<utility>

using namespace std;


struct Cinema
{
	char name[20];
	char genre[20];
	int rating;
};


void printList(const Cinema* arr, const int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << i << '\t' << arr[i].name << "\t\t";
		cout << arr[i].genre << "\t\t";
		cout << arr[i].rating << '\n';
	}
}


void printRating(const Cinema arr[], const int size, char ch[])
{
	bool searchMovie = true;

	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(ch, arr[i].genre) == 0)
		{
			searchMovie = false;
			cout << arr[i].name << "\t\t";
			cout << arr[i].genre << "\t\t";
			cout << arr[i].rating << endl;
		}
	}
	if (searchMovie)
	{
		cout << "-\t-\t\t\t\t-\t\t\t\t-\n\n";
		cout << "There are no films for this genre\n";
	}
}


bool up(const int number1, const int number2)
{
	return number1 < number2;
}

bool down(const int number1, const int number2)
{
	return number1 > number2;
}

typedef bool (*func_ptr)(int, int);

void sortByRating(Cinema*& arr, const int size, const func_ptr box)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = i + 1; j < size; j++)
		{
			if (box(arr[i].rating, arr[j].rating))
			{
				swap(arr[i], arr[j]);
			}
		}
	}
}


void deleteOneMovieInArr(Cinema*& arr, int& size, int num)
{
	Cinema* tmp = new Cinema[size - 1];
	for (size_t i = 0, j = 0; i < size; i++)
	{
		if (i != num)
		{
			tmp[j] = arr[i];
			j++;
		}
	}
	size--;
	delete[] arr;
	arr = tmp;
}



int main()
{

	const int exit = 0;
	const int add = 1;
	const int print = 2;
	const int search = 3;
	const int change = 4;
	const int sort = 5;
	const int remove = 6;


	const int youExit = -1;
	const int sortDown = 1;
	const int sortUp = 2;

	int raiting;
	int deleteMovie;
	int act;
	int action;
	int quantityMovie;
	char genre[20];

	cout << "Enter quantity movie \n";
	cin >> quantityMovie;

	Cinema* arr = new Cinema[quantityMovie];

	for (size_t i = 0; i < quantityMovie; i++)
	{
		cout << "Enter name of movie \n";
		cin >> arr[i].name;

		cout << "Enter name of genre \n";
		cin >> arr[i].genre;

		cout << "Enter name of rating \n";
		cin >> arr[i].rating;
	}

	do
	{
	

		cout << "Choose variant \n";
		cout << "0. Exit \n";
		cout << "1. Add film \n";
		cout << "2. Print film list \n";
		cout << "3. Search genre \n";
		cout << "4. Change rating \n";
		cout << "5. Sorting of films by rating \n";
		cout << "6. Remove film \n";


		cin >> action;

		if (action == exit)
		{
			cout << "You have left the program\n";
			break;
		}
		else if (action == add)
		{
			Cinema* add = new Cinema[quantityMovie + 1];

			for (size_t i = 0; i < quantityMovie; i++)
			{
				add[i] = arr[i];
			}

			cout << "Enter name of movie \n";
			cin >> add[quantityMovie].name;

			cout << "Enter name of genre \n";
			cin >> add[quantityMovie].genre;

			cout << "Enter number of rating \n";
			cin >> add[quantityMovie].rating;
			delete[] arr;
			quantityMovie++;
			arr = add;
		}
		else if (action == print)
		{
			cout << "\nPrint list of films\n\n";
			cout << "N\tName\t\t\t\tGenre\t\t\t\tRating\t\n\n";

			printList(arr, quantityMovie);
		}
		else if (action == search)
		{
			cout << "Search by genre\n";
			cin >> genre;

			cout << "\nPrint list of films by genre \n\n";
			cout << "\nN\tName\t\t\t\tGenre\t\t\t\tRating\n\n";

			printRating(arr, quantityMovie, genre);

		}
		else if (action == change)
		{
			int num;
			do
			{
				cout << "Exit -1\nWrite the movie number( N ) :\n";
				cin >> num;
				if (num < quantityMovie && num >= 0)
				{
					cout << "\nN\tName\t\t\t\tGenre\t\t\t\tRating\n\n";
					cout << num << '\t' << arr[num].name << "\t\t\t\t";
					cout << arr[num].genre << "\t\t\t\t";
					cout << arr[num].rating << endl;

					cout << "Please change rating\n";

					cin >> raiting;
					arr[num].rating = raiting;

					cout << "Rating changed\n";

					cout << "\nN\tName\t\t\t\tGenre\t\t\t\tRating\n\n";
					cout << num << '\t' << arr[num].name << "\t\t\t\t";
					cout << arr[num].genre << "\t\t\t\t";
					cout << arr[num].rating << endl;
					break;
				}
				else if (num == youExit) {
					cout << "You exit\n";
					break;
				}
				else {
					cout << "\nno such number ( # )! \n Try again\n\n";
				}

			} while (true);
		}
		else if (action == sort)
		{
			cout << "\nSort by Rating\n";

			do
			{
				cout << "1 - Up\n2 - Down\n\n";
				cin >> act;

				if (act == sortUp)
				{
					sortByRating(arr, quantityMovie, up);
					break;
				}
				else if (act == sortDown)
				{
					sortByRating(arr, quantityMovie, down);
					break;
				}

				else {
					cout << "Wrong selection, try again\n";
				}
			} while (true);

			cout << "\nN\tName\t\t\t\tGenre\t\t\t\tRating\n\n";
			printList(arr, quantityMovie);

		}
		else if (action == remove)
		{
			do
			{
				cout << "\nWrite the movie number( N ) for delete  :\n";
				cin >> deleteMovie;
				if (deleteMovie < quantityMovie && deleteMovie >= 0)
				{
					deleteOneMovieInArr(arr, quantityMovie, deleteMovie);
					break;
				}
				else {
					cout << "Wrong selection, try again\n";
				}
			} while (true);

			cout << deleteMovie << " Movie deleted\n\n";
			cout << "\nN\tName\t\t\t\tGenre\t\t\t\tRating\n\n";
			printList(arr, quantityMovie);
		}
		else {
			cout << "Wrong selection, try again\n";
		}

	} while (true);


	delete[] arr;
}