//-!- Missing TA information in header -1
/*
Author:  Shivam Mehrotra & Aleksandar Ilic
Lab:     Tuesdays 11 AM
Program : #3, 0 / 1 Guessing Game
Program plays the 0/1 guessing game, AI vs human.
*/

#include <iostream>
#include <stdio.h>
#include <ctype.h>

using namespace std;

 /*
 
 Overall Score out of 100: 98
 
 Program execution (55 points total)
 A. 5: Arrow marker moves left or right (on each move)         |
 B. 5: At +5 or -5 points, print message                       |-1 //-!- This was handled incorrectly, should be when the score is either -5 or 5
 C. 5: At +10 or -10 points, print message and end game        |
 D. 10: Display moves history table when toggled on            |
 E. 10: Use 2D array to store moves history table updates      |
 F.  3: Display previous 3 moves when moves history table on   |
 G.  5: User input of ‘r’ or ‘R’                               |
 H.  2: User input of ‘x’ or ‘X’                               |
 I.  5: Move number starts at 1 and increments each move       |
 J.  5: Display whether human or computer got the point        |
 
 Program Style (45 points total):
 A.  5: Followed program naming conventions     |
 B. 10: Meaningful identifier names             |
 C. 10: Comments                                | -1
 D.  5: Functional Decomposition                |
 E. 10: Appropriate data and control structures |
 F.  5: Code Layout                             |
*/


//--------------------------------------------------------------------------------
//displays who made the program
void displayProgrammers() {
	cout << "Author:  Shivam Mehrotra & Aleksandar Ilic" << endl
		<< "Lab:     Tuesdays 11 AM" << endl
		<< "Program : #3, 0 / 1 Guessing Game " << endl << endl;
}

//--------------------------------------------------------------------------------
//displays instructions on how to play the game
void displayInstructions() {
	cout << "Welcome to the 0/1 guessing game!" << endl << endl;
	cout << "Enter 0 or 1, trying to outsmart the computer, which is going to" << endl;
	cout << "attempt to forecast your guesses.On each move the score indicator" << endl;
	cout << "moves to the right if the computer guesses correctly, and moves" << endl;
	cout << "to the left if the computer does not." << endl;
	cout << "	Enter 't' to toggle displaying the data table." << endl;
	cout << "	Enter 'r' to reset the board." << endl;
	cout << "	Enter 'x' to exit." << endl;
	cout << "Good luck, you'll need it!" << endl << endl;
}

