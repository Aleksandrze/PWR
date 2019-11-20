#include "pch.h"
#include "CTreeStatic.h"
CTreeStatic::CTreeStatic() 
{
}

CTreeStatic::~CTreeStatic() 
{
}

void CTreeStatic::vPrintTree() 
{
	c_root.vPrintAllBelow();
}

bool CTreeStatic::bMoveSubTree(CNodeStatic* pcParentNode, CNodeStatic* pcNewChildNode) 
{
	if (pcParentNode != NULL && pcNewChildNode != NULL)
	{
		CNodeStatic* pc_parent = pcNewChildNode->pcGetParent();
		pcParentNode->vAddNewChild(*pcNewChildNode);
		pc_parent->vRemoveChild(*pcNewChildNode);
		return true;
	}
	return false;
}
