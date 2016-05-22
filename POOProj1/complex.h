#pragma once
#include <ostream>
#include <iostream>
#include <iomanip>
using namespace std;

class complex
{
	friend class matrice;
private:
	float real;
	float imag;
public:
	complex(float r = 0.0f, float im = 0.0f);
	complex(const complex&);
	
	//Not real using them
	float getmodulus();
	void setdata(float, float);
	void getdata();
	float getreal();
	float getimaginary();
	complex getconjugate();
	complex getreciprocal();

	//METODE PRELUCRARE*******************
	complex operator +(const complex &);
	complex operator -(const complex &);
	complex operator *(const complex &);
	complex operator /(const complex &);
	complex operator *(float);
	bool operator !=(float);
	bool operator ==(const complex);
	//void operator =(const complex &);
	complex& operator=(const complex&);
	friend ostream& operator <<(ostream &s, complex &c);
	friend istream& operator >>(istream &s, complex &c);

	//friend istream& operator>> (istream& (*pf)(istream&),complex &); 

	~complex();
};

