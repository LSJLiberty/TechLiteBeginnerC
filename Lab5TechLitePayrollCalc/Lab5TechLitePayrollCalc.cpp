/*
Developer: Luke Jany
Date: 10/15/2026
Purpose: Develop a program that calculates the payroll for employees of TechLite
Course/Section: CSCN111-005
*/

// Preprocessor statements
#include <iostream> // always included
#include <iomanip> // Required for string manipulators
#include <fstream> // file operations
#include <string> // Used for multi-char display
#include <cstdlib> //C standard library
using namespace std;

// Declaring variables
int userInput;
string userFile;
int totalHours = 0;
const double HOURLY_RATE = 15.00;
const double DAILY_RATE = 100.00;
double grossPay;
int noOrYes;
bool stillRun = true;


int main() {

	cout << "==================================================================" << endl;
	cout << "                   TECHLITE PAYROLL CALCULATOR                    " << endl;
	cout << "==================================================================" << endl;
	cout << endl << endl;
	cout << "Welcome to the payroll calculator for TechLite!" << endl;
	cout << "The menu below provides the possible options to choose to determine employees hours and pay." << endl << endl;

	//loops till quit option is selected
	while (stillRun) {
		//resets variables
		grossPay = 0;
		totalHours = 0;

		//menu for users
		cout << fixed << setprecision(2);
		cout << "==================================================================" << endl;
		cout << "Please select from one of the following options." << endl;
		cout << "1. File input for employee hours" << endl;
		cout << "2. Manual entry for employee hours" << endl;
		cout << "3. Flat rate employees" << endl;
		cout << "4. Quit" << endl;
		cout << "------------------------------------------------------------------" << endl;
		cout << "Selection: ";
		cin >> userInput;
		cout << endl;

		// Error check user input
		if (cin.fail() || (userInput <= 0 || userInput >= 5)) {
			cout << "Invalid selection. Sending you back to the menu." << endl;
			cin.clear();                                          // reset the error state
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // throw away the bad input
		}

		// If the user wants to input the file
		if (userInput == 1) {

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
				continue;
			}

			// value to read in input from the file
			int hours = 0;

			// reads input from file into hours, and then totalHours is added up
			while (payrollFile >> hours) {
				totalHours += hours;
			}

			//calculates gross pay
			grossPay = totalHours * HOURLY_RATE;

			//closes file
			payrollFile.close();

			//Output
			cout << endl << "------------------------------------------------------------------" << endl;
			cout << "Total hours worked: " << totalHours << endl;
			cout << "Employee gross pay: $" << grossPay << endl;
			cout << "------------------------------------------------------------------" << endl;

		}

		//If user wants to manually input horus
		else if (userInput == 2) {

			//for loop to bring in input and adds to totalHours
			for (int i = 1; i <= 7; i++) {
				int temp = 0;
				cout << "Please enter the hours worked on day #" << i << ": ";
				cin >> temp;
				if (cin.fail() || (temp < 0 || temp > 10)) {
					cout << "Please enter a value only between 0 and 10." << endl;
					cin.clear();                                          // reset the error state
					cin.ignore(numeric_limits<streamsize>::max(), '\n');  // throw away the bad input
					temp = 0;
					i--;
				}
				totalHours += temp;

			}

			//calculates gross pay
			grossPay = totalHours * HOURLY_RATE;

			//output
			cout << endl << "------------------------------------------------------------------" << endl;
			cout << "Total hours worked: " << totalHours << endl;
			cout << "Employee gross pay: $" << grossPay << endl;
			cout << "------------------------------------------------------------------" << endl;

		}

		else if (userInput == 3) {
			int days = 0;
			noOrYes = 1;
			while (noOrYes == 1) {
				days++;
				grossPay += DAILY_RATE;
				cout << "Current days to be paid: " << days << endl;

				while (true) {
					cout << "Add another day? Enter 0 for no and 1 for yes: ";
					cin >> noOrYes;
					if (!cin.fail() && (noOrYes == 0 || noOrYes == 1)) break;
					cout << "Invalid selection. Please enter 0 or 1." << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			cout << endl << "------------------------------------------------------------------" << endl;
			cout << "Employee gross pay: $" << grossPay << endl;
			cout << "------------------------------------------------------------------" << endl;
		}

		else if (userInput == 4) {
			cout << "Thank you for running the payroll calculator! The program now will end." << endl;
			stillRun = false;
		}

		cout << endl << endl;


	}
	system("pause");
	return 0;


}