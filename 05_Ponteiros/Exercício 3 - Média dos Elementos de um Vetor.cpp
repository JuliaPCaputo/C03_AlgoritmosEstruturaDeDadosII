//Faça um programa que leia inicialmente o tamanho N de um vetor de inteiros. Depois, o programa deve ler N números inteiros e os inseri-los no vetor.
//Finalmente, varra o vetor usando um ponteiro, e calcule a média dos elementos deste vetor.  

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int *v = NULL; // ponteiro para um vetor
	int N; // tamanho do vetor
	int i; // contador
	int *p = NULL; // ponteiro auxiliar
	double soma = 0; // soma das notas
	
	cin >> N;
	v = new int[N];
	for(i = 0; i < N; i++)
		cin >> v[i];
	p = v;
	for(i = 0; i < N; i++)
	{
		soma = soma + *p;
		p++;
	}
		
	cout << fixed << setprecision(2);
	cout << soma / (N * 1.0) << endl;
	
	delete [] v;
	
	return 0;
}