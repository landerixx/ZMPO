

#ifndef  CLinkedList_H
#define  CLinkedList_H

#include "CNode.h"

class CLinkedList{

private:

	CNode * pc_head;
	CNode * pc_tail;
	int i_listCounter;


	void v_prv_addFirstElem(void * pv_Elem);


	void v_prv_deleteData();


	CNode* pc_prv_nodeAtIndex(int i_Index);
	void v_prv_removeIfOneElem();

	void v_prv_copyOther( CLinkedList & c_Other); // do operatora przypisania i konstruktora kopiujacego 

	void v_prv_checkBounds(int i_Index, int& i_ErrorAppeard);


public:

	CNode* pc_getHead();


	CLinkedList();
	CLinkedList( CLinkedList & c_Other);
	~CLinkedList();

	void v_addFirst(void * pv_Elem);
	void v_addLast(void * pv_Elem);
	bool b_addOnIndex(void * pv_Elem, int i_Index);

	bool b_removeFirst();
	bool b_removeLast();
	bool b_removeFromIndex(int i_Index);


	bool b_isEmpty();
	int i_size();


	void * operator[]( int i_Index); 
	CLinkedList operator += ( void* pv_Elem);
	bool operator==(CLinkedList & c_OtherList);
	CLinkedList & operator=(CLinkedList & c_OtherList);

	CLinkedList* pc_clone();
	void ** pv_makeArray();
	int i_compare(CLinkedList *pcOtherList);
	int i_compare2(CLinkedList *pcOtherList);

	void v_push(void* pv_Elem);
	void* pv_top();
	void* pv_pop();

	void v_combination();
	











};





#endif
