#include "CNumb.h"




int main(){


	CNumb arg0, arg1, sum;

	cout << endl;
	arg0 = 5;
	cout << endl;
	arg1 = 8;
	cout << endl;
	cout << endl;
	sum = arg0 + arg1;
	cout << endl;

	arg0.v_show();
	arg1.v_show();
	sum.v_show();



	getchar();
	cin.ignore();
	return 0;
}