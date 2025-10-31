#include <stdio.h>

int main() {
    // Definindo o número de casas a mover 
    const int casasParaBaixo = 2;
    const int casasParaEsquerda = 1;

    printf("Movimento do Cavalo (2 casas para baixo, 1 para a esquerda):\n");

    // Movimenta o cavalo para baixo 2 vezes usei o FOR
    for (int i = 0; i < casasParaBaixo; i++) {
        printf("Baixo\n");

        // Movimenta o cavalo para a esquerda usei while
        int movimentosEsquerdaRestantes = casasParaEsquerda;
        while (movimentosEsquerdaRestantes > 0) {
            printf("Esquerda\n");
            movimentosEsquerdaRestantes--;
        }
    }

    printf("\n"); // Linha em branco separando do restante do programa

    return 0;
}
