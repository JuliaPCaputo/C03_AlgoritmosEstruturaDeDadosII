//Usando a função hash_aux(), faça uma função que implemente a sondagem quadrática, dada por: h(k,i,m)=(h'(k,m)+c1i+c2i2)modm
//Esta função deve ter o seguinte cabeçalho: int hash2(int k, int i, int m, int c1, int c2) onde k é a chave a ser inserida, m é o tamanho da tabela
//hash, e i é o número da tentativa. Depois faça um programa que leia os valores de k, m, c1 e c2 e faça uso desta função para retornar as posições
//da sondagem quadrática.

#include <iostream>
using namespace std;

int hash_aux(int k, int m)
{
	int h;
	
	h = k % m;
	if(h < 0)
		h += m;
	
	return h;
}

int hash2(int k, int i, int m, int c1, int c2) // função de sondagem quadrática
{
	return (hash_aux(k, m) + (c1 * i) + (c2 * i * i)) % m;
}

int main()
{
	int k; // k a chave a ser inserida
	int m; // tamanho da tabela hash
	int i; // número da tentativa.
	int c1, c2; 
	
	cin >> k >> m >> c1 >> c2;
	
	for(i = 0; i < m; i++)
	{
		cout << hash2(k, i, m, c1, c2) << " ";
	}

	return 0;
}