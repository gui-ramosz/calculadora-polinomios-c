#include <stdio.h>
#include "calculadora.h"


int menu(){
    int escolha;
    printf("====Calculadora de Polinômios====\n");
    printf("(1) Calcular Polinômio \n(2) Somar Polinômios \n(3) Multiplicar Polinômios\n");
    printf("Escolha uma das opções: ");
    scanf("%d", &escolha);
    return escolha;
}

void lePolinomio(int polinomio[], int grau){

    printf("Digite os coeficientes: \n");

    for(int i = 0; i <= grau; i++){
        int expoente = grau - i;
        printf("Coeficiente de x^%d: ", expoente );
        scanf("%d", &polinomio[expoente]);  
    }
}


void imprimePolinomio(int polinomio[], int grau){

    printf("Polinômio: ");

    int primeiro = 1;  // Variável para evitar imprimir sinal no primeiro termo

    for (int i = grau; i >= 0; i--) {  // Percorre do maior para o menor grau
        int coef = polinomio[i];

        if (coef == 0) continue;  // Ignora coeficientes zero

        // Exibe sinal corretamente
        if (!primeiro) {
            printf(coef > 0 ? " + " : " - ");
        } else if (coef < 0) {
            printf("-");  // Se o primeiro termo for negativo, imprime o sinal
        }

        // Exibe coeficiente (omitindo 1 para expoentes maiores que 0)
        if (coef != 1 && coef != -1 || i == 0) {
            printf("%d", coef > 0 ? coef : -coef);
        }

        // Exibe o 'x' apenas se o expoente for maior que 0
        if (i > 0) printf("x");

        // Exibe o expoente (se for maior que 1)
        if (i > 1) printf("^%d", i);

        primeiro = 0;  // Marca que o primeiro termo já foi impresso
    }

    printf("\n");
}

double calculaPolinomio(int polinomio[], int grau, double x) { //Double pois o valor de x pode ser de ponto flutuante

    double resultado = polinomio[grau]; 

    for (int i = grau - 1; i >= 0; i--) {
        resultado = resultado * x + polinomio[i];  // Método de Horner
    }
    return resultado;
}

double somaPolinomio(int polinomio1[], int grau1, int polinomio2[], int grau2, int vres[]){
    int soma;
    for(int i = 0; i > grau1; i++){
        for(int j = 0; j > grau2; j++){
            soma = polinomio1[i] + polinomio2[j];
            vres[] = soma;
        }
    }
return vres;
}
