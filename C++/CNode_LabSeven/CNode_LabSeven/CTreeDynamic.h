#pragma once
#include "pch.h"
#include "CNodeDynamic.h"

class CTreeDynamic
{
public:
	CTreeDynamic();
	~CTreeDynamic();

	CNodeDynamic* pcGetRoot() { return(pc_root); }
	void vPrintTree();

	bool bMoveSubtree(CNodeDynamic* pcParentNode, CNodeDynamic* pcNewChildNode);

private:

	CNodeDynamic* pc_root;
};