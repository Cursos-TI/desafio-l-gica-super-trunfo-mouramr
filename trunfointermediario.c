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

void compararSimples(Carta c1, Carta c2, int opcao) {
    switch (opcao) {
        case 1:
            printf("\nComparando por população...\n");
            if (c1.populacao > c2.populacao)
                printf("Vencedora: %s (maior população)\n", c1.cidade);
            else if (c2.populacao > c1.populacao)
                printf("Vencedora: %s (maior população)\n", c2.cidade);
            else
                printf("Empate na população!\n");
            break;

        case 2:
            printf("\nComparando por área...\n");
            if (c1.area > c2.area)
                printf("Vencedora: %s (maior área)\n", c1.cidade);
            else if (c2.area > c1.area)
                printf("Vencedora: %s (maior área)\n", c2.cidade);
            else
                printf("Empate na área!\n");
            break;

        case 3:
            printf("\nComparando por PIB...\n");
            if (c1.pib > c2.pib)
                printf("Vencedora: %s (maior PIB)\n", c1.cidade);
            else if (c2.pib > c1.pib)
                printf("Vencedora: %s (maior PIB)\n", c2.cidade);
            else
                printf("Empate no PIB!\n");
            break;

        case 4:
            printf("\nComparando por pontos turísticos...\n");
            if (c1.pontos_turisticos > c2.pontos_turisticos)
                printf("Vencedora: %s (mais pontos turísticos)\n", c1.cidade);
            else if (c2.pontos_turisticos > c1.pontos_turisticos)
                printf("Vencedora: %s (mais pontos turísticos)\n", c2.cidade);
            else
                printf("Empate nos pontos turísticos!\n");
            break;

        default:
            printf("Opção inválida!\n");
    }
}

void compararAninhada(Carta c1, Carta c2) {
    printf("\nComparando por múltiplos atributos (População > PIB > Área > Pontos Turísticos)...\n");

    if (c1.populacao != c2.populacao) {
        compararSimples(c1, c2, 1);
    } else if (c1.pib != c2.pib) {
        compararSimples(c1, c2, 3);
    } else if (c1.area != c2.area) {
        compararSimples(c1, c2, 2);
    } else if (c1.pontos_turisticos != c2.pontos_turisticos) {
        compararSimples(c1, c2, 4);
    } else {
        printf("Total empate entre as cartas!\n");
    }
}

int main() {
    Carta carta1, carta2;
    int opcao;

    printf("Super Nível Aventureiro\n");

    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);

    exibirCarta(carta1);
    exibirCarta(carta2);

    do {
        printf("\nComparação:\n");
        printf("1. Comparar por população\n");
        printf("2. Comparar por área\n");
        printf("3. Comparar por PIB\n");
        printf("4. Comparar por pontos turísticos\n");
        printf("5. Comparação múltipla (pop > PIB > área > pontos)\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // limpa o buffer

        if (opcao >= 1 && opcao <= 4) {
            compararSimples(carta1, carta2, opcao);
        } else if (opcao == 5) {
            compararAninhada(carta1, carta2);
        } else if (opcao != 0) {
            printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    printf("\n Até mais!\n");
    return 0;
}
