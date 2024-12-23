#include "ModuleC.h"

ModuleC::ModuleC() {};
ModuleC::ModuleC(vector<ObjectC> list_objC) : m_list_objC(list_objC){};
vector<ObjectC> ModuleC::getData() { return m_list_objC; };
void ModuleC::setData(vector<ObjectC> list_objC) { m_list_objC = list_objC; };