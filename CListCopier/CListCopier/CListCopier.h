


#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;


class CListCopier{

private:

	vector<int*> inty;


public:


	CListCopier();
	CListCopier(CListCopier & Pattern);
	~CListCopier();

	void vAddInt(int iNewInt);
	void vDeleteInt();
	void show();
	void showMem();




	CListCopier  & operator = (CListCopier & cSnd); //  zeby mozna bylo  uzywac a=b=c operujemy na elemencie nie na jego kopii
	CListCopier operator +(CListCopier & cSnd);

};