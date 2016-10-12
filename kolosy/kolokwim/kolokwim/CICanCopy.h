#pragma once
#include "stdafx.h"
#include <string>	
using namespace std;

class CICanCopy {
public:
	CICanCopy() { ps_data = new string(""); }
	CICanCopy(string s_data) { ps_data = new string(s_data); }
	CICanCopy(CICanCopy & c_data);
	~CICanCopy();
	void operator= (string s_newData);
	void operator= (CICanCopy &c_data);
	CICanCopy cConcatenate(CICanCopy* c_data);
	string sGetData() { return *ps_data; }
	void vClearData();

private:
	string *ps_data;
};