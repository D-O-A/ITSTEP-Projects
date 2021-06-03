#include <iostream>
#include <cstring>
using namespace std;

struct Location
{
	char name[200];
	char address[200];
	char phone[25];
	char description[300];
	char working_hours[20];
};

void InputLocation(Location& total_locations)
{
	cout << "Enter name:";
	cin.getline(total_locations.name, 200);
	cout << "Enter address:";
	cin.getline(total_locations.address, 200);
	cout << "Enter phone number:";
	cin.getline(total_locations.phone, 25);
	cout << "Enter description:";
	cin.getline(total_locations.description, 300);
	cout << "Enter working hours:";
	cin.getline(total_locations.working_hours, 20);

	cout << endl;
}

void AddLocation(Location*& total_locations, size_t& size)
{
	Location* temp = new Location[size + 1];

	for (size_t i = 0; i < size; i++)
	{
		temp[i] = total_locations[i];
	}

	InputLocation(temp[size]);

	delete[] total_locations;
	total_locations = temp;

	size++;
}

void PrintLocations(Location*& total_locations, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << total_locations[i].name << endl << total_locations[i].address << endl
			<< total_locations[i].phone << endl << total_locations[i].description << endl
			<< total_locations[i].working_hours << endl << endl;
	}
}

void PrintLocation(Location*& total_locations, int i)
{
	cout << total_locations[i].name << endl << total_locations[i].address << endl
	<< total_locations[i].phone << endl << total_locations[i].description << endl
	<< total_locations[i].working_hours << endl << endl;
}

void RemoveLastLocation(Location*& total_locations, size_t& size)
{
	if (size != 0)
	{
		Location* temp = new Location[size - 1];

		for (size_t i = 0; i < size - 1; i++)
		{
			temp[i] = total_locations[i];
		}

		delete[] total_locations;
		total_locations = temp;

		size--;
	}
}

size_t SelectLocationToEdit(size_t size)
{
	size_t choice;
	cout << size << " location(s) available, choose location to edit:";

	do
	{
		cin >> choice;
	} while (choice < 0 || choice > size);

	cin.ignore();

	return choice - 1;
}

int PrintMenu()
{
	int choice = 0;

	do
	{
		cout << "1. Add new location.\n"
			<< "2. Remove last location.\n"
			<< "3. Change info of location.\n"
			<< "4. Show all locations info.\n"
			<< "5. Search location by name.\n"
			<< "6. Search location by description.\n"
			<< "7. Exit.\n\n";

		cout << "Your choice: [ ]\b\b";
		cin >> choice;

		cin.ignore();

		system("cls");

	} while (choice < 0 || choice > 7);

	return choice;
}

void SearchByName(Location*& total_locations, size_t size)
{
	char key[200];
	int result;

	cout << "Enter name to search:";
	cin.getline(key, 200);

	for (size_t i = 0; i < size; i++)
	{
		result = strcmp(total_locations[i].name, key);

		if (result == 0)
		{
			PrintLocation(total_locations, i);
			cout << endl;
		}
	}

	if (result != 0)
	{
		cout << "No matching names found.\n\n";
	}
}

void SearchByDescription(Location*& total_locations, size_t size)
{
	char key[300];
	int result;

	cout << "Enter description to search:";
	cin.getline(key, 300);

	for (size_t i = 0; i < size; i++)
	{
		result = strcmp(total_locations[i].description, key);

		if (result == 0)
		{
			PrintLocation(total_locations, i);
			cout << endl;
		}
	}

	if (result != 0)
	{
		cout << "No matching descriptions found.\n\n";
	}
}

void SaveToBin(Location* total_locations, size_t size)
{
	FILE* file;
	errno_t error_code = fopen_s(&file, "savedata.bin", "w");

	if (error_code != 0)
	{
		cout << "Error code - " << error_code << endl;
		return;
	}

	fwrite(&size, sizeof(size_t), 1, file);
	fwrite(total_locations, sizeof(Location), size, file);

	fclose(file);
}

void ReadFromBin(Location*& total_locations, size_t& size)
{
	FILE* file;

	errno_t error_code = fopen_s(&file, "savedata.bin", "r");

	if (error_code != 0)
	{
		cout << "Error code - " << error_code << endl;
		system("pause");
		return;
	}

	fread(&size, sizeof(size_t), 1, file);

	total_locations = new Location[size];

	fread(total_locations, sizeof(Location), size, file);

	PrintLocations(total_locations, size);

	fclose(file);
}

int main()
{
	//Написать программу "Справочник покупателя", описывающую торговые точки города: название, адрес, телефоны, специализация, время работы. Количество торговых точек неограничено. Реализовать:
	//•	добавление торговой точки; 
	//•	удаление торговой точки; 
	//•	изменение информации о торговой точке; 
	//•	вывод информации о всех торговых точках; 
	//•	поиск по названию;
	//•	поиск по специализации.

	size_t size = NULL;
	Location* total_locations = nullptr;

	ReadFromBin(total_locations, size);

	int choice;

	do
	{
		choice = PrintMenu();

		system("cls");

		switch (choice)
		{
		case 1:
			AddLocation(total_locations, size);
			break;
		case 2:
			RemoveLastLocation(total_locations, size);
			break;
		case 3:
			InputLocation(total_locations[SelectLocationToEdit(size)]);
			break;
		case 4:
			PrintLocations(total_locations, size);
			break;
		case 5:
			SearchByName(total_locations, size);
			break;
		case 6:
			SearchByDescription(total_locations, size);
			break;
		case 7:
			SaveToBin(total_locations, size);
			exit(0);
		}

	} while (true);
}