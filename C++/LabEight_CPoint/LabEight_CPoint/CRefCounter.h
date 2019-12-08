#pragma once
#include <iostream>
using namespace std;
class CRefCounter
{
public:
	CRefCounter();
	int iAdd();
	int iDec();
	int iGet();

private:
	int i_count;
};

CRefCounter::CRefCounter()
{
	i_count = 0;
}
int CRefCounter::iAdd()
{
	return ++i_count;
}
int CRefCounter::iDec()
{
	return --i_count;
}
int CRefCounter::iGet()
{
	return i_count;
}
