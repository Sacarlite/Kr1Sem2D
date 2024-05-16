#include "pch.h"
#include "CppUnitTest.h"
#include "..\Kr1Sem2D\Kr1Sem2D\Book.cpp"
#include "..\Kr1Sem2D\Kr1Sem2D\Samplings.cpp"
#include <vector>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	private:
		Book book1 { "A����1", "��������1", "������������1", 2004,20};
		Book book2{ "A����1", "��������2", "������������1", 2005,20 };
		Book book3{ "A����2", "��������3", "������������2", 2006,20 };
		Book book4{ "A����3", "��������4", "������������3", 2007,20 };
		Book book5{ "A����4", "��������5", "������������4", 2008,20 };
	public:

	public:
		
		TEST_METHOD(TestMethod1)
		{
	
			std::vector<Book> books;
			books.push_back(book1);
			books.push_back(book2);
			books.push_back(book3);
			books.push_back(book4);
			books.push_back(book5);
			std::vector<Book> sortedApartments = SamplingBooksByAutor(books,"A����1");
			Assert::IsTrue(sortedApartments.at(0).GetName() == "��������1");
			Assert::IsTrue(sortedApartments.at(1).GetName() == "��������2");
			sortedApartments = SamplingBooksByAutor(books, "A����2");
			Assert::IsTrue(sortedApartments.at(0).GetName() == "��������3");
			sortedApartments = SamplingBooksByAutor(books, "A����3");
			Assert::IsTrue(sortedApartments.at(0).GetName() == "��������4");
			sortedApartments = SamplingBooksByAutor(books, "A����4");
			Assert::IsTrue(sortedApartments.at(0).GetName() == "��������5");
		}
		TEST_METHOD(TestMethod2)
		{
			std::vector<Book> books;
			books.push_back(book1);
			books.push_back(book2);
			books.push_back(book3);
			books.push_back(book4);
			books.push_back(book5);
			std::vector<Book> sortedApartments = SamplingBooksByPublisher(books, "������������1");
			Assert::IsTrue(sortedApartments.at(0).GetName() == "��������1");
			Assert::IsTrue(sortedApartments.at(1).GetName() == "��������2");
			sortedApartments = SamplingBooksByPublisher(books, "������������2");
			Assert::IsTrue(sortedApartments.at(0).GetName() == "��������3");
			sortedApartments = SamplingBooksByPublisher(books, "������������3");
			Assert::IsTrue(sortedApartments.at(0).GetName() == "��������4");
			sortedApartments = SamplingBooksByPublisher(books, "������������4");
			Assert::IsTrue(sortedApartments.at(0).GetName() == "��������5");
		}
		TEST_METHOD(TestMethod3)
		{
			std::vector<Book> books;
			books.push_back(book1);
			books.push_back(book2);
			books.push_back(book3);
			books.push_back(book4);
			books.push_back(book5);
			std::vector<Book> sortedApartments = SamplingBooksByYear(books, 2005);
			Assert::IsTrue(sortedApartments.at(0).GetName() == "��������3");
			Assert::IsTrue(sortedApartments.at(1).GetName() == "��������4");
			Assert::IsTrue(sortedApartments.at(2).GetName() == "��������5");
		}
		TEST_METHOD(TestMethod4)
		{
			std::vector<Book> books;
			books.push_back(book1);
			books.push_back(book2);
			books.push_back(book3);
			books.push_back(book4);
			books.push_back(book5);
			std::vector<Book> sortedApartments = SamplingBooksByYear(books, 2020);
			Assert::IsTrue(sortedApartments.empty());
		}
		TEST_METHOD(TestMethod5)
		{
			std::vector<Book> books;
			books.push_back(book1);
			books.push_back(book2);
			books.push_back(book3);
			books.push_back(book4);
			books.push_back(book5);
			std::vector<Book> sortedApartments = SamplingBooksByAutor(books, "�����6");
			Assert::IsTrue(sortedApartments.empty());
		}
	};
}
