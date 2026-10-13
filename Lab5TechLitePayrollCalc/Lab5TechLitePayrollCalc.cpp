/*
Developer: Luke Jany
Date: 10/15/2026
Purpose: Develop a program that calculates the payroll for employees of TechLite
Course/Section: CSCN111-005
*/

// Preprocessor statements
#include <iostream> // always included
#include <iomanip> // Required for stream manipulators
#include <fstream> // file operations
#include <string> // Used for multi-char display
#include <cstdlib> //C standard library
using namespace std;

// Declaring constant variables
const double HOURLY_RATE = 15.00;
const double DAILY_RATE = 100.00;
const int DAYS_IN_WEEK = 7;

int main() {

	// regular variables
	int userInput;
	string userFile;
	int totalHours = 0;
	double grossPay;
	int noOrYes;
	bool stillRun = true;


	cout << "==================================================================" << endl;
	cout << "                   TECHLITE PAYROLL CALCULATOR                    " << endl;
	cout << "==================================================================" << endl;
	cout << endl << endl;
	cout << "Welcome to the payroll calculator for TechLite!" << endl;
	cout << "The menu below provides the possible options to choose to determine employees hours and pay." << endl << endl;
	cout << fixed << setprecision(2);

	//loops till quit option is selected
	do {
		//resets variables
		grossPay = 0;
		totalHours = 0;

		//menu for users
		cout << "------------------------------------------------------------------" << endl;
		cout << "Please select from one of the following options." << endl;
		cout << "1. File input for employee hours" << endl;
		cout << "2. Manual entry for employee hours" << endl;
		cout << "3. Flat rate employees" << endl;
		cout << "4. Quit" << endl;
		cout << "------------------------------------------------------------------" << endl;
		cout << "Selection: ";
		cin >> userInput;
		cin.ignore(1000, '\n'); //ignores any extra info that would mess up the program
		cout << endl;

		// Error check user input
		if (cin.fail()) {
			cin.clear();                                          // reset the error state
			cin.ignore(1000, '\n');
			userInput = 0; // just sends to default case to error message
		}
		
		switch (userInput) {
			// If the user wants to input the file
			case 1: {

				//Gets the file name
				cout << "Please enter the name of the file: ";
				cin >> userFile;
				cout << endl;

				// creates file object and opens the users file
				ifstream payrollFile;
				payrollFile.open(userFile);

				// Error check that file opens
				if (!payrollFile) {
					cout << "ERROR: " << userFile << " could not be opened." << endl;
					cout << endl;
					continue;
				}

				// value to read in input from the file
				int hours = 0;

				// reads input from file into hours, and then totalHours is added up
				while (payrollFile >> hours) {
					totalHours += hours;
				}

				//closes file
				payrollFile.close();
				break;
			}
			//If user wants to manually input hours
			case 2: {

				//for loop to bring in input and adds to totalHours
				for (int i = 1; i <= DAYS_IN_WEEK; i++) {
					int temp = 0;
					cout << "Please enter the hours worked on day #" << i << ": ";
					cin >> temp;
					if (cin.fail() || (temp < 0 || temp > 10)) {
						cout << "Please enter a value only between 0 and 10." << endl;
						cin.clear();                                          // reset the error state
						cin.ignore(1000, '\n');
						temp = 0;
						i--;
					}
					totalHours += temp;

				}

				break;
			}

			case 3: {
				int days = 0;
				noOrYes = 1;
				while (noOrYes == 1) {
					days++;
					cout << "Current days to be paid: " << days << endl;
					cout << "Add another day? Enter 0 for no and 1 for yes: ";
					cin >> noOrYes;

					while (cin.fail() || (noOrYes != 0 && noOrYes != 1)) {
						cin.clear();
						cin.ignore(1000, '\n');
						cout << "Invalid input. Please only enter 0 for no and 1 for yes." << endl;
						cout << "Add another day? Enter 0 for no and 1 for yes: " << endl;
						cin >> noOrYes;
					}
				}

				// calculate gross pay
				grossPay = DAILY_RATE * days;

				//print gross pay
				cout << endl << "+++++++++++++++++++++++++++++++++++++++++" << endl;
				cout << left << setw(25) << "Total days worked:" << right << setw(10) << days << endl;
				cout << left << setw(25) << "Employee gross pay:" << right << "$" << setw(9) << grossPay << endl;

				cout << "+++++++++++++++++++++++++++++++++++++++++" << endl;
				break;
			}

			case 4: {
				cout << "Thank you for running the payroll calculator! The program now will end." << endl;
				stillRun = false;
				break;
			}

			default:
				cout << "That is not a valid input. Please try again." << endl;
		}
		if (userInput == 1 || userInput == 2) {
			grossPay = totalHours * HOURLY_RATE;
			cout << endl << "+++++++++++++++++++++++++++++++++++++++++" << endl;
			cout << left << setw(25) << "Total hours worked:" << right << setw(10) << totalHours << endl;
			cout << left << setw(25) << "Employee gross pay:" << right << "$" << setw(9) << grossPay << endl;
			cout << "+++++++++++++++++++++++++++++++++++++++++" << endl;
		}
		cout << endl << endl;


	} while (stillRun);

	system("pause");
	return 0;


}