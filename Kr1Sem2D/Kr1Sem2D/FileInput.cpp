#include "FileInput.h"
#include "CheckExeption.h"
#include "Checks.h"


std::vector<Book> FileDataInput()
{
	std::vector<Book> books;
	std::string fileName;
	std::ifstream file;
	file.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	while (true)
	{
		std::cout << "Введите имя фаила (в разрешении .txt): " << std::endl;
		std::cin >> fileName;
		try
		{
			if (fileName.find(".txt") == std::string::npos)
			{
				std::cout << "Не верное разрешение у файла.Повторитие попытку. " << std::endl;
				continue;
			}
			if (std::filesystem::is_regular_file(fileName))
			{
				std::cout << "Фаил открыт успешно. " << std::endl;
				file.open(fileName);
			}
			
		}
		catch (const std::exception&)
		{
			std::cout << " Произошла ошибка при открытии фаила.Повторите попытку:" << std::endl;
			continue;

		}
		std::string autor{};
		std::string name{};
		std::string publisher{};
		int year = 0;
		int amountOfPages = 0;
		try {
			int objectCount = CheckLineIntMoreThan0(file);
			for (int i = 0; i < objectCount; i++) { 
				autor = CheckLineS(file);
				name = CheckLineS(file);
				publisher = CheckLineS(file);
				year = CheckLineYear(file);
				amountOfPages = CheckLineIntMoreThan0(file);
				Book book(autor,name,publisher,year,amountOfPages);
				books.push_back(book);
			}

		}
		catch (const std::exception) {
			std::cout << " Произошла ошибка при чтении информации. Повторите попытку:" << std::endl;
			file.close();
			continue;
		}
		catch (const CheckException err) {
			std::cout << err.GetMessage() << std::endl;
			file.close();
			continue;
		}
		file.close();
		return  books;
	}
}
