#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double raiz(double x, double x0, double E)
{
	if((fabs(pow(x0, 2) - x)) <= E)
		return x0;
	else
		return raiz(x, ((pow(x0, 2) + x) / (2 * x0)), E);
}

int main()
{
	double x, x0, E;
	
	cin >> x >> x0 >> E;
	cout << fixed << setprecision(4);
	cout << raiz(x, x0, E) << endl;
	
	return 0;
}