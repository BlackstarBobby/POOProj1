#pragma once
#include "complex.h"
#include <vector>

//using namespace std;



template <class t_type> 
class matrice
{
private:
	vector < pair<int, vector< pair<int, complex<t_type> > > > > Matt;
	complex<t_type> det;
	int liniiDim,colDim;
public:
	matrice();
	matrice(char *nume, matrice<t_type>&);
	~matrice();

	//----------Metode acces

	 void insert(complex<t_type> &x,int linia,int coloana);
	 void ordonareLinii( matrice<t_type> &, unsigned int i);
	 void ordonareColoane( matrice<t_type> &);

	 int getDim();

	 int gradMaxim();
	 int gradLinii();
	 int gradColoane();
	 //
	complex<t_type> getValoareElement(unsigned int i, unsigned int j);

	//complex<t_type> determinant(int grad);
	virtual void determinant(complex<t_type>&, int grad);
	
	
	//virtual complex<int> determinant(int grad);
	//virtual complex<float> determinant(int grad);
	//virtual complex<double> determinant(int grad);

	matrice<t_type> MatrixInvers();
	matrice<t_type> cofactor(matrice<t_type> &, int);
	matrice<t_type> transpose( matrice<t_type>&, int);
	complex<t_type> operator ()(int i, int j);

	template <class t_type> friend ostream& operator<<(ostream&, matrice<t_type> &);
	template <class t_type> friend istream& operator>>(istream&, matrice<t_type> &);

	//Metode prelucrare

	matrice<t_type>& operator=(const matrice<t_type>&);
	 matrice<t_type> operator +(matrice<t_type> &);
	matrice<t_type> operator -(matrice<t_type> &);
	matrice<t_type> operator *(matrice<t_type> &);
	matrice<t_type> operator *(complex<t_type>);
	matrice<t_type>& operator /(complex<t_type>);
	matrice<t_type> operator !();
	matrice<t_type> Inversa();
	bool estePatratica();
};

template <class t_type>
class matrice_patratica :public matrice<t_type> {
	int ordin;
	t_type deter;
public:
	matrice_patratica(char *fisier): matrice<t_type>::matrice(fisier,*this) {
		ordin = this->gradMaxim();
	}
	~matrice_patratica(){
		matrice<t_type>::~matrice();
	}
	
	  void determinant(complex<t_type>&, int grad);

	virtual int getOrdin() {
		return ordin+1;
	}
};

template <class t_type>
class patratica_triunghiulara :public matrice_patratica<t_type> {
	int ordin;
	t_type deter;
public:
	patratica_triunghiulara(char *fisier):matrice_patratica<t_type>::matrice_patratica(fisier) {
		matrice_patratica<t_type> *p = this;
		ordin = p->gradMaxim()+1;
	}
	~patratica_triunghiulara() {
		matrice<t_type>::~matrice();
	}
	void determinant(complex<t_type>&, int grad);

	bool esteTriunghiulara() {
		matrice<t_type> *temp = this;
		for (unsigned int i = 0; i < ordin; i++)
		{
			for (unsigned int j = 0; j < ordin; j++)
			{
				if (i != j) {
					if (temp->getValoareElement(i, j) == 0 && temp->getValoareElement(j, i) == 0)
						return false;
					if (temp->getValoareElement(i, j) != 0 && temp->getValoareElement(j, i) != 0)
						return false;
				}
			}
			return true;
		}
	}

	bool esteScalara() {
		matrice<t_type> *temp = this;
		for (unsigned int i = 0; i < ordin-1; i++)
		{
			if (temp->getValoareElement(i, i) != temp->getValoareElement(i + 1, i + 1)) {
				return false;
			}
		}
		return true;
	}
};