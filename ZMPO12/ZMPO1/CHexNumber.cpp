#include "CHexNumber.h"


CHexNumb::CHexNumb(){

	
	this->i_length = DEFAULT_LEN;
	this->b_positive = true;
	this->pi_array = new int[i_length];
	v_prv_fullfillZeros();
	//cout << "konstruktor domyslny oraz jego miejsce w pamieci: " << this << endl << endl;

} //CHexNumb::CHexNumb()

CHexNumb::CHexNumb(int iLength){

	
	this->i_length = iLength;
	this->b_positive = true;
	this->pi_array = new int[iLength];
	v_prv_fullfillZeros();
	//cout << "konstruktor z podana dlugoscia: " << to_string(iLength) << " oraz jego miejsce w pamieci: " << this << endl << endl;
	
} //CHexNumb::CHexNumb(int iLength)

CHexNumb::CHexNumb( CHexNumb &pattern){  // konstruktor kopiujacy
	
	
	this->i_length = pattern.i_length;
	this->b_positive = pattern.b_positive;

	this->pi_array = new int[pattern.i_length];
	if (pattern.pi_array)
	for (int i = 0; i < this->i_length; i++)
		this->pi_array[i] = pattern.pi_array[i];

	//cout << "konstruktor kopiujacy, to moje this " << this  << "  oraz this  mojego wzorca" << &pattern << endl << endl;
	//memcpy(this->pi_array, pattern.pi_array, pattern.i_length); // przekopiuj blok pamieci z obiektu pattern (jego pola pi_array (wskaznika)) o dlugosci i_length 
																// do this pi_array (wskaznika)
} //CHexNumb::CHexNumb(const CHexNumb &pattern)

CHexNumb::~CHexNumb(){
	
	//cout << "destruktor obiektu o this: " << this << endl  << endl;
	if (pi_array) delete pi_array; 

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

	b_positive = true;
	if (pi_array) delete pi_array;

} //void CHexNumb::v_prv_clear()

//break ok
int CHexNumb::i_prv_ignoreZeros(string sInput){			//zwracam indeks od ktorego miejsca nie ma juz  0 (poczatkowych) w ciagu (w inpucie - stringu)

	int i = 0;
	bool b_zero = true;
	for (; i < sInput.size() && b_zero; i++){

		if ((int)sInput[i] != 48)
			b_zero = false;
	}//for (; i < sInput.size(); i++){

	

	return i-1;

} //int CHexNumb::i_prv_ignoreZeros(char* pc_Array)

bool CHexNumb::b_enter(string sInput){
																						/*  jezeli jest ujemna to Usuwam wybrany fragment tekstu
																						a dokladniej usuwam minus ze stringa, po to, aby bylo jedno i w forze */

	if ((int)sInput[0] == 45){															//jezeli minus jest na poczatku, liczba jest ujemna

		this->b_positive = false;
		sInput.erase(0, 1);
	}	//if ((int)sInput[0] == 45)
																						//warunek brzegowy na to, jesli input byl samym minusem,	
	if (sInput.size() == 0){ 															//juz go wymazalismy, wiec sInput bedzie pusta tablica

		this->b_positive = true;
		return false;
	} //if (sInput.size() == 0){ 
																		
	int i_index = i_prv_ignoreZeros(sInput);											//warunek brzegowy na to, czy same 0 pojawily sie na poczatku 00001 = 1
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




	if (!b_is_correct){													//clear potrzebny, poniewaz input moze byc nieprawidlowy,
																		// moglbyc  "minus"  na poczatku ->  clear ustawi znak na true,
		this->v_prv_clear();											// tak samo poprzednia tablica nam jest niepotrzebna, mozemy zwolnic miejsce w pamieci i zaalokowac nastepna
	} //if (!b_is_correct) 			 

	return b_is_correct;

} // bool CHexNumb::b_enter(string sInput)





void CHexNumb::v_prv_fullfillZeros(){							// wypelnij tablice zerami

	b_positive = true;
	for (int i = 0; i < i_length; i++)
		this->pi_array[i] = 0;

} //void CHexNumb::v_prv_fullfillZeros()       



