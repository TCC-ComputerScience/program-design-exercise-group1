#include <iostream>

enum Marks {Hit, Miss, Water, Ship};
enum ShipType {None, Pat, Sub, Dest, Battle, Carrier};
enum Orientation {Horizontal, Vertical};

struct battleship{

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
void InitGrid(battleship Grid[][11]){

    char letter = 'A';
    int number = 1;


    Grid[0][0].row = ' ';

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
