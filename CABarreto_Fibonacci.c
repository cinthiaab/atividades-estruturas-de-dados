/*
  Arquivo: CABarreto_Fibonacci.c
  Autor: Cinthia Alves Barreto
  Date: 04/04/2023 20:50
  Descri��o: Este programa calcula a quantidade de numeros de Fibonacci que pertencem ao intervalo [a, b].
*/

#include <stdlib.h>
#include <stdio.h>

// interface
int fibonacci(int, int);
int contarNumerosFibonacciEntreIntervalo(int, int);

int main()
{
    FILE *entrada;
    int a, b;
    int qtdeFibonacci;

    entrada = fopen("Textos-para-teste/Lista_Inteiros.txt", "r");

    if (entrada == NULL)
    {
        printf("\nArquivo nao encontrado \n");
    }
    else
    {
        printf("Arquivo encontrado");
        fscanf(entrada, "%d %d", &a, &b);
        do
        {
            qtdeFibonacci = contarNumerosFibonacciEntreIntervalo(a, b);
            printf("Quantidade de numeros que pertencem ao intervalo [%d, %d] = %d\n", a, b, qtdeFibonacci);
            fscanf(entrada, "%d %d", &a, &b);
        } while (a != 0 && b != 0);
    }
    fclose(entrada);

    return 0;
}
int fibonacci(int x, int y)
{
    return x + y;
}
int contarNumerosFibonacciEntreIntervalo(int a, int b)
{
    int cont = 0;     // contador de numeros Fibonacci dentro deste intervalo
    int x = 1, y = 1; // F(1)=1=x e F(2)=1=y
    int aux;
    while (x <= b)
    {
        if (x >= a && x <= b)
            cont++;
        aux = y;
        y = fibonacci(x, y);
        x = aux;
    }
    return cont;
}