int CHexNumb::i_prv_whichGreater(CHexNumb & cFst,CHexNumb & cSnd){			//pomocnicza funkcja, ktora liczba jest wieksza
	
	int i_greater = 0;

	if (cFst.i_length > cSnd.i_length)
		i_greater = 1;

	else if (cFst.i_length < cSnd.i_length)
		i_greater = -1;

	else{ // tej samej dlugosci tablice
		bool b_flag = false;
																			// return 1 -> oznacza ze fst jest wieksza
		for (int i = 0; i < cSnd.i_length && !b_flag; i++) {						// return -1 -> oznacza, ze fst jest mniejsza
																			// return 0 -> oznacza, ze sa rowne
			if (cFst.pi_array[i]>cSnd.pi_array[i]){
				b_flag = true;
				i_greater = 1;
			}//if (cFst.pi_array[i]>cSnd.pi_array[i])
					
			else if (cFst.pi_array[i] < cSnd.pi_array[i]){
				b_flag = true;
				i_greater = -1;
			}//else if (cFst.pi_array[i] < cSnd.pi_array[i])
				
		} // for (int i = 0; i < i_length && !flag; i++)

	} //  tej samej dlugosci tablice

	return i_greater;

} //int CHexNumb::i_prv_whichGreater(CHexNumb *pcFst, CHexNumb *pcSnd)     




// a=b+c a= result, b = this , c =csnd
void CHexNumb::v_prv_addAlgorithm(CHexNumb & cResult, CHexNumb  & cSnd){

	int i_greaterLength = max(this->i_length, cSnd.i_length);
	int i_lowerLength = min(this->i_length, cSnd.i_length);
	int i_transfer = 0;		// przeniesienie do nastepnego slupka
	int i_totality;			// calosc

	
	for (int i = i_greaterLength - 1; i >= 0; i--) {
		if (this->i_length >= cSnd.i_length){									//jezeli 1 tablica jest wieksza badz rowna od drugiej
			if (i_lowerLength){													// jezeli mniejsza tablica jest rozna od 0

				i_lowerLength--;												// zmiejszamy o 1, na samym poczatku aby lowerLength wskazywal na ostatni element mniejszej tablicy
				i_totality = this->pi_array[i] + cSnd.pi_array[i_lowerLength] + i_transfer;
				cResult.pi_array[i + 1] = i_totality % NUMBER_BASE;				//zakladam, ze w ostatnim kroku tez bedzie przeniesienie dlatego i+1
				i_transfer = i_totality / NUMBER_BASE;
			} // if (i_lowerLength)

			else {

				i_totality = this->pi_array[i] + i_transfer;
				cResult.pi_array[i + 1] = i_totality % NUMBER_BASE;				//zakladam, ze w ostatnim kroku tez bedzie przeniesienie dlatego i+1
				i_transfer = i_totality / NUMBER_BASE;
			} //else  if (i_lowerLength)

		}  // if (pcFst->i_length >= pcSnd->i_length)

		else {																	//w przeciwnym wypadku, gdy pierwsza jest mniejsza od drugiej

			if (i_lowerLength) {												// jezeli mniejsza tablica jest rozna od 0

				i_lowerLength--;
				i_totality = this->pi_array[i_lowerLength] + cSnd.pi_array[i] + i_transfer;
				cResult.pi_array[i + 1] = i_totality % NUMBER_BASE;				//zakladam, ze w ostatnim kroku tez bedzie przeniesienie dlatego i+1
				i_transfer = i_totality / NUMBER_BASE;
			}  // if (i_lowerLength)

			else {

				i_totality = cSnd.pi_array[i] + i_transfer;
				cResult.pi_array[i + 1] = i_totality % NUMBER_BASE;				//zakladam, ze w ostatnim kroku tez bedzie przeniesienie dlatego i+1
				i_transfer = i_totality / NUMBER_BASE;
			}// else if (i_lowerLength)

		}// else  if (pcFst->i_length >= pcSnd->i_length)

	} //for (int i = i_greaterLength - 1; i >= 0; i--)

	if (i_transfer){															//jezeli zostalo przeniesienie, przypisz je poczatkowi tablicy

		cResult.pi_array[0] = i_transfer;
		cResult.i_length = i_greaterLength + 1;
	} //if (i_transfer)

	else{																		//jezeli nie zostalo, to usun 0 z poczatku

		/*
		for (int i = 0; i < i_greaterLength; i++)								//przesuwam tablice z cyframi znaczacymi o 1 w lewo (nie bedzie 0 na poczatku)
			cResult.pi_array[i] = cResult.pi_array[i + 1];
		
		cResult.pi_array[i_greaterLength] = 0;
		cResult.i_length = i_greaterLength;
		*/
		cResult.i_length = i_greaterLength + 1;
		cResult.i_prv_deleteZeroes();

															
	} // else if (i_transfer)

} //void CHexNumb::v_prv_addAlgorithm(CHexNumb *pcFst, CHexNumb *pcSnd)






