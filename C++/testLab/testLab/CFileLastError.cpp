#define _CRT_SECURE_NO_DEPRECATE
#include "pch.h"
#include "CFileLastError.h"
#include <iostream> 
#include <string>
#include <vector>

using namespace std;


CFileLastError::CFileLastError() 
{
	b_last_error = false;
	pf_file = NULL;
}

CFileLastError::CFileLastError(string sFileName) 
{
	b_last_error = false;
	pf_file = fopen(&sFileName[0], "w+");
	if (pf_file != NULL)
	{
		b_last_error = true;
	}

}

CFileLastError::~CFileLastError()
{
	if (pf_file != NULL)
	{
		fclose(pf_file);
	}
}


void CFileLastError::vOpenFile(string sFileName) 
{
	b_last_error = false;
	if (pf_file != NULL) {
		b_last_error = true;
	}
	pf_file = fopen(&sFileName[0], "w+");

}

void CFileLastError::vCloseFile() 
{
	b_last_error = false;
	if (pf_file != NULL)
	{
		fclose(pf_file);
	}
	if (pf_file == NULL)
	{
		b_last_error = true;
	}
}

void CFileLastError::vPrintFile(string sText)
{
	b_last_error = false;
	if (pf_file == NULL) 
	{
		b_last_error = true;
	}
	else 
	{
		fprintf(pf_file, &sText[0]);
	}
}

void CFileLastError::vPrintManyLines(vector<string> sText)
{
	for (string v : sText) {
		vPrintFile(v + "\n");
	}
}

