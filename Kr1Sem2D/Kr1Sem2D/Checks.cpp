#include "Checks.h"
#include "CheckExeption.h"
#include <iostream>
#include <format>
#include <chrono>

int GetPositiveIntMoreThen0()
{
    while (true) {
        std::string str;
        std::cin >> str;
        try {
            int value = std::stoi(str);
            if (value > 0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return value;

            }
            else {
                throw std::exception();
            }
        }
        catch (std::exception&) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Были введены не корректные данные. Повторите ввод." << std::endl;
        }
        
    }
}

int GetYear()
{
    while (true) {
        std::string str;
        std::cin >> str;
        try {
            int value = std::stoi(str);
            if (value > 0&& value<=std::stoi(std::format("{:%Y}", std::chrono::system_clock::now()))) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return value;

            }
            else {
                throw std::exception();
            }
        }
        catch (std::exception&) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Были введены не корректные данные. Повторите ввод." << std::endl;
        }

    }
}

int SetMenuPoint()
{
    while (true) {
        std::string str;
        std::cin >> str;
        try {
            int value = std::stoi(str);
            if (value == 1 || value == 2|| value==3) 
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return value;

            }
            else {
                throw std::exception();
            }
        }
        catch (std::exception&) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Были введены не корректные данные. Повторите ввод." << std::endl;
        }
    }

}

bool isalpharus(char c)//Функция проверки на русские буквы
{
    return (c >= -64 && c <= -1) || c == -88 || c == -72;
}
std::string CheckLineS(std::ifstream& file)
{
    std::string temp_s = "";
    try
    {
        std::getline(file, temp_s);
        if (!temp_s.empty())
        {
            for (int i = 0; i < temp_s.size(); i++)
            {
                if (!isdigit(temp_s[i]) && !isalpharus(temp_s[i])  && temp_s[i] != '.' && temp_s[i] != ',' && temp_s[i] != ' ' )
                {
                    throw std::exception();
                }
            }
        }
        else
        {
            throw std::exception();
        }
       
        return temp_s;
       

    }
    catch (const std::exception&)
    {
        throw CheckException("Были введены не корректные данные. Повторите ввод.");
    }
}

std::string GetString()
{
    std::string temp_s = "";
    while (true)
    {
        try
        {
            getline(std::cin, temp_s);
            if (!temp_s.empty())
            {
                for (int i = 0; i < temp_s.size(); i++)
                {
                    if (!isdigit(temp_s[i]) && !isalpharus(temp_s[i]) && temp_s[i] != '.' && temp_s[i] != ',' && temp_s[i] != ' ')
                    {
                        throw std::exception();
                    }
                }
            }
            else
            {
                throw std::exception();
            }

            return temp_s;

        }
        catch (const std::exception&)
        {
            std::cout << "Были введены не корректные данные. Повторите ввод." << std::endl;
        }
    }
}
int CheckLineIntMoreThan0(std::ifstream& file)
{
    std::string temp_v = "";
    try
    {
        std::getline(file, temp_v);
        int temp_i = stoi(temp_v);
        if (temp_i <= 0)

        {
            throw  std::exception();
        }
        else

            return temp_i;
    }
    catch (const std::exception&)
    {
        throw CheckException("Произошла ошибка при чтении информации из фаила");
    }
    
}
int CheckLineYear(std::ifstream& file)
{
    std::string temp_v = "";
    try
    {
        std::getline(file, temp_v);
        int temp_i = stoi(temp_v);
        if (temp_i <= 0 && temp_i > std::stoi(std::format("{:%Y}", std::chrono::system_clock::now())))

        {
            throw  std::exception();
        }
        else

            return temp_i;
    }
    catch (const std::exception&)
    {
        throw CheckException("Произошла ошибка при чтении информации из фаила");
    }
}
int GetChoise()
{

    while (true) {
        std::string str;
        std::cin >> str;
        try {
            int value = std::stoi(str);
            if (value == 1 || value == 2) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return value;

            }
            else {
                throw std::exception();
            }
        }
        catch (std::exception&) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Были введены не корректные данные. Повторите ввод." << std::endl;
        }
    }
}

