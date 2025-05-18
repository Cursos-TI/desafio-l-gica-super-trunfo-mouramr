#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    char estado[MAX];
    int codigo;
    char cidade[MAX];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Carta;

void cadastrarCarta(Carta *carta, int numero) {
    printf("\n--- Cadastro da Carta %d ---\n", numero);

    printf("Estado: ");
    fgets(carta->estado, MAX, stdin);
    carta->estado[strcspn(carta->estado, "\n")] = 0;

    char buffer[100];

    printf("Código da carta: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &carta->codigo);

    printf("Nome da cidade: ");
    fgets(carta->cidade, MAX, stdin);
    carta->cidade[strcspn(carta->cidade, "\n")] = 0;

    printf("População: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &carta->populacao);

    printf("Área (km²): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%f", &carta->area);

    printf("PIB (em bilhões): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%f", &carta->pib);

    printf("Nº de pontos turísticos: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &carta->pontos_turisticos);
}

void exibirCarta(Carta carta) {
    printf("\n=== Carta da Cidade: %s ===\n", carta.cidade);
    printf("Estado: %s\n", carta.estado);
    printf("Código: %d\n", carta.codigo);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pontos_turisticos);
}

int compararAtributoInt(int a1, int a2) {
    return (a1 > a2) ? 1 : (a1 < a2) ? -1 : 0;
}

int compararAtributoFloat(float a1, float a2) {
    return (a1 > a2) ? 1 : (a1 < a2) ? -1 : 0;
}

void compararDuplo(Carta c1, Carta c2, int atr1, int atr2) {
    int pontosC1 = 0, pontosC2 = 0;

    // Atributo 1
    int r1 = 0;
    switch (atr1) {
        case 1: r1 = compararAtributoInt(c1.populacao, c2.populacao); break;
        case 2: r1 = compararAtributoFloat(c1.area, c2.area); break;
        case 3: r1 = compararAtributoFloat(c1.pib, c2.pib); break;
        case 4: r1 = compararAtributoInt(c1.pontos_turisticos, c2.pontos_turisticos); break;
        default: printf("Atributo 1 inválido!\n"); return;
    }

    // Atributo 2
    int r2 = 0;
    switch (atr2) {
        case 1: r2 = compararAtributoInt(c1.populacao, c2.populacao); break;
        case 2: r2 = compararAtributoFloat(c1.area, c2.area); break;
        case 3: r2 = compararAtributoFloat(c1.pib, c2.pib); break;
        case 4: r2 = compararAtributoInt(c1.pontos_turisticos, c2.pontos_turisticos); break;
        default: printf("Atributo 2 inválido!\n"); return;
    }

    // Soma pontos
    pontosC1 += (r1 == 1) + (r2 == 1);
    pontosC2 += (r1 == -1) + (r2 == -1);

    printf("\nResultado da comparação:\n");
    printf("Pontos %s: %d\n", c1.cidade, pontosC1);
    printf("Pontos %s: %d\n", c2.cidade, pontosC2);

    if (pontosC1 > pontosC2)
        printf("Vencedora: %s\n", c1.cidade);
    else if (pontosC2 > pontosC1)
        printf("Vencedora: %s\n", c2.cidade);
    else
        printf("Empate!\n");
}

void mostrarAtributos() {
    printf("\nAtributos disponíveis:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos turísticos\n");
}

int main() {
    Carta carta1, carta2;
    int atr1, atr2;

    printf("Nível Mestre\n");

    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);

    exibirCarta(carta1);
    exibirCarta(carta2);

    mostrarAtributos();
    printf("Escolha o 1º atributo (1 a 4): ");
    scanf("%d", &atr1);
    printf("Escolha o 2º atributo (1 a 4): ");
    scanf("%d", &atr2);

    compararDuplo(carta1, carta2, atr1, atr2);

    printf("\nFim de Jogo!\n");

    return 0;
}
