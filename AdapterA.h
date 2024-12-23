#pragma once
#include "ModuleA.h"
#include "Product.h"
#include "AdapterAll.h"
using namespace std;
class AdapterA : public AdapterAll
{
private:
    ModuleA m_moduleA;

    Product parseProduct(const string& data) const {
        Product product;
        stringstream ss(data);
        string param;
        vector<string> params;

        while (getline(ss, param, ';')) {
            params.push_back(param);
        }
        if (params.size() != 5) {
            std::cerr << "Ошибка при парсинге ModuleA! элементов не 5!, данные: " << data << std::endl;
            return product;
        }
        if (params[4] != "true" && params[4] != "false") {
            std::cerr << "Ошибка при парсинге ModuleA! параметр 'Наличие на складе' неправильно указан!, данные: " << data << std::endl;
            return product;
        }
        for (size_t k = 0; k < params.size(); k++)
        {
            if(params[k]==""){
                std::cerr << "Ошибка при парсинге ModuleA! какой либо из параметров пуст!, данные: " << data << std::endl;
                return product;
            }
        }
        try
        {
            double test = stod(params[2]);
        }
        catch (...)
        {
            std::cerr << "Ошибка при парсинге ModuleA! Проблема при парсинге цены на продукт!, данные: " << data << std::endl;
            return product;
        }



  
        product.setName(params[0]);
        product.setCategory(params[1]);
        product.setPrice(stod(params[2]));
        product.setDes(params[3]);
        product.setInStock(params[4] == "true");
        

        return product;
    }

public:
    AdapterA(ModuleA& mdA) :m_moduleA(mdA){};
    vector<Product> getAllProducts() override {
        vector<Product> products;
        for (auto& line : m_moduleA.getDataInFile()) {
            Product pr = parseProduct(line);
            if(pr.getName()!="") {
                products.push_back(pr);
            }
        }
        return products;
    }
};
