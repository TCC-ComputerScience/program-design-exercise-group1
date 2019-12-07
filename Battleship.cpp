//PACE/Github Assignment -- Part 3 (Beginning Implementation)
// BattleShip Program -The computer generates the board and places the ships, and then the player has to guess the ship positions.
// 12/7/2019
// Program-design-exercise-group1(Github)
// Pace 9 (Canvas)
#include <iostream>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

enum Marks {Hit, Miss, Water, Ship};
enum ShipType {None, Pat, Sub, Dest, Battle, Carrier};
enum Orientation {Horizontal, Vertical};

struct battleship{ //Struct to hold Battleships coordinates

    char row;
    int  column;
    bool location;

};

const int ROWS    = 11;            //default size 10
const int COLUMNS = 11;            //default size 10

using namespace std;


// Creates a play grid based on the ship placements from PlaceShips
// Pre: A grid with ships was created
// Post: A grid consisting of ships and blank spaces is created but not displayed
void InitGrid(battleship Grid[][11]);

//Places a true bool value based on ship size, orientation, and amount
//Pre: There is a value fo the ShipType variable and Orientation variable
//Post: The ship will be place onto the grid without overlap
void ShipPlace (battleship Grid [][11]);

// Prints the grid using only water, hit and miss marks
// Pre: A play grid has been created
// post: An updated grid is printed to the screen
void PrintGrid(battleship Grid [][11]);

// Tests if they hit or missed the ship
// Pre: A valid input combination is entered
// Post: Tells user if they hit or missed the ship
void HitMiss(char player[ROWS][COLUMNS], char boardHidden[ROWS][COLUMNS], int, int);

int main()
{
    int attempts;   // Number of guess attempts
    int maxAttempts;    // Maximum number of guess attempts
    int shipCount;      // Number of remaining ships on board
    battleship Grid[ROWS][COLUMNS];


    InitGrid(Grid);
    PrintGrid(Grid);
    //PlaceShips();       // Makes a board of randomly generated values where ships are placed
    //InitGrid(emptyGrid);        // Creates a play grid based on the ship placements from PlaceShips
    //do    //Main game loops until finished or X guesses are completed
    //{
        //cout << "Data collection prompt\n";     // Requests and collects user guess values
        //cin >> guessX;
        //cin >> guessY;
        //void HitMiss(boardHidden, guessX, guessY);      // Tests if they hit or missed the ship
        //void PrintGrid(displayBoard);       // Prints the grid using only water, hit and miss marks
        //cout << "Track number of ships here";       // Code to track number of ships left
        //attempts++;     // Increments attempts after each guess iteration
    //}
    //while(attempts<MAX_ATTEMPTS || shipCount == 0);
    //cout << "Game over message";       // End game and display Victory or Defeat message
    return 0;
}


// Creates a play grid based on the ship placements from PlaceShips
// Pre: A grid with ships was created
// Post: A grid consisting of ships and blank spaces is created but not displayed
void InitGrid(battleship Grid[][11]){

    char letter = 'A'; // Initializes top row of Grid 
    int number = 1; // Initializes Left most column of Grid


    Grid[0][0].row = ' '; // Space at upper left corner/Out of bounds.

    for (int i = 1; i < ROWS; i++){      // SHOULD make top row of Grid.letter of A - J

        Grid[i][0].row = letter;
        letter++;
    }


    for (int i = 1; i < COLUMNS; i++){   // SHOULD make left most column of Grid.number 1 - 10

        Grid[0][i].column = number;
        number++;
        // I changed number into an int to increment naturally
    }

    for (int i = 1; i < ROWS; i++){ //This sets every character in row in between the first column and first row waves

         for (int j = 1; j < COLUMNS; j++){

            Grid[i][j].row = '~';

         }
    }

    ShipPlace(Grid); // Call to Place ships on initialized grid

}

