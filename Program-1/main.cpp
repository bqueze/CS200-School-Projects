#include <iostream>
using namespace std;

int main()
{
	int num1, den1, num2, den2;                          //Main variables for the fraction.
	int multiA, multiB;                                  //Result variables for Multiplication.
	int diviA, diviB;                                    //Result variables for Division.
	int addiA, addiB, addiC, addiD;                      //Result variables for Addition.
	int whole1, whole2, whole3;                          //Variables to convert the results to whole number.

	//First Fraction Values
	cout << "FIRST FRACTION" << endl;
	cout << "Enter the value of the numerator: ";
	cin >> num1;
	cout << "Enter the value of the denominator: ";
	cin >> den1;
	cout << " " << endl;

	//Second Fraction Values
	cout << "SECOND FRACTION" << endl;
	cout << "Enter the value of the numerator: ";
	cin >> num2;
	cout << "Enter the value of the denominator: ";
	cin >> den2;
	cout << " " << endl;

	//Multiplying the fractions
	cout << "RESULTS" << endl;
	multiA = num1 * num2;
	multiB = den1 * den2;
	whole1 = multiA / multiB;       //To make the results a whole number.
	cout << num1 << "/" << den1 << " times " << num2 << "/" << den2 << " = " << multiA << "/" << multiB << " or " << whole1 << endl;

	//Dividing the fractions
	diviA = num1 * den2;
	diviB = den1 * num2;
	whole2 = diviA / diviB;         //To make the results a whole number.
	cout << num1 << "/" << den1 << " divided by " << num2 << "/" << den2 << " = " << diviA << "/" << diviB << " or " << whole2 << endl;

	//Adding the fractions
	addiA = num1 * den2;
	addiB = den1 * num2;
	addiC = den1 * den2;            //Acts as the common denominator.
	addiD = addiA + addiB;          //To make the results a whole number.
	whole3 = addiD / addiC;
	cout << num1 << "/" << den1 << " plus " << num2 << "/" << den2 << " = " << addiD << "/" << addiC << " or " << whole3 << endl;


	return 0;
}
