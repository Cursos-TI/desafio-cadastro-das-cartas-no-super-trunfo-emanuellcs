#include <stdio.h>

typedef struct {
    char codigo[4];             // Ex.: A01, B02 (3 chars + '\0')
    unsigned long int pop;      // População
    float area;                 // Área em km²
    float pib;                  // PIB em bilhões de reais
    int pontos;                 // Nº de pontos turísticos

    // Atributos calculados
    float dens;                 // Densidade Populacional (hab/km²)
    float pibpc;                // PIB per Capita em reais
    float invdens;              // Inverso da densidade populacional
    float superp;               // Super Poder (soma ponderada)
} Carta;

void calcular_atributos(Carta *c) {
    // Densidade Populacional
    if (c->area > 0.0f) {
        c->dens = (float)c->pop / c->area;
    } else {
        c->dens = 0.0f;
    }

    // Inverso da densidade
    if (c->dens > 0.0f) {
        c->invdens = 1.0f / c->dens;
    } else {
        c->invdens = 0.0f;
    }

    // PIB per Capita (em reais)
    if (c->pop > 0UL) {
        c->pibpc = (c->pib * 1000000000.0f) / (float)c->pop;
    } else {
        c->pibpc = 0.0f;
    }

    // Super Poder (soma de atributos relevantes)
    c->superp = (float)c->pop
              + c->area
              + c->pib
              + (float)c->pontos
              + c->invdens
              + c->pibpc;
}

int main(void) {
    Carta c1, c2;

    // Entrada da Carta 1
    printf("Cadastro da Carta 1\n");
    printf("Codigo (ex.: A01): ");
    scanf(" %3s", c1.codigo);
    printf("Populacao (unsigned long int): ");
    scanf(" %lu", &c1.pop);
    printf("Area (km²): ");
    scanf(" %f", &c1.area);
    printf("PIB (em bilhões de R$): ");
    scanf(" %f", &c1.pib);
    printf("Numero de pontos turisticos: ");
    scanf(" %d", &c1.pontos);

    // Entrada da Carta 2
    printf("\nCadastro da Carta 2\n");
    printf("Codigo (ex.: B02): ");
    scanf(" %3s", c2.codigo);
    printf("Populacao (unsigned long int): ");
    scanf(" %lu", &c2.pop);
    printf("Area (km²): ");
    scanf(" %f", &c2.area);
    printf("PIB (em bilhões de R$): ");
    scanf(" %f", &c2.pib);
    printf("Numero de pontos turisticos: ");
    scanf(" %d", &c2.pontos);

    // Calcular atributos
    calcular_atributos(&c1);
    calcular_atributos(&c2);

    // Exibir Carta 1
    printf("\n--- CARTA 1 (%s) ---\n", c1.codigo);
    printf("Populacao: %lu\n", c1.pop);
    printf("Area: %.2f km²\n", c1.area);
    printf("PIB: %.2f bilhões de R$\n", c1.pib);
    printf("Pontos Turisticos: %d\n", c1.pontos);
    printf("Densidade Populacional: %.6f hab/km²\n", c1.dens);
    printf("PIB per Capita: %.2f R$\n", c1.pibpc);
    printf("1/Densidade: %.6f km²/hab\n", c1.invdens);
    printf("Super Poder: %.6f\n", c1.superp);

    // Exibir Carta 2
    printf("\n--- CARTA 2 (%s) ---\n", c2.codigo);
    printf("Populacao: %lu\n", c2.pop);
    printf("Area: %.2f km²\n", c2.area);
    printf("PIB: %.2f bilhões de R$\n", c2.pib);
    printf("Pontos Turisticos: %d\n", c2.pontos);
    printf("Densidade Populacional: %.6f hab/km²\n", c2.dens);
    printf("PIB per Capita: %.2f R$\n", c2.pibpc);
    printf("1/Densidade: %.6f km²/hab\n", c2.invdens);
    printf("Super Poder: %.6f\n", c2.superp);

    // Comparações
    int vence_pop     = (c1.pop   > c2.pop)   ? 1 : 0;
    int vence_area    = (c1.area  > c2.area)  ? 1 : 0;
    int vence_pib     = (c1.pib   > c2.pib)   ? 1 : 0;
    int vence_pontos  = (c1.pontos> c2.pontos)? 1 : 0;
    int vence_dens    = (c1.dens  < c2.dens)  ? 1 : 0; // menor vence
    int vence_pibpc   = (c1.pibpc > c2.pibpc) ? 1 : 0;
    int vence_super   = (c1.superp> c2.superp)? 1 : 0;

    printf("\n--- COMPARACAO (1 = Carta 1 vence, 0 = Carta 2 vence) ---\n");
    printf("Populacao: %d\n", vence_pop);
    printf("Area: %d\n", vence_area);
    printf("PIB: %d\n", vence_pib);
    printf("Pontos Turisticos: %d\n", vence_pontos);
    printf("Densidade Populacional (menor vence): %d\n", vence_dens);
    printf("PIB per Capita: %d\n", vence_pibpc);
    printf("Super Poder: %d\n", vence_super);

    return 0;
}
