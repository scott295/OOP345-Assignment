#pragma once
#include<string>
#include<algorithm>
#include<vector>


class student
{
	std::string name;
	int studentNum;
	float marks;
public:
	student() { name = ""; studentNum = 0; marks = 0; }
	student(std::string n, int num, float mk);
	void updateName(std::string n);
	void updateNumber(int num);
	void updateMark(float mk);

	std::string getName();
	int getNumber();
	float getMark();

	void print();

	friend bool operator== (student s1, student s2);
};

const int cap = 51;
class hashTable   
{
	std::vector<student> students;
	int occupancy;
protected:
	int hash(unsigned int key);
	void deletion(student target);
public:
	hashTable();
	bool find(unsigned int key, student& result);
	void insertion(student stu);
	bool deletion(unsigned int target);

	void printAll();
	// my hash table doesn't implement any cluster solution as it's a small table and easy for liner search.
};

void hashTable_menu();
void hashTable_program();