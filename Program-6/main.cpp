#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include "SimpleTimer.hpp"

void LoadNames( vector<string>& nameList )
{
    ifstream input( "searchfile.txt" );
    string name;

    while ( input >> name )
    {
        nameList.push_back( name );
    }

    input.close();
    cout << nameList.size() << " names loaded" << endl;
}

int FindItem1( const string& searchTerm, vector<string>& nameList )
{
	for (int i = 0; i < nameList.size(); i++)
	{
		if (nameList[i] == searchTerm)
		{
			return i;
		}
	}

	return -1;
}

int FindItem2( const string& searchTerm, vector<string>& nameList )
{
	int center = nameList.size() / 2;

	if (nameList[center] == searchTerm)
	{
		return center;
	}	

	else if (nameList[center] < searchTerm)
	{
		for (int i = 0; i < center; i++)
		{
			if (nameList[i] == searchTerm)
			{
				return i;
			}
		}
	}

	else if (nameList[center] > searchTerm)
	{
		for (int i = center; i < nameList.size(); i++)
		{
			if (nameList[i] == searchTerm)
			{
				return i;
			}
		}
	}

	return -1;
}

void QuickSort( vector<string>& arr, int left, int right )
{
	int i = left;
	int j = right;
	string pivot = arr[(left + right) / 2];
	string value;

	while (i <= j)
	{
		while (arr[i] < pivot)
		{
			i++;
		}

		while (arr[j] > pivot)
		{
			j--;
		}

		if (i <= j)
		{
			value = arr[i];
			arr[i] = arr[j];
			arr[j] = value;
			i++;
			j--;
		}
	}

	if (left < j)
	{
		QuickSort(arr, left, j);
	}

	if (right > i)
	{
		QuickSort(arr, i, right);
	}
}

void ShellSort( vector<string>& arr, int size )
{
	int gap = size / 2;

	for (int gap = size / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < size; i++)
		{
			string value = arr[i];
			int j = i;

			for (; j >= gap && value < arr[j - gap]; j -= gap)
			{
				arr[j] = arr[j - gap];
			}

			arr[j] = value;
		}
	}
}

int main()
{
	cout << "0. Loading Names..." << endl;

    vector<string> nameList;
    LoadNames( nameList );

    SimpleTimer timer;
    int foundIndex;

    /* EXERCISE 1: LINEAR SEARCH (< 1 second) */
    cout << endl << "1. Simple Search" << endl;
    timer.Start();
    foundIndex = FindItem1( "CIOKAIAMHHUXQ", nameList );
    cout    << "Found at index " << foundIndex << "\t" << "Elapsed time: " << timer.GetElapsed() << endl;

    /* EXERCISE 2: SHELL SORT () */
    cout << endl << "2. Shell Sort" << endl;
    vector<string> sortedList1 = nameList;
    timer.Start();
    ShellSort( sortedList1, sortedList1.size() );
    cout    << "Elapsed time: " << timer.GetElapsed() << endl;

    /* EXERCISE 3: QUICK SORT () */
    cout << endl << "3. Quick Sort" << endl;
    vector<string> sortedList2 = nameList;
    timer.Start();
    QuickSort( sortedList2, 0, sortedList2.size() - 1 );
    cout    << "Elapsed time: " << timer.GetElapsed() << endl;

    /* EXERCISE 4: SEARCHING A SORTED LIST */
    // Linear Search
    cout << endl << "4. Searching a sorted list" << endl;
    timer.Start();
    foundIndex = FindItem1( "CIOKAIAMHHUXQ", sortedList2 );
    cout    << "Found at index " << foundIndex << "\t" << "Elapsed time: " << timer.GetElapsed() << endl;

    // You will write your own search algorithm
    timer.Start();
    foundIndex = FindItem2( "CIOKAIAMHHUXQ", sortedList2 );
    cout    << "Found at index " << foundIndex << "\t" << "Elapsed time: " << timer.GetElapsed() << endl;

    timer.Start();
    foundIndex = FindItem2( "MUBEYRZYEITF", sortedList2 );
    cout    << "Found at index " << foundIndex << "\t" << "Elapsed time: " << timer.GetElapsed() << endl;

    timer.Start();
    foundIndex = FindItem2( "YEIS", sortedList2 );
    cout    << "Found at index " << foundIndex << "\t" << "Elapsed time: " << timer.GetElapsed() << endl;

    timer.Start();
    foundIndex = FindItem2( "ZIKZANH", sortedList2 );
    cout    << "Found at index " << foundIndex << "\t" << "Elapsed time: " << timer.GetElapsed() << endl;

    return 0;
}
