#include <stdio.h>
#include "calculadora.h" // Inclui o arquivo de cabeçalho para conectar as funções

// Implementação da função menu
int menu() {
    int escolha;
    printf("\n==== Calculadora de Polinomios ====\n");
    printf("(1) Calcular Polinomio P(x)\n");
    printf("(2) Somar Polinomios\n");
    printf("===================================\n");
    printf("Escolha uma das opcoes: ");
    scanf("%d", &escolha);
    return escolha;
}

// Implementação da função para ler um polinômio
void lePolinomio(int polinomio[], int grau) {
    printf("Digite os coeficientes do polinomio:\n");
    // O loop começa do grau mais alto para o mais baixo, facilitando a entrada do usuário
    for (int i = grau; i >= 0; i--) {
        printf("Coeficiente de x^%d: ", i);
        scanf("%d", &polinomio[i]); // Armazena o coeficiente no índice correspondente ao seu grau
    }
}

// Implementação da função para imprimir um polinômio de forma elegante
void imprimePolinomio(int polinomio[], int grau) {
    printf("P(x) = ");
    int primeiroTermo = 1; // Flag para controlar a impressão do sinal no primeiro termo

    for (int i = grau; i >= 0; i--) {
        int coef = polinomio[i];

        if (coef == 0) continue; // Pula termos com coeficiente zero

        // Lógica para imprimir o sinal (+ ou -) corretamente
        if (!primeiroTermo) {
            printf(coef > 0 ? " + " : " - ");
            coef = coef > 0 ? coef : -coef; // Pega o valor absoluto para impressão
        } else if (coef < 0) {
            printf("-");
            coef = -coef;
        }

        // Lógica para imprimir o coeficiente (ex: não imprime '1' em '1x^2')
        if (coef != 1 || i == 0) {
            printf("%d", coef);
        }

        // Lógica para imprimir a variável 'x' e seu expoente
        if (i > 0) {
            printf("x");
            if (i > 1) {
                printf("^%d", i);
            }
        }
        primeiroTermo = 0; // Atualiza a flag após o primeiro termo ser impresso
    }
     if (primeiroTermo) { // Caso especial: polinômio nulo
        printf("0");
    }
    printf("\n");
}

// Implementação da função que calcula P(x)
// Esta função utiliza o Método de Horner, que é uma forma eficiente de calcular polinômios.
double calculaPolinomio(int polinomio[], int grau, double x) {
    double resultado = 0.0;
    // O loop começa do coeficiente de maior grau
    for (int i = grau; i >= 0; i--) {
        resultado = resultado * x + polinomio[i];
    }
    return resultado;
}

// Implementação da função de soma de polinômios (versão corrigida)
void somaPolinomio(int polinomio1[], int grau1, int polinomio2[], int grau2, int vres[]) {
    // Determina o maior grau para definir o tamanho do loop e do resultado
    int grauMaior = (grau1 > grau2) ? grau1 : grau2;

    // Inicializa o vetor de resultado com zeros para evitar lixo de memória
    for (int i = 0; i <= grauMaior; i++) {
        vres[i] = 0;
    }

    // Adiciona os coeficientes do primeiro polinômio ao vetor de resultado
    for (int i = 0; i <= grau1; i++) {
        vres[i] += polinomio1[i];
    }

    // Adiciona os coeficientes do segundo polinômio ao vetor de resultado
    for (int i = 0; i <= grau2; i++) {
        vres[i] += polinomio2[i];
    }
}
