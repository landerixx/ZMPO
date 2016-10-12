#include "COkrag.h"







int main(){




	COkrag okrag(2,2,1);
	CPunkt punkt(2.5,2);


	okrag.v_show();
	punkt.v_show();

	cout << " odleglosc punktu od  okregu wynosi: ";
	cout <<punkt.d_odleglosc(okrag);



	cin.ignore();
	return 0;
}