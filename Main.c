#include <stdio.h>
#include "calculadora.h"

int main(){

    int escolha = menu();
    
    if (escolha == 1){
        int grau;
        int resultado;
        double x;
        
        printf("Digite o grau do polinômio (expoente de maior valor): ");
        scanf("%d", &grau);
        int polinomio[grau + 1];

        lePolinomio(polinomio, grau);
        imprimePolinomio(polinomio, grau);

        printf("Digite o valor de x para P(x): ");
        scanf("%lf", &x);

        resultado = calculaPolinomio(polinomio, grau, x);
        printf("RESULTADO: %d", resultado); 
    }

    else if(escolha == 2){
        
    }


}