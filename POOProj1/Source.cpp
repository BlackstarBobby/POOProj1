#include <iostream>
#include <fstream>
#include <cstdlib>
#include "complex.h"
#include "matrice.h"
#include "complex.cpp"
#include "matrice.cpp"

using namespace std;
//ifstream inf("matPatratica.txt");

//Nota!!!!!!! La insert in matrice, scad -1 din pozitia dorita, la linie si coloana

int main() {
	/*
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

	*/

	complex<int> a(3, 4);
	cout << a<<endl;
	complex<double> b(5.44, 4.66);
	cout << b<<endl;
	matrice<int>A;
	matrice<double>B;
	A.insert(a, 3-1, 5-1);
	B.insert(b, 7-1, 2-1);
	cout << A << endl << B<<endl;

	
	complex<int>deter;
	A.determinant(deter,A.gradMaxim());
	cout << deter << endl;

	matrice_patratica<int> D("triunghi.txt");
	//D.insert(a, 3, 5);
	cout << D << endl;// << D.determinant(D.gradMaxim()) << endl;
//	complex<int>deter;
	matrice<int> *point = &D;
	D.matrice_patratica<int>::determinant(deter,D.getOrdin());
	cout << deter << endl;
	
	
	patratica_triunghiulara<float>E("scalara.txt");
	complex<float>ddd;
	matrice_patratica<float> *pp = &E;
	pp->determinant(ddd, pp->getOrdin());
	cout << E << endl << ddd << endl;
	if (E.esteScalara())
		cout << "este scalara" << endl;
	else
		cout << "nu este scalara" << endl;

	patratica_triunghiulara<float>F("triunghi.txt");
	cout << endl << F << endl;
	if (F.esteTriunghiulara())
		cout << "este triunghiulara" << endl;
	else
		cout << "nu este triunghiulara" << endl;
	
	//trimit din derivate numele in ala de baza din care sa faca citirea matricii

	return 0;
}