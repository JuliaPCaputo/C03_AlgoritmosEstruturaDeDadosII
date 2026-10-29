//Queremos guardar alguns dados ds atletas de uma equipe em uma tabela hash. Os dados são: nome, idade, peso, altura. Desta forma, podemos criar
//uma struct para armazenar estes dados: struct info {string nome; int idade; float peso; float altura;}; E a struct dado ficaria assim:
//struct dado {info atleta; // nome, idade, peso e altura de cada atleta int k; // chave int status; // 0:vazio, 1:ocupado, 2:removido};
//Repita o problema anterior para um esquema de hashing que gere a chave a partir do nome de cada atleta. Como no exercício anterior, a chave deve
//ser calculada como a soma dos valores ASCII de cada um de seus caracteres. Por exemplo, "Inatel" gera uma chave k = 605. USE O DOUBLE HASHING
//PARA ESTE PROBLEMA.

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct info
{
	string nome;
	int idade;
	float peso;
	float altura;
};

struct dado
{
	info atleta; // nome, idade, peso e altura de cada atleta
	int k; // chave
	int status; // 0: vazio, 1: ocupado, 2: removido
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

int hash_insert(dado t[], int m, int k, string s, int idade, float peso, float altura) // função para inserção na tabela hash
{
	int i = 0, j;
	
	do{
		j = dhash(k, m, i);
		if(t[j].status != 1)
		{
			t[j].k = k;
			t[j].status = 1;
			t[j].atleta.nome = s;
			t[j].atleta.idade = idade;
			t[j].atleta.peso = peso;
			t[j].atleta.altura = altura;
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
		if(t[j].status == 1 && t[j].k == k && t[j].atleta.nome == s)
		{
			return j;
		}
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
       t[j].atleta.nome = "";
       t[j].atleta.idade = 0;
       t[j].atleta.peso = 0;
       t[j].atleta.altura = 0;
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
		{
			cout << "Nome: " << t[i].atleta.nome << endl;
			cout << "Idade: " << t[i].atleta.idade << endl;
			cout << fixed << setprecision(1); 
			cout << "Peso: " << t[i].atleta.peso << endl;
			cout << fixed << setprecision(2);
			cout << "Altura: " << t[i].atleta.altura << endl;
			cout << endl;
		}
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
	string nm; // nome do atleta
	int id; // idade do atleta
	float ps; // peso do atleta
	float alt; // altura do atleta
	
	do
	{
		cin >> m;
	}while(m < 0 || m > 100);
	
	for(i = 0; i < m; i++) // para garantir que o vetor está vazio
	{
		t[i].status = 0;
		t[i].k = -1;
		t[i].atleta.nome = "";
		t[i].atleta.idade = 0;
		t[i].atleta.peso = 0;
		t[i].atleta.altura = 0;
	}
	
	do{
		cin >> op;
	}while(op < 1 || op > 5);
	
	while(op != 5) // pois, quando op == 5, o usuário quer sair do programa
	{
		cin.ignore();
		if(op == 1) // a opção escolhida é "inserir"
		{
			do
			{
				getline(cin, nm);
			}while(nm.size() < 0 || nm.size() > 50);
			do
			{
				cin >> id;
			}while(id < 0 || id > 100);
			do
			{
				cin >> ps;
			}while(ps < 0 || ps > 200);
			do
			{
				cin >> alt;
			}while(alt < 0 || alt > 2.50);
			k = calcular_chave(nm);
			hash_insert(t, m, k, nm, id, ps, alt);
		} 
		else if(op == 2) // a opção escolhida é "pesquisa"
		{
			do
			{
				getline(cin, nm);
			}while(nm.size() < 0 || nm.size() > 50);
			k = calcular_chave(nm);
			pesquisa = hash_search(t, m, k, nm);
			if(pesquisa == -1)
			{
				cout << nm << " nao encontrado" << endl;
				cout << endl;
			}
			else
			{
				cout << "Nome: " << t[pesquisa].atleta.nome << endl;
				cout << "Idade: " << t[pesquisa].atleta.idade << endl;
				cout << fixed << setprecision(1); 
				cout << "Peso: " << t[pesquisa].atleta.peso << endl;
				cout << fixed << setprecision(2); 
				cout << "Altura: " << t[pesquisa].atleta.altura << endl;
				cout << endl;
			}
		}
		else if(op == 3) // a opção escolhida é "remover"
		{
			do
			{
				getline(cin, nm);
			}while(nm.size() < 0 || nm.size() > 50);
			k = calcular_chave(nm);
			hash_remove(t, m, k, nm);
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