#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

class CFileLastError
{
public:

	CFileLastError();
	CFileLastError(string sFileName);
	~CFileLastError();

	void vOpenFile(string sFileName);
	void vCloseFile();
	void vPrintFile(string sText);
	void vPrintManyLines(vector<string> sText);

	 bool bGetLastError() { return (b_last_error); }

private:
	 bool b_last_error;
	FILE *pf_file = NULL;

};