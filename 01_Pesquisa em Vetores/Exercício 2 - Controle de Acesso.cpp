//Com o avanço da tecnologia, muitos empresas adotaram o método do cartão magnético para controle de acesso aos seus ambientes. Você deve
//construir um programa que verifique se uma ID (identificação) tem acesso ao ambiente. Antes de ser informado a ID, será informado a lista de IDS
//que possuem acesso ao ambiente. Obs: A verificação de acesso deve ser rápida. Portanto, use busca binária.

#include <iostream>
using namespace std;

int binaria(int vetor[],int tamanho, int x)
{
	bool achou; // var aux p/ busca
	int baixo, meio, alto; // var aux
	
	baixo = 0;
	alto = tamanho-1;
	achou = false;
	
	while ((baixo <= alto) && (achou == false))
	{
		meio = (baixo + alto) / 2;
		if (x < vetor[meio])
			alto = meio - 1;
		else
		{
			if (x > vetor[meio])
				baixo = meio + 1;
			else
				achou = true;
		}
	}
	
	if (achou)
		return meio;
	else
		return -1;
}

int main()
{
	int ID; // número que deseja verificar
	int vetor[20]; // vetor de até 20 ID's
	int i; // contador
	int tamanho = 0; //tamanho do vetor
	int acesso; // verifica na função se a ID foi ou não identificada
	
	for (i = 0; i < 20; i++)
	{
		cin >> vetor[i];
		if (vetor[i] == -1)
			break;
		else
			tamanho++;
	}
	
	cin >> ID;
	
	acesso = binaria(vetor, tamanho, ID);
	
	if (acesso == -1)
		cout << "Nao possui acesso" << endl;
	else
		cout << "Possui acesso" << endl;
	
	return 0;
}