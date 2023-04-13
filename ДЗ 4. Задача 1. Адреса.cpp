#include <iostream>
#include <cstring>
#include <fstream>
#include <string>

class adress
{
private:
	std::string City;
	std::string Street;
	int HouseNumber;
	int FlatNumber;
	std::string FullAdress;

public:
	adress(std::string NameOfTheCity, std::string NameOfTheStreet, int NumberOfTheHouse, int NumberOfFlat)
	{
		set_adress(NameOfTheCity, NameOfTheStreet, NumberOfTheHouse, NumberOfFlat);
	}

	void set_adress(std::string NameOfTheCity, std::string NameOfTheStreet, int NumberOfTheHouse, int NumberOfFlat)
	{
		City = NameOfTheCity;
		Street = NameOfTheStreet;
		HouseNumber = NumberOfTheHouse;
		FlatNumber = NumberOfFlat;
	}

	std::string get_output_address()
	{
		FullAdress = City + ", " + Street + ", " + std::to_string(HouseNumber) + ", " + std::to_string(FlatNumber);
		return FullAdress;
	};
};

int printArray(std::string* Array, const int NumberOfAdresses)
{
	std::ofstream file_out("out.txt");

	file_out << NumberOfAdresses << std::endl;

	for (int i = NumberOfAdresses - 1; i >= 0;i--)
	{
		file_out << Array[i] << std::endl;
	}
	file_out.close();
	return 0;
};


std::string* textArray(const int NumberOfAdresses)
{
	std::string* textArray = new std::string[NumberOfAdresses]{};
	return textArray;

}

void delete_textArray(std::string* textArray, const int NumberOfAdresses)
{
	delete[] textArray;
	textArray = nullptr;
}

int main ()
{
	setlocale(LC_ALL, "Russian"); 
	system("chcp 1251");

	std::ifstream file_in("in.txt"); 
	if (!file_in)
	{
		std::cout << "Ошибка открытия файла in.txt." << std::endl;
	}
	else
	{
		std::cout << "Файл in.txt успешно открыт." << std::endl;
	}

	int NumberOfAdresses = 0;
	std::string NameOfTheCity{};
	std::string NameOfTheStreet{};
	int NumberOfTheHouse = 0;
	int NumberOfFlat = 0;

	file_in >> NumberOfAdresses;
	std::string* Array = textArray(NumberOfAdresses);

	for (int i = 0;i < NumberOfAdresses;i++)
	{
		file_in >> NameOfTheCity >> NameOfTheStreet >> NumberOfTheHouse >> NumberOfFlat;
		adress Adress(NameOfTheCity, NameOfTheStreet, NumberOfTheHouse, NumberOfFlat);
		Array[i] = Adress.get_output_address();
	};
	file_in.close();

	printArray(Array, NumberOfAdresses);
	delete_textArray(Array, NumberOfAdresses);

}

