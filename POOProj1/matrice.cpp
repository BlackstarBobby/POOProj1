#pragma once
#include "matrice.h"
#include <iostream>
#include <fstream>

//CONSTRUCTORI
template <class a_type>
matrice<a_type>::matrice()
{
	det = (a_type)0;
	liniiDim = (a_type)0;
	colDim = (a_type)0;
}
template <class a_type>
matrice<a_type>::matrice(char *nume, matrice<a_type>& mat) {
	ifstream inf(nume);
	
	complex<a_type> x;
	int tempint, tempint2;
	while (!inf.eof()) {
		inf >> x >> tempint >> tempint2;
		mat.insert(x, tempint-1, tempint2-1);
		if (inf.eof())break;
	}
	inf.close();
	//return maxul;
}

template<class a_type>
void matrice<a_type>::ordonareLinii( matrice<a_type>&X, unsigned int i) {
	complex<a_type> temp;
	int aux;
	for (unsigned int k = 0; k < X.Matt[i].second.size() - 1; k++)
		for (unsigned int j = 1; j < X.Matt[i].second.size(); j++)
			if (X.Matt[i].second[k].first > X.Matt[i].second[j].first) {
				aux = X.Matt[i].second[k].first;
				X.Matt[i].second[k].first = X.Matt[i].second[j].first;
				X.Matt[i].second[j].first = aux;
				temp = complex<a_type>(X.Matt[i].second[k].second);
				X.Matt[i].second[k].second = complex<a_type>(X.Matt[i].second[j].second);
				X.Matt[i].second[j].second = complex<a_type>(temp);
			}
}

template<class a_type>
void matrice<a_type>::ordonareColoane( matrice<a_type> &X) {
	int k;
	unsigned int i;
	for (i = 0; i< X.Matt.size() - 1; i++)		//ORDONAREA PRIMEI COLOANE
		for (unsigned int j = i+1; j <X.Matt.size()-1; j++) {
			if (X.Matt[i].first > Matt[j].first) {
				k = Matt[i].first;
				Matt[i].first = Matt[j].first;
				Matt[j].first = k;
				Matt[i].second.swap(Matt[j].second);
			}
		}
}

template<class a_type>
void matrice<a_type>::insert(complex<a_type> &x, int linia, int coloana) {
	pair<int, complex<a_type>>pereche2;  //PREGATIREA VARIABILELOR
	pair<int, vector<pair<int, complex<a_type>>> >pereche1;
	
	pereche2.first = coloana ;
	pereche2.second = complex<a_type>(x);
	pereche1.first = linia ;

	bool LinieComuna = false;		//INSERAREA PE ACEEASI LINIE
	unsigned int i;
	for (i = 0; i < this->Matt.size(); i++) {
		if (Matt[i].first == linia) {
			LinieComuna = true;
			break;
		}
	}
	if (LinieComuna) {
		Matt[i].second.push_back(pereche2);
		if (Matt[i].second.size()>1) {			//ORDONAREA ELEMENTELOR AT CAND SE INTRODUCE PE ACEEASI LINIE
			complex<a_type> temp;
			int aux;
			for (unsigned int k = 0; k < this->Matt[i].second.size() - 1; k++)
				for (unsigned int j = k+1; j < this->Matt[i].second.size(); j++)
					if (Matt[i].second[k].first > Matt[i].second[j].first) {
						aux = Matt[i].second[k].first;
						Matt[i].second[k].first = Matt[i].second[j].first;
						Matt[i].second[j].first = aux;
						temp = complex<a_type>(Matt[i].second[k].second);
						Matt[i].second[k].second = complex<a_type>(Matt[i].second[j].second);
						Matt[i].second[j].second = complex<a_type>(temp);
					}
		}
	}
	else {
		pereche1.second.push_back(pereche2);		//ADAUGAREA UNUI NOI LINII
		Matt.push_back(pereche1);
	}

	int k;
	for ( i = 0; i< this->Matt.size()-1; i++)		//ORDONAREA PRIMEI COLOANE
		for (unsigned int j = i+1; j < this->Matt.size(); j++) {
			if (Matt[i].first > Matt[j].first) {
				k = Matt[i].first;
				Matt[i].first = Matt[j].first;
				Matt[j].first = k;
				Matt[i].second.swap(Matt[j].second);
			}
		}
	liniiDim = gradLinii();
	colDim = gradColoane();
}

