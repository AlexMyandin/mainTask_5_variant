// mainTask_5_variant.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <Windows.h>


#include "ModuleA.h"
#include "ModuleB.h"
#include "ModuleC.h"

#include "AdapterA.h"
#include "AdapterB.h"
#include "AdapterC.h"

#include "Filter.h"

using namespace std;


void fillDataForModuleB(vector<map<string, string>>& dataFileModuleB) {

    // Вставка элементов
    map<string, string> dict;
    dict["item_name_product"] = "productname1testb";
    dict["item_caterory"] = "Game";
    dict["item_price"] = "100.45";
    dict["des"] = "werhjhgfdsdfghjhgfds";
    dict["item_availability"] = "true";
    dataFileModuleB.push_back(dict);
    
    map<string, string> dict2;
    dict2["item_name_product"] = "productname2testb";
    dict2["item_caterory"] = "Game";
    dict2["item_price"] = "22.45";
    dict2["des"] = "werhjhgfdsdfghjhgfds";
    dict2["item_availability"] = "true";
    dataFileModuleB.push_back(dict2);

    map<string, string> dict3;
    dict3["item_name_product"] = "productname3testb";
    dict3["item_caterory"] = "Food";
    dict3["item_price"] = "1.45";
    dict3["des"] = "werhjhgfdsdfghjhgfds";
    dict3["item_availability"] = "true";
    dataFileModuleB.push_back(dict3);

}

void fillDataForModuleC(vector<ObjectC>& arrObjC) {
    ObjectC objC1("NameProductC1","Films","adasdasdad","10.32","true");
    ObjectC objC2("NameProductC2", "Films", "qqqqqqqq", "1.32", "true");
    ObjectC objC3("NameProductC3", "Game", "arttrrrrrr", "3.32", "false");
    arrObjC.push_back(objC1), arrObjC.push_back(objC2), arrObjC.push_back(objC3);
}

// Объединение данных из всех модулей
std::vector<Product> mergeData(const std::vector<AdapterAll*>& adapters) {
    std::vector<Product> allProducts;
    for (const auto adapter : adapters) {
        auto products = adapter->getAllProducts();
        allProducts.insert(allProducts.end(), products.begin(), products.end());
    }
    return allProducts;
}

// Вывод данных
void printProducts(vector<Product>& products) {
    for (auto& product : products) {
        cout<< product.getName()<<"; "
            << product.getCategory() << "; "
            << product.getPrice() << "; "
            << product.getDes() << "; "
            << (product.getInStock() ? "true" : "false") << std::endl;
    }
}



int main()
{
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

    //данные для модуля a хранятся в csv файле
    //Заполняем тестовыми данными для модуля b
    vector<map<string, string>> dataFileModuleB;
    fillDataForModuleB(dataFileModuleB);
    //Заполняем тестовыми данными для модуля c
    vector<ObjectC> dataFileModuleC;
    fillDataForModuleC(dataFileModuleC);

    ModuleA moduleA("FileModuleA.csv");
    ModuleB moduleB(dataFileModuleB);
    ModuleC moduleC(dataFileModuleC);

    AdapterA adapterA(moduleA);
    AdapterB adapterB(moduleB);
    AdapterC adapterC(moduleC);

    vector<AdapterAll*> adapters = { &adapterA,&adapterB,&adapterC };
    
    //Объединение данных и вывод в консоль
    vector<Product> allProducts = mergeData(adapters);
    printProducts(allProducts);

    //фильтр по категориям и по наличию на складе
    Filter filter(allProducts);
    vector<string> categories{"Game","Category2"};
    vector<Product> productsFilter = filter.getProductsByFilter(categories,1);
    cout <<"\nОтфильтрованные продукты" << endl;
    printProducts(productsFilter);

}
