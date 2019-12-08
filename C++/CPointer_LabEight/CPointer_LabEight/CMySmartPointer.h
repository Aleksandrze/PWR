#pragma once
#include "CRefCounter.h"
#include <iostream>
#include <cstdlib>
using namespace std;

template<typename T> class CMySmartPointer
{
public:

	CMySmartPointer(T *pcPointer) {
		pc_pointer = pcPointer;
		pc_counter = new CRefCounter();
		pc_counter->iAdd();
		cout << "i_c=" << pc_counter->iGet() << endl;

		cout << "Create : " << *pc_pointer << endl;
	}


	CMySmartPointer(const CMySmartPointer &pcOther) {
		pc_pointer = pcOther.pc_pointer;
		pc_counter = pcOther.pc_counter;
		pc_counter->iAdd();
	}


	~CMySmartPointer() {
		if (pc_counter->iDec() == 0)
		{
			cout << "Delite: " << *pc_pointer << endl;
			delete pc_pointer;
			delete pc_counter;
			

		}
	}

	T& operator*()
	{
		return(*pc_pointer);
	}

	T* operator->()
	{
		return pc_pointer;
	}

	
	CMySmartPointer<T>& operator=(const CMySmartPointer &pcOther)
	{
		if (pcOther.pc_pointer != pc_pointer) {
			if (pc_counter->iDec() == 0) {
				cout << "Delite old version: " << *pc_pointer << endl << endl;
				delete pc_pointer;
				delete pc_counter;
			}

			pc_pointer = pcOther.pc_pointer;
			pc_counter = pcOther.pc_counter;
			pc_counter->iAdd();
			cout << "i_c= " << pc_counter->iGet() << endl;
		}
			else {
				delete pc_counter;
				pc_counter = pcOther.pc_counter;
				pc_counter->iAdd();
				cout << "i_c= " << pc_counter->iGet() << endl;

			}
		
	

		return *this;
	}
	


private:
	T *pc_pointer;
	CRefCounter *pc_counter;
};



