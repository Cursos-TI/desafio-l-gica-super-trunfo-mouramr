#include <stdio.h>
#include <string.h>

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

void compararCartas(Carta c1, Carta c2, char atributo[]) {
    printf("\n Comparação: %s\n", atributo);
    
    if (strcmp(atributo, "populacao") == 0) {
        if (c1.populacao > c2.populacao)
            printf("Vencedora: %s (maior população)\n", c1.cidade);
        else if (c2.populacao > c1.populacao)
            printf("Vencedora: %s (maior população)\n", c2.cidade);
        else
            printf("Empate na população!\n");
    } else if (strcmp(atributo, "area") == 0) {
        if (c1.area > c2.area)
            printf("Vencedora: %s (maior área)\n", c1.cidade);
        else if (c2.area > c1.area)
            printf("Vencedora: %s (maior área)\n", c2.cidade);
        else
            printf("Empate na área!\n");
    } else if (strcmp(atributo, "pib") == 0) {
        if (c1.pib > c2.pib)
            printf("Vencedora: %s (maior PIB)\n", c1.cidade);
        else if (c2.pib > c1.pib)
            printf("Vencedora: %s (maior PIB)\n", c2.cidade);
        else
            printf("Empate no PIB!\n");
    } else if (strcmp(atributo, "pontos") == 0) {
        if (c1.pontos_turisticos > c2.pontos_turisticos)
            printf("Vencedora: %s (mais pontos turísticos)\n", c1.cidade);
        else if (c2.pontos_turisticos > c1.pontos_turisticos)
            printf("Vencedora: %s (mais pontos turísticos)\n", c2.cidade);
        else
            printf("Empate em pontos turísticos!\n");
    } else {
        printf("Atributo inválido!\n");
    }
}

int main() {
    Carta carta1, carta2;
    char atributo[MAX];

    printf("Super Trunfo Comparação das Cartas\n");

    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);

    exibirCarta(carta1);
    exibirCarta(carta2);

    printf("\nEscolha o atributo para comparar (populacao, area, pib, pontos): ");
    fgets(atributo, MAX, stdin);
    atributo[strcspn(atributo, "\n")] = 0;

    compararCartas(carta1, carta2, atributo);

    return 0;
}
