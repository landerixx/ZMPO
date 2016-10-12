#include "CHexNumber.h"


CHexNumb::CHexNumb(){

	cout << " konstruktor domyslny" << endl;
	this->i_length = DEFAULT_LEN;
	this->b_positive = true;
	this->pi_array = new int[i_length];
	v_prv_fullfillZeros();


} //CHexNumb::CHexNumb()

CHexNumb::CHexNumb(int iLength){
	this->i_length = iLength;
	this->b_positive = true;
	this->pi_array = new int[iLength];
	v_prv_fullfillZeros();

	cout << " konstruktor z podanym length" << endl;
} //CHexNumb::CHexNumb(int iLength)



CHexNumb::CHexNumb( CHexNumb &pattern){  // konstruktor kopiujacy

	cout << " konstruktor kopiujacy" << endl;
	this->i_length = pattern.i_length;
	this->b_positive = pattern.b_positive;

	this->pi_array = new int[pattern.i_length];

	if (pattern.pi_array)

	for (int i = 0; i < this->i_length; i++)
		this->pi_array[i] = pattern.pi_array[i];

	//memcpy(this->pi_array, pattern.pi_array, pattern.i_length); // przekopiuj blok pamieci z obiektu pattern (jego pola pi_array (wskaznika)) o dlugosci i_length 
																// do this pi_array (wskaznika)
} //CHexNumb::CHexNumb(const CHexNumb &pattern)


CHexNumb::~CHexNumb(){
	

	cout << " destruktor" << i_length << endl;

	if (pi_array) delete pi_array; 
		pi_array = NULL;

}//CHexNumb::~CHexNumb()

int CHexNumb::i_getLength(){

	return i_length;

}//int CHexNumb::i_getLength(){

void CHexNumb::v_setLength(int iLength){

	i_length = iLength;

}//void CHexNumb::v_setLength(int iLength){

int* CHexNumb::pi_getArray(){

	return pi_array ;

} //int* CHexNumb::pi_getArray(){

void CHexNumb::v_setArray(int* piArray){

	pi_array = piArray;

}//void CHexNumb::v_setArray(int* piArray)

bool CHexNumb::b_getPositive(){

	return b_positive;

}//bool CHexNumb::b_getPositive(){

void CHexNumb::v_setPositive(bool bPositive){

	b_positive = bPositive;

}//void CHexNumb::v_setPositive(bool bPositive){





void CHexNumb::v_prv_clear(){

	//cout << " uzywam cleara " << endl;
	b_positive = true;
	
	
	if (pi_array) delete pi_array;
		


} //void CHexNumb::v_prv_clear(){



int CHexNumb::i_prv_ignoreZeros(string sInput){			//zwracam indeks od ktorego miejsca nie ma juz  0 (poczatkowych) w ciagu (w inpucie - stringu)
	
	int i = 0;
	for (; i < sInput.size(); i++){

		if ((int)sInput[i] != 48)
			break ;
	}//for (; i < sInput.size(); i++){

	return i;

} //int CHexNumb::i_prv_ignoreZeros(char* pc_Array)



void CHexNumb::v_prv_fullfillZeros(){					// wypelnij tablice zerami
	b_positive = true;
	for (int i = 0; i < i_length; i++)
		this->pi_array[i] = 0;
} //void CHexNumb::v_prv_fullfillZeros()       




int CHexNumb::i_prv_whichGreater(CHexNumb *pcFst, CHexNumb *pcSnd){ //pomocnicza funkcja, wiem, ze tablice tej samej wielkosci, ktora liczba jest wieksza
																	// return 1 -> oznacza, ze fst jest wieksza
	for (int i = 0; i < pcFst->i_length ; i++) {					// return -1 -> oznacza, ze fst jest mniejsza
																	// return 0 -> oznacza, ze sa rowne
		if (pcFst->pi_array[i]>pcSnd->pi_array[i])
			return 1;
		else if (pcFst->pi_array[i] < pcSnd->pi_array[i])
			return -1;
	}
	return 0;
} //int CHexNumb::i_prv_whichGreater(CHexNumb *pcFst, CHexNumb *pcSnd)






