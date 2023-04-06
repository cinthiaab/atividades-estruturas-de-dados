/*
  Arquivo: CABarreto_Fibonacci.c
  Autor: Cinthia Alves Barreto
  Date: 04/04/2023 20:50
  Descri��o: Este programa calcula a quantidade de numeros de Fibonacci que são primos e menores que 100.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// interface
int proximoPrimo(int);
bool ePrimo(int);
int fibonacci(int, int);
int contarNumerosFibonacciEntreIntervalo(int, int);

int main()
{
    int cont = contarNumerosFibonacciEntreIntervalo(0, 100);

    printf("%d numeros de Fibonacci sao primos e menores que 100.\n", cont);
    return 0;
}
int proximoPrimo(int num)
{
    bool primo = false;
    int divisores, x, xLimite;

    while (primo == false)
    {
        if (num == 2)
            num = 3;
        else
            num = num + 2;
        divisores = 0;
        x = 1;
        xLimite = sqrt(num);
        while (x <= xLimite && divisores <= 1)
        {
            if (num % x == 0)
                divisores = divisores + 1;
            x = x + 1;
        }
        if (divisores == 1)
            primo = true;
        else
            primo = false;
    }

    return num;
}
bool ePrimo(int num)
{
    bool primo = true;
    int i = 2;
    int cont = 0;
    int x = sqrt(num);

    while (num % i != 0 && cont <= x)
    {
        i = proximoPrimo(i);
        cont++;
    }
    if (num % i == 0)
        primo = false;

    return primo;
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
        if (x >= a && x <= b && ePrimo(x) == true)
            cont++;
        aux = y;
        y = fibonacci(x, y);
        x = aux;
    }
    if (ePrimo(y) == true)
        cont++;

    return cont;
}