template<class a_type>
complex<a_type> matrice<a_type>::getValoareElement(unsigned int linia, unsigned int coloana) {
	complex<a_type> temp;
	for (unsigned int i = 0; i< this->Matt.size(); i++)
	{
		for (unsigned int j = 0; j<this->Matt[i].second.size(); j++)
		{
			if ((this->Matt[i].first == linia) && (this->Matt[i].second[j].first == coloana)) {
				temp = complex<a_type>( this->Matt[i].second[j].second);
				return temp;
			}
				
		}
	}
	return temp;
}

//METODE ACCES**************************

template<class a_type>
 int matrice<a_type>::getDim() { return this->dimensiune; }

 template<class a_type>
 int matrice<a_type>::gradMaxim() {
	  int max = 0, max2 = 0;
	 for (unsigned int i = 0; i < this->Matt.size(); i++)
	 {
		 if (this->Matt[i].first>max)
			 max = this->Matt[i].first;
		 for (unsigned int j = 0; j < this->Matt[i].second.size(); j++)
		 {
			 if (this->Matt[i].second[j].first>max2)
			 {
				 max2 = this->Matt[i].second[j].first;
			 }
		 }
	 }
	 if (max > max2)
		 return max;
	 else
		 return max2;
 }
 template<class a_type>
 int matrice<a_type>::gradLinii() { 
	 int max = 0;
	 for (unsigned int i = 0; i < this->Matt.size(); i++)
	 {
		 if (this->Matt[i].first>max)
			 max = this->Matt[i].first;
	 }
	 return max;
 }
 template<class a_type>
 int matrice<a_type>::gradColoane() { 
	  int max = 0, max2 = 0;
	 for (unsigned int i = 0; i < this->Matt.size(); i++)
	 {
		 if (this->Matt[i].first>max)
			 max = this->Matt[i].first;
		 for (unsigned int j = 0; j < this->Matt[i].second.size(); j++)
		 {
			 if (this->Matt[i].second[j].first>max2)
			 {
				 max2 = this->Matt[i].second[j].first;
			 }
		 }
	 }
	 return max2;
 }

 //AFISARE*****************
 template<class a_type>
 ostream& operator<<(ostream &s, matrice<a_type> &C) {
	 unsigned int k = 0;
	 unsigned int l = 0;
	 complex<a_type> temp;
	 for (int i = 0; i < C.gradLinii()+1; i++)
	 {
		 if (k<C.Matt.size() && (C.Matt[k].first == i)) {
			 l = 0;
			 for (int j = 0; j < C.gradColoane() + 1; j++)
			 {
				 if ((l < C.Matt[k].second.size()) && C.Matt[k].second[l].first == j) {
					 cout << C.Matt[k].second[l].second << " ";
					 l++;
				 }
				 else {
					 cout << temp << " ";
				 }
			 }
			 k++;
		 }
		 else {
			 for (int j = 0; j < C.gradColoane() + 1; j++)
			 {
				 cout << temp << " ";
			 }
		 }
		 cout << endl;
	 }
	 return s;
 }

 template<class a_type>
 istream & operator>>(istream &s, matrice<a_type> &C)
 {
	 complex<a_type> x;
	 cout << "\nIntroduceti partea reala si partea imaginara a numarului complex\n";
	 cin >> x;
	 int a, b;
	 cout << "\nIntroduceti linia: ";
	 cin >> a;
	 cout << "Introduceti coloana: ";
	 cin >> b;
	 C.insert(x,a-1,b-1);
	 return s;
 }

 //METODE PRELUCRARE********************************************************************
 template<class a_type>
 matrice<a_type> matrice<a_type>::operator+(matrice<a_type> &X) {
	matrice<a_type> temp;
	complex<a_type> x,y;
	unsigned int i, j;
	 unsigned int maxLinii, maxColoane;
	 this->gradLinii() > X.gradLinii() ? maxLinii = this->gradLinii() : maxLinii = X.gradLinii();
	 this->gradColoane() > X.gradColoane() ? maxColoane = this->gradColoane() : maxColoane = X.gradColoane();
	for ( i = 0; i <= maxLinii; i++){
		for (j = 0; j <= maxColoane; j++)
			if ((this->getValoareElement(i, j)==x) && (X.getValoareElement(i, j)==y) )
				continue;
			else
				temp.insert(this->getValoareElement(i, j) + X.getValoareElement(i, j), i, j);
	}

	return temp;
}

 template<class a_type>
