//Defina uma struct que armazene quatro notas de uma pessoa e a média destas notas. Depois faça um programa que use um ponteiro para alocar
//memória para esta struct, leia 4 notas, armazenando-as na struct alocada. Por fim, o programa deve calcular a média das notas, armazená-la na
//struct e mostrar a média calculada, com 2 casas decimais. IMPORTANTE: não se esqueça de desalocar a memória ocupada pela struct ao final do
//programa!

#include <iostream>
#include <iomanip>
using namespace std;

struct notas
{
	int N1, N2, N3, N4; // notas do aluno
	double md; // média das notas
};

int main()
{
	notas *aluno = NULL;
	aluno = new notas;
	
	cin >> aluno->N1 >> aluno->N2 >> aluno->N3 >> aluno->N4;
	aluno->md = (aluno->N1 + aluno->N2 + aluno->N3 + aluno->N4) / 4.0;
	
	cout << fixed << setprecision(2);
	cout << aluno->md << endl;
	delete[] aluno;
	
	return 0;
} 