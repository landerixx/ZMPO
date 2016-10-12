#include "CTree.h"




CTree::CTree(){

	p_root = new CNode();

}


CTree::~CTree(){

	v_deleteData();
	
}


void CTree::v_deleteData(){

	delete p_root;
	p_root = NULL;

}


/*
void CTree::v_setRoot(CNode * root){

	//co z rootem ktory byl wczesniej? potrzebna ta metoda?
	this->p_root = root;

}
*/

CNode* CTree::pc_getRoot(){
	return p_root;
}




void CTree::v_printTree(){

	
	p_root->v_print(0,"");

}

void CTree::v_duplicateTree(CTree & Other){

	v_deleteData();
	p_root = Other.pc_getRoot();
}