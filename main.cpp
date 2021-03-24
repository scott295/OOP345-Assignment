#include "book.h"
#include "friend.h"
#include "dictionary.h"
#include "freqTable.h"
#include "student.h"

#include<iostream>

void main_menu()
{
	std::cout << "\nThis is main menu:\n";
	std::cout << "1. Books\n";
	std::cout << "2. Dictionary\n";
	std::cout << "3. Frequency Table\n";
	std::cout << "4. Linked List\n";
	std::cout << "5. Hash Table\n";
	std::cout << "6. EXIT\n";
	std::cout << "Please enter number to select a test program: ";
}


int main()
{
	int choice{ 0 };
	while (choice!=6)
	{
		main_menu();
		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{
			book_program();
			break;
		}
		case 2:
		{
			dictionary_program();
			break;
		}
		case 3:
		{
			frequencyTable_program();
			break;
		}
		case 4:
		{
			friendlist_program();
			break;
		}
		case 5:
		{
			hashTable_program();
			break;
		}
		case 6:
		{
			std::cout << "exiting...\n";
			break;
		}
		default:
			std::cout<<"Invalid input, please try again. \n";
		}


	}
	return 0;
}