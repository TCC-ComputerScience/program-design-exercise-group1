PACE/Github Assignment -- Part 3 (Beginning Implementation): Battleship.cpp

InitGrid function:
-Set the char value of first position of the grid to nothing
for i less than 11
    -Set char value to A-J from [1][0] onwards to [10][0]
    -Set char value to 1-10 from [0][1] onwards to [0][10]
End of loop
-Call PlaceShip function
End of function

PlaceShip function:
for i = 1 less than row
    -for j = 1 less than column
        -Randomly select integer from 0-5
        -Select the ship based on the integer selected
        -if ship != NONE and int variables for any of the ships are not zero
            -Randomly select integer form 0-1
            -Select ship oreintation based on the integer selected
            -Start placing setting bool values of array ship to true horizontally or vertically
            -Check to ensure that there is no overlap between the ships
            -Decerement an int variable that keeps track of the number of that particualr ship type
        -else
            array ship [i][j] bool variabel equals false
    End of for loop
End of for loop

PrintGrid function:
    -Print blank space in the first array position
    -Print the array row with the letter grid
    -Print the array column with the number grid along with the waves of the rest of the array
End of function