matrice<a_type> matrice<a_type>::operator*(matrice<a_type> &X) {
	matrice<a_type> temp;
	unsigned int i, j;
	complex<a_type> toinsert;
	unsigned int maxLinii, maxColoane;
	this->gradLinii() > X.gradLinii() ? maxLinii = this->gradLinii() : maxLinii = X.gradLinii();
	this->gradColoane() > X.gradColoane() ? maxColoane = this->gradColoane() : maxColoane = X.gradColoane();
	for (i = 0; i <= maxLinii; i++) {
		for (unsigned int k = 0; k <= maxColoane; k++) {
			toinsert = complex<a_type>::complex();
			for (j = 0; j <= maxColoane; j++) {
				 toinsert = toinsert + (this->getValoareElement(i, j))*(X.getValoareElement(j, k));
			}
			temp.insert(toinsert, i, k);
		}
	}
	return temp;
}

template<class a_type>
matrice<a_type>& matrice<a_type>::operator/(complex<a_type> x) {
	for (unsigned int  i = 0; i < this->Matt.size(); i++)
	{
		for (unsigned int  j = 0; j < this->Matt[i].second.size(); j++)
		{
			this->Matt[i].second[j].second = this->Matt[i].second[j].second / x;
		}
	}
	return *this;
}



//*************************	DETERMINANTI********************

template<class a_type>
 void matrice<a_type>::determinant(complex<a_type>& x,int grad) {
	int  p, h, k, i, j;
	matrice<a_type> Y;
	if (grad == 1) {
		for (unsigned int i = 0; i < this->Matt.size(); i++)
		{
			for (unsigned int  j = 0; j < this->Matt[i].second.size(); j++)
			{
				if (this->Matt[i].second[j].second != 0)
					//return this->Matt[i].second[j].second;
					x = Matt[i].second[j].second;;
			}
		}
	}
	if (grad == 2)
	{
		x= ((this->getValoareElement(0, 0 )*this->getValoareElement(1 , 1 )) - (this->getValoareElement(1 , 0 )*this->getValoareElement(0 , 1 )));
	}
	else
	{
		complex<a_type> temp;
		for (p = 0; p < grad; p++) {
			h = 0;
			k = 0;
			Y.~matrice();
			for (i = 1; i < grad; i++) {
				for (j = 0; j < grad; j++) {
					if (j == p) {
						continue;
					}
					Y.insert(this->getValoareElement(i , j), h, k);
					k++;
					if (k == grad - 1) {
						h++;
						k = 0;
					}
				}
			}
			Y.determinant(temp, grad - 1);
			x = x + ((this->getValoareElement(0, p)) * temp * (a_type)pow(-1, p));
		}
		//return this->det;
	}
}
 
/*
complex<int> matrice<int>::determinant(int grad) {
	int  p, h, k, i, j;
	matrice<int> Y;
	if (grad == 1) {
		for (unsigned int i = 0; i < this->Matt.size(); i++)
		{
			for (unsigned int j = 0; j < this->Matt[i].second.size(); j++)
			{
				if (this->Matt[i].second[j].second != 0)
					return this->Matt[i].second[j].second;
			}
		}
	}
	if (grad == 2)
	{
		return ((this->getValoareElement(0, 0)*this->getValoareElement(1, 1)) - (this->getValoareElement(1, 0)*this->getValoareElement(0, 1)));
	}
	else
	{
		for (p = 0; p < grad; p++) {
			h = 0;
			k = 0;
			Y.~matrice();
			for (i = 1; i < grad; i++) {
				for (j = 0; j < grad; j++) {
					if (j == p) {
						continue;
					}
					Y.insert(this->getValoareElement(i, j), h, k);
					k++;
					if (k == grad - 1) {
						h++;
						k = 0;
					}
				}
			}
			this->det = this->det + ((this->getValoareElement(0, p)) * (Y.determinant(grad - 1)) * (int)pow(-1, p));
		}
		return this->det;
	}
}
*/
 //******************************************
