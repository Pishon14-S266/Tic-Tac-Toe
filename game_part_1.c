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

int checkWin (char *board, int size, char symbol)
{
    
    
    // Check rows
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            if (board[i * size + j] == symbol)
            {
                count++;
            }
        }
        if (count == size)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < size; j++)
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (board[i * size + j] == symbol)
            {
                count++;
            }
        }
        if (count == size)
        {
            return 1;
        }
    }

    // Check main diagonal (Top left to bottom right)
    int diag1 = 0;
    for (int i = 0; i < size; i++)
    {
        if (board[i * size + i] == symbol)
        {
            diag1++;
        }
    }
    if (diag1 == size)
    {
        return 1;
    }

    // Check anti diagonal (Top right to bottom left)
    int diag2 = 0;
    for (int i = 0; i < size; i++)
    {
        if (board[i * size - 1 - i] == symbol)
        {
            diag2++;
        }
    }

    if (diag2 == size)
    {
        return 1;
    }

    // No win conditions met
    return 0;
}

int checkDraw(char *board, int size)
{
    for (int i = 0; i < size * size; i++)
    {
        if (board[i] == ' ')
        {
            return 0; // Still empty cells, not a draw
        }
    }
    return 1; // All cells filled, it's a draw
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

        // Validate and accepting user input - DONE
        getPlayerMove(board, size, currentPlayer); 

        // Track number of moves
        moveCount++; 

        // Checking win conditions
        if(checkWin(board, size, currentPlayer))
        {
            displayBoard(board, size);
            printf("Player %c wins!\n", currentPlayer);
            break;
        }

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

        // Checking for a draw
        if (checkDraw(board, size))
        {
            displayBoard(board, size);
            printf("It's a draw!\n");
            break;
        }
       
        
    }   
 
    return (0);
}
