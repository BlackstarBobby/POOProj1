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
	char optiune;
	do {
		system("cls");
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
		cout << "A\n" << A << endl;
		cout << "B\n" << B << endl;
		cout << "Suma matricilor este:\n";
		cout << A + B;
		cout << "\nProdusul matricilor este:\n";
		cout << A*B;
		cout << "\nDeterminantul primei matrici este:\n";
			cout<< A.determinant(A.gradMaxim()+1);
		cout << "\nDeterminantul celei de-a 2 matrici este:\n";
			cout << B.determinant(B.gradMaxim()+1);
		cout << "\nInversa primei matrici este:\n";
		if (A.determinant(A.gradMaxim() + 1) != 0) {
			cout << A.MatrixInvers();
		}
		else
			cout << "Determinantul matricii e zero, nu se poate face inversa\n";
		cout << "\nInversa celei de-a 2 matrici este:\n";
		if (B.determinant(B.gradMaxim() + 1) != 0) {
			cout << B.MatrixInvers();
		}
		else
			cout << "Determinantul matricii e zero, nu se poate face inversa\n";
		
		cout << "\n\nReluati? (y/n)";
		cin >> optiune;
	} while (optiune == 'y');
	return 0;
}