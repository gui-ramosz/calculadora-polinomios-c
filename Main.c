#include <stdio.h>
#include "calculadora.h"

int main() {
    // A função menu é chamada para obter a escolha do usuário
    int escolha = menu();

    // ---- Opção 1: Calcular P(x) ----
    if (escolha == 1) {
        int grau;
        printf("\n--- Calcular Polinomio P(x) ---\n");
        printf("Digite o grau do polinomio: ");
        scanf("%d", &grau);

        int polinomio[grau + 1]; // Declara o vetor com o tamanho necessário

        lePolinomio(polinomio, grau);
        imprimePolinomio(polinomio, grau);

        double x;
        printf("\nDigite o valor de x para calcular P(x): ");
        scanf("%lf", &x);

        double resultado = calculaPolinomio(polinomio, grau, x);
        printf("\nO resultado de P(%.2f) e: %.2f\n", x, resultado);
    }
    // ---- Opção 2: Somar Polinômios ----
    else if (escolha == 2) {
        printf("\n--- Somar dois Polinomios ---\n");
        int grau1, grau2;

        // Leitura do primeiro polinômio
        printf("Digite o grau do PRIMEIRO polinomio: ");
        scanf("%d", &grau1);
        int polinomio1[grau1 + 1];
        lePolinomio(polinomio1, grau1);
        imprimePolinomio(polinomio1, grau1);

        // Leitura do segundo polinômio
        printf("\nDigite o grau do SEGUNDO polinomio: ");
        scanf("%d", &grau2);
        int polinomio2[grau2 + 1];
        lePolinomio(polinomio2, grau2);
        imprimePolinomio(polinomio2, grau2);

        // Define o grau do polinômio resultante
        int grauMaior = (grau1 > grau2) ? grau1 : grau2;
        int vres[grauMaior + 1]; // Vetor para armazenar o resultado

        // Chama a função de soma
        somaPolinomio(polinomio1, grau1, polinomio2, grau2, vres);

        // Imprime o resultado
        printf("\n--- RESULTADO DA SOMA ---\n");
        imprimePolinomio(vres, grauMaior);
    }
    // ---- Opção Inválida ----
    else {
        printf("Opcao invalida!\n");
    }

    return 0; // Fim do programa
}
