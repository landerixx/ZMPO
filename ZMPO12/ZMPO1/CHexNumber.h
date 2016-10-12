#ifndef CHexNumber_h
#define CHexNumber_h


#define  NUMBER_BASE  16
#define  DEFAULT_LEN  10



#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class CHexNumb	
{

private:

	int i_length; 
	int *pi_array;
	bool b_positive;


	void v_prv_substractionAlgorithm(CHexNumb &cGreater, CHexNumb &cLess, CHexNumb  &cResult);
	void v_prv_addAlgorithm(CHexNumb & cResult, CHexNumb & cSnd);
	int i_prv_whichGreater(CHexNumb & cFst, CHexNumb & cSnd);

	
	
	void v_prv_clear();
	int i_prv_ignoreZeros(string sInput);
	void v_prv_quitWithZeros();
	void v_prv_fullfillZeros(); 
	//void v_prv_deleteZeroes(); 
	int i_prv_deleteZeroes();

	CHexNumb make_to_index(int index, CHexNumb & liczba);
	void koryguj();
	bool skorygowane();
	



public:
	CHexNumb();
	CHexNumb(int iLength);
	CHexNumb(  CHexNumb &pattern);
	~CHexNumb(); 

	int i_getLength();
	void v_setLength(int iLength);

	int *pi_getArray();
	void v_setArray(int* piArray);

	bool b_getPositive();
	void v_setPositive(bool bPositive);

	bool b_enter(string sInput);
	void v_show();

	CHexNumb  & operator = (CHexNumb & cSnd); //  zeby mozna bylo  uzywac a=b=c operujemy na elemencie nie na jego kopii
	CHexNumb operator +( CHexNumb & cSnd);
	CHexNumb operator -( CHexNumb & cSnd);
	CHexNumb operator *( CHexNumb & cSnd);
	CHexNumb operator /( CHexNumb & cSnd);


	

	
	



	

	






	void showArray();








	
	

	

	

	



};



#endif



