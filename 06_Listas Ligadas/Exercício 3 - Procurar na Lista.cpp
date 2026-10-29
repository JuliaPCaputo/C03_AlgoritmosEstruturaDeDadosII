/*Faça uma função que receba em sua entrada um ponteiro para uma lista ligada que armazena números inteiros, e um número inteiro, e retorne
true se este estiver na lista, e false caso contrário. O cabeçalho desta função deve ser: bool encontrar(list<int> lista, int x)
Depois, faça um programa que vá lendo vários números e os inserindo na lista, e em seguida leia o número a ser pesquisado. Este deve mostrar a
mensagem "Encontrado", se o número a ser pesquisado estiver na lista, e "Nao encontrado", caso contrário*/

#include <iostream>
#include <list>
using namespace std;

bool encontrar(list <int> lista, int x)
{
	list <int>::iterator p; // ponteiro auxiliar
	
	for(p = lista.begin(); p != lista.end(); p++)
	{
		if(*p == x)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	list <int> lista; // "ponteiro" p/ lista
	int x; // números a serem inseridos na lista
	int procurar; // número a ser procurado na lista
	bool resultado; // resultado da busca
	
	cin >> x;
	
	while(x != 0)
	{
		cin >> x;
		lista.push_back(x);
	}
		
	cin >> procurar;
	resultado = encontrar(lista, procurar);
	
	if(resultado == false)
		cout << "Nao encontrado" << endl;
	else
		cout << "Encontrado" << endl;
	
	return 0;
}