#pragma once
#include <string>
#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class CNodeDynamic
{
public:
	CNodeDynamic() { i_val = 0; pc_parent_node = NULL; };
	~CNodeDynamic();
	void vSetValue(int iNewVal) { i_val = iNewVal; };

	int iGetChildrenNumber() { return(size(v_children)); };
	void vAddNewChild();
	CNodeDynamic* pcGetChild(int iChildOffset);

	void vAddNewChild(CNodeDynamic* cNode);

	void vPrint() { cout << " " << i_val; };
	void vPrintAllBelow();

	void vRemoveChild(CNodeDynamic* cNode);
	int iGetChildPosition(const CNodeDynamic* cNode);

	CNodeDynamic* pcGetParent() { return pc_parent_node; };
	bool operator==(const CNodeDynamic* cNodeDynamic);

private:

	vector<CNodeDynamic*> v_children;
	CNodeDynamic* pc_parent_node;
	int i_val;

};