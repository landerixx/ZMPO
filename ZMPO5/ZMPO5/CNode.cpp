#include "CNode.h"


CNode::CNode(){

	pv_element = NULL;
	pc_previous = NULL;
	pc_next = NULL;

}

CNode::CNode(void* pv_Elem){

	pv_element = pv_Elem;
	pc_previous = NULL;
	pc_next = NULL;


}

CNode::CNode(const CNode& c_Other){

	this->pc_next = c_Other.pc_next;
	this->pc_previous = c_Other.pc_previous;
	this->pv_element = c_Other.pv_element;

}

CNode & CNode::operator =(const CNode &c_Other){ // op przypisania tak o dorobilem

	this->pc_next = c_Other.pc_next;
	this->pc_previous = c_Other.pc_previous;
	this->pv_element = c_Other.pv_element;

	return *this;
}

CNode::~CNode(){

	v_deleteData();
}

void CNode::v_deleteData(){

	if (pc_next!=NULL)
		pc_next->v_setPrevious(this->pc_previous);
	if (pc_previous!=NULL)
		pc_previous->v_setNext(this->pc_next);

}






void CNode::v_setPrevious( CNode * pc_Prev){

	this->pc_previous = pc_Prev;
}


void CNode::v_setNext( CNode * pc_Next){

	this->pc_next = pc_Next;
}

void CNode::v_setElement(void * pv_Elem){

	this->pv_element = pv_Elem;
}


CNode* CNode::pc_getPrevious(){

	return this->pc_previous;

}
CNode* CNode::pc_getNext(){

	return this->pc_next;

}

void* CNode::pv_getElement(){

	return this->pv_element;
}



ostream& operator<< (ostream & cout, const CNode & c_Node){
	cout << c_Node.pv_element;
	return cout;
}
