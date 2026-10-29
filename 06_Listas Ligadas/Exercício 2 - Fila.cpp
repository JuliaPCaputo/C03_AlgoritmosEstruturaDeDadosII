/*Faça um programa que leia 4 valores inteiros e os insira no final de uma lista ligada (veja que estamos implementando uma fila).
Depois o programa deve ir removendo os elementos da lista e mostrando-os na tela.*/

#include <iostream>
#include <list>
using namespace std;

int main()
{
	list <int> lista;
	int x; // números a serem inseridos na lista
	int i; // contador
	
	for(i = 0; i < 4; i++)
	{
		cin >> x;
		lista.push_back(x);	
	}
	
	for(i = 0; i < 4; i++)
	{
		cout << *lista.begin() << " ";
		lista.pop_front();
	}
	
	return 0;
}