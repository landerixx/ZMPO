#include "CNumb.h"





CNumb::CNumb(){
	this->pi_number = NULL;
	cout << "Konstruktor domyslny" << this << endl;
}
CNumb::CNumb(CNumb & Pattern){

	cout << "konstruktor kopiujacy " << this << " a wzorzec to: " << &Pattern << endl;
	pi_number = new int(*Pattern.pi_number);
}

CNumb::CNumb(int i_Numb){
	cout << "konstruktor z podanym polem: " << this << "      " << i_Numb << endl;
	pi_number = new int(i_Numb);
}


CNumb::~CNumb(){
	cout << "DEstruktor " << this << endl;
	v_clearData();
}



CNumb & CNumb::operator = (CNumb & cSnd){

	cout << "Operator przypisania dla " << this << " korzystamy z " << &cSnd << endl;
	if (this != &cSnd) {								//jezeli nie wskazuja na ten sam obiekt , operator &Snd podaje adres obiektu, a this to wskaznik, czyli tez adres

		v_clearData();
		pi_number = new int(*cSnd.pi_number);

	} //if (this != &cSnd) 

	return *this;										//Operator wy³uskania * podaje  zmiennš wskazywanš przez pointer this
}

CNumb & CNumb::operator = (int i_Numb){
				
	cout << "operator przypisania dla: " << this << " wartoscia " << i_Numb << endl;
	v_clearData();
	pi_number = new int(i_Numb);
	return *this;										
}


CNumb CNumb::operator +(CNumb & cSnd){
	cout << " operator + dla " << this << " korzystamy z " << &cSnd << endl;
	//CNumb r(*this->pi_number + *cSnd.pi_number);
	return CNumb (*this->pi_number + *cSnd.pi_number);
	
	

}

void CNumb::v_clearData(){
	if (pi_number != NULL)
		delete pi_number;
}


void CNumb::v_show(){

	cout << *pi_number << endl;
}