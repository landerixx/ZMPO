#ifndef CNode_h
#define CNode_h


#define ZERO 0
#define ONE  1
#define TWO  2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define SIX 6
#define SEVEN 7
#define EIGHT 8
#define NINE 9
#define TEN 10
#define ELEVEN 11
#define TWELVE 12
#define THIRTEEN 13
#define FOURTEEN 14
#define FIVETEEN 15
#define ASCII_ZERO 48
#define ASCII_NINE 57
#define ASCII_DOT 46


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>

using namespace std;



class CNode {


private:

	string s_nazwaObiektu;
	float f_mnoznik;
	vector  <CNode*> vr_potomkowie;
	
	CNode();


public:

	CNode(string s_Nazwa, float f_Mnoznik);
	CNode( const CNode & pattern);
	~CNode();

	void v_setNazwaObiektu(string s_Nazwa);
	void v_setMnoznik(float f_Mnoznik);
	void v_setPotomkowie(vector  <CNode*> vr_Potomkowie);
	void v_setObject(string s_Nazwa, float f_Mnoznik);


	vector  <CNode*> vr_getPotomkowie();
	string s_getNazwaObiektu();
	float f_getMnoznik();


	void v_addChild(CNode & Child);


	bool b_hasChild();
	unsigned int i_howManyChildren();
	CNode* p_ChildAtIndex(unsigned int i);




	//friend ostream& operator<<(ostream&, const CNode&);
	


};


#endif






































