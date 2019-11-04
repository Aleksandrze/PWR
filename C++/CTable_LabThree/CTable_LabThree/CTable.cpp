
#include "pch.h"
#include "CTable.h"
#include <iostream>
#include <string>
#include <cstring>
#include <array>

using namespace std;

const string CTable::DEFAULT_NAME = "Default";
const int CTable::DEFAULT_LENGTH = 5;


CTable::CTable()
{
	s_name = DEFAULT_NAME;
	i_tab_length = DEFAULT_LENGTH;
	pi_Tab = new int[i_tab_length];
//	cout << "bezp: " << s_name << endl;
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

	pi_Tab = new int[i_tab_length];
	memcpy(pi_Tab, pcOther.pi_Tab, pcOther.i_tab_length);
	cout << "kopiuj: " << s_name << endl;
}

/*CTable::~CTable()
{
	delete[] pi_Tab;
	cout << "usuwam: " << s_name << endl;
}
*/

void CTable::vSetName(string sName)
{
	s_name = sName;
}

bool CTable::bSetNewSize(int iTableLen)
{
	if (i_tab_length != iTableLen && iTableLen > 0)
	{
		int *pi_newTab = new int[iTableLen];
		memcpy(pi_Tab, pi_newTab, iTableLen);
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





void CTable::vSetValues() {
	for (int ii = 0; ii < i_tab_length; ii++) {
		pi_Tab[ii] = rand() % 10;
	}
	cout << endl;
}


void CTable::vPrint() {
	for (int ii = 0; ii < i_tab_length; ii++) {
		cout << pi_Tab[ii] << " ";
	}
	cout << endl;
}


void CTable::vSetValueAt(int iOffset, int iNewVal) 
{
	if (iOffset < 0 || iOffset >= i_tab_length) {
		cout << "Index > length tab or Index < 0" << endl;
	}
	else {
		pi_Tab[iOffset] = iNewVal;
	}
}

/*
// Kontekunacja dwoch tablic przez operator +
CTable CTable::operator+(CTable& pcNewTable) {

	CTable temp;

	int lengthNewTemp = i_tab_length + pcNewTable.i_tab_length;

	temp.i_tab_length = lengthNewTemp;
	temp.pi_Tab = new int[lengthNewTemp];

	memcpy(temp.pi_Tab, pi_Tab, i_tab_length * sizeof(int));
	memcpy(temp.pi_Tab + i_tab_length, pcNewTable.pi_Tab, pcNewTable.i_tab_length * sizeof(int));


	temp.vPrint();
	return temp;
}
*/

// dodowanie tablic do siebie przez operato +
CTable CTable::operator+(const CTable& pcNewTable) {

	CTable temp;

	int length_new_temp_max = max(i_tab_length, pcNewTable.i_tab_length);

	temp.i_tab_length = length_new_temp_max;
	temp.pi_Tab = new int[length_new_temp_max];

	int lengthMin = min(i_tab_length, pcNewTable.i_tab_length);

	int* maxTable = i_tab_length > pcNewTable.i_tab_length ? pi_Tab : pcNewTable.pi_Tab;
	int* minTable = i_tab_length < pcNewTable.i_tab_length ? pi_Tab : pcNewTable.pi_Tab;

	memcpy(temp.pi_Tab, maxTable, length_new_temp_max * sizeof(int));

	for (int ii = 0; ii < lengthMin; ii++) {
		temp.pi_Tab[ii] += minTable[ii];
	}


	temp.vPrint();
	return temp;
}



int main() {
	
/*	cout << "Static tables creating" << endl;
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
	cout << "Original version tab: " << "Name: " + d_tab_default->s_getName() << "; Size: " << d_tab_default->i_getLength() << endl;
	cout << "Info clone tab version: " << "Name: " + d_tab_default_copy->s_getName() << "; Size: " << d_tab_default_copy->i_getLength() << endl;
	
	
	cout << endl;
	cout << "Test revers tab"<<endl;
	s_tab_default.vSetValues();
	s_tab_default.vPrint();
	
	cout << endl;
	cout << "Deleting" << endl;
	delete d_tab_default;
	delete d_tab_default_copy;
	delete d_tab_params;

*/
	
	cout << endl;
	cout << "Start lista 3"<<endl;
	CTable c_tab_0, c_tab_1;
	cout << endl;
	cout<<"B set new size"<<endl;
	c_tab_0.bSetNewSize(6);
	c_tab_1.bSetNewSize(4);
	
	cout << "B set values in tab" << endl;
	c_tab_0.vSetValues();
	c_tab_1.vSetValues();

	cout << "Print" << endl;
	c_tab_0.vPrint();
	c_tab_1.vPrint();

	/*
	c_tab_0 = c_tab_1;
	cout << "Set values At tab" << endl;
	c_tab_1.vSetValueAt(2, 12);
	c_tab_0.vSetValueAt(0, 99);

	cout << endl;
	cout << "Print" << endl;
	c_tab_0.vPrint();
	c_tab_1.vPrint();
	*/

	cout << endl;
	cout << "Operator +" << endl;
	CTable c_tab_3;
	c_tab_3 = c_tab_0 + c_tab_1;



}


