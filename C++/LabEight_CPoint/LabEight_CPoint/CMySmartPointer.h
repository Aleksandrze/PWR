#pragma once
#include "CRefCounter.h"

#include <iostream>
#include <cstdlib>
using namespace std;

template<typename T> class CMySmartPointer
{
public:
	T& operator*() { return(*pc_pointer); }
	T* operator->() { return(pc_pointer); }

	CMySmartPointer(T *pcPointer) {
		pc_pointer = pcPointer;
		pc_counter = new CRefCounter();
		pc_counter->iAdd();
		cout << "Create construcor for: " << *pc_pointer << endl;
	}

	CMySmartPointer(const CMySmartPointer &pcOther) {
		pc_pointer = pcOther.pc_pointer;
		pc_counter = pcOther.pc_counter;
		pc_counter->iAdd();
	}

	~CMySmartPointer() {
		if (pc_counter->iDec() == 0)
		{
			cout << "~ dla " << *pc_pointer << endl;
			delete pc_pointer;
			delete pc_counter;
		}
	}

	CMySmartPointer<T>& operator=(const CMySmartPointer &pcOther)
	{
		if (pc_counter->iDec() == 0) {
			cout << "Usuwamy stare: " << *pc_pointer << endl;
			delete pc_pointer;
			delete pc_counter;
		}

		pc_pointer = pcOther.pc_pointer;
		pc_counter = pcOther.pc_counter;
		pc_counter->iAdd();

		return *this;
	}

private:
	CRefCounter *pc_counter;
	T *pc_pointer;
};

