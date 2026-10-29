/*Faça um programa que leia 4 valores inteiros e os insira em uma pilha. Depois o programa deve ir removendo os elementos da pilha e mostrando-os
na tela.*/

#include <iostream>
#include <list>
using namespace std;

int main()
{
	list <int> lista; // "ponteiro" p/ lista
	int x;
	int i;
	
	for(i = 0; i < 4; i++)
	{
		cin >> x;
		lista.push_front(x);
	}
	
	for(i = 0; i < 4; i++)
	{
		cout << *lista.begin() << " ";
		lista.pop_front();
	}
	
	return 0;
}