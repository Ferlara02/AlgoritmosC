#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define BOARD_SIZE 4
#define WIN_CONDITION BOARD_SIZE
#define CELL_MAX (BOARD_SIZE * BOARD_SIZE - 1)

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    int cell = 0;

    print_sep(BOARD_SIZE);
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int column = 0; column < BOARD_SIZE; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(BOARD_SIZE);
    }
}

char get_winner(char board[BOARD_SIZE][BOARD_SIZE]) {
    char winner = '-';
    for (int i = 0; i < BOARD_SIZE; ++i) {
     bool row_win = true;
        bool col_win = true;
        char row_first = board[i][0];
        char col_first = board[0][i];
        
        if (row_first == '-') row_win = false;
        if (col_first == '-') col_win = false;
        
        for (int j = 1; j < BOARD_SIZE; ++j) {
            if (board[i][j] != row_first) row_win = false;
            if (board[j][i] != col_first) col_win = false;
        }
        if (row_win) return row_first;
        if (col_win) return col_first;
    }
    
    // Verificar diagonales
    /*if (board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] = board[3][3]) {
        winner = board[0][0]; // Gana en la diagonal principal
    }
    if (board[0][3] != '-' && board[0][3] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == board[3][3]) {
        winner = board[0][2]; // Gana en la diagonal secundaria
    }*/
    
    return winner;
}

bool has_free_cell(char board[4][4])
{
    bool free_cell = false;
    for (int row = 0; row < 4; ++row) {
        for (int column = 0; column < 4; ++column) {
            if(board[row][column] == '-') {
                free_cell = true;
            }
        }
        printf("\t | \n");
        print_sep(4);
    }
    return free_cell;
}

int main(void)
{
    printf("TicTacToe [InCoMpLeTo :'(]\n");

    char board[4][4] = {
        { '-', '-', '-', '-' },
        { '-', '-', '-', '-' },
        { '-', '-', '-', '-' }, 
        { '-', '-', '-', '-' }
    };

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn, CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / 3;
            int colum = cell % 3;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}
