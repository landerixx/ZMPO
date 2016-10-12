
#ifndef CSet_H
#define CSet_H

#define DEF_LENGTH 10

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;


template<class T>
class CSet{

private:

	T * pt_array;
	int i_length;
	int i_firstFreeIndex;

	void v_prv_fullfillWithNulls();
	void v_prv_setFromPattern(CSet<T> & Pattern);

	void v_prv_copyToNewArray();

	void v_prv_deleteData();



public:


	CSet();
	CSet(int len);
	CSet(CSet<T> & Pattern);
	~CSet();

	
	void v_clear(); // usuwa elementy, ze zbioru (czysci tablice, tablica ma caly czas zarezerwowana taka sama pamiec jak wczesniej)

	bool b_isFull();
	bool b_isEmpty();


	bool b_add(T & T_elem);
	
	bool b_contains(T & T_elem);



	CSet<T>  & operator = (CSet<T> & c_Snd); //  zeby mozna bylo  uzywac a=b=c operujemy na elemencie nie na jego kopii
	CSet<T>  operator +(CSet<T> & c_Snd);
	CSet<T>  operator +(T & t_Elem);



	
	void v_show();


};



#endif



