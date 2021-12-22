#include<iostream>
#pragma warning (disable: 4996)
#include<cstdio>

using namespace std;

/*

       Задание: Файловый менеджер
           Реализуйте следующие функции:
               1. Создание файла в указанной директории
               2. Удаление файла
               3. Смена названия/перемещение файла (вводим старое название и новое название)
               4. Чтение содержимого файла
               5. Определение размера файла (вводим путь до файла, получаем размер в байтах)
               6. Запись данных в файл (в конец)
*/

enum{ Create, Deletee, Change, Moving, Reading, DetermineSize, DataRecord, Exit};
int main()
{
    char directory[100];
    char newDirectory[100];
    char text[100];
    do {


        cout << "Choose your action: \n";
        cout << "0. Create file \n";
        cout << "1. Delete file \n";
        cout << "2. Rename file \n";
        cout << "3. Move file \n";
        cout << "4. Reading file \n";
        cout << "5. Determine size of file \n";
        cout << "6. Record data into file \n";
        cout << "7. Exit \n";

        
        int choice;
        int result;
        cin >> choice;
        if (choice == Create) {
            cout << "Please enter directory \n";
            cin >> directory;
            FILE* f = fopen(directory, "w");
            if (!f) {
                perror("Error message!");
            }
            else {
                fputs(text, f);
                fclose(f);
            }
        }
        else if (choice == Deletee) {
            cout << "Enter directory which you want to delete \n";
            cin >> directory;
            result = remove(directory);
            if (result != 0) {
                perror("You cannot delete file");
            }
            else {
                cout << "You already deleted file \n";
            }
        }
        else if (choice == Change) {
            cout << "Enter directory what you want to rename \n";
            cin >> directory;
            cout << "Enter new name \n";
            cin >> newDirectory;
            int result = rename(directory, newDirectory);
            if (result != 0) {
                perror("You cannot rename file");
            }
            else {
                cout << "You already renamed file \n";
            }
        }
        else if (choice == Moving) {
            cout << "Change location\n\nPlease enter file directory\n";
            cin >> directory;
            cout << "Please enter new directory\n";
            cin >> newDirectory;


            result = rename(directory, newDirectory);
            if (result != 0) {
                perror("You cannot rename file");
            }
            else
            {
                cout << "You already renamed file directory \n";
            }
        }
        else if (choice == Reading) {
            cout << "Enter file directory what you want to read \n";
            cin >> directory;
            FILE* f = fopen(directory, "r");
            if (!f) {
                perror("Error message");
            }
            else {
                char data[100];
                fgets(data, 100, f);
                cout << "data is : " << data << '\n';
                fclose(f);
            }
        }
        else if (choice == DetermineSize) {
            cout << "Enter directory which size you want to determine \n";
            cin >> directory;
            FILE* f = fopen(directory, "r");
            if (!f) {
                perror("Error");
            }
            else {
                FILE* f = fopen(directory, "r");
                fseek(f, 0, SEEK_END);
                cout << "filesize is : " << ftell(f) << '\n';
                fclose(f);
            }
        }
        else if (choice == DataRecord) {
            cout << "Please enter directory of file which you want to record \n";
            cin >> directory;
            cout << "Enter text of file \n";
            cin >> text;
            FILE* f = fopen(directory, "a");
            if (f) {
                fputs("\n", f);
                fputs(text, f);
                fclose(f);
            }
            else {
                perror("Error");
            }
        }
        else if (choice == Exit) {
        cout << "You exit the programm\n";
        break;
}

    } while (true);
}
       
     
   

  
 

