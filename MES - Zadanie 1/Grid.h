#pragma once

#include "Node.h"
#include "Element.h"
#include "GlobalData.h"

class Grid {
public:
	int nn, ne;//nn - liczba wezlow ne - liczba elementow
	Node *tab_wezlow;//nn
	Element *tab_elementow;//ne
	GlobalData pole;
	void stworz_wezly();
	Grid(int, int);
};

Grid::Grid(int x, int y)
{
	nn = x;
	ne = y;
	tab_wezlow = new Node[nn];
	tab_elementow = new Element[ne];
}

void Grid::stworz_wezly()
{
	int k = 0;
	for (double i = 0; pole.B; i + pole.szerokosc_elementu)
		for (double j = 0; pole.H; j + pole.szerokosc_elementu)
		{
			tab_wezlow[k] = Node(i, j);
		}
}