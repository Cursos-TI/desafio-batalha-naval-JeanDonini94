#include <stdio.h>
#include <stdlib.h> 

#define SIZE 10
#define HSIZE 5

void Tabuleiro(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void habilidade(int board[SIZE][SIZE], int skill[HSIZE][HSIZE], int originX, int originY) {
    int startX = originX - HSIZE / 2;
    int startY = originY - HSIZE / 2;

    for (int i = 0; i < HSIZE; i++) {
        for (int j = 0; j < HSIZE; j++) {
            int x = startX + i;
            int y = startY + j;
            if (x >= 0 && x < SIZE && y >= 0 && y < SIZE && skill[i][j] == 1) {
                board[x][y] = 5;
            }
        }
    }
}
//Criando as habilidades
void Cone(int skill[HSIZE][HSIZE]) {
    for (int i = 0; i < HSIZE; i++) {
        for (int j = 0; j < HSIZE; j++) {
            if (j >= HSIZE / 2 - i && j <= HSIZE / 2 + i) {
                skill[i][j] = 1;
            } else {
                skill[i][j] = 0;
            }
        }
    }
}

void Cruz(int skill[HSIZE][HSIZE]) {
    for (int i = 0; i < HSIZE; i++) {
        for (int j = 0; j < HSIZE; j++) {
            if (i == HSIZE / 2 || j == HSIZE / 2) {
                skill[i][j] = 1;
            } else {
                skill[i][j] = 0;
            }
        }
    }
}

void Octaedro(int skill[HSIZE][HSIZE]) {
    for (int i = 0; i < HSIZE; i++) {
        for (int j = 0; j < HSIZE; j++) {
            if (abs(i - HSIZE / 2) + abs(j - HSIZE / 2) <= HSIZE / 2) {
                skill[i][j] = 1;
            } else {
                skill[i][j] = 0;
            }
        }
    }
}

int main() {
    int board[SIZE][SIZE] = {0};
    int coneSkill[HSIZE][HSIZE];
    int cruzSkill[HSIZE][HSIZE];
    int octaedroSkill[HSIZE][HSIZE];

    // Definindo um navio no tabuleiro
    board[4][4] = 3;
    board[4][5] = 3;
    board[4][6] = 3;

    // Criando habilidades
    Cone(coneSkill);
    Cruz(cruzSkill);
    Octaedro(octaedroSkill);

    // Aplicando habilidades no tabuleiro
    habilidade(board, coneSkill, 2, 2);
    habilidade(board, cruzSkill, 5, 5);
    habilidade(board, octaedroSkill, 7, 7);

    // Exibindo o tabuleiro
    Tabuleiro(board);

    return 0;
}
