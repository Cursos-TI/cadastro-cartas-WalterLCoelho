#include <stdio.h>

// Movimentando a Torre com uma função Recursiva
void torreRecursiva(int moveCount, int direcao) {
    if (moveCount <= 0) return; 

    switch (direcao) {
        case 0: printf("Cima\n"); break;
        case 1: printf("Baixo\n"); break;
        case 2: printf("Esquerda\n"); break;
        case 3: printf("Direita\n"); break;
    }
    torreRecursiva(moveCount - 1, direcao);
}

// Movimentando o Bisco com uma função Recursiva

void bispoRecursivo(int moveCount, int movHorizontal, int movVertical) {
    if (moveCount <= 0) return; 

    // movimento diagonal: imprimir direção vertical e horizontal
    if (movVertical == 1) printf("Cima\n");
    else printf("Baixo\n");

    if (movHorizontal == 1) printf("Direita\n");
    else printf("Esquerda\n");

    bispoRecursivo(moveCount - 1, movHorizontal, movVertical);
}

// Loops aninhados, simula os movimentos em diagonal para cima-direita por exemplo
void bispoLoopsAninhados(int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {     // loop vertical (ex: casas para cima)
        printf("Cima\n");
        for (int j = 0; j < colunas; j++) { // loop horizontal (ex: casas para direita)
            printf("Direita\n");
        }
    }
}

// Função recursiva Movimento Rainha
void rainhaRecursiva(int moveCount, int movHorizontal, int movVertical, int movimentoTipo) {
    if (moveCount <= 0) return;

    // movimentoTipo: 0=linha (torre), 1=diagonal (bispo)
    if (movimentoTipo == 0) {
        // movimento linha (torre)
        switch (movHorizontal) {
            case 0: // vertical
                if (movVertical == 1) printf("Cima\n");
                else if (movVertical == -1) printf("Baixo\n");
                break;
            case 1: // horizontal
                if (movHorizontal == 1) printf("Direita\n");
                else if (movHorizontal == -1) printf("Esquerda\n");
                break;
        }
    }
    else if (movimentoTipo == 1) {
        // movimento diagonal (bispo)
        if (movVertical == 1) printf("Cima\n");
        else if (movVertical == -1) printf("Baixo\n");

        if (movHorizontal == 1) printf("Direita\n");
        else if (movHorizontal == -1) printf("Esquerda\n");
    }

    rainhaRecursiva(moveCount - 1, movHorizontal, movVertical, movimentoTipo);
}

// Loop aninhados para o movimento do cavalo para cima e direita em "L"
void cavaloLoopsComplexos(int movimentosVerticais, int movimentosHorizontais) {
    for (int i = 0; i < movimentosVerticais; i++) { // movimenta verticalmente (2 casas para cima)
        for (int j = 0; j < movimentosHorizontais; j++) { // movimenta horizontalmente (1 casa para direita)
            if (i == 2 && j == 1) {
                break; // break evita movimentação inválida
            }
            if (i == 0 && j == 0) {
                continue; // ignora o movimento zero-zero
            }
            if (i < 2 && j < 1) {
                printf("Cima\n");
                printf("Cima\n");
                printf("Direita\n");
            }
        }
    }
}

int main() {
    int movimentoCasas = 3;

    // Torre - Recursivo (exemplo: mover para cima)
    printf("Torre - movimento recursivo (Cima):\n");
    torreRecursiva(movimentoCasas, 0);

    printf("\n");

    // Bispo - Recursivo (exemplo: diagonal para cima-direita)
    printf("Bispo - movimento recursivo (Diagonal Cima-Direita):\n");
    bispoRecursivo(movimentoCasas, 1, 1);

    printf("\n");

    // Bispo - Loops aninhados
    printf("Bispo - movimento com loops aninhados:\n");
    bispoLoopsAninhados(movimentoCasas, movimentoCasas);

    printf("\n");

    // Rainha - Recursivo (exemplo: movimento diagonal)
    printf("Rainha - movimento recursivo (Diagonal Cima-Direita):\n");
    rainhaRecursiva(movimentoCasas, 1, 1, 1);

    printf("\n");

    // Cavalo - Loops complexos para cima e direita em "L"
    printf("Cavalo - movimento complexo com loops aninhados (2 para cima, 1 para direita):\n");
    cavaloLoopsComplexos(2, 1);

    return 0;
}
