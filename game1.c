#include <stdio.h>
#include <stdlib.h>

char *initializeBoard (int size)
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

void displayBoard (char *board, int size) 
// Need to bring the board array through a pointer. Size should also be brought for reference
// Returning only the board through the pointer
{

   /*
   If N = 6, Loop should be:
   [1] [2] [3] [4]
   [5] [6] [7] [8]
   [9] [10][11][12]
   [13][14][15][16]

   [i * size + j]
   */
   printf("\n");
   
   for (int i = 0; i < size; i++) // Loop through rows
   {
    for (int j = 0; j < size; j++) // Loop through columns
    {
        printf(" %c ", board[(i * size) + j]); // Print cells. Empty cells if no value is assigned yet to that address of the array
        if (j < size - 1) // Prints a seperator after each space (box)
        {
            printf("|"); 
        }
    }
    printf("\n");

    if (i<size -1) // Without the borders
    {
        for (int k = 0; k < size; k++) // Print the horizontal dividers
        {
            printf("---");

            if (k < size - 1) // Without the borders again print the intersection divider after each --- line
            {
                printf("+");
            }
        }
        printf("\n"); 
    }
   }
   printf("\n");
   

}

int main ()
{
    int size;
    printf("Enter the size of the board: ");
    scanf("%d", &size);

    // Initializing the game board - DONE
    char *board = initializeBoard(size);

    // Dissplaying the game board
    displayBoard(board, size);
    // Accepting user input
    // Validating user input and moves
    // Checking win conditions
    // Checking for a draw

    return (0);
}#include <stdio.h>
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
