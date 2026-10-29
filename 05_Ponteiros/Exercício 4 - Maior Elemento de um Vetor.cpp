//Faça um programa que leia inicialmente o tamanho N de um vetor de inteiros. Depois, o programa deve ler N números inteiros e os inseri-los no vetor.
//Finalmente, varra o vetor usando um ponteiro, e retorne o maior elemento deste vetor.

#include <iostream>
using namespace std;

int main()
{
	int N; // tamanho do vetor
	int i; // contador
	int *v = NULL; // ponteiro para um vetor
	int maior;
	
	cin >> N;
	v = new int [N];
	
	cin >> v[0];
	maior = v[0];
	
	for(i = 1; i < N; i++)
	{
		cin >> v[i];
		if(v[i] > maior)
			maior = v[i];
	}

	cout << maior << endl;
	
	delete [] v;
	
	return 0;
}