#ifndef CTree_h
#define CTree_h


#include "CNode.h"

class CTree{

private:

	CNode *p_root;



public:


	CTree();
	~CTree();

	void v_setRoot(CNode * root);
	CNode * pc_getRoot();

	void v_deleteData();

	void v_printTree();
	void v_duplicateTree(CTree & );



};











#endif