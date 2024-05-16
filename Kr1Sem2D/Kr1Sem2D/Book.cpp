#include "Book.h"
#include <iostream>

Book::Book(std::string autor, std::string name, std::string publisher, int year, int amountOfPages)
	:_autor(autor), _name(name), _publisher(publisher), _year(year), _amountOfPages(amountOfPages)
{
}

void Book::SetAutor(std::string autor)
{
	_autor = autor;
}

std::string Book::GetAutor()
{
	return _autor;
}

void Book::ShowAutor()
{
	std::cout << _autor << std::endl;
}

void Book::SetName(std::string name)
{
	_name = name;
}

std::string Book::GetName()
{
	return _name;
}

void Book::ShowName()
{
	std::cout << _name << std::endl;
}

void Book::SetPublisher(std::string publisher)
{
	_publisher = publisher;
}

std::string Book::GetPublisher()
{
	return _publisher;
}

void Book::ShowPublisher()
{
	std::cout << _publisher << std::endl;
}

void Book::SetYear(int year)
{
	_year = year;
}

int Book::GetYear()
{
	return _year;
}

void Book::ShowYear()
{
	std::cout << _year << std::endl;
}

void Book::SetAmountOfPages(int amountOfPages)
{
	_amountOfPages = amountOfPages;
}

int Book::GetAmountOfPages()
{
	return _amountOfPages;
}

void Book::ShowAmountOfPages()
{
	std::cout << _amountOfPages << std::endl;
}
