#include "CLinkedList.h"
#include "CNode.h"





template <class T>
void wypiszZListy(CLinkedList & lista)
{
	if (!lista.b_isEmpty())
	{
		T *temp;
		int size = lista.i_size();
		CNode *help = lista.pc_getHead();
		while (size > 0)
		{
			size--;
			temp = static_cast<T*>(help->pv_getElement());
			help = help->pc_getNext();
			cout << *temp << endl;
		}
	}
}




int main(){


	cout << "Hello world" << endl;

	CLinkedList lista;


	string *str1 = new string("andrzej");
	string *str2 = new string("benek");
	string *str3 = new string("cezar");
	string *str4 = new string("damian");
	string *str5 = new string("edek");
	string *str6 = new string("franek");
	string *str7 = new string("gienek");
	//cout << lista.b_isEmpty();

	
	lista += (str2);
	lista += (str3);
	lista.v_addLast(str5);
	lista.v_addFirst(str1);
	lista += (str4);
	lista.b_addOnIndex(str6,4);

	wypiszZListy<string>(lista);

	
	cout<< endl << *(static_cast<string*>(lista[0])) << endl << endl; // ok -> andrzej


	void ** array = lista.pv_makeArray();

	cout << "tablica" << endl;

	for (int i = 0; i < lista.i_size();i++){

		cout << *(static_cast<string*>(array[i])) << endl;
	}


	
	try{
		cout << *(static_cast<string*>(lista[-1])) << endl; // blad
	}
	catch (out_of_range e)
	{
		cout << e.what() << endl;
	}


	cout << "usuwam fst element z listy" << endl;

	lista.b_removeFirst();
	cout << endl;
	wypiszZListy<string>(lista);

	cout << "usuwam ostatni element z listy" << endl;

	lista.b_removeLast();
	cout << endl;
	wypiszZListy<string>(lista);

	cout << "usuwam  element z listy index 2" << endl;

	lista.b_removeFromIndex(2);
	cout << endl;
	cout << "Lista nr 1" << endl;
	wypiszZListy<string>(lista);


	CLinkedList* lista2 = lista.pc_clone();

	cout << "lista nr 2 cloned" << endl;
	wypiszZListy<string>(*lista2);

	cout << "lista nr 2 size: " << lista2->i_size() << endl;

	cout << "push gienek lista 2" << endl;
	lista2->v_push(str7);
	cout << "lista nr 2 cloned" << endl;
	wypiszZListy<string>(*lista2);

	cout << "top gienek lista 2" << endl;
	cout << *(static_cast<string*>(lista2->pv_top())) << endl; // 

	cout << "pop gienek lista 2" << endl;
	lista2->pv_pop();
	wypiszZListy<string>(*lista2);

	if (lista == *(lista.pc_clone()))
		cout << "lista == *(lista.pc_clone()" << endl;


	CLinkedList lista3;

	lista3 += (str2);
	lista3 += (str3);
	lista3.v_addLast(str5);
	lista3.v_addFirst(str1);
	lista3 += (str4);
	lista3.b_addOnIndex(str6, 4);
	lista3 += (str7);

	cout<< endl << "Lista nr 3:" << endl;

	wypiszZListy<string>(lista3);

	cout << endl << "Lista nr 3 po combination:" << endl;

	lista3.v_combination();

	wypiszZListy<string>(lista3);

	cout << "lista 3 size: " << lista3.i_size();
	cout << endl << lista3.i_compare(lista3.pc_clone());
	cout << endl << lista3.i_compare2(lista3.pc_clone());

	getchar();
	cin.ignore();
	return 0;
}