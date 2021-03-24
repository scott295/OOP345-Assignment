#include"book.h"
#include<iostream>

void book::showBook()
{
	std::cout << "Title: " << title << std::endl;
	std::cout << "Author: " << author << std::endl;
	std::cout << "Published in " << date << "\n\n";
}

void book::setBook(std::string _title, std::string _author, std::string _date)
{
	author = _author;
	title = _title;
	date = _date;
}
std::string book::getAuthor() const
{
	return author;
}
std::string book::getTitle() const
{
	return title;
}
std::string book::getDate() const
{
	return date;
}
bool operator< (const book& book1, const book& book2)
{
	return (book1.author < book2.author);
}
bool operator== (const book& book1, const book& book2)
{
	return (book1.author == book2.author 
			&& book1.title == book2.title
			&& book1.date == book2.date );
}

void addNewBook(std::vector<book> &bs)
{
	std::string s1, s2, s3;

	
	std::cout << "\nplease enter book title: ";
	std::getline(std::cin >> std::ws, s1);	 //first getline() will be skipped if no std::ws, don't know why
	
	std::cout << "please enter book author: ";
	std::getline(std::cin, s2);	
	
	std::cout << "please enter year of publish: ";
	std::getline(std::cin, s3);

	book b = book(s1, s2, s3);
	bs.push_back(b);
}

void sortBooks(std::vector<book> &bs)
{
	std::vector<book>::iterator it;
	std::vector<book> tempBooks;
	book buffer_bk;

	while (!bs.empty())
	{
		buffer_bk = bs[0]; // load first element to buffer

		//find out the smallest element and copy it to buffer book
		for (it=bs.begin()+1; it != bs.end(); it++) 
		{
			if (*it<buffer_bk) buffer_bk = *it;
		}

		//erase buffer value element from vector
		for (it = bs.begin(); it != bs.end(); it++)
		{
			if (*it == buffer_bk) 
			{
				bs.erase(it); 
				break;
			}
		}

		tempBooks.push_back(buffer_bk);  //push smallest element into tempBooks
		// elements in tempBooks will be in sorted order
		
	}
	
	bs.swap(tempBooks); 
}

void book_menu()
{
	std::cout << "\nThis is book menu:\n";
	std::cout << "1. Add new book \n";
	std::cout << "2. Sort books by author\n";
	std::cout << "3. Print all books \n";
	std::cout << "4. quite book testing\n";
	std::cout << "Please enter your choice: ";
}

void book_program()
{
	int c = 0;
	std::vector<book> books;

	while (1)
	{
		book_menu();
		std::cin >> c;
		switch (c)
		{
		case 1:
		{
			addNewBook(books);
			break;
		}
		case 2:
		{
			//sort books
			sortBooks(books);
			std::cout << "Book sorting completed.\n";
			break;
		}
		case 3:
		{
			//print books
			for (std::vector<book>::iterator it = books.begin(); it != books.end(); it++)
			{
				it->showBook();
			}
			break;
		}
		case 4:
		{
			std::cout << "exiting book testing...\n";
			return;
		}
		default:
			std::cout << "Invalid input, please try again\n";
		}
	}
}