//--------------------------------------------------------------------------------------------
//displays the 3 lines that show visually what the score is
void displayStatusBar(int score) {
	char carrotRow[21] = "                   ";
	cout << "Computer" << "        Human" << endl;
	cout << "x---------x+++++++++x" << endl;
	if (score < 0) {
		for (int i = 9; i > 0; i--) {
			if (i == 10 - (abs(score)) {
				carrotRow[i] = '^';
			}
			else
			{
				carrotRow[i] = ' ';
			}
		}
	}
	else if (score > 0) {
		for (int i = 10; i < 20; i++) {
			if (i == score + 10) {
				carrotRow[i] = '^';
			}
			else {
				carrotRow[i] = ' ';
			}
		}
	}
	else if (score == 0) {
		carrotRow[10] = '^';
	}
	cout << carrotRow << endl;
}

//------------------------------------------------------------
//Set's the values in 2d array to default 000, 001
void setTableValues(int table[8][5]) {
	table[1][2] = 1;
	table[2][1] = 1;
	table[3][1] = 1;
	table[3][2] = 1;
	table[4][0] = 1;
	table[5][0] = 1;
	table[5][2] = 1;
	table[6][0] = 1;
	table[6][1] = 1;
	table[7][0] = 1;
	table[7][1] = 1;
	table[7][2] = 1;
}

//------------------------------------------------------------
//updates the table to display what the user has picked in previous patterns
void updateTable(int tableOfValues[8][5], int lastThreeValues[], char userInput) {
	for (int i = 0; i < 8; i++) {
		for (int k = 0; k < 1; k++) {
			if (tableOfValues[i][k] == lastThreeValues[k]) {
				if (tableOfValues[i][k + 1] == lastThreeValues[k + 1]) {
					if (tableOfValues[i][k + 2] == lastThreeValues[k+2]) {
						if (userInput == '0') {
							tableOfValues[i][k +3]++;
						}
						else if (userInput == '1') {
							tableOfValues[i][k + 4]++;
						}
					}
				}
			}
		}
	}
}

//------------------------------------------------------------
//finds the values that the user typically inputs, past the third move
int mostUsedValue(int table[8][5], int threeValues[], int last2move) {
	for (int i = 0; i < 8; i++) {
		for (int k = 0; k < 1; k++) {
			if (table[i][k] == threeValues[k]) {
				if (table[i][k + 1] == threeValues[k + 1]) {
					if (table[i][k + 2] == threeValues[k + 2]) {
						if (table[i][k + 3] > table[i][k + 4]) {
							return 0;
						}
						else if (table[i][k + 4] > table[i][k + 3]) {
							return 1;
						}
						else {
							if (last2move == 1) {
								return 0;
							}
							else if (last2move == 0) {
								return 1;
							}
						}
					}
				}
			}
		}
	}
	return -1;
}

//---------------------------------------------------
//this function runs in order for the computer to predict the next value
int predictValue(int threeValues[], int table[8][5], int lastMove, int numMove) {
	if (numMove < 4) {
		if (lastMove == 0) {
			return 1;
		}
		else if (lastMove == 1) {
			return 0;
		}
	}
	else {
		return mostUsedValue(table, threeValues, lastMove);
	}
	return -1;
}

//------------------------------------------------------------
//displays the table listing what the user has picked previously under the patterns (for eg: 000 1 0)
void displayTable(int table2[8][5], int lastValues[3], int nextGuess) {
	cout << endl;
	cout << "      0   1" << endl;
	cout << "    --- ---" << endl;
	for (int i = 0; i < 8; i++) {
		cout << table2[i][0] << table2[i][1] << table2[i][2] << "   " << table2[i][3] << "   " << table2[i][4] << endl;
	}
	cout << "Previous three: ";
	for (int i = 0; i < 3; i++)
	{
		cout << lastValues[i];
	}
	cout << "." << " Forecast: " << nextGuess;
	cout << endl;
}

//------------------------------------------------------------
//main function
int main() {
	char userInput = 0; //what the user puts in the cmd

	//3 scores to see who's winning, and to work the table 
	int humanScore = 0;
	int computerScore = 0;
	int combinedScore = 0;

	//sets the default values in the table
	int tableOfValues[8][5] = { 0 };
	setTableValues(tableOfValues);

	//last three values that the user has put in
	int lastThreeValues[3] = { 0,0,0 };

	int previousMove = 0;
	int computerGuess = 0;

	bool tableDisplay = false;
	int moveNum = 1;

	displayProgrammers();
	displayInstructions();

	while (combinedScore < 9 && combinedScore > -9) //makes sure that the no one is winning
	{
		//decides who is about to win
		if (humanScore == 5) {
			cout << endl << ">>> You're about to win! <<<" << endl;
		}
		else if (computerScore == 5) {
			cout << endl << ">>> You're going to lose! <<<" << endl;
		}

		if (humanScore > computerScore) {
			combinedScore = humanScore - computerScore;
		}
		else if (humanScore == computerScore) {
			combinedScore = 0;
		}
		else {
			combinedScore = humanScore - computerScore;
		}

		displayStatusBar(combinedScore);

		//if the tabledisplay boolean is true, display the table
		if (tableDisplay == true)
		{
			displayTable(tableOfValues, lastThreeValues, computerGuess);
			cout << endl;
		}

		cout << moveNum << ". Your input: ";

		//generate computer prediction here
		computerGuess = predictValue(lastThreeValues, tableOfValues, previousMove, moveNum);

		cin >> userInput;
		cout << endl;
		userInput = toupper(userInput); //changes input to upper case for error fail safe

		if (userInput == 'T') { //key to display the table
			if (tableDisplay == true) {
				tableDisplay = false;
			}
			else {
				tableDisplay = true;
			}
			continue;
		}
		else if (userInput == 'X') { //exits program
			exit(0);
		}
		else if (userInput == 'R') { //resets everything if inputed
			for (int i = 0; i < 8; i++) {
				for (int k = 3; k < 5; k++) {
					cin >> tableOfValues[i][k];
				}
			}
			lastThreeValues[0] = 0;
			lastThreeValues[1] = 0;
			lastThreeValues[2] = 0;
			moveNum = 1;
			continue;
		}
		if (moveNum > 3) {
			updateTable(tableOfValues, lastThreeValues, userInput);
		}
		int userInputGuess = userInput - '0';
		for (int i = 0; i < 2; i++) {
			int temp = lastThreeValues[i + 1];
			lastThreeValues[i + 1] = userInputGuess;
			lastThreeValues[i] = temp;
		}

		if (computerGuess != userInputGuess) {
			cout << "Human gets this point!" << endl;
			humanScore++;
		}
		else if (computerGuess == userInputGuess) {
			cout << "Computer gets this point!" << endl;
			computerScore++;
		}
		previousMove = userInputGuess;
		moveNum++;
	}

	//checks who won after while loop is done
	if (humanScore > computerScore) {
		cout << "Human " << " won. Congratulations" << endl;
	}
	else if (computerScore > humanScore) {
		cout << "Computer " << " won." << endl;
	}

	return 0; //default return
}

