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

void getPlayerMove (char *board, int size, char symbol)
{
    int row, col;
    while (1)
    {
        printf("Player %c, enter your move (row and column): ", symbol);
        scanf("%d %d", &row, &col);

        // Range validate
        if (row < 1 || row > size || col < 1 || col > size)
        {
            printf("Invalid position Try againn. \n");
            continue;
        }

        // Converts the 2D array to a 1D array
        int index = (row - 1) * size + (col - 1);

        // To check whether the cell is empty
        if (board[index] != ' ')
        {
            printf("Cell already occupied. Try again.\n");
            continue;
        }

        board[index] = symbol;
        break;


    }
}

int main ()
{
    int size;
    printf("Enter the size of the board (3-10): ");
    scanf("%d", &size);

    // Check board size
    while (size < 3 || size > 10)
    {
        printf("Invalid board size. Please enter a value between 3 and 10.\n");
        return 1;
    }

    // Initializing the game board - DONE
    char *board = initializeBoard(size);

    // Game variables - X and O
    char currentPlayer = 'X'; // Starts with X player
    int moveCount = 0;

    //Game loop
    while (1)
    {
        // Displaying the game board - DONE
        displayBoard(board, size);

        // Accepting user input - DONE
        getPlayerMove(board, size, currentPlayer); 

        // To switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        /* if (currentPlayer == 'X')
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

void getPlayerMove (char *board, int size, char symbol)
{
    int row, col;
    while (1)
    {
        printf("Player %c, enter your move (row and column): ", symbol);
        scanf("%d %d", &row, &col);

        // Range validate
        if (row < 1 || row > size || col < 1 || col > size)
        {
            printf("Invalid position Try againn. \n");
            continue;
        }

        // Converts the 2D array to a 1D array
        int index = (row - 1) * size + (col - 1);

        // To check whether the cell is empty
        if (board[index] != ' ')
        {
            printf("Cell already occupied. Try again.\n");
            continue;
        }

        board[index] = symbol;
        break;


    }
}

int main ()
{
    int size;
    printf("Enter the size of the board (3-10): ");
    scanf("%d", &size);

    // Check board size
    while (size < 3 || size > 10)
    {
        printf("Invalid board size. Please enter a value between 3 and 10.\n");
        return 1;
    }

    // Initializing the game board - DONE
    char *board = initializeBoard(size);

    // Game variables - X and O
    char currentPlayer = 'X'; // Starts with X player
    int moveCount = 0;

    //Game loop
    while (1)
    {
        // Displaying the game board - DONE
        displayBoard(board, size);

        // Accepting user input - DONE
        getPlayerMove(board, size, currentPlayer); 

        // To switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        /* if (currentPlayer == 'X')
            {
                currentPlayer = 'O';
            } 
            else {
                currentPlayer = 'X';
            }
        */
    }   


    // Validating user input and moves - DONE
    
    // Checking win conditions
    // Checking for a draw

    return (0);
}           {
                currentPlayer = 'O';
            } 
            else {
                currentPlayer = 'X';
            }
        */
    }   


    // Validating user input and moves - DONE
    
    // Checking win conditions
    // Checking for a draw

    return (0);
}
