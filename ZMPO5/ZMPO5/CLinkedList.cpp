#include "CLinkedList.h"


CLinkedList::CLinkedList(){

	this->i_listCounter = 0;
	pc_head = pc_tail = NULL;

}//CLinkedList::CLinkedList()


void CLinkedList::v_prv_copyOther( CLinkedList & c_Other){
	
	if (!c_Other.b_isEmpty()){

		CNode* pc_temp = c_Other.pc_head;

		while (pc_temp != NULL){

			void* pv_elem = pc_temp->pv_getElement();

			this->v_addLast(pv_elem);
			pc_temp = pc_temp->pc_getNext();
		}//while (pc_tempNext != NULL)

	}//if (!b_isEmpty())

	i_listCounter = c_Other.i_listCounter;
}//void CLinkedList::v_prv_copyOther(const CLinkedList & c_Other)


CLinkedList* CLinkedList::pc_clone(){

	CLinkedList* c_result=new CLinkedList;
	c_result->v_prv_copyOther(*this);
	
	return c_result;
}//CLinkedList CLinkedList::pc_clone()

CLinkedList::CLinkedList( CLinkedList & c_Other){

	this->i_listCounter = 0; // potrzebne!!! przy kopiowaniu (dodawanie elementu w copyOther, isEmpty zwracalo zla wartosc, wczesniej ListCounter mialo dowolna wartosc, randomowe cyfry z pamieci)
	v_prv_copyOther(c_Other);

}//CLinkedList::CLinkedList(const CLinkedList & c_Other)



CLinkedList::~CLinkedList(){
	//cout << "destruktor";
	v_prv_deleteData();

}//CLinkedList::~CLinkedList()

bool CLinkedList::b_isEmpty(){

	return i_listCounter == 0;

}//bool CLinkedList::b_isEmpty()

int CLinkedList::i_size(){

	return i_listCounter ;

}//int CLinkedList::i_size()




void CLinkedList::v_prv_deleteData(){

	if (pc_head != NULL){

		CNode *pc_temp=pc_head;
		CNode *pc_tempNext = pc_head->pc_getNext();
		
		while (pc_tempNext !=NULL){

			delete pc_temp;

			pc_temp = pc_tempNext;
			pc_tempNext = pc_temp->pc_getNext();

		}//while (pc_next !=NULL)

		delete pc_temp;

		pc_head = pc_tail = NULL;
		this->i_listCounter = 0;
	}//if (pc_head != NULL)
}//void CLinkedList::v_prv_deleteData()




void CLinkedList::v_addFirst(void * pv_Elem){

	if (b_isEmpty())
		v_prv_addFirstElem(pv_Elem);
	
	else{
		CNode* pc_Node = new CNode(pv_Elem);
		pc_head->v_setPrevious(pc_Node);
		pc_Node->v_setNext(pc_head);
		pc_head = pc_Node;
		i_listCounter++;
	}//else if (b_isEmpty())

}//void CLinkedList::v_addFirst(void * pv_Elem)


void CLinkedList::v_addLast(void * pv_Elem){

	if (b_isEmpty())
		v_prv_addFirstElem(pv_Elem);

	else{
		CNode* pc_Node = new CNode(pv_Elem);
		pc_tail->v_setNext(pc_Node);
		pc_Node->v_setPrevious(pc_tail);
		pc_tail = pc_Node;
		i_listCounter++;
	}//else if (b_isEmpty())

}//void CLinkedList::v_addLast(void * pv_Elem)


bool CLinkedList::b_addOnIndex(void * pv_Elem, int i_Index){

	bool b_successs =  (i_Index >= 0 && i_Index <= i_listCounter);

	if (b_successs){

		if (b_isEmpty())
			v_prv_addFirstElem(pv_Elem);

		else{

			if (i_Index == 0)

				v_addFirst(pv_Elem);

			else if (i_Index == (i_size()))

				v_addLast(pv_Elem);

			else{

				CNode* pc_temp = pc_prv_nodeAtIndex(i_Index);
				CNode* pc_newNode = new CNode(pv_Elem);

				pc_newNode->v_setNext(pc_temp);
				pc_newNode->v_setPrevious(pc_temp->pc_getPrevious());
				pc_temp->v_setPrevious(pc_newNode);

				pc_temp = pc_newNode->pc_getPrevious();
				pc_temp->v_setNext(pc_newNode);

				i_listCounter++;
			}//else if (i_Index == (i_size() - 1))
		}//else if (b_isEmpty())


	}//if (b_successs)

	return b_successs;

}//bool CLinkedList::b_addOnIndex(void * pv_Elem, int i_Index)



void CLinkedList::v_prv_addFirstElem(void * pv_Elem){

	
		pc_head = new CNode(pv_Elem);
		pc_tail = pc_head;
		i_listCounter++;

}//void CLinkedList::v_prv_addFirstElem(void * pv_Elem)


