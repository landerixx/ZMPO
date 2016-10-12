#include "CPackingTree.h"


CPackingTree::CPackingTree(){

	p_root = NULL;
} //CPackingTree::CPackingTree(){


CPackingTree::~CPackingTree(){

	//cout << " destruktor tree" << endl;
	v_deleteTree();
}//CPackingTree::~CPackingTree(){

void CPackingTree::v_deleteTree(){

	if (!b_isEmpty()){

		//cout << " usuwam drzewo, bo byl call, a drzewo jest niepuste" << endl;
		delete p_root;
		p_root = NULL;
	}//if (!b_isEmpty()){
}//void CPackingTree::v_deleteTree(){


bool CPackingTree::b_isEmpty(){

	return p_root == NULL;
}//bool CPackingTree::b_isEmpty(){


//wiem, ze drzewo jest puste
void CPackingTree::v_createRoot(string s_NazwaObiektu, float  f_Mnoznik){ 

	p_root = new CNode(s_NazwaObiektu, f_Mnoznik);
}//void CPackingTree::v_createRoot(string s_NazwaObiektu, float  f_Mnoznik){

// drzewo juz ma roota
void CPackingTree::v_insert(string s_NazwaObiektu, float  f_Mnoznik, CNode & Parrent){

	CNode *node = new CNode(s_NazwaObiektu, f_Mnoznik);
	Parrent.v_addChild(*node);

}//void CPackingTree::v_insert(string s_NazwaObiektu, float  f_Mnoznik,CNode & Parrent)


CNode * CPackingTree::p_getRoot(){
	return p_root;
}//CNode * CPackingTree::c_getp_Root()



void CPackingTree::v_showUniqueList(){

	cout << endl << "Wyswietlam liste drzewa:" << endl;
	if (b_isEmpty())
		cout << "Drzewo jest puste." << endl;

	else{

		map<string, float>  m_mapa;
		prv_v_makeUniqueList(m_mapa, *p_root, 1.0);
		for (map<string, float>::iterator it = m_mapa.begin(); it != m_mapa.end(); it++)
			cout << to_string(it->second) << " produktow o nazwie: " << it->first << endl;
	}//else if (b_isEmpty())

}//void CPackingTree::v_show()


void CPackingTree::prv_v_makeUniqueList(map<string, float> & m_Mapa, CNode &Node, float Mnoz){

	float f_mnoznik = Node.f_getMnoznik()*Mnoz;
	string s_Nazwa = Node.s_getNazwaObiektu();

	map<string, float>::iterator it = m_Mapa.find(s_Nazwa);

	if (it == m_Mapa.end()) // jezeli nie znalazlem takiego klucza   to tworze nowa pare
		m_Mapa.insert(pair<string, float>(s_Nazwa, f_mnoznik));
	else					// jezeli jest juz taki klucz w mapie to dodaje wartosc
		it->second+=f_mnoznik;
	
	if (Node.b_hasChild())
	for (unsigned int i = 0; i < Node.i_howManyChildren(); i++)
		prv_v_makeUniqueList(m_Mapa, *Node.p_ChildAtIndex(i), f_mnoznik);

}//void CPackingTree::listaElementow(map<string, float> & m_Mapa, CNode &node, float Mnoz)



vector<CNode*> CPackingTree::vr_goDepth(){

	vector <CNode*> vr_vectorOfAllNodes;
	if (!b_isEmpty()){
		
		unsigned int* pi_indexOfElement = new unsigned int (ZERO);
		prv_v_goDepth(*p_root, ". ", *pi_indexOfElement, vr_vectorOfAllNodes);
		delete pi_indexOfElement;
	}//if (!b_isEmpty())

	else{
		//	cout << "Drzewo jest puste" << endl;
	}//else if (!b_isEmpty())

	return vr_vectorOfAllNodes;
}//vector<CNode*> CPackingTree::vr_goDepth()



void CPackingTree::prv_v_goDepth(CNode &Node, string s_Indentation, unsigned int &i_Index, vector <CNode*> & vr_VectorOfAllNodes){
	
	cout << i_Index++<< s_Indentation  << Node.s_getNazwaObiektu() << ", " << to_string(Node.f_getMnoznik()) << endl;
	s_Indentation += "	";
	vr_VectorOfAllNodes.push_back(&Node);

	if (Node.b_hasChild())
	for (unsigned int i = 0; i < Node.i_howManyChildren(); i++){
		prv_v_goDepth(*Node.p_ChildAtIndex(i), s_Indentation, i_Index, vr_VectorOfAllNodes);
	}//for (unsigned int i = 0; i < Node.i_howManyChildren(); i++){

}//void CPackingTree::prv_v_goDepth(CNode &Node, string s_Indentation, unsigned int &i_Index, vector <CNode*> & vr_VectorOfAllNodes)




