//Faça um programa que use o algoritmos Quick Sort para ordenar um vetor em ordem crescente.

#include <iostream>
#include <cmath>
using namespace std;

void quickSort(int vetor[], int i, int j)
{
	int trab,esq,dir,pivo;
	esq = i;
	dir = j;
	pivo = vetor[(int)round((esq + dir)/2.0)];
	do
	{
		while (vetor[esq] < pivo)
			esq++;
		while (vetor[dir] > pivo)
			dir--;
		if (esq <= dir)
		{
			trab = vetor[esq];
			vetor[esq] = vetor[dir];
			vetor[dir] = trab;
			esq++;
			dir--;
		}
	} while (esq <= dir);
	
	if (dir-i >= 0)
		quickSort(vetor,i,dir);
	if (j-esq >= 0)
		quickSort(vetor,esq,j);
}

int main()
{
	int vetor[100]; // vetor de 100 posições
	int a = 0; // contador
	int num; // números fornecidos
	int i, j; // índices dos elementos final e inicial do vetor
	int tamanho; // tamanho do vetor
	
	cin >> num;
	
	while(num != -1 && a < 100)
	{
		vetor[a] = num;
		a++;
		cin >> num;
	}
	
	tamanho = a;
	i = 0;
	j = tamanho - 1;
	
	quickSort(vetor, i, j);
	
	for(a = 0; a < tamanho; a++)
	{
		cout << vetor[a] << " ";	
	}
	
	return 0;
}