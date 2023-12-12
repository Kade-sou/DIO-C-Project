#include <stdio.h>
#include <stdlib.h>

// Função para exibir o tabuleiro
void displayBoard(char board[3][3]) {
    printf("\n  1 2 3\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se um jogador venceu
int checkWin(char board[3][3], char player) {
    // Verificar linhas e colunas
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;  // O jogador venceu
        }
    }

    // Verificar diagonais
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;  // O jogador venceu
    }

    return 0;  // Nenhum jogador venceu ainda
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int row, col;
    char currentPlayer = 'X';

    while (1) {
        // Exibir o tabuleiro
        displayBoard(board);

        // Receber a jogada do jogador atual
        printf("Jogador %c, insira a linha e coluna (1-3): ", currentPlayer);
        scanf("%d %d", &row, &col);

        // Verificar se a posição está vazia
        if (board[row - 1][col - 1] == ' ') {
            // Fazer a jogada
            board[row - 1][col - 1] = currentPlayer;

            // Verificar se o jogador venceu
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                printf("Jogador %c venceu!\n", currentPlayer);
                break;
            }

            // Verificar empate
            int isFull = 1;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] == ' ') {
                        isFull = 0;
                        break;
                    }
                }
            }

            if (isFull) {
                displayBoard(board);
                printf("Empate!\n");
                break;
            }

            // Trocar de jogador
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            printf("Posição ocupada. Tente novamente.\n");
        }
    }

    return 0;
}

