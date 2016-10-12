#ifndef CNode_h
#define CNode_h

#include <string>
#include <iostream>
#include <vector>
#include <cstdio>


using namespace std;




class CNode{

private:

	vector <CNode*> children;
	string s_name;


public:


	CNode();
	CNode(string s_Name);
	~CNode();



	void v_setName(string nazwa);
	string s_getName();

	int i_howManyChildren();
	bool b_hasChild();
	CNode * pc_addChild(string Name);

	void v_print(int depth, string );





};









#endif