//zmienilem algorytm nie ingerujac w tablice po operacji tzn, nie zmienilem dlugosci i nie usunalem 0 na poczatku

void CHexNumb::v_prv_substractionAlgorithm(CHexNumb &cGreater, CHexNumb &cLess, CHexNumb &cResult){

	int i_greaterLength = cGreater.i_length;
	int i_lowerLength = cLess.i_length;
	int i_totality = 0; // calosc
	int i_transfer = 0;

	for (int i = i_greaterLength - 1; i >= 0; i--) {
	
		if (i_lowerLength){																									// jezeli mniejsza tablica jest rozna od 0

			i_lowerLength--;																								// zmiejszamy o 1, na samym poczatku aby lowerLength wskazywal na ostatni element mniejszej tablicy
			if ((cGreater.pi_array[i] - i_transfer) < cLess.pi_array[i_lowerLength]){										// jezeli pierwsza cyfra jest mniejsza od drugiej

				i_totality = cGreater.pi_array[i] - cLess.pi_array[i_lowerLength] + NUMBER_BASE - i_transfer;				// pozyczylismy 16 dlatego w nastepnej odejmujemy 1
				cResult.pi_array[i] = i_totality;
				i_transfer = 1;																								// pozyczamy z nastepnego slupka, w nastepnej iteracji trzeba bedzie odjac 1
			} // if ((cGreater.pi_array[i] - i_transfer) < cLess.pi_array[i_lowerLength])

			else {

				i_totality = cGreater.pi_array[i] - cLess.pi_array[i_lowerLength] - i_transfer;
				cResult.pi_array[i] = i_totality;
				i_transfer = 0;																								//nic nie pozyczamy, dlatego w nastepnej iteracji nic nie odejmujemy transfer bedzie 0
			} //else  if ((cGreater.pi_array[i] - i_transfer) < cLess.pi_array[i_lowerLength])

		} // if (i_lowerLength)

		else {
																												//jezeli itransfer jakis byl to trza uporzadkowc
			if (i_transfer){

				if (cGreater.pi_array[i] - i_transfer < 0){

					cResult.pi_array[i] = cGreater.pi_array[i] - i_transfer + NUMBER_BASE;
				} //if (cGreater.pi_array[i] - i_transfer < 0)
					
				else{

					cResult.pi_array[i] = cGreater.pi_array[i] - i_transfer;
					i_transfer = 0;
				} //else if (cGreater.pi_array[i] - i_transfer < 0)

			}//	if (i_transfer)

			else{

				cResult.pi_array[i] = cGreater.pi_array[i];
			} //	if (i_transfer)

		} //else  if (i_lowerLength)

	} //for (int i = i_greaterLength - 1; i >= 0; i--)


	//cResult.i_length = i_greaterLength;
	//cResult.i_prv_deleteZeroes();


} //void CHexNumb::v_prv_substractionAlgorithm(CHexNumb &cGreater, CHexNumb &cLess, CHexNumb &cResult)



