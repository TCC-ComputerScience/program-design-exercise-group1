#include <iostream>

//The program will generate a battleship game board. The user will guess the computer-generated location of the ships, and the gameboard will change to show the results.
struct battleship {
    bool shipLocation; //The true and false values of this array will determine where the ships will be placed on the 10x10 grid by random
    char battleMap; //This will print the entirety of the map and will change based on whether a ship has been hit or not
  };

  int ROW_MAX = 10; //Maximum row size
  int COL_MAX =10; //Maximum Column size

  using namespace std;

//Function to create a gameboard
//Pre: none
//Post: gameboard is created, probably best to use an array and convert the letter and number square ids to strings
//void Gameboard (string battleArray[][boardSize]);

//Function to create ships
//Pre: gameboard array ready
//Post: ship locations will be determined based on a random number. Will have to make sure that a ship stay on the board. Will have five different ship types. Structs for battleships.
void Ships(battleship battleArray[][10], battleship []);

//Function to get user guess
//Pre: gameboard is set up and ships are in place
//Post: The computer gets the user's guess
void UserGuess (string guess);

//Function to change gameboard
//Pre: gameboard is set up, ships are in place and user has guessed a location
//Post: The computer compares the user's guess to the location of the ships (the values that the ships contain) and changes the gameboard and responses based on the correct answers. The gameboard should update and display to show the results (not sure if this should be the Gameboard function or a new function yet)
bool KaBoom(string battleArray[][10], string shipArray[], string guess);

int main(){
    string battleArray[ROW_MAX][COL_MAX];
    string guess;
    bool gameON = false;
    while (gameON != true){
      //loop thourgh all the functions while there are still ships to find
      //KaBoom is true when all ships are found or when user decides to quit
   }
   return 0;
}

void Gameboard (string battleArray[][10]){
   //use 2d array to make gameboard and convert to string
}

void Ships(string battleArray[][10], string shipArray[]){
   //use random value for first space of ship's location
   //fill in remaining spaces in a straight line up, down or to the sides
 // save a list of different ships, array of arrays or array to structs
}

void UserGuess (string guess){
   //asks user for guess and records it in a string
}

bool KaBoom(string battleArray[][10], string shipArray[], string guess){
   //compares user guess to the ship values
   //changes the gameboard and notifies the user if its a hit or a miss
   //returns true if user quits or all the ships are found
}

