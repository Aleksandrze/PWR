#include "pch.h"
#include "CNodeDynamic.h"
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;


CNodeDynamic::~CNodeDynamic()
{
	for (int ii = 0; ii < size(v_children); ++ii) {
		cout << "\nUsuwam " << pcGetChild(ii)->i_val;
		delete pcGetChild(ii);
	}
}

void CNodeDynamic::vAddNewChild()
{
	CNodeDynamic *child = new CNodeDynamic;
	child->pc_parent_node = this;
	v_children.push_back(child);
}


void CNodeDynamic::vAddNewChild(CNodeDynamic* cNode)
{
	cNode->pc_parent_node = this;
	v_children.push_back(cNode);
}

CNodeDynamic* CNodeDynamic::pcGetChild(int iChildOffset)
{
	if (iChildOffset >= size(v_children)) return NULL;
	else return v_children[iChildOffset];
}

void CNodeDynamic::vPrintAllBelow()
{
	vPrint();
	for (int ii = 0; ii < size(v_children); ii++)
	{
		v_children[ii]->vPrintAllBelow();
	}
}

void CNodeDynamic::vRemoveChild(CNodeDynamic* cNode)
{
	cNode->pc_parent_node = NULL;
	int iPosition = iGetChildPosition(cNode);
	v_children.erase(v_children.begin() + iPosition);
}

int CNodeDynamic::iGetChildPosition(const CNodeDynamic* cNode)
{
	vector<CNodeDynamic*>::iterator it = find(v_children.begin(), v_children.end(), cNode);
	if (it != v_children.end())
		return distance(v_children.begin(), it);
	return -1;
}

bool CNodeDynamic::operator==(const CNodeDynamic* cNodeDynamic)
{
	return i_val == cNodeDynamic->i_val;
}
