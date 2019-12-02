#include "pch.h"
#include "CTreeDynamic.h"
CTreeDynamic::CTreeDynamic() {
	pc_root = new CNodeDynamic();
}
CTreeDynamic::~CTreeDynamic() {
	delete pc_root;
}
void CTreeDynamic::vPrintTree() {
	pc_root->vPrintAllBelow();
}

bool CTreeDynamic::bMoveSubtree(CNodeDynamic* pcParentNode, CNodeDynamic* pcNewChildNode) {
	if (pcParentNode != NULL && pcNewChildNode != NULL) {
		CNodeDynamic* pc_parent = pcNewChildNode->pcGetParent();
		pcParentNode->vAddNewChild(pcNewChildNode);
		pc_parent->vRemoveChild(pcNewChildNode);
		return true;
	}
	return false;
}