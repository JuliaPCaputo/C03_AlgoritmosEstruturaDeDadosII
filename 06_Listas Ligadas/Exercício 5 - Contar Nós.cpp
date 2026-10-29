/*Faça uma função que receba em sua entrada um ponteiro para uma lista ligada, e retorne o número de nós nesta lista. Esta função deve ter o
seguinte cabeçalho: int contar(list<int> lista). Depois, faça um programa que vá lendo vários números e os inserindo na lista, e em seguida
mostre o número de nós desta lista.*/

#include <iostream>
#include <list>
using namespace std;

int contar(list<int> lista)
{
	list <int>::iterator p; // ponteiro auxiliar
	int quantidade = 0; // quantidade de valores na lista
	
	for(p = lista.begin(); p != lista.end(); p++)
		quantidade++;
	
	return quantidade;
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
	
	cout << contar(lista) << endl;
	
	return 0;
}