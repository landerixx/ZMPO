#include "CNode.h"


CNode::CNode(){
	
}


CNode::CNode(string nazwa){

	this->s_name = nazwa;
}


CNode::~CNode(){

	int i_size = i_howManyChildren();
	if (b_hasChild()){

		for (int i = 0; i < i_size; i++){

			delete children[i];
			children[i] = NULL;
		}
		children.clear();
	}//if (b_hasChild)
}//CNode::~CNode()


void CNode::v_setName(string s_Nazwa){

	this->s_name = s_Nazwa;
}


string CNode::s_getName(){

	return s_name;
}





int CNode::i_howManyChildren(){

	return (int)children.size();
}

bool CNode::b_hasChild(){
	return children.size() == 0;
}

CNode * CNode::pc_addChild(string s_NameChild){

	CNode * pc_child = new CNode(s_NameChild);

	this->children.push_back(pc_child);

	return pc_child;

}

void CNode::v_print(int i_Depth, string s_Identation){

	cout << s_Identation  << i_Depth << " " << s_name << endl;
	i_Depth++;
	s_Identation += " ";
	int i_size = i_howManyChildren();
	for (int i = 0; i < i_size; i++)
		children[i]->v_print(i_Depth,s_Identation);

}