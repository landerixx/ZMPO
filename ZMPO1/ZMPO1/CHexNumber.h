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


	void v_prv_addAlgorithm(CHexNumb *pcFst, CHexNumb *pcSnd);
	void v_prv_substractionAlgorithm(CHexNumb *pcFst, CHexNumb *pcSnd);
	int i_prv_whichGreater(CHexNumb *pcFst, CHexNumb *pcSnd);
	void v_prv_clear();
	int i_prv_ignoreZeros(string sInput);
	void v_prv_fullfillZeros(); 

	

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



	void v_add( CHexNumb *pcFst,  CHexNumb *pcSnd);
	void v_substract(CHexNumb *pcFst, CHexNumb *pcSnd);
	void v_multiply(CHexNumb * pcFst, CHexNumb *pcSnd);



	








	void showArray();








	
	

	

	

	



};



#endif



