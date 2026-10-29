//A Robélia, chefe das secretárias do Inatel, está querendo organizar o registro acadêmico dos alunos, e pediu para você ajudá-la. Ela precisa de
//um sistema de armazene o nome de cada aluno, bem como seu curso e número de matrícula. Depois ela quer digitar o nome de um aluno, e o sistema
//deve retornar o curso e o nome de matrícula deste aluno. Será que você consegue ajudá-la?

#include <iostream>
using namespace std;

struct registro
{
	string nome; // nome do aluno
	string curso; // curso do aluno
	int matricula; // número de matrícula do aluno
};

int main()
{
	int N; // quantidade de alunos a serem armazenados
	int i; // contador
	registro dados[10000]; // vetor do tipo registro de até 10k posições com os dados dos alunos
	string procurar; // nome do aluno a ser localizado
	bool encontrado = false; // verifica se o aluno foi encontrado
	
	do{
		cin >> N;
	} while (N < 1 || N > 10000);
	
	for (i = 0; i < N; i++)
	{
		cin.ignore();
		getline(cin, dados[i].nome);
		getline(cin, dados[i].curso);
		cin >> dados[i].matricula;
	}
	
	cin.ignore();
	getline(cin, procurar);
	
	for (i = 0; i < N; i++)
	{
		if(procurar == dados[i].nome)
		{
			cout << dados[i].nome << endl;
			cout << dados[i].curso << endl;
			cout << dados[i].matricula << endl;
			encontrado = true;
			break;
		}
	}
	
	if (encontrado == false)
		cout << "Aluno nao localizado" << endl;
	
	return 0;
}