CNode* CLinkedList::pc_getHead(){

	return pc_head;
}



CLinkedList & CLinkedList::operator=(CLinkedList & c_OtherList){
	
	cout << "operator przypisania" << endl;

	if (this != &c_OtherList){

		v_prv_deleteData();
		v_prv_copyOther(c_OtherList);
	}//if (this != &other)
	return *this;

}//void CLinkedList::operator=(CLinkedList & cOtherList)

bool CLinkedList::operator==(CLinkedList & c_OtherList){

	bool b_success=true;

	if (this->i_size() != c_OtherList.i_size())
		b_success = false;

	else{

		for (int i = 0; i < i_size(); i++){

			if (pc_prv_nodeAtIndex(i)->pv_getElement() != c_OtherList.pc_prv_nodeAtIndex(i)->pv_getElement()){

				b_success = false;
				break;
			}//if (pc_prv_nodeAtIndex(i)->pv_getElement() != pc_OtherList->pc_prv_nodeAtIndex(i)->pv_getElement())
		}//for (int i = 0; i < i_size(); i++)

	}//if (this->i_size() != pc_OtherList->i_size())

	return b_success;


}//bool CLinkedList::operator==(CLinkedList * pcOtherList)


CLinkedList CLinkedList::operator += (void* pv_Elem){

	v_addLast(pv_Elem);
	return *this;


}//CLinkedList CLinkedList::operator += (void* pv_Elem)


void*  CLinkedList:: operator[]( int i_Index){

	int i_success;
	v_prv_checkBounds(i_Index, i_success);
	if (i_success == OUT_OF_RANGE)
		throw out_of_range("Index out of bounds exception");
	else
		return pc_prv_nodeAtIndex(i_Index)->pv_getElement();

}//void* & CLinkedList:: operator[](unsigned int i_Index)






CNode* CLinkedList::pc_prv_nodeAtIndex(int i_Index){ // index juz jest sprawdzony wczesniej = jest poprawny

	CNode * pc_temp = pc_head;
	int i_index = 0;
	while (i_index != i_Index){
		i_index++;
		pc_temp = pc_temp->pc_getNext();
	}
	return pc_temp;

}//CNode* CLinkedList::pc_prv_nodeAtIndex(int i_Index)


void CLinkedList::v_prv_checkBounds(int i_Index, int& i_ErrorAppeard){

	if (!(i_Index >= 0 && i_Index < i_listCounter))
		i_ErrorAppeard = OUT_OF_RANGE;
		
}//void CLinkedList::v_prv_checkBounds(int i_Index, int& i_ErrorAppeard)





bool CLinkedList::b_removeFirst(){

	bool b_success = !b_isEmpty();

	if (b_success){

		if (i_size() == 1){

			v_prv_removeIfOneElem();

		}//if (i_size() == 1)
		else{

			CNode* pc_temp = pc_head->pc_getNext();
			delete pc_head;
			pc_head = pc_temp;

			i_listCounter--;
		}//else if (i_size() == 1)
	}//if (b_success)

	return b_success;
}//bool CLinkedList::b_removeFirst()



bool CLinkedList::b_removeLast(){

	return pv_pop() != NULL;

}//bool CLinkedList::b_removeLast()




bool CLinkedList::b_removeFromIndex(int i_Index){

	bool b_success =  (i_Index >= 0 && i_Index < i_listCounter);

	if (b_success){

		if (i_Index == 0){

			b_removeFirst();

		}//if (i_Index == 0)
		else if (i_Index == (i_listCounter - 1)){

			b_removeLast();

		}//else if (i_Index == (i_listCounter - 1))
		else{

			delete pc_prv_nodeAtIndex(i_Index);  //destruktor nodea: jezeli ma on (this) nastepnik to: pc_next->v_setPrevious(this->pc_previous)
												 //oraz  jezeli ma on(this) poprzednik to: pc_previous->v_setNext(this->pc_next);			
			i_listCounter--;
		}//else else if (i_Index == (i_listCounter - 1))
	}//if (b_success)

	return b_success;
}//bool CLinkedList::b_removeFromIndex(int i_Index){




void CLinkedList::v_prv_removeIfOneElem(){ //size ==1 

	delete pc_head;
	pc_head = pc_tail = NULL;
	i_listCounter--;

}//void CLinkedList::v_prv_removeIfOneElem()



void CLinkedList::v_push(void* pv_Elem){

	v_addLast(pv_Elem);

}//void CLinkedList::v_push(void* pv_Elem)

void* CLinkedList::pv_top(){

	if (b_isEmpty())
		return NULL;
	else
		return pc_tail->pv_getElement();

}//void* CLinkedList::pv_top()


