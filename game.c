#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	char symbol;
    	int isComputer; // 0 = human, 1 = computer
} Player; 

void setupPlayers(Player players[3]) 
{
    	char symbols[3] = {'X', 'O', 'Z'};
    	int humanCount;

    	do 
	{
        	humanCount = 0;
        	for (int i = 0; i < 3; i++) 
		{
            		players[i].symbol = symbols[i];
            		printf("Is Player %c a computer? (1 for Yes, 0 for No): ", players[i].symbol);
            		scanf("%d", &players[i].isComputer);
            		if (players[i].isComputer == 0) 
			{
                		humanCount++;
            		}
        	}

        	if (humanCount == 0) 
		{
            		printf("At least one player must be a human. Please re-enter player roles.\n\n");
        	}
    	} 
	while (humanCount == 0);
}


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


int checkWin(char *board, int size, char symbol)
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

    	// Anti-diagonal (Top right to bottom left)
    	int diag2 = 0;
    	for (int i = 0; i < size; i++)
    	{
        	if (board[i * size + (size - 1 - i)] == symbol)
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
			{	
				fprintf(file, "|");
			}
        	}
        	fprintf(file, "\n");

        	if (i < size - 1)
        	{
            		for (int k = 0; k < size; k++)
            		{
                		fprintf(file, "---");
                		if (k < size - 1)
				{
                    			fprintf(file, "+");
				}
            		}
            		fprintf(file, "\n");
        	}
    	}

    	fprintf(file, "\n");
    	fclose(file);
}

int getComputerMove(char *board, int size) 
{
    	int totalCells = size * size;
    	int index;

    	while (1) 
	{
        	index = rand() % totalCells;
        	if (board[index] == ' ') 
        	{	
            		return index;
        	}
    	}
}

void playTwoPlayerGame(char *board, int size, Player players[2]) 
{
    	int currentPlayerIndex = 0;
    	int moveCount = 0;

    	while (1) 
	{
        	displayBoard(board, size);

        	Player currentPlayer = players[currentPlayerIndex];
        	int index;

        	if (currentPlayer.isComputer == 0) 
		{
            		// Human player's turn
            		int row, col;
            		while (1) 
			{
                		getUserInput(&row, &col, currentPlayer.symbol);
                		index = validateMove(board, size, row, col);
                		if (index != -1) 
				{
                    			board[index] = currentPlayer.symbol;
                    			break;
                		} 
				else 
				{
                    			printf("Invalid move. Try again.\n");
                		}
            		}
        	}	 
		else 
		{
            		// Computer's turn
            		index = getComputerMove(board, size);
            		board[index] = currentPlayer.symbol;

            		int row = index / size;
            		int col = index % size;
            		printf("Computer Player %c played at row %d, column %d\n", currentPlayer.symbol, row, col);
        	}

        	moveCount++;
        	logGameState(board, size, currentPlayer.symbol, moveCount);

        	if (checkWin(board, size, currentPlayer.symbol)) 
		{
            		displayBoard(board, size);
            		printf("Player %c wins!\n", currentPlayer.symbol);
            		break;
        	}

        	if (checkDraw(board, size)) 
		{
            		displayBoard(board, size);
            		printf("It's a draw!\n");
            		break;
        	}

        	currentPlayerIndex = (currentPlayerIndex + 1) % 2;
    	}
}

void playThreePlayerGame(char *board, int size, Player players[3]) 
{
    	int currentPlayerIndex = 0;
    	int moveCount = 0;

    	while (1) 
	{
        	displayBoard(board, size);

        	Player currentPlayer = players[currentPlayerIndex];
        	int index;

        	if (currentPlayer.isComputer == 0) 
		{
            		// Human player's turn
            		int row, col;
            		while (1) 
			{
                		getUserInput(&row, &col, currentPlayer.symbol);
                		index = validateMove(board, size, row, col);
                		if (index != -1) 
				{
                    			board[index] = currentPlayer.symbol;
                    			break;
                		} 
				else 
				{
				
                    			printf("Invalid move. Try again.\n");
                		}
            		}
        	} 
		else 
		{
            		// Computer's turn
            		index = getComputerMove(board, size);
            		board[index] = currentPlayer.symbol;

            		int row = index / size;
            		int col = index % size;
            		printf("Computer Player %c played at row %d, column %d\n", currentPlayer.symbol, row, col);
        	}

        	moveCount++;
        	logGameState(board, size, currentPlayer.symbol, moveCount);

        	if (checkWin(board, size, currentPlayer.symbol)) 
		{
            		displayBoard(board, size);
            		printf("Player %c wins!\n", currentPlayer.symbol);
            		break;
        	}

        	if (checkDraw(board, size)) 
		{
            		displayBoard(board, size);
            		printf("It's a draw!\n");
            		break;
        	}

        	currentPlayerIndex = (currentPlayerIndex + 1) % 3;
    	}
}


int main()
{
    	srand(time(NULL));

    	int size;
    	printf("Enter the size of the board (3-10): ");
    	scanf("%d", &size);

    	// Validate board size
    	if (size < 3 || size > 10)
    	{
        	printf("Invalid board size. Please enter a value between 3 and 10.\n");
       		return 1;
    	}

    	int mode;
    	printf("\nSelect Game Mode:\n");
    	printf("1. Two Players (User vs User)\n");
    	printf("2. User vs Computer\n");
    	printf("3. Three Players\n");
    	printf("Enter choice (1-3): ");
    	scanf("%d", &mode);

    	if (mode < 1 || mode > 3) 
    	{
        	printf("Invalid choice. Exiting.\n");
        	return 1;
    	}

    	// Initialize board
    	char *board = initializeBoard(size);

    	if (mode == 1) 
    	{
        	Player players[2] = 
        	{
            		{'X', 0},
            		{'O', 0}
        	};
        	playTwoPlayerGame(board, size, players);
    	}
    	else if (mode == 2) 
    	{
        	Player players[2] = 
        	{
            	{'X', 0},
            	{'O', 1}
        	};
        	playTwoPlayerGame(board, size, players);
    	}
    	else if (mode == 3)
    	{
        	Player players[3];
        	setupPlayers(players);
        	playThreePlayerGame(board, size, players);
    	}	       

    	// Free memory
    	free(board);
    	return 0;
}
