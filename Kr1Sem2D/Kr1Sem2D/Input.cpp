#include "Input.h"//Подключение HeaderFile с вводом данных с консоли
#include <iostream>//Библиотека ввода и вывода
#include "Checks.h"//Подключение HeaderFile с проверками пользовательского ввода
#include "MainMenu.h"//Подключение HeaderFile с Enum menu

std::vector<Book> ConsoleIput()
{
	std::vector<Book> books;
	std::cout << "Добавление книг" << std::endl;
	int counter = 1; 
	int userChoice = 0;
	while(true)
	{

		std::cout << "Книга №" << counter<< std::endl;
		std::cout << "Введите автора:" << std::endl;
		std::string autor = GetString();
		std::cout << "Введите название:"<< std::endl;
		std::string name = GetString();
		std::cout << "Введите издательство:" << std::endl;
		std::string publisher = GetString();
		std::cout << "Введите год публикации:" << std::endl;
		int year = GetYear();
		std::cout << "Введите количество страниц:" << std::endl;
		int amountOfPages = GetPositiveIntMoreThen0();
		Book book(autor, name, publisher, year, amountOfPages);
		books.push_back(book);
		std::cout << "Хотите добавить ещё книгу"<<std::endl;
		std::cout << "1)Да" << std::endl;
		std::cout << "2)Нет" << std::endl;
		userChoice = GetChoise();
		if(userChoice== Yes)
		{
			counter++;
			continue;
		}
		else
		{
			return books;
		}
	}
}
