#include <stdio.h>

int main() {
    // Definição do movimento de cada peça
    int casasTorre = 5;
    int casasBispo = 5;
    int casasRainha = 8;

    // A torre se mopvera 5 casas para a direita, usei a estrutura FOR
    printf("Movimento da Torre:\n");
    for (int i = 0; i < casasTorre; i++) {
        printf("Direita\n");
    }

    // Bispo se movera 5 casas na diagonal para cima e para a direita, usei a estrutura WHILE
        printf("\nMovimento do Bispo:\n");
    int contadorBispo = 0;
    while (contadorBispo < casasBispo) {
        printf("Cima, Direita\n");
        contadorBispo++;
    }

    // Rainha se movera 8 casas para a esquerda, usei a estrutura do-while
    printf("\nMovimento da Rainha:\n");
    int contadorRainha = 0;
    do {
        printf("Esquerda\n");
        contadorRainha++;
    } while (contadorRainha < casasRainha);

    return 0;
}
