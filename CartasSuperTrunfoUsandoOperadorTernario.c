#include <stdio.h>

/*  
    Desafio Super Trunfo - Países
    Faremos o cadastro de Duas cidades para simplicificar o código e comparação entre elas.
    20250109-Alteracao para versao melhorada do código C que aprendi usando Operador Ternário
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
    int vencedor_populacao = (populacao1 > populacao2) * 1 + (populacao2 > populacao1) * 2;
    printf("População: %s vence com %d habitantes\n",
            (vencedor_populacao == 1) ? codigo1 : codigo2,
            (vencedor_populacao == 1) ? populacao1 : populacao2);

    // Área
    int vencedor_area = (area1 > area2) * 1 + (area2 > area1) * 2;
    printf("Área: %s vence com %.2f km²\n",
            (vencedor_area == 1) ? codigo1 : codigo2,
            (vencedor_area == 1) ? area1 : area2);

    // PIB
    int vencedor_pib = (pib1 > pib2) * 1 + (pib2 > pib1) * 2;
    printf("PIB: %s vence com %.2f milhões\n",
            (vencedor_pib == 1) ? codigo1 : codigo2,
            (vencedor_pib == 1) ? pib1 : pib2);

    // Pontos Turísticos
    int vencedor_pontos = (pontos_turisticos1 > pontos_turisticos2) * 1 + (pontos_turisticos2 > pontos_turisticos1) * 2;
    printf("Pontos Turísticos: %s vence com %d pontos\n",
            (vencedor_pontos == 1) ? codigo1 : codigo2,
            (vencedor_pontos == 1) ? pontos_turisticos1 : pontos_turisticos2);

    // Densidade Populacional (menor valor vence)
    int vencedor_densidade = (densidade1 < densidade2) * 1 + (densidade2 < densidade1) * 2;
    printf("Densidade Populacional: %s vence com %.2f hab/km²\n",
            (vencedor_densidade == 1) ? codigo1 : codigo2,
            (vencedor_densidade == 1) ? densidade1 : densidade2);

    // PIB per Capita
    int vencedor_pib_per_capita = (pib_per_capita1 > pib_per_capita2) * 1 + (pib_per_capita2 > pib_per_capita1) * 2;
    printf("PIB per Capita: %s vence com R$ %.2f\n",
            (vencedor_pib_per_capita == 1) ? codigo1 : codigo2,
            (vencedor_pib_per_capita == 1) ? pib_per_capita1 : pib_per_capita2);

    // Poder
    int vencedor_poder = (poder1 > poder2) * 1 + (poder2 > poder1) * 2;
    printf("Poder: %s vence com %.2f\n",
            (vencedor_poder == 1) ? codigo1 : codigo2,
            (vencedor_poder == 1) ? poder1 : poder2);

    return 0;
}
