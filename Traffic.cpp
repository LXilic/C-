/*
Overall Score out of 100: !- Scoreis  98 

Grading comments in the code below are marked with //-!-
Not following the naming convention results in 5 pt. Deduction as stated above

 Program execution (55 points total)
 A. 10: Displays the board                                     |
 B.  5: Move the TT piece around(without error check)          |
 C. 15: Move all of the pieces around(without error check)     |
        (A, B, and C above must work for the rest to be graded)|
 D.  2: Move numbers are shown in prompt for each move         |
 E.  3: Detects a win                                          |
 F.  5: Input of ‘x’ or ‘X’ exits the game                     |
 G.  5: Input of ‘-’ allows input to reset board and play      |
 H. 10: Attempt to move onto other piece or out of bounds moves| -2 //-!- Does not move piece as far as possible into a piece on the board
        As far as possible and gives error message.            |

 Program Style (45 points total):
 A.  5: Followed program naming conventions     |
 B. 10: Meaningful identifier names             |
 C. 10:yout                  Comments           |
 D.  5: Functional Decomposition                |
 E. 10: Appropriate data and control structures |
 F.  5: Code La            |
*/

/* --------------------------------------------------------
* Traffic.cpp
*	  RushHour game created in C++. This object in this game
*     is to move vehicle out of the traffic. This is a text-
*	  based version.
*     Please note that vehicle can only exit on the right side
*     of the board. Also, this program takes different inputs
*     in order to change the board.
*
* Class: Program #2 for CS 141, Fall 2017.
* Lab: Minh 11am
* TA Minh
* System: Mac OS X
* Author: A. Ilic
*/

#include <cstdlib>
#include <iomanip> // Enables use of rand()
#include <iostream>
#include <cctype>      // for toupper()
using namespace std;


// Global variables and constants
// Variables to store the board pieces
char  p1, p2, p3, p4, p5, p6,
p7, p8, p9, p10, p11, p12,
p13, p14, p15, p16, p17, p18,
p19, p20, p21, p22, p23, p24,
p25, p26, p27, p28, p29, p30,
p31, p32, p33, p34, p35, p36;

char r1, r2;
//--------------------------------------------------------------------
// Display ID info
//Get piece at switch that return p1 through p36 for cases 1 through 36
char* getPieceAt(int i) {
	switch (i) {
	case 1: return &p1;
	case 2: return &p2;
	case 3: return &p3;
	case 4: return &p4;
	case 5: return &p5;
	case 6: return &p6;
	case 7: return &p7;
	case 8: return &p8;
	case 9: return &p9;
	case 10: return &p10;
	case 11: return &p11;
	case 12: return &p12;
	case 13: return &p13;
	case 14: return &p14;
	case 15: return &p15;
	case 16: return &p16;
	case 17: return &p17;
	case 18: return &p18;
	case 19: return &p19;
	case 20: return &p20;
	case 21: return &p21;
	case 22: return &p22;
	case 23: return &p23;
	case 24: return &p24;
	case 25: return &p25;
	case 26: return &p26;
	case 27: return &p27;
	case 28: return &p28;
	case 29: return &p29;
	case 30: return &p30;
	case 31: return &p31;
	case 32: return &p32;
	case 33: return &p33;
	case 34: return &p34;
	case 35: return &p35;
	case 36: return &p36;
	default: return NULL;



	}
}

void displayIDInfo()
{
	printf("Author: Aleksandar Ilic\n");
	printf("Lab:     Tues 11am            \n");
	printf("Program: #2, Traffic \n");
	printf(" \n");
}//end displayIDInfo()


 //--------------------------------------------------------------------
 // Display Instructions
void displayInstructions()
{
	cout << "Welcome to the traffic game!                          " << endl
		<< "                                                      " << endl
		<< "Move the vehicles so that the Red car (RR) can exit   " << endl
		<< "the board to the right. Each move should be of the    " << endl
		<< "of the form:   CDN   where:                           " << endl
		<< "   C  is the vehicle to be moved                      " << endl
		<< "   D  is the direction (u=up, d=down, l=left or r=right)" << endl
		<< "   N  is the number of squares to move it             " << endl
		<< "For example GR2  means move the G vehicle to the right" << endl
		<< "2 squares.  Lower-case input such as   gr2  is also   " << endl
		<< "accepted.  Enter '-' to reset board, or 'x' to exit.  " << endl << endl << endl;

}//end displayInstructions()



 //--------------------------------------------------------------------
 // Display the board, using the current values in the global variables.
