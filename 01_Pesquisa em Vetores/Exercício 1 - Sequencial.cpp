//Faça um programa que leia vários valores inteiros e os armazene em um vetor. Depois, o programa deve ler um inteiro X e fazer uso da pesquisa
//sequencial para verificar se X está ou não no vetor. Se X for encontrado no vetor, o programa deve indicar a posição onde o mesmo foi encontrado.

#include <iostream>
using namespace std;

// Função de busca sequencial
int sequencial(int vetor[],int tamanho, int x)
{
	bool achou = false; // var aux p/ busca
	int i=0; // contador
	
	while (achou==false && i<tamanho)
		achou = vetor[i++]==x;
	
	if (achou)
		return (i-1);
	else
		return -1;
}

int main()
{
	int vetor[100]; // vetor de até 100 posições
	int tamanho = 0; // tamanho do vetor
	int x; // número a ser procurado
	int valor; // para chamar a função
	int i; // contador
	
	for (i = 0; i < 100; i++)
	{
		cin >> vetor[i];
		if (vetor[i] == -1)
			break;
		else
			tamanho++;
	}

	cin >> x;
	
	valor = sequencial(vetor, tamanho, x);
	
	if (valor == -1)
		cout << x << " nao encontrado" << endl;
	else
		cout << x << " encontrado na posicao " << valor << endl;
		
	return 0;
}