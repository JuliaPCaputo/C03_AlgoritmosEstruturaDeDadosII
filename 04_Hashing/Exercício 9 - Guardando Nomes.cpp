//Repita o problema anterior para um esquema de hashing que gere a chave a partir da informação a ser armazenada. A informação vai ser uma string de
//até 50 caracteres, e a chave deve ser calculada como a soma dos valores ASCII de cada um de seus caracteres. Por exemplo, "Inatel" gera uma chave
//k = 605. A struct para armazenar os dados deve ser modificada para: struct dado {<br>    string info; // informacao<br>    int k; // chave<br>
//int status; // 0: vazio, 1:ocupado, 2:removido<br>}; USE O DOUBLE HASHING PARA ESTE PROBLEMA.

#include <iostream>
#include <cstring>
using namespace std;

struct dado
{
	string info; // informação
	int k; // chave
	int status; // 0: vazio, 1:ocupado, 2:removido
};

int calcular_chave(string s) // função para converter uma string para um número inteiro
{
	int soma = 0; // soma dos caracteres
	int i; // contador
	
	for(i = 0; i < s.size(); i++)
	{
    	soma += s[i]; // soma os valores da tabela ASCII de cada caracter da string
	}
	
	return soma;
}

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

int hash_insert(dado t[], int m, int k, string s) // função para inserção na tabela hash
{
	int i = 0, j;
	
	do{
		j = dhash(k, m, i);
		if(t[j].status != 1)
		{
			t[j].k = k;
			t[j].status = 1;
			t[j].info = s;
			return j;
		}
		else
		{
			i++;
		}
	}while(i != m);

	return -1; // tabela cheia
}

int hash_search(dado t[], int m, int k, string s) // função para pesquisa na tabela hash
{
	int i = 0; // contador
	int j; // contador
	
	do
	{
		j = dhash(k, m, i);
		if(t[j]. status == 1 && t[j].k == k && t[j].info == s) 
			return j;
		i++;
	}while(t[j].status != 0 && i < m);
	
	return -1; // se não encontrar na tabela
}

int hash_remove(dado t[], int m, int k, string s) // função para remover da tabela hash
{
	int j;
	
    j = hash_search(t, m, k, s);
    if(j != -1) // quando j == -1, significa que a chave não foi encontrada na tabela pela função hash_search
	{
       t[j].status = 2;
       t[j].k = -1;
       t[j].info = "";
       return 0; // conseguiu remover		
	}
    else
       return -1; // k nao esta na tabela
}

void hash_list(dado t[], int m) // função para listar os itens da tabela hash
{
	int i; // contador
	
	for(i = 0; i < m; i++)
	{
		if(t[i].status == 1)
			cout << t[i].info << endl;
		else
			cout << "vazio" << endl;
	}
}

int main()
{
	int m; // tamanho da tabela hash
	int op; // opção de operação do usuário
	int k; // chave
	dado t[100]; // vetor de 100 posições do tipo dado
	int i; // contador
	int pesquisa; // variável que vai receber o valor de hash_search
	string s; // texto
	
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
	}while(op < 1 || op > 5);
	
	while(op != 5) // pois, quando op == 5, o usuário quer sair do programa
	{
		if(op == 1) // a opção escolhida é "inserir"
		{
			do
			{
				cin >> s;
			}while(s.size() < 0 || s.size() > 50);
			k = calcular_chave(s);
			hash_insert(t, m, k, s);
		} 
		else if(op == 2) // a opção escolhida é "pesquisa"
		{
			do
			{
				cin >> s;
			}while(s.size() < 0 || s.size() > 50);
			k = calcular_chave(s);
			pesquisa = hash_search(t, m, k, s);
			if(pesquisa == -1)
				cout << s << " nao encontrado" << endl;
			else
				cout << s << " encontrado na posicao " << pesquisa << endl;
		}
		else if(op == 3) // a opção escolhida é "remover"
		{
			do
			{
				cin >> s;
			}while(s.size() < 0 || s.size() > 50);
			k = calcular_chave(s);
			hash_remove(t, m, k, s);
		}
		else // quando op == 4, a opção escolhida é "listar"
		{
			hash_list(t, m);
		}
		do
		{
			cin >> op;
		} while(op < 1 || op > 5);
		i++;
	}

	return 0;
}