#include "pch.h"
#include <string>
#include <vector>
#include <iostream>
#include "CNodeStatic.h"
#include <iterator>
using namespace std;


CNodeStatic::~CNodeStatic() 
{
}

void CNodeStatic::vAddNewChild() 
{
	CNodeStatic child;
	child.pc_parent_node = this;
	v_children.push_back(child);
}

CNodeStatic* CNodeStatic::pcGetChild(int iChildOffset)
{
	if (iChildOffset >= size(v_children)) return NULL;
	else return &v_children[iChildOffset];
}

void CNodeStatic::vPrintAllBelow()
{
	vPrint();
	for (int ii = 0; ii < size(v_children); ii++) 
	{

		v_children[ii].vPrintAllBelow();
	}
}

void CNodeStatic::vPrintUp()
{
	vPrint();
	if (pc_parent_node != NULL) pc_parent_node->vPrintUp();
}

void CNodeStatic::vAddNewChild(CNodeStatic& cNode) 
{
	cNode.pc_parent_node = this;
	v_children.push_back(cNode);
}

void CNodeStatic::vRemoveChild(CNodeStatic& cNode) 
{
	cNode.pc_parent_node = NULL;
	int iChildPosition = iGetChildPosition(cNode);
	v_children.erase(v_children.begin() + iChildPosition);
}

int CNodeStatic::iGetChildPosition(const CNodeStatic& cNode) 
{
	vector<CNodeStatic>::iterator it = find(v_children.begin(), v_children.end(), cNode);
	return distance(v_children.begin(), it);

}

bool CNodeStatic::operator==(const CNodeStatic& cNodeStatic) 
{
	return i_val == cNodeStatic.i_val;
}