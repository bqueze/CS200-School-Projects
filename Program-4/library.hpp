#include "book.hpp"
#include <fstream>
#include <iostream>
using namespace std;

struct Library
{
	Book bookList[80];
	int listSize;
	int bookCount;

	void initLibrary()
	{
		bookCount = 0;

		ifstream input("library.txt");

		string tempvar;  //temporary variable to skip headers
		input >> tempvar;  //skipping headers
		input >> tempvar;
		input >> tempvar;

		//names
		string first;
		string middle;
		string last;

		while (
			input
			>> bookList[bookCount].id
			>> bookList[bookCount].title
			>> first
			>> middle
			>> last
			)
		{
			bookList[bookCount].author = first + " " + middle + " " + last;
			bookCount++;
		}

		listSize = 80;

		input.close();
	}

	//library menus
	void run()
	{
		bool done = false;

		while (!done)
		{
			int choice;
			choice = mainMenu();

			if (choice == 1)
			{
				runPublic();
			}

			else if (choice == 2)
			{
				runAdmin();
			}

			else if (choice == 3)
			{
				done = true;
			}
		}
	}

	int mainMenu()
	{
		cout << "LIBRARY SYSTEM ACCESS" << endl;
		cout << "1. Public Access" << endl;
		cout << "2. Admin Access" << endl;
		cout << "3. Exit" << endl;

		int choice = getValidInput(1, 3);

		return choice;
	}

	void runAdmin()
	{
		int choice = adminMenu();

		if (choice == 1)
		{
			updateBook();
		}

		else if (choice == 2)
		{
			addBook();
		}

		else if (choice == 3)
		{
			saveLibrary();
		}
	}

	int adminMenu()
	{
		cout << "ADMIN CONTROL PANEL" << endl;
		cout << "1. Update Book" << endl;
		cout << "2. Add Book" << endl;
		cout << "3. Export Database" << endl;

		int choice = getValidInput(1, 3);
		return choice;
	}

	void runPublic()
	{
		int choice = publicMenu();

		if (choice == 1)
		{
			searchByTitle();
		}

		else if (choice == 2)
		{
			searchByAuthor();
		}
	}

	int publicMenu()
	{
		cout << "WELCOME TO THE LIBRARY" << endl;
		cout << "1. Search By Title" << endl;
		cout << "2. Search By Author" << endl;

		int choice = getValidInput(1, 2);
		return choice;
	}

	//specific functionalities
	void addBook() // not complete yet
	{
		int avSlot = bookCount; //available slots
		int alSlot = listSize; //all slots

		cout << "ADD BOOK" << endl;
		cout << avSlot << "\t" << alSlot << endl;

		if (bookCount == listSize)
		{
			cout << "ERROR: The books are already full!" << endl;
			cout << endl;
		}

		else if (bookCount <= listSize)
		{
			updateBook(bookCount);
			bookList[bookCount].id = bookList[bookCount - 1].id + 1;
			bookCount++;
		}
	}

	void updateBook(int index)
	{
		string title;
		cout << "Title: ";
		cin >> title;

		string author;
		string first, middle, last;
		cout << "Author Name" << endl;
		cout << "First: ";
		cin >> first;
		cout << "Middle: ";
		cin >> middle;
		cout << "Last: ";
		cin >> last;
		author = first + " " + middle + " " + last;
		cout << endl;

		bookList[index].title = title;
		bookList[index].author = author;
	}

	void updateBook()
	{
		cout << "IDX" << "\t" << "ID" << "\t" << "TITLE" << "\t" << "\t" << "\t" << "AUTHOR" << endl;

		int index = selectBook();
		updateBook(index);
	}

	void searchByTitle()
	{
		cout << "SEARCH BY BOOK TITLE" << endl;
		cout << "Search title: ";
		string chosentitle;
		cin >> chosentitle;
		cout << endl;
		cout << "RESULTS" << endl;

		for (int i = 0; i < bookCount; i++)
		{
			string booktitle = bookList[i].title;
			if (booktitle.find(chosentitle) != string::npos)
			{
				cout << "(" << bookList[i].id << ")" << ": " << bookList[i].formatted() << endl;
			}
		}

		cout << endl;
	}

	void searchByAuthor()
	{
		cout << "SEARCH BY AUTHOR" << endl;
		cout << "Search author: ";
		string chosenauthor;
		cin >> chosenauthor;
		cout << endl;
		cout << "RESULTS" << endl;

		for (int i = 0; i < bookCount; i++)
		{
			string bookauthor = bookList[i].author;
			if (bookauthor.find(chosenauthor) != string::npos)
			{
				cout << "(" << bookList[i].id << ")" << ": " << bookList[i].formatted() << endl;
			}
		}

		cout << endl;
	}

	void saveLibrary()
	{
		ifstream input("library.txt");
		ofstream output("library.txt");

		output << "ID" << "\t" << "TITLE" << "\t" << "\t" << "\t" << "AUTHOR" << endl;

		for (int i = 0; i < bookCount; i++)
		{
			output << bookList[i].id << "\t" << bookList[i].title << "\t" << "\t" << bookList[i].author<< endl;
		}

		input.close();
		output.close();
	}

	int getValidInput(int minimum, int maximum)
	{
		int choice;
		cout << "Choice: ";
		cin >> choice;
		cout << endl;

		while (choice < minimum || choice > maximum)
		{
			cout << "Please enter a valid choice." << endl;
			cout << "Choice: ";
			cin >> choice;
			cout << endl;
		}

		return choice;
	}

	int selectBook()
	{
		int increment = 20;
		int pages = bookCount / increment;
		int loop = 0; //variable for infinite loop

		while (loop != 1)
		{
			for (int p = 0; p < pages + 1; p++)
			{
				int first = p*increment;
				int last = p*increment + increment;

				for (int i = first; i < last; i++)
				{
					cout << i << "\t" << bookList[i].id << "\t" << bookList[i].title << "\t" << "\t" << bookList[i].author << endl;
				}

				cout << "OR ENTER ANYTHING ELSE TO GO TO NEXT PAGE" << endl;
				int index;
				cin >> index;
				cout << endl;

				if (index >= first && index < last)
				{
					return index;
				}
			}
		}
	}
};
