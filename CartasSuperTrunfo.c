#include <stdio.h>

/*  
    Desafio Super Trunfo - Países
    Faremos o cadastro de Duas cidades para simplicificar o código e comparação entre elas.
    20250109-Versão com somente os cadastros.
*/


int main() {
    //Declaracao de variaveis
    
    //Variaveis primeira cidade
    char codigo1[4];
    int populacao1;
    float area1;
    float pib1;
    int pontos_turisticos1;
    float densidade1; // Densidade populacional
    float pib_per_capita1; // PIB per capita
    float poder1; //Poder da cidade

    // Variáveis para a segunda cidade
    char codigo2[4];
    int populacao2;
    float area2;
    float pib2;
    int pontos_turisticos2;
    float densidade2; // Densidade populacional
    float pib_per_capita2; // PIB per capita
    float poder2; //Poder da cidade

    //Entrada de dados

    printf("*** Bem-Vindo ao jogo Trunfo! ***\n");

    // Cadastro da primeira cidade
    printf("Cadastrando a primeira cidade:\n");
    printf("Digite o código da cidade (ex: A01): ");
    scanf("%s", codigo1);

    printf("Digite a população: ");
    scanf("%d", &populacao1);

    printf("Digite a área (em km²): ");
    scanf("%f", &area1);

    printf("Digite o PIB (em milhões): ");
    scanf("%f", &pib1);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontos_turisticos1);

    // Cadastro da segunda cidade
    printf("\nCadastrando a segunda cidade:\n");
    printf("Digite o código da cidade (ex: A02): ");
    scanf("%s", codigo2);

    printf("Digite a população: ");
    scanf("%d", &populacao2);

    printf("Digite a área (em km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB (em milhões): ");
    scanf("%f", &pib2);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontos_turisticos2);

    //Saida de dados

    // Exibindo os dados da primeira cidade
    printf("\nDados da primeira cidade %s:\n", codigo1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f milhões\n", pib1);
    printf("Pontos Turísticos: %d\n", pontos_turisticos1);

    // Exibindo os dados da segunda cidade
    printf("\nDados da segunda cidade %s:\n", codigo2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f milhões\n", pib2);
    printf("Pontos Turísticos: %d\n", pontos_turisticos2);

    return 0;
    
}
