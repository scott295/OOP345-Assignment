#pragma once
#include<string>
#include<algorithm>
#include<vector>

class book
{
	std::string author;
	std::string title;
	std::string date;
public:
	book(std::string _title="", std::string _author="", std::string _date="")
	{
		author = _author;
		title = _title;
		date = _date;
	}

	void setBook(std::string _title, std::string _author , std::string _date);
	std::string getAuthor() const;
	std::string getTitle() const;
	std::string getDate() const;
	void showBook();

	friend bool operator< (const book& book1, const book& book2);

	friend bool operator== (const book& book1, const book& book2);

};

void addNewBook(std::vector<book> &bs);

void sortBooks(std::vector<book> &bs);

void book_menu();

void book_program();
