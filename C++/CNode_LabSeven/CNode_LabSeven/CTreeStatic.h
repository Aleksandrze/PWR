#pragma once
#include "pch.h"
#include "CNodeStatic.h"

class CTreeStatic
{
public:
	CTreeStatic();
	~CTreeStatic();

	CNodeStatic* pcGetRoot() { return(&c_root); }
	void vPrintTree();
	bool bMoveSubTree(CNodeStatic* pcParentNode, CNodeStatic* pcNewChildNode);

private:

	CNodeStatic c_root;
};