bool CHexNumb::b_enter(string sInput){
																						/*  jezeli jest ujemna to Usuwam wybrany fragment tekstu
																						a dokladniej usuwam minus ze stringa, po to, aby bylo jedno i w forze */

	if ((int)sInput[0] == 45){															//jezeli minus jest na poczatku, liczba jest ujemna

		this->b_positive = false;
		sInput.erase(0, 1);

	}	//if ((int)sInput[0] == 45)


	//warunek brzegowy na to, jesli input byl samym minusem, juz go wymazalismy, wiec sInput bedzie pusta tablica

	if (sInput.size() == 0){

		this->b_positive = true;
		return false;
	
	}


	//warunek brzegowy na to, czy same 0 pojawily sie na poczatku 00001 = 1

	int i_index = i_prv_ignoreZeros(sInput);
	if (i_index != 0) 

		sInput.erase(0, i_index);														//usuwamy poczatkowe 0 z ciagu


	if (sInput.size() == 0)	{															//jezeli aktualny rozmiar to 0, tzn ze usunelismy caly input, a on byl z samych 0
		this->b_positive = true;
		this->i_length = 1;
		this->pi_array = new int[this->i_length];
		this->pi_array[0] = 0;

		return true;
	}//if (sInput.size() == 0)


	this->i_length = sInput.size();
	this->pi_array = new int[this->i_length];
	

	bool b_is_correct = true;


	for (int i = 0; i < i_length && b_is_correct; i++) {

		if ((int)sInput[i] >= 97 && (int)sInput[i] <= (102))			// male litery a->f

			pi_array[i] = (int)sInput[i] - 87;							// a=10, b=11, ... , f=15	

		else	if ((int)sInput[i] >= 65 && (int)sInput[i] <= 70)		// duze litery A->F

			pi_array[i] = (int)sInput[i] - 55;							// A=10, B=11, ..., F=15

		else	if ((int)sInput[i] >= 48 && (int)sInput[i] <= 57)		// cyfry od 0 do 9

			pi_array[i] = (int)sInput[i] - 48;							// zeby w tablicy byly 0, 1, 2, ..., 9

		else

			b_is_correct = false;										//jezeli zaden z powyzszych -> niepoprawny char, wychodzimy z fora


	}//for (int i = 0; i < idlugosc && b_is_correct; i++)




	if (!b_is_correct){

		this->v_prv_clear();																/*clear potrzebny, poniewaz input moze byc nieprawidlowy, ale - "minus" byl na poczatku -> zmieni sie znak na ujemny,
																					tak samo poprzednia tablica nam jest niepotrzebna, mozemy zwolnic miejsce w pamieci i zaalokowac nastepna */
		//cout << "byl niepoprawny input, deletuje zaalokowana tablice " << endl;

	} //if (!b_is_correct)


	return b_is_correct;

} // bool CHexNumb::b_assign(string sInput)




void CHexNumb::v_show(){

	if (!this->b_positive)

		cout << "-";


	int i = 0;
												 //przesun i, zeby nie wyswietlalo 0 na poczatku
		for (; i < i_length; i++)
		if (pi_array[i])
			break;

		if (i == i_length )
			cout << 0;
			
	for (; i < i_length; i++){

		if (pi_array[i] <= 9 && pi_array[i] >= 0)

			cout << pi_array[i];

		else

			switch (pi_array[i]){

				case 10:
					cout << 'A';
					break;

				case 11: 	
					cout << 'B';
					break;

				case 12: 
					cout << 'C';
					break;

				case 13:
					cout << 'D';
					break;

				case 14:
					cout << 'E';
					break;

				case 15:
					cout << 'F';
					break;

		} //switch (pi_array[i])

	} //for (int i = 0; i < i_length; i++)
	
	cout << endl;

} //void CHexNumb::v_show()



