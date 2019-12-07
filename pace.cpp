#include <iostream>

#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

enum Marks {Hit, Miss, Water, Ship};
enum ShipType {None, Pat, Sub, Dest, Battle, Carrier};
enum Orientation {Horizontal, Vertical};

struct battleship
{
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
void InitGrid(battleship Grid[][11])
{

    char letter = 'A';
    int number = 1;

    Grid[0][0].row = ' ';

    for (int i = 1; i < ROWS; i++)       // SHOULD make top row of Grid.letter of A - J
    {
        Grid[i][0].row = letter;
        letter++;
    }

    for (int i = 1; i < COLUMNS; i++)    // SHOULD make left most column of Grid.number 1 - 10
    {
        Grid[0][i].column = number;
        number++;
        // I changed number into an int to increment naturally
    }

    for (int i = 1; i < ROWS; i++)  //This sets every character in row in between the first column and first row waves
    {
        for (int j = 1; j < COLUMNS; j++)
        {
            Grid[i][j].row = '~';
        }
    }

    srand (time(NULL));
    int locatx, locaty;
    for (int c = 0; c < 5; c++)
    {
        int x = rand() % 7;    // generate random number between 0 - 6
        //int x = 2;
        int orient = rand() % 2;    // generate random number between 0 - 1
        //int orient = 2;
        ShipType boat = None;
        Orientation ori = Vertical;
        if(x == 0)
            boat = None;
        else if (x == 1)
            boat = Pat;
        else if (x == 2)
            boat = Sub;
        else if (x == 3)
            boat = Dest;
        else if (x == 4)
            boat = Battle;
        else
            boat = Carrier;

        if (orient == 0)
            ori = Vertical;
        else
            ori = Horizontal;

        switch (boat)
        {
        case None:
            break;
        case Pat:
            locatx = rand() % 9 + 1;    // random number between 1 and 9
            locaty = rand() % 9 + 1;    // random number between 1 and 9
            Grid[locatx][locaty].row = '#';
            break;
        case Sub:
            locatx = rand() % 9 + 1;    // random number between 1 and 9
            locaty = rand() % 9 + 1;    // random number between 1 and 9
            Grid[locatx][locaty].row = '#';
            if (ori == Vertical)
                Grid[locatx][locaty + 1].row = '#';
            else
                Grid[locatx + 1][locaty].row = '#';
            break;
        case Dest:
            locatx = rand() % 9 + 1;    // random number between 1 and 9
            locaty = rand() % 9 + 1;    // random number between 1 and 9
            Grid[locatx][locaty].row = '#';
            //for (int d = 0; d < 3; d++)
            //{
                if (ori == Vertical)
                {
                    Grid[locatx][locaty + 1].row = '#';
                    Grid[locatx][locaty - 1].row = '#';
                    Grid[locatx][locaty + 2].row = '#';
                    Grid[locatx][locaty - 2].row = '#';
                }
                else
                {
                    Grid[locatx + 1][locaty].row = '#';
                    Grid[locatx - 1][locaty].row = '#';
                    Grid[locatx + 2][locaty].row = '#';
                    Grid[locatx - 2][locaty].row = '#';
                }
            //}
            break;
        case Battle:
            locatx = rand() % 9 + 1;    // random number between 1 and 9
            locaty = rand() % 9 + 1;    // random number between 1 and 9
            Grid[locatx][locaty].row = '#';
            //for (int d = 0; d < 4; d++)
            //{
                if (ori == Vertical)
                {
                    Grid[locatx][locaty + 1].row = '#';
                    Grid[locatx][locaty - 1].row = '#';
                    Grid[locatx][locaty + 2].row = '#';
                    Grid[locatx][locaty - 2].row = '#';
                    Grid[locatx][locaty + 3].row = '#';
                    Grid[locatx][locaty - 3].row = '#';

                }
                else
                {
                    Grid[locatx + 1][locaty].row = '#';
                    Grid[locatx - 1][locaty].row = '#';
                    Grid[locatx + 2][locaty].row = '#';
                    Grid[locatx - 2][locaty].row = '#';
                    Grid[locatx + 3][locaty].row = '#';
                    Grid[locatx - 3][locaty].row = '#';
                }
            //}
            break;
        case Carrier:
            locatx = rand() % 9 + 1;    // random number between 1 and 9
            locaty = rand() % 9 + 1;    // random number between 1 and 9
            Grid[locatx][locaty].row = '#';
            //for (int d = 0; d < 5; d++)
            //{
                if (ori == Vertical)
                {
                    Grid[locatx][locaty + 1].row = '#';
                    Grid[locatx][locaty - 1].row = '#';
                    Grid[locatx][locaty + 2].row = '#';
                    Grid[locatx][locaty - 2].row = '#';
                    Grid[locatx][locaty + 3].row = '#';
                    Grid[locatx][locaty - 3].row = '#';
                    Grid[locatx][locaty + 4].row = '#';
                    Grid[locatx][locaty - 4].row = '#';

                }
                else
                {
                    Grid[locatx + 1][locaty].row = '#';
                    Grid[locatx - 1][locaty].row = '#';
                    Grid[locatx + 2][locaty].row = '#';
                    Grid[locatx - 2][locaty].row = '#';
                    Grid[locatx + 3][locaty].row = '#';
                    Grid[locatx - 3][locaty].row = '#';
                    Grid[locatx + 4][locaty].row = '#';
                    Grid[locatx - 4][locaty].row = '#';
                }
            //}
            break;
        }
    }
}


// Prints the grid using only water, hit and miss marks
// Pre: A play grid has been created
// post: An updated grid is printed to the screen
void PrintGrid(battleship Grid [][11])
{

    cout << Grid[0][0].row;    // very top left index of 2D array is a space

    cout << "  "; //Adds a space for neatness

    for (int i = 1; i < ROWS; i++)       // SHOULD print row of 2D array A - J
    {

        cout << Grid[i][0].row;
        cout << " ";
    }

    cout << '\n';


    for (int i = 1; i < COLUMNS; i++)    // SHOULD print left most column of 2D array 1 - 10
    {

        cout << Grid[0][i].column;

        if ( i != 10)
        {
            cout << "  ";
        }

        else   //Will only print on space when the column is 10 since the integer messes with spacing
        {
            cout << " ";
        }

        for (int j = 1; j < COLUMNS; j++)  //Prints the waves with spacing aligning with the row and column
        {

            cout << Grid[i][j].row;
            cout << " ";
        }

        cout << '\n';
    }

}
