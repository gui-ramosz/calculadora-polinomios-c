#ifndef CALCULADORA_H
#define CALCULADORA_H

// As linhas #ifndef, #define e #endif são "include guards".
// Elas garantem que o conteúdo deste arquivo seja incluído apenas uma vez
// durante a compilação, evitando erros.

#include <stdio.h> // Incluído para ter acesso a funções de I/O se necessário

// Protótipos das Funções (Assinaturas)

/**
 * @brief Exibe o menu principal e retorna a escolha do usuário.
 * @return Um inteiro representando a opção escolhida.
 */
int menu();

/**
 * @brief Lê os coeficientes de um polinômio a partir da entrada do usuário.
 * @param polinomio O vetor onde os coeficientes serão armazenados.
 * @param grau O grau do polinômio.
 */
void lePolinomio(int polinomio[], int grau);

/**
 * @brief Imprime um polinômio no terminal de forma legível (ex: 3x^2 + 2x - 5).
 * @param polinomio O vetor contendo os coeficientes.
 * @param grau O grau do polinômio.
 */
void imprimePolinomio(int polinomio[], int grau);

/**
 * @brief Calcula o valor de um polinômio P(x) para um dado valor de x.
 * @param polinomio O vetor de coeficientes.
 * @param grau O grau do polinômio.
 * @param x O valor de x para o qual P(x) será calculado.
 * @return O resultado de P(x) como um double.
 */
double calculaPolinomio(int polinomio[], int grau, double x);

/**
 * @brief Soma dois polinômios e armazena o resultado em um terceiro vetor.
 * @param polinomio1 O primeiro polinômio.
 * @param grau1 O grau do primeiro polinômio.
 * @param polinomio2 O segundo polinômio.
 * @param grau2 O grau do segundo polinômio.
 * @param vres O vetor onde o resultado da soma será armazenado.
 */
void somaPolinomio(int polinomio1[], int grau1, int polinomio2[], int grau2, int vres[]);


#endif // Fim do include guard
