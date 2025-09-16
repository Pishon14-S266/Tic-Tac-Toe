#include <stdio.h>
#include <stdlib.h>

char *initializeBoard(int size)
{
    int totalBoxes = size * size;
    char *board = malloc(totalBoxes);

    if (board == NULL)
    {
        printf ("Memory Allocation failed\n");
        exit (1);
    }

    for (int i = 0;  i < totalBoxes; i++)
    {
      board[i] = ' ';

    }
    return board;
    

}   

char *displayBoard ()
{
    
}

int main ()
{
    int size;
    printf("Enter the size of the board: ");
    scanf("%d", &size);

    // Initializing the game board - DONE
    intializeBoard(size);

    // Dissplaying the game board
    // Accepting user input
    // Validating user input and moves
    // Checking win conditions
    // Checking for a draw

    return (0);
}
