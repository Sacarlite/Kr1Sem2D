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
		Book book1 { "Aвтор1", "Название1", "Издательство1", 2004,20};
		Book book2{ "Aвтор1", "Название2", "Издательство1", 2005,20 };
		Book book3{ "Aвтор2", "Название3", "Издательство2", 2006,20 };
		Book book4{ "Aвтор3", "Название4", "Издательство3", 2007,20 };
		Book book5{ "Aвтор4", "Название5", "Издательство4", 2008,20 };
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
			std::vector<Book> sortedApartments = SamplingBooksByAutor(books,"Aвтор1");
			Assert::IsTrue(sortedApartments.at(0).GetName() == "Название1");
			Assert::IsTrue(sortedApartments.at(1).GetName() == "Название2");
			sortedApartments = SamplingBooksByAutor(books, "Aвтор2");
			Assert::IsTrue(sortedApartments.at(0).GetName() == "Название3");
			sortedApartments = SamplingBooksByAutor(books, "Aвтор3");
			Assert::IsTrue(sortedApartments.at(0).GetName() == "Название4");
			sortedApartments = SamplingBooksByAutor(books, "Aвтор4");
			Assert::IsTrue(sortedApartments.at(0).GetName() == "Название5");
		}
		TEST_METHOD(TestMethod2)
		{
			std::vector<Book> books;
			books.push_back(book1);
			books.push_back(book2);
			books.push_back(book3);
			books.push_back(book4);
			books.push_back(book5);
			std::vector<Book> sortedApartments = SamplingBooksByPublisher(books, "Издательство1");
			Assert::IsTrue(sortedApartments.at(0).GetName() == "Название1");
			Assert::IsTrue(sortedApartments.at(1).GetName() == "Название2");
			sortedApartments = SamplingBooksByPublisher(books, "Издательство2");
			Assert::IsTrue(sortedApartments.at(0).GetName() == "Название3");
			sortedApartments = SamplingBooksByPublisher(books, "Издательство3");
			Assert::IsTrue(sortedApartments.at(0).GetName() == "Название4");
			sortedApartments = SamplingBooksByPublisher(books, "Издательство4");
			Assert::IsTrue(sortedApartments.at(0).GetName() == "Название5");
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
			Assert::IsTrue(sortedApartments.at(0).GetName() == "Название3");
			Assert::IsTrue(sortedApartments.at(1).GetName() == "Название4");
			Assert::IsTrue(sortedApartments.at(2).GetName() == "Название5");
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
			std::vector<Book> sortedApartments = SamplingBooksByAutor(books, "Автор6");
			Assert::IsTrue(sortedApartments.empty());
		}
	};
}
