#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
class ModuleA
{
public:
	ModuleA(string path);

	vector<string> getDataInFile();
	string getPath();

	void setPath(string path);
private:
	string m_path;
};

