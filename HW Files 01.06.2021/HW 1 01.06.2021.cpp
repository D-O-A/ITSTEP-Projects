#include <iostream>
#include <cstring>
using namespace std;

FILE* file;

void OpenFile()
{
	char path[200];
	errno_t errorCode;

	do
	{
		cout << "Enter path: ";
		cin.getline(path, 200);

		//words.txt
		errorCode = fopen_s(&file, path, "r");

		if (errorCode == 2)
			cout << "Wrong Path, try again" << endl;

	} while (errorCode == 2);

	system("cls");

	if (errorCode != 0)
	{
		cout << "Error code: " << errorCode << endl;
		return;
	}

	cout << "File opened successfully." << endl << endl;
}

int SearchKey(char input[])
{
	char str[100];

	//cat = 5 times
	//dog = 4 
	//mouse = 3
	//fox = 2
	//rabbit = 2

	int input_length = strlen(input);
	int str_length;

	int char_counter;
	int word_counter = 0;
	int index_counter;

	while (!feof(file))
	{
		fgets(str, 100, file);

		str_length = strlen(str);

		for (size_t i = 0; i < str_length; i++)
		{
			char_counter = 0;

			if (str[i] == input[0])
			{
				i++;
				index_counter = 1;

				for (size_t j = index_counter; j < input_length; j++)
				{
					if (str[i] == input[j])
					{
						char_counter++;
						index_counter++;
					}
					i++;
				}
			}

			if (char_counter == input_length - 1)
			{
				word_counter++;
			}
		}
	}

	cout << input << " repeats " << word_counter << " times" << endl << endl;

	fclose(file);

	return word_counter;
}

void AddNewFile(char word_counter[], char input[])
{
	errno_t error_code = fopen_s(&file, "result.txt", "w");

	if (error_code != 0)
	{
		cout << "Error code: " << error_code << endl;
		return;
	}

	cout << "New file opened successfully." << endl << endl;

	char temp[100];

	//я не уверен можно ли было "слепить" строку более изящно, но так работает :)
	strcpy_s(temp, 100, input);
	strcat_s(temp, 100, " ");
	strcat_s(temp, 100, "repeats ");
	strcat_s(temp, 100, word_counter);
	strcat_s(temp, 100, " ");
	strcat_s(temp, 100, "times.");

	fputs(temp, file);

	fclose(file);
}

int main()
{
	OpenFile();

	char input[20];

	cout << "Enter cat, dog, mouse, fox or rabbit to see how many times it repeats:";
	cin.getline(input, 20);

	int word_counter = SearchKey(input);

	// buffer[33]
	char buffer[sizeof(int) * 8 + 1];

	//спасибо stack overflow, так можно преобразовать Int в строку, не уверен насчет 3 параметра, на msdn написано это размер буфера, мой вариант работает :)
	_itoa_s(word_counter, buffer, 33, 10);

	AddNewFile(buffer, input);
}