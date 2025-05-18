#include <stdio.h>

/*  
    Desafio Super Trunfo - Países
    Faremos o cadastro de Duas cidades para simplicificar o código e comparação entre elas.
    20250109-Alteracao para versao melhorada do código C que aprendi usando if/else como no PHP
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

    // Calcula as propriedades da primeira cidade
    densidade1 = populacao1 / area1; // Densidade populacional
    pib_per_capita1 = (pib1 * 1000000) / populacao1; // PIB per capita (em reais por habitante)
    poder1 = populacao1 + area1 + pib1 + pontos_turisticos1 + densidade1 + pib_per_capita1; // Poder

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

    // Calcula as propriedades da segunda cidade
    densidade2 = populacao2 / area2; // Densidade populacional
    pib_per_capita2 = (pib2 * 1000000) / populacao2; // PIB per capita (em reais por habitante)
    poder2 = populacao2 + area2 + pib2 + pontos_turisticos2 + densidade2 + pib_per_capita2; // Poder

    //Saida de dados

    // Exibindo os dados da primeira cidade
    printf("\nDados da primeira cidade %s:\n", codigo1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f milhões\n", pib1);
    printf("Pontos Turísticos: %d\n", pontos_turisticos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: R$ %.2f\n", pib_per_capita1);
    printf("Poder: %.2f\n", poder1);

    // Exibindo os dados da segunda cidade
    printf("\nDados da segunda cidade %s:\n", codigo2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f milhões\n", pib2);
    printf("Pontos Turísticos: %d\n", pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: R$ %.2f\n", pib_per_capita2);
    printf("Poder: %.2f\n", poder2);

    // Comparação das propriedades
    printf("\nComparando as cidades:\n");

    // População
    if (populacao1 > populacao2) {
        printf("População: %s vence com %d habitantes\n", codigo1, populacao1);
    } else if (populacao2 > populacao1) {
        printf("População: %s vence com %d habitantes\n", codigo2, populacao2);
    } else {
        printf("População: Empate com %d habitantes\n", populacao1);
    }

    // Área
    if (area1 > area2) {
        printf("Área: %s vence com %.2f km²\n", codigo1, area1);
    } else if (area2 > area1) {
        printf("Área: %s vence com %.2f km²\n", codigo2, area2);
    } else {
        printf("Área: Empate com %.2f km²\n", area1);
    }

    // PIB
    if (pib1 > pib2) {
        printf("PIB: %s vence com %.2f milhões\n", codigo1, pib1);
    } else if (pib2 > pib1) {
        printf("PIB: %s vence com %.2f milhões\n", codigo2, pib2);
    } else {
        printf("PIB: Empate com %.2f milhões\n", pib1);
    }

    // Pontos Turísticos
    if (pontos_turisticos1 > pontos_turisticos2) {
        printf("Pontos Turísticos: %s vence com %d pontos\n", codigo1, pontos_turisticos1);
    } else if (pontos_turisticos2 > pontos_turisticos1) {
        printf("Pontos Turísticos: %s vence com %d pontos\n", codigo2, pontos_turisticos2);
    } else {
        printf("Pontos Turísticos: Empate com %d pontos\n", pontos_turisticos1);
    }

    // Densidade Populacional (menor valor vence)
    if (densidade1 < densidade2) {
        printf("Densidade Populacional: %s vence com %.2f hab/km²\n", codigo1, densidade1);
    } else if (densidade2 < densidade1) {
        printf("Densidade Populacional: %s vence com %.2f hab/km²\n", codigo2, densidade2);
    } else {
        printf("Densidade Populacional: Empate com %.2f hab/km²\n", densidade1);
    }

    // PIB per Capita
    if (pib_per_capita1 > pib_per_capita2) {
        printf("PIB per Capita: %s vence com R$ %.2f\n", codigo1, pib_per_capita1);
    } else if (pib_per_capita2 > pib_per_capita1) {
        printf("PIB per Capita: %s vence com R$ %.2f\n", codigo2, pib_per_capita2);
    } else {
        printf("PIB per Capita: Empate com R$ %.2f\n", pib_per_capita1);
    }

    // Poder
    if (poder1 > poder2) {
        printf("Poder: %s vence com %.2f\n", codigo1, poder1);
    } else if (poder2 > poder1) {
        printf("Poder: %s vence com %.2f\n", codigo2, poder2);
    } else {
        printf("Poder: Empate com %.2f\n", poder1);
    }

    return 0;
}
