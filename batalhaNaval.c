#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    int matriz[10][10], linha, coluna;

    //INICIALIZANDO A MATRIZ COM TODAS AS POSIÇÕES EM 0
    for(linha=0; linha < 10; linha++){
        for(coluna=0; coluna < 10; coluna++){
            matriz[linha][coluna] = 0;
        }
    }

    for(linha=0; linha < 10; linha++){
        for(coluna=0; coluna < 10; coluna++){
            printf(" %4d", matriz[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
