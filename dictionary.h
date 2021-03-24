#pragma once
#include<string>
#include<algorithm>
#include<vector>

class dictionaryWord
{
	std::string word;
	std::string	meaning; 
	std::string synonym; //similar
	std::string antonym; //opposite
	std::string example_sentence;
public:
	dictionaryWord() {}
	dictionaryWord(std::string _word) { word = _word; }
	dictionaryWord(std::string _word, std::string _mean, std::string _syn, std::string _anto, std::string _ex);

	void setMeaning(std::string s);
	void setSynonym(std::string s);
	void setAntonym(std::string s);
	void setExample(std::string s);
	void display();

	std::string getWord();
	std::string getSynonym();
	std::string getAntonym();

	friend bool operator== (dictionaryWord w1, dictionaryWord w2);
	friend bool operator< (dictionaryWord w1, dictionaryWord w2);
};

void dictionary_menu();

void dictionary_program();

bool checkDuplicate(std::vector<dictionaryWord> dc, dictionaryWord nw);

void sortDictionary(std::vector<dictionaryWord>& dc);