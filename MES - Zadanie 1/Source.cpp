#include <iostream>
#include <iomanip>
#include "Node.h"
#include "Element.h"
#include "Grid.h"
#include "GlobalData.h"

using namespace std;
double f(double, double);


int main() {
	int np;

	cout << "Wprowadz liczbe npc: ";
	cin >> np;
	
	double *punkty3 = new double[np];
	double *punkty2 = new double[np];

	double *wagi3 = new double[np];
	double *wagi2 = new double[np];

	punkty3[0] = -sqrt(3.0 / 5.0); //-0.774597
	punkty3[1] = 0.0;
	punkty3[2] = sqrt(3.0 / 5.0); //0.774597
	wagi3[0] = 5.0 / 9.0;
	wagi3[1] = 8.0 / 9.0;
	wagi3[2] = 5.0 / 9.0;
	
	punkty2[0] = -1.0 / sqrt(3.0); //-0.57735
	punkty2[1] = 1.0 / sqrt(3.0); //0.57735
	wagi2[0] = 1;
	wagi2[1] = 1;

	double wynik = 0.0;
	if (np == 3)
		for (int i = 0; i<np; i++)
			for (int j = 0; j<np; j++)
				wynik += f(punkty3[i], punkty3[j])*wagi3[i] * wagi3[j];
	
	//cout<<f(punkty[i],punkty[j])<<endl;

	if (np == 2)
		for (int i = 0; i<np; i++)
			for (int j = 0; j<np; j++)
				wynik += f(punkty2[i], punkty2[j])*wagi2[i] * wagi2[j];
	cout << setprecision(20) << "Wynik calkowania Gauss'em [dla " << np << " npc]: " << wynik << endl;


	system("PAUSE");
	return 0;
}

double f(double x, double y)
{
	return 2 * (pow(x, 2))*pow(y, 2) + 6 * x + 5;
}