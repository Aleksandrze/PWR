#define _CRT_SECURE_NO_DEPRECATE
#include "pch.h"
#include <iostream>
#include<fstream>
#include "CFileLastError.h"
#include "CFileThrowEx.h"
#include "CFileErrCode.h"

using namespace std;
FILE *pf_file = NULL;

void create(string sFileName)
{
	pf_file = fopen(&sFileName[0], "w+");

}

int main() {

	CFileLastError LastError("CFileLastError.txt");
	CFileThrowEx ThrowEx("CFileThrowEx.txt");
	CFileErrCode ErrorCode("CFileErrorCode.txt");


	ofstream zapisz("dane.txt");
	

	for (int ii = 0; ii < 10; ii++) {
	//	cout << ii;
	//	LastError.vOpenFile("CFileLastError.txt");
	//	cout <<" "<< LastError.bGetLastError() << endl;
		int temp = LastError.bGetLastError();
		zapisz << ii << "  " << temp << "\n";
	}

	cout << "==================" << endl;
	zapisz << "=========="<<"\n";

	for (int ii = 0; ii < 10; ii++) {
	// cout << ii;
	//cout <<" "<< ErrorCode.bOpenFile("CFileErrorCode.txt")<<endl;
	int temp= ErrorCode.bOpenFile("CFileErrorCode.txt");
	zapisz << ii << "  " << temp<< "\n";
		
	}

	cout << "==================" << endl;

	for (int ii = 0; ii < 10; ii++) {
		ThrowEx.vOpenFile("CFileThrowEx.txt");
	}

}