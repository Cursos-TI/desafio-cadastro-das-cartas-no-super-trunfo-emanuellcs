#include <stdio.h>

typedef struct {
    char codigo[4];             // Ex.: A01, B02 (3 chars + '\0')
    unsigned long int pop;      // População
    float area;                 // Área
    float pib;                  // PIB
    int pontos;                 // Nº de pontos turísticos

    // Atributos calculados
    float dens;                 // Densidade Populacional
    float pibpc;                // PIB per Capita
    float invdens;              // 1 / densidade
    float superp;               // Super Poder
} Carta;

void calcular_atributos(Carta *c) {
    // Densidade = pop / area (evitar divisão por zero)
    if (c->area > 0.0f) {
        c->dens = (float)c->pop / c->area;
    } else {
        c->dens = 0.0f;
    }

    // 1/densidade (evitar divisão por zero)
    if (c->dens > 0.0f) {
        c->invdens = 1.0f / c->dens;
    } else {
        c->invdens = 0.0f;
    }

    // PIB per Capita = pib / pop (evitar divisão por zero)
    if (c->pop > 0UL) {
        c->pibpc = c->pib / (float)c->pop;
    } else {
        c->pibpc = 0.0f;
    }

    // Super Poder = soma de todos os atributos (com densidade invertida)
    // pop (UL) + area (f) + pib (f) + pontos (int) + invdens (f) + pibpc (f)
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
    printf("Area (float): ");
    scanf(" %f", &c1.area);
    printf("PIB (float): ");
    scanf(" %f", &c1.pib);
    printf("Numero de pontos turisticos (int): ");
    scanf(" %d", &c1.pontos);

    // Entrada da Carta 2
    printf("\nCadastro da Carta 2\n");
    printf("Codigo (ex.: B02): ");
    scanf(" %3s", c2.codigo);
    printf("Populacao (unsigned long int): ");
    scanf(" %lu", &c2.pop);
    printf("Area (float): ");
    scanf(" %f", &c2.area);
    printf("PIB (float): ");
    scanf(" %f", &c2.pib);
    printf("Numero de pontos turisticos (int): ");
    scanf(" %d", &c2.pontos);

    // Calcular atributos derivados
    calcular_atributos(&c1);
    calcular_atributos(&c2);

    // Exibir dados cadastrados e calculados
    printf("\n--- CARTA 1 (%s) ---\n", c1.codigo);
    printf("Populacao: %lu\n", c1.pop);
    printf("Area: %.2f\n", c1.area);
    printf("PIB: %.2f\n", c1.pib);
    printf("Pontos Turisticos: %d\n", c1.pontos);
    printf("Densidade Populacional: %.6f\n", c1.dens);
    printf("PIB per Capita: %.6f\n", c1.pibpc);
    printf("1/Densidade: %.6f\n", c1.invdens);
    printf("Super Poder: %.6f\n", c1.superp);

    printf("\n--- CARTA 2 (%s) ---\n", c2.codigo);
    printf("Populacao: %lu\n", c2.pop);
    printf("Area: %.2f\n", c2.area);
    printf("PIB: %.2f\n", c2.pib);
    printf("Pontos Turisticos: %d\n", c2.pontos);
    printf("Densidade Populacional: %.6f\n", c2.dens);
    printf("PIB per Capita: %.6f\n", c2.pibpc);
    printf("1/Densidade: %.6f\n", c2.invdens);
    printf("Super Poder: %.6f\n", c2.superp);

    // Comparacoes (1 se Carta 1 vence, 0 se Carta 2 vence)
    int vence_pop     = (c1.pop   > c2.pop)   ? 1 : 0; // maior vence
    int vence_area    = (c1.area  > c2.area)  ? 1 : 0; // maior vence
    int vence_pib     = (c1.pib   > c2.pib)   ? 1 : 0; // maior vence
    int vence_pontos  = (c1.pontos> c2.pontos)? 1 : 0; // maior vence
    int vence_dens    = (c1.dens  < c2.dens)  ? 1 : 0; // menor vence (regra especial)
    int vence_pibpc   = (c1.pibpc > c2.pibpc) ? 1 : 0; // maior vence
    int vence_super   = (c1.superp> c2.superp)? 1 : 0; // maior vence

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