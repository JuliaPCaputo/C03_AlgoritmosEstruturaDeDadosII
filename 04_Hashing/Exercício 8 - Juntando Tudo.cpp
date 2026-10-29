// Faça um programa que insira, remova, pesquise e liste os elementos de uma tabela, segundo o menu abaixo: 1: inserir, 2: pesquisar, 3: remover
// 4: listar, 5: sair do programa. USE O DOUBLE HASHING PARA ESTE PROBLEMA.

#include <iostream>
using namespace std;

struct dado
{
	int status; // 0: vazio; 1: ocupado; 2: removido
	int k;
};

int hash_aux(int k, int m) // função que calcula o índice inicial para a chave na tabela
{
	int h;
	
	h = k % m;
	if(h < 0)
		h += m;
	
	return h;
}

int h2(int k, int m) // função que calcula o incremento para a sondagem em caso de colisão
{
 	 return 1 + (k % (m - 1));
}

int dhash(int k, int m, int i) // função de double hashing
{
	int h;
	
	h = (hash_aux(k, m) + i * h2(k, m)) % m;
	if(h < 0)
		h += m;
	return h;
}

int hash_insert(dado t[], int m, int k) // função para inserção na tabela hash
{
	int i = 0, j;
	
	do{
		j = dhash(k, m, i);
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

int hash_search(dado t[], int m, int k) // função para pesquisa na tabela hash
{
	int i = 0; // contador
	int j; // contador
	
	do
	{
		j = dhash(k, m, i);
		if(t[j].k == k)
			return j;
		i++;
	}while(t[j].status != 0 && i < m);
	
	return -1; // se não encontrar na tabela
}

int hash_remove(dado t[], int m, int k) // função para remover da tabela hash
{
	int j;
	
    j = hash_search(t, m, k);
    if(j != -1) // quando j == -1, significa que a chave não foi encontrada na tabela pela função hash_search
	{
       t[j].status = 2;
       t[j].k = -1;
       return 0; // conseguiu remover		
	}
    else
       return -1; // k nao esta na tabela
}

void hash_list(dado t[], int m) // função para listar os itens da tabela hash
{
	for (int i = 0; i < m; ++i)
	{
            cout << t[i].k << " ";
	}
}

int main()
{
	int m; // tamanho da tabela hash
	int op; // opção de operação do usuário
	int k; // chave
	dado t[100]; // vetor de 100 posições do tipo dado
	int i = 0;
	int pesquisa; // variável que vai receber o valor de hash_search
	
	do
	{
		cin >> m;
	}while(m < 0 || m > 100);
	
	for(i = 0; i < m; i++) // para garantir que o vetor está vazio
	{
		t[i].status = 0;
		t[i].k = -1;
	}
	
	do{
		cin >> op;
	} while(op < 1 || op > 5);
	
	while(op != 5) // pois, quando op == 5, o usuário quer sair do programa
	{ 
		if(op == 1) // a opção escolhida é "inserir"
		{
			cin >> k;
			hash_insert(t, m, k);
		} 
		else if(op == 2) // a opção escolhida é "pesquisa"
		{
			cin >> k;
			pesquisa = hash_search(t, m, k);
			if(pesquisa == -1)
				cout << "-1" << endl;
			else
				cout << pesquisa << endl;
		}
		else if(op == 3) // a opção escolhida é "remover"
		{
			cin >> k;
			hash_remove(t, m, k);
		}
		else // quando op == 4, a opção escolhida é "listar"
		{
			hash_list(t, m);
			cout << endl;
		}
		do
		{
			cin >> op;
		} while(op < 1 || op > 5);
	}

	return 0;
}