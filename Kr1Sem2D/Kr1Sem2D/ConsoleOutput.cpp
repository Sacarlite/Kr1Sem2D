#include "ConsoleOutput.h"
void ConsoleOutput(std::vector<Book> books)
{
	std::cout << "Количество подходящих книг:" << books.size() << std::endl;
	std::cout << "Список книг:" << std::endl;
	for (auto i = books.begin(); i < books.end(); ++i)
	{
		std::cout << "Книга:" << std::endl;
		std::cout << "	Aвтор - ";
		i->ShowAutor();
		std::cout << "	Название - ";
		i->ShowName();
		std::cout << "	Издательство - ";
		i->ShowPublisher();
		std::cout << "	Год - ";
		i->ShowYear();
		std::cout << "	Количество страниц - ";
		i->ShowAmountOfPages();
		std::cout << std::endl;
	}
}
