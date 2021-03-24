#include"friend.h"
#include<iostream>

// myfriend members
std::string myfriend::getName() { return name; }

int myfriend::getAge() { return age; }

void myfriend::printFriend()
{
	std::cout << "My friend: " << name << " , " << age << " years old.\n";
}

void myfriend::setName(std::string n) { name = n; }

void myfriend::setAge(int a) { age = a; }

bool operator< (myfriend f1, myfriend f2)
{
	return f1.name < f2.name;
}

// link list program
void friend_menu()
{
	std::cout << "\nThis is friend link list menu:\n";
	std::cout << "1. insert a new friend\n";
	std::cout << "2. delete a friend\n";
	std::cout << "3. search friend\n";
	std::cout << "4. display all friends\n";
	std::cout << "5. Quit\n";
	std::cout << "please enter your choice: ";
}

bool searchFriend(std::list<myfriend> mf, const std::string target)
{
	std::list<myfriend>::iterator it;
	for (it = mf.begin(); it != mf.end(); it++)
	{
		if (it->getName() == target) return true;
	}
	return false;
}

bool searchFriend(std::list<myfriend> &mf, const std::string target, std::list<myfriend>::iterator &it)
{
	for (it = mf.begin(); it != mf.end(); it++)
	{
		if (it->getName() == target) return true;
	}
	return false;
}

std::list<myfriend>::iterator findPosition(std::list<myfriend>& mf, const myfriend &nf)
{
	std::list<myfriend>::iterator it= mf.begin();

	while (it != mf.end())
	{
		if (*it<nf)
		{
			it++;
		}
		else break;
	}
	return it;
}

void friendlist_program()
{
	std::list<myfriend> myfriends;
	int c;
	std::string sname ="";

	while (1)
	{
		std::list<myfriend>::iterator fit;
		friend_menu();
		std::cin >> c;
		switch (c)
		{
		case 1:
		{
			//inset 
			std::string n; int a;
			std::cout << "Please enter friend's name:";
			std::getline(std::cin >> std::ws, n);
			std::cout << "Please enter friend's age:";
			std::cin >> a;
			myfriend newfriend = myfriend(n, a);

			if (myfriends.size()>0)
			{
				fit = findPosition(myfriends, newfriend);
				myfriends.insert(fit, newfriend);
			}
			else
			{
				myfriends.push_back(newfriend);
			}
			break;
		}
		case 2:
		{
			//delete friend
			std::cout << "Please enter a name to delete:";
			std::getline(std::cin >> std::ws, sname);

			if (searchFriend(myfriends, sname))
			{
				searchFriend(myfriends, sname, fit);
				myfriends.erase(fit);
				std::cout << "\nfriend deleted\n";
			}
			else
			{
				std::cout << "\nNo such friend exist.\n";
			}
			break;
		}
		case 3:
		{
			// search friend
			std::cout << "Please enter a name to search:";
			std::getline(std::cin>>std::ws, sname);

			if ( searchFriend(myfriends, sname) )
			{
				std::cout << "\nfriend found\n";
				searchFriend(myfriends, sname, fit);
				fit->printFriend();
			}
			else
			{
				std::cout << "\nfriend not found!\n";
			}
			break;
		}
		case 4:
		{
			for (fit = myfriends.begin(); fit != myfriends.end(); fit++)
			{
				fit->printFriend();
			}
			break;
		}
		case 5:
		{
			std::cout << "exiting friend link list...\n";
			return;
		}
		default:
			std::cout << "Invalid choice, please try again.\n";
			break;
		}
	}
	
}