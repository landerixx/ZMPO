
#include "CHexNumber.h"




int main(){

	
	
	string s_input;
	bool b_priopriety;

	CHexNumb obj1;
	CHexNumb obj2;
	CHexNumb *pobj1 = &obj1;
	CHexNumb *pobj2 = &obj2;

	CHexNumb *du = new CHexNumb();
	cout << "Witam w kalkulatorze liczb szesnastkowych. \nWprowadz pierwsza liczbe:" << endl;

	do{ 

		cin >> s_input;
		b_priopriety = pobj1->b_enter(s_input);
		if (!b_priopriety)
			cout << "Niestety, nie podales prawidlowo pierwszej liczby, podaj jeszcze raz." << endl;
	} while (!b_priopriety);

	cout <<endl<< "Wprowadziles prawidlowo pierwsza liczbe, brawo!." << endl ;
	cout << endl << "Wprowadz druga liczbe. " << endl;

	do{

		cin >> s_input;
		b_priopriety = pobj2->b_enter(s_input);
		if (!b_priopriety)
			cout << "Niestety, nie podales prawidlowo drugiej liczby, podaj jeszcze raz" << endl;	
	} while (!b_priopriety);

	cout << endl << "Wprowadziles prawidlowo druga liczbe, brawo!." << endl << endl;


	int i_len = pobj1->i_getLength() + pobj2->i_getLength();
	CHexNumb result(i_len); // inicjalizacja obiektu result z zadana dlugoscia tablicy
	

	cout << endl << "Wyswietlenie skladnikow: " << endl;
	pobj1->v_show();
	pobj2->v_show();

	

	
	cout << "\nWpisz:\n+ aby dodac te dwie cyfry" << endl << "- aby je odjac " << endl << "* aby je pomnozyc " << endl  << "/ aby je podzielic " << endl << endl;

	
	char c_menu = ' ';
	cin >> c_menu;

	switch (c_menu){
		case '+':
			cout << endl << "Wybrales operacje dodawania, Twoj wynik: " << endl;
			result = *pobj1 + *pobj2;
			result.v_show();
			result.showArray();
			break;
		case '-':
			cout << endl << "Wybrales operacje odejmowania, Twoj wynik: " << endl;
			result = *pobj1 - *pobj2;
			result.v_show();
			result.showArray();
			break;
		case '*':
			cout << endl << "Wybrales operacje mnozenia, Twoj wynik: " << endl;
			result = *pobj1 * *pobj2;
			result.v_show();  cout << endl;
			result.showArray();
			break;
		case '/':
			cout << endl << "Wybrales operacje dzielenia, Twoj wynik: " << endl;

			if (pobj2->i_getLength() == 1 && pobj2->pi_getArray()[0] == 0)
				cout << "Dzielisz przez 0";
			else{

				result = *pobj1 / *pobj2;
				result.v_show();
				result.showArray();
			}
			break;
		default:
			cout << "niepoprawna opcja koncze program";
		} // switch (c_menu)

	cout << endl << "Dziekuje za skorzystanie z programu." << endl;


	delete du;


	getchar();
	cin.ignore(); 
	
		return 0;
}
