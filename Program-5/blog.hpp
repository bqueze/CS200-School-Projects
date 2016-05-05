#ifndef BLOG_HPP
#define BLOG_HPP

#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include "post.hpp"
#include "user.hpp"
#include "Menu_v2.hpp"
using namespace std;

class Blog
{
private:
	vector<User> m_userList;
	int m_currentUser;
	vector<Post> m_postList;

	void mainMenu()
	{
		bool done = false;

		while (!done)
		{
			Menu::Header("WELCOME TO BLAWGUR");

			Menu::ShowMenu({ "Register", "Log In", "Exit" }, true);

			cout << endl;
			int choice = Menu::GetValidChoice(1, 3, "");

			if (choice == 1)
			{
				Register();
			}

			else if (choice == 2)
			{
				login();
			}

			else if (choice == 3)
			{
				done = true;
			}
		}
	}

	void Register()
	{
		Menu::Header("REGISTER");

		cout << "Enter desired username: ";
		string username;
		cin >> username;

		User user(username);

		m_userList.push_back(user);
		m_currentUser = m_userList.size() - 1;

		saveFiles();
	}

	void login()
	{
		vector<string> usernameList;

		Menu::Header("USERS");
		
		for (int i = 0; i < m_userList.size(); i++)
		{
			cout << (i+1) << ". " << m_userList[i].getUsername() << endl;
			usernameList.push_back(m_userList[i].getUsername());
		}

		cout << endl;
		cout << "CHOOSE A USERNAME TO LOG IN" << endl;
		int choice = Menu::GetValidChoice(1, m_userList.size(), "");

		m_currentUser = choice;

		userMainMenu();
	}

	void userMainMenu()
	{

		bool done = false;

		while (!done)
		{
			Menu::Header("BLAWGUR HOME");

			Menu::ShowMenu({ "Add Post", "View Blog Wall", "Search", "Log Out" }, false);

			cout << endl;
			int choice = Menu::GetValidChoice(1, 4, "");
			cout << endl;

			if (choice == 1)
			{
				addPost();
			}

			else if (choice == 2)
			{
				wall();
			}

			else if (choice == 3)
			{
				search();
			}

			else if (choice == 4)
			{
				done = true;
			}
		}
	}

	void addPost()
	{
		string blogPost;
		string actualPost;

		cout << "Post Blog: " << endl;

		cin.ignore();
		while (getline(cin, blogPost) && blogPost != "DONE")
		{
			actualPost += blogPost + "\n";
		}

		Post post(actualPost, m_currentUser);
		m_postList.push_back(post);

		saveFiles();

		cout << endl;
	}

	void wall()
	{
		Menu::Header("BLOG WALL");

		bool done = false;

		while (!done)
		{
			for (int i = 0; i < m_postList.size(); i++)
			{
				cout << "POSTED BY: " << m_userList[m_postList[i].getAuthorId() - 1].getUsername() << endl;
				cout << m_postList[i].getContents() << endl;
				cout << "Press any character for next post: ";
				char next;
				cin >> next;
				cout << endl;

				Menu::DrawHorizontalBar(80);

				if (i == (m_postList.size() - 1))
				{
					cout << "That is the last post." << endl;
					cout << "Press any characters to continue to main menu." << endl;
					char choice;
					cin >> choice;
					cout << endl;

					done = true;
				}
			}
		}

		Menu::ClearScreen();
	}

	void search()
	{
		Menu::Header("SEARCH");

		cout << "1. Search a post" << endl;
		cout << "2. Search a user" << endl;

		int choice = Menu::GetValidChoice(1, 2, "");

		if (choice == 1)
		{
			string search;
			cout << "Search post: ";
			cin >> search;
			cout << endl;
			
			Menu::ClearScreen();
			Menu::Header("POSTS FOUND");

			for (int i = 0; i < m_postList.size(); i++)
			{
				string posts = m_postList[i].getContents();
				if (posts.find(search) != string::npos)
				{
					cout << "POSTED BY: " << m_userList[m_postList[i].getAuthorId() - 1].getUsername() << endl;
					cout << m_postList[i].getContents() << endl;
				}
			}
		}

		else if (choice == 2)
		{
			string search;
			cout << "Search user: ";
			cin >> search;
			cout << endl;

			Menu::ClearScreen();
			Menu::Header("USERS FOUND");

			for (int i = 0; i < m_userList.size(); i++)
			{
				string users = m_userList[i].getUsername();
				if (users.find(search) != string::npos)
				{
					cout << m_userList[i].getUsername() << endl;
				}
			}
		}
	}

	void loadFiles()
	{
		ifstream userInput("users.txt");

		string name;
		while (userInput >> name)
		{
			User newUser(name);
			m_userList.push_back(newUser);
		}

		userInput.close();

		ifstream postInput("posts.txt");

		string buffer;
		string post;
		int authorId;

		while (postInput >> buffer)
		{
			postInput >> authorId;
			post = "";
			buffer = "";

			postInput.ignore();
			while (buffer != "DONE")
			{
				if (buffer != "")
				{
					post += buffer + "\n";
				}
				getline(postInput, buffer);
			}

			Post newPost(post, authorId);
			m_postList.push_back(newPost);
		}

		postInput.close();
	}

	void saveFiles()
	{
		ofstream outputUsers("users.txt");

		for (int u = 0; u < m_userList.size(); u++)
		{
			outputUsers << m_userList[u].getUsername() << endl;
		}

		outputUsers.close();

		ofstream outputPosts("posts.txt");

		for (int p = 0; p < m_postList.size(); p++)
		{
			outputPosts << "AUTHOR_ID " << m_postList[p].getAuthorId() << "\n"
				<< "\n" << m_postList[p].getContents() << "\n" << "\n" << "DONE" << endl;
		}

		outputPosts.close();
	}

public:
	void run()
	{

		loadFiles();
		mainMenu();
	}
};

#endif // !BLOG_HPP
