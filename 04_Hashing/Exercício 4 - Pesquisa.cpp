//O algoritmo de pesquisa em uma tabela hash é mostrado abaixo:
//Faça uma função que implemente este algoritmo. Esta função deve retornar a posição onde a chave foi encontrada na tabela hash, ou -1 se a chave
//não estiver na tabela. Use a sondagem linear para fazer a sondagem na tabela. Sua função deve ter o seguinte cabeçalho:
//int hash_search(dado t[], int m, int k). Faça então um programa que leia o tamanho desejado m para a tabela hash e insira várias chaves nesta.
//Depois, o programa deve ler o elemento a ser procurado e retornar a posição em que este se encontra. Se o elemento não estiver na tabela, uma
//mensagem deve ser mostrada. 

#include <iostream>
using namespace std;

struct dado
{
	int status; // 0: vazio; -1: ocupado
	int k;
};

int hash_aux(int k, int m)
{
	int h;
	
	h = k % m;
	if(h < 0)
		h += m;
	
	return h;
}

int hash1(int k, int i, int m)
{
	int ha;
	
	ha = (hash_aux(k, m) + i) % m;
	
	return ha;
}

int hash_insert(dado t[], int m, int k)
{
	int i = 0, j;
	
	do{
		j = hash1(k, i, m);
		if(t[j].status != 1)
		{
			t[j].k = k;
			t[j].status = 1;
			return j;
		}
		else
		{
			i++;
		}
	}while(i != m);

	return -1; // tabela cheia
}

int hash_search(dado t[], int m, int k) // função de pesquisa em uma tabela hash
{
	int i = 0; // contador
	int j; // contador
	
	do
	{
		j = hash1(k, i, m);
		if(t[j].k == k)
			return j;
		i++;
	}while(t[j].status != 0 and i < m);
	
	return -1; // se não encontrar na tabela
}

int main()
{
	int m; // tamanho da tabela
	int k; // chaves
	int i; // contador
	dado t[100]; // vetor de 100 posições do tipo dado
	int procurar; // chave que quer encontrar
	int resultado; // posição da chave procurada
	
	do
	{
		cin >> m;
	}while(m < 0 || m > 100);

	for(i = 0; i < m; i++) // para garantir que o vetor está vazio
	{
		t[i].status = 0;
		t[i].k = -1;
	}
	
	cin >> k;
	
	while(k != 0)
	{
		hash_insert(t, m, k);
		cin >> k;
	}
	
	cin >> procurar;
	
	resultado = hash_search(t, m, procurar);
	
	if(resultado == -1)
		cout << "Chave " << procurar << " nao encontrada" << endl;
	else
	{
		cout << "Chave " << procurar << " encontrada na posicao " << resultado << endl;
	}
	
	return 0;
}