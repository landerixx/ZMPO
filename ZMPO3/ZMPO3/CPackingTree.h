#ifndef CPackingTree_h
#define CPackingTree_h



#include "CNode.h"



class CPackingTree {


private:
	CNode *p_root;



	void prv_v_goDepth(CNode &Node, string s_Indentation, unsigned int &i_Index, vector <CNode*> & vr_VectorOfAllNodes);
	void prv_v_makeUniqueList(map<string,float> & Map, CNode &Node, float Mnoz);
	bool prv_b_createMnoznik(float &f_Mnoznik, string::iterator & s_Iterator);
	void prv_v_communique(int i_Case);

public:

	CPackingTree();
	~CPackingTree();

	void v_deleteTree();
	bool b_isEmpty();
	void v_createRoot(string s_NazwaObiektu, float  f_Mnoznik);

	void v_showUniqueList(); // ile danych elementow znajduje sie sie drzewie (lista unikatowych obiektow alfabetycznie)
	vector <CNode*> vr_goDepth();

	void v_insert(string s_NazwaObiektu, float  f_Mnoznik, CNode &Parrent);
	
	


	CNode * p_getRoot();
	void v_setRoot(CNode*  p_Root);

	int i_enterString(string &s_Input);
	
	void poziom();


	//void v_showList(CNode &node, float Mnoz);
};


#endif