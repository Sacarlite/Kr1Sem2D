#include <iostream>
#include "PersonalInterface.h"

void ShowMenu()
{
	std::cout << "Перед вами меню запросов" << std::endl;
	std::cout << "1)Выборка книг, с заданным автором" << std::endl;
	std::cout << "2)Выборка книг, с заданным издательством" << std::endl;
	std::cout << "3)Выборка книг, выпущенных после заданного года" << std::endl;
	std::cout << "Ввод:" << std::endl;
}
void ShowTask() {
	std::cout << "Книга: автор, название, издательство, год, количество страниц. Создать" << std::endl;
	std::cout << "массив объектов. Реализовать возможность получения" << std::endl;
	std::cout << "– списка книг заданного автора, " << std::endl;
	std::cout << "– списка книг, выпущенных заданным издательством," << std::endl;
	std::cout << "– списка книг, выпущенных после заданного года." << std::endl;
}

void ShowOutputDataOption()
{
	std::cout << "Вы хотите сохранить исходные данные в файл?" << std::endl;
	std::cout << "1)Да" << std::endl;
	std::cout << "2)Нет" << std::endl;
}
void ShowInputOption()
{
	std::cout << "Какой вид ввода данных вы хотите использовать?" << std::endl;
	std::cout << "1)Фаиловый" << std::endl;
	std::cout << "2)Консольный" << std::endl;
}

void ShowGreetings()
{
	std::cout << "Контрольная работа №1 Дмитрий Нехорошев 4304г" << std::endl;
}

void ShowOutputType()
{
	std::cout << "Вы хотите записать данные в файл?" << std::endl;
	std::cout << "1)Да" << std::endl;
	std::cout << "2)Нет" << std::endl;
}


void ShowOutputChoise()
{
	std::cout << "Вы хотите перезаписать данный фаил?" << std::endl;
	std::cout << "1)Да" << std::endl;
	std::cout << "2)Ввести новое имя(путь к фаилу)" << std::endl;
}
