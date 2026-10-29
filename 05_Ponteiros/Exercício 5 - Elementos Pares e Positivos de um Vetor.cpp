//Faça um programa que leia inicialmente o tamanho N de um vetor de inteiros. Depois, o programa deve ler N números inteiros e os inseri-los no vetor.
//Finalmente, varra o vetor usando um ponteiro, e determine quantos elementos são pares e positivos.  

#include <iostream>
using namespace std;

int main()
{
	int N; // tamanho do vetor
	int i; // contador
	int *v = NULL; // ponteiro para um vetor
	int soma = 0; // soma dos valores positivos e pares
	
	cin >> N;
	v = new int[N];
	
	for(i = 0; i < N; i++)
	{
		cin >> v[i];
		if(v[i] > 0 && v[i] % 2 == 0)
			soma++;
	}
	
	cout << soma << endl;
	
	delete []v;
	
	return 0;
}