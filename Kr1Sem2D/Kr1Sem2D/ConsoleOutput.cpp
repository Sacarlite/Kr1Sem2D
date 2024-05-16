#include "ConsoleOutput.h"
void ConsoleOutput(std::vector<Book> books)
{
	std::cout << "���������� ���������� ����:" << books.size() << std::endl;
	std::cout << "������ ����:" << std::endl;
	for (auto i = books.begin(); i < books.end(); ++i)
	{
		std::cout << "�����:" << std::endl;
		std::cout << "	A���� - ";
		i->ShowAutor();
		std::cout << "	�������� - ";
		i->ShowName();
		std::cout << "	������������ - ";
		i->ShowPublisher();
		std::cout << "	��� - ";
		i->ShowYear();
		std::cout << "	���������� ������� - ";
		i->ShowAmountOfPages();
		std::cout << std::endl;
	}
}
