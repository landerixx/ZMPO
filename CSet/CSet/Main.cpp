#include "CSet.h"
#include "CSet.cpp"


int main(){

	cout << "Witam w programie: " << endl;

	CSet<char> tescik;
	char a = 'a';
	char b = 'b';
	char c = 'c';
	char d = 'd';
	char e = 'e';
	
	tescik.b_add(a);
	tescik.b_add(b);
	tescik.b_add(c);
	tescik.b_add(d);
	tescik.v_show();
	

	CSet<char> tescik2(tescik);
	//tescik2.v_show();
	//tescik2=tescik;
	//tescik2.v_show();
	//CSet<char> tescik2 = tescik;

	/*
	CSet<int> tescik1(4);
	int aa = 1;
	int bb = 2;


	tescik1.b_add(aa);
	tescik1.b_add(bb);
	tescik1.v_show();
	tescik1.v_clear();
	cout << "show 2";
	tescik1.v_show();

	*/

	getchar();
	cin.ignore();
	return 0;
}