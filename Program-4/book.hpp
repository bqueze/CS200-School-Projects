#include <string>
using namespace std;

struct Book
{
	string title;
	string author;
	int id = 0;

	void setup(const string& newTitle, const string& newAuthor, int newId)
	{
		title = newTitle;
		author = newAuthor;
		id = newId;

	}

	string formatted()
	{
		string combined = title + " by " + "[" + author + "]";

		return combined;
	}
};
