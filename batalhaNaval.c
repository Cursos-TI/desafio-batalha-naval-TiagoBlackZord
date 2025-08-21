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
        printf(" %2d ", i + 1); // %2d é para dar espaço entre os números... Só isso
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
    int linhaH = 1, colunaH = 1; // Navio horizontal
    int linhaV = 3, colunaV = 2; // Navio vertical
    int linhaC = 5, colunaC = 5; // Navio diagonal
    int linhaC2 = 6, colunaC2 = 1; // Segundo navio na diagonal

    // VERIFICA OS LIMITES DO TABULEIRO
    if (linhaH < 10 && colunaH + 3 <= 10 && linhaV + 3 <= 10 && colunaV < 10 && linhaC + 3 <= 10 && colunaC < 10 && linhaC2 + 3 <= 10 && colunaC2 < 10) {

        // POSICIONA O NAVIO NA HORIZONTAL
        for (int i = 0; i < 3; i++) {
            if(matriz[linhaC + i][colunaC] == 3){
                printf("Erro: sobreposição de navios!\n");
                return 1;
            }else{
                matriz[linhaH][colunaH + i] = 3;
                navioHorizontal[i] = colunaH + i;
            }
        }

        //POSICIONA O NAVIO NA DIAGONAL
        for(int i=0; i < 3; i++){
            if(matriz[linhaC + i][colunaC] == 3){
                printf("Erro: sobreposição de navios!\n");
                return 1;
            }else{
                matriz[linhaC][colunaC] = 3;
                linhaC = linhaC + 1;
                colunaC = colunaC + 1;
            }
        }
        //POSICIONA SEGUNDO NAVIO NA DIAGONAL
        for(int i=0; i < 3; i++){
            if(matriz[linhaC + i][colunaC] == 3){
                printf("Erro: sobreposição de navios!\n");
                return 1;
            }else{
                matriz[linhaC2][colunaC2] = 3;
                linhaC2 = linhaC2 + 1;
                colunaC2 = colunaC2 + 1;
            }
        }

        // POSICIONA O NAVIO NA VERTICAL
        for (int i = 0; i < 3; i++) {
            // VERIFICA SE EXISTE SOBREPOSIÇÃO
            if (matriz[linhaV + i][colunaV] == 3) {
                printf("Erro: sobreposição de navios!\n");
                return 1;
            }else{
                matriz[linhaV + i][colunaV] = 3;
                navioVertical[i] = linhaV + i;
            }
        }
    } else {
        printf("Erro: navios fora dos limites do tabuleiro.\n\n");
        return 1;
    }

    mostrarMatriz(matriz);

    return 0;
}
