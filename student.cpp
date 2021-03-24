#include "student.h"
#include<iostream>


// student class member functions

student::student(std::string n, int num, float mk)
{
	name = n; studentNum = num; marks = mk;
}
void student::updateName(std::string n)
{
	name = n;
}
void student::updateNumber(int num)
{
	studentNum = num;
}
void student::updateMark(float mk)
{
	marks = mk;
}

std::string student::getName() { return name; }
int student::getNumber() { return studentNum; }
float student::getMark() { return marks; }

bool operator== (student s1, student s2)
{
	return s1.studentNum == s2.studentNum;
}

void student::print()
{
	std::cout << "student name: " << name << std::endl;
	std::cout << "student number: " << studentNum << std::endl;
	std::cout << "student OOP345 marks: " << marks << std::endl;
}


// hash table member functions
hashTable::hashTable()
{
	occupancy = 0;
	student s;
	students.assign(cap, s);
}

int hashTable::hash(unsigned int key)
{
	return key % cap;
}

// student number of empty spot will be marked as 0, deleted spot will be marked as -1
bool hashTable::find(unsigned int key, student& result)
{
	int index = hash(key);
	while (index < cap)
	{
		int num = students[index].getNumber();
		if (num == key)
		{
			result = students[index];
			return true;
		}
		else if (num==0)  //if reach a never used empty spot, break loop
		{
			break;
		}
		else
		{
			index++;
		}
	}
	return false;
}

void hashTable::insertion(student stu)
{
	if (occupancy >= cap) return;  // check if the array is fully occupied
	
	int key = stu.getNumber();
	int index = hash(key);
	while (index < cap)
	{
		if (students[index].getNumber() > 0) index++;  // move to next if spot taken
		else
		{
			students[index] = stu;  // copy value when find student number 0 or -1
			break;
		}
	}
	occupancy++;
}

void hashTable::deletion(student target)
{
	if (occupancy <= 0) return;  //no deletion if array is empty

	int key = target.getNumber();
	int index = hash(key);
	while (index < cap)
	{
		if (target == students[index])
		{
			students[index] = student();  // replace the record with a blank record;
			students[index].updateNumber(-1);  // mark it as deleted
			occupancy--;
			break;
		}
		else
		{
			index++;
		}
	}
	
}
bool hashTable::deletion(unsigned int target_key)
{
	if (occupancy <= 0) return false;

	student s;
	if (find(target_key, s))
	{
		deletion(s);
		std::cout << "\nrecord deleted.\n";
		return true;
	}
	else
	{
		std::cout<<"Deletion failed! The student does not exist.\n";
		return false;
	}
}

void hashTable::printAll()
{
	for (int i = 0; i < students.size(); i++)
	{
		if (students[i].getNumber() > 0) students[i].print();
	}
}

// utility functions

void hashTable_menu()
{
	std::cout << "\nThis is student menu:\n";
	std::cout << "1. add new student\n";
	std::cout << "2. find student by number\n";
	std::cout << "3. delete student by number\n";
	std::cout << "4. print all students\n";
	std::cout << "5. exit student program\n";
}

void hashTable_program()
{
	hashTable table;
	int c;

	while (1)
	{
		hashTable_menu();
		std::cout << "please enter your choice: ";
		std::cin >> c;
		switch (c)
		{
		case 1:
		{
			std::string name; int num; float mark;
			std::cout << "please enter student name:";
			std::getline(std::cin >> std::ws, name);
			std::cout << "please enter student number:";
			std::cin >> num;
			std::cout << "please enter student's OOP345 marks:";
			std::cin >> mark;
			student buffer= student(name, num, mark);
			table.insertion(buffer);
			break;
		}
		case 2:
		{
			int target; student stu;
			std::cout << "please enter a student number:";
			std::cin >> target;
			if (table.find(target, stu))
			{
				std::cout << "Record found!\n";
				stu.print();
			}
			else
			{
				std::cout << "No record match!\n";
			}
			break;
		}
		case 3:
		{
			int target;
			std::cout << "please enter the student number to be deleted:";
			std::cin >> target;
			table.deletion(target);
			break;
		}
		case 4:
		{
			table.printAll();
			break;
		}
		case 5:
		{
			std::cout << "Exiting...\n";
			return;
		}
		default:
		{
			std::cout << "Invalid input, please try again.\n";
			break;
		}
		}
	}
}