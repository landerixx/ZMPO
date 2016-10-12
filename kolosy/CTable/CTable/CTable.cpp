#include "CTable.h"






CTable::CTable(int Length=10){

	i_len = Length;
	this->pi_table = new int[i_len];

}


CTable::~CTable(){

	if (pi_table) delete [] pi_table;
}


void CTable::vSetLength(int Len){

	if (pi_table){

		int *pi_newArray = new int[Len];
		

		/*
		for (int i = 0; i < i_len; i++)
			pi_newArray[i] = pi_table[i];
		*/
		memcpy(pi_newArray, pi_table, sizeof(int)* i_len);
		delete[] pi_table;
		pi_table = pi_newArray;
		

	}//if (pi_table)
	else {
	
		this->pi_table = new int[i_len];
	}//else if (pi_table)

	i_len = Len;
}



bool CTable::bSetValue(int Index,int Val){

	bool success = true;

	if (Index<0 || Index >(i_len-1))
		success = false;

	if (!success){
		cout << "Niepoprawny index przy dodawaniu wartosci " << Val << endl;
	}//if (!success)

	else{
		pi_table[Index] = Val;	
	}//else if (!success)
	

	return success;
}


void CTable::vAddValues(CTable & tab){

	int i_index = i_len;

	vSetLength(this->i_len + tab.i_len);

	for (int i = 0; i_index < i_len; i_index++)
		bSetValue(i_index, tab.pi_table[i++]);

}





void CTable::vshow(){

	cout << "moja dlugosc to: " << i_len << endl;

	for (int i = 0; i < i_len; i++)
		cout << pi_table[i] << ", ";


}