#pragma once

#include "Node.h"
#include "Element.h"
#include "GlobalData.h"

using namespace std;

class Grid {
public:
	int nn, ne;//nn - liczba wezlow ne - liczba elementow
	Node *tab_wezlow;//nn
	Element *tab_elementow;//ne
	//GlobalData pole;
	//void stworz_wezly();
	Grid(int, int);

	void generujSiatke(GlobalData globalData);
};

Grid::Grid(int nn, int ne)
{
	this->nn = nn;
	this->ne = ne;
	tab_wezlow = new Node[nn];
	tab_elementow = new Element[ne];
}
inline void Grid::generujSiatke(GlobalData globalData)
{
	bool status = false;
	double Temperture = 0.0;
	for (int i = 0; i < globalData.nB; i++)
	{
		if (i == 0 || i == globalData.nB - 1) //warunek brzegowy -> ogrzewana jest prawa i lewa œciana
			status = true;
		for (int j = 0; j < globalData.nH; j++)
		{
			if (j == 0 || j == globalData.nH - 1) //warunek brzegowy -> ogrzewana jest górna i dolna œciana
				status = true;

			//ustawiam wêz³y w tablicy
			tab_wezlow[(i * globalData.nB) + j].x = globalData.B / globalData.nB;
			tab_wezlow[(i * globalData.nB) + j].y = globalData.H / globalData.nH;
			tab_wezlow[(i * globalData.nB) + j].t = Temperture;
			tab_wezlow[(i * globalData.nB) + j].status = status;
			
			status = false;
		}
		status = false;
	}
	cout << "Wezly w siatce ustawione" << endl;

	for (int i = 0; i < globalData.nB - 1; i++)
	{
		for (int j = 0; j < globalData.nH - 1; j++)
		{
			int index = (i * globalData.nB) + j;
			
			tab_elementow[index].ID[0] = tab_wezlow[index];
			tab_elementow[index].ID[1] = tab_wezlow[index+1];
			tab_elementow[index].ID[2] = tab_wezlow[index + globalData.nH];
			tab_elementow[index].ID[3] = tab_wezlow[index + globalData.nH + 1];
		}
	}
	cout << "Elementy w siatce ustawione" << endl;
}

/*
void Grid::stworz_wezly()
{
	int k = 0;
	for (double i = 0; pole.B; i + pole.szerokosc_elementu)
		for (double j = 0; pole.H; j + pole.szerokosc_elementu)
		{
			tab_wezlow[k] = Node(i, j);
		}
}
*/