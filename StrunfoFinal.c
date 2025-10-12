#include <stdio.h>
#include <string.h>

// Struct da Carta
typedef struct {
    char estado;
    char codigo[5];
    char nomeCidade[50];
    unsigned long populacao;     // Use unsigned long para grandes valores
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
    float superPoder;
} Carta;

// Calcula propriedades derivadas e Super Poder
void calcularPropriedades(Carta *c) {
    c->densidade = c->populacao / c->area;
    c->pibPerCapita = c->pib / c->populacao;
    // Super Poder: soma de todos os atributos, invertendo a densidade
    c->superPoder = c->populacao + c->area + c->pib + c->pontosTuristicos + c->pibPerCapita + (1.0f / c->densidade);
}

void exibirCarta(const Carta *c, int n) {
    printf("Carta %d:\n", n);
    printf("Estado: %c\n", c->estado);
    printf("Código: %s\n", c->codigo);
    printf("Nome da Cidade: %s\n", c->nomeCidade);
    printf("População: %lu\n", c->populacao);
    printf("Área: %.2f km²\n", c->area);
    printf("PIB: %.2f\n", c->pib);
    printf("Pontos Turísticos: %d\n", c->pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", c->densidade);
    printf("PIB per capita: %.4f\n", c->pibPerCapita);
    printf("Super Poder: %.4f\n", c->superPoder);
    printf("\n");
}

void comparar(const char *nome, float v1, float v2, int tipoDensaMenorGanha) {
    // tipoDensaMenorGanha=1: menor vence. Caso contrário: maior vence.
    printf("%s - Carta 1: %.4f | Carta 2: %.4f => ", nome, v1, v2);
    if ((tipoDensaMenorGanha && v1 < v2) || (!tipoDensaMenorGanha && v1 > v2)) {
        printf("Carta 1 vence\n");
    } else if ((tipoDensaMenorGanha && v1 > v2) || (!tipoDensaMenorGanha && v1 < v2)) {
        printf("Carta 2 vence\n");
    } else {
        printf("Empate\n");
    }
}

int main() {
    Carta c1, c2;

    // Cadastro Carta 1
    printf("Insira os dados da Carta 1:\n");
    printf("Estado (A-H): "); scanf(" %c", &c1.estado);
    printf("Código: "); scanf("%s", c1.codigo);
    printf("Nome da Cidade: "); scanf(" %[^\n]", c1.nomeCidade);
    printf("População: "); scanf("%lu", &c1.populacao);
    printf("Área: "); scanf("%f", &c1.area);
    printf("PIB: "); scanf("%f", &c1.pib);
    printf("Pontos Turísticos: "); scanf("%d", &c1.pontosTuristicos);

    calcularPropriedades(&c1);

    // Cadastro Carta 2
    printf("\nInsira os dados da Carta 2:\n");
    printf("Estado (A-H): "); scanf(" %c", &c2.estado);
    printf("Código: "); scanf("%s", c2.codigo);
    printf("Nome da Cidade: "); scanf(" %[^\n]", c2.nomeCidade);
    printf("População: "); scanf("%lu", &c2.populacao);
    printf("Área: "); scanf("%f", &c2.area);
    printf("PIB: "); scanf("%f", &c2.pib);
    printf("Pontos Turísticos: "); scanf("%d", &c2.pontosTuristicos);

    calcularPropriedades(&c2);

    // Exibe cartas
    printf("\n--- CARTAS CADASTRADAS ---\n");
    exibirCarta(&c1, 1);
    exibirCarta(&c2, 2);

    // Comparação
    printf("--- RESULTADO DAS COMPARAÇÕES ---\n");
    comparar("População", (float)c1.populacao, (float)c2.populacao, 0);
    comparar("Área", c1.area, c2.area, 0);
    comparar("PIB", c1.pib, c2.pib, 0);
    comparar("Pontos Turísticos", (float)c1.pontosTuristicos, (float)c2.pontosTuristicos, 0);
    comparar("Densidade Populacional", c1.densidade, c2.densidade, 1); // aqui menor vence
    comparar("PIB per capita", c1.pibPerCapita, c2.pibPerCapita, 0);
    comparar("Super Poder", c1.superPoder, c2.superPoder, 0);

    return 0;
}
