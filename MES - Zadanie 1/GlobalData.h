#pragma once

class GlobalData {//nH - liczba elementów na danym boku
public:
	double H, B, nH, nB;//nB - ile elementów wchodzi na danym boku
	double szerokosc_elementu, wysokosc_elementu;
	void oblicz_wymiary();
	GlobalData();
};

GlobalData::GlobalData()
{

}

void GlobalData::oblicz_wymiary()
{
	szerokosc_elementu = B / nB;
	wysokosc_elementu = H / nH;
}