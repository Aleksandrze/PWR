#include "pch.h"
#include "CMySmartPointer.h"
#include "CRefCounter.h"
#include <iostream>


using namespace std;

int main() {

	CMySmartPointer<int> p_1(new int(1));
	CMySmartPointer<int> p_2(new int(3));

	CMySmartPointer<double> p_3(new double(19.55));
	CMySmartPointer<double> p_4(new double(20.88));


	p_1 = p_2;
	std::cout << *p_1 << std::endl;


	p_3 = p_4;
	std::cout << *p_3 << std::endl;



	return 0;
}