//odejmujemy druga od pierwszej: a-b
void CHexNumb::v_substract(CHexNumb *pcFst, CHexNumb  *pcSnd){
	
	this->v_prv_fullfillZeros();
	

	if ((!pcFst->b_positive && pcSnd->b_positive) || (pcFst->b_positive && !pcSnd->b_positive)){		// jezeli obie liczby sa przeciwnego znaku to dodaj je

		this->v_prv_addAlgorithm(pcFst, pcSnd);

		if (!pcFst->b_positive)
			this->b_positive = false;																	//jezeli pierwsza byla na minusie, to znaczy ze wynik jest na minusie

	}	// ((pcFst->b_positive && pcSnd->b_positive) || (!pcFst->b_positive && !pcSnd->b_positive))

	else{																								// jezeli sa tego samego znaku

		if (pcFst->i_length > pcSnd->i_length){
		//	cout << " pierwsza jest wieksza " << endl;
			if (pcFst->b_positive)
				this->b_positive = true;
			else
				this->b_positive = false;

			v_prv_substractionAlgorithm(pcFst, pcSnd);
				
		} // if (pcFst->i_length > pcSnd->i_length)

		else if (pcSnd->i_length > pcFst->i_length){

			//cout << " druga jest wieksza " << endl;

			if (pcSnd->b_positive)
				this->b_positive = false;
			else
				this->b_positive = true;

			v_prv_substractionAlgorithm(pcSnd, pcFst);

		} //else if (pcSnd->i_length > pcFst->i_length){

		
		else{  // takie same rozmiary tablicy

		//	cout << "takie same rozmiary tablicy" << endl;

			int i_greater = i_prv_whichGreater(pcFst, pcSnd);

			if (i_greater == 1){

		//		cout << "pierwsza wieksza" << endl;

				v_prv_substractionAlgorithm(pcFst, pcSnd);
				this->b_positive = pcFst->b_positive;
				this->i_length = pcFst->i_length;


			} //if (i_greater == 1)	

			else if (i_greater == -1){


		//		cout << "druga wieksza" << endl;

				v_prv_substractionAlgorithm(pcSnd, pcFst);
				this->b_positive = pcSnd->b_positive;
				this->i_length = pcFst->i_length;

			}//else if (i_greater == -1)

			else { // obie liczby sa takiej samej wartosci

			//	cout << " taka sama wartosc " << endl;

				this->i_length = 1;
				this->pi_array[0] = 0;

			} // obie liczby sa takiej samej wartosci

		}	 // takie same rozmiary tablicy

	}// else if ((pcFst->b_positive && pcSnd->b_positive) || (!pcFst->b_positive && !pcSnd->b_positive))


} //void CHexNumb::v_substract(CHexNumb *pcFst, CHexNumb  *pcSnd)
	









void CHexNumb::v_add(CHexNumb *pcFst, CHexNumb *pcSnd){

	

	this->v_prv_fullfillZeros();

	if ((pcFst->b_positive && pcSnd->b_positive) || (!pcFst->b_positive && !pcSnd->b_positive)){		// jezeli obie liczby sa tego samego znaku to dodaj je

		this->v_prv_addAlgorithm(pcFst, pcSnd);

		if (!pcFst->b_positive)
			this->b_positive = false;

		

	}	// ((pcFst->b_positive && pcSnd->b_positive) || (!pcFst->b_positive && !pcSnd->b_positive))


	else{																								// jezeli sa przeciwnego znaku

		// sprawdzam jaki bedzie znak wyniku

		if (pcFst->i_length > pcSnd->i_length){
			
			if (pcFst->b_positive)
				this->b_positive = true;
			else
				this->b_positive = false;

			v_prv_substractionAlgorithm(pcFst, pcSnd);

		} // if (pcFst->i_length > pcSnd->i_length)

		else if (pcSnd->i_length > pcFst->i_length){


			if (pcSnd->b_positive)
				this->b_positive = true;
			else
				this->b_positive = false;

			v_prv_substractionAlgorithm(pcSnd, pcFst);

		} //else if (pcSnd->i_length > pcFst->i_length){




		else{  // takie same rozmiary tablicy
		
			int i_greater=i_prv_whichGreater(pcFst,pcSnd);

			if (i_greater == 1){

				v_prv_substractionAlgorithm(pcFst, pcSnd);
				this->b_positive = pcFst->b_positive;


			} //if (i_greater == 1)	

			else if (i_greater == -1){

				v_prv_substractionAlgorithm(pcSnd, pcFst);
				this->b_positive = pcSnd->b_positive;
				

			}//else if (i_greater == -1)

			else { // obie liczby sa takiej samej wartosci

				this->i_length = 1;
				this->pi_array[0] = 0;



			}  // obie liczby sa takiej samej wartosci

		}// takie same rozmiary tablicy
			

	}// else if ((pcFst->b_positive && pcSnd->b_positive) || (!pcFst->b_positive && !pcSnd->b_positive))
	

}//void CHexNumb::add(CHexNumb *pcFst,CHexNumb  *pcSnd)