CHexNumb & CHexNumb::operator = (CHexNumb &cSnd){

	if (this != &cSnd) {								//jezeli nie wskazuja na ten sam obiekt , operator &Snd podaje adres obiektu, a this to wskaznik, czyli tez adres

		if (pi_array) delete pi_array;

		this->b_positive = cSnd.b_positive;
		this->i_length = cSnd.i_length;
		this->pi_array = new int[cSnd.i_length];
		if (cSnd.pi_array)								//jezeli cSnd ma zaalokowana w pamieci swoja dynamiczna tablice
		for (int i = 0; i < this->i_length; i++)
			this->pi_array[i] = cSnd.pi_array[i];
		else
			v_prv_fullfillZeros();
	} //if (this != &cSnd) 

	return *this;										//Operator wy³uskania * podaje  zmienn¹ wskazywan¹ przez pointer this

}//CHexNumb & CHexNumb::operator = (CHexNumb &cSnd)



// a -> result, b -> this , c -> cSnd // a=b+c
CHexNumb CHexNumb::operator +(CHexNumb & cSnd){

	CHexNumb result(this->i_length+cSnd.i_length);

	if ((this->b_positive && cSnd.b_positive) || (!this->b_positive && !cSnd.b_positive)){		// jezeli obie liczby sa tego samego znaku to dodaj je

		this->v_prv_addAlgorithm(result, cSnd);													// argument result zosta³ do niej przekazany bez jawnej konwersji na referencje – kompilator konwertowa³ go automatycznie.

		if (!this->b_positive)
			result.b_positive = false;
		else
			result.b_positive = true;
	}	//if ((this->b_positive && cSnd.b_positive) || (!this->b_positive && !cSnd.b_positive))

	else{
																								//  jezeli sa przeciwnego znaku	
		int i_greater = i_prv_whichGreater(*this,cSnd);

		if (i_greater == 1){

			v_prv_substractionAlgorithm(*this, cSnd, result);
			result.b_positive = this->b_positive;
			result.i_length = this->i_length;
			result.i_prv_deleteZeroes();
		} //if (i_greater == 1)	

		else if (i_greater == -1){

			v_prv_substractionAlgorithm(cSnd, *this, result);
			result.b_positive = cSnd.b_positive;
			result.i_length = this->i_length;
			result.i_prv_deleteZeroes();
		}//else if (i_greater == -1)

		else { // obie rowne

			result.i_length = 1;
			result.pi_array[0] = 0;
		}  // obie rowne

	}// else if ((this->b_positive && cSnd.b_positive) || (!this->b_positive && !cSnd.b_positive))

	return result;

} //CHexNumb CHexNumb::operator +(CHexNumb & cSnd)



// a -> result, b -> this , c -> cSnd // a=b+c
CHexNumb CHexNumb::operator -(CHexNumb & cSnd){

	CHexNumb result(this->i_length+cSnd.i_length);

	if ((!this->b_positive && cSnd.b_positive) || (this->b_positive && !cSnd.b_positive)){				// jezeli obie liczby sa przeciwnego znaku to dodaj je

		this->v_prv_addAlgorithm(result, cSnd);
		if (!this->b_positive)
			result.b_positive = false;																	//jezeli pierwsza byla na minusie, to znaczy ze wynik jest na minusie
		else
			result.b_positive = true;
	}	//  if ((!this->b_positive && cSnd.b_positive) || (this->b_positive && !cSnd.b_positive))

	else{																								// jezeli sa tego samego znaku

		int i_greater = i_prv_whichGreater(*this,cSnd);

		if (i_greater == 1){

			v_prv_substractionAlgorithm(*this, cSnd, result);
			result.b_positive = this->b_positive;
			result.i_length = this->i_length;
			result.i_prv_deleteZeroes();
		} //if (i_greater == 1)	

		
		else if (i_greater == -1){

			v_prv_substractionAlgorithm(cSnd, *this, result);
			result.b_positive = cSnd.b_positive;
			result.i_length = this->i_length;
			result.i_prv_deleteZeroes();
		}//else if (i_greater == -1)

		else { // obie liczby sa takiej samej wartosci	

			result.i_length = 1;
			result.pi_array[0] = 0;
		} // obie liczby sa takiej samej wartosci

	}// else if ((pcFst->b_positive && pcSnd->b_positive) || (!pcFst->b_positive && !pcSnd->b_positive))


	return result;

} // operator - 




