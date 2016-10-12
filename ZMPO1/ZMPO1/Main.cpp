
#include "CHexNumber.h"




int main(){

	
	
	string s_input;
	bool b_priopriety;

	
	CHexNumb *pobj1 = new CHexNumb;
	CHexNumb *pobj2 = new CHexNumb;

	cout << "Witam w kalkulatorze liczb szesnastkowych. \nWprowadz pierwsza liczbe:" << endl;

	do{
		 
		cin >> s_input;
		b_priopriety = pobj1->b_enter(s_input);

		if (!b_priopriety)
			cout << "Niestety, nie podales prawidlowo pierwszej liczby, podaj jeszcze raz." << endl;
	
	} while (!b_priopriety);

	//pobj1->showArray();
	
	cout <<endl<< "Wprowadziles prawidlowo pierwsza liczbe, brawo!." << endl ;
	cout << endl << "Wprowadz druga liczbe. " << endl;


	do{

		cin >> s_input;
		b_priopriety = pobj2->b_enter(s_input);

		if (!b_priopriety)
			cout << "Niestety, nie podales prawidlowo drugiej liczby, podaj jeszcze raz" << endl;
		
	} while (!b_priopriety);

	//pobj2->showArray();
	cout << endl << "Wprowadziles prawidlowo druga liczbe, brawo!." << endl << endl;



	int i_len = pobj1->i_getLength() + pobj2->i_getLength();
	CHexNumb result(i_len); // inicjalizacja obiektu result z zadana dlugoscia tablicy

	
	

	char c_menu=' ';
	
	while (c_menu !='q' && c_menu != 'Q'){
		cout << "\nWpisz:\n+ aby dodac te dwie cyfry" << endl << "- aby je odjac "<< endl << "* aby je pomnozyc " << endl
			<< "w aby je wyswietlic  " << endl << "q aby zakonczyc" << endl <<endl ;

		cin >> c_menu;

		switch (c_menu){
		case '+':

			cout << endl << " Wybrales operacje dodawania, Twoj wynik: ";
			result.v_add(pobj1, pobj2);
			result.v_show();

			break;
		case '-':

			cout << endl << " Wybrales operacje odejmowania, Twoj wynik: ";
			result.v_substract(pobj1, pobj2);
			result.v_show();
			result.showArray();

			break;
		case '*':

			cout << endl << " Wybrales operacje mnozenia, Twoj wynik: ";
			result.v_multiply(pobj1, pobj2);
			result.v_show();

			break;

		case 'w': case'W':

			cout << endl << " Wybrales operacje wyswietlenia skladnikow: " << endl;
			pobj1->v_show();
			pobj2->v_show();

			break;

		} // switch (c_menu)

		cout << endl << endl;

	} //while (c_menu != 'q' && 'Q')



	delete pobj1;
	delete pobj2;

	
	
	getchar();
	cin.ignore(); 
	
		return 0;
}
