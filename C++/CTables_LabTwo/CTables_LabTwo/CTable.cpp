
#include "pch.h"
#include "CTable.h"
#include <iostream>

using namespace std;

const string CTable::DEFAULT_NAME = "Default";
const int CTable::DEFAULT_LENGTH = 5;


CTable::CTable()
{
	s_name = DEFAULT_NAME;
	i_tab_length = DEFAULT_LENGTH;
	pi_Tab = new int[i_tab_length];
	cout << "bezp: " << s_name << endl;
}

CTable::CTable(string sName, int iTabLength)
{
	s_name = sName;
	i_tab_length = iTabLength;
	pi_Tab = new int[i_tab_length];
	cout << "parametr: " << s_name << endl;
}

CTable::CTable(const CTable &pcOther)
{
	s_name = pcOther.s_name + "_copy";
	i_tab_length = pcOther.i_tab_length;
	pi_Tab = new int [i_tab_length];
	cout << "kopiuj: " << s_name << endl;
}

CTable::~CTable()
{
	delete[] pi_Tab;
	//pi_Tab = NULL;
	cout << "usuwam: " << s_name << endl;
}


bool CTable::bSetNewSize(int iTableLen)
{
	if (i_tab_length != iTableLen && iTableLen > 0)
	{
		int *pi_newTab = new int[iTableLen];
		delete[] pi_Tab;
		pi_Tab = pi_newTab;
		i_tab_length = iTableLen;
		return true;
	} 
	return false;
}

CTable* CTable::pcClone() {
	return new CTable(*this);
}

void CTable::vSetName(string sName)
{
	s_name = sName;
}


void v_mod_tab(CTable *pcTab, int iNewSize)
{
	pcTab->bSetNewSize(iNewSize);
}

void v_mod_tab(CTable cTab, int iNewSize)
{
	cTab.bSetNewSize(iNewSize);
}

int CTable::i_getLength() {
	return i_tab_length;
}

string CTable::s_getName() {
	return s_name;
}




int main() {
	cout << "Static tables creating" << endl;
	CTable s_tab_default;
	CTable s_tab_parametr("Tab size", 10);
	cout << endl;

	cout << "Dynamic tables creating" << endl;
	CTable* d_tab_default = new CTable();
	CTable* d_tab_params = new CTable("Dynamic tab", 20);
	cout << endl;

	cout << "v_mod_tab(s_tab_default)" << endl;
	v_mod_tab(s_tab_default, 20);
	cout << "New length s_tab_default : " << s_tab_default.i_getLength() << endl;
	cout << endl;

	cout << "v_mod_tab(d_tab_default)" << endl;
	v_mod_tab(d_tab_default, 20);
	cout << "New length d_tab_default : " << d_tab_default->i_getLength() << endl;
	cout << endl;

	cout << "pcClone d_tab_default" << endl;
	CTable* d_tab_default_copy = d_tab_default->pcClone();

	cout << endl;
	d_tab_default_copy->vSetName("Clone dynamic tab");
	d_tab_default_copy->bSetNewSize(88);
	cout << "Original version tab: " << "Name: " + d_tab_default->s_getName()<< "; Size: " << d_tab_default->i_getLength()<<endl;
	cout << "Info clone tab version: " << "Name: " + d_tab_default_copy->s_getName() << "; Size: "<<d_tab_default_copy->i_getLength() << endl;

	cout << endl;
	cout << "Deleting" << endl;
	delete d_tab_default;
	delete d_tab_default_copy;
	delete d_tab_params;
	
}


