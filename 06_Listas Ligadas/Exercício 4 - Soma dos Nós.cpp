/*Faça uma função que receba em sua entrada um ponteiro para uma lista ligada, e retorne a soma dos nós nesta lista. O cabeçalho desta função
deve ser: int soma(list<int> lista). Depois, faça um programa que vá lendo vários números e os inserindo na lista, e em seguida mostre a soma
dos nós desta lista.*/

#include <iostream>
#include <list>
using namespace std;

int soma(list<int> lista)
{
	list <int>::iterator p; // ponteiro auxiliar
	int soma = 0; // soma dos valores da lista
	
	for(p = lista.begin(); p != lista.end(); p++)
		soma += *p;
	
	return soma;
}

int main()
{
	list <int> lista; // "ponteiro" para lista
	int x; // números a serem inseridos na lista
	
	cin >> x;
	
	while(x != 0)
	{
		lista.push_back(x);
		cin >> x;
	}
	
	cout << soma(lista) << endl;
	
	return 0;
}