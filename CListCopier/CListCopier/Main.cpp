#include "CListCopier.h"



int main(){


	CListCopier lista1;


	lista1.vAddInt(1);
	lista1.vAddInt(2);
	lista1.vAddInt(3);

	CListCopier lista2;

	lista2.vAddInt(5);
	lista2.vAddInt(6);
	lista2.vAddInt(7);

	CListCopier lista;
	lista= lista1 + lista2;


	cout << " 1 lista " << endl;
	lista1.show();

	cout << " 2 lista " << endl;
	lista2.show();

	cout << " suma list " << endl;
	lista.show();






	/*

	cout << "1 lista" << endl;
	lista1.show();
	lista1.showMem();


	cout << "tworze 2 liste" << endl;
	CListCopier lista2;
	lista2 = lista1;

	cout << "1 lista usuwam ostatni" << endl;
	lista1.vDeleteInt();


	cout << "1 lista" << endl;
	lista1.show();
	lista1.showMem();


	cout << "2 lista" << endl;
	lista2.show();
	lista2.showMem();
	*/


	getchar();
	cin.ignore();
	return 0;
}