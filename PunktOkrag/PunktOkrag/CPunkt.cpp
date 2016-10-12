#include "CPunkt.h"
#include "COkrag.h"



CPunkt::CPunkt(double d_x=0, double d_y=0){

	this->d_wspX = d_x;
	this->d_wspY = d_y;
	
}

void CPunkt::v_show(){

	cout << "Punkt, jego wspolrzedne: (" << to_string(d_wspX) << "," << to_string(d_wspY) << ")" << endl;

}


double CPunkt::d_odleglosc(COkrag & c_Obj){

	double d_x = pow((this->d_wspX - c_Obj.d_wspX),2);
	double d_y = pow((this->d_wspY - c_Obj.d_wspY),2);

	double d_distanceCenterCircle = sqrt((d_x + d_y));

	return abs(d_distanceCenterCircle - c_Obj.d_promien);

}

