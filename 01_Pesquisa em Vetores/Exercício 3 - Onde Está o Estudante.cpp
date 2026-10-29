//Na cidade de Morangoleste, existe um dormitório enorme. Acredita-se que existem cerca de 10.000 estudantes morando ali. Imagine se eles
//fossem procurar um estudante de forma sequencial, gastariam muito tempo. Então, o responsável pelo dormitório teve uma ideia: armazenar os
//números de matrícula em um sistema, e a posição em que a matrícula ficasse seria o número do corredor em que o estudante deveria ficar.

#include <iostream>
using namespace std;

int main()
{
	int N; //	número de alunos
	int i; // contador
	int mat[10000]; //vetor de até 10k posições com as matrículas
	int procurar; // matrícula a ser procurada
	bool encontrado = false; // verifica se a matrícula foi encontranda
	
	do{
		cin >> N;
	}while (N < 1 || N > 10000);
	
	for (i = 0; i < N; i++)
		cin >> mat[i];
	
	cin >> procurar;
	
	for (i = 0; i < N; i++)
	{
		if (mat[i] == procurar)
		{
			cout << "Corredor " << i << endl;
			encontrado = true;
			break;
		}
	}
	
	if (encontrado == false)
		cout << "Nao localizado" << endl;
	
	return 0;
}