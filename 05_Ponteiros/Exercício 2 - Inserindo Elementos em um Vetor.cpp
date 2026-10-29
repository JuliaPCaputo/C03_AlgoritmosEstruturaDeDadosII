//Faça um programa que leia inicialmente o tamanho N de um vetor de inteiros. Depois, o programa deve alocar dinamicamente um vetor de N posições. Em seguida, o
//programa deve ler N números inteiros e os inseri-los no vetor,usando um segundo ponteiro para esta tarefa: se o vetor é v, e o ponteiro é p, você deve usar p para
//apontar para a posição correta do vetor, e usar este ponteiro para inserir o elemento no vetor. Finalmente, varra o vetor usando um ponteiro, e mostre o seu conteúdo

#include <iostream>
using namespace std;

int main()
{
	int *v = NULL; // ponteiro para um vetor
	int N; // tamanho do vetor
	int i; // contador
	int *p = NULL; // ponteiro auxiliar
	
	cin >> N;
	v = new int[N]; // aloca dinamicamente o vetor

	for(i = 0;i < N; i++)
		cin >> v[i];

	p = v; // ponteiro aponta para o vetor
	
	for(i = 0; i < N; i++)
	{
		cout << *p << " ";
		p++;
	}
	cout << endl;
	
	delete [] v;
	
	return 0;
}