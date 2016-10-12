#include "CTable.h"


int main(){


	CTable tablica(4);
	CTable tablica1(5);

	tablica.bSetValue(0, 0);
	tablica.bSetValue(1, 1);
	tablica.bSetValue(2, 2);


	
	tablica1.bSetValue(0, 4);
	tablica1.bSetValue(1, 5);
	tablica1.bSetValue(2, 6);
	tablica1.bSetValue(3, 7);

	tablica.vshow();
	cout << endl;
	tablica1.vshow();
	cout << endl;

	tablica.vAddValues(tablica1);

	tablica.vshow();
	cout << endl;
	tablica1.vshow();
	cout << endl;




	getchar();
	cin.ignore();
	return 0;

}