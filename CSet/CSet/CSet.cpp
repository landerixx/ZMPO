#include "CSet.h"



// przy tablicach dynamicznych nie operuje sie znakami wskaznikowymi * & 
//Klasa** tablica = new Klasa*[size]; //dynamiczna tablica wskaŸników, mo¿esz zast¹piæ przez statyczn¹ 'Klasa* tablica[size]'


//niesprawdzony is full przy adzie
// co jesli usuniemy wszystkei elementy, a nastepnie chcemy dodac cos
// jak usunac elementy ze zbiotu, clear?




template <class T>
CSet<T>::CSet(){

	 i_firstFreeIndex=0;
	 i_length = DEF_LENGTH;
	pt_array = new T[i_length];
	
}//CSet<T>::CSet()


template <class T>
CSet<T>::CSet(int i_Size){

	i_firstFreeIndex = 0;
	i_length = i_Size;
	pt_array = new T[i_length];
	
}//CSet<T>::CSet(int i_Size)


template <class T>
CSet<T>::CSet(CSet<T>& c_Pattern){

	cout << "Konstruktor kopijacy" << endl;
	v_prv_deleteData();
	
	
	v_prv_setFromPattern(c_Pattern);

}//CSet<T>::CSet(CSet<T> & c_Pattern)


template <class T>
CSet<T>::~CSet(){

	v_prv_deleteData();

}//CSet<T>::~CSet()


template <class T>
void CSet<T>::v_prv_deleteData(){

	if (pt_array ){

		delete[] pt_array;
		pt_array = NULL;
		i_firstFreeIndex = 0;
	}//if (pt_array != NULL)

}//void CSet<T>::v_deleteData()


template <class T>
void CSet<T>::v_clear(){

	
	i_firstFreeIndex = 0;

}//void CSet<T>::v_clear()





template <class T>
void CSet<T>::v_prv_setFromPattern(CSet<T> & c_Pattern){


	cout << "set from pattern" << endl;
	i_firstFreeIndex = c_Pattern.i_firstFreeindex;
	i_length = c_Pattern.i_length;
	pt_array = new T[i_length];
	if (c_Pattern.pt_array)
	for (int i = 0; i < this->i_length; i++)
		this->pt_array[i] =  c_Pattern.pt_array[i];

}


template <class T>
bool CSet<T>::b_isFull(){

	return i_firstFreeIndex == i_length;
}//bool CSet<T>::b_isFull()

template <class T>
bool CSet<T>::b_isEmpty(){
	
	return i_firstFreeIndex == 0;
}//bool CSet<T>::b_isEmpty()




template <class T>
bool CSet<T>::b_contains(T & T_elem){

	bool b_exist = false;
	for (int i = 0; i < i_firstFreeIndex && !b_exist; i++)
		if (pt_array[i] == T_elem)
			b_exist = true;

	return b_exist;
}//bool CSet<T>::b_contains(T T_elem)






template <class T>
bool CSet<T>::b_add(T & t_Elem){

	bool b_success = !b_contains( t_Elem);

	if (b_success){

		if (b_isFull())
			v_prv_copyToNewArray();

		pt_array[i_firstFreeIndex++] = t_Elem;
	}//	if (b_success)
	
	return b_success;
}//bool CSet<T>::b_add(T & T_elem)





template <class T>
void  CSet<T>::v_prv_copyToNewArray(){

	T *pt_newArray = new T[2 * i_length];
	for (int i = 0; i < i_firstFreeIndex; i++)
		pt_newArray[i] = pt_array[i];

	delete[] pt_array;
	pt_array = pt_newArray;
	i_length *= 2;

	for (int i = i_firstFreeIndex; i < i_length; i++)
		pt_array[i] = NULL;
}//void  CSet<T>::v_prv_copyToNewArray()















template <class T>
CSet<T> &  CSet<T>:: operator=(CSet<T> & c_Snd){

	cout << "operator " << endl;
	if (this != &c_Snd){

		v_prv_deleteData();
		v_prv_setFromPattern(c_Snd);

	}//if (this != &cSnd)

	return *this;

}//CSet<T> &  CSet<T>:: operator=(CSet<T> & cSnd)


template <class T>
CSet<T>   CSet<T>:: operator+(CSet<T> & c_Snd){

}



template <class T>
CSet<T>   CSet<T>:: operator+(T & t_Elem){

	CSet<T> result = *this;
	result.b_add(t_Elem);
	return result;
}









template <class T>
void CSet<T>::v_show(){
	cout << "Wyswietlam zbior: " << endl;
	for (int i = 0; i < i_firstFreeIndex; i++)
		cout << pt_array[i] << ", ";
	cout << "       " << "Rozmiar tablicy: " << i_length << endl;
}



