#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CIDADES 32

typedef struct {
    char estado;
    char codigo[4];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} CartaCidade;

void exibir_dados(CartaCidade carta) {
    printf("\nCarta cadastrada com sucesso:\n");
    printf("Estado: %c\n", carta.estado);
    printf("Código da Carta: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nome);
    printf("População: %d\n", carta.populacao);
    printf("Área (km²): %.2f\n", carta.area);
    printf("PIB: %.2f\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontos_turisticos);
}

void cadastrar_cartas() {
    printf("Bem-vindo ao sistema de cadastro de cartas do Super Trunfo!\n");
    CartaCidade cartas[MAX_CIDADES];
    int count = 0;

    while (1) {
        if (count >= MAX_CIDADES) {
            printf("Limite de cartas atingido!\n");
            break;
        }

        CartaCidade carta;

        printf("Digite o estado (A-H): ");
        scanf(" %c", &carta.estado);
        if (carta.estado < 'A' || carta.estado > 'H') {
            printf("Estado inválido. Tente novamente.\n");
            continue;
        }

        printf("Digite o código da carta (ex: A01): ");
        scanf(" %3s", carta.codigo);
        if (carta.codigo[0] != carta.estado || strlen(carta.codigo) != 3 || !isdigit(carta.codigo[1]) || !isdigit(carta.codigo[2])) {
            printf("Código inválido. Deve estar no formato <Estado><01-04>. Tente novamente.\n");
            continue;
        }

        printf("Digite o nome da cidade: ");
        scanf(" %s", carta.nome);

        printf("Digite a população: ");
        scanf(" %d", &carta.populacao);
        
        if (carta.populacao != 1) {
            printf("Erro: Por favor, insira um valor numérico válido.\n");
            continue;
        }

        printf("Digite a área em km²: ");
        if (scanf(" %f", &carta.area) != 1) {
            printf("Erro: Por favor, insira um valor numérico válido.\n");
            continue;
        }

        printf("Digite o PIB: ");
        if (scanf(" %f", &carta.pib) != 1) {
            printf("Erro: Por favor, insira um valor numérico válido.\n");
            continue;
        }

        printf("Digite o número de pontos turísticos: ");
        if (scanf(" %d", &carta.pontos_turisticos) != 1) {
            printf("Erro: Por favor, insira um valor numérico válido.\n");
            continue;
        }

        cartas[count++] = carta;
        exibir_dados(carta);

        char continuar;
        printf("Deseja cadastrar outra carta? (S/N): ");
        scanf(" %c", &continuar);
        if (continuar != 'S' && continuar != 's') {
            break;
        }
    }

    printf("\nResumo do cadastro:\n");
    for (int i = 0; i < count; i++) {
        exibir_dados(cartas[i]);
    }

    printf("\nCadastro finalizado. Obrigado por utilizar o sistema!\n");
}

int main() {
    cadastrar_cartas();
    return 0;
}
