// kolokwim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CICanCopy.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{

	CICanCopy c_arg_0, c_arg_1, c_concat;
	c_arg_0 = "ala";
	cout << c_arg_0.sGetData() << endl;
	c_arg_1 = "ma kota";
	cout << c_arg_1.sGetData() << endl;
	c_concat = c_arg_0.cConcatenate(&c_arg_1);

	cout << c_concat.sGetData() << endl;
	//w tym momencie stan obiektów ma byæ nastêpuj¹cy :
	//c_arg_0 zawiera "ala"
	//	c_arg_1 zawiera "ma kota"
	//	c_concat zawiera "Alama kota"


	system("pause");
	return 0;
}