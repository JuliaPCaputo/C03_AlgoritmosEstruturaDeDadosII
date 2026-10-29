//Faça uma função que implemente o double hashing, dado por: h(k,i,m)=(h1(k,m)+ih2(k,m))modm onde h1(k,m)=kmodm h2(k,m)=1+(kmod(m-1)) são funções
//hash auxiliares. As funções devem ter os seguintes cabeçalhos: int h1(int k, int m), int h2(int k, int m), int dhash(int k, int m, int i)
//onde k é a chave a ser inserida, m é o tamanho da tabela hash, e i é o número da tentativa. Depois faça um programa que leia os valores de k e m e
//faça uso desta função para retornar as posições de sondagem para o double hashing.

#include <iostream>
using namespace std;

int h1(int k, int m)
{
	int h;
	
	h = k % m;
	if(h < 0)
		h += m;
	
	return h;
}

int h2(int k, int m)
{
 	 return 1 + (k % (m - 1));
}

int dhash(int k, int m, int i) // função de double hashing
{
	int h;
	
	h = (h1(k, m) + i * h2(k, m)) % m;
	if(h < 0)
		h += m;
	return h;
}

int main()
{
	int k; // chave a ser inserida
	int m; // tamanho da tabela hash
	int i; // número da tentativa.
	
	cin >> k;
	
	do
	{
		cin >> m;
	}while(m <= 1); // se m == 1, ocorre divisão por 0 em h2
	
	for (i = 0; i < m; i++)
	{
    	cout << dhash(k, m, i);
    	if (i < m - 1) // para não dar espaço depois do último número
        	cout << " ";
	}
	
	return 0;
}