void CPackingTree::prv_v_communique(int i_Case){


	switch (i_Case){

	case ZERO:
		cout << "Drzewo zostalo poprawnie stworzone." << endl;
		break;
	case ONE:
		cout << "Blad. Nie wprowadziles zadnego znaku" << endl;
		break;
	case TWO:
		cout << "Blad. Brak \"[\" na poczatku." << endl;
		break;
	case THREE: 
		cout << "Blad. Brak \"]\" na koncu." << endl;
		break;
	case FOUR:
		cout << "Blad przy wprowadzaniu, brak \" do zakoñczenia nazwy produktu." << endl; 
		break;
	case FIVE: 
		cout << "Blad, po przecinku za liczba nie ma nawiasu otwierajacego liste." << endl; 
		break;
	case SIX:
		cout << "Blad po liczbie nie ma przecinka." << endl;		
		break;
	case SEVEN: 
		cout << "Blad, zle wpisany float. Pamietaj rowniez, ze mnoznik musi byc wiekszy od 0" << endl;		
		break;
	case EIGHT:
		cout << "Blad przy wprowadzaniu, brak przecinka po nazwie produktu." << endl;  
		break;
	case NINE:
		cout << "Blad po otwarciu nawiasu kwadratowego nie ma cudzyslowia." << endl;  
		break;
	case TEN: 
		cout << "Blad. Nie zostal otwarty nawias kwadratowy w liscie produktow podrzednych " << endl; 
		break;
	case ELEVEN:
		cout << "Blad. Zle stworzony poczatek listy produktow podrzednych" << endl; 
		break;
	case TWELVE:
		cout << "Blad przy zamykaniu listy produktow podrzednych:" << endl; 
		break;
	case THIRTEEN:
		cout << "blad, zamkniety nawias zwykly, na poczatku ciagu " << endl;
		break;
	case FOURTEEN:
		cout << "blad, zamkniety nawias kwadratowy na poczatku ciagu " << endl;
		break;
	case FIVETEEN:
		cout << "blad przy wpisywaniu drzewa, brakuje nawiasu kwadratowego na poczatku" << endl;
		break;

	}//switch (i_Case)
}



bool CPackingTree::prv_b_createMnoznik(float &f_Mnoznik, string::iterator & s_Iterator){

	bool b_priopriety=true;
	string s_mnoznik = "";
	int i_ascii = (*s_Iterator);

	if ((i_ascii >= ASCII_ZERO) && ((i_ascii) <= ASCII_NINE)){

		while ((i_ascii >= ASCII_ZERO) && ((i_ascii) <= ASCII_NINE)){
			s_mnoznik += (*s_Iterator); s_Iterator++; i_ascii = (*s_Iterator);
		}//while ((i_ascii >= ASCII_ZERO) && ((i_ascii) <= ASCII_NINE))
		if (i_ascii == ASCII_DOT){
			s_mnoznik += (*s_Iterator); s_Iterator++; i_ascii = (*s_Iterator);
		}//if (i_ascii == ASCII_DOT)
		while ((i_ascii >= ASCII_ZERO) && ((i_ascii) <= ASCII_NINE)){
			s_mnoznik += (*s_Iterator); s_Iterator++; i_ascii = (*s_Iterator);
		}//while ((i_ascii >= ASCII_ZERO) && ((i_ascii) <= ASCII_NINE))

	}//if ((i_ascii >= ASCII_ZERO) && ((i_ascii) <= ASCII_NINE))
	else
		b_priopriety = false;
		
	if (b_priopriety)
		f_Mnoznik = stof(s_mnoznik);

		return b_priopriety;
		
	}//bool CPackingTree::prv_f_createMnoznik(float &f_Mnoznik, string::iterator & s_Iterator){







