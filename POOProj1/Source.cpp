#include <iostream>
#include <fstream>
#include <cstdlib>
#include "complex.h"
#include "matrice.h"

using namespace std;
ifstream inf("intrare.txt");

//Nota!!!!!!!!!!!!!!!!!!!! La insert in matrice, scad -1 din pozitia dorita, la linie si coloana

int main() {

	matrice A, B;
	unsigned int nrElemNenule;
	do {
		cout <<"Introduceti numarul de elemente nenule ale primei matrici\n";
		cin >> nrElemNenule;
		for (unsigned int i = 0; i < nrElemNenule; i++)
		{
			cin >> A;
		}
		system("cls");
		cout << "Introduceti numarul de elemente nenule ale celei de-a doua matrice\n";
		cin >> nrElemNenule;
		for (unsigned int i = 0; i < nrElemNenule; i++)
		{
			cin >> B;
		}
		system("cls");
		cout << "Suma matricilor este:\n";
		cout << A + B;
		cout << "Produsul matricilor este:\n";
		cout << A*B;
		cout << "Determinantul primei matrici este:\n";
		cout << A.determinant(A.gradMaxim());
		cout << "Determinantul celei de-a 2 matrici este:\n";
		cout << B.determinant(B.gradMaxim());
		cout << "Inversa primei matrici este:\n";
		cout << A.MatrixInvers();
		cout << "Inversa celei de-a 2 matrici este:\n";
		cout << B.MatrixInvers();
	} while (true);
	return 0;
}