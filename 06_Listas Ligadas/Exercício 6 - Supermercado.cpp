/*Um gerente de supermercado possui duas listas, sendo a primeira com os códigos de produtos que estão no estoque, e a segunda com os códigos
dos produtos que já estão disponíveis para venda. Sempre que um produto novo chega, primeiro ele é adicionado no estoque, e depois é movido
para venda, à medida em que os produtos vão sendo vendidos. Ele precisa de alguém para gerenciar essas listas e contratou você para o serviço.*/

#include <iostream>
#include <list>
using namespace std;

int main()
{
	list <int> estoque; // "ponteiro" para a lista de estoques
	list <int> venda; // "ponteiro" para a lista de vendas
	int x; // valor a ser adicionado à lista
	int N; // número de operações
	int op; // operação
	int i; // contador
	list <int>::iterator produto; // ponteiro para o produto a ser transferido de lista
	list <int>::iterator p; // ponteiro aux
	
	do{
		cin >> N;
	}while(N <= 0);
	
	for(i = 0; i < N; i++)
	{
		do{
			cin >> op;
		}while(op != 1 && op != 2);
		
		if(op == 1)
		{
			cin >> x;
			estoque.push_back(x); // primeiro a entrar e primeiro a sair
		}
		else
		{
			produto = estoque.begin();
			estoque.pop_front();
			venda.push_front(*produto);
		}
	}
	
	cout << "Estoque: ";
	for(p = estoque.begin(); p != estoque.end(); p++)
		cout << *p << " ";
	
	cout << endl;
	
	cout << "Venda: ";
	for(p = venda.begin(); p != venda.end(); p++)
		cout << *p << " ";
	
	return 0;
}