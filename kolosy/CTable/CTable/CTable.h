#include <iostream>
#include <cstdio>
#include <string>


using namespace std;



class CTable{

private:

	int *pi_table;
	int i_len;





public:

	CTable();
	CTable(int Length);
	~CTable();

	void vSetLength(int Len);
	bool bSetValue(int Index,int Val);

	void vshow();
	void vAddValues(CTable & tab);

};