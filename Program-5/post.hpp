#ifndef POST_HPP
#define POST_HPP

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Post
{
private:
	string m_contents;
	int m_authorId;

public:
	Post()
	{

	}
	Post(const string& contents, int authorId)
	{
		setContents(contents);
		setAuthorId(authorId);
	}

	void setContents(const string& contents)
	{
		m_contents = contents;
	}

	void setAuthorId(int id)
	{
		m_authorId = id;
	}

	string getContents()
	{
		return m_contents;
	}

	int getAuthorId()
	{
		return m_authorId;
	}
};

#endif
