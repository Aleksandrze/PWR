#include "pch.h"
#include <string>
#include <vector>
#include <iostream>
#include "CNodeStatic.h"
#include "CTreeStatic.h"
#include "CNodeDynamic.h"
#include "CTreeDynamic.h"

using namespace std;

void v_tree_test()
{
	cout << "TreeStatic" << endl;

	CTreeStatic c_tree;

	cout << "Drzewo 1" << endl;
	c_tree.pcGetRoot()->vAddNewChild();
	c_tree.pcGetRoot()->vAddNewChild();
	c_tree.pcGetRoot()->pcGetChild(0)->vSetValue(1);
	c_tree.pcGetRoot()->pcGetChild(1)->vSetValue(2);
	c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
	c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

	c_tree.vPrintTree();
	

	cout << endl << endl;

	cout << "\n";
	cout << "Drzewo 2" << endl;
	CTreeStatic c_tree_2;
	c_tree_2.pcGetRoot()->vAddNewChild();
	c_tree_2.pcGetRoot()->vAddNewChild();
	c_tree_2.pcGetRoot()->pcGetChild(0)->vSetValue(7);
	c_tree_2.pcGetRoot()->pcGetChild(1)->vSetValue(9);
	c_tree_2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree_2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree_2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(99);
	c_tree_2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(101);
	c_tree_2.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_tree_2.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_tree_2.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(17);
	c_tree_2.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(15);

	c_tree_2.vPrintTree();

	cout << "\n\nMove";
	c_tree.bMoveSubTree(c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(1),c_tree_2.pcGetRoot()->pcGetChild(0));

	cout << endl << endl;

	c_tree.vPrintTree();

	cout << endl << endl;

	c_tree_2.vPrintTree();
//	cout << "\n\nGetRoot\n";
//	c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vPrintUp();
	cout << "\n";
}

void v_tree_test2() {
	cout << "\nNodeStatic" << endl;

	CNodeStatic  c_root;

	c_root.vAddNewChild();
	c_root.vAddNewChild();
	c_root.pcGetChild(0)->vSetValue(1);
	c_root.pcGetChild(1)->vSetValue(2);
	c_root.pcGetChild(0)->vAddNewChild();
	c_root.pcGetChild(0)->vAddNewChild();
	c_root.pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	c_root.pcGetChild(0)->pcGetChild(1)->vSetValue(12);
	c_root.pcGetChild(1)->vAddNewChild();
	c_root.pcGetChild(1)->vAddNewChild();
	c_root.pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	c_root.pcGetChild(1)->pcGetChild(1)->vSetValue(22);

	cout << "Drzewo:" << endl;
	c_root.vPrintAllBelow();
	cout << "\nPrint up for 0:" << endl;
	c_root.pcGetChild(0)->pcGetChild(1)->vPrintUp();
	cout << endl;
}

void v_tree_test3()
{
	cout << "CTreeDynamic" << endl;
	CTreeDynamic c_tree;

	cout << "Drzewo 1" << endl;
	c_tree.pcGetRoot()->vAddNewChild();
	c_tree.pcGetRoot()->vAddNewChild();
	c_tree.pcGetRoot()->pcGetChild(0)->vSetValue(1);
	c_tree.pcGetRoot()->pcGetChild(1)->vSetValue(2);
	c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
	c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

	c_tree.vPrintTree();


	cout << endl << endl;

	cout << "\n";
	cout << "Drzewo 2" << endl;
	CTreeDynamic c_tree_2;
	c_tree_2.pcGetRoot()->vAddNewChild();
	c_tree_2.pcGetRoot()->vAddNewChild();
	c_tree_2.pcGetRoot()->pcGetChild(0)->vSetValue(7);
	c_tree_2.pcGetRoot()->pcGetChild(1)->vSetValue(9);
	c_tree_2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree_2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree_2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(99);
	c_tree_2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(101);
	c_tree_2.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_tree_2.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_tree_2.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(17);
	c_tree_2.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(15);

	c_tree_2.vPrintTree();

	cout << "\n\nMove";
	c_tree.bMoveSubtree(c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(1), c_tree_2.pcGetRoot()->pcGetChild(0));

	cout << endl << endl;

	c_tree.vPrintTree();

	cout << endl << endl;

	c_tree_2.vPrintTree();
}

void v_tree_test4()
{
	cout << "CNodeDynamic" << endl;

	CNodeDynamic c_root;
	c_root.vAddNewChild();
	c_root.vAddNewChild();
	c_root.pcGetChild(0)->vSetValue(1);
	c_root.pcGetChild(1)->vSetValue(2);
	c_root.pcGetChild(0)->vAddNewChild();
	c_root.pcGetChild(0)->vAddNewChild();
	c_root.pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	c_root.pcGetChild(0)->pcGetChild(1)->vSetValue(12);
	c_root.pcGetChild(1)->vAddNewChild();
	c_root.pcGetChild(1)->vAddNewChild();
	c_root.pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	c_root.pcGetChild(1)->pcGetChild(1)->vSetValue(22);

	cout << "Drzewo:" << endl;
	c_root.vPrintAllBelow();
//	cout << "\nPrint up for 0:" << endl;
//	c_root.pcGetChild(0)->pcGetChild(1)->vPrint();
	cout << endl;
}


int main() 
{
	v_tree_test();
	cout <<"============================================================"<< endl;
	v_tree_test2();
	cout << "============================================================" << endl;
	v_tree_test3();
	cout << "\n============================================================" << endl;
	v_tree_test4();
	return 0;

}