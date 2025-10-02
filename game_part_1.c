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

void getUserInput(int *row, int *col, char symbol)
{
    printf("Player %c, enter your move (row [space] column): ", symbol);
    scanf("%d %d", row, col);
}

int validateMove(char *board, int size, int row, int col)
{
    // Range validation
    if (row < 1 || row > size || col < 1 || col > size)
    {
        printf("Invalid position. Try again.\n");
        return -1; // Invalid
    }

    int index = (row - 1) * size + (col - 1);

    // Cell occupancy check
    if (board[index] != ' ')
    {
        printf("Cell already occupied. Try again.\n");
        return -1; // Invalid
    }

    return index; // Valid move
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

void logGameState(char *board, int size, char currentPlayer, int moveCount)
{
    FILE *file = fopen("game_log.txt", "a"); // Open in append mode
    if (file == NULL)
    {
        printf("Error opening log file.\n");
        return;
    }

    fprintf(file, "Move %d by Player %c:\n", moveCount, currentPlayer);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            fprintf(file, " %c ", board[i * size + j]);
            if (j < size - 1)
                fprintf(file, "|");
        }
        fprintf(file, "\n");

        if (i < size - 1)
        {
            for (int k = 0; k < size; k++)
            {
                fprintf(file, "---");
                if (k < size - 1)
                    fprintf(file, "+");
            }
            fprintf(file, "\n");
        }
    }

    fprintf(file, "\n");
    fclose(file);
}

int main()
{
    int size;
    printf("Enter the size of the board (3-10): ");
    scanf("%d", &size);

    // Validate board size
    if (size < 3 || size > 10)
    {
        printf("Invalid board size. Please enter a value between 3 and 10.\n");
        return 1;
    }

    // Initialize board
    char *board = initializeBoard(size);

    // Game variables
    char currentPlayer = 'X';
    int moveCount = 0;

    // Game loop
    while (1)
    {
        displayBoard(board, size);

        int row, col, index;

        // Accept and validate move
        while (1)
        {
            getUserInput(&row, &col, currentPlayer); // Accepting user input
            index = validateMove(board, size, row, col); // Validate user input and moves
            if (index != -1)
            {
                board[index] = currentPlayer;
                break;
            }
        }

        board[index] = currentPlayer;
        moveCount++;
        logGameState(board, size, currentPlayer, moveCount);

        // Check win condition
        if (checkWin(board, size, currentPlayer))
        {
            displayBoard(board, size);
            printf("Player %c wins!\n", currentPlayer);
            break;
        }

        // Check draw condition
        if (checkDraw(board, size))
        {
            displayBoard(board, size);
            printf("It's a draw!\n");
            break;
        }

        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        /*
            if (currentPlayer == 'X')
            {
                currentPlayer = 'O';
            }
            else
            {
                currentPlayer = 'X';
            }
        */
    }

    // Free memory
    free(board);
    return 0;
}
