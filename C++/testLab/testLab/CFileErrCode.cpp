#define _CRT_SECURE_NO_DEPRECATE
#include "pch.h"
#include "CFileErrCode.h"



using namespace std;

CFileErrCode::CFileErrCode() 
{
	pf_file = NULL;
}

CFileErrCode::CFileErrCode(string sFileName) 
{
	pf_file = fopen(&sFileName[0], "w+");
}

CFileErrCode::~CFileErrCode()
{
	if (pf_file != NULL) {
		fclose(pf_file);
	}
}

bool CFileErrCode::bOpenFile(string sFileName) {

	pf_file = fopen(&sFileName[0], "w+");
	if (pf_file == NULL) return false;
	else return true;

}

bool CFileErrCode::bCloseFile() {
	if (pf_file != NULL)
	{
		fclose(pf_file);
	}
	if (pf_file == NULL)
	{
		return true;
	}
	else {
		return false;
	}
}

bool CFileErrCode::bPrintLine(string sText) {
	int iTemp = fprintf(pf_file, &sText[0]);
	if (iTemp < 0)
	{
		return false;
	}
	else {
		return true;
	}
}
// mod ????
bool CFileErrCode::bPrintManyLines(vector<string> sText) {
	if (pf_file == NULL) return false;

	for (int i = 0; i < sText.size(); i++) {
		fprintf(pf_file, (char*)&sText[i]);
	}

	return true;
}
