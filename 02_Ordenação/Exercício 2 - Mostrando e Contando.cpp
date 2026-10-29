//Faça uma função usando o algoritmo Bubble Sort, que mostre toda vez que a variável trab receber um novo valor, o valor que ela recebeu.
//Por ultimo faça um contador, que conte quantas vezes a variável troca recebe o valor true.

#include <iostream>
using namespace std;

void bubbleSort(int vetor[], int tamanho)
{
	int i, j; // contadores
	int trab;
	bool troca;
	int limite;
	int contTrue = 0; // para contar quantas vezes troca recebe true
	
	troca = true;
	limite = tamanho - 1;
	
	while (troca)
	{
		troca = false;
		for (i = 0; i < limite; i++)
			if (vetor[i] > vetor[i + 1])
			{
				trab = vetor[i];
				cout << "New Trab:" << trab << endl;
				vetor[i] = vetor[i + 1];
				vetor[i + 1] = trab;
				j = i;
				troca = true;
				contTrue++;
			}
		
		limite = j;
	}
	cout << "Contador:" << contTrue << endl;
}

int main()
{
	int x; // quantos valores serão adicionados ao vetor
	int N[100]; // vetor de até 100 posições
	int i; // contador
	
	cin >> x;
	
	for(i = 0; i < x; i++)
	{
		cin >> N[i];
	}
	
	bubbleSort(N,x);
	
	return 0;
}