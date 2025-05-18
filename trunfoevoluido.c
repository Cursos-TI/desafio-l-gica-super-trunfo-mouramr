#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CARTAS 100
#define MAX_NOME 100

// Estrutura de Carta
typedef struct {
    char codigo[10];
    char nome[MAX_NOME];
    int populacao;
    float area;
    float pib;
    int ativa; // Para modo mata-mata
} Carta;

// Função para carregar cartas do arquivo
int carregarCartas(Carta cartas[], const char *nomeArquivo) {
    FILE *file = fopen(nomeArquivo, "r");
    if (!file) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        return 0;
    }

    int i = 0;
    while (fscanf(file, "%[^|]|%[^|]|%d|%f|%f\n",
                  cartas[i].codigo,
                  cartas[i].nome,
                  &cartas[i].populacao,
                  &cartas[i].area,
                  &cartas[i].pib) == 5) {
        cartas[i].ativa = 1;
        i++;
    }

    fclose(file);
    return i;
}

// Função para exibir carta
void exibirCarta(Carta c) {
    printf("\n[Carta: %s] %s\nPopulacao: %d\nArea: %.2f km2\nPIB: %.2f milhoes\n",
            c.codigo, c.nome, c.populacao, c.area, c.pib);
}

// Função de comparação
int compararCartas(Carta a, Carta b, int pesos[3]) {
    int pontosA = 0, pontosB = 0;

    if (a.populacao > b.populacao) pontosA += pesos[0];
    else if (b.populacao > a.populacao) pontosB += pesos[0];

    if (a.area > b.area) pontosA += pesos[1];
    else if (b.area > a.area) pontosB += pesos[1];

    if (a.pib > b.pib) pontosA += pesos[2];
    else if (b.pib > a.pib) pontosB += pesos[2];

    if (pontosA > pontosB) return 1;
    else if (pontosB > pontosA) return -1;
    return 0;
}

// Função de sorteio
int sortearIndice(int max) {
    return rand() % max;
}

void batalha(Carta *player, Carta *cpu, int pesos[3]) {
    printf("\nSua carta:");
    exibirCarta(*player);

    printf("\nCarta do computador:");
    exibirCarta(*cpu);

    int resultado = compararCartas(*player, *cpu, pesos);
    if (resultado == 1) printf("\nVoce venceu essa rodada!\n");
    else if (resultado == -1) printf("\nVoce perdeu essa rodada!\n");
    else printf("\nDeu Empate!\n");
}

void modoMataMata(Carta cartas[], int total, int pesos[3]) {
    while (total > 1) {
        printf("\nRodada com %d cartas:\n", total);

        int novaQtd = 0;
        for (int i = 0; i < total; i += 2) {
            if (i + 1 >= total) {
                cartas[novaQtd++] = cartas[i];
                continue;
            }

            printf("\nCombate entre %s e %s\n", cartas[i].nome, cartas[i + 1].nome);
            int resultado = compararCartas(cartas[i], cartas[i + 1], pesos);

            if (resultado == 1) cartas[novaQtd++] = cartas[i];
            else if (resultado == -1) cartas[novaQtd++] = cartas[i + 1];
            else {
                printf("Empate. Escolhendo aleatoriamente o vencedor...\n");
                cartas[novaQtd++] = (rand() % 2 == 0) ? cartas[i] : cartas[i + 1];
            }
        }

        total = novaQtd;
    }

    printf("\nGanhou: %s\n", cartas[0].nome);
}

int main() {
    srand(time(NULL));

    Carta cartas[MAX_CARTAS];
    int totalCartas = carregarCartas(cartas, "cartas.txt");

    if (totalCartas < 2) {
        printf("Cartas insuficientes para jogar.\n");
        return 1;
    }

    int pesos[3];
    printf("\nDefina os pesos para cada atributo:\n");
    printf("Peso Populacao: "); scanf("%d", &pesos[0]);
    printf("Peso Area: "); scanf("%d", &pesos[1]);
    printf("Peso PIB: "); scanf("%d", &pesos[2]);

    int opcao;
    do {
        printf("\n========= SUPER TRUNFO =========\n");
        printf("1. Modo Usuario vs CPU\n");
        printf("2. Modo Torneio Mata-Mata\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int idxPlayer = sortearIndice(totalCartas);
                int idxCPU = sortearIndice(totalCartas);
                while (idxCPU == idxPlayer)
                    idxCPU = sortearIndice(totalCartas);

                batalha(&cartas[idxPlayer], &cartas[idxCPU], pesos);
                break;
            }
            case 2:
                modoMataMata(cartas, totalCartas, pesos);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}
