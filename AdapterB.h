#pragma once
#include "Product.h"
#include "AdapterAll.h"
#include "ModuleB.h"
#include <iostream>
using namespace std;
class AdapterB : public AdapterAll
{
private:
    ModuleB m_moduleB;

    Product parseProduct(map<string, string>& data,size_t index){
        Product product;
        string name, category, price, des, in_stock;
        try
        {
            name = data.at("item_name_product");
            category = data.at("item_caterory");
            price = data.at("item_price");
            des = data.at("des");
            in_stock = data.at("item_availability");
        }
        catch (const std::out_of_range& e)
        {
            std::cerr << "Ошибка при парсинге ModuleB, отсутсвует один из параметров, индекс словаря: " <<to_string(index)<< std::endl;
            return product;
        }
        if (name == "" || category == "" || price == "" || des == "" || in_stock == "") {
            std::cerr << "Ошибка при парсинге ModuleB, один из параметров пуст!, индекс словаря: " << to_string(index) << std::endl;
            return product;
        }
        if (in_stock != "true" && in_stock != "false") {
            std::cerr << "Ошибка при парсинге ModuleB! параметр 'Наличие на складе' неправильно указан!, индекс словарая: " << to_string(index) << std::endl;
            return product;
        }
        try
        {
            double test = stod(price);
        }
        catch (...)
        {
            std::cerr << "Ошибка при парсинге ModuleB! цена неправильна указана на товар!, индекс словарая: " << to_string(index) << std::endl;
            return product;
        }

        product.setName(name);
        product.setCategory(category);
        product.setDes(des);
        product.setPrice(stod(price));
        product.setInStock(in_stock == "true");

        return product;
    }

public:

    AdapterB(ModuleB& mdB) :m_moduleB(mdB){};
    std::vector<Product> getAllProducts() override {
        std::vector<Product> products;
        vector<map<string, string>> allDict = m_moduleB.getData();
        for (size_t i =0;i<allDict.size();i++)
        {
            Product product = parseProduct(allDict[i],i);
            if(product.getName()!=""){ products.push_back(product); }
        }
        return products;
    }
};

