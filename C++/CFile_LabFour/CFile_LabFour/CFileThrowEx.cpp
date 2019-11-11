#define _CRT_SECURE_NO_DEPRECATE
#include "pch.h"
#include "CFileThrowEx.h"
#include <iostream> 
#include <string>
#include <vector>


using namespace std;

CFileThrowEx::CFileThrowEx() 
{
	
}

CFileThrowEx::CFileThrowEx(string sFileName)
{
	pf_file = fopen(&sFileName[0], "w+");
}

CFileThrowEx::~CFileThrowEx() 
{
	if (pf_file != NULL)
	{
		fclose(pf_file);
	}
}


void CFileThrowEx::vOpenFile(string sFileName)
{
	pf_file = fopen(&sFileName[0], "w+");
	try {

		if (pf_file == NULL) {
			cout << "e";
			throw 1;
		}

	}
	catch (int e) {
		cout << "An exception # " << e << endl;
	}
}

void CFileThrowEx::vCloseFile()
{
	if (pf_file != NULL)
	{
		fclose(pf_file);
	}

	try {
		if (pf_file != NULL) throw 1;
	}
	catch (int e) {
		cout << "An exception # " << e << endl;
	}
}

void CFileThrowEx::vPrintLine(string sText) 
{

	try {

		if (pf_file == NULL) {
			throw 1;
		}
		fprintf(pf_file, &sText[0]);
	}
	catch (int e) {
	}


}

void CFileThrowEx::vPrintManyLines(vector<string> sText)
{
	try {

		if (pf_file == NULL) {
			throw 1;
		}
		for (string v : sText) {
			vPrintLine(v + " ");
		}
	}
	catch (int e) {
	}
}


