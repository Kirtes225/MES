#pragma once

class GlobalData {//nH - liczba elementów na danym boku
public:
	double H, B;//nB - ile elementów wchodzi na danym boku

	int nH, nB;

	double szerokosc_elementu, wysokosc_elementu;
	void oblicz_wymiary();
	GlobalData();
	GlobalData(double, double, int, int);
};

GlobalData::GlobalData()
{
}

GlobalData::GlobalData(double H, double B, int nH, int nB)
{
	this->H = H;
	this->B = B;
	this->nH = nH;
	this->nB = nB;
}

void GlobalData::oblicz_wymiary()
{
	szerokosc_elementu = B / nB;
	wysokosc_elementu = H / nH;
}