#pragma once
#include <vector>//Библиотека подключения вектора
#include "Book.h"
std::vector<Book> SamplingBooksByAutor(std::vector<Book> books,std::string autor);
std::vector<Book> SamplingBooksByPublisher(std::vector<Book> books, std::string publisher);
std::vector<Book> SamplingBooksByYear(std::vector<Book> books, int year);

