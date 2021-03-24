#pragma once
#include<string>
#include<list>
#include<algorithm>


class myfriend
{
	std::string name;
	int age;
public:
	myfriend() { name = ""; age = 0; }
	myfriend(std::string _name, int _age) { name = _name; age = _age; }

	std::string getName();
	int getAge();
	void printFriend();
	void setName(std::string n);
	void setAge(int a);

	friend bool operator< (myfriend f1, myfriend f2);
};

void friend_menu();

void friendlist_program();

bool searchFriend(std::list<myfriend> mf, const std::string target);
bool searchFriend(std::list<myfriend> &mf, const std::string target, std::list<myfriend>::iterator &it);

std::list<myfriend>::iterator findPosition(const std::list<myfriend> &mf, const myfriend &nf);