#include <iostream>
#include <cstdio>

using namespace std;

class CNumb{


private:
	int * pi_number;


public :

	CNumb();
	CNumb(CNumb & Pattern);
	CNumb(int i_Numb);
	~CNumb();

	CNumb  & operator = (CNumb & cSnd); //  zeby mozna bylo  uzywac a=b=c operujemy na elemencie nie na jego kopii
	CNumb & operator = (int i_Numb);
	CNumb operator +(CNumb & cSnd);

	void v_clearData();

	void v_show();

};