int CPackingTree::i_enterString(string &s_Input){

	bool b_priopriety = true;
	string s_nazwaObiektu;;
	string::iterator s_iterator;
	stack <CNode*> sk_stackOfParents;
	int i_return = ZERO;

	if (s_Input.size() == ZERO){
		b_priopriety = false; i_return = ONE;															////// -> BLAD nr 1
	}//if (s_Input.size() == 0){

	else if (s_Input[0] != '['){
		b_priopriety = false; i_return = TWO;															////// -> BLAD nr 2
	}// else if (s_Input[0] != '[')

   else if (s_Input[s_Input.size() - ONE] != ']'){
	   b_priopriety = false; i_return = THREE;																 ////// -> BLAD nr 3
	}//else if (s_Input[s_Input.size() - 1] != ']'){
	
   else{
	   s_iterator = s_Input.begin();
	   while (b_priopriety && (s_iterator != s_Input.end())){

		   switch (*s_iterator){

		   case '[':
			   s_iterator++;
			   switch (*s_iterator){

			   case '\"':
				   s_iterator++;
				   s_nazwaObiektu = "";
				   while (s_iterator != s_Input.end() && *s_iterator != '\"') {	//Tworzenie Stringa
					   s_nazwaObiektu += (*s_iterator);
					   s_iterator++;
				   }//(((*s_iterator) != '\"') && (s_it != s_input.end()))

				   if (s_iterator == s_Input.end()){									
					   i_return = FOUR; b_priopriety = false;												//// -> BLAD nr 4 brak konca cudzyslowia
				   }//if (s_it == s_input.end())

				   if (b_priopriety){														//jezeli nazwa jest poprawnie skonstuowana

					   s_iterator++;
					   float   f_mnoznik = ZERO;
					   if ((*s_iterator) == ',') {										//jezeli to jest przecinek przed FLOATEM


						   s_iterator++;
						   bool b_isFloat = prv_b_createMnoznik(f_mnoznik, s_iterator); //czy float jest poprawnie skonstruowany
						   if (b_isFloat && f_mnoznik!=0){												//jezeli float jest poprawnie skonstruowany

							   if (this->b_isEmpty()){

								   v_createRoot(s_nazwaObiektu, f_mnoznik);
								   sk_stackOfParents.push(p_root);
							   }//if (this->b_isEmpty())
							   else{

								   CNode *node = new CNode(s_nazwaObiektu, f_mnoznik);
								   (*sk_stackOfParents.top()).v_addChild(*node);		//tworzony obiekt ma rodzica, (rodzic) jest na czubku stosu
								   sk_stackOfParents.push(node);
							   }//else if(this->is_Empty())

							   if (*s_iterator == ','){									// jezeli jest to przecinek przed LISTA DZIECI

								   s_iterator++;
								   if (*s_iterator == '('){}
								   else{
									   i_return= FIVE; b_priopriety = false;							//// -> BLAD nr 5 po przecinku po floacie nie ma nawiasu otwierajacego
								   }//else  if (*s_iterator == '(')

							   }// if (*s_iterator == ',')
							   else{
								   b_priopriety = false; i_return = SIX;								 //// -> BLAD nr 6  po liczbie nie ma przecinka
							   }//else  if (*s_iterator == ',')
						   }//if (b_isFloat)

						   else{
							   b_priopriety = false; i_return = SEVEN; 								 //// -> BLAD nr 7 Blad przy wprowadzaniu, zle wpisany float 
						   }//else if (b_isFloat)
					   }// if ((*s_iterator) == ',')
					   else{
						   i_return = EIGHT; b_priopriety = false;										 //// -> BLAD nr 8 Brak przecinka po nazwie produktu   
					   }// else  if ((*s_iterator) == ',')
				   }//if (b_success) //nazwa poprawnie skonstruowana

				   break;
			   case ']':
				   break;
			   default:
				   i_return = NINE; b_priopriety = false;												 //// -> BLAD nr 9 Brak cudzyslowia rozpoczynajacego nazwe prodktu			  
			   }// case [ switch

			   break;
		   case ',':
			   s_iterator++;
			   switch (*s_iterator){
			   case '[': break;
			   default:
				   i_return = TEN; b_priopriety = false;												//// -> BLAD nr 10 nie zostal otwarty nawias kwadratowy po poprawnie wprowadzonym bracie

			   }//switch (*s_iterator)

			   break;
		   case'(':
			   s_iterator++;
			   switch (*s_iterator){
			   case '[': break;
			   case ')': break;
			   default:
				   i_return = ELEVEN; b_priopriety = false;											//// -> BLAD nr 11 Zle stworzony poczatek listy dzieci parrenta
				  
			   }//switch (*s_iterator)

			   break;
		   case ')':
			   s_iterator++;
			   if (*s_iterator != ']'){
				   i_return = TWELVE; b_priopriety = false;											 //// -> BLAD nr 12 blad przy zamykaniu listy dzieci obietu
			   }// if (*s_iterator !=']')
			   else if (sk_stackOfParents.empty()){
				   i_return = THIRTEEN; b_priopriety = false;											//// -> BLAD nr 13 zamkniety nawias zwykly, na poczatku ciagu 
			   }//if (sk_stackOfParents.empty())
			   else
				   sk_stackOfParents.pop();

			   break;
		   case ']':
			   s_iterator++;

			   if (s_iterator == s_Input.end()){}
			   else if (*s_iterator == ','){}
			   else if (*s_iterator == ')'){}
			   else{
				   i_return = FOURTEEN; b_priopriety = false;											//// -> BLAD nr 14 zamkniety nawias kwadratowy na poczatku ciagu	   
			   }
			   break;
		   default:
			   i_return = FIVETEEN; b_priopriety = false;												//// ->BLAD nr 15 przy wpisywaniu drzewa, brakuje nawiasu kwadratowego na poczatku
		   }//   switch (*s_iterator){
	   }// while ( b_success && (s_iterator != s_Input.end())){
   }//else poczatkowe warunki

   if (!b_priopriety)
	   v_deleteTree();

   prv_v_communique(i_return);
	return i_return;
}//int CPackingTree::i_enterString(string s_Input){






void CPackingTree::poziom(){


	if (b_isEmpty()){

		cout << "drzewo jest puste";
	}
	else{


		queue<CNode*> kolejka;
		CNode * helper;
		kolejka.push(p_root);

	}



}






/*


void CPackingTree::v_showList(CNode & node, float Mnoz){// node, mnoznik

float mnoznik = node.f_getMnoznik()*Mnoz;

cout << to_string(mnoznik) << ", " << node.s_getNazwaObiektu() << endl;

if (node.b_hasChild())
for (unsigned int i = 0; i < node.i_howManyChildren(); i++){

v_showList(*node.p_ChildAtIndex(i), mnoznik);

}

}

*/