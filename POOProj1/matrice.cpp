#include "matrice.h"
#include <iostream>

matrice::matrice() :det(0, 0)
{
}

void matrice::ordonareLinii( matrice &X, unsigned int i) {
	complex temp;
	int aux;
	for (unsigned int k = 0; k < X.Matt[i].second.size() - 1; k++)
		for (unsigned int j = 1; j < X.Matt[i].second.size(); j++)
			if (X.Matt[i].second[k].first > X.Matt[i].second[j].first) {
				aux = X.Matt[i].second[k].first;
				X.Matt[i].second[k].first = X.Matt[i].second[j].first;
				X.Matt[i].second[j].first = aux;
				temp = complex(X.Matt[i].second[k].second);
				X.Matt[i].second[k].second = complex(X.Matt[i].second[j].second);
				X.Matt[i].second[j].second = complex(temp);
			}
}

void matrice::ordonareColoane( matrice &X) {
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

void matrice::insert(complex &x, int linia, int coloana) {
	pair<int, complex>pereche2;  //PREGATIREA VARIABILELOR
	pair<int, vector<pair<int, complex>> >pereche1;
	
	pereche2.first = coloana ;
	pereche2.second = complex(x);
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
			complex temp;
			int aux;
			for (unsigned int k = 0; k < this->Matt[i].second.size() - 1; k++)
				for (unsigned int j = k+1; j < this->Matt[i].second.size(); j++)
					if (Matt[i].second[k].first > Matt[i].second[j].first) {
						aux = Matt[i].second[k].first;
						Matt[i].second[k].first = Matt[i].second[j].first;
						Matt[i].second[j].first = aux;
						temp = complex(Matt[i].second[k].second);
						Matt[i].second[k].second = complex(Matt[i].second[j].second);
						Matt[i].second[j].second = complex(temp);
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
}

complex matrice::getValoareElement(unsigned int linia, unsigned int coloana) {
	complex temp;
	for (unsigned int i = 0; i< this->Matt.size(); i++)
	{
		for (unsigned int j = 0; j<this->Matt[i].second.size(); j++)
		{
			if ((this->Matt[i].first == linia) && (this->Matt[i].second[j].first == coloana)) {
				temp = complex( this->Matt[i].second[j].second);
				return temp;
			}
				
		}
	}
	return temp;
}

//METODE ACCES**************************

 int matrice::getDim() { return this->dimensiune; }

 int matrice::gradMaxim() {
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
 int matrice::gradLinii() { 
	 int max = 0;
	 for (unsigned int i = 0; i < this->Matt.size(); i++)
	 {
		 if (this->Matt[i].first>max)
			 max = this->Matt[i].first;
	 }
	 return max;
 }
 int matrice::gradColoane() { 
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
 ostream& operator<<(ostream &s, matrice &C) {
	 unsigned int k = 0;
	 unsigned int l = 0;
	 complex temp;
	 for (int i = 0; i < C.gradMaxim()+1; i++)
	 {
		 if (k<C.Matt.size() && (C.Matt[k].first == i)) {
			 l = 0;
			 for (int j = 0; j < C.gradMaxim() + 1; j++)
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
			 for (int j = 0; j < C.gradMaxim() + 1; j++)
			 {
				 cout << temp << " ";
			 }
		 }
		 cout << endl;
	 }
	 return s;
 }

 istream & operator>>(istream &s, matrice &C)
 {
	 complex x;
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

 matrice matrice::operator+(matrice &X) {
	matrice temp;
	complex x,y;
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

matrice matrice::operator*(matrice &X) {
	matrice temp;
	unsigned int i, j;
	complex toinsert;
	unsigned int maxLinii, maxColoane;
	this->gradLinii() > X.gradLinii() ? maxLinii = this->gradLinii() : maxLinii = X.gradLinii();
	this->gradColoane() > X.gradColoane() ? maxColoane = this->gradColoane() : maxColoane = X.gradColoane();
	for (i = 0; i <= maxLinii; i++) {
		for (unsigned int k = 0; k <= maxColoane; k++) {
			toinsert = complex::complex();
			for (j = 0; j <= maxColoane; j++) {
				 toinsert = toinsert + (this->getValoareElement(i, j))*(X.getValoareElement(j, k));
			}
			temp.insert(toinsert, i, k);
		}
	}
	return temp;
}

matrice& matrice::operator/(complex x) {
	for (unsigned int  i = 0; i < this->Matt.size(); i++)
	{
		for (unsigned int  j = 0; j < this->Matt[i].second.size(); j++)
		{
			this->Matt[i].second[j].second = this->Matt[i].second[j].second / x;
		}
	}
	return *this;
}

complex matrice::determinant(int grad) {
	int  p, h, k, i, j;
	matrice Y;
	if (grad == 1) {
		for (unsigned int i = 0; i < this->Matt.size(); i++)
		{
			for (unsigned int  j = 0; j < this->Matt[i].second.size(); j++)
			{
				if (this->Matt[i].second[j].second != 0)
					return this->Matt[i].second[j].second;
			}
		}
	}
	if (grad == 2)
	{
		return ((this->getValoareElement(0, 0 )*this->getValoareElement(1 , 1 )) - (this->getValoareElement(1 , 0 )*this->getValoareElement(0 , 1 )));
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
					Y.insert(this->getValoareElement(i , j), h, k);
					k++;
					if (k == grad - 1) {
						h++;
						k = 0;
					}
				}
			}
			this->det = this->det + ((this->getValoareElement(0, p)) * (Y.determinant(grad - 1)) * (float)pow(-1, p));
		}
		return this->det;
	}
}

matrice& matrice::operator=(const matrice &X)
{
	if (this->Matt.capacity() < X.Matt.capacity()) {
		this->Matt.reserve(X.Matt.size());
	}
	pair<int, vector<pair<int, complex>>>liniiContent;
	pair<int, complex>colContent;

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
matrice matrice::cofactor(matrice &X, int grad)
{	
	matrice b;
	matrice fac;
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
			fac.insert(b.determinant(grad-1)*(float)pow(-1, p + q), q , p );
			b.~matrice();
		}
	}
	return transpose(fac, grad);
}

/*Finding transpose of matrix*/
matrice matrice::transpose( matrice &Y, int grad)
{
		matrice inverse;
		for (int i = 0; i < Y.gradMaxim() + 1; i++)
		{
			for (int j = 0; j < Y.gradMaxim() + 1; j++)
			{
				inverse.insert(Y.getValoareElement(i, j), j, i);
			}
		}
		return inverse;
}

matrice matrice::MatrixInvers() {
	matrice Inversa;

	complex x(1, 0);
	complex detPrin = x/determinant(this->gradMaxim()+1);

//	x=complex();

	return cofactor(*this, this->gradMaxim()+1)/detPrin;  
}


 bool matrice::estePatratica() {
	 if (this->gradLinii() == this->gradColoane())
		 return true;
	 else
		 return false;
 }

 //DECONSTRUCTOR
matrice::~matrice() {
	this->Matt.erase(this->Matt.begin(),this->Matt.end());
}


// *****FIRST TRY, WITH STRUCT AND SHIT
/*
 void matrice::insert(complex &x, int linia, int coloana) {
	if (primCol==NULL) { //introducem un nod pe prima col daca e nula
		dimensiune = 1;
		primCol = new nod2;
		primCol->linia = linia;
		primCol->prim = new matrice::nod;
		primCol->next = NULL;
					//Probably useless
		dimensiune = 0;
		nrLinii = 1;
		nrCol = 1;
		//nrColoane.insert(coloana,1);
		nrColoane[coloana] = 1;
					//useless end
		primCol->prim->coloana = coloana;
		primCol->prim->nrComplex=complex::complex(x);
		primCol->prim->next = NULL;
	}
	else {			//daca nu e nula, introducem un nod 
		nod2 *p = primCol;
		while (p->linia < linia && p->next && p->next->linia<linia)
			p = p->next;				//cautam pox de introdus
		if (p->linia == linia) {			//cazul cand avem un singur nod in col de inceput
				nod *p2 = p->prim;
				while (p2->coloana < coloana && p2->next) {
					p2 = p2->next;
				}
				dimensiune += 1;
				if (!nrColoane[coloana]) {
					nrColoane[coloana] = 1;
					nrCol += 1;
				}
				if (p2 == p->prim && coloana<p->prim->coloana) {		//introducere inainte prim element al liniei
					nod *temp = new nod;
					temp->coloana = coloana;
					temp->next = p->prim;
					p->prim = temp;
					temp->nrComplex = complex(x);
				}
				else {
					nod *temp = new nod;
					temp->coloana = coloana;
					temp->next = p2->next;
					p2->next = temp;
					temp->nrComplex = complex(x);
				}
		}
		else {		//inseram o noua linie de inceput in prima coloana
			nod2 *temp = new nod2;
			temp->linia = linia;
			temp->prim = new nod;
			temp->prim->coloana = coloana;
			temp->prim->nrComplex = complex(x);
			temp->prim->next = NULL;
			temp->next = p->next;
			p->next = temp;
			if (!nrColoane[coloana]) {
				nrColoane[coloana] = 1;
				nrCol += 1;
			}
			nrLinii += 1;
			dimensiune += 1;
		}
	}
}


 //METODE ACCES**************************

 long matrice::getDim() { return this->dimensiune; }
 int matrice::getLinii() { return this->nrLinii; }
 int matrice::getColoane() { return this->nrCol; }

 complex matrice::getValoareElement(int linia, int coloana) {
	 complex temp;
	 if (!primCol) {
		 return temp;
	 }

	 nod2 *ciclare = primCol;
	 while (ciclare && ciclare->linia != linia) {
		 ciclare = ciclare->next;
	 }

	 if (!ciclare) {
		 return temp;
	 }

	 nod *ciclare2 = ciclare->prim;
	 while (ciclare2 && ciclare2->coloana != coloana) {
		 ciclare2 = ciclare2->next;
	 }

	 if (ciclare2 && ciclare2->coloana == coloana) {
		 temp = complex(ciclare2->nrComplex);
		 return temp;
	 }

	 return temp;
 }

matrice::~matrice()
{
	delete[] coloane;
	delete[] linii;
//	delete[] valori;
}
*/