void* CLinkedList::pv_pop(){

	bool b_success = !b_isEmpty();
	void* pv_elem = NULL;

	if (b_success){

		pv_elem = pc_tail->pv_getElement();
		if (i_size() == 1){

			v_prv_removeIfOneElem();
		}//if (i_size() == 1)
		else{

			CNode* pc_temp = pc_tail->pc_getPrevious();
			delete pc_tail;
			pc_tail = pc_temp;
			i_listCounter--;
		}//else if (i_size() == 1)
	}//if (b_success)

	return pv_elem;

}//void* CLinkedList::pv_pop()


int CLinkedList::i_compare(CLinkedList *pc_OtherList){

	int i_counter = 0;

	if (!b_isEmpty() && !pc_OtherList->b_isEmpty()){

		CNode * pc_thisIter = pc_head;
		CNode* pc_otherIter = pc_OtherList->pc_head;

		

		while (pc_thisIter != NULL && pc_otherIter != NULL){

			void* pv_thisData = pc_thisIter->pv_getElement();
			void* pv_otherData = pc_otherIter->pv_getElement();

			pc_thisIter = pc_thisIter->pc_getNext();
			pc_otherIter = pc_otherIter->pc_getNext();

			if (pv_thisData == pv_otherData)
				i_counter++;

		}//	while (pc_thisIter != NULL && pc_otherIter != NULL)




	}//if (!b_isEmpty() && !pc_OtherList->b_isEmpty())



	return i_counter;

}//int CLinkedList::i_compare(CLinkedList *pcOtherList)




int CLinkedList::i_compare2(CLinkedList *pc_OtherList){

	int i_counter = 0;

	if (!b_isEmpty() && !pc_OtherList->b_isEmpty()){

		CNode * pc_thisIter = pc_head;
		CNode* pc_otherIter = pc_OtherList->pc_head;



		while (pc_thisIter != NULL){

			void* pv_thisData = pc_thisIter->pv_getElement();

			while (pc_otherIter != NULL){

				void* pv_otherData = pc_otherIter->pv_getElement();
				pc_otherIter = pc_otherIter->pc_getNext();

				if (pv_thisData == pv_otherData)
					i_counter++;

			}//while (pc_otherIter != NULL)

			 pc_otherIter = pc_OtherList->pc_head;
			 pc_thisIter = pc_thisIter->pc_getNext();

		}//while (pc_thisIter != NULL)


	}//if (!b_isEmpty() && !pc_OtherList->b_isEmpty())



	return i_counter;

}//int CLinkedList::i_compare(CLinkedList *pcOtherList)








void ** CLinkedList::pv_makeArray(){

	void ** pv_array = new void*[i_size()];

	if (b_isEmpty())
		return NULL;

	else{

		CNode* pc_temp = pc_head;
		int i_index = 0;
		while (i_index <i_size()){

			pv_array[i_index] = pc_temp->pv_getElement();
			pc_temp = pc_temp->pc_getNext();
			i_index++;
		}//while (i_index > 0)

	}//(b_isEmpty()
	return pv_array;

}//void ** CLinkedList::pv_makeArray()







//parzyste na poczatek nieparzyste na koniec
void CLinkedList::v_combination(){

	if (i_size()>1){ // jezeli jest wiecej niz 1 element

		CNode* pc_Iterator = pc_head;
		CNode* pc_oddIterator = pc_head->pc_getNext();
		CNode *pc_oddHead = new CNode(pc_oddIterator->pv_getElement());
		pc_oddIterator = pc_oddHead;
			
		CLinkedList* pc_List = new CLinkedList;
		void ** pv_array = this->pv_makeArray();

		for (int i = 0; i < i_size(); i++){

			if (i % 2 == 1){ //nieparzyste, i!=1 bo odd head juz jest
				if (i != 1){
					CNode * pc_newNode = new CNode(pc_Iterator->pv_getElement());

					pc_oddIterator->v_setNext(pc_newNode);
					pc_newNode->v_setPrevious(pc_oddIterator);

					pc_oddIterator = pc_newNode;
				}//if (i != 1)
			}//if (i % 2 == 1)
			else{ // parzyste

				pc_List->v_addLast(pc_Iterator->pv_getElement());

			}// else if (i % 2 == 1)

			pc_Iterator = pc_Iterator->pc_getNext();

		}//for (int i = 0; i < i_size(); i++)

		pc_List->pc_tail->v_setNext(pc_oddHead); // ogonowi parzystych nastepnik head nieparzystych
		pc_oddHead->v_setPrevious(pc_List->pc_tail); //headowi neiparzystych to  previous ogon parzystych
		pc_List->pc_tail = pc_oddIterator;  // ogon to ostatni odditerator
		pc_List->i_listCounter = i_size(); // tyle elementow ile jest w this liscie

		*this = *pc_List;

		delete pc_List;
		delete pv_array;
		
	}//	if (i_size()>1){ // jezeli jest wiecej niz 1 element

}//void CLinkedList::v_combination()