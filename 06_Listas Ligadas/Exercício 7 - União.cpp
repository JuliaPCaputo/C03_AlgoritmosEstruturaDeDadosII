/*Faça um programa que leia os dados de duas listas ligadas cujos elementos estão em ordem crescente, crie e mostre uma terceira lista ligada,
formada pela união dos elementos das duas listas originais, também ordenada em ordem crescente.*/

#include <iostream>
#include <list>
using namespace std;

int main()
{
	list <int> lista1; // "ponteiro" para lista
	list <int> lista2; // "ponteiro" para lista
	list <int> lista3; // "ponteiro" para lista
	list <int>::iterator p1; // ponteiro auxiliar
	list <int>::iterator p2; // ponteiro auxiliar
	list <int>::iterator p3; // ponteiro auxiliar
	int x; // valores a serem inseridos na lista 1
	int y; // valores a serem inseridos na lista 2
	
	cin >> x;
	while(x != 0)
	{
		lista1.push_back(x);
		cin >> x;
	}
	
	cin >> y;
	while(y != 0)
	{
		lista2.push_back(y);
		cin >> y;
	}
	
	p1 = lista1.begin();
	p2 = lista2.begin();
	
	while(p1 != lista1.end() && p2 != lista2.end())
	{
		if (*p1 < *p2)
		{
            lista3.push_back(*p1);
            p1++;
        }
		else if (*p1 > *p2)
		{
            lista3.push_back(*p2);
            p2++;
        }
        else
		{
		    lista3.push_back(*p1);
		    p1++;
		    p2++;
		}
	}
	
	// para o caso de haver elementos ainda não adicionados à lista 3
	while(p1 != lista1.end())
	{
        lista3.push_back(*p1);
        p1++;
    }

    while(p2 != lista2.end())
	{
        lista3.push_back(*p2);
        p2++;
    }
	
	for(p3 = lista3.begin(); p3 != lista3.end(); p3++)
		cout << *p3 << " ";
	
	return 0;
}