#pragma once
#include <string>
/*
����� ����� � ���������� ������: �����, ��������, ������������, ���, ���������� �������
*/
class Book//����� �����
{
private:
	std::string _autor{};//���� �����
	std::string _name{};//���� ��������
	std::string _publisher{};//���� ������������
	int _year = 0;//���� ����
	int _amountOfPages = 0;//���� ���������� �������
public:
	Book() = default;//����������� �� ���������
	Book(std::string autor, std::string name, std::string publisher, int year, int amountOfPages);//�����������

	void SetAutor(std::string autor);//��������� ���� �����
	std::string GetAutor();//������� �������� ���� �����
	void ShowAutor();//����� �� ������� ���� �����

	void SetName(std::string name);//��������� ���� ��������
	std::string GetName();//������� �������� ���� ��������
	void ShowName();//����� �� ������� ���� ��������

	void SetPublisher(std::string publisher);//��������� ���� ������������
	std::string GetPublisher();//������� �������� ���� ������������
	void ShowPublisher();//����� �� ������� ���� ������������

	void SetYear(int year);//��������� ���� ����
	int GetYear();//������� �������� ���� ����
	void ShowYear();//����� �� ������� ���� ����

	void SetAmountOfPages(int amountOfPages);//��������� ���� ���������� �������
	int GetAmountOfPages();//������� �������� ���� ���������� �������
	void ShowAmountOfPages();//����� �� ������� ���� ���������� �������
};
