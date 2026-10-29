//Faça uma função que ordene um vetor em ordem decrescente usando o algoritmo de ordenação Insertion Sort.

#include <iostream>
using namespace std;

void insercaoDireta(int vetor[], int tamanho)
{
	int i, j; // contadores
	int chave;

	for (j = 1; j < tamanho; j++)
	{
		chave = vetor[j];
		i = j - 1;
		while ((i >= 0) && (vetor[i] < chave))
		{
			vetor[i + 1] = vetor[i];
			i = i - 1;
		}
		vetor[i + 1] = chave;
	}
}

int main()
{
	int N[100]; // números a serem inseridos no vetor
	int i = 0; // contador
	int tamanho = 0; // tamanho do vetor
	int num;

	cin >> num;
	
	while(num != 0)
	{
		N[i] = num;
		i++;
		cin >> num;
	}
	
	tamanho = i;
	
	insercaoDireta(N,tamanho);
	
	for(i = 0; i < tamanho; i++)
	{
		cout << N[i] << " ";
	}

	return 0;
}