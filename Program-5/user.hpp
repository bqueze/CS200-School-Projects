#ifndef USER_HPP
#define USER_HPP

#include <iostream>
#include <string>
using namespace std;

class User
{
private:
	string m_username;

public:
	User(const string& name)
	{
		setUsername(name);
	}

	void setUsername(const string& name)
	{
		m_username = name;
	}

	string getUsername()
	{
		return m_username;
	}
};

#endif
