#include "CNode.h"






CNode::CNode(){

//	cout << "konstruktor domyslny" << endl;
}//CNode::CNode()



CNode::CNode(string s_Nazwa, float f_Mnoznik){
	
//	cout << "konstruktor nodea  z danymi" << endl;
	v_setObject(s_Nazwa, f_Mnoznik);
}//CNode::CNode(string s_Nazwa, float f_Mnoznik)


CNode::CNode(const  CNode & pattern){ //nie uzywam

//	cout << "konstruktor kopiujacy nodea  " << endl;
	v_setObject(pattern.s_nazwaObiektu, pattern.f_mnoznik);
	
	//vr_potomkowie=pattern.vr_potomkowie;																																		//to sa pointery. A co jestli w patternie usuniemy wskazniki -> w zamysle usuniemy te obiekty, to w tym bedziemy miec pointery
																																												// do nie istniejacych juz obiektow ...
}//CNode::CNode(const  CNode & pattern)


CNode::~CNode(){

//	cout << " call destruktor  nodea: " << s_nazwaObiektu << endl;
	int i_size =(int) i_howManyChildren();
	if ( b_hasChild()){

		for (int i = 0; i < i_size; i++){
			delete vr_potomkowie[i];
			vr_potomkowie[i] = NULL;
		}//for (int i = 0; i < i_size; i++)

		vr_potomkowie.clear();
	}//if ( i_size!= 0)

//	cout << " wykonalem destruktor tego nodea: " << s_nazwaObiektu << endl;
}//CNode::~CNode()




void CNode::v_setObject(string s_Nazwa, float f_Mnoznik){

	s_nazwaObiektu = s_Nazwa;
	f_mnoznik = f_Mnoznik;
}//void CNode::v_setObject(string s_Nazwa, float f_Mnoznik)

void CNode::v_setNazwaObiektu(string s_Nazwa){
	 s_nazwaObiektu = s_Nazwa;
}//void CNode::v_setNazwaObiektu(string s_Nazwa)

void CNode::v_setMnoznik(float f_Mnoznik){
	f_mnoznik = f_Mnoznik;
}//void CNode::v_setMnoznik(float f_Mnoznik)

void CNode::v_setPotomkowie(vector  <CNode*> vr_Potomkowie){ //nie uzywam

	vr_potomkowie = vr_Potomkowie;
}//void CNode::v_setPotomkowie(vector  <CNode*> vr_Potomkowie)




vector  <CNode*> CNode::vr_getPotomkowie(){

	return vr_potomkowie;
}//vector  <CNode*> CNode::vr_getPotomkowie()

string CNode::s_getNazwaObiektu(){

	return s_nazwaObiektu;
}//tring CNode::s_getNazwaObiektu()

float CNode::f_getMnoznik(){

	return f_mnoznik;
} // float CNode::f_getMnoznik()






void CNode::v_addChild(CNode & Child){

	this->vr_potomkowie.push_back(&Child); // dodaje temu nodeowi pointer child do wektora potomkow
}//void CNode::v_addChild(CNode & Child)

bool CNode::b_hasChild(){

	return this->vr_potomkowie.size() != 0;

}

unsigned int CNode::i_howManyChildren(){

	return this->vr_potomkowie.size();
}

CNode* CNode::p_ChildAtIndex(unsigned int i){

	return vr_potomkowie[i];

}














/*

ostream& operator<<(ostream& str, const CNode& n) {
	     return str << n.s_nazwaObiektu;
	
}

*/