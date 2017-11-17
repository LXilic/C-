/*
 Overall Score out of 100: 98 

 Grading comments in the code below are marked with //-!-

 Program execution (55 points total)
 A.  5: Displays header information                            | 
 B.  5: Displays table from 99 down to 0                       | 
 C.  5: Columns are lined up                                   | 
 D.  5: Table has random upper and lower-case values           | 
 E.  5: Special character value in all multiple of 9 positions | 
 F. 10: Table shown, prompt, then special character displayed  | 
 G. 10: Special character is random                            |  
 H. 10: Table changes each time program is run                 | 
 
 Program Style (45 points total):
 A.  5: Followed program naming conventions     |
 B. 10: Meaningful identifier names             |
 C. 10: Comments                                | 
 D.  5: Functional Decomposition                |
 E. 10: Appropriate data and control structures |
 F.  5: Code Layout                             | -2
 */


// You should have a program header here with identifying info -2

#include <iostream>
#include <cstdlib>  
#include <iomanip> // Enables use of rand()
#include <ctime> // Enables use of time()
using namespace std;

int main() {

	srand(time(NULL));           // Enables generating rand numb
	int tableNumb = 99;          // Numbers for the table
	char specialLetter = 'A';    // Starting special
	char masterKey ;             // User's input must be "r" key
	int randomLetter;            


	// Generates upper and lower case for special letter
	specialLetter = rand() % 25 + specialLetter;  
	if (specialLetter % 2 != 0)
	{
		specialLetter = (char)tolower(specialLetter);
	}
	else {
		specialLetter = (char)toupper(specialLetter);
	}

    cout << "Program #1: Guess It " <<endl;
    cout << "Author: Aleksandar Ilic" <<endl;
    cout << "Lab: Tues 11am / TA's name: Minh  HuynhNguyen" <<endl;
    cout << "Date: Aug 29, 2017" <<endl;
    cout << "System:  C++ in Cloud 9" <<endl;
    cout <<endl;
    
   // While loop that generates table numbers
	while (tableNumb > -1) {                         
		char randomLetter = 'A';
	// Generates both lower and case letters for randomLetter
		randomLetter = ((rand() % 25) + randomLetter); 
		if (randomLetter % 2 != 0)
     	{
		randomLetter = ((char)tolower(randomLetter));
    	}
    	else {
		randomLetter = (char)toupper(randomLetter);
	    }
	    
	    /* Generates special number for all numbers divisible by 9
	       Starts new line when tableNumb is less then 10
	    */
		if (tableNumb % 9 == 0) {                                   
			if (tableNumb % 10 == 0) {
				if (tableNumb < 10) {                                 
					cout << " " << tableNumb << ":" << specialLetter << endl;
					--tableNumb;
				}
				else {
					cout << tableNumb << ":" << specialLetter << " " << endl;
					--tableNumb;
				}
			}
			// Generates extra space after the number if tableNumb is less then 10
			else {                                                  
				if (tableNumb < 10) {
					cout << " " << tableNumb << ":" << specialLetter << " ";
					--tableNumb;
				}
				else {
					cout << tableNumb << ":" << specialLetter << " ";
					--tableNumb;
				}
			}
		}
		// Generates extra space after the number if tableNumb value is less than
		else {                                                              
			if (tableNumb % 10 == 0) {
				if (tableNumb < 10) {
					cout << " " << tableNumb << ":" << specialLetter;
					--tableNumb;
				}
				else {
					cout << tableNumb << ":" << randomLetter << endl;
					--tableNumb;
				}
			}
			else {
				if (tableNumb < 10) {
					cout << " " << tableNumb << ":" << randomLetter << " ";
					--tableNumb;
				}
				else
				{
					cout << tableNumb << ":" << randomLetter << " ";
					--tableNumb;
				}
			}
		}
	}
   // Prints out the game instructions with the required steps.
   cout <<endl;
	cout << "1. Choose any two - digit number in the table above(e.g. 73)." <<endl;  
	cout << "2. Subtract its two digits from itself(e.g. 73 - 7 - 3 = 63) " << endl;
	cout << "3. Find this new number(e.g. 63) and remember the letter next to it." << endl;
	cout << "4. Now press 'r' and I'll read your mind..." << endl;
    cout <<endl;
    
	cin >> masterKey;
	while(masterKey != 'r') {   //Checks if the masterKey = 'r'
		cout << "Please press 'r' to find the character " << endl;
		cin >> masterKey;
	}
	cout << "You selected the character:" << specialLetter << endl; 	//Prints out the special character if user enters 'r'
	return 0;
}
