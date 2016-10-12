#ifndef  CNode_H
#define  CNode_H


#define OUT_OF_RANGE -1

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>


using namespace std;

class CNode{

private:

	void * pv_element;
	CNode * pc_previous;
	CNode * pc_next;


	void v_prv_copyOther(const CNode & c_Other);

public:

	CNode();
	CNode(void * pv_Elem);
	CNode(const CNode & pc_Other);
	~CNode();

	void v_setPrevious( CNode * pc_Prev);
	void v_setNext( CNode  * pc_Next);
	void v_setElement(void * pv_Elem);

	CNode * pc_getPrevious();
	CNode * pc_getNext();
	void * pv_getElement();

	void v_deleteData();
	
	CNode &operator =(const CNode &c_Other); // op przypisania

	friend ostream& operator<< (ostream & cout, const CNode & c_Node);











};





#endif
