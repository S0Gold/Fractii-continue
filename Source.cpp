// Algoritmul de scriere a unui numar real a
// sub forma de fractie continua normala 

#include <iostream>
#include<math.h>
using namespace std;

double b[1000];
double c[1000];

void FractieContinuaNormala(double, int);
void AfiseazaFractia(int);
double Calculeaza(int);

int main()
{
	double x;
	int nrit;
	//cout << "Introduceti numarul : "; cin >> x;
	//cout << "Introduceti numarul de iteratii : "; cin >> nrit;
	FractieContinuaNormala(sqrt(2), 100);
	system("pause");
}

// implementarea functiei
void FractieContinuaNormala(double a, int numarIteratii)
{
	cout << "\n---------------------------------------------\n";

	b[0] = int(a);

	if (a == b[0])
	{
		cout << "Fractia continua normala finita: " << a << " = " << b[0];
		return;
	}

	c[1] = 1.0 / (a - b[0]);
	b[1] = int(c[1]);

	for (int i = 1; i <= numarIteratii; i++) // repetam de un numar maxim de ori
	{
		if (c[i] - b[i] <= 0.0001) // eroare de calcul
		{
			cout << "Fractia continua regulata finita: \n" << a << " = ";
			AfiseazaFractia(i);
			cout << "Valoarea aploximata: " << Calculeaza(i) << endl;
			return;
		}

		c[i + 1] = 1.0 / (c[i] - b[i]);
		b[i + 1] = int(c[i + 1]);

	}
	cout << "Fractie continua regulata infinita: \n" << a << " = ";
	AfiseazaFractia(numarIteratii);
	cout << "Valoarea aploximata: " << Calculeaza(numarIteratii) << endl;
}

void AfiseazaFractia(int n)
{
	int i;
	cout << "[";
	for (i = 0; i <= n; i++)
		if (i == n)
			cout << b[i];
		else
			cout << b[i] << ", ";
	cout << "]\n\n";

	cout << b[0];
	for (i = 1; i <= n; i++)
	{
		cout << " + " << "1" << "\n";
		for (int j = 1; j <= 1 + (4 * i) - 1; j++)
			cout << " ";
		for (int k = 1; k <= 5; k++)
			cout << "_";
		cout << "\n";
		for (int j = 1; j <= 1 + (4 * i) - 1; j++)
			cout << " ";
		cout << b[i];
	}
	cout << endl;
}

double Calculeaza(int n)
{
	double R[1000];
	double S[1000];
	R[0] = b[0];
	R[1] = b[0] * b[1] + 1;
	S[0] = 1;
	S[1] = b[1];
	for (int k = 2; k <= n; k++)
	{
		R[k] = b[k] * R[k - 1] + 1 * R[k - 2];
		S[k] = b[k] * S[k - 1] + S[k - 2];
	}
	return R[n] / S[n];
}



