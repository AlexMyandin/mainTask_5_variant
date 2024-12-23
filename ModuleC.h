#pragma once
#include "ObjectC.h"
#include <vector>
using namespace std;
class ModuleC
{
public:
	ModuleC();
	ModuleC(vector<ObjectC> list_objC);
	vector<ObjectC> getData();
	void setData(vector<ObjectC> list_objC);
private:
	vector<ObjectC> m_list_objC;
};

