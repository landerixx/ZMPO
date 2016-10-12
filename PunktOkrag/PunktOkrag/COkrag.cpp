#include "COkrag.h"


COkrag::COkrag(double d_x = 0, double d_y = 0, double d_r = 1 ){

	this->d_wspX = d_x;
	this->d_wspY = d_y;
	this->d_promien = d_r;
}


//juz jest zdefiniowany konstruktor domyslny!
COkrag::COkrag(double d_r){

	this->d_wspX = 0;
	this->d_wspY = 0;
	this->d_promien = d_r;
}





void COkrag::v_show(){

	cout << "okrag, jego wspolrzedne: (" << to_string(d_wspX) << "," << to_string(d_wspY) << ") o promienu " << to_string(d_promien) << endl;

}