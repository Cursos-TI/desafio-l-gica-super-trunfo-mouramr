#include <stdio.h>
#include <string.h>

#define NUM_ESTADOS 8
#define NUM_CIDADES_POR_ESTADO 4

// Estrutura para representar uma cidade
typedef struct {
    char codigo[4]; // Código da carta (ex: "A01")
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional; // Nova propriedade calculada
    float pib_per_capita;         // Nova propriedade calculada
    float super_poder;            // Soma de todas as propriedades
} Cidade;

// Função para calcular a densidade populacional
float calcularDensidadePopulacional(int populacao, float area) {
    if (area == 0) return 0; // Evitar divisão por zero
    return populacao / area;
}

// Função para calcular o PIB per capita
float calcularPibPerCapita(float pib, int populacao) {
    if (populacao == 0) return 0; // Evitar divisão por zero
    return (pib * 1e6) / populacao; // PIB em milhões, convertido para unidade
}

// Função para calcular o "Super Poder"
float calcularSuperPoder(Cidade cidade) {
    return cidade.populacao + cidade.area + cidade.pib + cidade.pontos_turisticos +
            cidade.densidade_populacional + cidade.pib_per_capita;
}

// Função para cadastrar uma cidade
void cadastrarCidade(Cidade *cidade) {
    printf("Digite o código da cidade (ex: A01): ");
    scanf("%s", cidade->codigo);
    printf("Digite a população: ");
    scanf("%d", &cidade->populacao);
    printf("Digite a área (em km²): ");
    scanf("%f", &cidade->area);
    printf("Digite o PIB (em milhões): ");
    scanf("%f", &cidade->pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &cidade->pontos_turisticos);

    // Calcular novas propriedades
    cidade->densidade_populacional = calcularDensidadePopulacional(cidade->populacao, cidade->area);
    cidade->pib_per_capita = calcularPibPerCapita(cidade->pib, cidade->populacao);
    cidade->super_poder = calcularSuperPoder(*cidade);
}

// Função para exibir os dados de uma cidade
void exibirCidade(Cidade cidade) {
    printf("Código: %s\n", cidade.codigo);
    printf("População: %d\n", cidade.populacao);
    printf("Área: %.2f km²\n", cidade.area);
    printf("PIB: %.2f milhões\n", cidade.pib);
    printf("Pontos Turísticos: %d\n", cidade.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", cidade.densidade_populacional);
    printf("PIB per Capita: %.2f\n", cidade.pib_per_capita);
    printf("Super Poder: %.2f\n", cidade.super_poder);
    printf("\n");
}

// Função para comparar duas cidades
void compararCidades(Cidade cidade1, Cidade cidade2) {
    printf("\nComparando %s e %s:\n", cidade1.codigo, cidade2.codigo);

    // Comparar densidade populacional (menor valor vence)
    if (cidade1.densidade_populacional < cidade2.densidade_populacional) {
        printf("%s vence em Densidade Populacional (menor valor)\n", cidade1.codigo);
    } else {
        printf("%s vence em Densidade Populacional (menor valor)\n", cidade2.codigo);
    }

    // Comparar outras propriedades (maior valor vence)
    if (cidade1.populacao > cidade2.populacao) {
        printf("%s vence em População\n", cidade1.codigo);
    } else {
        printf("%s vence em População\n", cidade2.codigo);
    }

    if (cidade1.area > cidade2.area) {
        printf("%s vence em Área\n", cidade1.codigo);
    } else {
        printf("%s vence em Área\n", cidade2.codigo);
    }

    if (cidade1.pib > cidade2.pib) {
        printf("%s vence em PIB\n", cidade1.codigo);
    } else {
        printf("%s vence em PIB\n", cidade2.codigo);
    }

    if (cidade1.pontos_turisticos > cidade2.pontos_turisticos) {
        printf("%s vence em Pontos Turísticos\n", cidade1.codigo);
    } else {
        printf("%s vence em Pontos Turísticos\n", cidade2.codigo);
    }

    if (cidade1.pib_per_capita > cidade2.pib_per_capita) {
        printf("%s vence em PIB per Capita\n", cidade1.codigo);
    } else {
        printf("%s vence em PIB per Capita\n", cidade2.codigo);
    }

    if (cidade1.super_poder > cidade2.super_poder) {
        printf("%s vence em Super Poder\n", cidade1.codigo);
    } else {
        printf("%s vence em Super Poder\n", cidade2.codigo);
    }
}

// Função para comparar todas as cidades
void compararTodasCidades(Cidade cidades[NUM_ESTADOS][NUM_CIDADES_POR_ESTADO]) {
    for (int i = 0; i < NUM_ESTADOS; i++) {
        for (int j = 0; j < NUM_CIDADES_POR_ESTADO; j++) {
            for (int k = 0; k < NUM_ESTADOS; k++) {
                for (int l = 0; l < NUM_CIDADES_POR_ESTADO; l++) {
                    // Evitar comparar a cidade com ela mesma
                    if (i != k || j != l) {
                        compararCidades(cidades[i][j], cidades[k][l]);
                    }
                }
            }
        }
    }
}

int main() {
    Cidade cidades[NUM_ESTADOS][NUM_CIDADES_POR_ESTADO];

    // Cadastrar as cidades
    for (int i = 0; i < NUM_ESTADOS; i++) {
        for (int j = 0; j < NUM_CIDADES_POR_ESTADO; j++) {
            printf("Cadastrando cidade %c%02d:\n", 'A' + i, j + 1);
            cadastrarCidade(&cidades[i][j]);
        }
    }

    // Exibir as cidades cadastradas
    printf("\nCidades cadastradas:\n");
    for (int i = 0; i < NUM_ESTADOS; i++) {
        for (int j = 0; j < NUM_CIDADES_POR_ESTADO; j++) {
            exibirCidade(cidades[i][j]);
        }
    }

    // Comparar todas as cidades
    printf("\nComparando todas as cidades:\n");
    compararTodasCidades(cidades);

    return 0;
}