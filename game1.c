#include <stdio.h>
#include <stdlib.h>

char initializeBoard(int size) {
    int totalCells = size * size;
    char board = malloc(totalCells);

    if (board == NULL) {
        printf("Memory Allocation failed\n");
        
    }

    for (int i = 0; i < totalCells; i++) {
        board[i] = ' ';
    }

    return board;
}
