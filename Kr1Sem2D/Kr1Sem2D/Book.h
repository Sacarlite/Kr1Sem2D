#pragma once
#include <string>
/*
Класс Книга с приватными полями: автор, название, издательство, год, количество страниц
*/
class Book//Класс Книга
{
private:
	std::string _autor{};//Поле автор
	std::string _name{};//Поле названия
	std::string _publisher{};//Поле издательство
	int _year = 0;//Поле года
	int _amountOfPages = 0;//Поле количества страниц
public:
	Book() = default;//Конструктор по умолчанию
	Book(std::string autor, std::string name, std::string publisher, int year, int amountOfPages);//Конструктор

	void SetAutor(std::string autor);//Установка поля автор
	std::string GetAutor();//Возврат значения поля автор
	void ShowAutor();//Вывод на консоль поля автор

	void SetName(std::string name);//Установка поля названия
	std::string GetName();//Возврат значения поля названия
	void ShowName();//Вывод на консоль поля названия

	void SetPublisher(std::string publisher);//Установка поля издательство
	std::string GetPublisher();//Возврат значения поля издательство
	void ShowPublisher();//Вывод на консоль поля издательство

	void SetYear(int year);//Установка поля года
	int GetYear();//Возврат значения поля года
	void ShowYear();//Вывод на консоль поля года

	void SetAmountOfPages(int amountOfPages);//Установка поля количества страниц
	int GetAmountOfPages();//Возврат значения поля количества страниц
	void ShowAmountOfPages();//Вывод на консоль поля количества страниц
};