void CHexNumb::v_prv_substractionAlgorithm(CHexNumb *pcGreater, CHexNumb *pcLess){


	int i_greaterLength = pcGreater->i_length;
	int i_lowerLength = pcLess->i_length;

	int i_totality=0; // calosc
	int i_transfer=0;

	for (int i = i_greaterLength - 1; i >= 0; i--) {

			if (i_lowerLength){																								// jezeli mniejsza tablica jest rozna od 0

				i_lowerLength--;																								// zmiejszamy o 1, na samym poczatku aby lowerLength wskazywal na ostatni element mniejszej tablicy


				if ((pcGreater->pi_array[i] - i_transfer) < pcLess->pi_array[i_lowerLength]){									// jezeli pierwsza liczba jest mniejsza od drugiej

					i_totality = pcGreater->pi_array[i] - pcLess->pi_array[i_lowerLength] + NUMBER_BASE - i_transfer;			//pozyczylismy 16 dlatego w nastepnej odejmujemy 1

					this->pi_array[i] = i_totality;

					i_transfer = 1;																								// pozyczamy z nastepnego slupka, w nastepnej iteracji trzeba bedzie odjac 1

				} //if ((pcGreater->pi_array[i] - i_transfer) < pcLess->pi_array[i_lowerLength])

				else{

					i_totality = pcGreater->pi_array[i] - pcLess->pi_array[i_lowerLength] - i_transfer;

					this->pi_array[i] = i_totality;

					i_transfer = 0;																								//nic nie pozyczamy, dlatego w nastepnej iteracji nic nie odejmujemy

				} //else if ((pcGreater->pi_array[i] - i_transfer) < pcLess->pi_array[i_lowerLength])

			} // if (i_lowerLength)

			else {

				i_totality = pcGreater->pi_array[i] - i_transfer;

				this->pi_array[i] = i_totality;

				i_transfer = 0;

			} //else  if (i_lowerLength)
			

	} //for (int i = i_greaterLength - 1; i >= 0; i--)


	//this->i_length = i_greaterLength;

} //void CHexNumb::v_prv_substractionAlgorithm(CHexNumb *pcGreater, CHexNumb *pcLess)





