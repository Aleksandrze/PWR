

#include "pch.h"
#include "CMySmartPointer.h"
#include "CRefCounter.h"
#include <iostream>


int main()
{
	
	CMySmartPointer<int> p_1(new int(1));
	CMySmartPointer<int> p_2(new int(3));
	CMySmartPointer<int> p_t(new int(1));

	CMySmartPointer<double> p_3(new double(19.55));
	CMySmartPointer<double> p_4(new double(20.88));

	CMySmartPointer<char> p_5(new char('a'));
	CMySmartPointer<char> p_6(new char('c'));

	cout << endl;
	p_1 = p_2;
	std::cout <<"p_1 = "<< *p_1 << std::endl<<endl;


	p_3 = p_4;
	std::cout << "p_3 = " << *p_3 << std::endl<<endl;

	p_5 = p_6;
	std::cout << "p_5 = " << *p_5 << std::endl<<endl;

/*
	int static_val  = 5;
	CMySmartPointer<int> p_static(&static_val);
*/


}

