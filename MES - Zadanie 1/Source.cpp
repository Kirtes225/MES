#include <iostream>
#include <iomanip>

using namespace std;
double f(double, double);

class node; class globalData; class grid; class element;

class node {
public:
	double x, y, t;
	int status;
	node(double, double);
	node();
};

node::node()
{

}

node::node(double x, double y)
{
	this->x = x;
	this->y = y;
}

class element {
	int ID[4];
	//walls[4]
};

class globalData {//nH - liczba elementów na danym boku
public:
	double H, B, nH, nB;//nB - ile elementów wchodzi na danym boku
	double szerokosc_elementu, wysokosc_elementu;
	void oblicz_wymiary();
	globalData();
};

globalData::globalData()
{

}

void globalData::oblicz_wymiary()
{
	szerokosc_elementu = B / nB;
	wysokosc_elementu = H / nH;
}

class grid {
public:
	int nn, ne;//nn - liczba wezlow ne - liczba elementow
	node *tab_wezlow;//nn
	element *tab_elementow;//ne
	globalData pole;
	void stworz_wezly();
	grid(int, int);
};

grid::grid(int x, int y)
{
	nn = x;
	ne = y;
	tab_wezlow = new node[nn];
	tab_elementow = new element[ne];
}

void grid::stworz_wezly()
{
	int k = 0;
	for (double i = 0; pole.B; i + pole.szerokosc_elementu)
		for (double j = 0; pole.H; j + pole.szerokosc_elementu)
		{
			tab_wezlow[k] = node(i, j);
		}
}

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

	cout << punkty3[0] << endl;

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