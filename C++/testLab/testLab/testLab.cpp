#define _CRT_SECURE_NO_DEPRECATE
#include "pch.h"
#include <iostream>
#include "CFileLastError.h"
#include "CFileThrowEx.h"
#include "CFileErrCode.h"

using namespace std;

int main() {
	CFileLastError test("CFileLastError.txt");
	CFileThrowEx test1("CFileThrowEx.txt");
	CFileErrCode test2("CFileErrorCode.txt");

	vector<string> v_s_temp = { "Zadanie", "testowe", "nr", "0001", "!j" };
	test.vPrintManyLines(v_s_temp);
	test1.vPrintManyLines(v_s_temp);
	

	string common_txt_file = "AllTheErrors.txt";

	for (int ii = 0; ii < 10; ii++) {
		cout << ii;
		test.vOpenFile("CFileLastError.txt");
	
	}
	
}