CHexNumb CHexNumb::operator *(CHexNumb & cSnd){

	CHexNumb result(this->i_length+cSnd.i_length);
	int i_transfer = 0;

	for (int i = this->i_length - 1; i >= 0; i--){

		for (int j = cSnd.i_length - 1; j >= 0; j--){

			result.pi_array[i + j + 1] += this->pi_array[i] * cSnd.pi_array[j];
			i_transfer = result.pi_array[i + j + 1] / NUMBER_BASE;
			result.pi_array[i + j + 1] %= NUMBER_BASE;
			result.pi_array[i + j] += i_transfer;

		}//for (int i = this->i_length - 1; i >= 0; i--)

	} //for (int j = cSnd.i_length - 1; j >= 0; j--)

	this->b_positive == cSnd.b_positive ? result.b_positive = true : result.b_positive = false;

	result.i_prv_deleteZeroes();

	return result;

} //CHexNumb CHexNumb::operator *(CHexNumb & cSnd)






 // znaki + -
//refaktoryzacja jakas

CHexNumb CHexNumb::operator /(CHexNumb & cSnd){

	CHexNumb result(this->i_length);

	this->b_positive == cSnd.b_positive ? result.b_positive = true : result.b_positive = false;



	// cholero nie dziel przez 0
	int i_comp = i_prv_whichGreater(*this, cSnd);

	if (i_comp == -1 || i_comp == 0){

		result.v_prv_clear();				// dealokuje wczesniej tablice resulta z dluzszym length i alokuje mu nowa z len = 1
		result.i_length = 1;
		result.pi_array = new int[this->i_length];
		if (i_comp == -1)
			result.pi_array[0] = 0;			//jezeli pierwsza jest mniejsza od drugiej to wynik bedzie 0
		else
			result.pi_array[0] = 1;			// jezeli byly rowne to wynik bedzie 1 

		return result;
	} //if (i_comp == -1 || i_comp==0){ 

	CHexNumb Pomoc = *this;

	for (int i = 0; i < this->i_length; i++){

		int i_wynik = 0;
		CHexNumb temp= make_to_index(i, Pomoc);						// stworz temp z tablicy obj Pomoc do indexu od 0 do indexu i 
		int i_howManyZeroes = temp.i_prv_deleteZeroes();			// deletuj zera w tempie na poczatku i miej wskaznik ile 0 usunalem												
				
		while (i_prv_whichGreater(temp, cSnd) != -1){ //dopoki temp nie jest mniejszy od cSnd

			v_prv_substractionAlgorithm(temp, cSnd, temp);			//odejmuj csnd od temp		
			i_howManyZeroes += temp.i_prv_deleteZeroes();			//w trakcie odejmowan jak jest 0 na poczatku to usun je(zmniejsz tablice na wlasciwy rozmiar, i dodaj do wskaznika ile 0 usunietych)
			i_wynik++;
		} //while (i_comp != -1)					
																	//teraz zastepujemy w Pomoc tablice zerami (ile bylo ich we wskazniku how many)
		for (int k = 0; k < i_howManyZeroes; k++)
			Pomoc.pi_array[k] = 0;
																	//jezeli zostala reszta w tempie to podmieniamy na odpowiednich indeksach w Pomoc
		int j = 0;													// jezeli nie bylo to jeszcze jedno 0 na odpowiedni indeks w Pomoc
		for (int z = i_howManyZeroes; z < i_howManyZeroes + temp.i_length; z++)
			Pomoc.pi_array[z] = temp.pi_array[j++];
																	// reszta indeksow bez zmian
		result.pi_array[i] = i_wynik;
	} //for (int i = 0; i < this->i_length; i++){

	result.i_prv_deleteZeroes();
	return result;
}//CHexNumb CHexNumb::operator /(CHexNumb & cSnd){



	CHexNumb CHexNumb::make_to_index(int index, CHexNumb & liczba){

		CHexNumb result(index + 1);  //result z dlugoscia tablicy index+1
		for (int i = 0; i <= index; i++)
			result.pi_array[i] = liczba.pi_array[i];
	
		return result;
	} //CHexNumb CHexNumb::make_to_index(int index, CHexNumb & liczba){





