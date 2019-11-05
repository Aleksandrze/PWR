#include <string>
#include <vector>
#pragma once
#define _CRT_SECURE_NO_DEPRECATE


using namespace std;

class CFileErrCode
{

public:
	CFileErrCode();
	CFileErrCode(string sFileName);
	~CFileErrCode();

	bool bOpenFile(string sFileName);
	bool bCloseFile();
	bool bPrintLine(string sText);
	bool bPrintManyLines(vector<string> sText);

private:

	FILE *pf_file;

};