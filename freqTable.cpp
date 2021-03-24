#include "freqTable.h"
#include<iostream>
#include<cctype>
#include<fstream>

// class member functions
frequencyTable::frequencyTable(std::map<std::string, int> _table)
{
    table = _table;
}
void frequencyTable::setTable(std::map<std::string, int> _table)
{
    table = _table;
}
void frequencyTable::printTable()
{
    std::map<std::string, int>::iterator it;
    std::cout << "\nwords and frequency(times):\n";
    for (it= table.begin(); it != table.end(); it++)
    {
        std::cout << it->first << "  " << it->second << std::endl;
    }
    std::cout << "End of table.\n";
}
int frequencyTable::frequency(std::string str)
{
    std::map<std::string, int>::iterator it;
    int i=0;
    for (it= table.begin(); it != table.end(); it++)
    {
        if (it->first==str) {i=it->second; break;}
    }
    return i;
}
bool frequencyTable::searchWords(int i, std::list<std::string> &result)
{
    size_t size =result.size();  
    //user should pass empty list, but in case user pass a list with elements, comparing list size of origin and the end can help determine boolean result
    std::map<std::string,int>::iterator it;
    for (it=table.begin();it!=table.end();it++)
    {
        if (it->second==i) result.push_back(it->first);
    }
    if (size==result.size())return false;  // if the list size not change, means no such value found in the table
    else return true;
}

// utility functions
std::list<std::string> readFile(std::string fileName)  //extract word and put into list
{
    char c;
    std::string buffer;
    std::list<std::string> words;
    std::ifstream file(fileName);
    
    while (!file.eof())
    {
        file.get(c);
        if (!ispunct(c)&&!iswspace(c)) 
        {
            c= tolower(c);
            buffer.push_back(c);
            
        }
        else if ((ispunct(c)||iswspace(c)) &&buffer!="") 
        {
            words.push_back(buffer);
            buffer="";    
        }
        
    }
    file.close();
    return words;
}


std::map<std::string, int> countingWord(std::list<std::string> words)
{
    std::map<std::string, int> table;
    std::list<std::string>::iterator it;
    it=words.begin();
    std::string key; int count;
    while (it!=words.end())
    {
        key = *it; count=0;
        if (table.count(key)>0) it++;
        else
        {
            for (std::list<std::string>::iterator it2 = words.begin(); it2!=words.end(); it2++)
            {
                if (key==*it2) count++;
            }
            table[key]=count;
            it++;
        }
    }
    return table;
}

std::map<std::string, int> makeTable()
{
    std::map<std::string, int> table;
    std::list<std::string> words;
    std::string fileName;
    
    while(1)  // loop to get a valid file name
    {
        std::cout<<"Please enter your file name:";
        std::getline(std::cin>>std::ws, fileName);

        std::ifstream check(fileName);
        if (!check.good()) 
        {
            std::cout<<"Your file does not exist!\n";
        }
        else 
        {
            std::cout<<"loading your file...\n";
            break;
        }
    }

    words= readFile(fileName);
    std::cout<<"file loading complete.\n";

    table= countingWord(words);
    std::cout<<"word counting complete.\n";

    return table;
}

void table_menu()
{
    std::cout<<"\nThis is frequency table maker.\n";
    std::cout<<"1. add new file for frequency counting\n"
            <<"2. print frequency table for last file\n"
            <<"3. print all tables\n"
            <<"4. Exit\n";
    std::cout<<"please enter your choice:";
}

void frequencyTable_program()
{
    std::list<frequencyTable> tables;
    int c;

    while(1)
    {
        table_menu();
        std::cin>>c;

        switch (c)
        {
        case 1: //get a file name and make a frequency table object
        {
            std::cout << "\nplease ensure your target file is in the same folder of the program.\n";
            frequencyTable t = frequencyTable(makeTable());
            tables.push_front(t);
            break;
        }
        case 2:
        {
            std::list<frequencyTable>::iterator it= tables.begin();
            it->printTable();
            break;
        }
        case 3:
        {
            std::cout<<"Starting to print all tables from most recent added...\n";
            std::list<frequencyTable>::iterator it;
            for (it=tables.begin(); it!=tables.end(); it++)
            {
                it->printTable();
            }
            std::cout<<"All table printing complete\n";
            break;
        }
        case 4:
        {
            std::cout<<"Exiting frequency table program...\n";
            return;
        }
        default:
        {
            std::cout<<"Invalid input!\n";
            break;
        }
        }
    }

}