void displayBoard()
{
	cout << r1 << setw(2) << r1 << setw(2) << r1 << setw(2) << r1 << setw(2) << r1 << setw(2) << r1 << setw(2) << r1 << endl;
	cout << r2 << p1 << setw(2) << p2 << setw(2) << p3 << setw(2) << p4 << setw(2) << p5 << setw(2) << p6 << r2 << endl;
	cout << r2 << p7 << setw(2) << p8 << setw(2) << p9 << setw(2) << p10 << setw(2) << p11 << setw(2) << p12 << r2 << endl;
	cout << r2 << p13 << setw(2) << p14 << setw(2) << p15 << setw(2) << p16 << setw(2) << p17 << setw(2) << p18 << setw(1) << endl;
	cout << r2 << p19 << setw(2) << p20 << setw(2) << p21 << setw(2) << p22 << setw(2) << p23 << setw(2) << p24 << r2 << endl;
	cout << r2 << p25 << setw(2) << p26 << setw(2) << p27 << setw(2) << p28 << setw(2) << p29 << setw(2) << p30 << r2 << endl;
	cout << r2 << p31 << setw(2) << p32 << setw(2) << p33 << setw(2) << p34 << setw(2) << p35 << setw(2) << p36 << r2 << endl;
	cout << r1 << setw(2) << r1 << setw(2) << r1 << setw(2) << r1 << setw(2) << r1 << setw(2) << r1 << setw(2) << r1 << endl;
}//end displayBoard()

 //Checks in what *row is the vehicle in
