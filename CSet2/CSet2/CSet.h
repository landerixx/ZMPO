#ifndef CSet_H
#define CSet_H

#define BASE_SIZE 10

#include <string>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <type_traits>

using namespace std;





template<typename T>
class CSet
{

private:
	T *pt_array;
	int i_length;
	int i_firstFreeIndex;

	void v_prv_deleteData(); // do destruktora
	void v_prv_copyOther(const CSet & c_Other); // do operatora przypisania i konstruktora kopiujacego 


	void v_prv_copyToNewArray();		 //  przy dodawaniu elementu, jak mamy pelna tablice, tworzymy nowa tablice 2x wieksza
	void v_prv_createNewArray(int i_Len); // wymusza zaalokwanie nowej tablicy o podanym len (oczywiscie dealokuje poprzednia)
	

	void  v_prv_intersection(CSet &c_Less,  CSet &c_Greater, CSet &c_Result);  // czesc wspolna priv algor
	
	void v_prv_removeFromIndex(int i_IndexOfElem); // usuwa element na danym indeksie (prv algor, wiem, ze index jest poprawny)

public:
	CSet();
	CSet(int i_Size);
	CSet(const CSet &c_Other); // kopiujacy
	~CSet();

	CSet &operator =(const CSet &c_Other); // op przypisania

	CSet operator + (T & t_Elem);
	CSet operator + (const CSet &c_Other);

	CSet operator += (T & t_Elem);
	CSet operator += (const CSet &c_Other);

	CSet operator - (T & t_Elem);
	CSet operator - (const CSet &c_Other);

	CSet operator * (const CSet &c_Other);

	CSet c_intersection(CSet &c_Other);





	void v_clear(); // ZADANIE
					// przesuwamy first free indeks na poczatek, dzieki temu mozemy nadpisac wszystkie indeksy z powrotem
					// tablica ma caly czas taki sam rozmiar, nie trzeba dealokowac i alokowac z powrotem 


	bool b_isFull();
	bool b_isEmpty(); //nie uzywam


	bool b_contains(T & t_Elem); // ZADANIE
	int  i_indexOf(T & t_Elem); // index, na ktorym miejscu w tablicy, jezeli nie ma to zwraca -1 

	
	bool b_add(T & t_Elem);
	void v_addArray(T* pt_AnArray, int i_Len); //ZADANIE.  W operatorze +(set) wykorzystuje ta metode. Argumentowi i_Len przypisuje set.i_firstFreeIndex.
	bool b_remove(T & t_Elem);
	void v_removeElements(T* pt_AnArray, int i_Len);

	
	void v_show();



	CSet<string> * isIntiger();

};



//default constructor

template<typename T>
CSet<T>::CSet() : pt_array(new T[BASE_SIZE]),
i_length(BASE_SIZE), i_firstFreeIndex(0)
{}


template<typename T>
CSet<T>::CSet(int i_Size) : pt_array(new T[i_Size]),
i_length(i_Size), i_firstFreeIndex(0)
{}


// copy constructor

template<typename T>
CSet<T>::CSet(const CSet &c_Other){
	cout << "Konstruktor kopiujacy" << endl;
	v_prv_copyOther(c_Other);
	
}//CSet<T>::CSet(const CSet &c_Other)


//destruktor

template<typename T>
CSet<T>::~CSet(){
	v_prv_deleteData();

}//CSet<T>::~CSet()





//operator przypisania
//Tu operator = zwraca referencje na lewy operand, dziêki czemu mo¿liwe s¹ wielokrotne przypisania 
template<typename T>
CSet<T> & CSet<T>::operator =(const CSet &c_Other){
	cout << "operator przypisania" << endl;

	if (this != &c_Other){

		v_prv_deleteData();
		v_prv_copyOther(c_Other);
	}//if (this != &other)
	return *this;

}//CSet<T> & CSet<T>::operator =(const CSet &other)



template <typename T>
CSet<T>   CSet<T>:: operator+(T & t_Elem){

	CSet<T> result = *this;
	result.b_add(t_Elem);
	return result;
}//CSet<T>   CSet<T>:: operator+(T & t_Elem)


template<typename T>
CSet<T>  CSet<T>::operator +(const CSet &c_Other){
	
	CSet<T> result = *this;
	result.v_addArray(c_Other.pt_array, c_Other.i_firstFreeIndex);
	return result;

}//CSet<T> & CSet<T>::operator +(const CSet &other)


