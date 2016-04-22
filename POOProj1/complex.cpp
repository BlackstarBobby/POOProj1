#include "complex.h"


complex::complex(float r, float im):real(r), imag(im) {
}
//                                 COPY CONSTRUCTOR
complex::complex(const complex &c){
	this->real = c.real;
	this->imag = c.imag;
}


//------- METODE PRELUCRARE ----------------------
void complex::operator =(complex &c){
	this->real = c.real;
	this->imag = c.imag;
}

complex complex::operator +(complex &c){
	complex tmp;
	tmp.real = this->real + c.real;
	tmp.imag = this->imag + c.imag;
	return tmp;
}

complex complex::operator -(complex &c){
	complex tmp;
	tmp.real = this->real - c.real;
	tmp.imag = this->imag - c.imag;
	return tmp;
}

complex complex::operator *(complex &c){
	complex tmp;
	tmp.real = (real*c.real) - (imag*c.imag);
	tmp.imag = (real*c.imag) + (imag*c.real);
	return tmp;
}

complex complex::operator*(float x) {
	complex tmp;
	tmp.real = real*x;
	tmp.imag = imag*x;
	return tmp;
}

bool complex::operator!=(float c)
{
	if (this->real != c || this->imag != c)
		return true;
	else
		return false;
}

complex complex::operator /(complex &c){
	float div = (c.real*c.real) + (c.imag*c.imag);
	complex tmp;
	tmp.real = (real*c.real) + (imag*c.imag);
	tmp.real /= div;
	tmp.imag = (imag*c.real) - (real*c.imag);
	tmp.imag /= div;
	return tmp;
}

bool complex::operator ==(complex c){
	return (real == c.real) && (imag == c.imag) ? 1 : 0;
}


//--------------- INPUT/OUTPUT METHODS --------------------
ostream& operator <<(ostream &s, complex &c){
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

istream & operator>>(istream & s, complex & c)
{
	//cout << "Partea reala:";
	s >> c.real;
	//cout << "Partea imaginara:";
	s >> c.imag;
	return s;
}/*
 istream& operator>> (istream& (*pf)(istream&), complex &c) {
	 if (pf) {

	 }

}*/

complex::~complex()
{
}



//*****************NOT TO USEFUL*****************************
complex complex::getconjugate() {
	complex tmp;
	tmp.real = this->real;
	tmp.imag = this->imag * -1;
	return tmp;
}

complex complex::getreciprocal() {
	complex t;
	t.real = real;
	t.imag = imag * -1;
	float div;
	div = (real*real) + (imag*imag);
	t.real /= div;
	t.imag /= div;
	return t;
}

float complex::getmodulus() {
	float z;
	z = (real*real) + (imag*imag);
	z = sqrt(z);
	return z;
}

void complex::setdata(float r, float i) {
	real = r;
	imag = i;
}

void complex::getdata() {
	cout << "Enter Real:";
	cin >> this->real;
	cout << "Enter Imaginary:";
	cin >> this->imag;

}

float complex::getreal() {
	return real;
}

float complex::getimaginary() {
	return imag;
}
