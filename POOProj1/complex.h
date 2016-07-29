#pragma once
#include <ostream>
#include <iostream>
#include <iomanip>
using namespace std;
template <class a_type>
class complex
{
	//friend class matrice;
	template <class t_type> friend class matrice;
private:
	a_type real;
	a_type imag;
public:
	complex(a_type r = 0.0f, a_type im = 0.0f);
	complex(const complex&);
	
	//Not real using them
	/*float getmodulus();
	void setdata(float, float);
	void getdata();
	float getreal();
	float getimaginary();
	complex getconjugate();
	complex getreciprocal();*/

	//METODE PRELUCRARE*******************
	complex<a_type> operator +(const complex<a_type>&);
	complex<a_type> operator -(const complex<a_type>&);
	complex operator *(const complex<a_type> &);
	complex<a_type> operator /(const complex<a_type> &);
	complex<a_type> operator *(a_type);
	bool operator !=(a_type);
	bool operator ==(a_type);
	bool operator ==(const complex<a_type>&);
	bool operator !=(const complex<a_type>&);
	//void operator =(const complex &);
	complex<a_type>& operator=(const complex<a_type>&);
	template <class a_type> friend ostream& operator <<(ostream &s, complex<a_type> &c);
	template <class a_type> friend istream& operator >>(istream &s, complex<a_type> &c);

	//friend istream& operator>> (istream& (*pf)(istream&),complex &); 

	~complex();
};

