#include <stdio.h>

void mostrarMatriz(int matriz[10][10]){

     // CABEÇALHO COM LETRAS
    printf("    ");
    for (int cabecalho = 0; cabecalho < 10; cabecalho++) {
        printf("  %c ", 'A' + cabecalho);
    }
    printf("\n\n");

    // IMPRIME LINHA VERTICAL COM O NÚMERO DA LINHA
    for (int i = 0; i < 10; i++) {
        printf(" %2d ", i + 1);
        //IMPRIME O CONTEÚDO DA MATRIZ 
        for (int j = 0; j < 10; j++) {
            printf(" %2d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

int main() {
    int matriz[10][10], navioHorizontal[3], navioVertical[3];

    //INICIALIZANDO A MATRIZ COM TODAS AS POSIÇÕES EM 0
    for(int linha=0; linha < 10; linha++){
        for(int coluna=0; coluna < 10; coluna++){
            matriz[linha][coluna] = 0;
        }
    }


    // COORDENADAS DOS NAVIOS
    int linhaH = 2, colunaH = 4; // Navio horizontal
    int linhaV = 5, colunaV = 7; // Navio vertical

    // VERIFICA OS LIMITES DO TABULEIRO
    if (colunaH + 3 <= 10 && linhaV + 3 <= 10) {
        // POSICIONA O NAVIO NA HORIZONTAL
        for (int i = 0; i < 3; i++) {
            matriz[linhaH][colunaH + i] = 3;
            navioHorizontal[i] = colunaH + i;
        }

        // POSICIONA O NAVIO NA VERTICAL
        for (int i = 0; i < 3; i++) {
            // VERIFICA SE EXISTE SOBREPOSIÇÃO
            if (matriz[linhaV + i][colunaV] == 3) {
                printf("Erro: sobreposição de navios!\n");
                return 1;
            }
            matriz[linhaV + i][colunaV] = 3;
            navioVertical[i] = linhaV + i;
        }
    } else {
        printf("Erro: navios fora dos limites do tabuleiro.\n");
        return 1;
    }

    mostrarMatriz(matriz);

    return 0;
}
