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
		std::cout << "������� ��� ����� (� ���������� .txt): " << std::endl;
		std::cin >> fileName;
		try
		{
			if (fileName.find(".txt") == std::string::npos)
			{
				std::cout << "�� ������ ���������� � �����.���������� �������. " << std::endl;
				continue;
			}
			if (std::filesystem::is_regular_file(fileName))
			{
				std::cout << "���� ������ �������. " << std::endl;
				file.open(fileName);
			}
			
		}
		catch (const std::exception&)
		{
			std::cout << " ��������� ������ ��� �������� �����.��������� �������:" << std::endl;
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
			std::cout << " ��������� ������ ��� ������ ����������. ��������� �������:" << std::endl;
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