int findVehiclerow(char vehicle) {

	int i;
	for (i = 1; i <36; i++) {
		if (*getPieceAt(i) == vehicle) {
			break;
		}
	}

	if (*getPieceAt(i) == *getPieceAt(i + 1)) {
		return i;
	}
	else if (*getPieceAt(i) == *getPieceAt(i + 6)) {
		return (-1)*i;
	}
	else {
		return 0;
	}

	
}
//Funtion that set rows takes in loc 
void setrows(int loc, char** row1, char** row2, char** row3, char** row4, char** row5, char** row6) {
	switch (loc) {

	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
		*row1 = &p1;
		*row2 = &p2;
		*row3 = &p3;
		*row4 = &p4;
		*row5 = &p5;
		*row6 = &p6;
		return;

	case 7:
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
		*row1 = &p7;
		*row2 = &p8;
		*row3 = &p9;
		*row4 = &p10;
		*row5 = &p11;
		*row6 = &p12;
		return;

	case 13:
	case 14:
	case 15:
	case 16:
	case 17:
	case 18:
		*row1 = &p13;
		*row2 = &p14;
		*row3 = &p15;
		*row4 = &p16;
		*row5 = &p17;
		*row6 = &p18;
		return;
	case 19:
	case 20:
	case 21:
	case 22:
	case 23:
	case 24:
		*row1 = &p19;
		*row2 = &p20;
		*row3 = &p21;
		*row4 = &p22;
		*row5 = &p23;
		*row6 = &p24;
		return;
	case 25:
	case 26:
	case 27:
	case 28:
	case 29:
	case 30:
		*row1 = &p25;
		*row2 = &p26;
		*row3 = &p27;
		*row4 = &p28;
		*row5 = &p29;
		*row6 = &p30;
		return;
	case 31:
	case 32:
	case 33:
	case 34:
	case 35:
	case 36:
		*row1 = &p31;
		*row2 = &p32;
		*row3 = &p33;
		*row4 = &p34;
		*row5 = &p35;
		*row6 = &p36;
		return;
	case -1:
	case -7:
	case -13:
	case -19:
	case -25:
	case -31:
		*row1 = &p1;
		*row2 = &p7;
		*row3 = &p13;
		*row4 = &p19;
		*row5 = &p25;
		*row6 = &p31;
		return;
	case -2:
	case -8:
	case -14:
	case -20:
	case -26:
	case -32:
		*row1 = &p2;
		*row2 = &p8;
		*row3 = &p14;
		*row4 = &p20;
		*row5 = &p26;
		*row6 = &p32;
		return;
	case -3:
	case -9:
	case -15:
	case -21:
	case -27:
	case -33:
		*row1 = &p3;
		*row2 = &p9;
		*row3 = &p15;
		*row4 = &p21;
		*row5 = &p27;
		*row6 = &p33;
		return;
	case -4:
	case -10:
	case -16:
	case -22:
	case -28:
	case -34:
		*row1 = &p4;
		*row2 = &p10;
		*row3 = &p16;
		*row4 = &p22;
		*row5 = &p28;
		*row6 = &p34;
		return;
	case -5:
	case -11:
	case -17:
	case -23:
	case -29:
	case -35:
		*row1 = &p5;
		*row2 = &p11;
		*row3 = &p17;
		*row4 = &p23;
		*row5 = &p29;
		*row6 = &p35;
		return;
	case -6:
	case -12:
	case -18:
	case -24:
	case -30:
	case -36:
		*row1 = &p6;
		*row2 = &p12;
		*row3 = &p18;
		*row4 = &p24;
		*row5 = &p30;
		*row6 = &p36;
		return;
	}



}
//Int checks for move takes in vehicle, motion, and direction
int checkMove(char vehicle, int motion, char direction) {
	int location = findVehiclerow(vehicle);
	if (location > 0) {
		if (direction == 'U' || direction == 'D') {
			return 0;
		}
	}
	else {
		if (direction == 'L' || direction == 'R') {
			return 0;
		}
	}

	char *row1;
	char *row2;
	char *row3;
	char *row4;
	char *row5;
	char *row6;
	char *temp1;
	char *temp2;
	char *temp3;

	setrows(location, &row1, &row2, &row3, &row4, &row5, &row6);
	if (motion <= 0 || motion > 5) {
		return 0;
	}

	//Switch for direction checks the direction of the piece
	switch (direction) {
	case 'R':
	case 'D':
		switch (motion) {
		case 1:
			if (*row6 == vehicle) {
				return 0;
			}
			if (*row1 == vehicle) {
				if (*row2 != '.' && *row2 != vehicle) {
					return 0;
				}

			}
			if (*row2 == vehicle) {
				if (*row3 != '.' && *row3 != vehicle) {
					return 0;
				}
			}
			if (*row3 == vehicle) {
				if (*row4 != '.' && *row4 != vehicle) {
					return 0;
				}
			}
			if (*row4 == vehicle) {
				if (*row5 != '.' && *row5 != vehicle) {
					return 0;
				}
			}
			if (*row5 == vehicle) {
				if (*row6 != '.' && *row6 != vehicle) {
					return 0;
				}
			}

			return 1;
			break;
		case 2:
			if (*row6 == vehicle) {
				return 0;
			}
			if (*row5 == vehicle) {
				return 0;
			}
			if (*row1 == vehicle) {
				if (*row3 != '.' && *row3 != vehicle) {
					return 0;
				}
			}
			if (*row2 == vehicle) {
				if (*row4 != '.' && *row4 != vehicle) {
					return 0;
				}
			}
			if (*row3 == vehicle) {
				if (*row5 != '.' && *row5 != vehicle) {
					return 0;
				}
			}
			if (*row4 == vehicle) {
				if (*row6 != '.' && *row6 != vehicle) {
					return 0;
				}
			}

			return 1;
			break;
		case 3:
			if (*row6 == vehicle) {
				return 0;
			}
			if (*row5 == vehicle) {
				return 0;
			}
			if (*row4 == vehicle) {
				return 0;
			}
			if (*row1 == vehicle) {
				if (*row4 != '.' && *row4 != vehicle) {
					return 0;
				}
			}
			if (*row2 == vehicle) {
				if (*row5 != '.' && *row5 != vehicle) {
					return 0;
				}
			}
			if (*row3 == vehicle) {
				if (*row6 != '.' && *row6 != vehicle) {
					return 0;
				}
			}
			return 1;
			break;
		case 4:
			if (*row6 == vehicle) {
				return 0;
			}
			if (*row5 == vehicle) {
				return 0;
			}
			if (*row4 == vehicle) {
				return 0;
			}
			if (*row3 == vehicle) {
				return 0;
			}
			if (*row1 == vehicle) {
				if (*row5 != '.' && *row5 != vehicle) {
					return 0;
				}
			}
			if (*row2 == vehicle) {
				if (*row6 != '.' && *row6 != vehicle) {
					return 0;
				}
			}
			return 1;
			break;
		case 5:
			if (*row6 == vehicle) {
				return 0;
			}
			if (*row5 == vehicle) {
				return 0;
			}
			if (*row4 == vehicle) {
				return 0;
			}
			if (*row3 == vehicle) {
				return 0;
			}
			if (*row2 == vehicle) {
				return 0;
			}
			if (*row1 == vehicle) {
				if (*row6 != '.' && *row6 != vehicle) {
					return 0;
				}
			}
			return 1;
			break;
		default:
			return 0;
		}

	case 'U':
	case 'L':
		temp1 = row1;
		temp2 = row2;
		temp3 = row3;
		row3 = row4;
		row2 = row5;
		row1 = row6;
		row6 = temp1;
		row5 = temp2;
		row4 = temp3;
		switch (motion) {
		case 1:
			if (*row6 == vehicle) {
				return 0;
			}
			if (*row1 == vehicle) {
				if (*row2 != '.' && *row2 != vehicle) {
					return 0;
				}

			}
			if (*row2 == vehicle) {
				if (*row3 != '.' && *row3 != vehicle) {
					return 0;
				}
			}
			if (*row3 == vehicle) {
				if (*row4 != '.' && *row4 != vehicle) {
					return 0;
				}
			}
			if (*row4 == vehicle) {
				if (*row5 != '.' && *row5 != vehicle) {
					return 0;
				}
			}
			if (*row5 == vehicle) {
				if (*row6 != '.' && *row6 != vehicle) {
					return 0;
				}
			}

			return 1;
			break;
		case 2:
			if (*row6 == vehicle) {
				return 0;
			}
			if (*row5 == vehicle) {
				return 0;
			}
			if (*row1 == vehicle) {
				if (*row3 != '.' && *row3 != vehicle) {
					return 0;
				}
			}
			if (*row2 == vehicle) {
				if (*row4 != '.' && *row4 != vehicle) {
					return 0;
				}
			}
			if (*row3 == vehicle) {
				if (*row5 != '.' && *row5 != vehicle) {
					return 0;
				}
			}
			if (*row4 == vehicle) {
				if (*row6 != '.' && *row6 != vehicle) {
					return 0;
				}
			}
			return 1;
			break;
		case 3:
			if (*row6 == vehicle) {
				return 0;
			}
			if (*row5 == vehicle) {
				return 0;
			}
			if (*row4 == vehicle) {
				return 0;
			}
			if (*row1 == vehicle) {
				if (*row4 != '.' && *row4 != vehicle) {
					return 0;
				}
			}
			if (*row2 == vehicle) {
				if (*row5 != '.' && *row5 != vehicle) {
					return 0;
				}
			}
			if (*row3 == vehicle) {
				if (*row6 != '.' && *row6 != vehicle) {
					return 0;
				}
			}
			return 1;
			break;
		case 4:
			if (*row6 == vehicle) {
				return 0;
			}
			if (*row5 == vehicle) {
				return 0;
			}
			if (*row4 == vehicle) {
				return 0;
			}
			if (*row3 == vehicle) {
				return 0;
			}
			if (*row1 == vehicle) {
				if (*row5 != '.' && *row5 != vehicle) {
					return 0;
				}
			}
			if (*row2 == vehicle) {
				if (*row6 != '.' && *row6 != vehicle) {
					return 0;
				}
			}
			return 1;
			break;
		case 5:
			if (*row6 == vehicle) {
				return 0;
			}
			if (*row5 == vehicle) {
				return 0;
			}
			if (*row4 == vehicle) {
				return 0;
			}
			if (*row3 == vehicle) {
				return 0;
			}
			if (*row2 == vehicle) {
				return 0;
			}
			if (*row1 == vehicle) {
				if (*row6 != '.' && *row6 != vehicle) {
					return 0;
				}
			}
			return 1;
		default:
			return 0;
		}
	}

	return 0;
}

