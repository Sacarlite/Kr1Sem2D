#include "FileOutput.h"
#include <fstream>
#include <iostream>
#include "Checks.h"
#include "MainMenu.h"
#include "PersonalInterface.h"
#include <filesystem>
class FileWriteException
{
public:
	FileWriteException(std::string message) : message{ message } {}
	std::string getMessage() const { return message; }
private:
	std::string message;
};

void WriteBooks(std::vector<Book> apartments,std::string fileName)
{
	std::ofstream  out;
	out.exceptions(std::ofstream::badbit | std::ofstream::failbit);
	try {
		out.open(fileName);
		out << apartments.size() << std::endl;
		for (auto i = apartments.begin(); i < apartments.end(); ++i)
		{
			out << i->GetAutor() << std::endl;
			out << i->GetName() << std::endl;
			out << i->GetPublisher() << std::endl;
			out << i->GetYear() << std::endl;
			out << i->GetAmountOfPages() << std::endl;
		}
		out.close();
		std::cout << "Данные успешно сохранены" << std::endl;
	}
	catch(const std::exception&)
	{
		throw FileWriteException("Невозможно записать данные в файл.Повторите попытку.");
	}
}
void FileOutput(std::vector<Book> books)
{
	std::ifstream out2;
	std::string fileName;
	out2.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	int userChoice = 0;
	while (true) {
		std::cout << "Введите имя фаила (в разрешении .txt): ";
		std::cin >> fileName;
		try {
			if(fileName.find(".txt") == std::string::npos)
			{
				std::cout << "Не верное разрешение у файла.Повторитие попытку. "<<std::endl;
				continue;
			}
			try
			{
				if (std::filesystem::is_regular_file(fileName))//Проверка на системные фаилы
				{
					std::cout << "Фаил с таким именем уже существует" << std::endl;
				}
			}
			catch (const std::exception&)
			{
				throw FileWriteException("Невозможно записать данные в файл.Повторите попытку.");

			}
			out2.open(fileName);
			ShowOutputChoise();
			userChoice = GetChoise();
			if (userChoice == Yes) {
				
				out2.close();
				WriteBooks(books, fileName);
			}
			else {
				out2.close();
				continue;
			}
			break;
		}
		catch (const std::exception&) {
			try {
				WriteBooks(books, fileName);
				break;
			}
			catch ( FileWriteException err) {
				std::cout << err.getMessage() << std::endl;
			}
		}
		catch (FileWriteException err) {
			std::cout << err.getMessage() << std::endl;
		}

	}
}
