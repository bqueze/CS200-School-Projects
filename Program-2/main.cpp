#include <iostream>
#include <stdlib.h>
using namespace std;

//declarations
void drawParameter(int length);
void displayMenu(int& round, int& playerHP, int& enemyHP);
void clearScreen();

int swordAttack();
int axeAttack();
int herbHeal();
int potionHeal();
int getChoice(int minimum, int maximum);
int attHealChoice(int minimum, int maximum);

//global variables
int pHP = 100;
int eHP = 100;

int main()
{
	bool done = false;

	int r = 0;

	while (!done)
	{
		int enemyChoice = rand() % 4;
		displayMenu(r, pHP, eHP);

		//checks the player choices
		switch (getChoice(1, 3))
		{

		//attack choice
		case 1:
			drawParameter(40);
			cout << "1. Attack With Sword" << "\t" << "2. Attack With Axe" << endl;

			switch (attHealChoice(1, 2))
			{
			case 1:
				cout << endl;
				eHP = eHP - swordAttack();

				cout << "You attacked your enemy with a sword for " << swordAttack() << " points" << endl;

				//enemy turn
				if (enemyChoice == 0)
				{
					pHP = pHP - swordAttack();

					cout << "The enemy attacked you with a sword for " << swordAttack() << " points." << endl;
				}
				else if (enemyChoice == 1)
				{
					eHP = eHP + herbHeal();

					cout << "The enemy healed itself with a herb for " << herbHeal() << " points." << endl;
				}

				else if (enemyChoice == 2)
				{
					pHP = pHP - axeAttack();

					cout << "The enemy attacked you with an axe for " << axeAttack() << " points." << endl;
				}
				else if (enemyChoice == 3)
				{
					eHP = eHP + herbHeal();

					cout << "The enemy healed itself with a potion for " << potionHeal() << " points." << endl;
				}

				break;

			case 2:
				cout << endl;
				eHP = eHP - axeAttack();

				cout << "You attacked your enemy with an axe for " << axeAttack() << " points" << endl;

				//enemy turn
				if (enemyChoice == 0)
				{
					pHP = pHP - swordAttack();

					cout << "The enemy attacked you with a sword for " << swordAttack() << " points." << endl;
				}
				else if (enemyChoice == 1)
				{
					eHP = eHP + herbHeal();

					cout << "The enemy healed itself with a herb for " << herbHeal() << " points." << endl;
				}

				else if (enemyChoice == 2)
				{
					pHP = pHP - axeAttack();

					cout << "The enemy attacked you with an axe for " << axeAttack() << " points." << endl;
				}
				else if (enemyChoice == 3)
				{
					eHP = eHP + herbHeal();

					cout << "The enemy healed itself with a potion for " << potionHeal() << " points." << endl;
				}

				break;
			}

			break;

		//heal choice
		case 2:
			drawParameter(40);
			cout << "1. Heal With Herb" << "\t" << "2. Heal With Potion" << endl;

			switch (attHealChoice(1, 2))
			{
			case 1:
				cout << endl;
				pHP = pHP + herbHeal();

				cout << "You healed yourself with a herb for " << herbHeal() << " points" << endl;

				//enemy turn
				if (enemyChoice == 0)
				{
					pHP = pHP - swordAttack();

					cout << "The enemy attacked you with a sword for " << swordAttack() << " points." << endl;
				}
				else if (enemyChoice == 1)
				{
					eHP = eHP + herbHeal();

					cout << "The enemy healed itself with a herb for " << herbHeal() << " points." << endl;
				}

				else if (enemyChoice == 2)
				{
					pHP = pHP - axeAttack();

					cout << "The enemy attacked you with an axe for " << axeAttack() << " points." << endl;
				}
				else if (enemyChoice == 3)
				{
					eHP = eHP + herbHeal();

					cout << "The enemy healed itself with a potion for " << potionHeal() << " points." << endl;
				}

				break;

			case 2:
				cout << endl;
				pHP = pHP + potionHeal();

				cout << "You healed yourself with a potion for " << potionHeal() << " points" << endl;

				//enemy turn
				if (enemyChoice == 0)
				{
					pHP = pHP - swordAttack();

					cout << "The enemy attacked you with a sword for " << swordAttack() << " points." << endl;
				}
				else if (enemyChoice == 1)
				{
					eHP = eHP + herbHeal();

					cout << "The enemy healed itself with a herb for " << herbHeal() << " points." << endl;
				}

				else if (enemyChoice == 2)
				{
					pHP = pHP - axeAttack();

					cout << "The enemy attacked you with an axe for " << axeAttack() << " points." << endl;
				}
				else if (enemyChoice == 3)
				{
					eHP = eHP + herbHeal();

					cout << "The enemy healed itself with a potion for " << potionHeal() << " points." << endl;
				}

				break;
			}

			break;

		case 3:
			done = true;

			break;
		}

		//checks the game if you won or lost
		if (pHP < 1)
		{
			cout << endl;
			cout << "YOU LOST THE BATTLE!" << endl;
			done = true;
		}
		else if (eHP < 1)
		{
			cout << endl;
			cout << "YOU WON THE BATTLE!" << endl;
			done = true;
		}

		drawParameter(40);
		system("pause");

		//clears the screen
		clearScreen();
	}

	return 0;
}

void drawParameter(int length)   //draws the line above
{
	for (int i = 0; i < length; i++)
	{
		cout << "-";
	}

	cout << endl;
}

void displayMenu(int& round, int& playerHP, int& enemyHP)   //displays the menu
{
	drawParameter(40);

	round++;

	cout << "Round: " << round << endl;
	cout << endl;
	cout << "Your HP: " << playerHP << "\t" << "Enemy HP: " << enemyHP << endl;
	cout << endl;
	cout << "1. Attack" << "\t" << "3. Quit" << endl;
	cout << "2. Heal" << endl;
	cout << endl;
	cout << "What do you want to do?" << endl;

}

void clearScreen()   //clears the screen
{
	system("cls");
}

int swordAttack()    //generates damage for sword attack
{
	int sword = rand() % 8 + 8;

	return sword;
}

int axeAttack()      //generates damage for axe attack
{
	int axe = rand() % 10 + 10;

	return axe;
}

int herbHeal()       //generates the healing amount for herb
{
	int herb = rand() % 8 + 8;

	return herb;
}

int potionHeal()     //generates the healing amount for potion
{
	int potion = rand() % 10 + 10;

	return potion;
}

int getChoice(int minimum, int maximum)    //checks if the first choice is valid
{
	int actualChoice;
	cin >> actualChoice;

	if (actualChoice < minimum)
	{
		cout << endl;
		cout << "You choosed an invalid choice." << endl;

		return actualChoice;
	}
	else if (actualChoice > maximum)
	{
		cout << endl;
		cout << "You choosed an invalid choice." << endl;

		return actualChoice;
	}


	return actualChoice;
}

int attHealChoice(int minimum, int maximum)   //checks if the second choice is valid
{
	int actualChoice;
	cin >> actualChoice;

	if (actualChoice < minimum)
	{
		cout << endl;
		cout << "You choosed an invalid choice." << endl;

		return actualChoice;
	}
	else if (actualChoice > maximum)
	{
		cout << endl;
		cout << "You choosed an invalid choice." << endl;

		return actualChoice;
	}


	return actualChoice;
}
