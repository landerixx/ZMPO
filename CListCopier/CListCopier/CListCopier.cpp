#include "CListCopier.h"






CListCopier::CListCopier(){

	cout << " konstruktor domyslny, obiekt: " << this << endl;



}

CListCopier::~CListCopier(){

	cout << " destruktor obiektu " << this <<  endl;


	int i_size = (int)inty.size();
	if (i_size > 0){

		for (int i = 0; i < i_size; i++){
			delete inty[i];
			inty[i] = NULL;
		}

		inty.clear();
	}

}//CListCopier::~CListCopier(){



CListCopier::CListCopier(CListCopier & Pattern){

	cout << " konstruktor kopiujacy obiektu " << this << "    a wzorzec to  " << &Pattern <<  endl;

	int i_size = (int)Pattern.inty.size();

	for (int i = 0; i < i_size; i++){

		int* ptr = new int; //Declare and initialize a pointer to some dynamically allocated memory
		*ptr = *Pattern.inty[i];
		this->inty.push_back(ptr);
	}

}




void CListCopier::vAddInt(int iNewInt){

	int* ptr = new int; //Declare and initialize a pointer to some dynamically allocated memory
	*ptr = iNewInt; //Set our integer "variable" to 5 (via the pointer)
	inty.push_back(ptr);

}

void CListCopier::vDeleteInt(){

	inty.pop_back();
}



void CListCopier::show(){

	int i_size = (int)inty.size();
	for (int i = 0; i < i_size; i++){
		cout << *inty[i] << ", ";
	}
	cout << endl;

}

void CListCopier::showMem(){

	int i_size = (int)inty.size();
	for (int i = 0; i < i_size; i++){
		cout << inty[i] << ", ";
	}
	cout << endl;

}


CListCopier  & CListCopier::operator = (CListCopier & cSnd){

	int i_size = (int) cSnd.inty.size();

		for (int i = 0; i < i_size; i++){

			int* ptr = new int; //Declare and initialize a pointer to some dynamically allocated memory
			*ptr = *cSnd.inty[i];
			this->inty.push_back(ptr);
		}
	
	return *this;

} //CListCopier  & CListCopier::operator = (CListCopier & cSnd)


CListCopier CListCopier::operator +(CListCopier & cSnd){

	CListCopier result;

	int i_size = (int)this->inty.size();

	for (int i = 0; i < i_size; i++){

		int* ptr = new int; //Declare and initialize a pointer to some dynamically allocated memory
		*ptr = *this->inty[i];
		result.inty.push_back(ptr);
	}



	i_size = (int)cSnd.inty.size();

	for (int i = 0; i < i_size; i++){

		int* ptr = new int; //Declare and initialize a pointer to some dynamically allocated memory
		*ptr = *cSnd.inty[i];
		result.inty.push_back(ptr);
	}

	return result;
}