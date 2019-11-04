#include <string>

using namespace std;

class CTable {
public:

	static const string DEFAULT_NAME;
	static const int DEFAULT_LENGTH;


	CTable();
	CTable(string sName, int iTableLen);
	CTable(const CTable &pcOther);
	// ~CTable();
	CTable* pcClone();
	void vSetName(string sName);
	bool bSetNewSize(int iTableLen);
	int i_getLength();
	string s_getName();
	//***
	void vSetValues();
	void vPrint();
	void vSetValueAt(int iOffset, int iNewVal);

	//CTable operator+(CTable & pcNewTable);

	CTable operator+(const CTable& pcNewTable);

	

	

private:
	string s_name;
	int i_tab_length;
	int *pi_Tab;

};