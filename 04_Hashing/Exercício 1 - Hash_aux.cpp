//Faça uma  função que implemente o método da divisão, dado por: h(k,m)=k mod m. Se o valor resultante for negativo, você deve somar m a ele.
//A sua função deve ter o seguinte cabeçalho: int hash_aux(int k, int m) onde k é a chave a ser inserida, e m é o tamanho da tabela hash.
//Depois faça um programa que leia vários valores de k e m e faça uso desta função para retornar o valor dela.

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

int main()
{
	int k, m; // parâmetros da função
	
	cin >> k >> m;
	
	while(k != 0 && m != 0)
	{
		cout << hash_aux(k, m) << endl;
		cin >> k >> m;
	}
	
	return 0;
}