//Make move function takes the vehicle paramater its different for *row and column
void makeMove(char vehicle, int motion, char direction) {
	int location = findVehiclerow(vehicle);


	char *row1;
	char *row2;
	char *row3;
	char *row4;
	char *row5;
	char *row6;
	char *temp1;
	char *temp2;
	char *temp3;

	setrows(location, &row1, &row2, &row3, &row4, &row5, &row6);

	if (direction == 'L' || direction == 'U') {
		temp1 = row1;
		temp2 = row2;
		temp3 = row3;
		row3 = row4;
		row2 = row5;
		row1 = row6;
		row6 = temp1;
		row5 = temp2;
		row4 = temp3;
	}
	//Switch cheks for motion or how many spaces to move
	switch (motion) {
	case 1:
		if (vehicle == *row5) {
			*row5 = '.';
			*row6 = vehicle;
		}
		if (vehicle == *row4) {
			*row4 = '.';
			*row5 = vehicle;
		}
		if (vehicle == *row3) {
			*row3 = '.';
			*row4 = vehicle;
		}
		if (vehicle == *row2) {
			*row2 = '.';
			*row3 = vehicle;
		}
		if (vehicle == *row1) {
			*row1 = '.';
			*row2 = vehicle;
		}
		break;

	case 2:
		if (vehicle == *row4) {
			*row6 = vehicle;  // *row6 = vehicle  *row4
			*row4 = '.';
		}
		if (vehicle == *row3) {
			*row5 = vehicle;
			*row3 = '.';
		}
		if (vehicle == *row2) {
			*row4 = vehicle;
			*row2 = '.';
		}
		if (vehicle == *row1) {
			*row3 = vehicle;
			*row1 = '.';
		}
		break;

	case 3:
		if (vehicle == *row3) {
			*row6 = vehicle;
			*row3 = '.';
		}
		if (vehicle == *row2) {
			*row5 = vehicle;
			*row2 = '.';
		}
		if (vehicle == *row1) {
			*row4 = vehicle;
			*row1 = '.';
		}
		break;

	case 4:
		if (vehicle == *row2) {
			*row6 = vehicle;
			*row2 = '.';
		}
		if (vehicle == *row1) {
			*row5 = vehicle;
			*row1 = '.';
		}
		break;
	case 5:
		if (vehicle == *row1) {
			*row6 = vehicle;
		}
		break;

	}

	return;

}

