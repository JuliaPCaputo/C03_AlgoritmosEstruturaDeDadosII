//A remoção de elementos de uma tabela hash cria problemas na busca, pois posições que foram removidas interrompem a sequência de sondagem.
//Uma forma de evitar é este problema é criar um sinalizador de status de cada posição. Assim, a tabela hash irá armazenar em cada posição, não só a
//chave, mas também o seu status. Para implementar esta ideia, podemos usar a struct abaixo:
//struct dado
//{<br>    int k;<br>    int status; // 0-vazio, 1-ocupado, 2-removido<br>};
//Para remover um elemento da tabela, basta fazer a busca e, se este for encontrado, basta alterar o status dele para 2, como mostrado no pseudocódigo
//A função de remoção deve ter o seguinte cabeçalho: int hash_remove(dado t[], int m, int k). Sua tarefa é então implementar a função hash_remove(). 
//Faça então um programa que leia o tamanho da tabela e insira várias chaves nela. Depois, o programa deve ler a chave que deve ser removida, e
//mostrar a tabela depois da remoção.

#include <iostream>
using namespace std;

struct dado
{
	int status; // 0: vazio; -1: ocupado; 2: removido
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
		if(t[j].status == 0 && t[j].k == k)
			return j;
		i++;
	}while(t[j].status != 0 && i < m);
	
	return -1; // se não encontrar na tabela
}

int hash_remove(dado t[], int m, int k)
{
	int j;
	
    j = hash_search(t, m, k);
    if(j != -1)
	{
       t[j].status = 2;
       t[j].k = -1;
       return 0; // consegui remover		
	}
    else
       return -1; // k nao esta na tabela
}

int main()
{
	int m; // tamanho da tabela
	int k; // chaves
	int i; // contador
	dado t[100]; // vetor de 100 posições do tipo dado
	int apagar; // chave que quer remover
	
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
	
	cin >> apagar;
	
	hash_remove(t, m, apagar);
	
	for(i = 0; i < m; i++)
	{
		cout << t[i].k << " ";
	}
	
	return 0;
}