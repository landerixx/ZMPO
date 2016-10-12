#ifndef COkrag_h
#define COkrag_h

#include <string>
#include <iostream>
#include <cmath>

// include musi byc nad deklaracja klasy Cpunkt ??
#include "CPunkt.h"


using namespace std;


class COkrag{

private:

	double d_wspX;
	double d_wspY;
	double d_promien;

public:

	COkrag(double d_x, double d_y, double d_r);
	COkrag(double d_r);
	
	void v_show();

	friend double CPunkt::d_odleglosc(COkrag & c_Obj);

	//friend class CPunkt;

};








#endif