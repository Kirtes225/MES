#include <iostream>
#include <iomanip>

#include <fstream>
#include <string>

#include "Node.h"
#include "Element.h"
#include "Grid.h"
#include "GlobalData.h"

using namespace std;


int main() {
	GlobalData globalData;
	string * lines = new string[4];
	int i = 0;

	ifstream infile("globalData.txt");
	string line;
	while (getline(infile, lines[i])) {
			cout << lines[i] << endl;
			i++;
	}
	infile.close();

	globalData.H = stod(lines[0]); 
	globalData.B = stod(lines[1]);
	globalData.nH = stoi(lines[2]);
	globalData.nB = stoi(lines[3]);

	cout << "\nTEST\n" << globalData.H << endl;
	cout << globalData.B << endl;
	cout << globalData.nH << endl;
	cout << globalData.nB << endl << endl;;

	//przypisuje iloœæ wêz³ów elementów w siatce
	Grid grid((globalData.nH + 1)*(globalData.nB + 1), globalData.nH*globalData.nH);  
	grid.generujSiatke(globalData);


	system("PAUSE");
	return 0;
}