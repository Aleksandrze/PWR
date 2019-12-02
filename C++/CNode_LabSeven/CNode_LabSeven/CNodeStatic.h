#pragma once
#include <string>
#include "pch.h"
#include <vector>
#include <iostream>
using namespace std;

class CNodeStatic
{
public:
	CNodeStatic() { i_val = 0; pc_parent_node = NULL; };
	~CNodeStatic();
	void vSetValue(int iNewVal) { i_val = iNewVal; };

	int iGetChildrenNumber() { return(v_children.size()); };
	void vAddNewChild();

	void vAddNewChild(CNodeStatic& cNode);
	void vRemoveChild(CNodeStatic& cNode);

	int iGetChildPosition(const CNodeStatic& cNode);

	CNodeStatic* pcGetChild(int iChildOffset);
	CNodeStatic* pcGetParent() { return pc_parent_node; };

	void vPrint() { cout << " " << i_val; };

	void vPrintAllBelow();
	void vPrintUp();
	bool operator==(const CNodeStatic& cNodeStatic);
private:
	vector<CNodeStatic> v_children;
	CNodeStatic* pc_parent_node;
	int i_val;
};//class CNodeStatic 
