#pragma once
#include<vector>
#include<cstdlib>
#include<iostream>
#define COUNT 10
using namespace std;

template<typename T>
class CNodeDynamic
{

public:

	void vSetValue(T iNewVal) { i_val = iNewVal; }
	int iGetChildrenNumber() { return (v_children.size()); }
	void vPrint() { cout << "-"<< i_val << " "; }




	CNodeDynamic()
	{
		i_val = T();
		pc_parent_node = NULL;
	}


	~CNodeDynamic()
	{
		for (int ii = 0; ii < iGetChildrenNumber(); ii++) {
			cout << "\nUsuwam " << pcGetChild(ii)->i_val;
			delete v_children[ii];
		}
	}


	void vAddNewChild()
	{
		CNodeDynamic* child = new CNodeDynamic();
		child->pc_parent_node = this;
		v_children.push_back(child);
	}


	void vAddNewChild(T iVal)
	{
		CNodeDynamic* child = new CNodeDynamic();
		child->vSetValue(iVal);
		child->pc_parent_node = this;
		v_children.push_back(child);
	}

	void vAddNewChild(CNodeDynamic* pc_new_child) {
		pc_new_child->pc_parent_node = this;
		v_children.push_back(pc_new_child);
	}

	CNodeDynamic* pcGetChild(int iChildOffset)
	{
		if (iGetChildrenNumber() <= iChildOffset || 0 > iChildOffset) return NULL;
		else return v_children.at(iChildOffset);
	}



	void vPrintUp() {
		vPrint();
		if (pc_parent_node != NULL)
			pc_parent_node->vPrintUp();
	}


	void vRemoveChild() {

		int i_count = 0;
		while (i_count != pc_parent_node->v_children.size()) {
			if (pc_parent_node->v_children[i_count] == this) {
				pc_parent_node->v_children.erase(pc_parent_node->v_children.begin() + i_count);
			}
			i_count++;
		}
	}

	void vRemoveChild(CNodeDynamic* cNode)
	{
		cNode->pc_parent_node = NULL;
		int iPosition = iGetChildPosition(cNode);
		v_children.erase(v_children.begin() + iPosition);
	}


	//==============================
	/*void CNodeDynamic<T>::vPrintSubtreePretty(int depth) {
		if (v_children.size() == 0) {
			printSpacecs(depth * 10);
			cout << i_val << endl;
		}
		else {
			for (int i = 0; i < v_children.size(); i++) {
				if (i == v_children.size() / 2) {
					printSpacecs(depth * 10);
					cout << i_val << endl;
				}

				v_children.at(i)->vPrintSubtreePretty(depth + 1);
			}
		}
	}


	void printSpacecs(int times) {
		for (int i = 0; i < times; i++) {
			cout << " ";
		}
	}
	*/
	//===============================

	void vPrintAllBelow()
	{
		vPrint();
		for (int i = 0; i < iGetChildrenNumber(); i++) {
			v_children.at(i)->vPrintAllBelow();
			cout << endl;
		}
	}

//========================================
	int v_count_help() {
		int count = 1;
		for (int i = 0; i < iGetChildrenNumber(); i++) {
			count += v_children.at(i)->v_count_help();
		}
		return count;
	}

	int v_sum() {
		int count = i_val;
		for (int i = 0; i < iGetChildrenNumber(); i++) {
			count += v_children.at(i)->v_sum();
		}
		return count;
	}

	int i_get_value() {
		return i_val;
	}

// ===========================================


private:
	vector<CNodeDynamic<T>*> v_children;
	CNodeDynamic<T>* pc_parent_node;
	T i_val;

};

template<typename T>
class CTreeDynamic
{

public:
	CTreeDynamic() { pc_root = new CNodeDynamic<T>(); }
	~CTreeDynamic() { delete pc_root; }

	CNodeDynamic<T>* pcGetRoot() { return pc_root; }

	void vPrintTree() { pc_root->vPrintAllBelow(); }


	int i_count() { return(pc_root->v_count_help()); }



	bool bMoveSubtree(CNodeDynamic<T>* pcParentNode, CNodeDynamic<T>* pcNewChildNode) {
			pcNewChildNode->vRemoveChild();
			pcParentNode->vAddNewChild(pcNewChildNode);
			return true;
		
	}


private:
	CNodeDynamic<T>* pc_root;

};



