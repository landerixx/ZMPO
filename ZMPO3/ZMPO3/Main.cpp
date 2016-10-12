#include "CPackingTree.h"



int main(){

	
	CPackingTree drzewo;

	cout << "Witaj w programie, tworzace drzewo pakowania" << endl;

	int i_helper = -ONE;
	int i_result = -ONE;
	string s_input = "";

	while (i_helper!= ZERO){

		cout << "Wybierz opcje stworzenia drzewa:" << endl;
		cout << "1:  Za pomoca Stringa" << endl;
		cout << "2:  Za pomoca korzenia " << endl;
		cout << "0:  Zakoncz program" << endl;
		cin >> i_helper;
		
		while (i_helper != ZERO && i_helper != ONE && i_helper != TWO){
				
				cout << "Wprowadziles niepoprawna dana, podaj 0, 1 lub 2." << endl;
				cin.clear();
				cin.sync();
				cin >> i_helper;
			}//	while (i_create != 1 && i_create != 2)
			
			if (i_helper != ZERO){

				string s_nazwa;
				float f_mnoznik = -ONE; 

				switch (i_helper){

				case ONE:

					cout << "Wybrales opcje nr 1" << endl;
				
				
					do {
						cout << "Wpisz string " << endl << endl;
						cin.clear();
						cin.sync();
						getline(std::cin, s_input);
						i_result = drzewo.i_enterString(s_input);
					} while (i_result != ZERO);
						
				cin.clear();
				cin.sync();

				break;
				case 2:
					cout << "Wybrales opcje nr 2." << endl;
					cout << "Podaj nazwe korzenia oraz jego mnoznik." << endl;

					cin >> s_nazwa;
					cin.clear();
					cin.sync();

					while (f_mnoznik <= 0){
						cin >> f_mnoznik;
						cin.clear();
						cin.sync();
						if (f_mnoznik <= ZERO)
							cout << "Wprowadziles niepoprawna dana, mnoznik musi byc dodatni. Wprowadz go jeszcze raz" << endl;
					} //while (f_mnoznik <= 0)

					drzewo.v_createRoot(s_nazwa, f_mnoznik);
				break;
			}//switch (i_create)

			 i_helper = -ONE;
			 while (i_helper != 0 && i_helper != 9){
				
				s_nazwa = "";
				f_mnoznik = -ONE;

				cin.clear();
				cin.sync();

				cout << endl;
				cout << "Co chcesz teraz zrobic?" << endl;
				cout << "0: wyjsc z programu" << endl;
				cout << "9: usun drzewo" << endl;
				cout << "1: wyswietl unikatowa liste elementow" << endl;
				cout << "2: Dodaj element do drzewa" << endl << endl;
				cout << "Gdy podasz zla wartosc, zapytam cie jeszcze raz" << endl << endl;

				cin >> i_helper;
				if (cin.good()){
					switch (i_helper){

					case NINE:
						drzewo.v_deleteTree();
						break;
					case ZERO: 
						break;

					case ONE:
						drzewo.v_showUniqueList();
						cout << endl << endl;
						break;

					case TWO:
						if (drzewo.b_isEmpty()){
							cout << "Twoje drzewo jest puste" << endl;
							cout << "Podaj nazwe korzenia oraz jego mnoznik" << endl;

							cin >> s_nazwa;
							cin.clear();
							cin.sync();

							while (f_mnoznik <= 0){
								cin >> f_mnoznik;
								cin.clear();
								cin.sync();
								if (f_mnoznik <= 0)
									cout << "Wprowadziles niepoprawna dana, mnoznik musi byc dodatni. Wprowadz go jeszcze raz" << endl;
							} //while (f_mnoznik <= 0)
							drzewo.v_createRoot(s_nazwa, f_mnoznik);
						}//if (drzewo.b_isEmpty())

						else{
							cout << "Wybrales dodanie elementu. " << endl << "Do ktorego node'a chcesz doczepic swoj element?" << endl;
							cout << "Jesli sie rozmysliles, wcisnij -1" << endl << endl;
							vector <CNode*> wektor = drzewo.vr_goDepth();
							int i_number = -TWO;

							while (i_number < -ONE || i_number >= (int)wektor.size()){

								cin >> i_number;
								cin.clear();
								cin.sync();
								if (i_number < -ONE || i_number >= (int)wektor.size())
									cout << "Niepoprawny numer, podaj jeszcze raz" << endl;
							} //while (i_number < 0 && i_number >> (int)wektor.size())

							if (i_number != -1){
								cout << endl << "Podaj nazwe produktu oraz jego mnoznik" << endl;
								cin >> s_nazwa;
								while (f_mnoznik <= ONE){
									cin >> f_mnoznik;
									cin.clear();
									cin.sync();
									if (f_mnoznik <= ONE)
										cout << "Wprowadziles niepoprawna dana, mnoznik musi byc dodatni. Wprowadz go jeszcze raz" << endl;
								}//while (f_mnoznik <= 0)

								drzewo.v_insert(s_nazwa, f_mnoznik, *wektor[i_number]);
						} //(i_number != -1)
					}//else if (drzewo.b_isEmpty())
						break;

					}//switch (i_helper)
				}//if (cin good())
			} //while (i_helper != 0 && i_helper !=9)


		}//if (i_helper !=0)
	}//	while (i_helper != 0')



	cout << "Dziekuje za skorzystanie z programu." << endl;
	getchar();
	cin.ignore();
	return 0;
}