//Places a true bool value based on ship size, orientation, and amount
//Pre: There is a value fo the ShipType variable and Orientation variable
//Post: The ship will be place onto the grid without overlap
void ShipPlace (battleship Grid [][11]){

    int shipSelection;
    ShipType ship;
    int placeOrientation;
    Orientation ori;
    int locatx, locaty;
    bool shipAmount = false; //This varibale is for the first do-while loop

    //These integers represent the ship
    int Patrol = 5;
    int Submarine = 4;
    int Destroyer = 3;
    int Battleship = 2;
    int Carry = 1;

    bool placed = false; //This variable is for the second do-while loop

    srand (time(NULL));
    for (int c = 0; c < 1; c++)
    {
        //Will Loop until a ship is selected where ther representative integer doesn't equal zero
        do{
        //Randomly select ship based on random integers 0-5
        shipSelection = rand() % 5;
        switch (shipSelection)
        {

        case 0 :
            ship = None;
            shipAmount = true;
            break;
        case 1 :
            if (Patrol != 0){
            ship = Pat;
            Patrol--;
            shipAmount = true;
            }
            else{
            shipAmount = false;
            }
            break;
        case 2:
            if (Submarine != 0){
            ship = Sub;
            Submarine--;
            shipAmount = true;
            }
            else{
            shipAmount = false;
            }
            break;
        case 3:
            if (Destroyer != 0){
            ship = Dest;
            Destroyer--;
            shipAmount = true;
            }
            else {
            shipAmount = false;
            }
            break;
        case 4:
            if (Battleship != 0){
            ship = Battle;
            Battleship--;
            shipAmount = true;
            }
            else{
            shipAmount = false;
            }

            break;
        case 5:
            if (Carrier != 0){
            ship = Carrier;
            Carry--;
            shipAmount = true;
            }
            else{
            shipAmount = false;
            }
            break;

        }
        } while (shipAmount = false);

        //Select ship orientation based on random integers 0-1

            placeOrientation = rand() % 2;
            switch (placeOrientation)
            {
            case 0 :
                ori = Horizontal;
                break;
            case 1 :
                ori = Vertical;
                break;
            }

            ///Will keep looping until the ship has found a postion to be at (placed = true), main issues are that it the ships may overwrite the letters of the row and the program will hang because the ships may be going out of bounds
            do
            {
                switch (ship)
                {
                case None:
                    placed = true;
                    break;
                case Pat:
                    locatx = rand() % 9 + 1;    // random number between 1 and 9
                    locaty = rand() % 9 + 1;    // random number between 1 and 9
                    if (Grid[locatx][locaty].location = false && locaty != 0)  //This checks if the coordinate chosen is already taken
                    {
                        Grid[locatx][locaty].row = '#';
                        Grid[locatx][locaty].location = true;
                        placed = true;
                    }
                    else
                    {
                        placed = false;
                    }
                    break;
                case Sub:
                    locatx = rand() % 9 + 1;    // random number between 1 and 9
                    locaty = rand() % 9 + 1;    // random number between 1 and 9
                    if (Grid[locatx][locaty].location == false)
                    {
                        Grid[locatx][locaty].row = '#';
                        Grid[locatx][locaty].location = true;

                        if (ori == Vertical && Grid[locatx][locaty + 1].location == false) ///The if-else statements from here on outward will check to see if the positions around the ship are taken, this list will keep getting bigger
                        {
                            Grid[locatx][locaty + 1].row = '#'; ///The rows will keep being marked true for as long the ship is going to be
                            Grid[locatx][locaty + 1].location = true;
                            placed = true;
                        }
                        else if (ori == Horizontal && Grid[locatx + 1][locaty].location == false)///Sames as vertical
                        {
                            Grid[locatx + 1][locaty].row = '#';
                            Grid[locatx + 1][locaty].location = true;
                            placed = true;
                        }

                        else
                        {
                            placed = false;
                            Grid[locatx][locaty].location = false;
                            Grid[locatx][locaty].row = '~';


                        }

                    }
                    else
                    {
                        placed = false;

                    }
                    break;
                case Dest:
                    locatx = rand() % 9 + 1;    // random number between 1 and 9
                    locaty = rand() % 9 + 1;    // random number between 1 and 9
                    if (Grid[locatx][locaty].location == false)
                    {
                        Grid[locatx][locaty].row = '#';
                        Grid[locatx][locaty].location = true;

                        if (ori == Vertical && Grid[locatx][locaty + 1].location == false && Grid[locatx][locaty - 1].location == false && Grid[locatx][locaty + 2].location == false && Grid[locatx][locaty - 2].location == false)
                        {
                            Grid[locatx][locaty + 1].row = '#';
                            Grid[locatx][locaty - 1].row = '#';
                            Grid[locatx][locaty + 2].row = '#';
                            Grid[locatx][locaty - 2].row = '#';
                            Grid[locatx][locaty + 1].location = true;
                            Grid[locatx][locaty - 1].location = true;
                            Grid[locatx][locaty + 2].location = true;
                            Grid[locatx][locaty - 2].location = true;
                            placed = true;
                        }
                        else if (ori == Horizontal && Grid[locatx + 1][locaty].location == false && Grid[locatx - 1][locaty].location == false && Grid[locatx + 2][locaty].location == false && Grid[locatx - 2][locaty].location == false)
                        {
                            Grid[locatx + 1][locaty].row = '#';
                            Grid[locatx - 1][locaty].row = '#';
                            Grid[locatx + 2][locaty].row = '#';
                            Grid[locatx - 2][locaty].row = '#';
                            Grid[locatx + 1][locaty].location = true;
                            Grid[locatx - 1][locaty].location = true;
                            Grid[locatx + 2][locaty].location = true;
                            Grid[locatx - 2][locaty].location = true;
                            placed = true;
                        }

                        else
                        {

                            placed = false;
                            Grid[locatx][locaty].location = false;
                            Grid[locatx][locaty].row = '~';

                        }


                    }

                    else
                    {
                        placed = false;
                    }
                    //}
                    break;
                case Battle:
                    locatx = rand() % 9 + 1;    // random number between 1 and 9
                    locaty = rand() % 9 + 1;    // random number between 1 and 9
                    if (Grid[locatx][locaty].location == false)
                    {
                        Grid[locatx][locaty].row = '#';
                        Grid[locatx][locaty].location = true;

                        if (ori == Vertical && Grid[locatx][locaty + 1].location == false && Grid[locatx][locaty - 1].location == false && Grid[locatx][locaty + 2].location == false && Grid[locatx][locaty - 2].location == false && Grid[locatx][locaty + 3].location == false && Grid[locatx][locaty - 3].location == false)
                        {
                            Grid[locatx][locaty + 1].row = '#';
                            Grid[locatx][locaty - 1].row = '#';
                            Grid[locatx][locaty + 2].row = '#';
                            Grid[locatx][locaty - 2].row = '#';
                            Grid[locatx][locaty + 3].row = '#';
                            Grid[locatx][locaty - 3].row = '#';

                            Grid[locatx][locaty + 1].location = true;
                            Grid[locatx][locaty - 1].location = true;
                            Grid[locatx][locaty + 2].location = true;
                            Grid[locatx][locaty - 2].location = true;
                            Grid[locatx][locaty + 3].location = true;
                            Grid[locatx][locaty - 3].location = true;
                            placed = true;

                        }
                        else if (ori == Horizontal && Grid[locatx + 1][locaty].location == false && Grid[locatx - 1][locaty].location == false && Grid[locatx + 2][locaty].location == false && Grid[locatx - 2][locaty].location == false && Grid[locatx + 3][locaty].location == false && Grid[locatx - 3][locaty].location == false)
                        {
                            Grid[locatx + 1][locaty].row = '#';
                            Grid[locatx - 1][locaty].row = '#';
                            Grid[locatx + 2][locaty].row = '#';
                            Grid[locatx - 2][locaty].row = '#';
                            Grid[locatx + 3][locaty].row = '#';
                            Grid[locatx - 3][locaty].row = '#';

                            Grid[locatx + 1][locaty].location = true;
                            Grid[locatx - 1][locaty].location = true;
                            Grid[locatx + 2][locaty].location = true;
                            Grid[locatx - 2][locaty].location = true;
                            Grid[locatx + 3][locaty].location = true;
                            Grid[locatx - 3][locaty].location = true;
                            placed = true;
                        }
                        else
                        {
                            placed = false;
                            Grid[locatx][locaty].location = false;
                            Grid[locatx][locaty].row = '~';
                        }
                    }
                    else
                    {
                        placed = false;
                    }
                    //}
                    break;
                case Carrier:
                    locatx = rand() % 9 + 1;    // random number between 1 and 9
                    locaty = rand() % 9 + 1;    // random number between 1 and 9
                    if (Grid[locatx][locaty].location == false)
                    {
                        Grid[locatx][locaty].row = '#';
                        Grid[locatx][locaty].location = true;
                        if (ori == Vertical && Grid[locatx][locaty + 1].location == false && Grid[locatx][locaty - 1].location == false && Grid[locatx][locaty + 2].location == false && Grid[locatx][locaty - 2].location == false && Grid[locatx][locaty + 3].location == false && Grid[locatx][locaty - 3].location == false && Grid[locatx][locaty + 4].location == false && Grid[locatx][locaty - 4].location == false)
                        {
                            Grid[locatx][locaty + 1].row = '#';
                            Grid[locatx][locaty - 1].row = '#';
                            Grid[locatx][locaty + 2].row = '#';
                            Grid[locatx][locaty - 2].row = '#';
                            Grid[locatx][locaty + 3].row = '#';
                            Grid[locatx][locaty - 3].row = '#';
                            Grid[locatx][locaty + 4].row = '#';
                            Grid[locatx][locaty - 4].row = '#';

                            Grid[locatx][locaty + 1].location = true;
                            Grid[locatx][locaty - 1].location = true;
                            Grid[locatx][locaty + 2].location = true;
                            Grid[locatx][locaty - 2].location = true;
                            Grid[locatx][locaty + 3].location = true;
                            Grid[locatx][locaty - 3].location = true;
                            Grid[locatx][locaty + 4].location = true;
                            Grid[locatx][locaty - 4].location = true;
                            placed = true;

                        }
                        else if (ori == Horizontal && Grid[locatx + 1][locaty].location == false && Grid[locatx - 1][locaty].location == false && Grid[locatx + 2][locaty].location == false && Grid[locatx - 2][locaty].location == false && Grid[locatx + 3][locaty].location == false && Grid[locatx - 3][locaty].location == false && Grid[locatx + 4][locaty].location == false && Grid[locatx - 4][locaty].location == false)
                        {
                            Grid[locatx + 1][locaty].row = '#';
                            Grid[locatx - 1][locaty].row = '#';
                            Grid[locatx + 2][locaty].row = '#';
                            Grid[locatx - 2][locaty].row = '#';
                            Grid[locatx + 3][locaty].row = '#';
                            Grid[locatx - 3][locaty].row = '#';
                            Grid[locatx + 4][locaty].row = '#';
                            Grid[locatx - 4][locaty].row = '#';

                            Grid[locatx + 1][locaty].location = true;
                            Grid[locatx - 1][locaty].location = true;
                            Grid[locatx + 2][locaty].location = true;
                            Grid[locatx - 2][locaty].location = true;
                            Grid[locatx + 3][locaty].location = true;
                            Grid[locatx - 3][locaty].location = true;
                            Grid[locatx + 4][locaty].location = true;
                            Grid[locatx - 4][locaty].location = true;
                            placed = true;
                        }
                        else
                        {
                            placed = false;
                            Grid[locatx][locaty].location = false;
                            Grid[locatx][locaty].row = '~';
                        }
                    }
                    //}
                    break;
                }
            }
            while (placed == false);

        }

}




// Prints the grid using only water, hit and miss marks
// Pre: A play grid has been created
// post: An updated grid is printed to the screen
void PrintGrid(battleship Grid [][11]){

    cout << Grid[0][0].row;    // very top left index of 2D array is a space

    cout << "  "; //Adds a space for neatness

    for (int i = 1; i < ROWS; i++){      // SHOULD print row of 2D array A - J

        cout << Grid[i][0].row;
        cout << " ";
    }

    cout << '\n';


    for (int i = 1; i < COLUMNS; i++){   // SHOULD print left most column of 2D array 1 - 10

        cout << Grid[0][i].column;

        if ( i != 10){
            cout << "  ";
        }

        else { //Will only print on space when the column is 10 since the integer messes with spacing

            cout << " ";
        }

        for (int j = 1; j < COLUMNS; j++){ //Prints the waves with spacing aligning with the row and column

                cout << Grid[i][j].row;
                cout << " ";
         }

        cout << '\n';
    }

}