template<class a_type>
matrice<a_type>& matrice<a_type>::operator=(const matrice<a_type> &X)
{
	if (this->Matt.capacity() < X.Matt.capacity()) {
		this->Matt.reserve(X.Matt.size());
	}
	pair<int, vector<pair<int, complex<a_type>>>>liniiContent;
	pair<int, complex<a_type>>colContent;

	for (unsigned int  i = 0; i < X.Matt.size(); i++)
	{
		/*
		//this->Matt[i].first = X.Matt[i].first;

		if (this->Matt[i].second.capacity() < X.Matt[i].second.capacity()) {
			this->Matt[i].second.reserve(X.Matt[i].second.size());
		}
		for (unsigned int j = 0; j < X.Matt[i].second.size(); j++)
		{
			this->Matt[i].second[j].first = X.Matt[i].second[j].first;
			this->Matt[i].second[j].second = this->Matt[i].second[j].second;
		}*/
		liniiContent.first = X.Matt[i].first;
		for (unsigned j = 0; j < X.Matt[i].second.size(); j++)
		{
			colContent.first = X.Matt[i].second[j].first;
			colContent.second = X.Matt[i].second[j].second;
			liniiContent.second.push_back(colContent);
		}
		this->Matt.push_back(liniiContent);
		liniiContent.second.clear();
	}
	return *this;
}

//***************************************************************************
//---------------VARIANTA DE GASIRE INVERSA ------
template<class a_type>
matrice<a_type> matrice<a_type>::cofactor(matrice<a_type> &X, int grad)
{	
	matrice<a_type> b;
	matrice<a_type> fac;
	complex<a_type> temp;
	int p, q, m, n, i, j;
	for (q = 0; q<grad; q++){
		for (p = 0; p<grad; p++){
			m = 0;
			n = 0;
			for (i = 0; i<grad; i++){
				for (j = 0; j<grad; j++){
					if (i != q && j != p){
						b.insert(X.getValoareElement(i, j), m , n);
						if (n<(grad - 2))
							n++;
						else{
							n = 0;
							m++;
						}
					}
				}
			}
			b.determinant(temp, grad - 1);
			fac.insert(temp*(float)pow(-1, p + q), q , p );
			b.~matrice();
		}
	}
	return transpose(fac, grad);
}

/*Finding transpose of matrix*/
template<class a_type>
matrice<a_type> matrice<a_type>::transpose( matrice<a_type> &Y, int grad)
{
		matrice<a_type> inverse;
		for (int i = 0; i < Y.gradMaxim() + 1; i++)
		{
			for (int j = 0; j < Y.gradMaxim() + 1; j++)
			{
				inverse.insert(Y.getValoareElement(i, j), j, i);
			}
		}
		return inverse;
}

template<class a_type>
matrice<a_type> matrice<a_type>::MatrixInvers() {
	matrice<a_type> Inversa;

	complex<a_type> x(1, 0);
	complex<a_type> deImpartit;
	determinant(deImpartit, this->gradMaxim() + 1);
	complex<a_type> detPrin = x/deImpartit;

//	x=complex();

	return cofactor(*this, this->gradMaxim()+1)/detPrin;  
}

template<class a_type>
 bool matrice<a_type>::estePatratica() {
	 if (this->gradLinii() == this->gradColoane())
		 return true;
	 else
		 return false;
 }

 //DECONSTRUCTOR
 template<class a_type>
matrice<a_type>::~matrice() {
	this->Matt.erase(this->Matt.begin(),this->Matt.end());
}


template <class a_type>
void matrice_patratica<a_type>::determinant(complex<a_type>&x,int grad){
	complex<a_type> rezultat;
	rezultat = this->getValoareElement(0, 0);
	for (int i =1; i < grad; i++) {
		rezultat = rezultat * this->getValoareElement(i, i);
	}
	x= rezultat;
}

template <class a_type>
void patratica_triunghiulara<a_type>::determinant(complex<a_type>&x, int grad) {
	complex<a_type> rezultat;
	rezultat = this->getValoareElement(0, 0);
	for (int i = 1; i < grad; i++) {
		rezultat = rezultat * this->getValoareElement(i, i);
	}
	x = rezultat;
}