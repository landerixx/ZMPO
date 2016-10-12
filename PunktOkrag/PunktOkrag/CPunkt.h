#ifndef CPunkt_h
#define CPunkt_h


//#include "COkrag.h"
//pulta sie tylko o cuouty


class COkrag;



class CPunkt{

private:
	double d_wspX;
	double d_wspY;
	
public:

	CPunkt(double d_x, double d_y); 
	void v_show();


  double d_odleglosc(COkrag & c_Obj);



};


// include musi byc pod deklaracja klasy ???






#endif