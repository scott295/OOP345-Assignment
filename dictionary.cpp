#include "dictionary.h"
#include<iostream>


// class member functions
dictionaryWord::dictionaryWord(std::string _word, std::string _mean, std::string _syn, std::string _anto, std::string _ex)
{
	word = _word;
	meaning = _mean;
	synonym = _syn;
	antonym = _anto;
	example_sentence = _ex;
}

void dictionaryWord::setMeaning(std::string s) { meaning = s; }
void dictionaryWord::setSynonym(std::string s) { synonym = s; }
void dictionaryWord::setAntonym(std::string s) { antonym = s; }
void dictionaryWord::setExample(std::string s) { example_sentence = s; }

std::string dictionaryWord::getWord() { return word; }
std::string dictionaryWord::getSynonym() { return synonym; }
std::string dictionaryWord::getAntonym() { return antonym; }

void dictionaryWord::display() //display the word
{
	std::cout << "Word: "<< word <<std::endl;
	std::cout << "Meaning: " << meaning << std::endl;
	std::cout << "Synonym: " << synonym << std::endl;
	std::cout << "Antonym: " << antonym << std::endl;
	std::cout << "Example: " << example_sentence << std::endl;
}

bool operator== (dictionaryWord w1, dictionaryWord w2)
{
	return w1.word == w2.word;
}

bool operator< (dictionaryWord w1, dictionaryWord w2)
{
	return w1.word < w2.word;
}

// utility functions
void dictionary_menu()
{
	std::cout << "\nThis is the dictionary menu:\n"
		<< "1. search word\n"
		<< "2. add new word of your own\n"
		<< "3. sort the words\n"
		<< "4. explore dictionary by alphabet order\n"
		<< "5. Exit\n";
	std::cout << "please enter your choice: ";
}

std::vector<dictionaryWord> d_initialization()
{
	std::vector<dictionaryWord> d;
	dictionaryWord word = dictionaryWord("apple", "a tasty fruit." , "", "", "An apple a day, keep doctor away.");
	d.push_back(word);
	word = dictionaryWord("baby", "newborn, little one", "child", "adult", "What a cute baby.");
	d.push_back(word);
	word = dictionaryWord("white","color of snow","blank","black","Princess Snow White is white as snow.");
	d.push_back(word);
	word = dictionaryWord("little","small, tiny, few","small","large","Little squirrel only needs a little foods.");
	d.push_back(word);

	return d;
}

void sortDictionary(std::vector<dictionaryWord>& dc)  // same logic as book sorting
{
	dictionaryWord dw;
	std::vector<dictionaryWord> temp;
	std::vector<dictionaryWord>::iterator it;

	while (!dc.empty())
	{
		dw = dc[0];

		for (it = dc.begin() + 1; it != dc.end(); it++)
		{
			if (*it < dw) dw = *it;
		}

		for (it = dc.begin(); it != dc.end(); it++)
		{
			if (*it == dw)
			{
				dc.erase(it);
				break;
			}
		}
		temp.push_back(dw);  
	}

	dc.swap(temp);
}

bool checkDuplicate(std::vector<dictionaryWord> dc, dictionaryWord nw)
{
	std::vector<dictionaryWord>::iterator it;
	for (it = dc.begin(); it != dc.end(); it++)
	{
		if (*it == nw) return true;
	}
	return false;
}

void dictionary_program() 
{
	std::vector<dictionaryWord> mydictionary = d_initialization();
	std::cout << "\nDictionary initialized\n";
	int c;

	while (1)
	{
		dictionary_menu();
		std::cin >> c;
		switch (c)
		{
		case 1:  // search word
		{
			std::string input;
			std::cout << "Please enter a word:";
			std::cin >> input;
			for (std::vector<dictionaryWord>::iterator it = mydictionary.begin(); it != mydictionary.end(); it++)
			{
				if (it->getWord() == input) { it->display(); break; }
			}
			break;
		}
		case 2:  //add new word
		{
			std::string word, mean, syn, anto, sentence;
			std::cout << "please enter your word:"; std::cin >> word;
			dictionaryWord w = dictionaryWord(word);
			if (checkDuplicate(mydictionary, w))
			{
				std::cout << "\nthis word already exist.\n";
				break;
			}
			std::cout << "please enter meaning for the word:"; std::getline(std::cin>>std::ws, mean);
			std::cout << "please enter its synonym:"; std::cin >> syn;
			std::cout << "please enter its antonym:"; std::cin >> anto;
			std::cout << "please enter example sentence:"; std::getline(std::cin >>std::ws, sentence);
			dictionaryWord newWord = dictionaryWord(word, mean, syn, anto, sentence);
			mydictionary.push_back(newWord);
			std::cout << "New word: " << (mydictionary.end() - 1)->getWord() << "is added to the dictionary.\n";
			break;
		}
		case 3:  // sort the dictionary
		{
			sortDictionary(mydictionary);
			std::cout << "sorting complete.\n";
			break;
		}
		case 4:
		{
			std::vector<dictionaryWord>::iterator it;
			for (it = mydictionary.begin(); it != mydictionary.end(); it++)
			{
				it->display();
			}
			std::cout << "\nEnd of dictionary.\n";
			break;
		}
		case 5:
		{
			std::cout << "exiting...\n";
			return;
		}
		default:
		{
			std::cout << "Please enter a valid number.\n";
			break;
		}

		}
	}


}