void CHexNumb::v_prv_addAlgorithm(CHexNumb *pcFst, CHexNumb *pcSnd){

	int i_greaterLength = max(pcFst->i_length, pcSnd->i_length);
	int i_lowerLength = min(pcFst->i_length, pcSnd->i_length);


	int i_transfer = 0; // przeniesienie do nastepnego slupka
	int i_totality; // calosc
	
	cout << "greater " << i_greaterLength << endl;

	for (int i = i_greaterLength - 1; i >= 0; i--) {

		if (pcFst->i_length >= pcSnd->i_length){							//jezeli 1 tablica jest wieksza badz rowna od drugiej

			if (i_lowerLength){												// jezeli mniejsza tablica jest rozna od 0

				i_lowerLength--;											// zmiejszamy o 1, na samym poczatku aby lowerLength wskazywal na ostatni element mniejszej tablicy

				i_totality = pcFst->pi_array[i] + pcSnd->pi_array[i_lowerLength] + i_transfer;

				this->pi_array[i + 1] = i_totality % NUMBER_BASE;			//zakladam, ze w ostatnim kroku tez bedzie przeniesienie dlatego i+1
				i_transfer = i_totality / NUMBER_BASE;

				

			} // if (i_lowerLength)

			else {

				i_totality = pcFst->pi_array[i] + i_transfer;

				this->pi_array[i + 1] = i_totality % NUMBER_BASE;			//zakladam, ze w ostatnim kroku tez bedzie przeniesienie dlatego i+1
				i_transfer = i_totality / NUMBER_BASE;

			} //else  if (i_lowerLength)

		}  // if (pcFst->i_length >= pcSnd->i_length)

		else {																//w przeciwnym wypadku, gdy pierwsza jest mniejsza od drugiej


			if (i_lowerLength) {											// jezeli mniejsza tablica jest rozna od 0

				i_lowerLength--;

				i_totality = pcFst->pi_array[i_lowerLength] + pcSnd->pi_array[i] + i_transfer;

				this->pi_array[i + 1] = i_totality % NUMBER_BASE;			//zakladam, ze w ostatnim kroku tez bedzie przeniesienie dlatego i+1
				i_transfer = i_totality / NUMBER_BASE;

			}  // if (i_lowerLength)

			else{

				i_totality = pcSnd->pi_array[i] + i_transfer;

				this->pi_array[i + 1] = i_totality % NUMBER_BASE;			//zakladam, ze w ostatnim kroku tez bedzie przeniesienie dlatego i+1
				i_transfer = i_totality / NUMBER_BASE;

			}// else if (i_lowerLength)

		}// else  if (pcFst->i_length >= pcSnd->i_length)

	//	this->showArray();
	} //for (int i = i_greaterLength - 1; i >= 0; i--)



	if (i_transfer){														//jezeli zostalo przeniesienie, przypisz je poczatkowi tablicy

		this->pi_array[0] = i_transfer;
		this->i_length = i_greaterLength + 1;

	} //if (i_transfer)

	else{																	//jezeli nie zostalo, to przesun wskaznik w prawo o 1		

		this->i_length = i_greaterLength +1;									
		//this->pi_array += 1;												//przesuwam wskaznik o 1 w prawo, nie bylo przeniesienia

	} // else if (i_transfer)

} //void CHexNumb::v_prv_addAlgorithm(CHexNumb *pcFst, CHexNumb *pcSnd)



void CHexNumb::v_multiply(CHexNumb *pcFst, CHexNumb *pcSnd){

	this->v_setLength(pcFst->i_length + pcSnd->i_length);
	v_prv_fullfillZeros();
	int i_transfer = 0;

	for (int i = pcFst->i_length-1; i >=0; i--){

		for (int j = pcSnd->i_length-1; j >=0; j--){

			this->pi_array[i + j +1] += pcFst->pi_array[i] * pcSnd->pi_array[j];
			 i_transfer = this->pi_array[i + j +1] / NUMBER_BASE;
			this->pi_array[i + j +1] %= NUMBER_BASE;
			this->pi_array[i + j  ] += i_transfer;

		}//for (int j = 0; j < pcSnd->i_length; j++)

	} //for (int i = 0; i < pcFst->i_length; i++)
	

	pcFst->b_positive == pcSnd->b_positive ? this->b_positive = true : this->b_positive = false;


	

} //void CHexNumb::v_multiply(CHexNumb *pcFst, CHexNumb *pcSnd)











	void CHexNumb::showArray(){
		cout << "moje liczby w tablicy: ";
		if (!b_positive)
			cout << "- ";
		for (int i = 0; i < i_getLength(); i++){
			cout << pi_array[i] << " " ;
		}
	}