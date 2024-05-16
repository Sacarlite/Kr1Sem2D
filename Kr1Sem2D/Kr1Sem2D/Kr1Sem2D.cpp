#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include "Book.h"
#include "MainMenu.h"
#include "Checks.h"
#include "ConsoleOutput.h"
#include "FileInput.h"
#include "FileOutput.h"
#include "Input.h"
#include "PersonalInterface.h"
#include "Samplings.h"
#define QUIT 27//Макрос присваивания Esc значение 27
int main()
{
	setlocale(LC_CTYPE, "RU");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int userChoice = 0;
	std::vector<Book> books;
	std::vector<Book> sortedBooks;
	ShowGreetings();
	ShowTask();
	do
	{
		ShowInputOption();
		userChoice = GetChoise();
		switch (userChoice)
		{
		case  (ConsoleInput):
			books = ConsoleIput();
			break;
		case (FileInput):
			books = FileDataInput();
			ConsoleOutput(books);
			break;
		}
		if (userChoice != FileInput) {
			ShowOutputType();
			userChoice = GetChoise();
			if (userChoice == Yes)
			{
				FileOutput(books);
			}
		}
		int year = 0;
		std::string autor{};
		std::string publisher{};
		do {
			ShowMenu();
			userChoice = SetMenuPoint();
			switch (userChoice) {
			case SamplingByAutor:
				std::cout << "Введите автора:" << std::endl;
				autor = GetString();
				sortedBooks = SamplingBooksByAutor(books, autor);
				break;
			case SamplingByPublisher:
				std::cout << "Введите издательство:" << std::endl;
				publisher = GetString();
				sortedBooks = SamplingBooksByPublisher(books, publisher);
				break;

			case SamplingByYear:
				std::cout << "Введите год публикации:" << std::endl;
				year = GetYear();
				sortedBooks = SamplingBooksByYear(books, year);
				break;
			}
			if (sortedBooks.empty()) {
				std::cout << "Нет элементов удовлетворяющих поиску" << std::endl;
				continue;
			}
			else {
				ConsoleOutput(sortedBooks);
				ShowOutputType();
				userChoice = GetChoise();
				if (userChoice == Yes) {
					FileOutput(sortedBooks);
				}
			}
			sortedBooks.clear();
			std::cout << "Нажмите Esc чтобы завершить работу с подменю." << std::endl;
			std::cout << "Нажмите Enter чтобы продолжить." << std::endl;
			std::cout << " " << std::endl;
			userChoice = _getch();
		} while (userChoice != QUIT);

		books.clear();
		std::cout << "Нажмите Esc чтобы завершить работу программы." << std::endl;
		std::cout << "Нажмите Enter чтобы продолжить." << std::endl;
		userChoice = _getch();
	} while (userChoice != QUIT);
}
