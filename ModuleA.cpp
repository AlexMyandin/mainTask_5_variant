#include "ModuleA.h"

ModuleA::ModuleA(string path): m_path(path) {};

vector<string> ModuleA::getDataInFile(){
    // Открытие файла для чтения
    ifstream infile(m_path);
    if (!infile.is_open()) {
        cerr << "Ошибка при открытии файла(Module A)" << endl;
        throw "Ошибка при открытии";
    }

    // Чтение файла построчно
    vector<string> AllData;
    string line;
    while (getline(infile, line)) {
        AllData.push_back(line);
    }
    return AllData;
};


string ModuleA::getPath() { return m_path; };

void ModuleA::setPath(string path) { m_path = path; };