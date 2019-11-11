#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

class CFileThrowEx
{
public:

	CFileThrowEx();
	CFileThrowEx(string sFileName);
	~CFileThrowEx();

	void vOpenFile(string sFileName);
	void vCloseFile();
	void vPrintLine(string sText);
	void vPrintManyLines(vector<string> sText);

private:
	FILE *pf_file = NULL;

};