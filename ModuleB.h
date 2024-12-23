#pragma once
#include <string>
#include <vector>
#include <map>
using namespace std;
class ModuleB
{
public:
	ModuleB();
	ModuleB(vector<map<string, string>> data);
	vector<map<string, string>> getData();
	void setData(vector<map<string, string>> data);
private:
	vector<map<string, string>> m_data;
};

