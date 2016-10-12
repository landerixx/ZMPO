#include "CSet.h"


//implemtancja bez nulli


int main(){


	cout << "witaj " << endl;

	/*
	CSet<int> one(2);
	CSet<int> two;
	
	
	int o = 1;
	int t = 2;
	int th = 3;
	int f = 4;
	int fi = 5;

	one.b_add(o);

	two = one;

	one.b_add(th);
	cout << "one" << endl;
	one.v_show();

	one.b_add(f);
	cout << "one" << endl;
	one.v_show();
	one.b_add(f);

	two.b_add(o);
	one.b_add(t);
	CSet<int> three = one;
	one.b_add(fi);

	
	
	one.v_show();
	two.v_show();
	three.v_show();


	*/





	/*
	CSet<char> zbior;

	int i_lenOfTable = 13;
	char * pc_chary = new char[i_lenOfTable];
	pc_chary[0] = 'a';
	pc_chary[1] = 'b';
	pc_chary[2] = 'c';
	pc_chary[3] = 'd';
	pc_chary[4] = 'e';

	for (int i = 5; i < i_lenOfTable; i++)
		pc_chary[i] = NULL;

	zbior.v_addArray(pc_chary, i_lenOfTable);

	zbior.v_show();


	CSet<int> zbiorLiczb;

	
	int * pc_inty = new int[i_lenOfTable];
	pc_inty[0] = 1;
	pc_inty[1] = 2;
	pc_inty[2] = 3;
	pc_inty[3] = 4;
	pc_inty[4] = 5;

	for (int i = 5; i < i_lenOfTable; i++)
		pc_inty[i] = NULL;

	zbiorLiczb.v_addArray(pc_inty, i_lenOfTable);

	zbiorLiczb.v_show();

	delete[] pc_chary;
	delete[] pc_inty;

	*/






	/*
	float o = 1;
	float t = 2;
	float th = 3;
	float f = 4;
	float fi = 5;

	CSet<float> zbior;

	zbior.b_add(th);

	CSet<float> result;
	result = zbior + o;



	zbior.v_show();
	result.v_show();

	result = result + th;
	result = result + fi;

	result.v_show();


	*/



	/*
	CSet<string> zbior;
	CSet<string> zbior2;
	CSet<string> result;

	string a = "adam";
	string b = "benek";
	string c = "czesiek";
	string d = "dawid";
	string e = "edek";
	string f = "franek";


	zbior.b_add(a);
	zbior.b_add(b);
	zbior.b_add(c);

	zbior2.b_add(d);
	zbior2.b_add(e);
	zbior2.b_add(f);

	result = zbior + zbior2;

	zbior.v_show();
	zbior2.v_show();
	result.v_show();

	cout << " First free index zbioru:" << zbior.i_get_firstFreeIndex() << endl;
	cout << " First free index zbioru2:" << zbior2.i_get_firstFreeIndex() << endl;
	cout << " First free index resulta:" << result.i_get_firstFreeIndex() << endl;


	*/



/*
	CSet<int> pierwszy;
	CSet<int> drugi;
	CSet<int> result(1);
	CSet<int> result2(1);

	int o = 1;
	int t = 2;
	int th = 3;
	int f = 4;
	int fi = 5;

	pierwszy += o;
	pierwszy +=t;
	pierwszy += th;
	pierwszy += f;

	pierwszy.v_show();
	
	drugi +=th;
	drugi += f;
	drugi += fi;

	drugi.v_show();

	cout << " SUMA: " << endl;
	result = pierwszy + drugi;
	result.v_show();

	cout << "CLEAR RESULT " << endl;
	result.v_clear();
	result.v_show();

	cout << "CZESC WSPOLNA" << endl;
	result = pierwszy*drugi;
	result.v_show();
	
	result2 += pierwszy;

	cout << "result2 " << endl;
	result2.v_show();
	*/



/*
CSet<int> pierwszy(5);
CSet<int> drugi;

int o = 1;
int t = 2;
int th = 3;
int f = 4;
int fi = 5;

pierwszy += o;
pierwszy += t;
pierwszy += th;
pierwszy += f;

pierwszy.v_show();

drugi = pierwszy - o;
drugi = drugi - th;
drugi = drugi - t;
drugi = drugi - t;


drugi.v_show();
*/





/*
CSet<int> pierwszy(5);
CSet<int> drugi(4);
CSet<int> result;

int o = 1;
int t = 2;
int th = 3;
int f = 4;
int fi = 5;

pierwszy += o;
pierwszy += t;
pierwszy += th;

drugi += t;
drugi += th;
drugi += f;



result = pierwszy - drugi;


pierwszy.v_show();
drugi.v_show();
result.v_show();

*/

/*
CSet<char> pierwszy(5);
CSet<char> drugi(4);
CSet<char> result;

char a = 'A';
char b = 'B';
char c = 'C';
char d = 'D';
char e = 'E';

pierwszy += a;
pierwszy += b;
pierwszy += c;

drugi += b;
drugi += c;
drugi += d;


pierwszy.v_show();
drugi.v_show();

result = pierwszy *drugi;

result.v_show();

*/


CSet<char> pierwszy(5);

char a = 'A';
char b = 'B';
char c = 'C';
char d = 'D';

pierwszy += a;
pierwszy += b;
pierwszy += c;

/*
CSet<string> *prawda= pierwszy.isIntiger();

if (prawda == NULL)
	cout << " Jestem pusty" << endl;
else 
	prawda->v_show();


CSet<int> two(10);
int o = 1;
int t = 2;
int th = 3;
int f = 4;
int fi = 5;


two += o;
two += t;
two += th;
two += f;

prawda = two.isIntiger();


if (prawda == NULL)
cout << " Jestem pusty" << endl;
else
prawda->v_show();





delete prawda;


*/




	cin.ignore();
	getchar();
	return 0;
}