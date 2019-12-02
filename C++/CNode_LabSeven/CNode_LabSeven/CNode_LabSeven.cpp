#include "pch.h"
#include <string>
#include <vector>
#include <iostream>
#include "CNodeStatic.h"
#include "CTreeStatic.h"
#include "Dynamic_lab7.h"

using namespace std;



void v_tree_test3()
{
	cout << "CTreeDynamic" << endl;

	CTreeDynamic<double> *c_tree = new CTreeDynamic<double>();

	cout << "Drzewo double" << endl;
	c_tree->pcGetRoot()->vAddNewChild();
	c_tree->pcGetRoot()->vAddNewChild();
	c_tree->pcGetRoot()->pcGetChild(0)->vSetValue(1);
	c_tree->pcGetRoot()->pcGetChild(1)->vSetValue(2);
	c_tree->pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree->pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(1.1);
	c_tree->pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(1.2);
	c_tree->pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_tree->pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_tree->pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(2.1);
	c_tree->pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(2.2);

	c_tree->vPrintTree();


	cout << endl << endl;

	cout << "\n";
	cout << "Drzewo Char" << endl;
	CTreeDynamic<char> *c_tree_2 = new CTreeDynamic<char>();
	c_tree_2->pcGetRoot()->vAddNewChild();
	c_tree_2->pcGetRoot()->vAddNewChild();
	c_tree_2->pcGetRoot()->pcGetChild(0)->vSetValue('s');
	c_tree_2->pcGetRoot()->pcGetChild(1)->vSetValue('a');
	c_tree_2->pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree_2->pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree_2->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue('y');
	c_tree_2->pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue('d');
	c_tree_2->pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_tree_2->pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_tree_2->pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue('d');
	c_tree_2->pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue('g');
	
	c_tree_2->vPrintTree();

	cout << "\nNumber Double: ";
	cout << c_tree->i_count() << "\n";

	cout << "\nNumber Char: ";
	cout << c_tree_2->i_count() << "\n";


}

void v_tree_test4()
{
	cout << "CNodeDynamic\n" << endl;

	CNodeDynamic<double> *c_root = new CNodeDynamic<double>();
	c_root->vAddNewChild();
	c_root->vAddNewChild();
	c_root->pcGetChild(0)->vSetValue(1);
	c_root->pcGetChild(1)->vSetValue(2);
	c_root->pcGetChild(0)->vAddNewChild();
	c_root->pcGetChild(0)->vAddNewChild();
	c_root->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	c_root->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
	c_root->pcGetChild(1)->vAddNewChild();
	c_root->pcGetChild(1)->vAddNewChild();
	c_root->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	c_root->pcGetChild(1)->pcGetChild(1)->vSetValue(22);



	cout << "Drzewo:" << endl;
	c_root->vPrintAllBelow();
	//	cout << "\nPrint up for 0:" << endl;
	//	c_root->pcGetChild(0)->pcGetChild(1)->vPrint();
	cout << endl;


}


int main()
{
	v_tree_test3();
	cout << "\n===========================" << endl;
	v_tree_test4();
	cout << "\n===========================" << endl;
	return 0;

}