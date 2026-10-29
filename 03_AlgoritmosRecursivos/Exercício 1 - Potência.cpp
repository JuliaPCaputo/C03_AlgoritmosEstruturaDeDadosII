#include <iostream>
using namespace std;

int potencia(int a, int n)
{
	if(n == 0)
		return 1;
	else
		return a * potencia(a, n - 1);
}

int main()
{
	int a, n; // parâmetros da função
	
	cin >> a >> n;
	cout << potencia(a,n) << endl;
	
	return 0;
}