//Checks in what column is the vehicle in  

//--------------------------------------------------------------------
/*  Board and corresponding global variable values are:
- - - - - - - -
1  | G G . . . Y |
7  | P . . B . Y |
13 | P R R B . Y >
19 | P . . B . . |
25 | O . . . T T |
31 | O . F F F . |
- - - - - - - -
*/
int main() {
	int column = 0;
	int *row = 0;

	displayIDInfo();        // Display ID info
	displayInstructions();  // Display game instructions

							// Set the board values
	p1 = 'G'; p2 = 'G'; p3 = '.'; p4 = '.'; p5 = '.'; p6 = 'Y';
	p7 = 'P'; p8 = '.'; p9 = '.'; p10 = 'B'; p11 = '.'; p12 = 'Y';
	p13 = 'P'; p14 = 'R'; p15 = 'R'; p16 = 'B'; p17 = '.'; p18 = 'Y';
	p19 = 'P'; p20 = '.'; p21 = '.'; p22 = 'B'; p23 = '.'; p24 = '.';
	p25 = 'O'; p26 = '.'; p27 = '.'; p28 = '.'; p29 = 'T'; p30 = 'T';
	p31 = 'O'; p32 = '.'; p33 = 'F'; p34 = 'F'; p35 = 'F'; p36 = '.';

	r1 = '-'; r2 = '|';

	// Display the initial board
	displayBoard();
	int moveNum = 1;
	//checks if you win
	while (true) {
		if (p18 == 'R') {
			cout << "*** Congratulations, you did it! ***" << endl;
			exit(0);
		}
		//char var to store user input
		//char var for direction, and piece, int for distance, 
		char vehToMove;
		char direction;
		int distance;
		//Numbers to move
		cout << moveNum << ". Your move -> ";
		//user input for vehicle
		cin >> vehToMove;
		//switches to uppercase 
		vehToMove = toupper(vehToMove);
		if (vehToMove == 'X')
		{
			exit(0);
		}
		else if (vehToMove == '-') {
			cin >> p1 >> p2 >> p3 >> p4 >> p5 >> p6
				>> p7 >> p8 >> p9 >> p10 >> p11 >> p12
				>> p13 >> p14 >> p15 >> p16 >> p17 >> p18
				>> p19 >> p20 >> p21 >> p22 >> p23 >> p24
				>> p25 >> p26 >> p27 >> p28 >> p29 >> p30
				>> p31 >> p32 >> p33 >> p34 >> p35 >> p36;
			moveNum = 1;
			displayBoard();
			continue;
		}
		cin >> direction; //takes in the direction 
		direction = toupper(direction); //changes direction to upper case
		cin >> distance; //takes in the distance

		//checks for user input if its correct and gives an error
		if (checkMove(vehToMove, distance, direction) == 1) {
			makeMove(vehToMove, distance, direction);
		}
		else {
			cout << endl << "*** Move was attempted, but couldn't be completed. ***  " << endl;
		}
		moveNum++;
		displayBoard();
	}

	cout << endl;
	cout << "Thank you for playing.  Exiting..." << endl;

	return 0;
}//end main()





