#include "stdafx.h"
#include "CICanCopy.h"
#include <string>

CICanCopy::CICanCopy(CICanCopy & c_data)
{
	ps_data = new string(*(c_data.ps_data));
}

CICanCopy::~CICanCopy()
{
	delete ps_data;
}

void CICanCopy::operator=(string s_newData)
{
	vClearData();
	ps_data = new string(s_newData);
}

void CICanCopy::operator=(CICanCopy & c_data)
{
	vClearData();
	ps_data = new string (*(c_data).ps_data);
}

CICanCopy CICanCopy::cConcatenate(CICanCopy* c_data)
{
	return CICanCopy(*ps_data + (*c_data->ps_data));
}

void CICanCopy::vClearData()
{
	if (ps_data != NULL)
		delete ps_data;
}
