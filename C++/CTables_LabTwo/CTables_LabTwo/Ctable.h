#include <string>

using namespace std;

class CTable {
public:

	static const string DEFAULT_NAME;
	static const int DEFAULT_LENGTH;

	CTable();
	CTable(string sName, int iTableLen);
	CTable(const CTable &pcOther);
	~CTable();
	CTable* pcClone();
	void vSetName(string sName);
	bool bSetNewSize(int iTableLen);


	int i_getLength();
	string s_getName();
	


private:
	string s_name;
	int i_tab_length;
	int *pi_Tab;
};