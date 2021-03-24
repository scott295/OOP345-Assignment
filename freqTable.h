#pragma once
#include<string>
#include<list>
#include<map>

class frequencyTable
{
	std::map<std::string, int> table;
public:
	frequencyTable(){}
	frequencyTable(std::map<std::string, int> _table);
	void setTable(std::map<std::string, int> _table);
	void printTable();
	int frequency(std::string str);
	bool searchWords(int i, std::list<std::string> &result);
};

void frequencyTable_program();

std::list<std::string> readFile(std::string fileName);

std::map<std::string, int> countingWord(std::list<std::string> words);

std::map<std::string, int> makeTable();

void table_menu();