/*
CHexNumb CHexNumb::operator /(CHexNumb & cSnd){

	CHexNumb result(this->i_length + cSnd.i_length);


	// cholero nie dziel przez 0

	int i_comp = i_prv_whichGreater(*this, cSnd);

	if (i_comp == -1 || i_comp == 0){

		result.v_prv_clear();				// dealokuje wczesniej tablice resulta z dluzszym length i alokuje mu nowa z len = 1
		result.i_length = 1;
		result.pi_array = new int[this->i_length];

		if (i_comp == -1)
			result.pi_array[0] = 0;			//jezeli pierwsza jest mniejsza od drugiej to wynik bedzie 0
		else
			result.pi_array[0] = 1;			// jezeli byly rowne to wynik bedzie 1 

		return result;
	} //if (i_comp == -1 || i_comp==0){ 

	CHexNumb helper(*this);			// kopia this

	while (i_prv_whichGreater(helper, cSnd) != -1){


		v_prv_substractionAlgorithm(helper, cSnd, helper);
		helper.i_length = this->i_length;
		helper.i_prv_deleteZeroes();

		result.pi_array[result.i_length - 1]++;

		bool shifted = true;
		int i_transfer = 0;
		for (int i = result.i_length - 1; i > 0 && shifted; i--){

			i_transfer = result.pi_array[i] / NUMBER_BASE;

			if (i_transfer){
				//	result.showArray(); cout << " tabcica result" << endl;

			}

			result.pi_array[i] %= NUMBER_BASE;
			result.pi_array[i - 1] += i_transfer;


			if (i_transfer == 0)
				shifted = false;

		} //for (int i = result.i_length - 1; i > 0 && shifted; i--)

	}//while (i_prv_whichGreater(helper, cSnd) != -1){

	result.v_prv_deleteZeroes();
	return result;

}
*/









int CHexNumb::i_prv_deleteZeroes(){

	int i_len = i_length;
	int i_shift = 0;

	bool b_isShifted = true;

	for (int i = 0; i < i_length && b_isShifted; i++){

		if (pi_array[i] == 0){

			i_len--;
			i_shift++;
		} //if (cNumber.pi_array[i] == 0)

		else
			b_isShifted = false;
	} //for (int i = 0; i < cNumber.i_length && isShifted; i++)

	// jezeli shift !=0 to bylo przesuniecie

	if (i_shift!= 0){

		if (i_len == 0){ // jezeli cala tablice to 0 
			i_shift = i_length-1;  //to przesuniecie wynosi dl tablicy - 1 (1 jest ostatnim zerem)
			i_length = 1;  //liczba ta wynosi po prostu 0
		} //if (len == 0)

		else{
			int j = i_shift;
			for (int i = 0; i < i_len; i++)
				pi_array[i] = pi_array[j++];

			for (int i = i_len; i < i_length; i++)
				pi_array[i] = 0;

			i_length = i_len; //zmienia dlugosc tablicy na len 

		}// else if (len == 0)

	} //if (shift!= 0)

	return i_shift;

}






void CHexNumb::v_show(){

	if (!this->b_positive)

		cout << "-";

	for (int i =0; i < i_length; i++){

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









	void CHexNumb::showArray(){
		cout << "moje liczby w tablicy: ";
		if (!b_positive)
			cout << "- ";
		for (int i = 0; i < i_getLength(); i++){
			cout << pi_array[i] << " " ;
		}
	}