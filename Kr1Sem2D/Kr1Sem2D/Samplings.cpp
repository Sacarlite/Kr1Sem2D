#include "Samplings.h"
#include "Checks.h"
#include <iostream>

std::vector<Book> SamplingBooksByAutor(std::vector<Book> books, std::string autor)
{
	std::vector<Book> sampledBooks;
	for (auto i = books.begin(); i < books.end(); ++i)
	{
		if(i->GetAutor() == autor)
		{
			sampledBooks.push_back(*i);
		}
	}
	return sampledBooks;

}

std::vector<Book> SamplingBooksByPublisher(std::vector<Book> books, std::string publisher)
{
	std::vector<Book> sampledBooks;
	for (auto i = books.begin(); i < books.end(); ++i)
	{
		if (i->GetPublisher() == publisher)
		{
			sampledBooks.push_back(*i);
		}
		
	}
	return sampledBooks;
}

std::vector<Book> SamplingBooksByYear(std::vector<Book> apartments, int year)
{
	std::vector<Book> sampledBooks;
	for (auto i = apartments.begin(); i < apartments.end(); ++i)
	{
		if (i->GetYear() > year)
		{
			sampledBooks.push_back(*i);
		}
	}
	return sampledBooks;


}