template<typename T>
CSet<T>  CSet<T>::operator +=(const CSet &c_Other){

	v_addArray(c_Other.pt_array, c_Other.i_firstFreeIndex);
	return *this;

}//CSet<T> & CSet<T>::operator +=(const CSet &other)


template <typename T>
CSet<T>   CSet<T>:: operator+=(T & t_Elem){

	b_add(t_Elem);
	return *this;

}//CSet<T>   CSet<T>:: operator+=(T & t_Elem)




template<typename T> // ROZNICA SYMETRYCZNA {A,B,C} * {B,C,D} = {A,D}
CSet<T>  CSet<T>::operator *(const CSet &c_Other){

	CSet<T> result = *this;
	int i_indexOfElem = -1;

	for (int i = 0; i < c_Other.i_firstFreeIndex; i++){

		i_indexOfElem = result.i_indexOf(c_Other.pt_array[i]);
		if (i_indexOfElem != -1)						//czyli jezeli element z C_Other wystepuje w resulcie to go usuwamy z resulta
			result.v_prv_removeFromIndex(i_indexOfElem);
		else
			result.b_add(c_Other.pt_array[i]);			//jezeli nie wystepuje element z cOther w resulcie to go dodajemy do resulta
			
	}//for (int i = 0; i < c_Other.i_firstFreeIndex; i++)

	return result;

}//CSet<T> & CSet<T>::operator *(const CSet &other)




template <typename T>
CSet<T>   CSet<T>:: operator-(T & t_Elem){

	CSet<T> result = *this;
	result.b_remove(t_Elem);
	return result;

}//CSet<T>   CSet<T>:: operator-(T & t_Elem)




template<typename T>
CSet<T>  CSet<T>::operator -(const CSet &c_Other){

	CSet<T> result = *this;
	result.v_removeElements(c_Other.pt_array, c_Other.i_firstFreeIndex);
	return result;

}//CSet<T> & CSet<T>::operator =(const CSet &other)































template<typename T>
void CSet<T>::v_prv_deleteData(){
	if (pt_array){

		delete[] pt_array;
		pt_array = NULL;
		i_firstFreeIndex = 0;
		i_length = 0;
	}//if (pt_array != NULL)

}//void CSet<T>::v_prv_deleteData()



template<typename T>
void CSet<T>::v_prv_copyOther(const CSet &c_Other){

	i_firstFreeIndex = c_Other.i_firstFreeIndex;
	i_length = c_Other.i_length;
	pt_array = new T[i_length];
	for (int i = 0; i < i_firstFreeIndex; i++)
		pt_array[i] = c_Other.pt_array[i];

}//void CSet<T>::v_prv_copyOther(const CSet &c_Other)




template<typename T>
void CSet<T>::v_clear(){

	i_firstFreeIndex = 0;

}//void CSet<T>::v_clear()




template <typename T>
bool CSet<T>::b_isFull(){

	return i_firstFreeIndex == i_length;
}//bool CSet<T>::b_isFull()



template <typename T>
bool CSet<T>::b_isEmpty(){

	return i_firstFreeIndex == 0;
}//bool CSet<T>::b_isEmpty()


template <typename T>
bool CSet<T>::b_contains(T & t_Elem){

	bool b_exist = false;
	for (int i = 0; i < i_firstFreeIndex && !b_exist; i++)
	if (pt_array[i] == t_Elem)
		b_exist = true;

	return b_exist;
}//bool CSet<T>::b_contains(T T_elem)


template <typename T>
int CSet<T>::i_indexOf(T & t_Elem){

	int i_index = -1;
	for (int i = 0; i < i_firstFreeIndex && i_index==-1; i++)
	if (pt_array[i] == t_Elem)
		i_index = i;

	return i_index;
}//bool CSet<T>::b_contains(T T_elem)




template <typename T>
bool CSet<T>::b_add(T & t_Elem){

	bool b_success = !b_contains(t_Elem);

	if (b_success){

		if (b_isFull())
			v_prv_copyToNewArray();

		pt_array[i_firstFreeIndex++] = t_Elem;
	}//	if (b_success)

	return b_success;
}//bool CSet<T>::b_add(T & T_elem)



template <typename T>
void  CSet<T>::v_prv_copyToNewArray(){

	T *pt_newArray = new T[2 * i_length];
	for (int i = 0; i < i_firstFreeIndex; i++)
		pt_newArray[i] = pt_array[i];

	delete[] pt_array;
	pt_array = pt_newArray;
	i_length *= 2;


}//void  CSet<T>::v_prv_copyToNewArray()

