#include "CTree.h"



int main(){



	cout << "witam w programie" << endl;


	CTree tree0, tree1;
	CNode *root, *node;

	

	root = tree0.pc_getRoot();
	root->v_setName("root");

	node = root->pc_addChild("X");
	node->pc_addChild("XChild0");
	node->pc_addChild("XChild1");
	
	
	node = root->pc_addChild("Y");
	node->pc_addChild("YChild0");

	node = root->pc_addChild("Z");


	tree0.v_printTree();



	root = tree1.pc_getRoot();
	root->v_setName("root2");
	node = root->pc_addChild("XX");

	cout << endl << "przed duplicate " << endl;

	tree1.v_printTree();


	cout << endl << " po duplicate" << endl;



	
	tree1.v_duplicateTree(tree0);

	cout << "TREEE 0" << endl;
	tree0.v_printTree();
	cout << "TREE 1" << endl;
	tree1.v_printTree();
	cout << endl;//wykonanie vPrint wyprowadzi na ekran nastêpuj¹cy napis
	
	/*
	c_tree_0.vDuplicateTo(&c_tree_1));// po wykonaniu tej komendy drzewo c_tree_1 jest
	identyczne jak c_tree_0;
	*/










	cin.ignore();
	getchar();
	return 0;
}