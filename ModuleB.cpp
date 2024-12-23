#include "ModuleB.h"


ModuleB::ModuleB() {};
ModuleB::ModuleB(vector<map<string, string>> data) :
	m_data(data) {};
vector<map<string, string>> ModuleB::getData() {
	return m_data;
};
void ModuleB::setData(vector<map<string, string>> data) { m_data = data; };