template <typename T>//zadanie
void CSet<T>::v_addArray(T* pt_AnArray, int i_Len){

	for (int i = 0; i < i_Len; i++)
		b_add(pt_AnArray[i]);

}//void CSet<T>::v_addArray(T* pt_AnArray, int i_Len)








template <typename T>
bool CSet<T>::b_remove(T & t_Elem){

	int i_indexOfElem = i_indexOf(t_Elem);
	bool b_success = false;

	if (i_indexOfElem!=-1){

		b_success = true;
		v_prv_removeFromIndex(i_indexOfElem);
	}//	if (b_success)

	return b_success;

}//bool CSet<T>::b_remove(T & t_Elem)

template <typename T>
void CSet<T>::v_prv_removeFromIndex(int i_IndexOfElem){

	for (; i_IndexOfElem < (this->i_firstFreeIndex - 1); i_IndexOfElem++)
		this->pt_array[i_IndexOfElem] = this->pt_array[i_IndexOfElem + 1];

	this->i_firstFreeIndex--;
}//void CSet<T>::v_prv_removeFromIndex(int i_IndexOfElem)




template <typename T>//zadanie 
void CSet<T>::v_removeElements(T* pt_AnArray, int i_Len){

	for (int i = 0; i < i_Len; i++)
		b_remove(pt_AnArray[i]);

}//void CSet<T>::v_addArray(T* pt_AnArray, int i_Len)




























template<typename T> // czy elementy z mniejszego zbioru zawieraja sie w wiekszym
CSet<T>  CSet<T>::c_intersection(CSet &c_Other){

	CSet<T> result;

	if (this->i_firstFreeIndex < c_Other.i_firstFreeIndex){ //jezeli this jest mniejszy

		result.v_prv_createNewArray(this->i_length);
		v_prv_intersection(*this, c_Other, result);
	}//	if (this->i_firstFreeIndex < c_Other.i_firstFreeIndex)

	else{                                                  // other jest mniejszy

		result.v_prv_createNewArray(c_Other.i_length);
		v_prv_intersection(c_Other, *this, result);
	}//else	if (this->i_firstFreeIndex < c_Other.i_firstFreeIndex)

	return result;

}//CSet<T>  CSet<T>::c_intersection (CSet &c_Other)



template<typename T>
void  CSet<T>::v_prv_intersection(CSet &c_Less, CSet &c_Greater, CSet &c_Result){


	for (int i = 0; i < c_Less.i_firstFreeIndex; i++)

	if (c_Greater.b_contains(c_Less.pt_array[i])){

		c_Result.pt_array[c_Result.i_firstFreeIndex++] = c_Less.pt_array[i];
	}//if (c_Greater.b_contains(c_Less.pt_array[i]))

}//void  CSet<T>::v_prv_intersection(const CSet &c_Less, const CSet &c_Greater, CSet &c_Result){



template <typename T>
void CSet<T>::v_prv_createNewArray(int i_Len){

	if (pt_array)
		delete[] pt_array;

	i_firstFreeIndex = 0;
	i_length = i_Len;
	pt_array = new T[i_Len];

}//void CSet<T>::v_prv_createNewArray(int i_Len)



















template <class T>
void CSet<T>::v_show(){
	cout << "Wyswietlam zbior: " << endl;


	for (int i = 0; i < i_firstFreeIndex; i++)
		cout << pt_array[i] << ",";
	cout << endl<< "       " << "Rozmiar tablicy: " << i_length << "   oraz firstfree index " << i_firstFreeIndex << endl;
}







template <class T>
CSet<string> * CSet<T>::isIntiger(){

	if (is_same<T, int>::value) {
		CSet<string> * p_zbior = new CSet<string>(this->i_length);
	

		for (int i = 0; i < i_firstFreeIndex; i++){
			(*p_zbior) += to_string(this->pt_array[i]);
			
		}
		return p_zbior;
	}  // optimizable...
	
	else
		return NULL;
}

/*

template <class T>
class Myclass
{
private:
	T temp;

public:
	// called for general T
	void checkNumeric() {
		cout << "is numeric = false" << endl;
	}
};

// specialized version for T = Numeric
template<> void Myclass<Numeric>::checkNumeric() {
	cout << "is numeric = " << temp.isNumeric() << endl;
}
*/








#endif