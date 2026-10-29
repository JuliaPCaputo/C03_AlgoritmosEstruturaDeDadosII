//Faça uma função que implemente este algoritmo. Esta função deve retornar a posição onde a chave foi inserida na tabela hash, ou -1 se não for
//possível inseri-la (tabela cheia). Use a sondagem linear para escolher a posição de inserção da chave. Sua função deve ter o seguinte cabeçalho:
//int hash_insert(dado t[], int m, int k). Faça então um programa que leia o tamanho desejado m para a tabela hash e as chaves a serem inseridas.
//Depois, o programa deve criar uma tabela de tamanho m inicialmente vazia (todas as posições preenchidas com -1), e ir inserindo as chaves digitadas.
//Ao final, seu programa deve mostrar a tabela depois das inserções. 

#include <iostream>
#include <cmath>
using namespace std;

struct dado
{
	int status;
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

int main()
{
	int k, m, i = 0; // chaves, tamanho do vetor e contador
	dado t[100];
	
	do{
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
	
	for(i = 0; i < m; i++)
	{
		cout << t[i].k << " ";
	}
	
	return 0;
}