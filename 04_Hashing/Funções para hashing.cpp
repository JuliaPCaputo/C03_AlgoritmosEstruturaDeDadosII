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

int hash1(int k, int i, int m) // função para sondagem linear
{
	int ha;
	
	ha = (hash_aux(k, m) + i) % m;
	
	return ha;
}

int hash2(int k, int i, int m, int c1, int c2) // função para sondagem quadrática
{
	return (hash_aux(k, m) + (c1 * i) + (c2 * i * i)) % m;
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

int hash_search(dado t[], int m, int k) // função para pesquisa na tabela hash
{
	int i = 0; // contador
	int j; // contador
	
	do
	{
		j = hash1(k, i, m);
		if(t[j].k == k)
			return j;
		i++;
	}while(t[j].status != 0 && i < m);
	
	return -1; // se não encontrar na tabela
}

int hash_remove(dado t[], int m, int k) // função para remover da ta bela hash
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

void hash_list(dado t[], int m) // função para listar os itens da tabela hash
{
	for (int i = 0; i < m; ++i)
	//{
        //if (t[i].status == 1) {
            cout << t[i].k << " ";
		//}
	//}
	// se colocar o trecho comentado, os espaços vazios (iguais a -1) não vão aparecer
}

// Funções que usam double hashing

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

// Funções com strings de parâmetro

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