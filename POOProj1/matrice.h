#pragma once
#include "complex.h"
#include <vector>

using namespace std;

class matrice
{public:
/*public:
	struct nod {
		int coloana;
		complex nrComplex=complex::complex(0.0,0.0);
		nod *next;

		//nod(){}
	};
	struct nod2 {
		int linia;
		nod *prim;
		nod2 *next;
	};*/
private:
	vector < pair<int, vector< pair<int, complex> > > > Matt;
	complex det;
	unsigned int dimensiune = 0;
public:
	matrice();
	~matrice();

	//----------Metode acces

	 void insert(complex &x,int linia,int coloana);
	 void ordonareLinii( matrice &, unsigned int i);
	 void ordonareColoane( matrice &);

	 int getDim();

	 int gradMaxim();
	 int gradLinii();
	 int gradColoane();
	 //
	complex getValoareElement(unsigned int i, unsigned int j);

	complex determinant(int grad);
	matrice MatrixInvers();
	matrice cofactor(matrice &, int);
	matrice transpose( matrice&, int);
	complex operator ()(int i, int j);

	friend ostream& operator<<(ostream&, matrice &);
	friend istream& operator>>(istream&, matrice &);

	//Metode prelucrare

	//matrice operator =(matrice &);
	void operator =(matrice &);
	//matrice operator =( matrice &y);
	 matrice operator +(matrice &);
	matrice operator -(matrice &);
	matrice operator *(matrice &);
	matrice operator *(complex);
	matrice& operator /(complex);
	matrice operator !();
	matrice Inversa();
	bool estePatratica();
};