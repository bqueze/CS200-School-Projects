#include <iostream>
#include <string>
using namespace std;

//declarations
int getUserInput(int minimum, int maximum);
void displayMenu();
void drawParameter(int length);
void addClass(string classTitles[10], string classSchedules[10], int classStudentCount[10], int& classCount);
void removeLastClass(string classTitles[10], string classSchedules[10], int classStudentCount[10], int& classCount);
void clearClasses(string classTitles[10], string classSchedules[10], int classStudentCount[10], int& classCount);
void updateClasses(string classTitles[10], string classSchedules[10], int classStudentCount[10], int& classCount);
void viewAllClasses(string classTitles[10], string classSchedules[10], int classStudentCount[10], int& classCount);

int main()
{
	string classTitles[10];
	string classSchedules[10];
	int classStudentCount[10];
	int classCount = 0;
	bool done = false;

	while (!done)
	{
		displayMenu();

		cout << endl;
		cout << "What do you want to do?" << endl;

		int choice = getUserInput(1, 6);

		if (choice == 1)
		{
			addClass(classTitles, classSchedules, classStudentCount, classCount);
		}
		else if (choice == 2)
		{
			removeLastClass(classTitles, classSchedules, classStudentCount, classCount);
		}
		else if (choice == 3)
		{
			clearClasses(classTitles, classSchedules, classStudentCount, classCount);
		}
		else if (choice == 4)
		{
			updateClasses(classTitles, classSchedules, classStudentCount, classCount);
		}
		else if (choice == 5)
		{
			viewAllClasses(classTitles, classSchedules, classStudentCount, classCount);
		}
		else if (choice == 6)
		{
			done = true;
		}
	}

	return 0;
}

int getUserInput(int minimum, int maximum)
{
	int actualChoice;
	cin >> actualChoice;

	while (actualChoice < minimum || actualChoice > maximum)
	{
		cout << endl;
		cout << "INVALID CHOICE!" << endl;
		cout << "Choose a valid choice: " << endl;
		cin >> actualChoice;
	}

	return actualChoice;
}

void displayMenu()
{
	drawParameter(30);

	cout << endl;
	cout << "School System" << endl;
	cout << endl;
	cout << "1. Add Class" << endl;
	cout << "2. Remove Last Class" << endl;
	cout << "3. Clear Classes" << endl;
	cout << "4. Update Class" << endl;
	cout << "5. View All Classes" << endl;
	cout << "6. Exit" << endl;
}

void drawParameter(int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << "-";
	}

	cout << endl;
}

void addClass(string classTitles[10], string classSchedules[10], int classStudentCount[10], int& classCount)
{
	int maxCount = 10;

	if (classCount < 10)
	{
		drawParameter(30);

		cout << endl;
		cout << "ADD CLASS" << endl;
		cout << "Class Title: ";
		string cTitle;
		cin.ignore();
		getline(cin, cTitle);

		classTitles[classCount] = cTitle;

		cout << "Student Count: ";
		int sCount;
		cin >> sCount;

		classStudentCount[classCount] = sCount;

		cout << "Class Schedule: ";
		string cSched;
		cin.ignore();
		getline(cin, cSched);

		classSchedules[classCount] = cSched;

		classCount++;

		cout << endl;

		cout << "CLASS ADDED!" << endl;
	}
	else
	{
		drawParameter(30);

		cout << endl;
		cout << "CLASS LIST IS FULL!" << endl;
	}

	cout << endl;
}

void removeLastClass(string classTitles[10], string classSchedules[10], int classStudentCount[10], int& classCount)
{
	if (classCount <= 0)
	{
		cout << "CLASS LIST IS ALREADY EMPTY!" << endl;
	}
	else if (classCount > 0)
	{
		int newCCount = classCount - 1;

		classCount = newCCount;

		cout << "LAST CLASS REMOVED!" << endl;
	}
}

void clearClasses(string classTitles[10], string classSchedules[10], int classStudentCount[10], int& classCount)
{
	if (classCount <= 0)
	{
		cout << "CLASS LIST IS ALREADY EMPTY!" << endl;
	}
	else if (classCount > 0)
	{
		int newCCount = classCount - classCount;

		classCount = newCCount;

		cout << "CLASSES CLEARED!" << endl;
	}
}

void updateClasses(string classTitles[10], string classSchedules[10], int classStudentCount[10], int& classCount)
{
	drawParameter(30);
	cout << endl;

	if (classCount > 0)
	{
		cout << "CLASS LIST" << endl;

		for (int showClasses = 0; showClasses < classCount; showClasses++)
		{
			cout << showClasses << ". " << "CLASS NAME: " << classTitles[showClasses] << ", STUDENTS: " << classStudentCount[showClasses] << ", SCHEDULE: " << classSchedules[showClasses] << endl;
		}
		cout << endl;
		cout << "UPDATE CLASS" << endl;
		cout << "Which class do you want to update? ";

		int choice = getUserInput(0, classCount - 1);

		cout << endl;
		cout << "New Class Title: ";
		string nTitle;
		cin.ignore();
		getline(cin, nTitle);

		classTitles[choice] = nTitle;

		cout << "New Student Count: ";
		int nCount;
		cin >> nCount;

		classStudentCount[choice] = nCount;

		cout << "New Class Schedule: ";
		string nSched;
		cin.ignore();
		getline(cin, nSched);

		classSchedules[choice] = nSched;

		cout << "CLASS UPDATED!" << endl;
	}
	else
	{
		cout << "THERE ARE NO CLASSES!" << endl;
	}

	cout << endl;
}

void viewAllClasses(string classTitles[10], string classSchedules[10], int classStudentCount[10], int& classCount)
{
	drawParameter(30);
	cout << endl;

	if (classCount > 0)
	{
		cout << "CLASS LIST" << endl;

		for (int showClasses = 0; showClasses < classCount; showClasses++)
		{
			cout << showClasses << ". " << "CLASS NAME: " << classTitles[showClasses] << ", STUDENTS: " << classStudentCount[showClasses] << ", SCHEDULE: " << classSchedules[showClasses] << endl;
		}
	}
	else
	{
		cout << "CLASS LIST IS EMPTY!" << endl;
	}

	cout << endl;
}
