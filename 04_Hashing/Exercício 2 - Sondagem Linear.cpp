//Usando a função hash_aux(), faça uma função que implemente a sondagem linear, dada por: h(k,i,m)=(h'(k,m)+i) mod m
//Esta função deve ter o seguinte cabeçalho: int hash1(int k, int i, int m) onde k é a chave a ser inserida, m é o tamanho da tabela hash e i é o
//número da tentativa. Depois faça um programa que leia os valores de k e m e faça uso desta função para retornar as posições da sondagem linear.

#include <iostream>
#include <cmath>
using namespace std;

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

int main()
{
	int k, m, i; // parâmetros da função
	
	cin >> k >> m;
	for(i = 0; i < m; i++)
	{
		cout << hash1(k, i, m) << " ";
	}

	return 0;
}