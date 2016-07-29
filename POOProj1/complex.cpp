#pragma once
#include "complex.h"


//***********	CONSTRUCTOR CU PARAMETRII
template <class a_type>
complex<a_type>::complex(a_type r, a_type im){//:real(r), imag(im) {
	real = r;
	imag = im;
}

//************************	CONSTRUCTOR FARA PARAMETRII
template <class a_type>
complex<a_type>::~complex()
{
}
//                                 COPY CONSTRUCTOR
template <class a_type>
complex<a_type>::complex(const complex &c){
	this->real = c.real;
	this->imag = c.imag;
}


//------- METODE PRELUCRARE ----------------------
template <class a_type>
complex<a_type>& complex<a_type>::operator=(const complex<a_type>& x) {
	this->real = x.real;
	this->imag = x.imag;
	return *this;
}

template <class a_type>
complex<a_type> complex<a_type>::operator +(const complex<a_type> &c){
	complex<a_type> tmp;
	tmp.real = this->real + c.real;
	tmp.imag = this->imag + c.imag;
	return tmp;
}
template <class a_type>
complex<a_type> complex<a_type>::operator -(const complex<a_type> &c){
	complex<a_type> tmp;
	tmp.real = this->real - c.real;
	tmp.imag = this->imag - c.imag;
	return tmp;
}
template <class a_type>
complex<a_type> complex<a_type>::operator *(const complex<a_type> &c){
	complex<a_type> tmp;
	tmp.real = (real*c.real) - (imag*c.imag);
	tmp.imag = (real*c.imag) + (imag*c.real);
	return tmp;
}
template <class a_type>
complex<a_type> complex<a_type>::operator*(a_type x) {
	complex<a_type> tmp;
	tmp.real = real*x;
	tmp.imag = imag*x;
	return tmp;
}
template <class a_type>
bool complex<a_type>::operator!=(a_type c)
{
	if (this->real != c || this->imag != c)
		return true;
	else
		return false;
}
template<class a_type>
bool complex<a_type>::operator==(a_type var)
{
	if (this->real == var && this->imag == var)
		return true;
	return false;
}
template <class a_type>
complex<a_type> complex<a_type>::operator /(const complex<a_type>&c){
	float div = (c.real*c.real) + (c.imag*c.imag);
	complex<a_type> tmp;
	tmp.real = (real*c.real) + (imag*c.imag);
	tmp.real /= div;
	tmp.imag = (imag*c.real) - (real*c.imag);
	tmp.imag /= div;
	return tmp;
}
template <class a_type>
bool complex<a_type>::operator ==(const complex<a_type>& c){
	return (real == c.real) && (imag == c.imag) ? 1 : 0;
}

template<class a_type>
bool complex<a_type>::operator!=(const complex<a_type>& c)
{
	if (this->real != c.real && this->imag != c.real)
		return true;
	return false;
}


//--------------- INPUT/OUTPUT METHODS --------------------
template <class a_type>
ostream& operator <<(ostream &s, complex<a_type> &c){
	/*s << "Real Part = " << c.real << endl
		<< "Imaginary Part = " << c.imag << endl;
	s << "z = " << c.real << setiosflags(ios::showpos)
		<< c.imag << "i" << endl << resetiosflags(ios::showpos);*/
	s << c.real;
	if (c.imag == 0) {
		s << "+" << 0<<"i";
		return s;
	}else if (c.imag > 0)
		s << "+";
	else if (c.imag < 0)
		s << "-";
	s<< c.imag << "i";
	return s;
}

template <class a_type>
istream & operator>>(istream & s, complex<a_type> & c)
{
	//cout << "Partea reala:";
	s >> c.real;
	//cout << "Partea imaginara:";
	s >> c.imag;
	return s;
}




//*****************NOT TO USEFUL*****************************
/*
complex complex<a_type>::getconjugate() {
	complex tmp;
	tmp.real = this->real;
	tmp.imag = this->imag * -1;
	return tmp;
}

complex complex<a_type>::getreciprocal() {
	complex t;
	t.real = real;
	t.imag = imag * -1;
	float div;
	div = (real*real) + (imag*imag);
	t.real /= div;
	t.imag /= div;
	return t;
}

float complex<a_type>::getmodulus() {
	float z;
	z = (real*real) + (imag*imag);
	z = sqrt(z);
	return z;
}

void complex<a_type>::setdata(float r, float i) {
	real = r;
	imag = i;
}

void complex<a_type>::getdata() {
	cout << "Enter Real:";
	cin >> this->real;
	cout << "Enter Imaginary:";
	cin >> this->imag;

}

float complex<a_type>::getreal() {
	return real;
}

float complex<a_type>::getimaginary() {
	return imag;
}
*/
