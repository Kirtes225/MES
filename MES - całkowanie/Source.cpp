#include <iostream>
#include <cmath>

#define TWO 2
#define THREE 3

using namespace std;

//https://en.wikipedia.org/wiki/Gaussian_quadrature

const double TWO_POINTS[] = {
	-1.0 / sqrt(3.0),	//-0.57735
	1.0 / sqrt(3.0)		//0.57735
};

const double TWO_WEIGHTS[] = {
	1.0,
	1.0
};

const double THREE_POINTS[] = {
	-sqrt(3.0/5.0),		//-0.774597
	0.0,
	sqrt(3.0 / 5.0)		//0.774597
};

const double THREE_WEIGHTS[] = {
	5.0/9.0,
	8.0/9.0,
	5.0/9.0
};

double function(double, double);
double gaussQuadratureTwoPoints(double(*)(double, double));
double gaussQuadratureThreePoints(double(*)(double, double));

int main() 
{
	cout.precision(20);

	cout << "Gauss - Legendre quadrature [2 POINTS]: " << gaussQuadratureTwoPoints(function) << endl;
	cout << "Gauss - Legendre quadrature [3 POINTS]: " << gaussQuadratureThreePoints(function) << endl;
	
	system("pause");
	return 0;
}

double function(double x, double y)
{
	return 2*pow(x, 2)*pow(y, 2)+6*x+5;
}

double gaussQuadratureTwoPoints(double(*)(double, double))
{
	double result = 0;
	for (int i = 0; i < TWO; i++)
		for (int j = 0; j < TWO; j++)
			result += function(TWO_POINTS[i], TWO_POINTS[j])*TWO_WEIGHTS[i]*TWO_WEIGHTS[j];
	return result;
}

double gaussQuadratureThreePoints(double (*)(double, double))
{
	double result = 0;
	for (int i = 0; i < THREE; i++)
		for (int j = 0; j < THREE; j++)
			result += function(THREE_POINTS[i], THREE_POINTS[j])*THREE_WEIGHTS[i]*THREE_WEIGHTS[j];
	return result;
}
